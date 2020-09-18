

#include <string.h>
#include <string>
#include <iostream>

unsigned long CURR_ID = 0;

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) { }

extern "C" void __attribute__((visibility ("default"))) shim_init() {
    CURR_ID = 0;

    std::cout << "#include \"include/core/SkRect.h\"\n#include \"include/core/SkRegion.h\"\n" << std::endl;
    std::cout << "\n#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))\n\nstruct GFUZZ_BUNDLE {\npublic:\n    void *active;\n    void *inactive;\n    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}\n};\n\n#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)\n" << std::endl;

    std::cout << "int main() {" << std::endl;
}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {
    std::cout << "}" << std::endl;
}


/* CPPScope(name=(auto) SkRegion::SkRegion();) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_0" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkRegion);\n        SkRegion ref = SkRegion();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_0" << std::endl;
}


/* CPPScope(name=(auto) SkRegion::bool op(const SkIRect & rect, SkRegion::Op op);) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 6) {
        case 0: _a0 = "SkRegion::Op::kDifference_Op"; break;
        case 1: _a0 = "SkRegion::Op::kIntersect_Op"; break;
        case 2: _a0 = "SkRegion::Op::kUnion_Op"; break;
        case 3: _a0 = "SkRegion::Op::kXOR_Op"; break;
        case 4: _a0 = "SkRegion::Op::kReverseDifference_Op"; break;
        case 5: _a0 = "SkRegion::Op::kReplace_Op"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_1" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->op(*" << "var_" << _i1 << ", " << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_1" << std::endl;
}


/* CPPScope(name=(auto) SkRegion::int computeRegionComplexity();) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_2" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->computeRegionComplexity();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_2" << std::endl;
}


/* CPPScope(name=(auto) SkRegion::~SkRegion();) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_3" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_3" << std::endl;
}


/* CPPScope(name=(auto) SkIRect::void sort();) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_4" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->sort();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_4" << std::endl;
}


/* CPPScope(name=(auto) SkIRect::SkIRect MakeLTRB(int32_t l, int32_t t, int32_t r, int32_t b);) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    int32_t _a0;
    memcpy(&_a0, context + 0, sizeof(int32_t));
    int32_t _a1;
    memcpy(&_a1, context + 4, sizeof(int32_t));
    int32_t _a2;
    memcpy(&_a2, context + 8, sizeof(int32_t));
    int32_t _a3;
    memcpy(&_a3, context + 12, sizeof(int32_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_5" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkIRect);\n        SkIRect ref = SkIRect::MakeLTRB(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_5" << std::endl;
}


/* CPPScope(name=(auto) SkIRect::~SkIRect();) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_6" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_6" << std::endl;
}


void __attribute__((visibility ("default"))) (*FUZZER_SHIMS[])(void **, void **, const char *) = {
    &shim_0,
    &shim_1,
    &shim_2,
    &shim_3,
    &shim_4,
    &shim_5,
    &shim_6,
};

