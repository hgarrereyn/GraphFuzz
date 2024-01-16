
import enum
import pathlib
from typing import List, Tuple, Set, Dict
import json
import re
import yaml

from gfuzz.commands.cliopt import CLIOpt
from gfuzz.schema import Schema

from .cpp_sig import parse_signature, CPPFuncSignature


CPP_TEMPLATE_MAIN = '''
/* {comment} */
extern "C" void {shim_name}(void **in_ref, void **out_ref, const char *context) {{
{load_args}{fn_call}{save_args}}}
'''

CPP_TEMPLATE_MAIN_WRITE = '''
/* {comment} */
extern "C" void {shim_name}(void **in_ref, void **out_ref, const char *context) {{
{load_args}
    std::cout << "    {{" << std::endl;
{inner_load_args}
{fn_call}{save_args}
    std::cout << "    }}" << std::endl;
}}
'''

CPP_TEMPLATE_MAIN_SOFT = '''
/* {comment} */
extern "C" void {shim_name}(void **in_ref, void **out_ref, const char *context) {{
{load_args}
    if (!graphfuzz_try()) {{
    {fn_call}    }}

{save_args}}}
'''

CPP_LOAD_REF = '''\
    {var_type} *{arg_name} = reinterpret_cast<{var_type} *>(in_ref[{in_ref_idx}]);
'''

CPP_LOAD_REF_BUNDLE = '''\
    GFUZZ_BUNDLE *_b{arg_name} = (GFUZZ_BUNDLE *)in_ref[{in_ref_idx}];
    {var_type} *{arg_name} = reinterpret_cast<{var_type} *>(_b{arg_name}->active);
'''

CPP_LOAD_REF_WRITE = '''\
    unsigned long {arg_name} = reinterpret_cast<unsigned long>(in_ref[{in_ref_idx}]);
'''

CPP_SAVE_REF = '''\
    out_ref[{out_ref_idx}] = (void*)({arg_name});
'''

CPP_LOAD_SIMPLE = '''\
    {var_type} {arg_name};
    memcpy(&{arg_name}, context + {context_offset}, sizeof({var_type}));
'''

CPP_LOAD_SIMPLE_ARRAY = '''\
    {var_type} {arg_name}[{count}];
    memcpy(&{arg_name}, context + {context_offset}, {context_size} * {count});
'''

CPP_LOAD_SIMPLE_ARRAY_WRITE = '''\
    std::cout << "    {var_type} {arg_name}[{count}] = {{";
    for (int i = 0; i < {count}; ++i) {{
        if (i % 16 == 0 && {count} > 16) std::cout << std::endl << "        ";
        {var_type} ref;
        memcpy(&ref, context + {context_offset} + ({context_size} * i), {context_size});
        std::cout << {print_cast}ref;
        if (i < {count} - 1) std::cout << ", ";
    }}
    if ({count} > 16) std::cout << std::endl << "    ";
    std::cout << "}};" << std::endl;
'''

CPP_PRINT_SIMPLE_ARRAY = '''\
    std::cout << "    {var_type} {arg_name}[{count}] = {{";
    for (int i = 0; i < {count}; ++i) {{
        if (i % 16 == 0 && {count} > 16) std::cout << std::endl << "        ";
        std::cout << {print_cast}{arg_name}[i];
        if (i < {count} - 1) std::cout << ", ";
    }}
    if ({count} > 16) std::cout << std::endl << "    ";
    std::cout << "}};" << std::endl;
'''

CPP_LOAD_ENUM = '''\
    {var_type} {arg_name};
    switch (*(reinterpret_cast<const unsigned char *>(context + {context_offset})) % {enum_size}) {{
{enum_cases}    }}
'''

CPP_LOAD_ENUM_WRITE = '''\
    const char *{arg_name};
    switch (*(reinterpret_cast<const unsigned char *>(context + {context_offset})) % {enum_size}) {{
{enum_cases}    }}
'''

CPP_ENUM_CASE = '''\
        case {case}: {arg_name} = {enum_value}; break;
'''

CPP_ENUM_CASE_WRITE = '''\
        case {case}: {arg_name} = "{enum_value}"; break;
'''

CPP_NEW_REF_CUSTOM = '''\
    unsigned long {name} = CURR_ID++;
    std::cout << "    {var_type} *var_" << {name} << ";" << std::endl;
'''


WRITE_ARG_REF = '''"*var_" << {arg_name}'''
WRITE_ARG_VAL = '''{arg_name}'''
WRITE_ARG_SEP = ''' << ", " << '''

SHIM_ARRAY = '''
void __attribute__((visibility ("default"))) (*FUZZER_SHIMS[])(void **, void **, const char *) = {{
{shims}
}};
'''

SHIM_MACROS = '''
#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))

struct GFUZZ_BUNDLE {
public:
    void *active;
    void *inactive;
    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}
};

#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)
'''

SHIM_MACROS_DRY = '''
#ifdef FUZZ_DRY
#define FUZZ_ENDPOINT(T) 0;
#else
#define FUZZ_ENDPOINT(T) T
#endif
'''

SHIM_HEADER = '''
#include <string.h>
#include <stdlib.h>
#include <cstdint>

extern "C" int graphfuzz_try();
extern "C" void graphfuzz_bail();

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) {{
{global_init}
}}

extern "C" void __attribute__((visibility ("default"))) shim_init() {{
{initializer}
}}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {{
{finalizer}
}}

{macros}
'''

