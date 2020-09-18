
# Endpoints

Endpoints are the fundamental building block of a GraphFuzz harness. In the previous section, we used some inference magic to automatically define endpoints and in this section we will explore the full verbose specification language:

```yaml
Foo:
    ...
    methods:
    ...
    # Endpoint name.
    - myEndpoint:
        # List of "live" inputs.
        inputs: ['Foo', 'Bar']

        # List of "live" outputs.
        outputs: ['Bar']

        # Additional fuzzable parameters.
        args: ['int', 'char[10]']

        # Endpoint code. (note: "exec: |" is YAML syntax for a multiline string)
        exec: |
            // Arbitrary C/C++ code here
            for (int i = 0; i < 10; ++i) {
                $a1[i] &= 0x7f;
            }
            $i1->doFunction($i0, $a0, $a1);
            $o0 = $i1;

```

You can imagine our endpoint definition as a code snippet with certain requirements about usage:

```c
// [Preconditions:]
// $i0 is a live Foo *
// $i1 is a live Bar *
// $a0 is an int
// $a1 is a char[10]
{
    for (int i = 0; i < 10; ++i) {
        $a1[i] &= 0x7f;
    }
    $i1->doFunction($i0, $a0, $a1);
    $o0 = $i1;
}
// [Postconditions:]
// $o0 is a live Bar *
```

In order to run this code, we need to initialize several objects including live data types. After we have run this code, one object will be left over that we will need to clean up.

With GraphFuzz, the fuzzer engine will automatically figure out how to invoke this endpoint by invoking other endpoints that construct the requisite objects and destruct the resulting objects.

---

In [Basic Usage](quick_start/basic_usage.md) we used the following schema which automatically generated full endpoint definitions:

**schema.yaml**
```yaml
Foo:
  type: struct
  name: Foo
  headers: [lib.h]
  methods:
  - Foo()
  - ~Foo()
  - void write(char val)
  - void check()
```

Internally, GraphFuzz produced a complete schema like the following:

**schema_verbose.yaml**
```yaml
Foo:
  type: struct
  name: Foo
  headers: [lib.h]
  methods:
  - Foo():
      outputs: ['Foo']
      exec: |
        $o0 = new Foo();
  - ~Foo():
      inputs: ['Foo']
      exec: |
        delete $i0;
  - void write(char val):
      inputs: ['Foo']
      outputs: ['Foo']
      args: ['char']
      exec: |
        $i0->write($a0);
        $o0 = $i0;
  - void check():
      inputs: ['Foo']
      outputs: ['Foo']
      exec: |
        $i0->check();
        $o0 = $i0;
```

Let's go endpoint by endpoint:

### Foo::Foo()

```yaml
- Foo():
    outputs: ['Foo']
    exec: |
        $o0 = new Foo();
```

This endpoint has no inputs and no context arguments (we can simply omit those fields). Since this is a constructor, it produces one output of type `Foo`. In `outputs`, we write the type name of our output object. Inside the `exec` template we need to actually call this constructor. Since we specified an output, we have access to a template variable `$o0` (output #0), a `Foo *` that we need to populate.

### Foo::~Foo()

```yaml
- ~Foo():
    inputs: ['Foo']
    exec: |
        delete $i0;
```

This endpoint is a destructor. In order to invoke a destructor, we need an instance of the object; hence, we specify one `Foo` object in our `inputs` array. Since we specified an input, we have access to a template variable `$i0` (input #0), a `Foo *`.

### Foo::check()

```yaml
- void check():
    inputs: ['Foo']
    outputs: ['Foo']
    exec: |
        $i0->check();
        $o0 = $i0;
```

This endpoint is a method call. In order to perform a method call, we need an instance of this object. After we have performed this method call, the object will still be valid and therefore it is also an output. So we specify `Foo` in both our inputs and outputs fields. Inside our exec template we have access to both `$i0` and `$o0`. When this endpoint is invoked, `$i0` will point to a valid `Foo` object and we are responsible for populating `$o0`.

### Foo::write(char)

```yaml
- void write(char val):
    inputs: ['Foo']
    outputs: ['Foo']
    args: ['char']
    exec: |
        $i0->write($a0);
        $o0 = $i0;
```

Like `Foo::check`, this endpoint is a method call. However, we now have another argument: a `char` that will be passed to our endpoint. `char` is a primative type and by default, it won't be tracked as part of the dataflow graph. Instead, each instance of this endpoint in a given graph will contain a separate instance of this argument which can be fuzzed. These context-based arguments are specified in the `args` array. Here we specify `char` and refer to it via the `$a0` (argument #0) template variable.

---




