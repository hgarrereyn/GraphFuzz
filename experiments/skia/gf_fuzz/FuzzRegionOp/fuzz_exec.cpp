#include "include/core/SkRect.h"
#include "include/core/SkRegion.h"


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



/* CPPScope(name=(auto) SkRegion::SkRegion();) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    SkRegion *_o0;
	_o0 = MAKE(SkRegion);
	SkRegion ref = SkRegion();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkRegion::bool op(const SkIRect & rect, SkRegion::Op op);) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    SkRegion *_i0 = reinterpret_cast<SkRegion *>(in_ref[0]);
    SkIRect *_i1 = reinterpret_cast<SkIRect *>(in_ref[1]);
    SkRegion::Op _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 6) {
        case 0: _a0 = SkRegion::Op::kDifference_Op; break;
        case 1: _a0 = SkRegion::Op::kIntersect_Op; break;
        case 2: _a0 = SkRegion::Op::kUnion_Op; break;
        case 3: _a0 = SkRegion::Op::kXOR_Op; break;
        case 4: _a0 = SkRegion::Op::kReverseDifference_Op; break;
        case 5: _a0 = SkRegion::Op::kReplace_Op; break;
    }
    SkRegion *_o0;
    SkIRect *_o1;
	FUZZ_ENDPOINT(_i0->op(*_i1, _a0);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkRegion::int computeRegionComplexity();) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    SkRegion *_i0 = reinterpret_cast<SkRegion *>(in_ref[0]);
    SkRegion *_o0;
	FUZZ_ENDPOINT(_i0->computeRegionComplexity();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkRegion::~SkRegion();) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    SkRegion *_i0 = reinterpret_cast<SkRegion *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) SkIRect::void sort();) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    SkIRect *_i0 = reinterpret_cast<SkIRect *>(in_ref[0]);
    SkIRect *_o0;
	FUZZ_ENDPOINT(_i0->sort();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
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
    SkIRect *_o0;
	_o0 = MAKE(SkIRect);
	SkIRect ref = SkIRect::MakeLTRB(_a0, _a1, _a2, _a3);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkIRect::~SkIRect();) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    SkIRect *_i0 = reinterpret_cast<SkIRect *>(in_ref[0]);
	free(_i0);
	
	                
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

