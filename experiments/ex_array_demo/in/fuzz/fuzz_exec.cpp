#include "lib.h"


#include <string.h>
#include <stdlib.h>
#include <cstdint>

extern "C" int graphfuzz_try();

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) {

}

extern "C" void __attribute__((visibility ("default"))) shim_init() {

}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {

}


#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))

struct GFUZZ_BUNDLE {
public:
    void *active;
    void *inactive;
    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}
};

#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)



/* CPPScope(name=fuzz1) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    Test *_i0 = reinterpret_cast<Test *>(in_ref[0]);
    int _a0[4];
    memcpy(&_a0, context + 0, 4 * 4);
    Test *_o0;
	_i0->fuzz1(_a0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=fuzz2) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    Test *_i0 = reinterpret_cast<Test *>(in_ref[0]);
    int _a0[32];
    memcpy(&_a0, context + 0, 4 * 32);
    float _a1[8];
    memcpy(&_a1, context + 128, 4 * 8);
    Test *_o0;
	_i0->fuzz2(_a0, _a1);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Test::Test();) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    Test *_o0;
	_o0 = MAKE(Test);
	Test ref = Test();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Test::~Test();) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    Test *_i0 = reinterpret_cast<Test *>(in_ref[0]);
	free(_i0);
	
	                
}


void __attribute__((visibility ("default"))) (*FUZZER_SHIMS[])(void **, void **, const char *) = {
    &shim_0,
    &shim_1,
    &shim_2,
    &shim_3,
};