SHIM_HEADER_WRITE = '''
#include <string.h>
#include <string>
#include <iostream>

unsigned long CURR_ID = 0;

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) {{
    char **new_argv = (char **)malloc((*argc + 2) * sizeof(char *));
    memcpy(new_argv, *argv, sizeof(*new_argv) * *argc);
    new_argv[*argc] = (char *)"-detect_leaks=0";
    new_argv[*argc + 1] = 0;
    (*argc)++;
    *argv = new_argv;
}}

extern "C" void __attribute__((visibility ("default"))) shim_init() {{
    CURR_ID = 0;

    std::cout << "{header_string}" << std::endl;
    std::cout << "{macros}" << std::endl;

    std::cout << "int main() {{" << std::endl;
}}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {{
    std::cout << "}}" << std::endl;
}}
'''

CPP_INCLUDE = '''\
#include "{header}"
'''

CPP_INCLUDE_LIB = '''\
#include {header}
'''

CPP_INCLUDE_C = '''\
extern "C" {{
    #include "{header}" 
}}
'''

FULL_HARNESS = '''\
{includes}
{header}
{shim_code}
{shim_array}
'''


class CPPScopeType(enum.Enum):
    # MyClass::MyClass(...)
    CONSTRUCTOR = 1

    # MyClass::~MyClass(...)
    DESTRUCTOR = 2

    # MyClass MyClass::Make(...)
    STATIC_CONSTRUCTOR = 3

    # void MyClass::foo(...)
    METHOD = 4

    # void foo(...)
    # int MyClass::DoFoo(...)
    STATIC = 5


def _is_live_type(obj: dict) -> bool:
    return obj['type'] in ['struct', 'class', 'bundle']


def _classify(parent: dict, sig: CPPFuncSignature, is_static: bool) -> CPPScopeType:
    """Determine the scope type."""

    # TODO: remove?
    if parent['type'] == 'file':
        return CPPScopeType.STATIC
    
    obj_name = parent['name']

    if sig.func_name.name == obj_name and not is_static:
        return CPPScopeType.CONSTRUCTOR
    elif sig.func_name.name == f'~{obj_name}' and not is_static:
        return CPPScopeType.DESTRUCTOR
    elif sig.func_type.base_type == obj_name and is_static:
        return CPPScopeType.STATIC_CONSTRUCTOR
    elif is_static:
        return CPPScopeType.STATIC
    else:
        return CPPScopeType.METHOD


def _escape_text(t: str) -> str:
    return t.replace('\\', '\\\\').replace('\"', '\\\"')


