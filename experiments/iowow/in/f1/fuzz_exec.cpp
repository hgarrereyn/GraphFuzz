#include "db_tracker.h"
#include <iowow/iwkv.h>


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



/* CPPScope(name=open) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    IWKV *_o0;
	_o0 = new_db();
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=close) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    IWKV *_i0 = reinterpret_cast<IWKV *>(in_ref[0]);
	// forget
	
}


/* CPPScope(name=iwkv_db_destroy(IWDB *dbp);) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    IWDB *_i0 = reinterpret_cast<IWDB *>(in_ref[0]);
	// iwkv_db_destroy(_i0);
	
}


/* CPPScope(name=iwkv_new_db) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    IWKV *_i0 = reinterpret_cast<IWKV *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    IWKV *_o0;
    IWDB *_o1;
	_o1 = MAKE(IWDB);
	uint32_t a;
	iwkv_new_db(*_i0, _a0, &a, _o1);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=iwkv_get(IWDB db, const IWKV_val *key, IWKV_val *oval);) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    IWDB *_i0 = reinterpret_cast<IWDB *>(in_ref[0]);
    IWKV_val *_i1 = reinterpret_cast<IWKV_val *>(in_ref[1]);
    IWDB *_o0;
    IWKV_val *_o1;
	IWKV_val oval;
	iwkv_get(*_i0, _i1, &oval);
	_o0 = _i0;
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=iwkv_db_set_meta(IWDB db, void *buf, size_t sz);) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    IWDB *_i0 = reinterpret_cast<IWDB *>(in_ref[0]);
    char _a0[100];
    memcpy(&_a0, context + 0, 1 * 100);
    uint8_t _a1;
    memcpy(&_a1, context + 100, sizeof(uint8_t));
    IWDB *_o0;
	iwkv_db_set_meta(*_i0, &_a0, _a1 % 100);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=iwkv_db_get_meta) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    IWDB *_i0 = reinterpret_cast<IWDB *>(in_ref[0]);
    IWDB *_o0;
	char buffer[100];
	size_t rsz;
	iwkv_db_get_meta(*_i0, &buffer, 100, &rsz);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) IWDB::void iwkv_db_cache_release(IWDB db);) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    IWDB *_i0 = reinterpret_cast<IWDB *>(in_ref[0]);
    IWDB *_o0;
	iwkv_db_cache_release(*_i0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) IWDB::void iwkv_put(IWDB db, IWKV_val * key, IWKV_val * val, uint8_t opflags);) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    IWDB *_i0 = reinterpret_cast<IWDB *>(in_ref[0]);
    IWKV_val *_i1 = reinterpret_cast<IWKV_val *>(in_ref[1]);
    IWKV_val *_i2 = reinterpret_cast<IWKV_val *>(in_ref[2]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    IWDB *_o0;
    IWKV_val *_o1;
    IWKV_val *_o2;
	iwkv_put(*_i0, _i1, _i2, _a0);
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) IWDB::void iwkv_del(IWDB db, const IWKV_val * key, iwkv_opflags opflags);) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    IWDB *_i0 = reinterpret_cast<IWDB *>(in_ref[0]);
    IWKV_val *_i1 = reinterpret_cast<IWKV_val *>(in_ref[1]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    IWDB *_o0;
    IWKV_val *_o1;
	iwkv_del(*_i0, _i1, _a0);
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=create) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    char _a0[100];
    memcpy(&_a0, context + 0, 1 * 100);
    uint8_t _a1;
    memcpy(&_a1, context + 100, sizeof(uint8_t));
    IWKV_val *_o0;
	_o0 = MAKE(IWKV_val);
	_o0->data = (char *)calloc(100,1);
	memcpy(_o0->data, _a0, 100);
	_o0->size = _a1 % 100;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=delete) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    IWKV_val *_i0 = reinterpret_cast<IWKV_val *>(in_ref[0]);
	free(_i0->data);
	free(_i0);
	
}


/* CPPScope(name=create) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    IWDB *_i0 = reinterpret_cast<IWDB *>(in_ref[0]);
    IWKV_val *_i1 = reinterpret_cast<IWKV_val *>(in_ref[1]);
    IWKV_cursor_op _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 6) {
        case 0: _a0 = IWKV_cursor_op::IWKV_CURSOR_BEFORE_FIRST; break;
        case 1: _a0 = IWKV_cursor_op::IWKV_CURSOR_AFTER_LAST; break;
        case 2: _a0 = IWKV_cursor_op::IWKV_CURSOR_NEXT; break;
        case 3: _a0 = IWKV_cursor_op::IWKV_CURSOR_PREV; break;
        case 4: _a0 = IWKV_cursor_op::IWKV_CURSOR_EQ; break;
        case 5: _a0 = IWKV_cursor_op::IWKV_CURSOR_GE; break;
    }
    IWDB *_o0;
    IWKV_val *_o1;
    IWKV_cursor *_o2;
	_o2 = MAKE(IWKV_cursor);
	iwrc rc = iwkv_cursor_open(*_i0, _o2, _a0, _i1);
	if (rc) {
	  graphfuzz_bail();
	}
	_o0 = _i0;
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=close) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    IWKV_cursor *_i0 = reinterpret_cast<IWKV_cursor *>(in_ref[0]);
	iwkv_cursor_close(_i0);
	
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

