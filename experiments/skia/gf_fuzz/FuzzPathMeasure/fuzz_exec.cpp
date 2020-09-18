#include "include/core/SkPath.h"
#include "include/core/SkPathMeasure.h"
#include "include/core/SkPoint.h"
#include "include/core/SkRect.h"


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



/* CPPScope(name=(auto) SkPath::SkPath();) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    SkPath *_o0;
	_o0 = MAKE(SkPath);
	SkPath ref = SkPath();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void moveTo(SkScalar None, SkScalar None);) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkPath *_o0;
	FUZZ_ENDPOINT(_i0->moveTo(_a0, _a1);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void lineTo(SkScalar None, SkScalar None);) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkPath *_o0;
	FUZZ_ENDPOINT(_i0->lineTo(_a0, _a1);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void quadTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    SkPath *_o0;
	FUZZ_ENDPOINT(_i0->quadTo(_a0, _a1, _a2, _a3);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void conicTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    float _a4;
    memcpy(&_a4, context + 16, sizeof(float));
    SkPath *_o0;
	FUZZ_ENDPOINT(_i0->conicTo(_a0, _a1, _a2, _a3, _a4);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void cubicTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    float _a4;
    memcpy(&_a4, context + 16, sizeof(float));
    float _a5;
    memcpy(&_a5, context + 20, sizeof(float));
    SkPath *_o0;
	FUZZ_ENDPOINT(_i0->cubicTo(_a0, _a1, _a2, _a3, _a4, _a5);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void close();) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkPath *_o0;
	FUZZ_ENDPOINT(_i0->close();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::SkRect getBounds();) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkPath *_o0;
    SkRect *_o1;
	_o1 = MAKE(SkRect);
	*_o1 = _i0->getBounds();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPath::~SkPath();) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) SkPathMeasure::SkPathMeasure(const SkPath & path, bool forceClosed, SkScalar resScale);) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    float _a1;
    memcpy(&_a1, context + 1, sizeof(float));
    SkPathMeasure *_o0;
    SkPath *_o1;
	_o0 = new SkPathMeasure(*_i0, _a0, _a1);
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPathMeasure::bool getPosTan(SkScalar distance, SkPoint * position, SkVector * tangent);) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    SkPathMeasure *_i0 = reinterpret_cast<SkPathMeasure *>(in_ref[0]);
    SkPoint *_i1 = reinterpret_cast<SkPoint *>(in_ref[1]);
    SkPoint *_i2 = reinterpret_cast<SkPoint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    SkPathMeasure *_o0;
    SkPoint *_o1;
    SkPoint *_o2;
	FUZZ_ENDPOINT(_i0->getPosTan(_a0, _i1, _i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkPathMeasure::bool getSegment(SkScalar startD, SkScalar stopD, SkPath * dst, bool startWithMoveTo);) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    SkPathMeasure *_i0 = reinterpret_cast<SkPathMeasure *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    SkPathMeasure *_o0;
    SkPath *_o1;
	FUZZ_ENDPOINT(_i0->getSegment(_a0, _a1, _i1, _a2);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPathMeasure::bool nextContour();) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    SkPathMeasure *_i0 = reinterpret_cast<SkPathMeasure *>(in_ref[0]);
    SkPathMeasure *_o0;
	FUZZ_ENDPOINT(_i0->nextContour();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPathMeasure::~SkPathMeasure();) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    SkPathMeasure *_i0 = reinterpret_cast<SkPathMeasure *>(in_ref[0]);
	delete _i0;
	
	                
}


/* CPPScope(name=(auto) SkRect::SkRect MakeXYWH(SkScalar x, SkScalar y, SkScalar w, SkScalar h);) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    SkRect *_o0;
	_o0 = MAKE(SkRect);
	SkRect ref = SkRect::MakeXYWH(_a0, _a1, _a2, _a3);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkRect::~SkRect();) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    SkRect *_i0 = reinterpret_cast<SkRect *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) SkPoint::SkPoint Make(SkScalar x, SkScalar y);) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkPoint *_o0;
	_o0 = MAKE(SkPoint);
	SkPoint ref = SkPoint::Make(_a0, _a1);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPoint::~SkPoint();) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    SkPoint *_i0 = reinterpret_cast<SkPoint *>(in_ref[0]);
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
};