class CPPScope(object):
    def __init__(self, name: str, inputs: List[str], outputs: List[str], 
            args: List[str], exec_str: str):
        self.name = name
        self.inputs = inputs
        self.outputs = outputs
        self.args = args
        self.exec = exec_str

        self.needs_resolve = True
        self.has_all_refs = True
        self.missing_refs = []

        # *_ref is a list of schema objects filled during resolve_all
        self.inputs_ref = []
        self.outputs_ref = []
        self.args_ref = []

        # arg_count contains a positive integer describing the size of the
        # argument array. I.e. "1" for a single value and 2+ for an array.
        self.arg_count = []

    @staticmethod
    def from_dict(info: dict) -> 'CPPScope':
        """Initialize from a manual scope definition.
        
        Info is a dict of the form:

        "scope_name": {
            "inputs": ["MyClass"]
            "outputs": ["MyClass"]
            "args": ["int", "float"]
            "exec": "$i0->fuzz($a0, $a1);\n$o0 = $i0;"
        }
        """
        keys = [k for k in info]
        assert(len(keys) == 1)

        name = keys[0]
        dat = info[name]

        inputs = dat.get('inputs') or []
        outputs = dat.get('outputs') or []
        args = dat.get('args') or []
        exec_str = dat.get('exec') or ''

        return CPPScope(name, inputs, outputs, args, exec_str)

    @staticmethod
    def destructor_for(schema: Schema, parent: dict) -> 'CPPScope':
        sig = parse_signature(f'~{parent["name"]}()')
        return CPPScope.from_signature(schema, parent, sig, False)

    @staticmethod
    def from_signature(schema: Schema, parent: dict, sig: CPPFuncSignature, is_static: bool, generate_dry: bool = False) -> 'CPPScope':
        """Initialize from a C++ signature.
        
        Inputs/Outputs/Args are automatically inferred.

        Args:
        - schema: The global schema.
        - parent: The parent struct/class object.
        - sig: A parsed CPPFuncSignature.
        - is_static: True if this function was defined in static_methods.

        Returns a CPPScope if succesful, None if the types could not be resolved.
        """
        # Try to infer the scope type.
        scope_type = _classify(parent, sig, is_static)
        
        # Temporarily resolve type to figure out if they are arguments or inputs.
        # TODO: Clean this up, we end up resolving types twice in this pathway.
        resolved = []
        missing = []
        for arg in sig.func_args.args:
            if arg.is_raw:
                resolved.append(arg.raw_value)
            else:
                obj = schema.resolve(arg.base_type.base_type)
                if obj is None:
                    missing.append(arg.base_type.base_type)

                resolved.append(obj)

        func_base_type = None
        if sig.func_type is not None:
            func_base_type = schema.resolve(sig.func_type.base_type)
            if func_base_type is None:
                missing.append(sig.func_type.base_type)
        
        if len(missing) > 0:
            # Missing types.
            scp = CPPScope('', [], [], [], '')
            scp.needs_resolve = False
            scp.missing_refs = missing
            scp.has_all_refs = False

            return scp

        live_types = [k for k in resolved if type(k) is dict and _is_live_type(k)]
        context_types = [k for k in resolved if type(k) is dict and not _is_live_type(k)]

        inputs = [k['name'] for k in live_types]
        outputs = [k['name'] for k in live_types]
        args = [k['name'] for k in context_types]
        exec_str = ''

        arg_list = []
        idx_input = 0
        idx_arg = 0
        for i in range(len(resolved)):
            k = resolved[i]
            if type(k) is str:
                # raw type
                arg_list.append(k)
            else:
                if _is_live_type(k):
                    if sig.func_args.args[i].base_type.is_ptr:
                        arg_list.append(f'$i{idx_input}')
                    else:
                        arg_list.append(f'*$i{idx_input}')
                    idx_input += 1
                else:
                    arg_list.append(f'$a{idx_arg}')
                    idx_arg += 1
        arg_list = ', '.join(arg_list)

        if scope_type == CPPScopeType.CONSTRUCTOR:
            outputs = [parent['name']] + outputs
            copy_inputs = '\n'.join([
                f'$o{i+1} = $i{i};' for i in range(len(inputs))
            ])
            # Copy with memcpy or operator= ?
            if 'alloc_with_new' in parent and parent['alloc_with_new']:
                exec_str = f'''\
$o0 = new {parent['name']}({arg_list});
{copy_inputs}
                '''
            else:
                exec_str = f'''\
$o0 = MAKE({parent['name']});
{parent['name']} ref = {parent['name']}({arg_list});
*$o0 = ref;
{copy_inputs}
                '''
        elif scope_type == CPPScopeType.STATIC_CONSTRUCTOR:
            outputs = [parent['name']] + outputs
            copy_inputs = '\n'.join([
                f'$o{i+1} = $i{i};' for i in range(len(inputs))
            ])
            func_name = sig.func_name.name
            # If the func_name is not fully scoped (i.e. does not include "::") assume
            # it uses the base class.
            if not '::' in func_name:
                func_name = f'{parent["name"]}::{func_name}'

            # TODO: alloc_with_new for static constructors?
            if False or 'alloc_with_new' in parent and parent['alloc_with_new']:
                exec_str = f'''\
$o0 = MAKE({parent['name']});
{parent['name']} ref = {func_name}({arg_list});
*$o0 = ref;
{copy_inputs}
                '''
            else:
                exec_str = f'''\
$o0 = MAKE({parent['name']});
{parent['name']} ref = {func_name}({arg_list});
*$o0 = ref;
{copy_inputs}
                '''
        elif scope_type == CPPScopeType.METHOD:
            inputs = [parent['name']] + inputs
            outputs = [parent['name']] + outputs
            copy_inputs = '\n'.join([
                f'$o{i} = $i{i};' for i in range(len(inputs))
            ])
            arg_list = []
            idx_input = 1
            idx_arg = 0
            for i in range(len(resolved)):
                k = resolved[i]
                if type(k) is str:
                    # raw type
                    arg_list.append(k)
                else:
                    if _is_live_type(k):
                        if sig.func_args.args[i].base_type.is_ptr:
                            arg_list.append(f'$i{idx_input}')
                        else:
                            arg_list.append(f'*$i{idx_input}')
                        idx_input += 1
                    else:
                        arg_list.append(f'$a{idx_arg}')
                        idx_arg += 1
            arg_list = ', '.join(arg_list)

            if func_base_type is not None and _is_live_type(func_base_type):
                # Method-constructor
                outputs.append(func_base_type['name'])
                exec_str = f'''\
$o{len(inputs)} = MAKE({func_base_type['name']});
*$o{len(inputs)} = $i0->{sig.func_name.name}({arg_list});
{copy_inputs}
                '''
            else:
                if generate_dry:
                    exec_str = f'''\
FUZZ_ENDPOINT($i0->{sig.func_name.name}({arg_list});)
{copy_inputs}
                    '''
                else:
                    exec_str = f'''\
$i0->{sig.func_name.name}({arg_list});
{copy_inputs}
                    '''
        elif scope_type == CPPScopeType.STATIC:
            copy_inputs = '\n'.join([
                f'$o{i} = $i{i};' for i in range(len(inputs))
            ])
            if generate_dry:
                exec_str = f'''\
FUZZ_ENDPOINT({sig.func_name.name}({arg_list});)
{copy_inputs}
                '''
            else:
                exec_str = f'''\
{sig.func_name.name}({arg_list});
{copy_inputs}
                '''
        elif scope_type == CPPScopeType.DESTRUCTOR:
            inputs = [parent['name']] + inputs
            copy_inputs = '\n'.join([
                f'$o{i-1} = $i{i};' for i in range(1,len(inputs))
            ])
            if 'alloc_with_new' in parent and parent['alloc_with_new'] is True:
                exec_str = f'''\
delete $i0;
{copy_inputs}
                '''
            else:
                exec_str = f'''\
free($i0);
{copy_inputs}
                '''
        else:
            return None

        name = f'(auto) {parent["name"]}::{repr(sig)}'

        return CPPScope(name, inputs, outputs, args, exec_str)

    def __repr__(self):
        return f'CPPScope(name={self.name})'

    def resolve_all(self, schema: Schema, verbose=False):
        if not self.needs_resolve:
            return
        
        # TODO: maybe do this a bit cleaner
        # Process argument arrays.
        for i in range(len(self.args)):
            k = self.args[i]
            m = re.match('([^\[\]]*)\[([0-9]+)\]', k)

            if m is None:
                self.arg_count.append(1)
            else:
                typ, num = m.groups()
                self.args[i] = typ
                self.arg_count.append(int(num))

        to_resolve = [
            (self.inputs, self.inputs_ref),
            (self.outputs, self.outputs_ref),
            (self.args, self.args_ref),
        ]

        for src, res in to_resolve:
            for k in src:
                obj = schema.resolve(k)
                res.append(obj)

                if obj is None:
                    self.has_all_refs = False
                    self.missing_refs.append(k)

        for k in self.inputs_ref:
            if k is not None and not _is_live_type(k):
                self.has_all_refs = False
                print(f'[!] Error: {k["name"]} was defined as an input but it is not'\
                      f' a live type. Consider defining it in "args". (in "{self.name}")')

        for k in self.outputs_ref:
            if k is not None and not _is_live_type(k):
                self.has_all_refs = False
                print(f'[!] Error: {k["name"]} was defined as an output but it is not'\
                      f' a live type. (in "{self.name}")')

        for i in range(len(self.args_ref)):
            k = self.args_ref[i]
            if k is not None and _is_live_type(k):
                self.has_all_refs = False
                print(f'[!] Error: {k["name"]} was defined as an argument but it is '\
                      f'a live type. Consider defining it in "inputs". (in "{self.name}")')

            if k is not None and k['type'] =='enum' and self.arg_count[i] != 1:
                self.has_all_refs = False
                print(f'[!] Error: Array types are not supported for enums. Found {k["name"]}[{self.arg_count[i]}] in "{self.name}"')

    def is_resolved(self) -> bool:
        return self.has_all_refs

    def get_resolve_errors(self) -> List[str]:
        return self.missing_refs

    def build_scopedef(self):
        context_size = 0
        for i in range(len(self.args_ref)):
            k = self.args_ref[i]
            if k['type'] == 'simple':
                context_size += (k['context_size'] * self.arg_count[i])
            elif k['type'] == 'enum':
                context_size += 1

        return {
            'name': self.name,
            'inputs': [k['id'] for k in self.inputs_ref],
            'outputs': [k['id'] for k in self.outputs_ref],
            'context': context_size
        }

    def build_exec_shim(self, shim_name, soft_execution=False, generate_dry=False) -> str:
        load_args = []
        
        context_offset = 0
        arg_idx = 0

        var_map = {}

        bundle_input_idx = [i for i in range(len(self.inputs_ref)) if self.inputs_ref[i]['type'] == 'bundle']
        bundle_output_idx = [i for i in range(len(self.outputs_ref)) if self.outputs_ref[i]['type'] == 'bundle']

        assert len(bundle_input_idx) <= 1
        assert len(bundle_output_idx) <= 1

        for i in range(len(self.inputs_ref)):
            name = f'_i{i}'
            if self.inputs_ref[i]['type'] == 'bundle':
                # Input bundle has two forms:
                # 1. input only, i.e. reference the bundle directly (in unlink procedure)
                # 2. input+output, reference just the active type
                if len(bundle_output_idx) == 0:
                    # form 1
                    load_args.append(CPP_LOAD_REF.format(
                        var_type='GFUZZ_BUNDLE',
                        arg_name=name,
                        in_ref_idx=i
                    ))
                    var_map[f'$i{i}'] = name
                else:
                    # form 2
                    load_args.append(CPP_LOAD_REF.format(
                        var_type='GFUZZ_BUNDLE',
                        arg_name=name,
                        in_ref_idx=i
                    ))
                    var_type = self.inputs_ref[i]['active']
                    var_map[f'$i{i}'] = f'(({var_type} *){name}->active)'
            else:
                load_args.append(CPP_LOAD_REF.format(
                    var_type=self.inputs_ref[i]['name'],
                    arg_name=name,
                    in_ref_idx=i
                ))
                var_map[f'$i{i}'] = name
        
        context_offset = 0
        for i in range(len(self.args_ref)):
            name = f'_a{i}'
            k = self.args_ref[i]

            if k['type'] == 'simple':
                if self.arg_count[i] == 1:
                    fmt = k['load'] if 'load' in k else CPP_LOAD_SIMPLE
                    load_args.append(fmt.format(
                        var_type=k['name'],
                        arg_name=name,
                        context_offset=context_offset
                    ))
                    context_offset += k['context_size']
                else:
                    fmt = k['load_arr'] if 'load_arr' in k else CPP_LOAD_SIMPLE_ARRAY
                    load_args.append(fmt.format(
                        var_type=k['name'],
                        count=self.arg_count[i],
                        arg_name=name,
                        context_offset=context_offset,
                        context_size=k['context_size']
                    ))
                    context_offset += k['context_size'] * self.arg_count[i]
            elif k['type'] == 'enum':
                cases = [
                    CPP_ENUM_CASE.format(
                        case=i,
                        arg_name=name,
                        enum_value=f'{k["name"]}::{k["values"][i]}'
                    )
                    for i in range(len(k['values']))
                ]
                load_args.append(CPP_LOAD_ENUM.format(
                    var_type=k['name'],
                    arg_name=name,
                    enum_size=len(k['values']),
                    context_offset=context_offset,
                    enum_cases=''.join(cases)
                ))
                context_offset += 1
            
            var_map[f'$a{i}'] = name

        # Predefine scope outputs.
        scope_outputs = []
        for i in range(len(self.outputs_ref)):
            name = f'_o{i}'
            if self.outputs_ref[i]['type'] == 'bundle':
                # TODO: this is hacky
                # Currently bundle ouput has two forms:
                # 1. bundle output only, i.e. we are allocating a new bundle.
                # 2. bundle input+output, i.e. the bundle needs to be preserved so we copy it.
                if len(bundle_input_idx) == 0:
                    # form 1
                    load_args.append('    GFUZZ_BUNDLE *{name};\n'.format(
                        name=name
                    ))
                    # Reference the bundle directly.
                    var_map[f'$o{i}'] = name
                else:
                    # form 2, copy the input bundle and reference the active type.
                    load_args.append('    GFUZZ_BUNDLE *{name} = (GFUZZ_BUNDLE *)in_ref[{idx}];\n'.format(
                        name=name,
                        idx=bundle_input_idx[0]
                    ))
                    # Reference the active type.
                    var_map[f'$o{i}'] = f'({name}->active)'
            else:
                load_args.append('    {var_type} *{name};\n'.format(
                    var_type=self.outputs_ref[i]['name'],
                    name=name
                ))
                var_map[f'$o{i}'] = name
    
            scope_outputs.append(name)

        exec_fn = self.exec

        # indent
        exec_fn = '\n'.join(['    ' + x for x in exec_fn.split('\n')])

        for key in var_map:
            exec_fn = exec_fn.replace(key, var_map[key])
        exec_fn = exec_fn.replace('$$', '$')
        exec_fn = exec_fn + '\n'

        save_args = []
        for i in range(len(scope_outputs)):
            save_args.append(CPP_SAVE_REF.format(
                out_ref_idx=i,
                arg_name=scope_outputs[i]
            ))

        code = CPP_TEMPLATE_MAIN.format(
            comment=repr(self),
            shim_name=shim_name,
            load_args=''.join(load_args),
            fn_call=exec_fn,
            save_args=''.join(save_args)
        )

        return code

    def build_write_shim(self, shim_name) -> str:
        load_args = []
        inner_load_args = []
        
        context_offset = 0
        arg_idx = 0

        var_map = {}
        arg_map = {}

        bundle_input_idx = [i for i in range(len(self.inputs_ref)) if self.inputs_ref[i]['type'] == 'bundle']
        bundle_output_idx = [i for i in range(len(self.outputs_ref)) if self.outputs_ref[i]['type'] == 'bundle']

        assert len(bundle_input_idx) <= 1
        assert len(bundle_output_idx) <= 1

        # for i in range(len(self.inputs_ref)):
        #     name = f'_i{i}'
        #     if self.inputs_ref[i]['type'] == 'bundle':
        #         # Input bundle has two forms:
        #         # 1. input only, i.e. reference the bundle directly (in unlink procedure)
        #         # 2. input+output, reference just the active type
        #         if len(bundle_output_idx) == 0:
        #             # form 1
        #             load_args.append(CPP_LOAD_REF.format(
        #                 var_type='GFUZZ_BUNDLE',
        #                 arg_name=name,
        #                 in_ref_idx=i
        #             ))
        #             var_map[f'$i{i}'] = name
        #         else:
        #             # form 2
        #             load_args.append(CPP_LOAD_REF.format(
        #                 var_type='GFUZZ_BUNDLE',
        #                 arg_name=name,
        #                 in_ref_idx=i
        #             ))
        #             var_type = self.inputs_ref[i]['active']
        #             var_map[f'$i{i}'] = f'(({var_type} *){name}->active)'
        #     else:
        #         load_args.append(CPP_LOAD_REF.format(
        #             var_type=self.inputs_ref[i]['name'],
        #             arg_name=name,
        #             in_ref_idx=i
        #         ))
        #         var_map[f'$i{i}'] = name

        for i in range(len(self.inputs_ref)):
            name = f'_i{i}'
            if self.inputs_ref[i]['type'] == 'bundle':
                # Input bundle has two forms:
                # 1. input only, i.e. reference the bundle directly (in unlink procedure)
                # 2. input+output, reference just the active type
                if len(bundle_output_idx) == 0:
                    # form 1
                    load_args.append(CPP_LOAD_REF_WRITE.format(
                        arg_name=name,
                        in_ref_idx=i
                    ))
                    var_map[f'$i{i}'] = f'"var_" << {name}'
                else:
                    # form 2
                    load_args.append(CPP_LOAD_REF_WRITE.format(
                        arg_name=name,
                        in_ref_idx=i
                    ))
                    var_type = self.inputs_ref[i]['active']
                    var_map[f'$i{i}'] = f'"(({var_type} *)var_" << {name} << "->active)"'
            else:
                load_args.append(CPP_LOAD_REF_WRITE.format(
                    arg_name=name,
                    in_ref_idx=i
                ))
                var_map[f'$i{i}'] = f'"var_" << {name}'

        
        context_offset = 0
        for i in range(len(self.args_ref)):
            name = f'_a{i}'
            k = self.args_ref[i]

            if k['type'] == 'simple':
                if self.arg_count[i] == 1:
                    fmt = k['load'] if 'load' in k else CPP_LOAD_SIMPLE
                    load_args.append(fmt.format(
                        var_type=k['name'],
                        arg_name=name,
                        context_offset=context_offset
                    ))
                    context_offset += k['context_size']
                    if 'print_cast' in k:
                        name = f'({k["print_cast"]})_a{i}'
                else:
                    fmt = k['load_arr'] if 'load_arr' in k else CPP_LOAD_SIMPLE_ARRAY
                    inner_load_args.append(fmt.format(
                        var_type=k['name'],
                        count=self.arg_count[i],
                        arg_name=name,
                        context_offset=context_offset,
                        context_size=k['context_size']
                    ))
                    inner_load_args.append(CPP_PRINT_SIMPLE_ARRAY.format(
                        var_type=k['name'],
                        count=self.arg_count[i],
                        arg_name=name,
                        print_cast=f'({k["print_cast"]})' if 'print_cast' in k else ''
                    ))
                    # inner_load_args.append(CPP_LOAD_SIMPLE_ARRAY_WRITE.format(
                    #     var_type=k['name'],
                    #     count=self.arg_count[i],
                    #     arg_name=name,
                    #     context_offset=context_offset,
                    #     context_size=k['context_size'],
                    #     print_cast=f'({k["print_cast"]})' if 'print_cast' in k else ''
                    # ))
                    context_offset += k['context_size'] * self.arg_count[i]
                    # name references array
                    name = f'"_a{i}"'
            elif k['type'] == 'enum':
                cases = [
                    CPP_ENUM_CASE_WRITE.format(
                        case=i,
                        arg_name=name,
                        enum_value=f'{k["name"]}::{k["values"][i]}'
                    )
                    for i in range(len(k['values']))
                ]
                load_args.append(CPP_LOAD_ENUM_WRITE.format(
                    var_type=k['name'],
                    arg_name=name,
                    enum_size=len(k['values']),
                    context_offset=context_offset,
                    enum_cases=''.join(cases)
                ))
                context_offset += 1
            
            arg_map[f'$a{i}'] = name

        # Predefine scope outputs.
        scope_outputs = []
        for i in range(len(self.outputs_ref)):
            name = f'_o{i}'
            var_type = self.outputs_ref[i]['name']
            if self.outputs_ref[i]['type'] == 'bundle':
                var_type = 'GFUZZ_BUNDLE'
            load_args.append(CPP_NEW_REF_CUSTOM.format(
                name=name,
                var_type=var_type
            ))
            var_map[f'$o{i}'] = f'"var_" << {name}'
            scope_outputs.append(name)


        # Format exec code as a printed string.

        # (double indent)
        write_fn = '        ' + _escape_text(self.exec.strip())
        write_fn = write_fn.replace('\n', '\\n        ')

        # Replace largest macros first. i.e. "$i10" before "$i1"
        for key in sorted(var_map, key=len, reverse=True):
            write_fn = write_fn.replace(key, f'" << {var_map[key]} << "')
        for key in sorted(arg_map, key=len, reverse=True):
            write_fn = write_fn.replace(key, f'" << {arg_map[key]} << "')
        write_fn = write_fn.replace('$$', '$')
        write_fn = f'    std::cout << "{write_fn}" << std::endl;\n'

        save_args = []
        for i in range(len(scope_outputs)):
            save_args.append(CPP_SAVE_REF.format(
                out_ref_idx=i,
                arg_name=scope_outputs[i]
            ))

        code = CPP_TEMPLATE_MAIN_WRITE.format(
            comment=repr(self),
            shim_name=shim_name,
            load_args=''.join(load_args),
            inner_load_args=''.join(inner_load_args),
            fn_call=write_fn,
            save_args=''.join(save_args)
        )

        return code


