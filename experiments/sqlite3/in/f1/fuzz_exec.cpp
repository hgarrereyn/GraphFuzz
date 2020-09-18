#include "db_tracker.h"
extern "C" {
    #include "extra.h" 
}
extern "C" {
    #include "sqlite3.h" 
}


#include <string.h>
#include <stdlib.h>
#include <cstdint>

extern "C" int graphfuzz_try();
extern "C" void graphfuzz_bail();

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) {

}

extern "C" void __attribute__((visibility ("default"))) shim_init() {

}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {
close_all();

}


#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))

struct GFUZZ_BUNDLE {
public:
    void *active;
    void *inactive;
    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}
};

#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)



/* CPPScope(name=open_memory) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    sqlite3 *_o0;
	_o0 = new_database();
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=forget) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    sqlite3 *_i0 = reinterpret_cast<sqlite3 *>(in_ref[0]);
	// pass
	
}


/* CPPScope(name=db_config_SQLITE_DBCONFIG_MAINDBNAME) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    sqlite3 *_i0 = reinterpret_cast<sqlite3 *>(in_ref[0]);
    char _a0[256];
    memcpy(&_a0, context + 0, 1 * 256);
    sqlite3 *_o0;
	_a0[255] = 0;
	sqlite3_db_config(_i0, 1000, _a0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=db_config_SQLITE_DBCONFIG_LOOKASIDE) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    sqlite3 *_i0 = reinterpret_cast<sqlite3 *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    sqlite3 *_o0;
	sqlite3_db_config(_i0, 1001, 0, _a0, _a1);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=int sqlite3_db_config_other) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    sqlite3 *_i0 = reinterpret_cast<sqlite3 *>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    sqlite3 *_o0;
	int op = (_a0 % 16) + 1002;
	sqlite3_db_config(_i0, op, _a1, 0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3::int sqlite3_busy_timeout(sqlite3 * None, int ms);) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    sqlite3 *_i0 = reinterpret_cast<sqlite3 *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3 *_o0;
	sqlite3_busy_timeout(_i0, _a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3::int sqlite3_changes(sqlite3 * None);) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    sqlite3 *_i0 = reinterpret_cast<sqlite3 *>(in_ref[0]);
    sqlite3 *_o0;
	sqlite3_changes(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3::int sqlite3_db_cacheflush(sqlite3 * None);) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    sqlite3 *_i0 = reinterpret_cast<sqlite3 *>(in_ref[0]);
    sqlite3 *_o0;
	sqlite3_db_cacheflush(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3::int sqlite3_db_release_memory(sqlite3 * None);) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    sqlite3 *_i0 = reinterpret_cast<sqlite3 *>(in_ref[0]);
    sqlite3 *_o0;
	sqlite3_db_release_memory(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3::int sqlite3_total_changes(sqlite3 * None);) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    sqlite3 *_i0 = reinterpret_cast<sqlite3 *>(in_ref[0]);
    sqlite3 *_o0;
	sqlite3_total_changes(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=prepare_v2) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    sqlite3 *_i0 = reinterpret_cast<sqlite3 *>(in_ref[0]);
    char _a0[256];
    memcpy(&_a0, context + 0, 1 * 256);
    sqlite3 *_o0;
    sqlite3_stmt *_o1;
	sqlite3_prepare_v2(_i0, _a0, 256, &_o1, 0);
	if (_o1 == 0) {
	  close_all();
	  graphfuzz_bail();
	}
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=sqlite3_finalize) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
	sqlite3_finalize(_i0);
	
}


/* CPPScope(name=int sqlite3_bind_parameter_index(sqlite3_stmt*, const char *zName);) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    char _a0[64];
    memcpy(&_a0, context + 0, 1 * 64);
    sqlite3_stmt *_o0;
	_a0[63] = 0;
	sqlite3_bind_parameter_index(_i0, _a0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=sqlite3_value *sqlite3_column_value(sqlite3_stmt*, int iCol);) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3_stmt *_o0;
    unprotected_sqlite3_value *_o1;
	_o1 = sqlite3_column_value(_i0, _a0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_double(sqlite3_stmt * None, int None, double None);) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    double _a1;
    memcpy(&_a1, context + 4, sizeof(double));
    sqlite3_stmt *_o0;
	sqlite3_bind_double(_i0, _a0, _a1);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_int(sqlite3_stmt * None, int None, int None);) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    sqlite3_stmt *_o0;
	sqlite3_bind_int(_i0, _a0, _a1);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_int64(sqlite3_stmt * None, int None, sqlite3_int64 None);) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int64_t _a1;
    memcpy(&_a1, context + 4, sizeof(int64_t));
    sqlite3_stmt *_o0;
	sqlite3_bind_int64(_i0, _a0, _a1);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_null(sqlite3_stmt * None, int None);) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3_stmt *_o0;
	sqlite3_bind_null(_i0, _a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_value(sqlite3_stmt * None, int None, const sqlite3_value * None);) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    sqlite3_value *_i1 = reinterpret_cast<sqlite3_value *>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3_stmt *_o0;
    sqlite3_value *_o1;
	sqlite3_bind_value(_i0, _a0, _i1);
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_value(sqlite3_stmt * None, int None, const unprotected_sqlite3_value * None);) */
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    unprotected_sqlite3_value *_i1 = reinterpret_cast<unprotected_sqlite3_value *>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3_stmt *_o0;
    unprotected_sqlite3_value *_o1;
	sqlite3_bind_value(_i0, _a0, _i1);
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_zeroblob(sqlite3_stmt * None, int None, int n);) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    sqlite3_stmt *_o0;
	sqlite3_bind_zeroblob(_i0, _a0, _a1);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_zeroblob64(sqlite3_stmt * None, int None, sqlite3_uint64 None);) */
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    uint64_t _a1;
    memcpy(&_a1, context + 4, sizeof(uint64_t));
    sqlite3_stmt *_o0;
	sqlite3_bind_zeroblob64(_i0, _a0, _a1);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_step(sqlite3_stmt * None);) */
