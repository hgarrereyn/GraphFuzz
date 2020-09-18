

#include <string.h>
#include <string>
#include <iostream>

unsigned long CURR_ID = 0;

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) { }

extern "C" void __attribute__((visibility ("default"))) shim_init() {
    CURR_ID = 0;

    std::cout << "#include \"<iowow/iwkv.h>\"\n#include \"db_tracker.h\"\n" << std::endl;
    std::cout << "\n#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))\n\nstruct GFUZZ_BUNDLE {\npublic:\n    void *active;\n    void *inactive;\n    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}\n};\n\n#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)\n" << std::endl;

    std::cout << "int main() {" << std::endl;
}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {
    std::cout << "}" << std::endl;
}


/* CPPScope(name=open) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    IWKV *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_0" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new_db();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_0" << std::endl;
}


/* CPPScope(name=close) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_1" << std::endl;

    std::cout << "        // forget" << std::endl;

    std::cout << "    } // end shim_1" << std::endl;
}


/* CPPScope(name=iwkv_db_destroy(IWDB *dbp);) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_2" << std::endl;

    std::cout << "        // iwkv_db_destroy(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_2" << std::endl;
}


/* CPPScope(name=iwkv_new_db) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    IWKV *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    IWDB *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_3" << std::endl;

    std::cout << "        " << "var_" << _o1 << " = MAKE(IWDB);\n        uint32_t a;\n        iwkv_new_db(*" << "var_" << _i0 << ", " << _a0 << ", &a, " << "var_" << _o1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_3" << std::endl;
}


/* CPPScope(name=iwkv_get(IWDB db, const IWKV_val *key, IWKV_val *oval);) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    IWDB *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    IWKV_val *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_4" << std::endl;

    std::cout << "        IWKV_val oval;\n        iwkv_get(*" << "var_" << _i0 << ", " << "var_" << _i1 << ", &oval);\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_4" << std::endl;
}


/* CPPScope(name=iwkv_db_set_meta(IWDB db, void *buf, size_t sz);) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    uint8_t _a1;
    memcpy(&_a1, context + 100, sizeof(uint8_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    IWDB *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_5" << std::endl;
    char _a0[100];
    memcpy(&_a0, context + 0, 1 * 100);
    std::cout << "    char _a0[100] = {";
    for (int i = 0; i < 100; ++i) {
        if (i % 16 == 0 && 100 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 100 - 1) std::cout << ", ";
    }
    if (100 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        iwkv_db_set_meta(*" << "var_" << _i0 << ", &" << "_a0" << ", " << (int)_a1 << " % 100);\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_5" << std::endl;
}


/* CPPScope(name=iwkv_db_get_meta) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    IWDB *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_6" << std::endl;

    std::cout << "        char buffer[100];\n        size_t rsz;\n        iwkv_db_get_meta(*" << "var_" << _i0 << ", &buffer, 100, &rsz);\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_6" << std::endl;
}


/* CPPScope(name=(auto) IWDB::void iwkv_db_cache_release(IWDB db);) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    IWDB *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_7" << std::endl;

    std::cout << "        iwkv_db_cache_release(*" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_7" << std::endl;
}


/* CPPScope(name=(auto) IWDB::void iwkv_put(IWDB db, IWKV_val * key, IWKV_val * val, uint8_t opflags);) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    IWDB *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    IWKV_val *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    IWKV_val *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_8" << std::endl;

    std::cout << "        iwkv_put(*" << "var_" << _i0 << ", " << "var_" << _i1 << ", " << "var_" << _i2 << ", " << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_8" << std::endl;
}


/* CPPScope(name=(auto) IWDB::void iwkv_del(IWDB db, const IWKV_val * key, iwkv_opflags opflags);) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    IWDB *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    IWKV_val *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_9" << std::endl;

    std::cout << "        iwkv_del(*" << "var_" << _i0 << ", " << "var_" << _i1 << ", " << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_9" << std::endl;
}


/* CPPScope(name=create) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    uint8_t _a1;
    memcpy(&_a1, context + 100, sizeof(uint8_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    IWKV_val *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_10" << std::endl;
    char _a0[100];
    memcpy(&_a0, context + 0, 1 * 100);
    std::cout << "    char _a0[100] = {";
    for (int i = 0; i < 100; ++i) {
        if (i % 16 == 0 && 100 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 100 - 1) std::cout << ", ";
    }
    if (100 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(IWKV_val);\n        " << "var_" << _o0 << "->data = (char *)calloc(100,1);\n        memcpy(" << "var_" << _o0 << "->data, " << "_a0" << ", 100);\n        " << "var_" << _o0 << "->size = " << (int)_a1 << " % 100;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_10" << std::endl;
}


/* CPPScope(name=delete) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_11" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << "->data);\n        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_11" << std::endl;
}


/* CPPScope(name=create) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 6) {
        case 0: _a0 = "IWKV_cursor_op::IWKV_CURSOR_BEFORE_FIRST"; break;
        case 1: _a0 = "IWKV_cursor_op::IWKV_CURSOR_AFTER_LAST"; break;
        case 2: _a0 = "IWKV_cursor_op::IWKV_CURSOR_NEXT"; break;
        case 3: _a0 = "IWKV_cursor_op::IWKV_CURSOR_PREV"; break;
        case 4: _a0 = "IWKV_cursor_op::IWKV_CURSOR_EQ"; break;
        case 5: _a0 = "IWKV_cursor_op::IWKV_CURSOR_GE"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    IWDB *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    IWKV_val *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    IWKV_cursor *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_12" << std::endl;

    std::cout << "        " << "var_" << _o2 << " = MAKE(IWKV_cursor);\n        iwrc rc = iwkv_cursor_open(*" << "var_" << _i0 << ", " << "var_" << _o2 << ", " << _a0 << ", " << "var_" << _i1 << ");\n        if (rc) {\n          graphfuzz_bail();\n        }\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_12" << std::endl;
}


/* CPPScope(name=close) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_13" << std::endl;

    std::cout << "        iwkv_cursor_close(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_13" << std::endl;
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
    &shim_8,
    &shim_9,
    &shim_10,
    &shim_11,
    &shim_12,
    &shim_13,
};

