"""
Utilities for parsing Cpp-like signatures.
"""
from dataclasses import dataclass
from typing import Set, Optional, List

import pyparsing as pp


@dataclass
class CPPTypeModifier:
    modifiers: Set[str]
    
    @staticmethod
    def action(tok):
        return CPPTypeModifier(set(tok))
    
    @staticmethod
    def build() -> pp.ParseExpression:
        modifiers = ['unsigned', 'const', 'override', 'constexpr']
        modifier_list = pp.Each([pp.Optional(pp.Keyword(x)) for x in modifiers])
        modifier_list.setParseAction(CPPTypeModifier.action)
        return modifier_list

    
@dataclass
class CPPBaseType:
    """
    For simplicity, we consider three types:
    - bare types: e.g. "int"
    - reference types: e.g. "MyClass &"
    - pointer types: e.g. "MyClass *"
    """
    base_type: str
    is_ref: bool = False
    is_ptr: bool = False

    def __repr__(self):
        if self.is_ref:
            return f'{self.base_type} &'
        elif self.is_ptr:
            return f'{self.base_type} *'
        else:
            return f'{self.base_type}'
        
    @staticmethod
    def action(tok):
        if len(tok) == 1:
            return CPPBaseType(tok[0])
        elif tok[1] == '*':
            return CPPBaseType(tok[0], is_ptr=True)
        elif tok[1] == '&':
            return CPPBaseType(tok[0], is_ref=True)
        else:
            return None
        
    @staticmethod
    def build() -> pp.ParseExpression:
        identifier = pp.Word(pp.alphanums + '_:<>')
        base_type = identifier & pp.Optional(pp.Or(['&', '*']))
        base_type.setParseAction(CPPBaseType.action)
        return base_type


@dataclass
class CPPArgName:
    name: Optional[str] = None
        
    @staticmethod
    def action(tok):
        if len(tok) == 1:
            return CPPArgName(tok[0])
        else:
            return CPPArgName()
    
    @staticmethod
    def build() -> pp.ParseExpression:
        identifier = pp.Word(pp.alphanums + '_')
        arg_name = pp.Optional(identifier)
        arg_name.setParseAction(CPPArgName.action)
        return arg_name
    
@dataclass
class CPPArgument:
    """Represents a full type name and argument name in a function signature.
    
    For example:
    - unsigned char
    - const char *foo
    - MyClass&
    - int
    """
    modifiers: CPPTypeModifier
    base_type: CPPBaseType
    arg_name: CPPArgName
    raw_value: str = ''
    is_raw: bool = False

    def __repr__(self):
        if self.is_raw:
            return '{' + self.raw_value + '}'
        else:
            parts = (
                list(self.modifiers.modifiers) + 
                [repr(self.base_type), self.arg_name.name])
            
            return ' '.join([str(x) for x in parts])
        
    @staticmethod
    def action(tok):
        assert len(tok) == 3
        return CPPArgument(*tok)
    
    @staticmethod
    def action_raw(tok):
        assert len(tok) == 1
        raw_value = tok[0].strip()[1:-1]
        return CPPArgument(modifiers=None, base_type=None, arg_name=None, raw_value=raw_value, is_raw=True)

    @staticmethod
    def build() -> pp.ParseExpression:
        full_arg = (
            CPPTypeModifier.build() + \
            CPPBaseType.build() + \
            CPPArgName.build()
        )
        full_arg.setParseAction(CPPArgument.action)

        raw_arg = (
            pp.Regex('\{[^\{\}]*\}')
        )
        raw_arg.setParseAction(CPPArgument.action_raw)

        return pp.Or([full_arg, raw_arg])
    

@dataclass
class CPPArgList:
    args: List[CPPArgument]
        
    def __repr__(self):
        return ', '.join(repr(x) for x in self.args)

    @staticmethod
    def action(tok):
        if len(tok) == 0:
            return CPPArgList([])
        else:
            return CPPArgList(tok)
    
    @staticmethod
    def build() -> pp.ParseExpression:
        arg_list = pp.Optional(pp.delimitedList(CPPArgument.build()))
        arg_list.setParseAction(CPPArgList.action)
        return arg_list
    

@dataclass
class CPPFuncName:
    name: str
        
    @staticmethod
    def action(tok):
        return CPPFuncName(tok[0])
    
    @staticmethod
    def build() -> pp.ParseExpression:
        # Allow some special characters for operator overloads.
        func_name = pp.Word(pp.alphanums + '_:+-[]<>=*/^%-&|~!,')
        func_name.setParseAction(CPPFuncName.action)
        return func_name
    

@dataclass
class CPPFuncSignature:
    modifiers: CPPTypeModifier
    func_type: CPPBaseType
    func_name: CPPFuncName
    func_args: CPPArgList
    trailing_modifiers: CPPTypeModifier

    def __repr__(self):
        if self.func_type is None:
            # Untyped.
            return f'{self.func_name.name}({self.func_args});'
        else:
            # Typed.
            parts = (
                list(self.modifiers.modifiers) +
                [repr(self.func_type), self.func_name.name]
            )
            pre = ' '.join(parts)
            return f'{pre}({self.func_args});'

    @staticmethod
    def action_typed(tok):
        assert len(tok) == 5
        return CPPFuncSignature(*tok)
    
    @staticmethod
    def action_untyped(tok):
        assert len(tok) == 3
        return CPPFuncSignature(None, None, *tok)
    
    @staticmethod
    def build() -> pp.ParseExpression:
        typed_func = (
            CPPTypeModifier.build() + 
            CPPBaseType.build() +
            CPPFuncName.build() + 
            pp.Suppress(pp.Literal('(')) +
            CPPArgList.build() +
            pp.Suppress(pp.Literal(')')) +
            CPPTypeModifier.build() +
            pp.Suppress(pp.Optional(pp.Literal(';')))
        )
        typed_func.setParseAction(CPPFuncSignature.action_typed)
        
        # e.g. constructors and destructors
        untyped_func = (
            CPPFuncName.build() + 
            pp.Suppress(pp.Literal('(')) +
            CPPArgList.build() +
            pp.Suppress(pp.Literal(')')) +
            CPPTypeModifier.build() +
            pp.Suppress(pp.Optional(pp.Literal(';')))
        )
        untyped_func.setParseAction(CPPFuncSignature.action_untyped)
        
        return pp.Or([typed_func, untyped_func])
    

cpp_signature_parser = CPPFuncSignature.build()
def parse_signature(signature: str) -> Optional[CPPFuncSignature]:
    try:
        sig = cpp_signature_parser.parseString(signature.strip(), parseAll=True)
        return sig[0]
    except:
        return None
