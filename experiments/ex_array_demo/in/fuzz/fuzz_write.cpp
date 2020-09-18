

#include <string.h>
#include <string>
#include <iostream>

unsigned long CURR_ID = 0;

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) { }

extern "C" void __attribute__((visibility ("default"))) shim_init() {
    CURR_ID = 0;

    std::cout << "#include \"lib.h\"\n" << std::endl;
    std::cout << "\n#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))\n\nstruct GFUZZ_BUNDLE {\npublic:\n    void *active;\n    void *inactive;\n    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}\n};\n\n#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)\n" << std::endl;

    std::cout << "int main() {" << std::endl;
}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {
    std::cout << "}" << std::endl;
}


/* CPPScope(name=fuzz1) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Test *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_0" << std::endl;
    int _a0[4];
    memcpy(&_a0, context + 0, 4 * 4);
    std::cout << "    int _a0[4] = {";
    for (int i = 0; i < 4; ++i) {
        if (i % 16 == 0 && 4 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 4 - 1) std::cout << ", ";
    }
    if (4 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->fuzz1(" << "_a0" << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_0" << std::endl;
}


/* CPPScope(name=fuzz2) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Test *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_1" << std::endl;
    int _a0[32];
    memcpy(&_a0, context + 0, 4 * 32);
    std::cout << "    int _a0[32] = {";
    for (int i = 0; i < 32; ++i) {
        if (i % 16 == 0 && 32 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 32 - 1) std::cout << ", ";
    }
    if (32 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    float _a1[8];
    memcpy(&_a1, context + 128, 4 * 8);
    std::cout << "    float _a1[8] = {";
    for (int i = 0; i < 8; ++i) {
        if (i % 16 == 0 && 8 > 16) std::cout << std::endl << "        ";
        std::cout << _a1[i];
        if (i < 8 - 1) std::cout << ", ";
    }
    if (8 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->fuzz2(" << "_a0" << ", " << "_a1" << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_1" << std::endl;
}


/* CPPScope(name=(auto) Test::Test();) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Test *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_2" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(Test);\n        Test ref = Test();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_2" << std::endl;
}


/* CPPScope(name=(auto) Test::~Test();) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_3" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_3" << std::endl;
}


void __attribute__((visibility ("default"))) (*FUZZER_SHIMS[])(void **, void **, const char *) = {
    &shim_0,
    &shim_1,
    &shim_2,
    &shim_3,
};