def _apply_signature_filter(sig: str, ignore_keywords: List[str] = []) -> str:
    filtered = sig
    for word in ignore_keywords:
        filtered = filtered.replace(word, '')
    return filtered


def _build_custom_scope(info: dict) -> CPPScope:
    try:
        scope = CPPScope.from_dict(info)
        return scope
    except:
        print(f'[!] Unable to process custom scope: {info}')
        return None


def collect_scopes(schema: Schema, ignore_keywords: List[str] = [], generate_dry: bool = False) -> Tuple[List[CPPScope], int, dict]:
    """Enumerate methods in a schema and return CPPScope objects.
    
    Args:
    - schema: The Schema object to enumerate.
    - ignore_keywords: If set, these keywords will be removed from function
      signatures. For example, this is useful if certain functions have keywords
      like "WARN_UNUSED" which are really attributes.

    Returns:
    - scopes, max_num, errors
    """
    scopes = []
    max_num = 0

    # (obj, sig, err)
    errors = []

    for k in schema.objects:
        obj = schema.objects[k]

        if len(obj['headers']) == 0 and len(obj['c_headers']) == 0:
            continue

        if obj['type'] in ['class', 'struct']:

            # (signature, is_static)
            sigs: List[Tuple[str, bool]] = []
            custom: List[CPPScope] = []

            if 'methods' in obj:
                for sig in obj['methods']:
                    max_num += 1
                    if type(sig) is str:
                        sigs.append((sig, False))
                    else:
                        custom.append(_build_custom_scope(sig))

            if 'static_methods' in obj:
                for sig in obj['static_methods']:
                    max_num += 1
                    if type(sig) is str:
                        sigs.append((sig, True))
                    else:
                        custom.append(_build_custom_scope(sig))

            scopes += [x for x in custom if x is not None]

            for sig, is_static in sigs:
                sig = _apply_signature_filter(sig, ignore_keywords)
                psig = parse_signature(sig)
                if psig is None:
                    errors.append((obj, sig, 'parse error'))
                    # print(f'[!] Could not parse signature: {sig}')
                    continue

                try:
                    scope = CPPScope.from_signature(schema, obj, psig, is_static, generate_dry=generate_dry)
                except Exception as e:
                    errors.append((obj, sig, 'parse error'))
                    print(f'[!] Error while parsing: {sig}')
                    print(e)
                    continue

                scopes.append(scope)


        if obj['type'] in ['class', 'struct']:
            # Check if user wants to add a default destructor.
            if 'default_destructor' in obj and obj['default_destructor'] is True:
                max_num += 1
                scopes.append(CPPScope.destructor_for(schema, obj))

    return scopes, max_num, errors


