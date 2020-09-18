

#include <string.h>
#include <string>
#include <iostream>

unsigned long CURR_ID = 0;

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) { }

extern "C" void __attribute__((visibility ("default"))) shim_init() {
    CURR_ID = 0;

    std::cout << "#include \"poly_util.h\"\n" << std::endl;
    std::cout << "\n#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))\n\nstruct GFUZZ_BUNDLE {\npublic:\n    void *active;\n    void *inactive;\n    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}\n};\n\n#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)\n" << std::endl;

    std::cout << "int main() {" << std::endl;
}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {
    std::cout << "}" << std::endl;
}


/* CPPScope(name=PolyTester(int _count, SkScalar coords[1024], uint16_t _indexMap[512])) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    PolyTester *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_0" << std::endl;
    float _a1[1024];
    memcpy(&_a1, context + 4, 4 * 1024);
    std::cout << "    float _a1[1024] = {";
    for (int i = 0; i < 1024; ++i) {
        if (i % 16 == 0 && 1024 > 16) std::cout << std::endl << "        ";
        std::cout << _a1[i];
        if (i < 1024 - 1) std::cout << ", ";
    }
    if (1024 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint16_t _a2[512];
    memcpy(&_a2, context + 4100, 2 * 512);
    std::cout << "    uint16_t _a2[512] = {";
    for (int i = 0; i < 512; ++i) {
        if (i % 16 == 0 && 512 > 16) std::cout << std::endl << "        ";
        std::cout << _a2[i];
        if (i < 512 - 1) std::cout << ", ";
    }
    if (512 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new PolyTester(" << _a0 << ", " << "_a1" << ", " << "_a2" << ");" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_0" << std::endl;
}


/* CPPScope(name=(auto) PolyTester::void test_SkGetPolygonWinding();) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    PolyTester *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_1" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->test_SkGetPolygonWinding();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_1" << std::endl;
}


/* CPPScope(name=(auto) PolyTester::void test_SkIsConvexPolygon();) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    PolyTester *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_2" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->test_SkIsConvexPolygon();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_2" << std::endl;
}


/* CPPScope(name=(auto) PolyTester::void test_SkIsSimplePolygon();) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    PolyTester *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_3" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->test_SkIsSimplePolygon();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_3" << std::endl;
}


/* CPPScope(name=(auto) PolyTester::void test_SkInsetConvexPolygon(SkScalar inset);) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    PolyTester *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_4" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->test_SkInsetConvexPolygon(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_4" << std::endl;
}


/* CPPScope(name=(auto) PolyTester::void test_SkOffsetSimplePolygon(SkScalar offset);) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    PolyTester *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_5" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->test_SkOffsetSimplePolygon(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_5" << std::endl;
}


/* CPPScope(name=(auto) PolyTester::void test_SkTriangulateSimplePolygon();) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    PolyTester *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_6" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->test_SkTriangulateSimplePolygon();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_6" << std::endl;
}


/* CPPScope(name=(auto) PolyTester::~PolyTester();) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_7" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    } // end shim_7" << std::endl;
}


void __attribute__((visibility ("default"))) (*FUZZER_SHIMS[])(void **, void **, const char *) = {
    &shim_0,
    &shim_1,
    &shim_2,
    &shim_3,
    &shim_4,
    &shim_5,
    &shim_6,
    &shim_7,
};

