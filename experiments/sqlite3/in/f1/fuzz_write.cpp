

#include <string.h>
#include <string>
#include <iostream>

unsigned long CURR_ID = 0;

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) { }

extern "C" void __attribute__((visibility ("default"))) shim_init() {
    CURR_ID = 0;

    std::cout << "#include \"db_tracker.h\"\nextern \"C\" {\n    #include \"extra.h\" \n}\nextern \"C\" {\n    #include \"sqlite3.h\" \n}\n" << std::endl;
    std::cout << "\n#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))\n\nstruct GFUZZ_BUNDLE {\npublic:\n    void *active;\n    void *inactive;\n    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}\n};\n\n#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)\n" << std::endl;

    std::cout << "int main() {" << std::endl;
}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {
    std::cout << "}" << std::endl;
}


/* CPPScope(name=open_memory) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3 *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_0" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new_database();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_0" << std::endl;
}


/* CPPScope(name=forget) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_1" << std::endl;

    std::cout << "        // pass" << std::endl;

    std::cout << "    } // end shim_1" << std::endl;
}


/* CPPScope(name=db_config_SQLITE_DBCONFIG_MAINDBNAME) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3 *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_2" << std::endl;
    char _a0[256];
    memcpy(&_a0, context + 0, 1 * 256);
    std::cout << "    char _a0[256] = {";
    for (int i = 0; i < 256; ++i) {
        if (i % 16 == 0 && 256 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 256 - 1) std::cout << ", ";
    }
    if (256 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "_a0" << "[255] = 0;\n        sqlite3_db_config(" << "var_" << _i0 << ", 1000, " << "_a0" << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_2" << std::endl;
}


/* CPPScope(name=db_config_SQLITE_DBCONFIG_LOOKASIDE) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3 *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_3" << std::endl;

    std::cout << "        sqlite3_db_config(" << "var_" << _i0 << ", 1001, 0, " << _a0 << ", " << _a1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_3" << std::endl;
}


/* CPPScope(name=int sqlite3_db_config_other) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3 *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_4" << std::endl;

    std::cout << "        int op = (" << _a0 << " % 16) + 1002;\n        sqlite3_db_config(" << "var_" << _i0 << ", op, " << _a1 << ", 0);\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_4" << std::endl;
}


/* CPPScope(name=(auto) sqlite3::int sqlite3_busy_timeout(sqlite3 * None, int ms);) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3 *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_5" << std::endl;

    std::cout << "        sqlite3_busy_timeout(" << "var_" << _i0 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_5" << std::endl;
}


/* CPPScope(name=(auto) sqlite3::int sqlite3_changes(sqlite3 * None);) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3 *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_6" << std::endl;

    std::cout << "        sqlite3_changes(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_6" << std::endl;
}


/* CPPScope(name=(auto) sqlite3::int sqlite3_db_cacheflush(sqlite3 * None);) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3 *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_7" << std::endl;

    std::cout << "        sqlite3_db_cacheflush(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_7" << std::endl;
}


/* CPPScope(name=(auto) sqlite3::int sqlite3_db_release_memory(sqlite3 * None);) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3 *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_8" << std::endl;

    std::cout << "        sqlite3_db_release_memory(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_8" << std::endl;
}


/* CPPScope(name=(auto) sqlite3::int sqlite3_total_changes(sqlite3 * None);) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3 *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_9" << std::endl;

    std::cout << "        sqlite3_total_changes(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_9" << std::endl;
}


/* CPPScope(name=prepare_v2) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3 *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_10" << std::endl;
    char _a0[256];
    memcpy(&_a0, context + 0, 1 * 256);
    std::cout << "    char _a0[256] = {";
    for (int i = 0; i < 256; ++i) {
        if (i % 16 == 0 && 256 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 256 - 1) std::cout << ", ";
    }
    if (256 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        sqlite3_prepare_v2(" << "var_" << _i0 << ", " << "_a0" << ", 256, &" << "var_" << _o1 << ", 0);\n        if (" << "var_" << _o1 << " == 0) {\n          close_all();\n          graphfuzz_bail();\n        }\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_10" << std::endl;
}


/* CPPScope(name=sqlite3_finalize) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_11" << std::endl;

    std::cout << "        sqlite3_finalize(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_11" << std::endl;
}


/* CPPScope(name=int sqlite3_bind_parameter_index(sqlite3_stmt*, const char *zName);) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_12" << std::endl;
    char _a0[64];
    memcpy(&_a0, context + 0, 1 * 64);
    std::cout << "    char _a0[64] = {";
    for (int i = 0; i < 64; ++i) {
        if (i % 16 == 0 && 64 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 64 - 1) std::cout << ", ";
    }
    if (64 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "_a0" << "[63] = 0;\n        sqlite3_bind_parameter_index(" << "var_" << _i0 << ", " << "_a0" << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_12" << std::endl;
}


/* CPPScope(name=sqlite3_value *sqlite3_column_value(sqlite3_stmt*, int iCol);) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    unprotected_sqlite3_value *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_13" << std::endl;

    std::cout << "        " << "var_" << _o1 << " = sqlite3_column_value(" << "var_" << _i0 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_13" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_double(sqlite3_stmt * None, int None, double None);) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    double _a1;
    memcpy(&_a1, context + 4, sizeof(double));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_14" << std::endl;

    std::cout << "        sqlite3_bind_double(" << "var_" << _i0 << ", " << _a0 << ", " << _a1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_14" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_int(sqlite3_stmt * None, int None, int None);) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_15" << std::endl;

    std::cout << "        sqlite3_bind_int(" << "var_" << _i0 << ", " << _a0 << ", " << _a1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_15" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_int64(sqlite3_stmt * None, int None, sqlite3_int64 None);) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int64_t _a1;
    memcpy(&_a1, context + 4, sizeof(int64_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_16" << std::endl;

    std::cout << "        sqlite3_bind_int64(" << "var_" << _i0 << ", " << _a0 << ", " << _a1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_16" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_null(sqlite3_stmt * None, int None);) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_17" << std::endl;

    std::cout << "        sqlite3_bind_null(" << "var_" << _i0 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_17" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_value(sqlite3_stmt * None, int None, const sqlite3_value * None);) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_18" << std::endl;

    std::cout << "        sqlite3_bind_value(" << "var_" << _i0 << ", " << _a0 << ", " << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_18" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_value(sqlite3_stmt * None, int None, const unprotected_sqlite3_value * None);) */
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    unprotected_sqlite3_value *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_19" << std::endl;

    std::cout << "        sqlite3_bind_value(" << "var_" << _i0 << ", " << _a0 << ", " << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_19" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_zeroblob(sqlite3_stmt * None, int None, int n);) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_20" << std::endl;

    std::cout << "        sqlite3_bind_zeroblob(" << "var_" << _i0 << ", " << _a0 << ", " << _a1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_20" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_zeroblob64(sqlite3_stmt * None, int None, sqlite3_uint64 None);) */
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    uint64_t _a1;
    memcpy(&_a1, context + 4, sizeof(uint64_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_21" << std::endl;

    std::cout << "        sqlite3_bind_zeroblob64(" << "var_" << _i0 << ", " << _a0 << ", " << _a1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_21" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_step(sqlite3_stmt * None);) */
extern "C" void shim_22(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_22" << std::endl;

    std::cout << "        sqlite3_step(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_22" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_reset(sqlite3_stmt * pStmt);) */
extern "C" void shim_23(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_23" << std::endl;

    std::cout << "        sqlite3_reset(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_23" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_clear_bindings(sqlite3_stmt * None);) */
extern "C" void shim_24(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_24" << std::endl;

    std::cout << "        sqlite3_clear_bindings(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_24" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_parameter_count(sqlite3_stmt * None);) */
extern "C" void shim_25(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_25" << std::endl;

    std::cout << "        sqlite3_bind_parameter_count(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_25" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::const char * sqlite3_bind_parameter_name(sqlite3_stmt * None, int None);) */
extern "C" void shim_26(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_26" << std::endl;

    std::cout << "        sqlite3_bind_parameter_name(" << "var_" << _i0 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_26" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_stmt_busy(sqlite3_stmt * None);) */
extern "C" void shim_27(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_27" << std::endl;

    std::cout << "        sqlite3_stmt_busy(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_27" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::void sqlite3_next_stmt(sqlite3 * pDb, sqlite3_stmt * pStmt);) */
extern "C" void shim_28(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3 *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_28" << std::endl;

    std::cout << "        sqlite3_next_stmt(" << "var_" << _i0 << ", " << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_28" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_stmt_isexplain(sqlite3_stmt * pStmt);) */
extern "C" void shim_29(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_29" << std::endl;

    std::cout << "        sqlite3_stmt_isexplain(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_29" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_stmt_readonly(sqlite3_stmt * pStmt);) */
extern "C" void shim_30(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_30" << std::endl;

    std::cout << "        sqlite3_stmt_readonly(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_30" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_stmt_status(sqlite3_stmt * None, int op, int resetFlg);) */
extern "C" void shim_31(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_31" << std::endl;

    std::cout << "        sqlite3_stmt_status(" << "var_" << _i0 << ", " << _a0 << ", " << _a1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_31" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_column_count(sqlite3_stmt * pStmt);) */
extern "C" void shim_32(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_32" << std::endl;

    std::cout << "        sqlite3_column_count(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_32" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_data_count(sqlite3_stmt * pStmt);) */
extern "C" void shim_33(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_33" << std::endl;

    std::cout << "        sqlite3_data_count(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_33" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::const char * sqlite3_column_decltype(sqlite3_stmt * None, int None);) */
extern "C" void shim_34(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_34" << std::endl;

    std::cout << "        sqlite3_column_decltype(" << "var_" << _i0 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_34" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::const void * sqlite3_column_decltype16(sqlite3_stmt * None, int None);) */
extern "C" void shim_35(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_35" << std::endl;

    std::cout << "        sqlite3_column_decltype16(" << "var_" << _i0 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_35" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::const void * sqlite3_column_blob(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_36(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_36" << std::endl;

    std::cout << "        sqlite3_column_blob(" << "var_" << _i0 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_36" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::double sqlite3_column_double(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_37(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_37" << std::endl;

    std::cout << "        sqlite3_column_double(" << "var_" << _i0 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_37" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_column_int(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_38(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_38" << std::endl;

    std::cout << "        sqlite3_column_int(" << "var_" << _i0 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_38" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::sqlite3_int64 sqlite3_column_int64(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_39(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_39" << std::endl;

    std::cout << "        sqlite3_column_int64(" << "var_" << _i0 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_39" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::const unsigned char * sqlite3_column_text(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_40(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_40" << std::endl;

    std::cout << "        sqlite3_column_text(" << "var_" << _i0 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_40" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::const void * sqlite3_column_text16(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_41(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_41" << std::endl;

    std::cout << "        sqlite3_column_text16(" << "var_" << _i0 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_41" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_column_bytes(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_42(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_42" << std::endl;

    std::cout << "        sqlite3_column_bytes(" << "var_" << _i0 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_42" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_column_bytes16(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_43(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_43" << std::endl;

    std::cout << "        sqlite3_column_bytes16(" << "var_" << _i0 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_43" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_column_type(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_44(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_stmt *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_44" << std::endl;

    std::cout << "        sqlite3_column_type(" << "var_" << _i0 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_44" << std::endl;
}


/* CPPScope(name=forget) */
extern "C" void shim_45(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_45" << std::endl;

    std::cout << "        // pass" << std::endl;

    std::cout << "    } // end shim_45" << std::endl;
}


/* CPPScope(name=sqlite3_value *sqlite3_value_dup(const sqlite3_value*);) */
extern "C" void shim_46(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_46" << std::endl;

    std::cout << "        " << "var_" << _o1 << " = sqlite3_value_dup(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_46" << std::endl;
}


/* CPPScope(name=sqlite3_value *sqlite3_value_dup(const sqlite3_value*);) */
extern "C" void shim_47(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    unprotected_sqlite3_value *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_47" << std::endl;

    std::cout << "        " << "var_" << _o1 << " = sqlite3_value_dup(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_47" << std::endl;
}


/* CPPScope(name=void sqlite3_value_free(sqlite3_value*);) */
extern "C" void shim_48(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_48" << std::endl;

    std::cout << "        sqlite3_value_free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_48" << std::endl;
}


/* CPPScope(name=void *sqlite3_value_pointer(sqlite3_value*, const char*);) */
extern "C" void shim_49(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_49" << std::endl;
    char _a0[64];
    memcpy(&_a0, context + 0, 1 * 64);
    std::cout << "    char _a0[64] = {";
    for (int i = 0; i < 64; ++i) {
        if (i % 16 == 0 && 64 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 64 - 1) std::cout << ", ";
    }
    if (64 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "_a0" << "[63] = 0;\n        sqlite3_value_pointer(" << "var_" << _i0 << ", " << "_a0" << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_49" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_value::const void * sqlite3_value_blob(sqlite3_value * None);) */
extern "C" void shim_50(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_50" << std::endl;

    std::cout << "        sqlite3_value_blob(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_50" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_value::double sqlite3_value_double(sqlite3_value * None);) */
extern "C" void shim_51(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_51" << std::endl;

    std::cout << "        sqlite3_value_double(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_51" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_value::int sqlite3_value_int(sqlite3_value * None);) */
extern "C" void shim_52(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_52" << std::endl;

    std::cout << "        sqlite3_value_int(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_52" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_value::sqlite3_int64 sqlite3_value_int64(sqlite3_value * None);) */
extern "C" void shim_53(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_53" << std::endl;

    std::cout << "        sqlite3_value_int64(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_53" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_value::const unsigned char * sqlite3_value_text(sqlite3_value * None);) */
extern "C" void shim_54(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_54" << std::endl;

    std::cout << "        sqlite3_value_text(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_54" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_value::const void * sqlite3_value_text16(sqlite3_value * None);) */
extern "C" void shim_55(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_55" << std::endl;

    std::cout << "        sqlite3_value_text16(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_55" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_value::const void * sqlite3_value_text16le(sqlite3_value * None);) */
extern "C" void shim_56(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_56" << std::endl;

    std::cout << "        sqlite3_value_text16le(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_56" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_value::const void * sqlite3_value_text16be(sqlite3_value * None);) */
extern "C" void shim_57(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_57" << std::endl;

    std::cout << "        sqlite3_value_text16be(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_57" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_value::int sqlite3_value_bytes(sqlite3_value * None);) */
extern "C" void shim_58(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_58" << std::endl;

    std::cout << "        sqlite3_value_bytes(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_58" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_value::int sqlite3_value_bytes16(sqlite3_value * None);) */
extern "C" void shim_59(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_59" << std::endl;

    std::cout << "        sqlite3_value_bytes16(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_59" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_value::int sqlite3_value_type(sqlite3_value * None);) */
extern "C" void shim_60(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_60" << std::endl;

    std::cout << "        sqlite3_value_type(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_60" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_value::int sqlite3_value_numeric_type(sqlite3_value * None);) */
extern "C" void shim_61(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_61" << std::endl;

    std::cout << "        sqlite3_value_numeric_type(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_61" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_value::int sqlite3_value_nochange(sqlite3_value * None);) */
extern "C" void shim_62(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_62" << std::endl;

    std::cout << "        sqlite3_value_nochange(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_62" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_value::int sqlite3_value_frombind(sqlite3_value * None);) */
extern "C" void shim_63(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_value *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_63" << std::endl;

    std::cout << "        sqlite3_value_frombind(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_63" << std::endl;
}


/* CPPScope(name=sqlite3_str *sqlite3_str_new(sqlite3*);) */
extern "C" void shim_64(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3 *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sqlite3_str *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_64" << std::endl;

    std::cout << "        " << "var_" << _o1 << " = sqlite3_str_new(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_64" << std::endl;
}


/* CPPScope(name=char *sqlite3_str_finish(sqlite3_str*);) */
extern "C" void shim_65(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_65" << std::endl;

    std::cout << "        char *out = sqlite3_str_finish(" << "var_" << _i0 << ");\n        sqlite3_free(out);" << std::endl;

    std::cout << "    } // end shim_65" << std::endl;
}


/* CPPScope(name=void sqlite3_str_append(sqlite3_str*, const char *zIn, int N);) */
extern "C" void shim_66(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    uint32_t _a1;
    memcpy(&_a1, context + 256, sizeof(uint32_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_str *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_66" << std::endl;
    char _a0[256];
    memcpy(&_a0, context + 0, 1 * 256);
    std::cout << "    char _a0[256] = {";
    for (int i = 0; i < 256; ++i) {
        if (i % 16 == 0 && 256 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 256 - 1) std::cout << ", ";
    }
    if (256 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "_a0" << "[255] = 0;\n        int size = strlen(" << "_a0" << ");\n        if (size != 0) {\n          int len = " << _a1 << " % size;\n          sqlite3_str_append(" << "var_" << _i0 << ", " << "_a0" << ", len);\n        }\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_66" << std::endl;
}


/* CPPScope(name=void sqlite3_str_appendall(sqlite3_str*, const char *zIn);) */
extern "C" void shim_67(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_str *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_67" << std::endl;
    char _a0[256];
    memcpy(&_a0, context + 0, 1 * 256);
    std::cout << "    char _a0[256] = {";
    for (int i = 0; i < 256; ++i) {
        if (i % 16 == 0 && 256 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 256 - 1) std::cout << ", ";
    }
    if (256 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "_a0" << "[255] = 0;\n        sqlite3_str_appendall(" << "var_" << _i0 << ", " << "_a0" << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_67" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_str::void sqlite3_str_reset(sqlite3_str * None);) */
extern "C" void shim_68(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_str *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_68" << std::endl;

    std::cout << "        sqlite3_str_reset(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_68" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_str::void sqlite3_str_appendchar(sqlite3_str * None, int N, char C);) */
extern "C" void shim_69(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    char _a1;
    memcpy(&_a1, context + 4, sizeof(char));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_str *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_69" << std::endl;

    std::cout << "        sqlite3_str_appendchar(" << "var_" << _i0 << ", " << _a0 << ", " << (int)_a1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_69" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_str::int sqlite3_str_errcode(sqlite3_str * None);) */
extern "C" void shim_70(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_str *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_70" << std::endl;

    std::cout << "        sqlite3_str_errcode(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_70" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_str::int sqlite3_str_length(sqlite3_str * None);) */
extern "C" void shim_71(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_str *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_71" << std::endl;

    std::cout << "        sqlite3_str_length(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_71" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_str::char * sqlite3_str_value(sqlite3_str * None);) */
extern "C" void shim_72(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_str *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_72" << std::endl;

    std::cout << "        sqlite3_str_value(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_72" << std::endl;
}


/* CPPScope(name=sqlite3_backup *sqlite3_backup_init) */
extern "C" void shim_73(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3 *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sqlite3 *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sqlite3_backup *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_73" << std::endl;

    std::cout << "        " << "var_" << _o2 << " = sqlite3_backup_init(" << "var_" << _i0 << ", \"main\", " << "var_" << _i1 << ", \"main\");\n        if (" << "var_" << _o2 << " == 0) {\n          close_all();\n          graphfuzz_bail();\n        }\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_73" << std::endl;
}


/* CPPScope(name=int sqlite3_backup_finish(sqlite3_backup *p);) */
extern "C" void shim_74(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_74" << std::endl;

    std::cout << "        sqlite3_backup_finish(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_74" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_backup::int sqlite3_backup_step(sqlite3_backup * p, int nPage);) */
extern "C" void shim_75(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_backup *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_75" << std::endl;

    std::cout << "        sqlite3_backup_step(" << "var_" << _i0 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_75" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_backup::int sqlite3_backup_remaining(sqlite3_backup * p);) */
extern "C" void shim_76(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_backup *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_76" << std::endl;

    std::cout << "        sqlite3_backup_remaining(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_76" << std::endl;
}


/* CPPScope(name=(auto) sqlite3_backup::int sqlite3_backup_pagecount(sqlite3_backup * p);) */
extern "C" void shim_77(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sqlite3_backup *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_77" << std::endl;

    std::cout << "        sqlite3_backup_pagecount(" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_77" << std::endl;
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
    &shim_14,
    &shim_15,
    &shim_16,
    &shim_17,
    &shim_18,
    &shim_19,
    &shim_20,
    &shim_21,
    &shim_22,
    &shim_23,
    &shim_24,
    &shim_25,
    &shim_26,
    &shim_27,
    &shim_28,
    &shim_29,
    &shim_30,
    &shim_31,
    &shim_32,
    &shim_33,
    &shim_34,
    &shim_35,
    &shim_36,
    &shim_37,
    &shim_38,
    &shim_39,
    &shim_40,
    &shim_41,
    &shim_42,
    &shim_43,
    &shim_44,
    &shim_45,
    &shim_46,
    &shim_47,
    &shim_48,
    &shim_49,
    &shim_50,
    &shim_51,
    &shim_52,
    &shim_53,
    &shim_54,
    &shim_55,
    &shim_56,
    &shim_57,
    &shim_58,
    &shim_59,
    &shim_60,
    &shim_61,
    &shim_62,
    &shim_63,
    &shim_64,
    &shim_65,
    &shim_66,
    &shim_67,
    &shim_68,
    &shim_69,
    &shim_70,
    &shim_71,
    &shim_72,
    &shim_73,
    &shim_74,
    &shim_75,
    &shim_76,
    &shim_77,
};