def collect_headers(schema: Schema) -> Tuple[List[str], List[str]]:
    """Returns (headers, c_headers)."""
    headers = set()
    c_headers = set()

    for k in schema.objects:
        obj = schema.objects[k]
        if obj['type'] in ['struct', 'class', 'enum']:
            if 'headers' in obj:
                headers |= set(obj['headers'])
            if 'c_headers' in obj:
                c_headers |= set(obj['c_headers'])

    return sorted(list(headers)), sorted(list(c_headers))


def make_exec_harness(schema: Schema, scopes: List[CPPScope], soft_execution: bool = False, generate_dry: bool = False) -> str:
    shims = [
        scopes[i].build_exec_shim(f'shim_{i}', soft_execution, generate_dry)
        for i in range(len(scopes))
    ]
    shim_code = '\n'.join(shims)

    headers, c_headers = collect_headers(schema)
    includes = [
        CPP_INCLUDE.format(header=h)
        for h in headers if h.endswith('.h')
    ] + [
        CPP_INCLUDE_LIB.format(header=h)
        for h in headers if h.startswith('<') and h.endswith('>')
    ] + [
        CPP_INCLUDE_C.format(header=h)
        for h in c_headers
    ]
    includes = ''.join(includes)

    # Check for custom initializer/finalizer
    global_init = ''
    initializer = ''
    finalizer = ''
    for k in schema.objects:
        if schema.objects[k]['type'] == 'config':
            if 'global_init' in schema.objects[k]:
                global_init = schema.objects[k]['global_init']
            if 'initializer' in schema.objects[k]:
                initializer = schema.objects[k]['initializer']
            if 'finalizer' in schema.objects[k]:
                finalizer = schema.objects[k]['finalizer']

    code = FULL_HARNESS.format(
        includes=includes,
        header=SHIM_HEADER.format(
            global_init=global_init,
            initializer=initializer,
            finalizer=finalizer,
            macros=SHIM_MACROS + (SHIM_MACROS_DRY if generate_dry else '')
        ),
        shim_code=shim_code,
        shim_array=SHIM_ARRAY.format(
            shims='\n'.join(
                f'    &shim_{i},' for i in range(len(shims))
            )
        )
    )

    return code


