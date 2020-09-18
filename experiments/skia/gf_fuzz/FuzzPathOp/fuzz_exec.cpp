#include "include/core/SkPath.h"
#include "include/core/SkPathTypes.h"
#include "include/core/SkRect.h"
#include "include/pathops/SkPathOps.h"


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


/* CPPScope(name=(auto) SkPath::void setFillType(SkPathFillType None);) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkPathFillType _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 4) {
        case 0: _a0 = SkPathFillType::kWinding; break;
        case 1: _a0 = SkPathFillType::kEvenOdd; break;
        case 2: _a0 = SkPathFillType::kInverseWinding; break;
        case 3: _a0 = SkPathFillType::kInverseEvenOdd; break;
    }
    SkPath *_o0;
	FUZZ_ENDPOINT(_i0->setFillType(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::~SkPath();) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) SkOpBuilder::SkOpBuilder();) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    SkOpBuilder *_o0;
	_o0 = MAKE(SkOpBuilder);
	SkOpBuilder ref = SkOpBuilder();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkOpBuilder::void add(const SkPath & path, SkPathOp op);) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    SkOpBuilder *_i0 = reinterpret_cast<SkOpBuilder *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    SkPathOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = SkPathOp::kDifference_SkPathOp; break;
        case 1: _a0 = SkPathOp::kIntersect_SkPathOp; break;
        case 2: _a0 = SkPathOp::kUnion_SkPathOp; break;
        case 3: _a0 = SkPathOp::kXOR_SkPathOp; break;
        case 4: _a0 = SkPathOp::kReverseDifference_SkPathOp; break;
    }
    SkOpBuilder *_o0;
    SkPath *_o1;
	FUZZ_ENDPOINT(_i0->add(*_i1, _a0);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkOpBuilder::bool resolve(SkPath * result);) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    SkOpBuilder *_i0 = reinterpret_cast<SkOpBuilder *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    SkOpBuilder *_o0;
    SkPath *_o1;
	FUZZ_ENDPOINT(_i0->resolve(_i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkOpBuilder::bool Simplify(const SkPath & path, SkPath * result);) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    SkPath *_o0;
    SkPath *_o1;
	FUZZ_ENDPOINT(Simplify(*_i0, _i1);)
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkOpBuilder::bool Op(const SkPath & one, const SkPath & two, SkPathOp op, SkPath * result);) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    SkPath *_i2 = reinterpret_cast<SkPath *>(in_ref[2]);
    SkPathOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = SkPathOp::kDifference_SkPathOp; break;
        case 1: _a0 = SkPathOp::kIntersect_SkPathOp; break;
        case 2: _a0 = SkPathOp::kUnion_SkPathOp; break;
        case 3: _a0 = SkPathOp::kXOR_SkPathOp; break;
        case 4: _a0 = SkPathOp::kReverseDifference_SkPathOp; break;
    }
    SkPath *_o0;
    SkPath *_o1;
    SkPath *_o2;
	FUZZ_ENDPOINT(Op(*_i0, *_i1, _a0, _i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkOpBuilder::bool AsWinding(const SkPath & path, SkPath * result);) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    SkPath *_o0;
    SkPath *_o1;
	FUZZ_ENDPOINT(AsWinding(*_i0, _i1);)
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkOpBuilder::bool TightBounds(const SkPath & path, SkRect * result);) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPath *_o0;
    SkRect *_o1;
	FUZZ_ENDPOINT(TightBounds(*_i0, _i1);)
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkOpBuilder::~SkOpBuilder();) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    SkOpBuilder *_i0 = reinterpret_cast<SkOpBuilder *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) SkRect::SkRect MakeXYWH(SkScalar x, SkScalar y, SkScalar w, SkScalar h);) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    SkRect *_i0 = reinterpret_cast<SkRect *>(in_ref[0]);
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
    &shim_18,
    &shim_19,
};

