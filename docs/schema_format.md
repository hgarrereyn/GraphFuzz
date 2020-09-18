
# Schema Format

A GraphFuzz schema is a key-value mapping of schema objects written in YAML:

```yaml
object1:
    type: ...
    name: object1
    ...
object2:
    type: ...
    name: object2
    ...
...
```

# Available Objects

## Struct/Class

Represents a C++ struct/class with associated methods.

```yaml
struct_Foo:
    type: struct # (or type: class)
    name: Foo
    headers: ['foo.h']
    methods:
    - void Foo()
    - void ~Foo()
    static_methods:
    - Foo * MakeFoo(int)
```

Properties:

| name | type | default value | info |
| --- | --- | --- | --- |
| `type` | `string` | - | `struct` or `class` |
| `name` | `string` | - | Name of the class (e.g. `Foo`) or name of a template instance (e.g. `Foo<int>`). |
| `methods` | `List[endpoint]` | `[]` | List of instance methods (signatures or endpoint objects). |
| `static_methods` | `List[endpoint]` | `[]` | List of static methods (signatures or endpoint objects). |
| `headers` | `List[string]` | `[]` | List of C++ headers containing definitions of all enclosed methods. |
| `c_headers` | `List[string]` | `[]` | List of C headers containing definitions of all enclosed methods. |
| `default_destructor` | `bool` | `false` | If `true`, add a default destructor endpoint (e.g. `void ~Foo()`) |
| `alloc_with_new` | `bool` | `false` | If `true`, invoke constructors as `Foo *f = new Foo()` instead of performing local allocation and using a copy-constructor. |

## Enum

Represents a C/C++ enum.

```yaml
enum_Options:
    type: enum
    name: Options
    headers: ['options.h']
    values:
    - OptA
    - OptB
    - OptC
```

Properties:

| name | type | default value | info |
| --- | --- | --- | --- |
| `type` | `string` | - | `enum` |
| `name` | `string` | - | Name of the enum (e.g. `Options`). |
| `headers` | `List[string]` | `[]` | Required C++ headers to use this enum. |
| `c_headers` | `List[string]` | `[]` | Required C headers to use this type. |
| `values` | `List[string]` | `[]` | List of enum values. |

## Typedef

Represents a C/C++ type definition.

```yaml
# E.g.
# typedef float MyFoo;

typedef_foo:
  type: typedef
  name: MyFoo
  headers: ['foo.h']
  value: float
```

Properties:

| name | type | default value | info |
| --- | --- | --- | --- |
| `type` | `string` | - | `typedef` |
| `name` | `string` | - | Name of the newly created type (e.g. `MyFoo`). |
| `headers` | `List[string]` | `[]` | Required C++ headers to use this type. |
| `c_headers` | `List[string]` | `[]` | Required C headers to use this type. |
| `value` | `string` | `''` | Value of the type. |

## Simple

Represents a builtin C/C++ primative type.

```yaml
simple_float:
  type: simple
  name: float
  context_size: 4
```

Properties:

| name | type | default value | info |
| --- | --- | --- | --- |
| `type` | `string` | - | `simple` |
| `name` | `string` | - | Name of the builtin type (e.g. `float`). |
| `context_size` | `int` | `0` | Size of the type in bytes. |

# Endpoint Definitions

Endpoints can be specified in two ways:

1. (automatic) Provide a C/C++ function signature.
2. (manual) Provide an endpoint definition object.

## Automatic Endpoints

```yaml
- void doBar(Bar *, int)
```

GraphFuzz uses the following logic to determine how to interpret an endpoint signature:

| condition | result |
| --- | --- |
| in `methods` and matches `void <name>(...)`? | standard constructor |
| in `methods` and matches `void ~<name>(...)`? | destructor |
| in `methods`? | instance method |
| in `static_methods` and return type is `<name> *`? | static constructor |
| in `static_methods`? | static function |

## Manual Endpoints

```yaml
- my_endpoint:
    inputs: ['Foo', 'Bar']
    outputs: ['Bar']
    args: ['int']
    exec: |
        $i0->doFoo($i1, $a0);
        $o0 = $i1;
```

Properties:

| name | type | default value | info |
| --- | --- | --- | --- |
| `inputs` | `List[string]` | `[]` | List of live input types. |
| `outputs` | `List[string]` | `[]` | List of live output types. |
| `args` | `List[string]` | `[]` | List of context arguments. Can also use fixed-size arrays, e.g. `int[10]` or `char[256]` here. |
| `exec` | `string` | `''` | Execution template (C/C++). `$(i/o/a)N` macros reference the Nth inputs/outputs/args element respectively. |