def make_write_harness(schema: Schema, scopes: List[CPPScope]) -> str:
    shims = [
        scopes[i].build_write_shim(f'shim_{i}')
        for i in range(len(scopes))
    ]
    shim_code = '\n'.join(shims)

    headers, c_headers = collect_headers(schema)
    includes = [
        CPP_INCLUDE.format(header=h)
        for h in headers if h.endswith('.h')
    ] + [
        CPP_INCLUDE_LIB.format(header=h)
        for h in headers if h.startswith('<') and h.endswith('>')
    ] + [
        CPP_INCLUDE_C.format(header=h)
        for h in c_headers
    ]
    includes = ''.join(includes)
    header_string = includes.replace('"', "\\\"").replace('\n', '\\n')

    code = FULL_HARNESS.format(
        includes='',
        header=SHIM_HEADER_WRITE.format(
            header_string=header_string,
            macros=SHIM_MACROS.replace('"', "\\\"").replace('\n', '\\n')
        ),
        shim_code=shim_code,
        shim_array=SHIM_ARRAY.format(
            shims='\n'.join(
                f'    &shim_{i},' for i in range(len(shims))
            )
        )
    )

    return code


def make_fuzz_schema(schema: Schema, scopes: List[CPPScope]) -> dict:
    defs = [k.build_scopedef() for k in scopes]
    types = [{
        'id': schema.objects[k]['id'],
        'name': schema.objects[k]['name']
    } for k in schema.objects if schema.objects[k]['type'] in ['struct', 'class', 'bundle']]

    return {
        'types': types,
        'scopes': defs
    }


