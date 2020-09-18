#include "poly_util.h"


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

#ifdef FUZZ_DRY
#define FUZZ_ENDPOINT(T) 0;
#else
#define FUZZ_ENDPOINT(T) T
#endif



/* CPPScope(name=PolyTester(int _count, SkScalar coords[1024], uint16_t _indexMap[512])) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    float _a1[1024];
    memcpy(&_a1, context + 4, 4 * 1024);
    uint16_t _a2[512];
    memcpy(&_a2, context + 4100, 2 * 512);
    PolyTester *_o0;
	_o0 = new PolyTester(_a0, _a1, _a2);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) PolyTester::void test_SkGetPolygonWinding();) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    PolyTester *_i0 = reinterpret_cast<PolyTester *>(in_ref[0]);
    PolyTester *_o0;
	FUZZ_ENDPOINT(_i0->test_SkGetPolygonWinding();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) PolyTester::void test_SkIsConvexPolygon();) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    PolyTester *_i0 = reinterpret_cast<PolyTester *>(in_ref[0]);
    PolyTester *_o0;
	FUZZ_ENDPOINT(_i0->test_SkIsConvexPolygon();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) PolyTester::void test_SkIsSimplePolygon();) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    PolyTester *_i0 = reinterpret_cast<PolyTester *>(in_ref[0]);
    PolyTester *_o0;
	FUZZ_ENDPOINT(_i0->test_SkIsSimplePolygon();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) PolyTester::void test_SkInsetConvexPolygon(SkScalar inset);) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    PolyTester *_i0 = reinterpret_cast<PolyTester *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    PolyTester *_o0;
	FUZZ_ENDPOINT(_i0->test_SkInsetConvexPolygon(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) PolyTester::void test_SkOffsetSimplePolygon(SkScalar offset);) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    PolyTester *_i0 = reinterpret_cast<PolyTester *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    PolyTester *_o0;
	FUZZ_ENDPOINT(_i0->test_SkOffsetSimplePolygon(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) PolyTester::void test_SkTriangulateSimplePolygon();) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    PolyTester *_i0 = reinterpret_cast<PolyTester *>(in_ref[0]);
    PolyTester *_o0;
	FUZZ_ENDPOINT(_i0->test_SkTriangulateSimplePolygon();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) PolyTester::~PolyTester();) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    PolyTester *_i0 = reinterpret_cast<PolyTester *>(in_ref[0]);
	delete _i0;
	
	                
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

