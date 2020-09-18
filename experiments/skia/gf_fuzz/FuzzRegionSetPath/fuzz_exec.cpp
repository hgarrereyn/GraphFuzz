#include "SkMatrix.h"
#include "SkPath.h"
#include "SkPathTypes.h"
#include "SkRRect.h"
#include "include/core/SkPath.h"
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



/* CPPScope(name=(auto) SkRect::SkRect MakeXYWH(SkScalar x, SkScalar y, SkScalar w, SkScalar h);) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    SkRect *_i0 = reinterpret_cast<SkRect *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=make) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    SkRect *_i0 = reinterpret_cast<SkRect *>(in_ref[0]);
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
    float _a6;
    memcpy(&_a6, context + 24, sizeof(float));
    float _a7;
    memcpy(&_a7, context + 28, sizeof(float));
    SkRRect *_o0;
    SkRect *_o1;
	_o0 = MAKE(SkRRect);
	*_o0 = SkRRect();
	SkVector radii[4] = {
	  SkPoint::Make(_a0,_a1),
	  SkPoint::Make(_a2,_a3),
	  SkPoint::Make(_a4,_a5),
	  SkPoint::Make(_a6,_a7)
	};
	_o0->setRectRadii(*_i0, radii);
	_o1 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkRRect::~SkRRect();) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    SkRRect *_i0 = reinterpret_cast<SkRRect *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=void setAffine(SkScalar[6])) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    SkMatrix *_i0 = reinterpret_cast<SkMatrix *>(in_ref[0]);
    float _a0[6];
    memcpy(&_a0, context + 0, 4 * 6);
    SkMatrix *_o0;
	_i0->setAffine(_a0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=void set9(SkScalar[9])) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    SkMatrix *_i0 = reinterpret_cast<SkMatrix *>(in_ref[0]);
    float _a0[9];
    memcpy(&_a0, context + 0, 4 * 9);
    SkMatrix *_o0;
	_i0->set9(_a0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkMatrix::void postTranslate(SkScalar None, SkScalar None);) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    SkMatrix *_i0 = reinterpret_cast<SkMatrix *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkMatrix *_o0;
	FUZZ_ENDPOINT(_i0->postTranslate(_a0, _a1);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkMatrix::SkMatrix I();) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    SkMatrix *_o0;
	_o0 = MAKE(SkMatrix);
	SkMatrix ref = SkMatrix::I();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkMatrix::SkMatrix Translate(SkScalar None, SkScalar None);) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkMatrix *_o0;
	_o0 = MAKE(SkMatrix);
	SkMatrix ref = SkMatrix::Translate(_a0, _a1);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkMatrix::SkMatrix Scale(SkScalar None, SkScalar None);) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkMatrix *_o0;
	_o0 = MAKE(SkMatrix);
	SkMatrix ref = SkMatrix::Scale(_a0, _a1);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkMatrix::~SkMatrix();) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    SkMatrix *_i0 = reinterpret_cast<SkMatrix *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=add_self_path_matrix) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkMatrix *_i1 = reinterpret_cast<SkMatrix *>(in_ref[1]);
    SkPath::AddPathMode _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkPath::AddPathMode::kAppend_AddPathMode; break;
        case 1: _a0 = SkPath::AddPathMode::kExtend_AddPathMode; break;
    }
    SkPath *_o0;
    SkMatrix *_o1;
	_i0->addPath(*_i0, *_i1, _a0);
	_o0 = _i0;
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=add_self_path) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkPath *_o0;
	_i0->addPath(*_i0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=add_self_path_reverse) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkPath *_o0;
	_i0->reverseAddPath(*_i0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=offset_self) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkPath *_o0;
	_i0->offset(_a0, _a1, _i0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=transform_self) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkMatrix *_i1 = reinterpret_cast<SkMatrix *>(in_ref[1]);
    SkPath *_o0;
    SkMatrix *_o1;
	_i0->transform(*_i1, _i0);
	_o0 = _i0;
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPath::SkPath();) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    SkPath *_o0;
	_o0 = MAKE(SkPath);
	SkPath ref = SkPath();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void moveTo(SkScalar None, SkScalar None);) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkPath::void rMoveTo(SkScalar None, SkScalar None);) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkPath *_o0;
	FUZZ_ENDPOINT(_i0->rMoveTo(_a0, _a1);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void lineTo(SkScalar None, SkScalar None);) */
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkPath::void rLineTo(SkScalar None, SkScalar None);) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkPath *_o0;
	FUZZ_ENDPOINT(_i0->rLineTo(_a0, _a1);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void quadTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkPath::void rQuadTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_22(void **in_ref, void **out_ref, const char *context) {
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
	FUZZ_ENDPOINT(_i0->rQuadTo(_a0, _a1, _a2, _a3);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void conicTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_23(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkPath::void rConicTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_24(void **in_ref, void **out_ref, const char *context) {
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
	FUZZ_ENDPOINT(_i0->rConicTo(_a0, _a1, _a2, _a3, _a4);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void cubicTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_25(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkPath::void rCubicTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_26(void **in_ref, void **out_ref, const char *context) {
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
	FUZZ_ENDPOINT(_i0->rCubicTo(_a0, _a1, _a2, _a3, _a4, _a5);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void arcTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_27(void **in_ref, void **out_ref, const char *context) {
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
	FUZZ_ENDPOINT(_i0->arcTo(_a0, _a1, _a2, _a3, _a4);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void arcTo(SkRect None, SkScalar None, SkScalar None, bool None);) */
extern "C" void shim_28(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    SkPath *_o0;
    SkRect *_o1;
	FUZZ_ENDPOINT(_i0->arcTo(*_i1, _a0, _a1, _a2);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPath::void close();) */
extern "C" void shim_29(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkPath *_o0;
	FUZZ_ENDPOINT(_i0->close();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void addRect(SkRect None, SkPathDirection None);) */
extern "C" void shim_30(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPathDirection _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkPathDirection::kCW; break;
        case 1: _a0 = SkPathDirection::kCCW; break;
    }
    SkPath *_o0;
    SkRect *_o1;
	FUZZ_ENDPOINT(_i0->addRect(*_i1, _a0);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPath::void addRect(SkRect None, SkPathDirection None, unsigned int None);) */
extern "C" void shim_31(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPathDirection _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkPathDirection::kCW; break;
        case 1: _a0 = SkPathDirection::kCCW; break;
    }
    int _a1;
    memcpy(&_a1, context + 1, sizeof(int));
    SkPath *_o0;
    SkRect *_o1;
	FUZZ_ENDPOINT(_i0->addRect(*_i1, _a0, _a1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPath::void addOval(SkRect None, SkPathDirection None);) */
extern "C" void shim_32(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPathDirection _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkPathDirection::kCW; break;
        case 1: _a0 = SkPathDirection::kCCW; break;
    }
    SkPath *_o0;
    SkRect *_o1;
	FUZZ_ENDPOINT(_i0->addOval(*_i1, _a0);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPath::void addOval(SkRect None, SkPathDirection None, unsigned int None);) */
extern "C" void shim_33(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPathDirection _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkPathDirection::kCW; break;
        case 1: _a0 = SkPathDirection::kCCW; break;
    }
    int _a1;
    memcpy(&_a1, context + 1, sizeof(int));
    SkPath *_o0;
    SkRect *_o1;
	FUZZ_ENDPOINT(_i0->addOval(*_i1, _a0, _a1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPath::void addCircle(SkScalar None, SkScalar None, SkScalar None, SkPathDirection None);) */
extern "C" void shim_34(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    SkPathDirection _a3;
    switch (*(reinterpret_cast<const unsigned char *>(context + 12)) % 2) {
        case 0: _a3 = SkPathDirection::kCW; break;
        case 1: _a3 = SkPathDirection::kCCW; break;
    }
    SkPath *_o0;
	FUZZ_ENDPOINT(_i0->addCircle(_a0, _a1, _a2, _a3);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void addArc(SkRect None, SkScalar None, SkScalar None);) */
extern "C" void shim_35(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkPath *_o0;
    SkRect *_o1;
	FUZZ_ENDPOINT(_i0->addArc(*_i1, _a0, _a1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPath::void addRoundRect(SkRect None, SkScalar None, SkScalar None, SkPathDirection None);) */
extern "C" void shim_36(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkPathDirection _a2;
    switch (*(reinterpret_cast<const unsigned char *>(context + 8)) % 2) {
        case 0: _a2 = SkPathDirection::kCW; break;
        case 1: _a2 = SkPathDirection::kCCW; break;
    }
    SkPath *_o0;
    SkRect *_o1;
	FUZZ_ENDPOINT(_i0->addRoundRect(*_i1, _a0, _a1, _a2);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPath::void addRRect(SkRRect None, SkPathDirection None);) */
extern "C" void shim_37(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkRRect *_i1 = reinterpret_cast<SkRRect *>(in_ref[1]);
    SkPathDirection _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkPathDirection::kCW; break;
        case 1: _a0 = SkPathDirection::kCCW; break;
    }
    SkPath *_o0;
    SkRRect *_o1;
	FUZZ_ENDPOINT(_i0->addRRect(*_i1, _a0);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPath::void addRRect(SkRRect None, SkPathDirection None, unsigned int None);) */
extern "C" void shim_38(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkRRect *_i1 = reinterpret_cast<SkRRect *>(in_ref[1]);
    SkPathDirection _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkPathDirection::kCW; break;
        case 1: _a0 = SkPathDirection::kCCW; break;
    }
    int _a1;
    memcpy(&_a1, context + 1, sizeof(int));
    SkPath *_o0;
    SkRRect *_o1;
	FUZZ_ENDPOINT(_i0->addRRect(*_i1, _a0, _a1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPath::void addPath(SkPath None, SkMatrix None, SkPath::AddPathMode None);) */
extern "C" void shim_39(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    SkMatrix *_i2 = reinterpret_cast<SkMatrix *>(in_ref[2]);
    SkPath::AddPathMode _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkPath::AddPathMode::kAppend_AddPathMode; break;
        case 1: _a0 = SkPath::AddPathMode::kExtend_AddPathMode; break;
    }
    SkPath *_o0;
    SkPath *_o1;
    SkMatrix *_o2;
	FUZZ_ENDPOINT(_i0->addPath(*_i1, *_i2, _a0);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkPath::void reverseAddPath(SkPath None);) */
extern "C" void shim_40(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    SkPath *_o0;
    SkPath *_o1;
	FUZZ_ENDPOINT(_i0->reverseAddPath(*_i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPath::void offset(SkScalar None, SkScalar None, SkPath * None);) */
extern "C" void shim_41(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkPath *_o0;
    SkPath *_o1;
	FUZZ_ENDPOINT(_i0->offset(_a0, _a1, _i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPath::void transform(SkMatrix None, SkPath * None);) */
extern "C" void shim_42(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkMatrix *_i1 = reinterpret_cast<SkMatrix *>(in_ref[1]);
    SkPath *_i2 = reinterpret_cast<SkPath *>(in_ref[2]);
    SkPath *_o0;
    SkMatrix *_o1;
    SkPath *_o2;
	FUZZ_ENDPOINT(_i0->transform(*_i1, _i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkPath::void setLastPt(SkScalar None, SkScalar None);) */
extern "C" void shim_43(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkPath *_o0;
	FUZZ_ENDPOINT(_i0->setLastPt(_a0, _a1);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::~SkPath();) */
extern "C" void shim_44(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) SkRegion::SkRegion();) */
extern "C" void shim_45(void **in_ref, void **out_ref, const char *context) {
    SkRegion *_o0;
	_o0 = MAKE(SkRegion);
	SkRegion ref = SkRegion();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkRegion::bool op(const SkIRect & rect, SkRegion::Op op);) */
extern "C" void shim_46(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_47(void **in_ref, void **out_ref, const char *context) {
    SkRegion *_i0 = reinterpret_cast<SkRegion *>(in_ref[0]);
    SkRegion *_o0;
	FUZZ_ENDPOINT(_i0->computeRegionComplexity();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkRegion::bool setPath(const SkPath & path, const SkRegion & clip);) */
extern "C" void shim_48(void **in_ref, void **out_ref, const char *context) {
    SkRegion *_i0 = reinterpret_cast<SkRegion *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    SkRegion *_i2 = reinterpret_cast<SkRegion *>(in_ref[2]);
    SkRegion *_o0;
    SkPath *_o1;
    SkRegion *_o2;
	FUZZ_ENDPOINT(_i0->setPath(*_i1, *_i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkRegion::bool isComplex();) */
extern "C" void shim_49(void **in_ref, void **out_ref, const char *context) {
    SkRegion *_i0 = reinterpret_cast<SkRegion *>(in_ref[0]);
    SkRegion *_o0;
	FUZZ_ENDPOINT(_i0->isComplex();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkRegion::bool contains(int32_t x, int32_t y);) */
extern "C" void shim_50(void **in_ref, void **out_ref, const char *context) {
    SkRegion *_i0 = reinterpret_cast<SkRegion *>(in_ref[0]);
    int32_t _a0;
    memcpy(&_a0, context + 0, sizeof(int32_t));
    int32_t _a1;
    memcpy(&_a1, context + 4, sizeof(int32_t));
    SkRegion *_o0;
	FUZZ_ENDPOINT(_i0->contains(_a0, _a1);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkRegion::~SkRegion();) */
extern "C" void shim_51(void **in_ref, void **out_ref, const char *context) {
    SkRegion *_i0 = reinterpret_cast<SkRegion *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) SkIRect::SkIRect MakeLTRB(int32_t l, int32_t t, int32_t r, int32_t b);) */
extern "C" void shim_52(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_53(void **in_ref, void **out_ref, const char *context) {
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
};

