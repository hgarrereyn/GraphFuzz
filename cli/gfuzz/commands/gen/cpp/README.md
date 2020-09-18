

# C++ harness generation

## Overview

A C++ schema can be broken down into two components: `types` and `scopes`.

A `type` is an object and there are two versions:
- `live types` are things like `structs` and `classes` that have explicit constructors and destructors. These objects are tracked by the dataflow graph.
- `simple types` are things like `int`, `float` or `enum` types that exist only within the context of a single function and are embedded in the `context` string during fuzzing.

A `scope` is a function and for C++ code, we have four types:
- `constructor`: A function with the same name as the enclosing `struct` or `class`.
- `destructor`: A function with the form `~MyStruct`.
- `method`: A function defined for an instance of an object, e.g. `myObj::foo()`
- `static`: A function not bound to a class, e.g. `void foo()`.

To generate harnesses, we first construct a list of `scopes` by enumerating functions defined in the schema. Each `scope` has a list of input and output `types`.

In the next stage, we resolve `types` (following typedef's as necessary), and determine the version. For example, `int x` should resolve as a "simple type of size 4" while `MyStruct &ref` should resolve to a "reference to `MyStruct`."

After the type resolution stage, we can compute the necessary "context" size for a scope and determine how many "live" inputs and outputs there will be.

Finally, we can layout the scope using a code generation template. We need to do this once for both the "exec" harness and the "write" harness.

## Method call

```cpp
extern "C" void shim_N(void **in_ref, void **out_ref, const char *context) {
    MyClass *ref = (MyClass *)in_ref[0];
    ref->myMethod();
    out_ref[0] = ref;
}
```