extern "C" void shim_22(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    sqlite3_stmt *_o0;
	sqlite3_step(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_reset(sqlite3_stmt * pStmt);) */
extern "C" void shim_23(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    sqlite3_stmt *_o0;
	sqlite3_reset(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_clear_bindings(sqlite3_stmt * None);) */
extern "C" void shim_24(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    sqlite3_stmt *_o0;
	sqlite3_clear_bindings(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_bind_parameter_count(sqlite3_stmt * None);) */
extern "C" void shim_25(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    sqlite3_stmt *_o0;
	sqlite3_bind_parameter_count(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::const char * sqlite3_bind_parameter_name(sqlite3_stmt * None, int None);) */
extern "C" void shim_26(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3_stmt *_o0;
	sqlite3_bind_parameter_name(_i0, _a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_stmt_busy(sqlite3_stmt * None);) */
extern "C" void shim_27(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    sqlite3_stmt *_o0;
	sqlite3_stmt_busy(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::void sqlite3_next_stmt(sqlite3 * pDb, sqlite3_stmt * pStmt);) */
extern "C" void shim_28(void **in_ref, void **out_ref, const char *context) {
    sqlite3 *_i0 = reinterpret_cast<sqlite3 *>(in_ref[0]);
    sqlite3_stmt *_i1 = reinterpret_cast<sqlite3_stmt *>(in_ref[1]);
    sqlite3 *_o0;
    sqlite3_stmt *_o1;
	sqlite3_next_stmt(_i0, _i1);
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_stmt_isexplain(sqlite3_stmt * pStmt);) */
extern "C" void shim_29(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    sqlite3_stmt *_o0;
	sqlite3_stmt_isexplain(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_stmt_readonly(sqlite3_stmt * pStmt);) */
extern "C" void shim_30(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    sqlite3_stmt *_o0;
	sqlite3_stmt_readonly(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_stmt_status(sqlite3_stmt * None, int op, int resetFlg);) */
extern "C" void shim_31(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    sqlite3_stmt *_o0;
	sqlite3_stmt_status(_i0, _a0, _a1);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_column_count(sqlite3_stmt * pStmt);) */
extern "C" void shim_32(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    sqlite3_stmt *_o0;
	sqlite3_column_count(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_data_count(sqlite3_stmt * pStmt);) */
extern "C" void shim_33(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    sqlite3_stmt *_o0;
	sqlite3_data_count(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::const char * sqlite3_column_decltype(sqlite3_stmt * None, int None);) */
extern "C" void shim_34(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3_stmt *_o0;
	sqlite3_column_decltype(_i0, _a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::const void * sqlite3_column_decltype16(sqlite3_stmt * None, int None);) */
extern "C" void shim_35(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3_stmt *_o0;
	sqlite3_column_decltype16(_i0, _a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::const void * sqlite3_column_blob(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_36(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3_stmt *_o0;
	sqlite3_column_blob(_i0, _a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::double sqlite3_column_double(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_37(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3_stmt *_o0;
	sqlite3_column_double(_i0, _a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_column_int(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_38(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3_stmt *_o0;
	sqlite3_column_int(_i0, _a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::sqlite3_int64 sqlite3_column_int64(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_39(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3_stmt *_o0;
	sqlite3_column_int64(_i0, _a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::const unsigned char * sqlite3_column_text(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_40(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3_stmt *_o0;
	sqlite3_column_text(_i0, _a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::const void * sqlite3_column_text16(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_41(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3_stmt *_o0;
	sqlite3_column_text16(_i0, _a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_column_bytes(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_42(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3_stmt *_o0;
	sqlite3_column_bytes(_i0, _a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_column_bytes16(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_43(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3_stmt *_o0;
	sqlite3_column_bytes16(_i0, _a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_stmt::int sqlite3_column_type(sqlite3_stmt * None, int iCol);) */
extern "C" void shim_44(void **in_ref, void **out_ref, const char *context) {
    sqlite3_stmt *_i0 = reinterpret_cast<sqlite3_stmt *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3_stmt *_o0;
	sqlite3_column_type(_i0, _a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=forget) */
extern "C" void shim_45(void **in_ref, void **out_ref, const char *context) {
    unprotected_sqlite3_value *_i0 = reinterpret_cast<unprotected_sqlite3_value *>(in_ref[0]);
	// pass
	
}


/* CPPScope(name=sqlite3_value *sqlite3_value_dup(const sqlite3_value*);) */
extern "C" void shim_46(void **in_ref, void **out_ref, const char *context) {
    sqlite3_value *_i0 = reinterpret_cast<sqlite3_value *>(in_ref[0]);
    sqlite3_value *_o0;
    sqlite3_value *_o1;
	_o1 = sqlite3_value_dup(_i0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=sqlite3_value *sqlite3_value_dup(const sqlite3_value*);) */
extern "C" void shim_47(void **in_ref, void **out_ref, const char *context) {
    unprotected_sqlite3_value *_i0 = reinterpret_cast<unprotected_sqlite3_value *>(in_ref[0]);
    unprotected_sqlite3_value *_o0;
    sqlite3_value *_o1;
	_o1 = sqlite3_value_dup(_i0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=void sqlite3_value_free(sqlite3_value*);) */
extern "C" void shim_48(void **in_ref, void **out_ref, const char *context) {
    sqlite3_value *_i0 = reinterpret_cast<sqlite3_value *>(in_ref[0]);
	sqlite3_value_free(_i0);
	
}


/* CPPScope(name=void *sqlite3_value_pointer(sqlite3_value*, const char*);) */
extern "C" void shim_49(void **in_ref, void **out_ref, const char *context) {
    sqlite3_value *_i0 = reinterpret_cast<sqlite3_value *>(in_ref[0]);
    char _a0[64];
    memcpy(&_a0, context + 0, 1 * 64);
    sqlite3_value *_o0;
	_a0[63] = 0;
	sqlite3_value_pointer(_i0, _a0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_value::const void * sqlite3_value_blob(sqlite3_value * None);) */
extern "C" void shim_50(void **in_ref, void **out_ref, const char *context) {
    sqlite3_value *_i0 = reinterpret_cast<sqlite3_value *>(in_ref[0]);
    sqlite3_value *_o0;
	sqlite3_value_blob(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_value::double sqlite3_value_double(sqlite3_value * None);) */
extern "C" void shim_51(void **in_ref, void **out_ref, const char *context) {
    sqlite3_value *_i0 = reinterpret_cast<sqlite3_value *>(in_ref[0]);
    sqlite3_value *_o0;
	sqlite3_value_double(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_value::int sqlite3_value_int(sqlite3_value * None);) */
extern "C" void shim_52(void **in_ref, void **out_ref, const char *context) {
    sqlite3_value *_i0 = reinterpret_cast<sqlite3_value *>(in_ref[0]);
    sqlite3_value *_o0;
	sqlite3_value_int(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_value::sqlite3_int64 sqlite3_value_int64(sqlite3_value * None);) */
extern "C" void shim_53(void **in_ref, void **out_ref, const char *context) {
    sqlite3_value *_i0 = reinterpret_cast<sqlite3_value *>(in_ref[0]);
    sqlite3_value *_o0;
	sqlite3_value_int64(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_value::const unsigned char * sqlite3_value_text(sqlite3_value * None);) */
extern "C" void shim_54(void **in_ref, void **out_ref, const char *context) {
    sqlite3_value *_i0 = reinterpret_cast<sqlite3_value *>(in_ref[0]);
    sqlite3_value *_o0;
	sqlite3_value_text(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_value::const void * sqlite3_value_text16(sqlite3_value * None);) */
extern "C" void shim_55(void **in_ref, void **out_ref, const char *context) {
    sqlite3_value *_i0 = reinterpret_cast<sqlite3_value *>(in_ref[0]);
    sqlite3_value *_o0;
	sqlite3_value_text16(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_value::const void * sqlite3_value_text16le(sqlite3_value * None);) */
extern "C" void shim_56(void **in_ref, void **out_ref, const char *context) {
    sqlite3_value *_i0 = reinterpret_cast<sqlite3_value *>(in_ref[0]);
    sqlite3_value *_o0;
	sqlite3_value_text16le(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_value::const void * sqlite3_value_text16be(sqlite3_value * None);) */
extern "C" void shim_57(void **in_ref, void **out_ref, const char *context) {
    sqlite3_value *_i0 = reinterpret_cast<sqlite3_value *>(in_ref[0]);
    sqlite3_value *_o0;
	sqlite3_value_text16be(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_value::int sqlite3_value_bytes(sqlite3_value * None);) */
extern "C" void shim_58(void **in_ref, void **out_ref, const char *context) {
    sqlite3_value *_i0 = reinterpret_cast<sqlite3_value *>(in_ref[0]);
    sqlite3_value *_o0;
	sqlite3_value_bytes(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_value::int sqlite3_value_bytes16(sqlite3_value * None);) */
extern "C" void shim_59(void **in_ref, void **out_ref, const char *context) {
    sqlite3_value *_i0 = reinterpret_cast<sqlite3_value *>(in_ref[0]);
    sqlite3_value *_o0;
	sqlite3_value_bytes16(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_value::int sqlite3_value_type(sqlite3_value * None);) */
extern "C" void shim_60(void **in_ref, void **out_ref, const char *context) {
    sqlite3_value *_i0 = reinterpret_cast<sqlite3_value *>(in_ref[0]);
    sqlite3_value *_o0;
	sqlite3_value_type(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_value::int sqlite3_value_numeric_type(sqlite3_value * None);) */
extern "C" void shim_61(void **in_ref, void **out_ref, const char *context) {
    sqlite3_value *_i0 = reinterpret_cast<sqlite3_value *>(in_ref[0]);
    sqlite3_value *_o0;
	sqlite3_value_numeric_type(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_value::int sqlite3_value_nochange(sqlite3_value * None);) */
extern "C" void shim_62(void **in_ref, void **out_ref, const char *context) {
    sqlite3_value *_i0 = reinterpret_cast<sqlite3_value *>(in_ref[0]);
    sqlite3_value *_o0;
	sqlite3_value_nochange(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_value::int sqlite3_value_frombind(sqlite3_value * None);) */
extern "C" void shim_63(void **in_ref, void **out_ref, const char *context) {
    sqlite3_value *_i0 = reinterpret_cast<sqlite3_value *>(in_ref[0]);
    sqlite3_value *_o0;
	sqlite3_value_frombind(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=sqlite3_str *sqlite3_str_new(sqlite3*);) */
extern "C" void shim_64(void **in_ref, void **out_ref, const char *context) {
    sqlite3 *_i0 = reinterpret_cast<sqlite3 *>(in_ref[0]);
    sqlite3 *_o0;
    sqlite3_str *_o1;
	_o1 = sqlite3_str_new(_i0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=char *sqlite3_str_finish(sqlite3_str*);) */
extern "C" void shim_65(void **in_ref, void **out_ref, const char *context) {
    sqlite3_str *_i0 = reinterpret_cast<sqlite3_str *>(in_ref[0]);
	char *out = sqlite3_str_finish(_i0);
	sqlite3_free(out);
	
}


/* CPPScope(name=void sqlite3_str_append(sqlite3_str*, const char *zIn, int N);) */
extern "C" void shim_66(void **in_ref, void **out_ref, const char *context) {
    sqlite3_str *_i0 = reinterpret_cast<sqlite3_str *>(in_ref[0]);
    char _a0[256];
    memcpy(&_a0, context + 0, 1 * 256);
    uint32_t _a1;
    memcpy(&_a1, context + 256, sizeof(uint32_t));
    sqlite3_str *_o0;
	_a0[255] = 0;
	int size = strlen(_a0);
	if (size != 0) {
	  int len = _a1 % size;
	  sqlite3_str_append(_i0, _a0, len);
	}
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=void sqlite3_str_appendall(sqlite3_str*, const char *zIn);) */
extern "C" void shim_67(void **in_ref, void **out_ref, const char *context) {
    sqlite3_str *_i0 = reinterpret_cast<sqlite3_str *>(in_ref[0]);
    char _a0[256];
    memcpy(&_a0, context + 0, 1 * 256);
    sqlite3_str *_o0;
	_a0[255] = 0;
	sqlite3_str_appendall(_i0, _a0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_str::void sqlite3_str_reset(sqlite3_str * None);) */
extern "C" void shim_68(void **in_ref, void **out_ref, const char *context) {
    sqlite3_str *_i0 = reinterpret_cast<sqlite3_str *>(in_ref[0]);
    sqlite3_str *_o0;
	sqlite3_str_reset(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_str::void sqlite3_str_appendchar(sqlite3_str * None, int N, char C);) */
extern "C" void shim_69(void **in_ref, void **out_ref, const char *context) {
    sqlite3_str *_i0 = reinterpret_cast<sqlite3_str *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    char _a1;
    memcpy(&_a1, context + 4, sizeof(char));
    sqlite3_str *_o0;
	sqlite3_str_appendchar(_i0, _a0, _a1);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_str::int sqlite3_str_errcode(sqlite3_str * None);) */
extern "C" void shim_70(void **in_ref, void **out_ref, const char *context) {
    sqlite3_str *_i0 = reinterpret_cast<sqlite3_str *>(in_ref[0]);
    sqlite3_str *_o0;
	sqlite3_str_errcode(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_str::int sqlite3_str_length(sqlite3_str * None);) */
extern "C" void shim_71(void **in_ref, void **out_ref, const char *context) {
    sqlite3_str *_i0 = reinterpret_cast<sqlite3_str *>(in_ref[0]);
    sqlite3_str *_o0;
	sqlite3_str_length(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_str::char * sqlite3_str_value(sqlite3_str * None);) */
extern "C" void shim_72(void **in_ref, void **out_ref, const char *context) {
    sqlite3_str *_i0 = reinterpret_cast<sqlite3_str *>(in_ref[0]);
    sqlite3_str *_o0;
	sqlite3_str_value(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=sqlite3_backup *sqlite3_backup_init) */
extern "C" void shim_73(void **in_ref, void **out_ref, const char *context) {
    sqlite3 *_i0 = reinterpret_cast<sqlite3 *>(in_ref[0]);
    sqlite3 *_i1 = reinterpret_cast<sqlite3 *>(in_ref[1]);
    sqlite3 *_o0;
    sqlite3 *_o1;
    sqlite3_backup *_o2;
	_o2 = sqlite3_backup_init(_i0, "main", _i1, "main");
	if (_o2 == 0) {
	  close_all();
	  graphfuzz_bail();
	}
	_o0 = _i0;
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=int sqlite3_backup_finish(sqlite3_backup *p);) */
extern "C" void shim_74(void **in_ref, void **out_ref, const char *context) {
    sqlite3_backup *_i0 = reinterpret_cast<sqlite3_backup *>(in_ref[0]);
	sqlite3_backup_finish(_i0);
	
}


/* CPPScope(name=(auto) sqlite3_backup::int sqlite3_backup_step(sqlite3_backup * p, int nPage);) */
extern "C" void shim_75(void **in_ref, void **out_ref, const char *context) {
    sqlite3_backup *_i0 = reinterpret_cast<sqlite3_backup *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    sqlite3_backup *_o0;
	sqlite3_backup_step(_i0, _a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_backup::int sqlite3_backup_remaining(sqlite3_backup * p);) */
extern "C" void shim_76(void **in_ref, void **out_ref, const char *context) {
    sqlite3_backup *_i0 = reinterpret_cast<sqlite3_backup *>(in_ref[0]);
    sqlite3_backup *_o0;
	sqlite3_backup_remaining(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sqlite3_backup::int sqlite3_backup_pagecount(sqlite3_backup * p);) */
extern "C" void shim_77(void **in_ref, void **out_ref, const char *context) {
    sqlite3_backup *_i0 = reinterpret_cast<sqlite3_backup *>(in_ref[0]);
    sqlite3_backup *_o0;
	sqlite3_backup_pagecount(_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
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