def _enumerate_bundleable(bundle: dict, types: List[dict]) -> List[int]:
    out = []
    for i in range(len(types)):
        typ = types[i]
        # TODO: nested bundling (hard)

        # if typ['type'] == 'bundle':
        #     if typ['inactive'] == bundle['active']:
        #         out.append(i)
        # else:

        if typ['name'] == bundle['active']:
            out.append(i)
    
    return out


def _compose_bundle(outer: dict, inner: dict):
    """
    outer has form <A,B>
    inner has form <B,C>

    produces a new bundle of form <A,<B,C>>
    """
    return {
        'type': 'bundle',
        'name': f'(auto) ({outer["name"]}, {inner["name"]})',
        'active': outer['active'],
        'inactive': inner['name']
    }


def make_bundled_scope(schema: Schema, scope: CPPScope, bundle: dict) -> CPPScope:

    active_input_idx = _enumerate_bundleable(bundle, scope.inputs_ref)
    active_output_idx = _enumerate_bundleable(bundle, scope.outputs_ref)

    if len(active_input_idx) != 1 or len(active_output_idx) != 1:
        # TODO: warn user if len is greater than 1, i.e. we can't infer what
        # the bundled scope should look like.
        return None

    in_idx = active_input_idx[0]
    out_idx = active_output_idx[0]

    in_typ = scope.inputs_ref[in_idx]
    out_typ = scope.outputs_ref[out_idx]

    in_bundle = bundle
    out_bundle = bundle

    # Check if we need to compose bundles.
    if in_typ['type'] == 'bundle':
        comp = _compose_bundle(in_typ, bundle)
        comp = schema.add_unique(comp)
        in_bundle = comp

    if out_typ['type'] == 'bundle':
        comp = _compose_bundle(out_typ, bundle)
        comp = schema.add_unique(comp)
        out_bundle = comp

    bscope = CPPScope(f'bundled_{scope.name}', [], [], [], scope.exec)
    
    inputs_ref = scope.inputs_ref[:in_idx] + [in_bundle] + scope.inputs_ref[in_idx+1:]
    outputs_ref = scope.outputs_ref[:out_idx] + [out_bundle] + scope.outputs_ref[out_idx+1:]

    bscope.inputs_ref = inputs_ref
    bscope.outputs_ref = outputs_ref
    bscope.args_ref = scope.args_ref
    bscope.arg_count = scope.arg_count

    return bscope


def duplicate_bundle_scopes(schema: Schema, scopes: List[CPPScope]) -> List[CPPScope]:
    bundle_defs = [
        schema.objects[k] for k in schema.objects 
        if schema.objects[k]['type'] == 'bundle'
    ]

    extra_scopes = []

    for bundle in bundle_defs:
        for scope in scopes:
            bscope = make_bundled_scope(schema, scope, bundle)
            if bscope:
                extra_scopes.append(bscope)

    return scopes + extra_scopes


def generate_harness(schema: Schema, output_path: str, soft_execution: bool = False, ignore_keywords: List[str] = [], generate_dry: bool =False):

    schema.assign_ids()

    # 1. Collect and parse scopes.
    raw_scopes, max_num, errors = collect_scopes(schema, ignore_keywords, generate_dry)

    if max_num == 0:
        print('No scopes found')
        exit(0)

    paths = list(set([x[0]['orig_path'] for x in errors]))
    for p in paths:
        print(f'{p}:')
        sub_errors = [x for x in errors if x[0]['orig_path'] == p]

        for obj, sig, typ in sub_errors:
            print(f'- ({typ}) {obj["name"]} "{sig}"')

    # 2. Resolve type names and compute scope details.
    for s in raw_scopes:
        s.resolve_all(schema, verbose=True)

    # 3. Filter out unresolvable scopes.
    scopes = [k for k in raw_scopes if k.is_resolved()]
    unresolved = [k for k in raw_scopes if not k.is_resolved()]

    # name: count
    missing_refs: Dict[str, int] = {}

    for k in unresolved:
        for ref in k.get_resolve_errors():
            if not ref in missing_refs:
                missing_refs[ref] = 0
            missing_refs[ref] += 1

    missing_refs_sorted = sorted(
        [(k, missing_refs[k]) for k in missing_refs],
        key=lambda x:x[1],
        reverse=True
    )

    if len(missing_refs_sorted) > 0:
        print('\nMissing refs:')
        for k,c in missing_refs_sorted:
            print(f'- {k} ({c})')

    # 3.5. Enumerate scopes for bundles.
    scopes = duplicate_bundle_scopes(schema, scopes)

    # 4. Generate fuzzer files.
    fuzz_schema = make_fuzz_schema(schema, scopes)
    exec_code = make_exec_harness(schema, scopes, soft_execution, generate_dry)
    write_code = make_write_harness(schema, scopes)

    # Save generated components.
    path = pathlib.Path(output_path)
    open(path / 'schema.json', 'w').write(json.dumps(fuzz_schema))
    open(path / 'fuzz_exec.cpp', 'w').write(exec_code)
    open(path / 'fuzz_write.cpp', 'w').write(write_code)

    print('\n[Results]:')
    print(f'- Parsed {len(raw_scopes)} / {max_num} ({len(raw_scopes) * 100.0 / max_num:.1f}%)')
    print(f'- Generated {len(scopes)} / {max_num} ({len(scopes) * 100.0 / max_num:.1f}%)')


def register(sub):
    sub.add_argument('schema', help='Path to schema.yaml.')
    sub.add_argument('output_path', default='.', help='Folder to save generated fuzzer files.')
    sub.add_argument(
        '--enable_soft_execution', default=False, action='store_true', 
        help='If enabled, catch assertion errors in nodes and continue execution.')
    
    sub.add_argument('--ignore_keywords', default=[], type=str, nargs='+', 
        help='If set, ignore these keywords in function signatures.')

    sub.add_argument('--generate_dry', default=False, action='store_true',
        help='If enabled, wrap method calls in a no-opable FUZZ_ENDPOINT macro.')

def execute(args):
    base_path = pathlib.Path(__file__).parent / 'base_schema.yaml'
    base_schema = Schema.load(str(base_path))

    schema = Schema.load(args.schema)
    schema.add_all(base_schema)
    
    generate_harness(
        schema, 
        args.output_path, 
        args.enable_soft_execution,
        args.ignore_keywords,
        args.generate_dry
    )


GenCppAPI = CLIOpt(
    'cpp',
    'Generate a C++ harness.',
    register,
    execute
)
