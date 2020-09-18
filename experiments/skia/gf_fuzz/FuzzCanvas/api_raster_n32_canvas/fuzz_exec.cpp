#include "Sk1DPathEffect.h"
#include "Sk2DPathEffect.h"
#include "SkBlendMode.h"
#include "SkBlurTypes.h"
#include "SkCanvas.h"
#include "SkClipOp.h"
#include "SkColor.h"
#include "SkColorFilter.h"
#include "SkColorMatrixFilter.h"
#include "SkCornerPathEffect.h"
#include "SkDashPathEffect.h"
#include "SkDiscretePathEffect.h"
#include "SkFilterQuality.h"
#include "SkFont.h"
#include "SkFontMgr.h"
#include "SkFontTypes.h"
#include "SkGradientShader.h"
#include "SkHighContrastFilter.h"
#include "SkImage.h"
#include "SkImageFilter.h"
#include "SkImageFilters.h"
#include "SkLumaColorFilter.h"
#include "SkMaskFilter.h"
#include "SkMatrix.h"
#include "SkPaint.h"
#include "SkPath.h"
#include "SkPathEffect.h"
#include "SkPathTypes.h"
#include "SkPerlinNoiseShader.h"
#include "SkPicture.h"
#include "SkPictureRecorder.h"
#include "SkPoint.h"
#include "SkPoint3.h"
#include "SkRRect.h"
#include "SkRect.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkSize.h"
#include "SkSurface.h"
#include "SkTableColorFilter.h"
#include "SkTextBlob.h"
#include "SkTileMode.h"
#include "SkTypeface.h"
#include "SkVertices.h"
#include "fuzz_util.h"
#include "private/SkTemplates.h"


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



/* CPPScope(name=api_null_canvas) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_o0;
	sk_sp<SkSurface> *parent = MAKE(sk_sp<SkSurface>);
	*parent = SkSurface::MakeRasterN32Premul(128,160);
	SkCanvas *canvas = parent->get()->getCanvas();
	_o0 = BUNDLE(canvas, parent);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=delete) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
	delete _i0;
	
}


/* CPPScope(name=(auto) SkPoint::SkPoint Make(SkScalar x, SkScalar y);) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    SkPoint *_i0 = reinterpret_cast<SkPoint *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) SkIRect::SkIRect MakeXYWH(int32_t x, int32_t y, int32_t w, int32_t h);) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
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
	SkIRect ref = SkIRect::MakeXYWH(_a0, _a1, _a2, _a3);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkIRect::~SkIRect();) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    SkIRect *_i0 = reinterpret_cast<SkIRect *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) SkISize::SkISize Make(int32_t w, int32_t h);) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    int32_t _a0;
    memcpy(&_a0, context + 0, sizeof(int32_t));
    int32_t _a1;
    memcpy(&_a1, context + 4, sizeof(int32_t));
    SkISize *_o0;
	_o0 = MAKE(SkISize);
	SkISize ref = SkISize::Make(_a0, _a1);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkISize::~SkISize();) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    SkISize *_i0 = reinterpret_cast<SkISize *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=make) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    SkRRect *_i0 = reinterpret_cast<SkRRect *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) SkRegion::SkRegion();) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    SkRegion *_o0;
	_o0 = MAKE(SkRegion);
	SkRegion ref = SkRegion();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkRegion::void op(SkIRect None, SkRegion::Op None);) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    SkRegion *_i0 = reinterpret_cast<SkRegion *>(in_ref[0]);
    SkIRect *_i1 = reinterpret_cast<SkIRect *>(in_ref[1]);
    SkRegion::Op _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 7) {
        case 0: _a0 = SkRegion::Op::kDifference_Op; break;
        case 1: _a0 = SkRegion::Op::kIntersect_Op; break;
        case 2: _a0 = SkRegion::Op::kUnion_Op; break;
        case 3: _a0 = SkRegion::Op::kXOR_Op; break;
        case 4: _a0 = SkRegion::Op::kReverseDifference_Op; break;
        case 5: _a0 = SkRegion::Op::kReplace_Op; break;
        case 6: _a0 = SkRegion::Op::kLastOp; break;
    }
    SkRegion *_o0;
    SkIRect *_o1;
	FUZZ_ENDPOINT(_i0->op(*_i1, _a0);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkRegion::~SkRegion();) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    SkRegion *_i0 = reinterpret_cast<SkRegion *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=void setAffine(SkScalar[6])) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    SkMatrix *_i0 = reinterpret_cast<SkMatrix *>(in_ref[0]);
    float _a0[6];
    memcpy(&_a0, context + 0, 4 * 6);
    SkMatrix *_o0;
	_i0->setAffine(_a0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=void set9(SkScalar[9])) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    SkMatrix *_i0 = reinterpret_cast<SkMatrix *>(in_ref[0]);
    float _a0[9];
    memcpy(&_a0, context + 0, 4 * 9);
    SkMatrix *_o0;
	_i0->set9(_a0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkMatrix::void postTranslate(SkScalar None, SkScalar None);) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    SkMatrix *_o0;
	_o0 = MAKE(SkMatrix);
	SkMatrix ref = SkMatrix::I();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkMatrix::SkMatrix Translate(SkScalar None, SkScalar None);) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    SkMatrix *_i0 = reinterpret_cast<SkMatrix *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=add_self_path_matrix) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkPath *_o0;
	_i0->addPath(*_i0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=add_self_path_reverse) */
extern "C" void shim_22(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkPath *_o0;
	_i0->reverseAddPath(*_i0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=offset_self) */
extern "C" void shim_23(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_24(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_25(void **in_ref, void **out_ref, const char *context) {
    SkPath *_o0;
	_o0 = MAKE(SkPath);
	SkPath ref = SkPath();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void moveTo(SkScalar None, SkScalar None);) */
extern "C" void shim_26(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_27(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_28(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_29(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_30(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_31(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_32(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_33(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_34(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_35(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_36(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_37(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_38(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkPath *_o0;
	FUZZ_ENDPOINT(_i0->close();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void addRect(SkRect None, SkPathDirection None);) */
extern "C" void shim_39(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_40(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_41(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_42(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_43(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_44(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_45(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_46(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_47(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_48(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_49(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_50(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_51(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_52(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_53(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=make_fuzz_image) */
extern "C" void shim_54(void **in_ref, void **out_ref, const char *context) {
    uint16_t _a0[2];
    memcpy(&_a0, context + 0, 2 * 2);
    uint32_t _a1[64];
    memcpy(&_a1, context + 4, 4 * 64);
    uint32_t _a2[64];
    memcpy(&_a2, context + 260, 4 * 64);
    sk_sp<SkImage> *_o0;
	_o0 = MAKE(sk_sp<SkImage>);
	unsigned int w = _a0[0];
	unsigned int h = _a0[1];
	SkAutoTMalloc<SkPMColor> data(w * h);
	SkPixmap pixmap(SkImageInfo::MakeN32Premul(w, h), data.get(), w * sizeof(SkPMColor));
	int n = w * h;
	if (n > 0) {
	  for (int i = 0; i < 64; ++i) {
	    data[_a1[i] % n] = SkPreMultiplyColor(_a2[i]);
	  }
	}
	(void)data.release();
	*_o0 = SkImage::MakeFromRaster(pixmap, [](const void* p, void*) { sk_free((void*)p); }, nullptr);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sk_sp<SkImage>::~sk_sp<SkImage>();) */
extern "C" void shim_55(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImage> *_i0 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=nullptr) */
extern "C" void shim_56(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkColorFilter> *_o0;
	_o0 = MAKE(sk_sp<SkColorFilter>);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=sk_sp<SkColorFilter> makeComposed) */
extern "C" void shim_57(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkColorFilter> *_i0 = reinterpret_cast<sk_sp<SkColorFilter> *>(in_ref[0]);
    sk_sp<SkColorFilter> *_i1 = reinterpret_cast<sk_sp<SkColorFilter> *>(in_ref[1]);
    sk_sp<SkColorFilter> *_o0;
    sk_sp<SkColorFilter> *_o1;
    sk_sp<SkColorFilter> *_o2;
	_o2 = MAKE(sk_sp<SkColorFilter>);
	if (*_i0 != nullptr) *_o2 = (*_i0)->makeComposed(*_i1);
	_o0 = _i0;
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=SkColorFilters::Matrix) */
extern "C" void shim_58(void **in_ref, void **out_ref, const char *context) {
    float _a0[20];
    memcpy(&_a0, context + 0, 4 * 20);
    sk_sp<SkColorFilter> *_o0;
	_o0 = MAKE(sk_sp<SkColorFilter>);
	*_o0 = SkColorFilters::Matrix(_a0);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=SkHighContrastFilter::Make) */
extern "C" void shim_59(void **in_ref, void **out_ref, const char *context) {
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    SkHighContrastConfig::InvertStyle _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 1)) % 3) {
        case 0: _a1 = SkHighContrastConfig::InvertStyle::kNoInvert; break;
        case 1: _a1 = SkHighContrastConfig::InvertStyle::kInvertBrightness; break;
        case 2: _a1 = SkHighContrastConfig::InvertStyle::kInvertLightness; break;
    }
    float _a2;
    memcpy(&_a2, context + 2, sizeof(float));
    sk_sp<SkColorFilter> *_o0;
	_o0 = MAKE(sk_sp<SkColorFilter>);
	*_o0 = SkHighContrastFilter::Make(SkHighContrastConfig(_a0, _a1, _a2));
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=sk_sp<SkColorFilter> SkTableColorFilter::Make) */
extern "C" void shim_60(void **in_ref, void **out_ref, const char *context) {
    uint8_t _a0[256];
    memcpy(&_a0, context + 0, 1 * 256);
    sk_sp<SkColorFilter> *_o0;
	_o0 = MAKE(sk_sp<SkColorFilter>);
	*_o0 = SkTableColorFilter::Make(_a0);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=sk_sp<SkColorFilter> SkTableColorFilter::MakeARGB) */
extern "C" void shim_61(void **in_ref, void **out_ref, const char *context) {
    uint8_t _a0[256];
    memcpy(&_a0, context + 0, 1 * 256);
    uint8_t _a1[256];
    memcpy(&_a1, context + 256, 1 * 256);
    uint8_t _a2[256];
    memcpy(&_a2, context + 512, 1 * 256);
    uint8_t _a3[256];
    memcpy(&_a3, context + 768, 1 * 256);
    sk_sp<SkColorFilter> *_o0;
	_o0 = MAKE(sk_sp<SkColorFilter>);
	*_o0 = SkTableColorFilter::MakeARGB(_a0, _a1, _a2, _a3);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sk_sp<SkColorFilter>::sk_sp<SkColorFilter> SkColorFilters::Blend(SkColor None, SkBlendMode None);) */
extern "C" void shim_62(void **in_ref, void **out_ref, const char *context) {
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    SkBlendMode _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 4)) % 32) {
        case 0: _a1 = SkBlendMode::kClear; break;
        case 1: _a1 = SkBlendMode::kSrc; break;
        case 2: _a1 = SkBlendMode::kDst; break;
        case 3: _a1 = SkBlendMode::kSrcOver; break;
        case 4: _a1 = SkBlendMode::kDstOver; break;
        case 5: _a1 = SkBlendMode::kSrcIn; break;
        case 6: _a1 = SkBlendMode::kDstIn; break;
        case 7: _a1 = SkBlendMode::kSrcOut; break;
        case 8: _a1 = SkBlendMode::kDstOut; break;
        case 9: _a1 = SkBlendMode::kSrcATop; break;
        case 10: _a1 = SkBlendMode::kDstATop; break;
        case 11: _a1 = SkBlendMode::kXor; break;
        case 12: _a1 = SkBlendMode::kPlus; break;
        case 13: _a1 = SkBlendMode::kModulate; break;
        case 14: _a1 = SkBlendMode::kScreen; break;
        case 15: _a1 = SkBlendMode::kOverlay; break;
        case 16: _a1 = SkBlendMode::kDarken; break;
        case 17: _a1 = SkBlendMode::kLighten; break;
        case 18: _a1 = SkBlendMode::kColorDodge; break;
        case 19: _a1 = SkBlendMode::kColorBurn; break;
        case 20: _a1 = SkBlendMode::kHardLight; break;
        case 21: _a1 = SkBlendMode::kSoftLight; break;
        case 22: _a1 = SkBlendMode::kDifference; break;
        case 23: _a1 = SkBlendMode::kExclusion; break;
        case 24: _a1 = SkBlendMode::kMultiply; break;
        case 25: _a1 = SkBlendMode::kHue; break;
        case 26: _a1 = SkBlendMode::kSaturation; break;
        case 27: _a1 = SkBlendMode::kColor; break;
        case 28: _a1 = SkBlendMode::kLuminosity; break;
        case 29: _a1 = SkBlendMode::kLastCoeffMode; break;
        case 30: _a1 = SkBlendMode::kLastSeparableMode; break;
        case 31: _a1 = SkBlendMode::kLastMode; break;
    }
    sk_sp<SkColorFilter> *_o0;
	_o0 = MAKE(sk_sp<SkColorFilter>);
	sk_sp<SkColorFilter> ref = SkColorFilters::Blend(_a0, _a1);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sk_sp<SkColorFilter>::sk_sp<SkColorFilter> SkColorMatrixFilter::MakeLightingFilter(SkColor None, SkColor None);) */
extern "C" void shim_63(void **in_ref, void **out_ref, const char *context) {
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    uint32_t _a1;
    memcpy(&_a1, context + 4, sizeof(uint32_t));
    sk_sp<SkColorFilter> *_o0;
	_o0 = MAKE(sk_sp<SkColorFilter>);
	sk_sp<SkColorFilter> ref = SkColorMatrixFilter::MakeLightingFilter(_a0, _a1);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sk_sp<SkColorFilter>::sk_sp<SkColorFilter> SkLumaColorFilter::Make();) */
extern "C" void shim_64(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkColorFilter> *_o0;
	_o0 = MAKE(sk_sp<SkColorFilter>);
	sk_sp<SkColorFilter> ref = SkLumaColorFilter::Make();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sk_sp<SkColorFilter>::~sk_sp<SkColorFilter>();) */
extern "C" void shim_65(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkColorFilter> *_i0 = reinterpret_cast<sk_sp<SkColorFilter> *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) SkPaint::SkPaint();) */
extern "C" void shim_66(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_o0;
	_o0 = MAKE(SkPaint);
	SkPaint ref = SkPaint();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPaint::void setAntiAlias(bool None);) */
extern "C" void shim_67(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    SkPaint *_o0;
	FUZZ_ENDPOINT(_i0->setAntiAlias(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPaint::void setDither(bool None);) */
extern "C" void shim_68(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    SkPaint *_o0;
	FUZZ_ENDPOINT(_i0->setDither(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPaint::void setColor(SkColor None);) */
extern "C" void shim_69(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    SkPaint *_o0;
	FUZZ_ENDPOINT(_i0->setColor(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPaint::void setBlendMode(SkBlendMode None);) */
extern "C" void shim_70(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    SkBlendMode _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 32) {
        case 0: _a0 = SkBlendMode::kClear; break;
        case 1: _a0 = SkBlendMode::kSrc; break;
        case 2: _a0 = SkBlendMode::kDst; break;
        case 3: _a0 = SkBlendMode::kSrcOver; break;
        case 4: _a0 = SkBlendMode::kDstOver; break;
        case 5: _a0 = SkBlendMode::kSrcIn; break;
        case 6: _a0 = SkBlendMode::kDstIn; break;
        case 7: _a0 = SkBlendMode::kSrcOut; break;
        case 8: _a0 = SkBlendMode::kDstOut; break;
        case 9: _a0 = SkBlendMode::kSrcATop; break;
        case 10: _a0 = SkBlendMode::kDstATop; break;
        case 11: _a0 = SkBlendMode::kXor; break;
        case 12: _a0 = SkBlendMode::kPlus; break;
        case 13: _a0 = SkBlendMode::kModulate; break;
        case 14: _a0 = SkBlendMode::kScreen; break;
        case 15: _a0 = SkBlendMode::kOverlay; break;
        case 16: _a0 = SkBlendMode::kDarken; break;
        case 17: _a0 = SkBlendMode::kLighten; break;
        case 18: _a0 = SkBlendMode::kColorDodge; break;
        case 19: _a0 = SkBlendMode::kColorBurn; break;
        case 20: _a0 = SkBlendMode::kHardLight; break;
        case 21: _a0 = SkBlendMode::kSoftLight; break;
        case 22: _a0 = SkBlendMode::kDifference; break;
        case 23: _a0 = SkBlendMode::kExclusion; break;
        case 24: _a0 = SkBlendMode::kMultiply; break;
        case 25: _a0 = SkBlendMode::kHue; break;
        case 26: _a0 = SkBlendMode::kSaturation; break;
        case 27: _a0 = SkBlendMode::kColor; break;
        case 28: _a0 = SkBlendMode::kLuminosity; break;
        case 29: _a0 = SkBlendMode::kLastCoeffMode; break;
        case 30: _a0 = SkBlendMode::kLastSeparableMode; break;
        case 31: _a0 = SkBlendMode::kLastMode; break;
    }
    SkPaint *_o0;
	FUZZ_ENDPOINT(_i0->setBlendMode(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPaint::void setStyle(SkPaint::Style None);) */
extern "C" void shim_71(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    SkPaint::Style _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 3) {
        case 0: _a0 = SkPaint::Style::kFill_Style; break;
        case 1: _a0 = SkPaint::Style::kStroke_Style; break;
        case 2: _a0 = SkPaint::Style::kStrokeAndFill_Style; break;
    }
    SkPaint *_o0;
	FUZZ_ENDPOINT(_i0->setStyle(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPaint::void setShader(sk_sp<SkShader> None);) */
extern "C" void shim_72(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    sk_sp<SkShader> *_i1 = reinterpret_cast<sk_sp<SkShader> *>(in_ref[1]);
    SkPaint *_o0;
    sk_sp<SkShader> *_o1;
	FUZZ_ENDPOINT(_i0->setShader(*_i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPaint::void setPathEffect(sk_sp<SkPathEffect> None);) */
extern "C" void shim_73(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    sk_sp<SkPathEffect> *_i1 = reinterpret_cast<sk_sp<SkPathEffect> *>(in_ref[1]);
    SkPaint *_o0;
    sk_sp<SkPathEffect> *_o1;
	FUZZ_ENDPOINT(_i0->setPathEffect(*_i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPaint::void setMaskFilter(sk_sp<SkMaskFilter> None);) */
extern "C" void shim_74(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    sk_sp<SkMaskFilter> *_i1 = reinterpret_cast<sk_sp<SkMaskFilter> *>(in_ref[1]);
    SkPaint *_o0;
    sk_sp<SkMaskFilter> *_o1;
	FUZZ_ENDPOINT(_i0->setMaskFilter(*_i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPaint::void setImageFilter(sk_sp<SkImageFilter> None);) */
extern "C" void shim_75(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    SkPaint *_o0;
    sk_sp<SkImageFilter> *_o1;
	FUZZ_ENDPOINT(_i0->setImageFilter(*_i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPaint::void setColorFilter(sk_sp<SkColorFilter> None);) */
extern "C" void shim_76(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    sk_sp<SkColorFilter> *_i1 = reinterpret_cast<sk_sp<SkColorFilter> *>(in_ref[1]);
    SkPaint *_o0;
    sk_sp<SkColorFilter> *_o1;
	FUZZ_ENDPOINT(_i0->setColorFilter(*_i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPaint::void setStrokeWidth(SkScalar None);) */
extern "C" void shim_77(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    SkPaint *_o0;
	FUZZ_ENDPOINT(_i0->setStrokeWidth(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPaint::void setStrokeMiter(SkScalar None);) */
extern "C" void shim_78(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    SkPaint *_o0;
	FUZZ_ENDPOINT(_i0->setStrokeMiter(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPaint::void setStrokeCap(SkPaint::Cap None);) */
extern "C" void shim_79(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    SkPaint::Cap _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = SkPaint::Cap::kButt_Cap; break;
        case 1: _a0 = SkPaint::Cap::kRound_Cap; break;
        case 2: _a0 = SkPaint::Cap::kSquare_Cap; break;
        case 3: _a0 = SkPaint::Cap::kLast_Cap; break;
        case 4: _a0 = SkPaint::Cap::kDefault_Cap; break;
    }
    SkPaint *_o0;
	FUZZ_ENDPOINT(_i0->setStrokeCap(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPaint::void setStrokeJoin(SkPaint::Join None);) */
extern "C" void shim_80(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    SkPaint::Join _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = SkPaint::Join::kMiter_Join; break;
        case 1: _a0 = SkPaint::Join::kRound_Join; break;
        case 2: _a0 = SkPaint::Join::kBevel_Join; break;
        case 3: _a0 = SkPaint::Join::kLast_Join; break;
        case 4: _a0 = SkPaint::Join::kDefault_Join; break;
    }
    SkPaint *_o0;
	FUZZ_ENDPOINT(_i0->setStrokeJoin(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPaint::~SkPaint();) */
extern "C" void shim_81(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) SkFont::SkFont();) */
extern "C" void shim_82(void **in_ref, void **out_ref, const char *context) {
    SkFont *_o0;
	_o0 = MAKE(SkFont);
	SkFont ref = SkFont();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::void setTypeface(sk_sp<SkTypeface> None);) */
extern "C" void shim_83(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    sk_sp<SkTypeface> *_i1 = reinterpret_cast<sk_sp<SkTypeface> *>(in_ref[1]);
    SkFont *_o0;
    sk_sp<SkTypeface> *_o1;
	FUZZ_ENDPOINT(_i0->setTypeface(*_i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkFont::void setSize(SkScalar None);) */
extern "C" void shim_84(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setSize(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::void setScaleX(SkScalar None);) */
extern "C" void shim_85(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setScaleX(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::void setSkewX(SkScalar None);) */
extern "C" void shim_86(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setSkewX(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::void setLinearMetrics(bool None);) */
extern "C" void shim_87(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setLinearMetrics(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::void setSubpixel(bool None);) */
extern "C" void shim_88(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setSubpixel(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::void setEmbeddedBitmaps(bool None);) */
extern "C" void shim_89(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setEmbeddedBitmaps(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::void setForceAutoHinting(bool None);) */
extern "C" void shim_90(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setForceAutoHinting(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::void setEmbolden(bool None);) */
extern "C" void shim_91(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setEmbolden(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::void setHinting(SkFontHinting None);) */
extern "C" void shim_92(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    SkFontHinting _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 4) {
        case 0: _a0 = SkFontHinting::kNone; break;
        case 1: _a0 = SkFontHinting::kSlight; break;
        case 2: _a0 = SkFontHinting::kNormal; break;
        case 3: _a0 = SkFontHinting::kFull; break;
    }
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setHinting(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::void setEdging(SkFont::Edging None);) */
extern "C" void shim_93(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    SkFont::Edging _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 3) {
        case 0: _a0 = SkFont::Edging::kAlias; break;
        case 1: _a0 = SkFont::Edging::kAntiAlias; break;
        case 2: _a0 = SkFont::Edging::kSubpixelAntiAlias; break;
    }
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setEdging(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::~SkFont();) */
extern "C" void shim_94(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) SkRect::SkRect MakeXYWH(SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_95(void **in_ref, void **out_ref, const char *context) {
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
extern "C" void shim_96(void **in_ref, void **out_ref, const char *context) {
    SkRect *_i0 = reinterpret_cast<SkRect *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) SkPoint3::SkPoint3 Make(SkScalar x, SkScalar y, SkScalar z);) */
extern "C" void shim_97(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    SkPoint3 *_o0;
	_o0 = MAKE(SkPoint3);
	SkPoint3 ref = SkPoint3::Make(_a0, _a1, _a2);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPoint3::~SkPoint3();) */
extern "C" void shim_98(void **in_ref, void **out_ref, const char *context) {
    SkPoint3 *_i0 = reinterpret_cast<SkPoint3 *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=canvas_saveLayer) */
extern "C" void shim_99(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    sk_sp<SkImageFilter> *_i3 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[3]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    bool _a2 = *(static_cast<const char *>(context + 2)) & 1;
    SkCanvas *_o0;
    SkRect *_o1;
    SkPaint *_o2;
    sk_sp<SkImageFilter> *_o3;
	SkCanvas::SaveLayerRec saveLayerRec;
	if (_a0) saveLayerRec.fBounds = _i1;
	if (_a1) saveLayerRec.fPaint = _i2;
	if (_a2) saveLayerRec.fBackdrop = _i3->get();
	_i0->saveLayer(saveLayerRec);
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=canvas_drawPoints) */
extern "C" void shim_100(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    float _a0[60];
    memcpy(&_a0, context + 0, 4 * 60);
    int _a1;
    memcpy(&_a1, context + 240, sizeof(int));
    SkCanvas::PointMode _a2;
    switch (*(reinterpret_cast<const unsigned char *>(context + 244)) % 3) {
        case 0: _a2 = SkCanvas::PointMode::kPoints_PointMode; break;
        case 1: _a2 = SkCanvas::PointMode::kLines_PointMode; break;
        case 2: _a2 = SkCanvas::PointMode::kPolygon_PointMode; break;
    }
    SkCanvas *_o0;
    SkPaint *_o1;
	int count = _a1 % 30;
	SkPoint pts[30];
	for (int i = 0; i < count; ++i) {
	  pts[i] = SkPoint::Make(_a0[i*2], _a0[(i*2)+1]);
	}
	_i0->drawPoints(_a2, count, pts, *_i1);
	_o0 = _i0;
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=drawImage) */
extern "C" void shim_101(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    SkCanvas *_o0;
    sk_sp<SkImage> *_o1;
    SkPaint *_o2;
	_i0->drawImage(_i1->get(), _a0, _a1, SkSamplingOptions(), _a2 ? _i2 : nullptr);
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=drawImageRect) */
extern "C" void shim_102(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    SkRect *_i2 = reinterpret_cast<SkRect *>(in_ref[2]);
    SkRect *_i3 = reinterpret_cast<SkRect *>(in_ref[3]);
    SkPaint *_i4 = reinterpret_cast<SkPaint *>(in_ref[4]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    SkCanvas *_o0;
    sk_sp<SkImage> *_o1;
    SkRect *_o2;
    SkRect *_o3;
    SkPaint *_o4;
	_i0->drawImageRect(_i1->get(), *_i2, *_i3, SkSamplingOptions(), _a0 ? _i4 : nullptr, _a1 ? SkCanvas::kStrict_SrcRectConstraint : SkCanvas::kFast_SrcRectConstraint);
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	_o4 = _i4;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);
}


/* CPPScope(name=drawImageNine) */
extern "C" void shim_103(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    SkIRect *_i2 = reinterpret_cast<SkIRect *>(in_ref[2]);
    SkRect *_i3 = reinterpret_cast<SkRect *>(in_ref[3]);
    SkPaint *_i4 = reinterpret_cast<SkPaint *>(in_ref[4]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    SkCanvas *_o0;
    sk_sp<SkImage> *_o1;
    SkIRect *_o2;
    SkRect *_o3;
    SkPaint *_o4;
	_i0->drawImageNine(_i1->get(), *_i2, *_i3, SkFilterMode::kNearest, _a0 ? _i4 : nullptr);
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	_o4 = _i4;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);
}


/* CPPScope(name=canvas_drawImageLattice) */
extern "C" void shim_104(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    SkRect *_i2 = reinterpret_cast<SkRect *>(in_ref[2]);
    SkPaint *_i3 = reinterpret_cast<SkPaint *>(in_ref[3]);
    int _a0[6];
    memcpy(&_a0, context + 0, 4 * 6);
    int _a1[6];
    memcpy(&_a1, context + 24, 4 * 6);
    int _a2;
    memcpy(&_a2, context + 48, sizeof(int));
    int _a3;
    memcpy(&_a3, context + 52, sizeof(int));
    bool _a4 = *(static_cast<const char *>(context + 56)) & 1;
    SkCanvas *_o0;
    sk_sp<SkImage> *_o1;
    SkRect *_o2;
    SkPaint *_o3;
	SkCanvas::Lattice lattice{
	  _a0, 
	  _a1, 
	  nullptr, 
	  (_a2 % (6-2)) + 2,
	  (_a3 % (6-2)) + 2, 
	  nullptr, 
	  nullptr
	};
	_i0->drawImageLattice(_i1->get(), lattice, *_i2, SkFilterMode::kLinear, _a4 ? _i3 : nullptr);
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=canvas_drawSimpleText) */
extern "C" void shim_105(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkFont *_i1 = reinterpret_cast<SkFont *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    float _a1;
    memcpy(&_a1, context + 128, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 132, sizeof(float));
    SkTextEncoding _a3;
    switch (*(reinterpret_cast<const unsigned char *>(context + 136)) % 4) {
        case 0: _a3 = SkTextEncoding::kUTF8; break;
        case 1: _a3 = SkTextEncoding::kUTF16; break;
        case 2: _a3 = SkTextEncoding::kUTF32; break;
        case 3: _a3 = SkTextEncoding::kGlyphID; break;
    }
    SkCanvas *_o0;
    SkFont *_o1;
    SkPaint *_o2;
	Fuzz f = Fuzz(_a0, 128);
	SkTDArray<uint8_t> text = make_fuzz_text(&f, *_i1, _a3);
	_i0->drawSimpleText(
	  text.begin(), 
	  SkToSizeT(text.count()),
	  _a3,
	  _a1,
	  _a2,
	  *_i1,
	  *_i2
	);
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=canvas_drawVertices) */
extern "C" void shim_106(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    SkVertices::VertexMode _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 3) {
        case 0: _a0 = SkVertices::VertexMode::kTriangles_VertexMode; break;
        case 1: _a0 = SkVertices::VertexMode::kTriangleStrip_VertexMode; break;
        case 2: _a0 = SkVertices::VertexMode::kTriangleFan_VertexMode; break;
    }
    SkBlendMode _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 1)) % 32) {
        case 0: _a1 = SkBlendMode::kClear; break;
        case 1: _a1 = SkBlendMode::kSrc; break;
        case 2: _a1 = SkBlendMode::kDst; break;
        case 3: _a1 = SkBlendMode::kSrcOver; break;
        case 4: _a1 = SkBlendMode::kDstOver; break;
        case 5: _a1 = SkBlendMode::kSrcIn; break;
        case 6: _a1 = SkBlendMode::kDstIn; break;
        case 7: _a1 = SkBlendMode::kSrcOut; break;
        case 8: _a1 = SkBlendMode::kDstOut; break;
        case 9: _a1 = SkBlendMode::kSrcATop; break;
        case 10: _a1 = SkBlendMode::kDstATop; break;
        case 11: _a1 = SkBlendMode::kXor; break;
        case 12: _a1 = SkBlendMode::kPlus; break;
        case 13: _a1 = SkBlendMode::kModulate; break;
        case 14: _a1 = SkBlendMode::kScreen; break;
        case 15: _a1 = SkBlendMode::kOverlay; break;
        case 16: _a1 = SkBlendMode::kDarken; break;
        case 17: _a1 = SkBlendMode::kLighten; break;
        case 18: _a1 = SkBlendMode::kColorDodge; break;
        case 19: _a1 = SkBlendMode::kColorBurn; break;
        case 20: _a1 = SkBlendMode::kHardLight; break;
        case 21: _a1 = SkBlendMode::kSoftLight; break;
        case 22: _a1 = SkBlendMode::kDifference; break;
        case 23: _a1 = SkBlendMode::kExclusion; break;
        case 24: _a1 = SkBlendMode::kMultiply; break;
        case 25: _a1 = SkBlendMode::kHue; break;
        case 26: _a1 = SkBlendMode::kSaturation; break;
        case 27: _a1 = SkBlendMode::kColor; break;
        case 28: _a1 = SkBlendMode::kLuminosity; break;
        case 29: _a1 = SkBlendMode::kLastCoeffMode; break;
        case 30: _a1 = SkBlendMode::kLastSeparableMode; break;
        case 31: _a1 = SkBlendMode::kLastMode; break;
    }
    float _a2[200];
    memcpy(&_a2, context + 2, 4 * 200);
    float _a3[200];
    memcpy(&_a3, context + 802, 4 * 200);
    uint32_t _a4[100];
    memcpy(&_a4, context + 1602, 4 * 100);
    int _a5;
    memcpy(&_a5, context + 2002, sizeof(int));
    bool _a6 = *(static_cast<const char *>(context + 2006)) & 1;
    bool _a7 = *(static_cast<const char *>(context + 2007)) & 1;
    bool _a8 = *(static_cast<const char *>(context + 2008)) & 1;
    uint16_t _a9[200];
    memcpy(&_a9, context + 2009, 2 * 200);
    int _a10;
    memcpy(&_a10, context + 2409, sizeof(int));
    SkCanvas *_o0;
    SkPaint *_o1;
	int vertexCount = (_a5 % (100 - 3)) + 3;
	
	SkPoint vertices[100];
	SkPoint texs[100];
	
	for (int i = 0; i < vertexCount; ++i) {
	  vertices[i] = SkPoint::Make(_a2[i*2], _a2[(i*2)+1]);
	  texs[i] = SkPoint::Make(_a3[i*2], _a3[(i*2)+1]);
	}
	
	int indexCount = _a8 ? ((_a10 % 100) + vertexCount) : 0;
	
	_i0->drawVertices(SkVertices::MakeCopy(
	    _a0, vertexCount, vertices,
	    _a6 ? texs : nullptr,
	    _a7 ? _a4 : nullptr,
	    indexCount, _a9
	  ), _a1, *_i1
	);
	_o0 = _i0;
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=void drawColor(SkColor4f, SkBlendMode)) */
extern "C" void shim_107(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    SkBlendMode _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 4)) % 32) {
        case 0: _a1 = SkBlendMode::kClear; break;
        case 1: _a1 = SkBlendMode::kSrc; break;
        case 2: _a1 = SkBlendMode::kDst; break;
        case 3: _a1 = SkBlendMode::kSrcOver; break;
        case 4: _a1 = SkBlendMode::kDstOver; break;
        case 5: _a1 = SkBlendMode::kSrcIn; break;
        case 6: _a1 = SkBlendMode::kDstIn; break;
        case 7: _a1 = SkBlendMode::kSrcOut; break;
        case 8: _a1 = SkBlendMode::kDstOut; break;
        case 9: _a1 = SkBlendMode::kSrcATop; break;
        case 10: _a1 = SkBlendMode::kDstATop; break;
        case 11: _a1 = SkBlendMode::kXor; break;
        case 12: _a1 = SkBlendMode::kPlus; break;
        case 13: _a1 = SkBlendMode::kModulate; break;
        case 14: _a1 = SkBlendMode::kScreen; break;
        case 15: _a1 = SkBlendMode::kOverlay; break;
        case 16: _a1 = SkBlendMode::kDarken; break;
        case 17: _a1 = SkBlendMode::kLighten; break;
        case 18: _a1 = SkBlendMode::kColorDodge; break;
        case 19: _a1 = SkBlendMode::kColorBurn; break;
        case 20: _a1 = SkBlendMode::kHardLight; break;
        case 21: _a1 = SkBlendMode::kSoftLight; break;
        case 22: _a1 = SkBlendMode::kDifference; break;
        case 23: _a1 = SkBlendMode::kExclusion; break;
        case 24: _a1 = SkBlendMode::kMultiply; break;
        case 25: _a1 = SkBlendMode::kHue; break;
        case 26: _a1 = SkBlendMode::kSaturation; break;
        case 27: _a1 = SkBlendMode::kColor; break;
        case 28: _a1 = SkBlendMode::kLuminosity; break;
        case 29: _a1 = SkBlendMode::kLastCoeffMode; break;
        case 30: _a1 = SkBlendMode::kLastSeparableMode; break;
        case 31: _a1 = SkBlendMode::kLastMode; break;
    }
    SkCanvas *_o0;
	_i0->drawColor(SkColor4f::FromColor(_a0), _a1);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=canvas_drawString) */
extern "C" void shim_108(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkFont *_i1 = reinterpret_cast<SkFont *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    float _a1;
    memcpy(&_a1, context + 128, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 132, sizeof(float));
    SkCanvas *_o0;
    SkFont *_o1;
    SkPaint *_o2;
	Fuzz f = Fuzz(_a0, 128);
	std::string str = make_fuzz_string(&f);
	_i0->drawString(str.c_str(), _a1, _a2, *_i1, *_i2);
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=canvas_drawPatch) */
extern "C" void shim_109(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    float _a0[24];
    memcpy(&_a0, context + 0, 4 * 24);
    uint32_t _a1[4];
    memcpy(&_a1, context + 96, 4 * 4);
    float _a2[8];
    memcpy(&_a2, context + 112, 4 * 8);
    bool _a3 = *(static_cast<const char *>(context + 144)) & 1;
    SkBlendMode _a4;
    switch (*(reinterpret_cast<const unsigned char *>(context + 145)) % 32) {
        case 0: _a4 = SkBlendMode::kClear; break;
        case 1: _a4 = SkBlendMode::kSrc; break;
        case 2: _a4 = SkBlendMode::kDst; break;
        case 3: _a4 = SkBlendMode::kSrcOver; break;
        case 4: _a4 = SkBlendMode::kDstOver; break;
        case 5: _a4 = SkBlendMode::kSrcIn; break;
        case 6: _a4 = SkBlendMode::kDstIn; break;
        case 7: _a4 = SkBlendMode::kSrcOut; break;
        case 8: _a4 = SkBlendMode::kDstOut; break;
        case 9: _a4 = SkBlendMode::kSrcATop; break;
        case 10: _a4 = SkBlendMode::kDstATop; break;
        case 11: _a4 = SkBlendMode::kXor; break;
        case 12: _a4 = SkBlendMode::kPlus; break;
        case 13: _a4 = SkBlendMode::kModulate; break;
        case 14: _a4 = SkBlendMode::kScreen; break;
        case 15: _a4 = SkBlendMode::kOverlay; break;
        case 16: _a4 = SkBlendMode::kDarken; break;
        case 17: _a4 = SkBlendMode::kLighten; break;
        case 18: _a4 = SkBlendMode::kColorDodge; break;
        case 19: _a4 = SkBlendMode::kColorBurn; break;
        case 20: _a4 = SkBlendMode::kHardLight; break;
        case 21: _a4 = SkBlendMode::kSoftLight; break;
        case 22: _a4 = SkBlendMode::kDifference; break;
        case 23: _a4 = SkBlendMode::kExclusion; break;
        case 24: _a4 = SkBlendMode::kMultiply; break;
        case 25: _a4 = SkBlendMode::kHue; break;
        case 26: _a4 = SkBlendMode::kSaturation; break;
        case 27: _a4 = SkBlendMode::kColor; break;
        case 28: _a4 = SkBlendMode::kLuminosity; break;
        case 29: _a4 = SkBlendMode::kLastCoeffMode; break;
        case 30: _a4 = SkBlendMode::kLastSeparableMode; break;
        case 31: _a4 = SkBlendMode::kLastMode; break;
    }
    SkCanvas *_o0;
    SkPaint *_o1;
	SkPoint cubics[12];
	for (int i = 0; i < 12; ++i) cubics[i] = SkPoint::Make(_a0[i*2], _a0[(i*2)+1]);
	SkPoint tex[4];
	for (int i = 0; i < 4; ++i) tex[i] = SkPoint::Make(_a2[i*2], _a2[(i*2)+1]);
	_i0->drawPatch(cubics, _a1, _a3 ? tex : nullptr, _a4, *_i1);
	_o0 = _i0;
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkCanvas::void flush();) */
extern "C" void shim_110(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkCanvas *_o0;
	FUZZ_ENDPOINT(_i0->flush();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkCanvas::void save();) */
extern "C" void shim_111(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkCanvas *_o0;
	FUZZ_ENDPOINT(_i0->save();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkCanvas::void saveLayer(SkRect * None, SkPaint * None);) */
extern "C" void shim_112(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    SkCanvas *_o0;
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(_i0->saveLayer(_i1, _i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkCanvas::void saveLayer(SkRect * None, {nullptr});) */
extern "C" void shim_113(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkCanvas *_o0;
    SkRect *_o1;
	FUZZ_ENDPOINT(_i0->saveLayer(_i1, nullptr);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkCanvas::void saveLayer({nullptr}, SkPaint * None);) */
extern "C" void shim_114(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    SkCanvas *_o0;
    SkPaint *_o1;
	FUZZ_ENDPOINT(_i0->saveLayer(nullptr, _i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkCanvas::void saveLayer({nullptr}, {nullptr});) */
extern "C" void shim_115(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkCanvas *_o0;
	FUZZ_ENDPOINT(_i0->saveLayer(nullptr, nullptr);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkCanvas::void saveLayerAlpha({nullptr}, uint8_t None);) */
extern "C" void shim_116(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    SkCanvas *_o0;
	FUZZ_ENDPOINT(_i0->saveLayerAlpha(nullptr, _a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkCanvas::void saveLayerAlpha(SkRect * None, uint8_t None);) */
extern "C" void shim_117(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    SkCanvas *_o0;
    SkRect *_o1;
	FUZZ_ENDPOINT(_i0->saveLayerAlpha(_i1, _a0);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkCanvas::void restore();) */
extern "C" void shim_118(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkCanvas *_o0;
	FUZZ_ENDPOINT(_i0->restore();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkCanvas::void restoreToCount(int None);) */
extern "C" void shim_119(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    SkCanvas *_o0;
	FUZZ_ENDPOINT(_i0->restoreToCount(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkCanvas::void translate(SkScalar None, SkScalar None);) */
extern "C" void shim_120(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkCanvas *_o0;
	FUZZ_ENDPOINT(_i0->translate(_a0, _a1);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkCanvas::void scale(SkScalar None, SkScalar None);) */
extern "C" void shim_121(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkCanvas *_o0;
	FUZZ_ENDPOINT(_i0->scale(_a0, _a1);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkCanvas::void rotate(SkScalar None);) */
extern "C" void shim_122(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    SkCanvas *_o0;
	FUZZ_ENDPOINT(_i0->rotate(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkCanvas::void rotate(SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_123(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    SkCanvas *_o0;
	FUZZ_ENDPOINT(_i0->rotate(_a0, _a1, _a2);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkCanvas::void skew(SkScalar None, SkScalar None);) */
extern "C" void shim_124(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkCanvas *_o0;
	FUZZ_ENDPOINT(_i0->skew(_a0, _a1);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkCanvas::void concat(SkMatrix None);) */
extern "C" void shim_125(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkMatrix *_i1 = reinterpret_cast<SkMatrix *>(in_ref[1]);
    SkCanvas *_o0;
    SkMatrix *_o1;
	FUZZ_ENDPOINT(_i0->concat(*_i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkCanvas::void setMatrix(SkMatrix None);) */
extern "C" void shim_126(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkMatrix *_i1 = reinterpret_cast<SkMatrix *>(in_ref[1]);
    SkCanvas *_o0;
    SkMatrix *_o1;
	FUZZ_ENDPOINT(_i0->setMatrix(*_i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkCanvas::void resetMatrix();) */
extern "C" void shim_127(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkCanvas *_o0;
	FUZZ_ENDPOINT(_i0->resetMatrix();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkCanvas::void clipRect(SkRect None, SkClipOp None, bool None);) */
extern "C" void shim_128(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkClipOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkClipOp::kDifference; break;
        case 1: _a0 = SkClipOp::kIntersect; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    SkCanvas *_o0;
    SkRect *_o1;
	FUZZ_ENDPOINT(_i0->clipRect(*_i1, _a0, _a1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkCanvas::void clipRRect(SkRRect None, SkClipOp None, bool None);) */
extern "C" void shim_129(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkRRect *_i1 = reinterpret_cast<SkRRect *>(in_ref[1]);
    SkClipOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkClipOp::kDifference; break;
        case 1: _a0 = SkClipOp::kIntersect; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    SkCanvas *_o0;
    SkRRect *_o1;
	FUZZ_ENDPOINT(_i0->clipRRect(*_i1, _a0, _a1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkCanvas::void clipPath(SkPath None, SkClipOp None, bool None);) */
extern "C" void shim_130(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    SkClipOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkClipOp::kDifference; break;
        case 1: _a0 = SkClipOp::kIntersect; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    SkCanvas *_o0;
    SkPath *_o1;
	FUZZ_ENDPOINT(_i0->clipPath(*_i1, _a0, _a1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkCanvas::void clipRegion(SkRegion None, SkClipOp None);) */
extern "C" void shim_131(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkRegion *_i1 = reinterpret_cast<SkRegion *>(in_ref[1]);
    SkClipOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkClipOp::kDifference; break;
        case 1: _a0 = SkClipOp::kIntersect; break;
    }
    SkCanvas *_o0;
    SkRegion *_o1;
	FUZZ_ENDPOINT(_i0->clipRegion(*_i1, _a0);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkCanvas::void drawPaint(SkPaint None);) */
extern "C" void shim_132(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    SkCanvas *_o0;
    SkPaint *_o1;
	FUZZ_ENDPOINT(_i0->drawPaint(*_i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkCanvas::void drawRect(SkRect None, SkPaint None);) */
extern "C" void shim_133(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    SkCanvas *_o0;
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(_i0->drawRect(*_i1, *_i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkCanvas::void drawRegion(SkRegion None, SkPaint None);) */
extern "C" void shim_134(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkRegion *_i1 = reinterpret_cast<SkRegion *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    SkCanvas *_o0;
    SkRegion *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(_i0->drawRegion(*_i1, *_i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkCanvas::void drawOval(SkRect None, SkPaint None);) */
extern "C" void shim_135(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    SkCanvas *_o0;
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(_i0->drawOval(*_i1, *_i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkCanvas::void drawRRect(SkRRect None, SkPaint None);) */
extern "C" void shim_136(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkRRect *_i1 = reinterpret_cast<SkRRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    SkCanvas *_o0;
    SkRRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(_i0->drawRRect(*_i1, *_i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkCanvas::void drawDRRect(SkRRect None, SkRRect None, SkPaint None);) */
extern "C" void shim_137(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkRRect *_i1 = reinterpret_cast<SkRRect *>(in_ref[1]);
    SkRRect *_i2 = reinterpret_cast<SkRRect *>(in_ref[2]);
    SkPaint *_i3 = reinterpret_cast<SkPaint *>(in_ref[3]);
    SkCanvas *_o0;
    SkRRect *_o1;
    SkRRect *_o2;
    SkPaint *_o3;
	FUZZ_ENDPOINT(_i0->drawDRRect(*_i1, *_i2, *_i3);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=(auto) SkCanvas::void drawArc(SkRect None, SkScalar None, SkScalar None, bool None, SkPaint None);) */
extern "C" void shim_138(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    SkCanvas *_o0;
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(_i0->drawArc(*_i1, _a0, _a1, _a2, *_i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkCanvas::void drawPath(SkPath None, SkPaint None);) */
extern "C" void shim_139(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    SkCanvas *_o0;
    SkPath *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(_i0->drawPath(*_i1, *_i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkCanvas::void drawTextBlob(sk_sp<SkTextBlob> None, SkScalar None, SkScalar None, SkPaint None);) */
extern "C" void shim_140(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    sk_sp<SkTextBlob> *_i1 = reinterpret_cast<sk_sp<SkTextBlob> *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkCanvas *_o0;
    sk_sp<SkTextBlob> *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(_i0->drawTextBlob(*_i1, _a0, _a1, *_i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, SkMatrix * None, SkPaint * None);) */
extern "C" void shim_141(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    sk_sp<SkPicture> *_i1 = reinterpret_cast<sk_sp<SkPicture> *>(in_ref[1]);
    SkMatrix *_i2 = reinterpret_cast<SkMatrix *>(in_ref[2]);
    SkPaint *_i3 = reinterpret_cast<SkPaint *>(in_ref[3]);
    SkCanvas *_o0;
    sk_sp<SkPicture> *_o1;
    SkMatrix *_o2;
    SkPaint *_o3;
	FUZZ_ENDPOINT(_i0->drawPicture(*_i1, _i2, _i3);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, SkMatrix * None, {nullptr});) */
extern "C" void shim_142(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    sk_sp<SkPicture> *_i1 = reinterpret_cast<sk_sp<SkPicture> *>(in_ref[1]);
    SkMatrix *_i2 = reinterpret_cast<SkMatrix *>(in_ref[2]);
    SkCanvas *_o0;
    sk_sp<SkPicture> *_o1;
    SkMatrix *_o2;
	FUZZ_ENDPOINT(_i0->drawPicture(*_i1, _i2, nullptr);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, {nullptr}, SkPaint * None);) */
extern "C" void shim_143(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    sk_sp<SkPicture> *_i1 = reinterpret_cast<sk_sp<SkPicture> *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    SkCanvas *_o0;
    sk_sp<SkPicture> *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(_i0->drawPicture(*_i1, nullptr, _i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, {nullptr}, {nullptr});) */
extern "C" void shim_144(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    sk_sp<SkPicture> *_i1 = reinterpret_cast<sk_sp<SkPicture> *>(in_ref[1]);
    SkCanvas *_o0;
    sk_sp<SkPicture> *_o1;
	FUZZ_ENDPOINT(_i0->drawPicture(*_i1, nullptr, nullptr);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkCanvas::void drawColor(SkColor None, SkBlendMode None);) */
extern "C" void shim_145(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    SkBlendMode _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 4)) % 32) {
        case 0: _a1 = SkBlendMode::kClear; break;
        case 1: _a1 = SkBlendMode::kSrc; break;
        case 2: _a1 = SkBlendMode::kDst; break;
        case 3: _a1 = SkBlendMode::kSrcOver; break;
        case 4: _a1 = SkBlendMode::kDstOver; break;
        case 5: _a1 = SkBlendMode::kSrcIn; break;
        case 6: _a1 = SkBlendMode::kDstIn; break;
        case 7: _a1 = SkBlendMode::kSrcOut; break;
        case 8: _a1 = SkBlendMode::kDstOut; break;
        case 9: _a1 = SkBlendMode::kSrcATop; break;
        case 10: _a1 = SkBlendMode::kDstATop; break;
        case 11: _a1 = SkBlendMode::kXor; break;
        case 12: _a1 = SkBlendMode::kPlus; break;
        case 13: _a1 = SkBlendMode::kModulate; break;
        case 14: _a1 = SkBlendMode::kScreen; break;
        case 15: _a1 = SkBlendMode::kOverlay; break;
        case 16: _a1 = SkBlendMode::kDarken; break;
        case 17: _a1 = SkBlendMode::kLighten; break;
        case 18: _a1 = SkBlendMode::kColorDodge; break;
        case 19: _a1 = SkBlendMode::kColorBurn; break;
        case 20: _a1 = SkBlendMode::kHardLight; break;
        case 21: _a1 = SkBlendMode::kSoftLight; break;
        case 22: _a1 = SkBlendMode::kDifference; break;
        case 23: _a1 = SkBlendMode::kExclusion; break;
        case 24: _a1 = SkBlendMode::kMultiply; break;
        case 25: _a1 = SkBlendMode::kHue; break;
        case 26: _a1 = SkBlendMode::kSaturation; break;
        case 27: _a1 = SkBlendMode::kColor; break;
        case 28: _a1 = SkBlendMode::kLuminosity; break;
        case 29: _a1 = SkBlendMode::kLastCoeffMode; break;
        case 30: _a1 = SkBlendMode::kLastSeparableMode; break;
        case 31: _a1 = SkBlendMode::kLastMode; break;
    }
    SkCanvas *_o0;
	FUZZ_ENDPOINT(_i0->drawColor(_a0, _a1);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkCanvas::void drawLine(SkPoint None, SkPoint None, SkPaint None);) */
extern "C" void shim_146(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkPoint *_i1 = reinterpret_cast<SkPoint *>(in_ref[1]);
    SkPoint *_i2 = reinterpret_cast<SkPoint *>(in_ref[2]);
    SkPaint *_i3 = reinterpret_cast<SkPaint *>(in_ref[3]);
    SkCanvas *_o0;
    SkPoint *_o1;
    SkPoint *_o2;
    SkPaint *_o3;
	FUZZ_ENDPOINT(_i0->drawLine(*_i1, *_i2, *_i3);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=(auto) SkCanvas::void drawIRect(SkIRect None, SkPaint None);) */
extern "C" void shim_147(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkIRect *_i1 = reinterpret_cast<SkIRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    SkCanvas *_o0;
    SkIRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(_i0->drawIRect(*_i1, *_i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkCanvas::void drawCircle(SkPoint None, SkScalar None, SkPaint None);) */
extern "C" void shim_148(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkPoint *_i1 = reinterpret_cast<SkPoint *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    SkCanvas *_o0;
    SkPoint *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(_i0->drawCircle(*_i1, _a0, *_i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkCanvas::void drawArc(SkRect None, SkScalar None, SkScalar None, bool None, SkPaint None);) */
extern "C" void shim_149(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    SkCanvas *_o0;
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(_i0->drawArc(*_i1, _a0, _a1, _a2, *_i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkCanvas::void drawRoundRect(SkRect None, SkScalar None, SkScalar None, SkPaint None);) */
extern "C" void shim_150(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkCanvas *_o0;
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(_i0->drawRoundRect(*_i1, _a0, _a1, *_i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=begin_recording_canvas) */
extern "C" void shim_151(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    GFUZZ_BUNDLE *_o0;
	SkPictureRecorder *recorder = new SkPictureRecorder();
	SkCanvas *canvas = recorder->beginRecording(_a0, _a1);
	_o0 = BUNDLE(canvas, recorder);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=end_recording_canvas) */
extern "C" void shim_152(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkPicture> *_o0;
	SkPictureRecorder *recorder = (SkPictureRecorder *)_i0->inactive;
	delete _i0;
	_o0 = MAKE(sk_sp<SkPicture>);
	*_o0 = recorder->finishRecordingAsPicture();
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sk_sp<SkPicture>::~sk_sp<SkPicture>();) */
extern "C" void shim_153(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkPicture> *_i0 = reinterpret_cast<sk_sp<SkPicture> *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=nullptr) */
extern "C" void shim_154(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkShader> *_o0;
	_o0 = MAKE(sk_sp<SkShader>);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=SkImage::makeShader) */
extern "C" void shim_155(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImage> *_i0 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[0]);
    SkMatrix *_i1 = reinterpret_cast<SkMatrix *>(in_ref[1]);
    SkTileMode _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = SkTileMode::kClamp; break;
        case 1: _a0 = SkTileMode::kRepeat; break;
        case 2: _a0 = SkTileMode::kMirror; break;
        case 3: _a0 = SkTileMode::kDecal; break;
        case 4: _a0 = SkTileMode::kLastTileMode; break;
    }
    SkTileMode _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 1)) % 5) {
        case 0: _a1 = SkTileMode::kClamp; break;
        case 1: _a1 = SkTileMode::kRepeat; break;
        case 2: _a1 = SkTileMode::kMirror; break;
        case 3: _a1 = SkTileMode::kDecal; break;
        case 4: _a1 = SkTileMode::kLastTileMode; break;
    }
    sk_sp<SkShader> *_o0;
    sk_sp<SkImage> *_o1;
    SkMatrix *_o2;
	_o0 = MAKE(sk_sp<SkShader>);
	if (*_i0 != nullptr) *_o0 = (*_i0)->makeShader(_a0, _a1, SkSamplingOptions(), *_i1);
	_o1 = _i0;
	_o2 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=SkShader::makeWithLocalMatrix) */
extern "C" void shim_156(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkShader> *_i0 = reinterpret_cast<sk_sp<SkShader> *>(in_ref[0]);
    SkMatrix *_i1 = reinterpret_cast<SkMatrix *>(in_ref[1]);
    sk_sp<SkShader> *_o0;
    sk_sp<SkShader> *_o1;
    SkMatrix *_o2;
	_o0 = MAKE(sk_sp<SkShader>);
	if (*_i0 != nullptr) *_o0 = (*_i0)->makeWithLocalMatrix(*_i1);
	_o1 = _i0;
	_o2 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=SkShader::makeWithColorFilter) */
extern "C" void shim_157(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkShader> *_i0 = reinterpret_cast<sk_sp<SkShader> *>(in_ref[0]);
    sk_sp<SkColorFilter> *_i1 = reinterpret_cast<sk_sp<SkColorFilter> *>(in_ref[1]);
    sk_sp<SkShader> *_o0;
    sk_sp<SkShader> *_o1;
    sk_sp<SkColorFilter> *_o2;
	_o0 = MAKE(sk_sp<SkShader>);
	if (*_i0 != nullptr) *_o0 = (*_i0)->makeWithColorFilter(*_i1);
	_o1 = _i0;
	_o2 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=SkPicture::makeShader) */
extern "C" void shim_158(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkPicture> *_i0 = reinterpret_cast<sk_sp<SkPicture> *>(in_ref[0]);
    SkMatrix *_i1 = reinterpret_cast<SkMatrix *>(in_ref[1]);
    SkRect *_i2 = reinterpret_cast<SkRect *>(in_ref[2]);
    SkTileMode _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = SkTileMode::kClamp; break;
        case 1: _a0 = SkTileMode::kRepeat; break;
        case 2: _a0 = SkTileMode::kMirror; break;
        case 3: _a0 = SkTileMode::kDecal; break;
        case 4: _a0 = SkTileMode::kLastTileMode; break;
    }
    SkTileMode _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 1)) % 5) {
        case 0: _a1 = SkTileMode::kClamp; break;
        case 1: _a1 = SkTileMode::kRepeat; break;
        case 2: _a1 = SkTileMode::kMirror; break;
        case 3: _a1 = SkTileMode::kDecal; break;
        case 4: _a1 = SkTileMode::kLastTileMode; break;
    }
    bool _a2 = *(static_cast<const char *>(context + 2)) & 1;
    bool _a3 = *(static_cast<const char *>(context + 3)) & 1;
    sk_sp<SkShader> *_o0;
    sk_sp<SkPicture> *_o1;
    SkMatrix *_o2;
    SkRect *_o3;
	_o0 = MAKE(sk_sp<SkShader>);
	if (*_i0 != nullptr) {
	  if (_a2 && _a3)
	    *_o0 = (*_i0)->makeShader(_a0, _a1, SkFilterMode::kNearest, _i1, _i2);
	  else if (_a2)
	    *_o0 = (*_i0)->makeShader(_a0, _a1, SkFilterMode::kNearest, _i1, nullptr);
	  else if (_a3)
	    *_o0 = (*_i0)->makeShader(_a0, _a1, SkFilterMode::kNearest, nullptr, _i2);
	  else
	    *_o0 = (*_i0)->makeShader(_a0, _a1, SkFilterMode::kNearest, nullptr, nullptr);
	}
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=SkGradientShader::MakeLinear) */
extern "C" void shim_159(void **in_ref, void **out_ref, const char *context) {
    SkMatrix *_i0 = reinterpret_cast<SkMatrix *>(in_ref[0]);
    float _a0[2];
    memcpy(&_a0, context + 0, 4 * 2);
    float _a1[2];
    memcpy(&_a1, context + 8, 4 * 2);
    uint32_t _a2[12];
    memcpy(&_a2, context + 16, 4 * 12);
    float _a3[12];
    memcpy(&_a3, context + 64, 4 * 12);
    SkTileMode _a4;
    switch (*(reinterpret_cast<const unsigned char *>(context + 112)) % 5) {
        case 0: _a4 = SkTileMode::kClamp; break;
        case 1: _a4 = SkTileMode::kRepeat; break;
        case 2: _a4 = SkTileMode::kMirror; break;
        case 3: _a4 = SkTileMode::kDecal; break;
        case 4: _a4 = SkTileMode::kLastTileMode; break;
    }
bool _a5[2];
for (int i = 0; i < 2; ++i) _a5[i] = *(static_cast<const char *>(context + 113 + i)) & 1;
    int _a6;
    memcpy(&_a6, context + 115, sizeof(int));
    sk_sp<SkShader> *_o0;
    SkMatrix *_o1;
	_o0 = MAKE(sk_sp<SkShader>);
	
	SkPoint pts[2] = {
	  SkPoint::Make(_a0[0], _a0[1]),
	  SkPoint::Make(_a1[0], _a1[1]),
	};
	
	int colorCount = _a6;
	if (colorCount < 2) colorCount = 2;
	if (colorCount > 12) colorCount = 12;
	
	fuzz_gradient_stops(_a3, colorCount);
	
	if (_a5[0] && _a5[1])
	  *_o0 = SkGradientShader::MakeLinear(pts, _a2, _a3, colorCount, _a4, 0, _i0);
	else if (_a5[0])
	  *_o0 = SkGradientShader::MakeLinear(pts, _a2, _a3, colorCount, _a4, 0, nullptr);
	else if (_a5[1])
	  *_o0 = SkGradientShader::MakeLinear(pts, _a2, nullptr, colorCount, _a4, 0, _i0);
	else
	  *_o0 = SkGradientShader::MakeLinear(pts, _a2, nullptr, colorCount, _a4, 0, nullptr);
	
	_o1 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=SkGradientShader::MakeRadial) */
extern "C" void shim_160(void **in_ref, void **out_ref, const char *context) {
    SkMatrix *_i0 = reinterpret_cast<SkMatrix *>(in_ref[0]);
    float _a0[2];
    memcpy(&_a0, context + 0, 4 * 2);
    float _a1;
    memcpy(&_a1, context + 8, sizeof(float));
    uint32_t _a2[12];
    memcpy(&_a2, context + 12, 4 * 12);
    float _a3[12];
    memcpy(&_a3, context + 60, 4 * 12);
    SkTileMode _a4;
    switch (*(reinterpret_cast<const unsigned char *>(context + 108)) % 5) {
        case 0: _a4 = SkTileMode::kClamp; break;
        case 1: _a4 = SkTileMode::kRepeat; break;
        case 2: _a4 = SkTileMode::kMirror; break;
        case 3: _a4 = SkTileMode::kDecal; break;
        case 4: _a4 = SkTileMode::kLastTileMode; break;
    }
bool _a5[2];
for (int i = 0; i < 2; ++i) _a5[i] = *(static_cast<const char *>(context + 109 + i)) & 1;
    int _a6;
    memcpy(&_a6, context + 111, sizeof(int));
    sk_sp<SkShader> *_o0;
    SkMatrix *_o1;
	_o0 = MAKE(sk_sp<SkShader>);
	
	SkPoint center = SkPoint::Make(_a0[0], _a0[1]);
	
	int colorCount = _a6;
	if (colorCount < 2) colorCount = 2;
	if (colorCount > 12) colorCount = 12;
	
	fuzz_gradient_stops(_a3, colorCount);
	
	if (_a5[0] && _a5[1])
	  *_o0 = SkGradientShader::MakeRadial(center, _a1, _a2, _a3, colorCount, _a4, 0, _i0);
	else if (_a5[0])
	  *_o0 = SkGradientShader::MakeRadial(center, _a1, _a2, _a3, colorCount, _a4, 0, nullptr);
	else if (_a5[1])
	  *_o0 = SkGradientShader::MakeRadial(center, _a1, _a2, nullptr, colorCount, _a4, 0, _i0);
	else
	  *_o0 = SkGradientShader::MakeRadial(center, _a1, _a2, nullptr, colorCount, _a4, 0, nullptr);
	
	_o1 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=SkGradientShader::MakeTwoPointConical) */
extern "C" void shim_161(void **in_ref, void **out_ref, const char *context) {
    SkMatrix *_i0 = reinterpret_cast<SkMatrix *>(in_ref[0]);
    float _a0[4];
    memcpy(&_a0, context + 0, 4 * 4);
    float _a1[2];
    memcpy(&_a1, context + 16, 4 * 2);
    uint32_t _a2[12];
    memcpy(&_a2, context + 24, 4 * 12);
    float _a3[12];
    memcpy(&_a3, context + 72, 4 * 12);
    SkTileMode _a4;
    switch (*(reinterpret_cast<const unsigned char *>(context + 120)) % 5) {
        case 0: _a4 = SkTileMode::kClamp; break;
        case 1: _a4 = SkTileMode::kRepeat; break;
        case 2: _a4 = SkTileMode::kMirror; break;
        case 3: _a4 = SkTileMode::kDecal; break;
        case 4: _a4 = SkTileMode::kLastTileMode; break;
    }
bool _a5[2];
for (int i = 0; i < 2; ++i) _a5[i] = *(static_cast<const char *>(context + 121 + i)) & 1;
    int _a6;
    memcpy(&_a6, context + 123, sizeof(int));
    sk_sp<SkShader> *_o0;
    SkMatrix *_o1;
	_o0 = MAKE(sk_sp<SkShader>);
	
	SkPoint start = SkPoint::Make(_a0[0], _a0[1]);
	SkPoint end = SkPoint::Make(_a0[2], _a0[3]);
	
	int colorCount = _a6;
	if (colorCount < 2) colorCount = 2;
	if (colorCount > 12) colorCount = 12;
	
	fuzz_gradient_stops(_a3, colorCount);
	
	if (_a5[0] && _a5[1])
	  *_o0 = SkGradientShader::MakeTwoPointConical(start, _a1[0], end, _a1[1], _a2, _a3, colorCount, _a4, 0, _i0);
	else if (_a5[0])
	  *_o0 = SkGradientShader::MakeTwoPointConical(start, _a1[0], end, _a1[1], _a2, _a3, colorCount, _a4, 0, nullptr);
	else if (_a5[1])
	  *_o0 = SkGradientShader::MakeTwoPointConical(start, _a1[0], end, _a1[1], _a2, nullptr, colorCount, _a4, 0, _i0);
	else
	  *_o0 = SkGradientShader::MakeTwoPointConical(start, _a1[0], end, _a1[1], _a2, nullptr, colorCount, _a4, 0, nullptr);
	
	_o1 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sk_sp<SkShader>::sk_sp<SkShader> SkShaders::Empty();) */
extern "C" void shim_162(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkShader> *_o0;
	_o0 = MAKE(sk_sp<SkShader>);
	sk_sp<SkShader> ref = SkShaders::Empty();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sk_sp<SkShader>::sk_sp<SkShader> SkShaders::Color(SkColor None);) */
extern "C" void shim_163(void **in_ref, void **out_ref, const char *context) {
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    sk_sp<SkShader> *_o0;
	_o0 = MAKE(sk_sp<SkShader>);
	sk_sp<SkShader> ref = SkShaders::Color(_a0);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sk_sp<SkShader>::sk_sp<SkShader> SkShaders::Blend(SkBlendMode None, sk_sp<SkShader> None, sk_sp<SkShader> None);) */
extern "C" void shim_164(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkShader> *_i0 = reinterpret_cast<sk_sp<SkShader> *>(in_ref[0]);
    sk_sp<SkShader> *_i1 = reinterpret_cast<sk_sp<SkShader> *>(in_ref[1]);
    SkBlendMode _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 32) {
        case 0: _a0 = SkBlendMode::kClear; break;
        case 1: _a0 = SkBlendMode::kSrc; break;
        case 2: _a0 = SkBlendMode::kDst; break;
        case 3: _a0 = SkBlendMode::kSrcOver; break;
        case 4: _a0 = SkBlendMode::kDstOver; break;
        case 5: _a0 = SkBlendMode::kSrcIn; break;
        case 6: _a0 = SkBlendMode::kDstIn; break;
        case 7: _a0 = SkBlendMode::kSrcOut; break;
        case 8: _a0 = SkBlendMode::kDstOut; break;
        case 9: _a0 = SkBlendMode::kSrcATop; break;
        case 10: _a0 = SkBlendMode::kDstATop; break;
        case 11: _a0 = SkBlendMode::kXor; break;
        case 12: _a0 = SkBlendMode::kPlus; break;
        case 13: _a0 = SkBlendMode::kModulate; break;
        case 14: _a0 = SkBlendMode::kScreen; break;
        case 15: _a0 = SkBlendMode::kOverlay; break;
        case 16: _a0 = SkBlendMode::kDarken; break;
        case 17: _a0 = SkBlendMode::kLighten; break;
        case 18: _a0 = SkBlendMode::kColorDodge; break;
        case 19: _a0 = SkBlendMode::kColorBurn; break;
        case 20: _a0 = SkBlendMode::kHardLight; break;
        case 21: _a0 = SkBlendMode::kSoftLight; break;
        case 22: _a0 = SkBlendMode::kDifference; break;
        case 23: _a0 = SkBlendMode::kExclusion; break;
        case 24: _a0 = SkBlendMode::kMultiply; break;
        case 25: _a0 = SkBlendMode::kHue; break;
        case 26: _a0 = SkBlendMode::kSaturation; break;
        case 27: _a0 = SkBlendMode::kColor; break;
        case 28: _a0 = SkBlendMode::kLuminosity; break;
        case 29: _a0 = SkBlendMode::kLastCoeffMode; break;
        case 30: _a0 = SkBlendMode::kLastSeparableMode; break;
        case 31: _a0 = SkBlendMode::kLastMode; break;
    }
    sk_sp<SkShader> *_o0;
    sk_sp<SkShader> *_o1;
    sk_sp<SkShader> *_o2;
	_o0 = MAKE(sk_sp<SkShader>);
	sk_sp<SkShader> ref = SkShaders::Blend(_a0, *_i0, *_i1);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkShader>::sk_sp<SkShader> SkPerlinNoiseShader::MakeTurbulence(SkScalar None, SkScalar None, int None, SkScalar None, SkISize * None);) */
extern "C" void shim_165(void **in_ref, void **out_ref, const char *context) {
    SkISize *_i0 = reinterpret_cast<SkISize *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    int _a2;
    memcpy(&_a2, context + 8, sizeof(int));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    sk_sp<SkShader> *_o0;
    SkISize *_o1;
	_o0 = MAKE(sk_sp<SkShader>);
	sk_sp<SkShader> ref = SkPerlinNoiseShader::MakeTurbulence(_a0, _a1, _a2, _a3, _i0);
	*_o0 = ref;
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sk_sp<SkShader>::sk_sp<SkShader> SkPerlinNoiseShader::MakeFractalNoise(SkScalar None, SkScalar None, int None, SkScalar None, SkISize * None);) */
extern "C" void shim_166(void **in_ref, void **out_ref, const char *context) {
    SkISize *_i0 = reinterpret_cast<SkISize *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    int _a2;
    memcpy(&_a2, context + 8, sizeof(int));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    sk_sp<SkShader> *_o0;
    SkISize *_o1;
	_o0 = MAKE(sk_sp<SkShader>);
	sk_sp<SkShader> ref = SkPerlinNoiseShader::MakeFractalNoise(_a0, _a1, _a2, _a3, _i0);
	*_o0 = ref;
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sk_sp<SkShader>::~sk_sp<SkShader>();) */
extern "C" void shim_167(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkShader> *_i0 = reinterpret_cast<sk_sp<SkShader> *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=nullptr) */
extern "C" void shim_168(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkPathEffect> *_o0;
	_o0 = MAKE(sk_sp<SkPathEffect>);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=SkDashPathEffect::Make) */
extern "C" void shim_169(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2[20];
    memcpy(&_a2, context + 8, 4 * 20);
    sk_sp<SkPathEffect> *_o0;
	_o0 = MAKE(sk_sp<SkPathEffect>);
	int count = _a0;
	if (count < 0) count = 0;
	if (count > 20) count = 20;
	*_o0 = SkDashPathEffect::Make(_a2, count, _a1);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sk_sp<SkPathEffect>::sk_sp<SkPathEffect> SkPathEffect::MakeSum(sk_sp<SkPathEffect> None, sk_sp<SkPathEffect> None);) */
extern "C" void shim_170(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkPathEffect> *_i0 = reinterpret_cast<sk_sp<SkPathEffect> *>(in_ref[0]);
    sk_sp<SkPathEffect> *_i1 = reinterpret_cast<sk_sp<SkPathEffect> *>(in_ref[1]);
    sk_sp<SkPathEffect> *_o0;
    sk_sp<SkPathEffect> *_o1;
    sk_sp<SkPathEffect> *_o2;
	_o0 = MAKE(sk_sp<SkPathEffect>);
	sk_sp<SkPathEffect> ref = SkPathEffect::MakeSum(*_i0, *_i1);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkPathEffect>::sk_sp<SkPathEffect> SkPathEffect::MakeCompose(sk_sp<SkPathEffect> None, sk_sp<SkPathEffect> None);) */
extern "C" void shim_171(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkPathEffect> *_i0 = reinterpret_cast<sk_sp<SkPathEffect> *>(in_ref[0]);
    sk_sp<SkPathEffect> *_i1 = reinterpret_cast<sk_sp<SkPathEffect> *>(in_ref[1]);
    sk_sp<SkPathEffect> *_o0;
    sk_sp<SkPathEffect> *_o1;
    sk_sp<SkPathEffect> *_o2;
	_o0 = MAKE(sk_sp<SkPathEffect>);
	sk_sp<SkPathEffect> ref = SkPathEffect::MakeCompose(*_i0, *_i1);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkPathEffect>::sk_sp<SkPathEffect> SkPath1DPathEffect::Make(SkPath None, SkScalar None, SkScalar None, SkPath1DPathEffect::Style None);) */
extern "C" void shim_172(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkPath1DPathEffect::Style _a2;
    switch (*(reinterpret_cast<const unsigned char *>(context + 8)) % 3) {
        case 0: _a2 = SkPath1DPathEffect::Style::kTranslate_Style; break;
        case 1: _a2 = SkPath1DPathEffect::Style::kRotate_Style; break;
        case 2: _a2 = SkPath1DPathEffect::Style::kMorph_Style; break;
    }
    sk_sp<SkPathEffect> *_o0;
    SkPath *_o1;
	_o0 = MAKE(sk_sp<SkPathEffect>);
	sk_sp<SkPathEffect> ref = SkPath1DPathEffect::Make(*_i0, _a0, _a1, _a2);
	*_o0 = ref;
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sk_sp<SkPathEffect>::sk_sp<SkPathEffect> SkLine2DPathEffect::Make(SkScalar None, SkMatrix None);) */
extern "C" void shim_173(void **in_ref, void **out_ref, const char *context) {
    SkMatrix *_i0 = reinterpret_cast<SkMatrix *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    sk_sp<SkPathEffect> *_o0;
    SkMatrix *_o1;
	_o0 = MAKE(sk_sp<SkPathEffect>);
	sk_sp<SkPathEffect> ref = SkLine2DPathEffect::Make(_a0, *_i0);
	*_o0 = ref;
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sk_sp<SkPathEffect>::sk_sp<SkPathEffect> SkPath2DPathEffect::Make(SkMatrix None, SkPath None);) */
extern "C" void shim_174(void **in_ref, void **out_ref, const char *context) {
    SkMatrix *_i0 = reinterpret_cast<SkMatrix *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    sk_sp<SkPathEffect> *_o0;
    SkMatrix *_o1;
    SkPath *_o2;
	_o0 = MAKE(sk_sp<SkPathEffect>);
	sk_sp<SkPathEffect> ref = SkPath2DPathEffect::Make(*_i0, *_i1);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkPathEffect>::sk_sp<SkPathEffect> SkCornerPathEffect::Make(SkScalar None);) */
extern "C" void shim_175(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    sk_sp<SkPathEffect> *_o0;
	_o0 = MAKE(sk_sp<SkPathEffect>);
	sk_sp<SkPathEffect> ref = SkCornerPathEffect::Make(_a0);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sk_sp<SkPathEffect>::sk_sp<SkPathEffect> SkDiscretePathEffect::Make(SkScalar None, SkScalar None, uint32_t None);) */
extern "C" void shim_176(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    uint32_t _a2;
    memcpy(&_a2, context + 8, sizeof(uint32_t));
    sk_sp<SkPathEffect> *_o0;
	_o0 = MAKE(sk_sp<SkPathEffect>);
	sk_sp<SkPathEffect> ref = SkDiscretePathEffect::Make(_a0, _a1, _a2);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sk_sp<SkPathEffect>::~sk_sp<SkPathEffect>();) */
extern "C" void shim_177(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkPathEffect> *_i0 = reinterpret_cast<sk_sp<SkPathEffect> *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=nullptr) */
extern "C" void shim_178(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkMaskFilter> *_o0;
	_o0 = MAKE(sk_sp<SkMaskFilter>);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sk_sp<SkMaskFilter>::sk_sp<SkMaskFilter> SkMaskFilter::MakeBlur(SkBlurStyle None, SkScalar None, bool None);) */
extern "C" void shim_179(void **in_ref, void **out_ref, const char *context) {
    SkBlurStyle _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = SkBlurStyle::kNormal_SkBlurStyle; break;
        case 1: _a0 = SkBlurStyle::kSolid_SkBlurStyle; break;
        case 2: _a0 = SkBlurStyle::kOuter_SkBlurStyle; break;
        case 3: _a0 = SkBlurStyle::kInner_SkBlurStyle; break;
        case 4: _a0 = SkBlurStyle::kLastEnum_SkBlurStyle; break;
    }
    float _a1;
    memcpy(&_a1, context + 1, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 5)) & 1;
    sk_sp<SkMaskFilter> *_o0;
	_o0 = MAKE(sk_sp<SkMaskFilter>);
	sk_sp<SkMaskFilter> ref = SkMaskFilter::MakeBlur(_a0, _a1, _a2);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sk_sp<SkMaskFilter>::~sk_sp<SkMaskFilter>();) */
extern "C" void shim_180(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkMaskFilter> *_i0 = reinterpret_cast<sk_sp<SkMaskFilter> *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=nullptr) */
extern "C" void shim_181(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkTypeface> *_o0;
	_o0 = MAKE(sk_sp<SkTypeface>);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=fetch_font_style) */
extern "C" void shim_182(void **in_ref, void **out_ref, const char *context) {
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    uint32_t _a1;
    memcpy(&_a1, context + 4, sizeof(uint32_t));
    sk_sp<SkTypeface> *_o0;
	_o0 = MAKE(sk_sp<SkTypeface>);
	auto fontMugger = SkFontMgr::RefDefault();
	int familyCount = fontMugger->countFamilies();
	sk_sp<SkFontStyleSet> family(fontMugger->createStyleSet(_a0 % familyCount));
	int styleCount = family->count();
	*_o0 = sk_sp<SkTypeface>(family->createTypeface(_a1 % styleCount));
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sk_sp<SkTypeface>::~sk_sp<SkTypeface>();) */
extern "C" void shim_183(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkTypeface> *_i0 = reinterpret_cast<sk_sp<SkTypeface> *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=nullptr) */
extern "C" void shim_184(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_o0;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=SkImageFilters::MatrixTransform) */
extern "C" void shim_185(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    SkMatrix *_i1 = reinterpret_cast<SkMatrix *>(in_ref[1]);
    SkFilterQuality _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = SkFilterQuality::kNone_SkFilterQuality; break;
        case 1: _a0 = SkFilterQuality::kLow_SkFilterQuality; break;
        case 2: _a0 = SkFilterQuality::kMedium_SkFilterQuality; break;
        case 3: _a0 = SkFilterQuality::kHigh_SkFilterQuality; break;
        case 4: _a0 = SkFilterQuality::kLast_SkFilterQuality; break;
    }
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    SkMatrix *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	*_o0 = SkImageFilters::MatrixTransform(*_i1, SkSamplingOptions(_a0), *_i0);
	_o1 = _i0;
	_o2 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=SkImageFilters::Image) */
extern "C" void shim_186(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImage> *_i0 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkRect *_i2 = reinterpret_cast<SkRect *>(in_ref[2]);
    SkFilterQuality _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = SkFilterQuality::kNone_SkFilterQuality; break;
        case 1: _a0 = SkFilterQuality::kLow_SkFilterQuality; break;
        case 2: _a0 = SkFilterQuality::kMedium_SkFilterQuality; break;
        case 3: _a0 = SkFilterQuality::kHigh_SkFilterQuality; break;
        case 4: _a0 = SkFilterQuality::kLast_SkFilterQuality; break;
    }
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImage> *_o1;
    SkRect *_o2;
    SkRect *_o3;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	*_o0 = SkImageFilters::Image(*_i0, *_i1, *_i2, SkSamplingOptions(_a0));
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=SkImageFilters::MatrixConvolution) */
extern "C" void shim_187(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    SkIRect *_i1 = reinterpret_cast<SkIRect *>(in_ref[1]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    uint8_t _a1;
    memcpy(&_a1, context + 1, sizeof(uint8_t));
    float _a2[25];
    memcpy(&_a2, context + 2, 4 * 25);
    float _a3;
    memcpy(&_a3, context + 102, sizeof(float));
    float _a4;
    memcpy(&_a4, context + 106, sizeof(float));
    uint8_t _a5;
    memcpy(&_a5, context + 110, sizeof(uint8_t));
    uint8_t _a6;
    memcpy(&_a6, context + 111, sizeof(uint8_t));
    SkTileMode _a7;
    switch (*(reinterpret_cast<const unsigned char *>(context + 112)) % 5) {
        case 0: _a7 = SkTileMode::kClamp; break;
        case 1: _a7 = SkTileMode::kRepeat; break;
        case 2: _a7 = SkTileMode::kMirror; break;
        case 3: _a7 = SkTileMode::kDecal; break;
        case 4: _a7 = SkTileMode::kLastTileMode; break;
    }
    bool _a8 = *(static_cast<const char *>(context + 113)) & 1;
    bool _a9 = *(static_cast<const char *>(context + 114)) & 1;
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    SkIRect *_o2;
	int32_t n = (_a0 % (5-1)) + 1;
	int32_t m = (_a1 % (5-1)) + 1;
	int32_t offsetX = (_a5 % n);
	int32_t offsetY = (_a6 % n);
	_o0 = MAKE(sk_sp<SkImageFilter>);
	*_o0 = SkImageFilters::MatrixConvolution(
	  SkISize{n, m}, _a2, _a3, _a4, SkIPoint{offsetX, offsetY},
	  _a7, _a8, *_i0, _a9 ? _i1 : nullptr
	);
	_o1 = _i0;
	_o2 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=merge_1) */
extern "C" void shim_188(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    SkIRect *_i1 = reinterpret_cast<SkIRect *>(in_ref[1]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    SkIRect *_o2;
	sk_sp<SkImageFilter> ifs[] = {*_i0};
	_o0 = MAKE(sk_sp<SkImageFilter>);
	*_o0 = SkImageFilters::Merge(ifs, 1, _a0 ? _i1 : nullptr);
	_o1 = _i0;
	_o2 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=merge_2) */
extern "C" void shim_189(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    SkIRect *_i2 = reinterpret_cast<SkIRect *>(in_ref[2]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    sk_sp<SkImageFilter> *_o2;
    SkIRect *_o3;
	sk_sp<SkImageFilter> ifs[] = {*_i0, *_i1};
	_o0 = MAKE(sk_sp<SkImageFilter>);
	*_o0 = SkImageFilters::Merge(ifs, 2, _a0 ? _i2 : nullptr);
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=merge_3) */
extern "C" void shim_190(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    sk_sp<SkImageFilter> *_i2 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[2]);
    SkIRect *_i3 = reinterpret_cast<SkIRect *>(in_ref[3]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    sk_sp<SkImageFilter> *_o2;
    sk_sp<SkImageFilter> *_o3;
    SkIRect *_o4;
	sk_sp<SkImageFilter> ifs[] = {*_i0, *_i1, *_i2};
	_o0 = MAKE(sk_sp<SkImageFilter>);
	*_o0 = SkImageFilters::Merge(ifs, 3, _a0 ? _i3 : nullptr);
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	_o4 = _i3;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);
}


/* CPPScope(name=merge_4) */
extern "C" void shim_191(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    sk_sp<SkImageFilter> *_i2 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[2]);
    sk_sp<SkImageFilter> *_i3 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[3]);
    SkIRect *_i4 = reinterpret_cast<SkIRect *>(in_ref[4]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    sk_sp<SkImageFilter> *_o2;
    sk_sp<SkImageFilter> *_o3;
    sk_sp<SkImageFilter> *_o4;
    SkIRect *_o5;
	sk_sp<SkImageFilter> ifs[] = {*_i0, *_i1, *_i2, *_i3};
	_o0 = MAKE(sk_sp<SkImageFilter>);
	*_o0 = SkImageFilters::Merge(ifs, 4, _a0 ? _i4 : nullptr);
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	_o4 = _i3;
	_o5 = _i4;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);
    out_ref[5] = reinterpret_cast<void *>(_o5);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DistantLitDiffuse(SkPoint3 p, SkColor lightColor, SkScalar surfaceScale, SkScalar k, sk_sp<SkImageFilter> input, SkIRect * cropRect);) */
extern "C" void shim_192(void **in_ref, void **out_ref, const char *context) {
    SkPoint3 *_i0 = reinterpret_cast<SkPoint3 *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    SkIRect *_i2 = reinterpret_cast<SkIRect *>(in_ref[2]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    SkPoint3 *_o1;
    sk_sp<SkImageFilter> *_o2;
    SkIRect *_o3;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::DistantLitDiffuse(*_i0, _a0, _a1, _a2, *_i1, _i2);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DistantLitDiffuse(SkPoint3 p, SkColor lightColor, SkScalar surfaceScale, SkScalar k, sk_sp<SkImageFilter> input, {nullptr});) */
extern "C" void shim_193(void **in_ref, void **out_ref, const char *context) {
    SkPoint3 *_i0 = reinterpret_cast<SkPoint3 *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    SkPoint3 *_o1;
    sk_sp<SkImageFilter> *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::DistantLitDiffuse(*_i0, _a0, _a1, _a2, *_i1, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::PointLitDiffuse(SkPoint3 p, SkColor lightColor, SkScalar surfaceScale, SkScalar k, sk_sp<SkImageFilter> input, SkIRect * cropRect);) */
extern "C" void shim_194(void **in_ref, void **out_ref, const char *context) {
    SkPoint3 *_i0 = reinterpret_cast<SkPoint3 *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    SkIRect *_i2 = reinterpret_cast<SkIRect *>(in_ref[2]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    SkPoint3 *_o1;
    sk_sp<SkImageFilter> *_o2;
    SkIRect *_o3;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::PointLitDiffuse(*_i0, _a0, _a1, _a2, *_i1, _i2);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::PointLitDiffuse(SkPoint3 p, SkColor lightColor, SkScalar surfaceScale, SkScalar k, sk_sp<SkImageFilter> input, {nullptr});) */
extern "C" void shim_195(void **in_ref, void **out_ref, const char *context) {
    SkPoint3 *_i0 = reinterpret_cast<SkPoint3 *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    SkPoint3 *_o1;
    sk_sp<SkImageFilter> *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::PointLitDiffuse(*_i0, _a0, _a1, _a2, *_i1, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::SpotLitDiffuse(SkPoint3 p, SkPoint3 q, SkScalar specularExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar k, sk_sp<SkImageFilter> input, SkIRect * cropRect);) */
extern "C" void shim_196(void **in_ref, void **out_ref, const char *context) {
    SkPoint3 *_i0 = reinterpret_cast<SkPoint3 *>(in_ref[0]);
    SkPoint3 *_i1 = reinterpret_cast<SkPoint3 *>(in_ref[1]);
    sk_sp<SkImageFilter> *_i2 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[2]);
    SkIRect *_i3 = reinterpret_cast<SkIRect *>(in_ref[3]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    uint32_t _a2;
    memcpy(&_a2, context + 8, sizeof(uint32_t));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    float _a4;
    memcpy(&_a4, context + 16, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    SkPoint3 *_o1;
    SkPoint3 *_o2;
    sk_sp<SkImageFilter> *_o3;
    SkIRect *_o4;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::SpotLitDiffuse(*_i0, *_i1, _a0, _a1, _a2, _a3, _a4, *_i2, _i3);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	_o4 = _i3;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::SpotLitDiffuse(SkPoint3 p, SkPoint3 q, SkScalar specularExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar k, sk_sp<SkImageFilter> input, {nullptr});) */
extern "C" void shim_197(void **in_ref, void **out_ref, const char *context) {
    SkPoint3 *_i0 = reinterpret_cast<SkPoint3 *>(in_ref[0]);
    SkPoint3 *_i1 = reinterpret_cast<SkPoint3 *>(in_ref[1]);
    sk_sp<SkImageFilter> *_i2 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    uint32_t _a2;
    memcpy(&_a2, context + 8, sizeof(uint32_t));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    float _a4;
    memcpy(&_a4, context + 16, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    SkPoint3 *_o1;
    SkPoint3 *_o2;
    sk_sp<SkImageFilter> *_o3;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::SpotLitDiffuse(*_i0, *_i1, _a0, _a1, _a2, _a3, _a4, *_i2, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DistantLitSpecular(SkPoint3 p, SkColor lightColor, SkScalar surfaceScale, SkScalar k, SkScalar shininess, sk_sp<SkImageFilter> input, SkIRect * cropRect);) */
extern "C" void shim_198(void **in_ref, void **out_ref, const char *context) {
    SkPoint3 *_i0 = reinterpret_cast<SkPoint3 *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    SkIRect *_i2 = reinterpret_cast<SkIRect *>(in_ref[2]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    SkPoint3 *_o1;
    sk_sp<SkImageFilter> *_o2;
    SkIRect *_o3;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::DistantLitSpecular(*_i0, _a0, _a1, _a2, _a3, *_i1, _i2);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DistantLitSpecular(SkPoint3 p, SkColor lightColor, SkScalar surfaceScale, SkScalar k, SkScalar shininess, sk_sp<SkImageFilter> input, {nullptr});) */
extern "C" void shim_199(void **in_ref, void **out_ref, const char *context) {
    SkPoint3 *_i0 = reinterpret_cast<SkPoint3 *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    SkPoint3 *_o1;
    sk_sp<SkImageFilter> *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::DistantLitSpecular(*_i0, _a0, _a1, _a2, _a3, *_i1, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::PointLitSpecular(SkPoint3 p, SkColor lightColor, SkScalar surfaceScale, SkScalar k, SkScalar shininess, sk_sp<SkImageFilter> input, SkIRect * cropRect);) */
extern "C" void shim_200(void **in_ref, void **out_ref, const char *context) {
    SkPoint3 *_i0 = reinterpret_cast<SkPoint3 *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    SkIRect *_i2 = reinterpret_cast<SkIRect *>(in_ref[2]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    SkPoint3 *_o1;
    sk_sp<SkImageFilter> *_o2;
    SkIRect *_o3;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::PointLitSpecular(*_i0, _a0, _a1, _a2, _a3, *_i1, _i2);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::PointLitSpecular(SkPoint3 p, SkColor lightColor, SkScalar surfaceScale, SkScalar k, SkScalar shininess, sk_sp<SkImageFilter> input, {nullptr});) */
extern "C" void shim_201(void **in_ref, void **out_ref, const char *context) {
    SkPoint3 *_i0 = reinterpret_cast<SkPoint3 *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    SkPoint3 *_o1;
    sk_sp<SkImageFilter> *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::PointLitSpecular(*_i0, _a0, _a1, _a2, _a3, *_i1, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::SpotLitSpecular(SkPoint3 p, SkPoint3 q, SkScalar specularExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar k, SkScalar shininess, sk_sp<SkImageFilter> input, SkIRect * cropRect);) */
extern "C" void shim_202(void **in_ref, void **out_ref, const char *context) {
    SkPoint3 *_i0 = reinterpret_cast<SkPoint3 *>(in_ref[0]);
    SkPoint3 *_i1 = reinterpret_cast<SkPoint3 *>(in_ref[1]);
    sk_sp<SkImageFilter> *_i2 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[2]);
    SkIRect *_i3 = reinterpret_cast<SkIRect *>(in_ref[3]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    uint32_t _a2;
    memcpy(&_a2, context + 8, sizeof(uint32_t));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    float _a4;
    memcpy(&_a4, context + 16, sizeof(float));
    float _a5;
    memcpy(&_a5, context + 20, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    SkPoint3 *_o1;
    SkPoint3 *_o2;
    sk_sp<SkImageFilter> *_o3;
    SkIRect *_o4;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::SpotLitSpecular(*_i0, *_i1, _a0, _a1, _a2, _a3, _a4, _a5, *_i2, _i3);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	_o4 = _i3;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::SpotLitSpecular(SkPoint3 p, SkPoint3 q, SkScalar specularExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar k, SkScalar shininess, sk_sp<SkImageFilter> input, {nullptr});) */
extern "C" void shim_203(void **in_ref, void **out_ref, const char *context) {
    SkPoint3 *_i0 = reinterpret_cast<SkPoint3 *>(in_ref[0]);
    SkPoint3 *_i1 = reinterpret_cast<SkPoint3 *>(in_ref[1]);
    sk_sp<SkImageFilter> *_i2 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    uint32_t _a2;
    memcpy(&_a2, context + 8, sizeof(uint32_t));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    float _a4;
    memcpy(&_a4, context + 16, sizeof(float));
    float _a5;
    memcpy(&_a5, context + 20, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    SkPoint3 *_o1;
    SkPoint3 *_o2;
    sk_sp<SkImageFilter> *_o3;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::SpotLitSpecular(*_i0, *_i1, _a0, _a1, _a2, _a3, _a4, _a5, *_i2, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Blur(SkScalar None, SkScalar None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_204(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    SkIRect *_i1 = reinterpret_cast<SkIRect *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    SkIRect *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Blur(_a0, _a1, *_i0, _i1);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Blur(SkScalar None, SkScalar None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_205(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Blur(_a0, _a1, *_i0, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::AlphaThreshold(SkRegion None, SkScalar None, SkScalar None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_206(void **in_ref, void **out_ref, const char *context) {
    SkRegion *_i0 = reinterpret_cast<SkRegion *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    SkIRect *_i2 = reinterpret_cast<SkIRect *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    SkRegion *_o1;
    sk_sp<SkImageFilter> *_o2;
    SkIRect *_o3;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::AlphaThreshold(*_i0, _a0, _a1, *_i1, _i2);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::AlphaThreshold(SkRegion None, SkScalar None, SkScalar None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_207(void **in_ref, void **out_ref, const char *context) {
    SkRegion *_i0 = reinterpret_cast<SkRegion *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    SkRegion *_o1;
    sk_sp<SkImageFilter> *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::AlphaThreshold(*_i0, _a0, _a1, *_i1, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Arithmetic(float None, float None, float None, float None, bool None, sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_208(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    SkIRect *_i2 = reinterpret_cast<SkIRect *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    bool _a4 = *(static_cast<const char *>(context + 16)) & 1;
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    sk_sp<SkImageFilter> *_o2;
    SkIRect *_o3;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Arithmetic(_a0, _a1, _a2, _a3, _a4, *_i0, *_i1, _i2);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Arithmetic(float None, float None, float None, float None, bool None, sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_209(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    bool _a4 = *(static_cast<const char *>(context + 16)) & 1;
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    sk_sp<SkImageFilter> *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Arithmetic(_a0, _a1, _a2, _a3, _a4, *_i0, *_i1, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::ColorFilter(sk_sp<SkColorFilter> None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_210(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkColorFilter> *_i0 = reinterpret_cast<sk_sp<SkColorFilter> *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    SkIRect *_i2 = reinterpret_cast<SkIRect *>(in_ref[2]);
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkColorFilter> *_o1;
    sk_sp<SkImageFilter> *_o2;
    SkIRect *_o3;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::ColorFilter(*_i0, *_i1, _i2);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::ColorFilter(sk_sp<SkColorFilter> None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_211(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkColorFilter> *_i0 = reinterpret_cast<sk_sp<SkColorFilter> *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkColorFilter> *_o1;
    sk_sp<SkImageFilter> *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::ColorFilter(*_i0, *_i1, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Compose(sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None);) */
extern "C" void shim_212(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    sk_sp<SkImageFilter> *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Compose(*_i0, *_i1);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DisplacementMap(SkColorChannel None, SkColorChannel None, SkScalar None, sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_213(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    SkIRect *_i2 = reinterpret_cast<SkIRect *>(in_ref[2]);
    SkColorChannel _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = SkColorChannel::kR; break;
        case 1: _a0 = SkColorChannel::kG; break;
        case 2: _a0 = SkColorChannel::kB; break;
        case 3: _a0 = SkColorChannel::kA; break;
        case 4: _a0 = SkColorChannel::kLastEnum; break;
    }
    SkColorChannel _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 1)) % 5) {
        case 0: _a1 = SkColorChannel::kR; break;
        case 1: _a1 = SkColorChannel::kG; break;
        case 2: _a1 = SkColorChannel::kB; break;
        case 3: _a1 = SkColorChannel::kA; break;
        case 4: _a1 = SkColorChannel::kLastEnum; break;
    }
    float _a2;
    memcpy(&_a2, context + 2, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    sk_sp<SkImageFilter> *_o2;
    SkIRect *_o3;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::DisplacementMap(_a0, _a1, _a2, *_i0, *_i1, _i2);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DisplacementMap(SkColorChannel None, SkColorChannel None, SkScalar None, sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_214(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    SkColorChannel _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = SkColorChannel::kR; break;
        case 1: _a0 = SkColorChannel::kG; break;
        case 2: _a0 = SkColorChannel::kB; break;
        case 3: _a0 = SkColorChannel::kA; break;
        case 4: _a0 = SkColorChannel::kLastEnum; break;
    }
    SkColorChannel _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 1)) % 5) {
        case 0: _a1 = SkColorChannel::kR; break;
        case 1: _a1 = SkColorChannel::kG; break;
        case 2: _a1 = SkColorChannel::kB; break;
        case 3: _a1 = SkColorChannel::kA; break;
        case 4: _a1 = SkColorChannel::kLastEnum; break;
    }
    float _a2;
    memcpy(&_a2, context + 2, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    sk_sp<SkImageFilter> *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::DisplacementMap(_a0, _a1, _a2, *_i0, *_i1, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DropShadowOnly(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkColor None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_215(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    SkIRect *_i1 = reinterpret_cast<SkIRect *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    uint32_t _a4;
    memcpy(&_a4, context + 16, sizeof(uint32_t));
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    SkIRect *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::DropShadowOnly(_a0, _a1, _a2, _a3, _a4, *_i0, _i1);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DropShadowOnly(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkColor None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_216(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    uint32_t _a4;
    memcpy(&_a4, context + 16, sizeof(uint32_t));
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::DropShadowOnly(_a0, _a1, _a2, _a3, _a4, *_i0, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DropShadow(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkColor None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_217(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    SkIRect *_i1 = reinterpret_cast<SkIRect *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    uint32_t _a4;
    memcpy(&_a4, context + 16, sizeof(uint32_t));
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    SkIRect *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::DropShadow(_a0, _a1, _a2, _a3, _a4, *_i0, _i1);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DropShadow(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkColor None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_218(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    uint32_t _a4;
    memcpy(&_a4, context + 16, sizeof(uint32_t));
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::DropShadow(_a0, _a1, _a2, _a3, _a4, *_i0, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Image(sk_sp<SkImage> None);) */
extern "C" void shim_219(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImage> *_i0 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[0]);
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImage> *_o1;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Image(*_i0);
	*_o0 = ref;
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Magnifier(SkRect None, SkScalar None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_220(void **in_ref, void **out_ref, const char *context) {
    SkRect *_i0 = reinterpret_cast<SkRect *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    SkIRect *_i2 = reinterpret_cast<SkIRect *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    SkRect *_o1;
    sk_sp<SkImageFilter> *_o2;
    SkIRect *_o3;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Magnifier(*_i0, _a0, *_i1, _i2);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Magnifier(SkRect None, SkScalar None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_221(void **in_ref, void **out_ref, const char *context) {
    SkRect *_i0 = reinterpret_cast<SkRect *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    SkRect *_o1;
    sk_sp<SkImageFilter> *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Magnifier(*_i0, _a0, *_i1, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Merge(sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_222(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    SkIRect *_i2 = reinterpret_cast<SkIRect *>(in_ref[2]);
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    sk_sp<SkImageFilter> *_o2;
    SkIRect *_o3;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Merge(*_i0, *_i1, _i2);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Merge(sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_223(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    sk_sp<SkImageFilter> *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Merge(*_i0, *_i1, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Dilate(int None, int None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_224(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    SkIRect *_i1 = reinterpret_cast<SkIRect *>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    SkIRect *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Dilate(_a0, _a1, *_i0, _i1);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Dilate(int None, int None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_225(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Dilate(_a0, _a1, *_i0, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Erode(int None, int None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_226(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    SkIRect *_i1 = reinterpret_cast<SkIRect *>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    SkIRect *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Erode(_a0, _a1, *_i0, _i1);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Erode(int None, int None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_227(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Erode(_a0, _a1, *_i0, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Offset(SkScalar None, SkScalar None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_228(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    SkIRect *_i1 = reinterpret_cast<SkIRect *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    SkIRect *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Offset(_a0, _a1, *_i0, _i1);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Offset(SkScalar None, SkScalar None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_229(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Offset(_a0, _a1, *_i0, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Paint(SkPaint None, SkIRect * None);) */
extern "C" void shim_230(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    SkIRect *_i1 = reinterpret_cast<SkIRect *>(in_ref[1]);
    sk_sp<SkImageFilter> *_o0;
    SkPaint *_o1;
    SkIRect *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Paint(*_i0, _i1);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Paint(SkPaint None, {nullptr});) */
extern "C" void shim_231(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    sk_sp<SkImageFilter> *_o0;
    SkPaint *_o1;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Paint(*_i0, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Picture(sk_sp<SkPicture> None);) */
extern "C" void shim_232(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkPicture> *_i0 = reinterpret_cast<sk_sp<SkPicture> *>(in_ref[0]);
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkPicture> *_o1;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Picture(*_i0);
	*_o0 = ref;
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Picture(sk_sp<SkPicture> None, SkRect None);) */
extern "C" void shim_233(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkPicture> *_i0 = reinterpret_cast<sk_sp<SkPicture> *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkPicture> *_o1;
    SkRect *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Picture(*_i0, *_i1);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Tile(SkRect None, SkRect None, sk_sp<SkImageFilter> None);) */
extern "C" void shim_234(void **in_ref, void **out_ref, const char *context) {
    SkRect *_i0 = reinterpret_cast<SkRect *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    sk_sp<SkImageFilter> *_i2 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[2]);
    sk_sp<SkImageFilter> *_o0;
    SkRect *_o1;
    SkRect *_o2;
    sk_sp<SkImageFilter> *_o3;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Tile(*_i0, *_i1, *_i2);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Blend(SkBlendMode None, sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_235(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    SkIRect *_i2 = reinterpret_cast<SkIRect *>(in_ref[2]);
    SkBlendMode _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 32) {
        case 0: _a0 = SkBlendMode::kClear; break;
        case 1: _a0 = SkBlendMode::kSrc; break;
        case 2: _a0 = SkBlendMode::kDst; break;
        case 3: _a0 = SkBlendMode::kSrcOver; break;
        case 4: _a0 = SkBlendMode::kDstOver; break;
        case 5: _a0 = SkBlendMode::kSrcIn; break;
        case 6: _a0 = SkBlendMode::kDstIn; break;
        case 7: _a0 = SkBlendMode::kSrcOut; break;
        case 8: _a0 = SkBlendMode::kDstOut; break;
        case 9: _a0 = SkBlendMode::kSrcATop; break;
        case 10: _a0 = SkBlendMode::kDstATop; break;
        case 11: _a0 = SkBlendMode::kXor; break;
        case 12: _a0 = SkBlendMode::kPlus; break;
        case 13: _a0 = SkBlendMode::kModulate; break;
        case 14: _a0 = SkBlendMode::kScreen; break;
        case 15: _a0 = SkBlendMode::kOverlay; break;
        case 16: _a0 = SkBlendMode::kDarken; break;
        case 17: _a0 = SkBlendMode::kLighten; break;
        case 18: _a0 = SkBlendMode::kColorDodge; break;
        case 19: _a0 = SkBlendMode::kColorBurn; break;
        case 20: _a0 = SkBlendMode::kHardLight; break;
        case 21: _a0 = SkBlendMode::kSoftLight; break;
        case 22: _a0 = SkBlendMode::kDifference; break;
        case 23: _a0 = SkBlendMode::kExclusion; break;
        case 24: _a0 = SkBlendMode::kMultiply; break;
        case 25: _a0 = SkBlendMode::kHue; break;
        case 26: _a0 = SkBlendMode::kSaturation; break;
        case 27: _a0 = SkBlendMode::kColor; break;
        case 28: _a0 = SkBlendMode::kLuminosity; break;
        case 29: _a0 = SkBlendMode::kLastCoeffMode; break;
        case 30: _a0 = SkBlendMode::kLastSeparableMode; break;
        case 31: _a0 = SkBlendMode::kLastMode; break;
    }
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    sk_sp<SkImageFilter> *_o2;
    SkIRect *_o3;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Blend(_a0, *_i0, *_i1, _i2);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	_o3 = _i2;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Blend(SkBlendMode None, sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_236(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
    sk_sp<SkImageFilter> *_i1 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[1]);
    SkBlendMode _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 32) {
        case 0: _a0 = SkBlendMode::kClear; break;
        case 1: _a0 = SkBlendMode::kSrc; break;
        case 2: _a0 = SkBlendMode::kDst; break;
        case 3: _a0 = SkBlendMode::kSrcOver; break;
        case 4: _a0 = SkBlendMode::kDstOver; break;
        case 5: _a0 = SkBlendMode::kSrcIn; break;
        case 6: _a0 = SkBlendMode::kDstIn; break;
        case 7: _a0 = SkBlendMode::kSrcOut; break;
        case 8: _a0 = SkBlendMode::kDstOut; break;
        case 9: _a0 = SkBlendMode::kSrcATop; break;
        case 10: _a0 = SkBlendMode::kDstATop; break;
        case 11: _a0 = SkBlendMode::kXor; break;
        case 12: _a0 = SkBlendMode::kPlus; break;
        case 13: _a0 = SkBlendMode::kModulate; break;
        case 14: _a0 = SkBlendMode::kScreen; break;
        case 15: _a0 = SkBlendMode::kOverlay; break;
        case 16: _a0 = SkBlendMode::kDarken; break;
        case 17: _a0 = SkBlendMode::kLighten; break;
        case 18: _a0 = SkBlendMode::kColorDodge; break;
        case 19: _a0 = SkBlendMode::kColorBurn; break;
        case 20: _a0 = SkBlendMode::kHardLight; break;
        case 21: _a0 = SkBlendMode::kSoftLight; break;
        case 22: _a0 = SkBlendMode::kDifference; break;
        case 23: _a0 = SkBlendMode::kExclusion; break;
        case 24: _a0 = SkBlendMode::kMultiply; break;
        case 25: _a0 = SkBlendMode::kHue; break;
        case 26: _a0 = SkBlendMode::kSaturation; break;
        case 27: _a0 = SkBlendMode::kColor; break;
        case 28: _a0 = SkBlendMode::kLuminosity; break;
        case 29: _a0 = SkBlendMode::kLastCoeffMode; break;
        case 30: _a0 = SkBlendMode::kLastSeparableMode; break;
        case 31: _a0 = SkBlendMode::kLastMode; break;
    }
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkImageFilter> *_o1;
    sk_sp<SkImageFilter> *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Blend(_a0, *_i0, *_i1, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Shader(sk_sp<SkShader> None, SkIRect * None);) */
extern "C" void shim_237(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkShader> *_i0 = reinterpret_cast<sk_sp<SkShader> *>(in_ref[0]);
    SkIRect *_i1 = reinterpret_cast<SkIRect *>(in_ref[1]);
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkShader> *_o1;
    SkIRect *_o2;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Shader(*_i0, _i1);
	*_o0 = ref;
	_o1 = _i0;
	_o2 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Shader(sk_sp<SkShader> None, {nullptr});) */
extern "C" void shim_238(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkShader> *_i0 = reinterpret_cast<sk_sp<SkShader> *>(in_ref[0]);
    sk_sp<SkImageFilter> *_o0;
    sk_sp<SkShader> *_o1;
	_o0 = MAKE(sk_sp<SkImageFilter>);
	sk_sp<SkImageFilter> ref = SkImageFilters::Shader(*_i0, nullptr);
	*_o0 = ref;
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::~sk_sp<SkImageFilter>();) */
extern "C" void shim_239(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImageFilter> *_i0 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) sk_sp<SkTextBlob>::~sk_sp<SkTextBlob>();) */
extern "C" void shim_240(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkTextBlob> *_i0 = reinterpret_cast<sk_sp<SkTextBlob> *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=SkTextBlobBuilder) */
extern "C" void shim_241(void **in_ref, void **out_ref, const char *context) {
    SkTextBlobBuilder *_o0;
	_o0 = new SkTextBlobBuilder();
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=delete) */
extern "C" void shim_242(void **in_ref, void **out_ref, const char *context) {
    SkTextBlobBuilder *_i0 = reinterpret_cast<SkTextBlobBuilder *>(in_ref[0]);
	delete _i0;
	
}


/* CPPScope(name=make) */
extern "C" void shim_243(void **in_ref, void **out_ref, const char *context) {
    SkTextBlobBuilder *_i0 = reinterpret_cast<SkTextBlobBuilder *>(in_ref[0]);
    sk_sp<SkTextBlob> *_o0;
	_o0 = MAKE(sk_sp<SkTextBlob>);
	*_o0 = _i0->make();
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=allocRun) */
extern "C" void shim_244(void **in_ref, void **out_ref, const char *context) {
    SkTextBlobBuilder *_i0 = reinterpret_cast<SkTextBlobBuilder *>(in_ref[0]);
    SkFont *_i1 = reinterpret_cast<SkFont *>(in_ref[1]);
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    SkTextEncoding _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 128)) % 4) {
        case 0: _a1 = SkTextEncoding::kUTF8; break;
        case 1: _a1 = SkTextEncoding::kUTF16; break;
        case 2: _a1 = SkTextEncoding::kUTF32; break;
        case 3: _a1 = SkTextEncoding::kGlyphID; break;
    }
    float _a2;
    memcpy(&_a2, context + 129, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 133, sizeof(float));
    SkTextBlobBuilder *_o0;
    SkFont *_o1;
	Fuzz f(_a0, 128);
	SkTDArray<uint8_t> text = make_fuzz_text(&f, *_i1, _a1);
	int glyphCount = _i1->countText(text.begin(), SkToSizeT(text.count()), _a1);
	const void* textPtr = text.begin();
	size_t textLen =  SkToSizeT(text.count());
	
	const SkTextBlobBuilder::RunBuffer* buffer;
	buffer = &_i0->allocRun(*_i1, glyphCount, _a2, _a3);
	_i1->textToGlyphs(textPtr, textLen, _a1, buffer->glyphs, glyphCount);
	
	_o0 = _i0;
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=allocRunPosH) */
extern "C" void shim_245(void **in_ref, void **out_ref, const char *context) {
    SkTextBlobBuilder *_i0 = reinterpret_cast<SkTextBlobBuilder *>(in_ref[0]);
    SkFont *_i1 = reinterpret_cast<SkFont *>(in_ref[1]);
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    SkTextEncoding _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 128)) % 4) {
        case 0: _a1 = SkTextEncoding::kUTF8; break;
        case 1: _a1 = SkTextEncoding::kUTF16; break;
        case 2: _a1 = SkTextEncoding::kUTF32; break;
        case 3: _a1 = SkTextEncoding::kGlyphID; break;
    }
    float _a2;
    memcpy(&_a2, context + 129, sizeof(float));
    float _a3[32];
    memcpy(&_a3, context + 133, 4 * 32);
    SkTextBlobBuilder *_o0;
    SkFont *_o1;
	Fuzz f(_a0, 128);
	SkTDArray<uint8_t> text = make_fuzz_text(&f, *_i1, _a1);
	int glyphCount = _i1->countText(text.begin(), SkToSizeT(text.count()), _a1);
	const void* textPtr = text.begin();
	size_t textLen =  SkToSizeT(text.count());
	
	const SkTextBlobBuilder::RunBuffer* buffer;
	buffer = &_i0->allocRunPosH(*_i1, glyphCount, _a2);
	_i1->textToGlyphs(textPtr, textLen, _a1, buffer->glyphs, glyphCount);
	
	for (int i = 0; (i < glyphCount) && (i < 32); ++i) {
	  buffer->pos[i] = _a3[i];
	}
	
	_o0 = _i0;
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=allocRunPos) */
extern "C" void shim_246(void **in_ref, void **out_ref, const char *context) {
    SkTextBlobBuilder *_i0 = reinterpret_cast<SkTextBlobBuilder *>(in_ref[0]);
    SkFont *_i1 = reinterpret_cast<SkFont *>(in_ref[1]);
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    SkTextEncoding _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 128)) % 4) {
        case 0: _a1 = SkTextEncoding::kUTF8; break;
        case 1: _a1 = SkTextEncoding::kUTF16; break;
        case 2: _a1 = SkTextEncoding::kUTF32; break;
        case 3: _a1 = SkTextEncoding::kGlyphID; break;
    }
    float _a2[64];
    memcpy(&_a2, context + 129, 4 * 64);
    SkTextBlobBuilder *_o0;
    SkFont *_o1;
	Fuzz f(_a0, 128);
	SkTDArray<uint8_t> text = make_fuzz_text(&f, *_i1, _a1);
	int glyphCount = _i1->countText(text.begin(), SkToSizeT(text.count()), _a1);
	const void* textPtr = text.begin();
	size_t textLen =  SkToSizeT(text.count());
	
	const SkTextBlobBuilder::RunBuffer* buffer;
	buffer = &_i0->allocRunPos(*_i1, glyphCount);
	_i1->textToGlyphs(textPtr, textLen, _a1, buffer->glyphs, glyphCount);
	
	for (int i = 0; (i < (glyphCount * 2)) && (i < 64); ++i) {
	  buffer->pos[i] = _a2[i];
	}
	
	_o0 = _i0;
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_canvas_saveLayer) */
extern "C" void shim_247(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    sk_sp<SkImageFilter> *_i3 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[3]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    bool _a2 = *(static_cast<const char *>(context + 2)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
    SkPaint *_o2;
    sk_sp<SkImageFilter> *_o3;
	SkCanvas::SaveLayerRec saveLayerRec;
	if (_a0) saveLayerRec.fBounds = _i1;
	if (_a1) saveLayerRec.fPaint = _i2;
	if (_a2) saveLayerRec.fBackdrop = _i3->get();
	((SkCanvas *)_i0->active)->saveLayer(saveLayerRec);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=bundled_canvas_drawPoints) */
extern "C" void shim_248(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    float _a0[60];
    memcpy(&_a0, context + 0, 4 * 60);
    int _a1;
    memcpy(&_a1, context + 240, sizeof(int));
    SkCanvas::PointMode _a2;
    switch (*(reinterpret_cast<const unsigned char *>(context + 244)) % 3) {
        case 0: _a2 = SkCanvas::PointMode::kPoints_PointMode; break;
        case 1: _a2 = SkCanvas::PointMode::kLines_PointMode; break;
        case 2: _a2 = SkCanvas::PointMode::kPolygon_PointMode; break;
    }
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPaint *_o1;
	int count = _a1 % 30;
	SkPoint pts[30];
	for (int i = 0; i < count; ++i) {
	  pts[i] = SkPoint::Make(_a0[i*2], _a0[(i*2)+1]);
	}
	((SkCanvas *)_i0->active)->drawPoints(_a2, count, pts, *_i1);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_drawImage) */
extern "C" void shim_249(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkImage> *_o1;
    SkPaint *_o2;
	((SkCanvas *)_i0->active)->drawImage(_i1->get(), _a0, _a1, SkSamplingOptions(), _a2 ? _i2 : nullptr);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_drawImageRect) */
extern "C" void shim_250(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    SkRect *_i2 = reinterpret_cast<SkRect *>(in_ref[2]);
    SkRect *_i3 = reinterpret_cast<SkRect *>(in_ref[3]);
    SkPaint *_i4 = reinterpret_cast<SkPaint *>(in_ref[4]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkImage> *_o1;
    SkRect *_o2;
    SkRect *_o3;
    SkPaint *_o4;
	((SkCanvas *)_i0->active)->drawImageRect(_i1->get(), *_i2, *_i3, SkSamplingOptions(), _a0 ? _i4 : nullptr, _a1 ? SkCanvas::kStrict_SrcRectConstraint : SkCanvas::kFast_SrcRectConstraint);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	_o4 = _i4;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);
}


/* CPPScope(name=bundled_drawImageNine) */
extern "C" void shim_251(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    SkIRect *_i2 = reinterpret_cast<SkIRect *>(in_ref[2]);
    SkRect *_i3 = reinterpret_cast<SkRect *>(in_ref[3]);
    SkPaint *_i4 = reinterpret_cast<SkPaint *>(in_ref[4]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkImage> *_o1;
    SkIRect *_o2;
    SkRect *_o3;
    SkPaint *_o4;
	((SkCanvas *)_i0->active)->drawImageNine(_i1->get(), *_i2, *_i3, SkFilterMode::kNearest, _a0 ? _i4 : nullptr);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	_o4 = _i4;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);
}


/* CPPScope(name=bundled_canvas_drawImageLattice) */
extern "C" void shim_252(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    SkRect *_i2 = reinterpret_cast<SkRect *>(in_ref[2]);
    SkPaint *_i3 = reinterpret_cast<SkPaint *>(in_ref[3]);
    int _a0[6];
    memcpy(&_a0, context + 0, 4 * 6);
    int _a1[6];
    memcpy(&_a1, context + 24, 4 * 6);
    int _a2;
    memcpy(&_a2, context + 48, sizeof(int));
    int _a3;
    memcpy(&_a3, context + 52, sizeof(int));
    bool _a4 = *(static_cast<const char *>(context + 56)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkImage> *_o1;
    SkRect *_o2;
    SkPaint *_o3;
	SkCanvas::Lattice lattice{
	  _a0, 
	  _a1, 
	  nullptr, 
	  (_a2 % (6-2)) + 2,
	  (_a3 % (6-2)) + 2, 
	  nullptr, 
	  nullptr
	};
	((SkCanvas *)_i0->active)->drawImageLattice(_i1->get(), lattice, *_i2, SkFilterMode::kLinear, _a4 ? _i3 : nullptr);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=bundled_canvas_drawSimpleText) */
extern "C" void shim_253(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkFont *_i1 = reinterpret_cast<SkFont *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    float _a1;
    memcpy(&_a1, context + 128, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 132, sizeof(float));
    SkTextEncoding _a3;
    switch (*(reinterpret_cast<const unsigned char *>(context + 136)) % 4) {
        case 0: _a3 = SkTextEncoding::kUTF8; break;
        case 1: _a3 = SkTextEncoding::kUTF16; break;
        case 2: _a3 = SkTextEncoding::kUTF32; break;
        case 3: _a3 = SkTextEncoding::kGlyphID; break;
    }
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkFont *_o1;
    SkPaint *_o2;
	Fuzz f = Fuzz(_a0, 128);
	SkTDArray<uint8_t> text = make_fuzz_text(&f, *_i1, _a3);
	((SkCanvas *)_i0->active)->drawSimpleText(
	  text.begin(), 
	  SkToSizeT(text.count()),
	  _a3,
	  _a1,
	  _a2,
	  *_i1,
	  *_i2
	);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_canvas_drawVertices) */
extern "C" void shim_254(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    SkVertices::VertexMode _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 3) {
        case 0: _a0 = SkVertices::VertexMode::kTriangles_VertexMode; break;
        case 1: _a0 = SkVertices::VertexMode::kTriangleStrip_VertexMode; break;
        case 2: _a0 = SkVertices::VertexMode::kTriangleFan_VertexMode; break;
    }
    SkBlendMode _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 1)) % 32) {
        case 0: _a1 = SkBlendMode::kClear; break;
        case 1: _a1 = SkBlendMode::kSrc; break;
        case 2: _a1 = SkBlendMode::kDst; break;
        case 3: _a1 = SkBlendMode::kSrcOver; break;
        case 4: _a1 = SkBlendMode::kDstOver; break;
        case 5: _a1 = SkBlendMode::kSrcIn; break;
        case 6: _a1 = SkBlendMode::kDstIn; break;
        case 7: _a1 = SkBlendMode::kSrcOut; break;
        case 8: _a1 = SkBlendMode::kDstOut; break;
        case 9: _a1 = SkBlendMode::kSrcATop; break;
        case 10: _a1 = SkBlendMode::kDstATop; break;
        case 11: _a1 = SkBlendMode::kXor; break;
        case 12: _a1 = SkBlendMode::kPlus; break;
        case 13: _a1 = SkBlendMode::kModulate; break;
        case 14: _a1 = SkBlendMode::kScreen; break;
        case 15: _a1 = SkBlendMode::kOverlay; break;
        case 16: _a1 = SkBlendMode::kDarken; break;
        case 17: _a1 = SkBlendMode::kLighten; break;
        case 18: _a1 = SkBlendMode::kColorDodge; break;
        case 19: _a1 = SkBlendMode::kColorBurn; break;
        case 20: _a1 = SkBlendMode::kHardLight; break;
        case 21: _a1 = SkBlendMode::kSoftLight; break;
        case 22: _a1 = SkBlendMode::kDifference; break;
        case 23: _a1 = SkBlendMode::kExclusion; break;
        case 24: _a1 = SkBlendMode::kMultiply; break;
        case 25: _a1 = SkBlendMode::kHue; break;
        case 26: _a1 = SkBlendMode::kSaturation; break;
        case 27: _a1 = SkBlendMode::kColor; break;
        case 28: _a1 = SkBlendMode::kLuminosity; break;
        case 29: _a1 = SkBlendMode::kLastCoeffMode; break;
        case 30: _a1 = SkBlendMode::kLastSeparableMode; break;
        case 31: _a1 = SkBlendMode::kLastMode; break;
    }
    float _a2[200];
    memcpy(&_a2, context + 2, 4 * 200);
    float _a3[200];
    memcpy(&_a3, context + 802, 4 * 200);
    uint32_t _a4[100];
    memcpy(&_a4, context + 1602, 4 * 100);
    int _a5;
    memcpy(&_a5, context + 2002, sizeof(int));
    bool _a6 = *(static_cast<const char *>(context + 2006)) & 1;
    bool _a7 = *(static_cast<const char *>(context + 2007)) & 1;
    bool _a8 = *(static_cast<const char *>(context + 2008)) & 1;
    uint16_t _a9[200];
    memcpy(&_a9, context + 2009, 2 * 200);
    int _a10;
    memcpy(&_a10, context + 2409, sizeof(int));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPaint *_o1;
	int vertexCount = (_a5 % (100 - 3)) + 3;
	
	SkPoint vertices[100];
	SkPoint texs[100];
	
	for (int i = 0; i < vertexCount; ++i) {
	  vertices[i] = SkPoint::Make(_a2[i*2], _a2[(i*2)+1]);
	  texs[i] = SkPoint::Make(_a3[i*2], _a3[(i*2)+1]);
	}
	
	int indexCount = _a8 ? ((_a10 % 100) + vertexCount) : 0;
	
	((SkCanvas *)_i0->active)->drawVertices(SkVertices::MakeCopy(
	    _a0, vertexCount, vertices,
	    _a6 ? texs : nullptr,
	    _a7 ? _a4 : nullptr,
	    indexCount, _a9
	  ), _a1, *_i1
	);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_void drawColor(SkColor4f, SkBlendMode)) */
extern "C" void shim_255(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    SkBlendMode _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 4)) % 32) {
        case 0: _a1 = SkBlendMode::kClear; break;
        case 1: _a1 = SkBlendMode::kSrc; break;
        case 2: _a1 = SkBlendMode::kDst; break;
        case 3: _a1 = SkBlendMode::kSrcOver; break;
        case 4: _a1 = SkBlendMode::kDstOver; break;
        case 5: _a1 = SkBlendMode::kSrcIn; break;
        case 6: _a1 = SkBlendMode::kDstIn; break;
        case 7: _a1 = SkBlendMode::kSrcOut; break;
        case 8: _a1 = SkBlendMode::kDstOut; break;
        case 9: _a1 = SkBlendMode::kSrcATop; break;
        case 10: _a1 = SkBlendMode::kDstATop; break;
        case 11: _a1 = SkBlendMode::kXor; break;
        case 12: _a1 = SkBlendMode::kPlus; break;
        case 13: _a1 = SkBlendMode::kModulate; break;
        case 14: _a1 = SkBlendMode::kScreen; break;
        case 15: _a1 = SkBlendMode::kOverlay; break;
        case 16: _a1 = SkBlendMode::kDarken; break;
        case 17: _a1 = SkBlendMode::kLighten; break;
        case 18: _a1 = SkBlendMode::kColorDodge; break;
        case 19: _a1 = SkBlendMode::kColorBurn; break;
        case 20: _a1 = SkBlendMode::kHardLight; break;
        case 21: _a1 = SkBlendMode::kSoftLight; break;
        case 22: _a1 = SkBlendMode::kDifference; break;
        case 23: _a1 = SkBlendMode::kExclusion; break;
        case 24: _a1 = SkBlendMode::kMultiply; break;
        case 25: _a1 = SkBlendMode::kHue; break;
        case 26: _a1 = SkBlendMode::kSaturation; break;
        case 27: _a1 = SkBlendMode::kColor; break;
        case 28: _a1 = SkBlendMode::kLuminosity; break;
        case 29: _a1 = SkBlendMode::kLastCoeffMode; break;
        case 30: _a1 = SkBlendMode::kLastSeparableMode; break;
        case 31: _a1 = SkBlendMode::kLastMode; break;
    }
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((SkCanvas *)_i0->active)->drawColor(SkColor4f::FromColor(_a0), _a1);
	(_o0->active) = ((SkCanvas *)_i0->active);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_canvas_drawString) */
extern "C" void shim_256(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkFont *_i1 = reinterpret_cast<SkFont *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    float _a1;
    memcpy(&_a1, context + 128, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 132, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkFont *_o1;
    SkPaint *_o2;
	Fuzz f = Fuzz(_a0, 128);
	std::string str = make_fuzz_string(&f);
	((SkCanvas *)_i0->active)->drawString(str.c_str(), _a1, _a2, *_i1, *_i2);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_canvas_drawPatch) */
extern "C" void shim_257(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    float _a0[24];
    memcpy(&_a0, context + 0, 4 * 24);
    uint32_t _a1[4];
    memcpy(&_a1, context + 96, 4 * 4);
    float _a2[8];
    memcpy(&_a2, context + 112, 4 * 8);
    bool _a3 = *(static_cast<const char *>(context + 144)) & 1;
    SkBlendMode _a4;
    switch (*(reinterpret_cast<const unsigned char *>(context + 145)) % 32) {
        case 0: _a4 = SkBlendMode::kClear; break;
        case 1: _a4 = SkBlendMode::kSrc; break;
        case 2: _a4 = SkBlendMode::kDst; break;
        case 3: _a4 = SkBlendMode::kSrcOver; break;
        case 4: _a4 = SkBlendMode::kDstOver; break;
        case 5: _a4 = SkBlendMode::kSrcIn; break;
        case 6: _a4 = SkBlendMode::kDstIn; break;
        case 7: _a4 = SkBlendMode::kSrcOut; break;
        case 8: _a4 = SkBlendMode::kDstOut; break;
        case 9: _a4 = SkBlendMode::kSrcATop; break;
        case 10: _a4 = SkBlendMode::kDstATop; break;
        case 11: _a4 = SkBlendMode::kXor; break;
        case 12: _a4 = SkBlendMode::kPlus; break;
        case 13: _a4 = SkBlendMode::kModulate; break;
        case 14: _a4 = SkBlendMode::kScreen; break;
        case 15: _a4 = SkBlendMode::kOverlay; break;
        case 16: _a4 = SkBlendMode::kDarken; break;
        case 17: _a4 = SkBlendMode::kLighten; break;
        case 18: _a4 = SkBlendMode::kColorDodge; break;
        case 19: _a4 = SkBlendMode::kColorBurn; break;
        case 20: _a4 = SkBlendMode::kHardLight; break;
        case 21: _a4 = SkBlendMode::kSoftLight; break;
        case 22: _a4 = SkBlendMode::kDifference; break;
        case 23: _a4 = SkBlendMode::kExclusion; break;
        case 24: _a4 = SkBlendMode::kMultiply; break;
        case 25: _a4 = SkBlendMode::kHue; break;
        case 26: _a4 = SkBlendMode::kSaturation; break;
        case 27: _a4 = SkBlendMode::kColor; break;
        case 28: _a4 = SkBlendMode::kLuminosity; break;
        case 29: _a4 = SkBlendMode::kLastCoeffMode; break;
        case 30: _a4 = SkBlendMode::kLastSeparableMode; break;
        case 31: _a4 = SkBlendMode::kLastMode; break;
    }
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPaint *_o1;
	SkPoint cubics[12];
	for (int i = 0; i < 12; ++i) cubics[i] = SkPoint::Make(_a0[i*2], _a0[(i*2)+1]);
	SkPoint tex[4];
	for (int i = 0; i < 4; ++i) tex[i] = SkPoint::Make(_a2[i*2], _a2[(i*2)+1]);
	((SkCanvas *)_i0->active)->drawPatch(cubics, _a1, _a3 ? tex : nullptr, _a4, *_i1);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void flush();) */
extern "C" void shim_258(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->flush();)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void save();) */
extern "C" void shim_259(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->save();)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayer(SkRect * None, SkPaint * None);) */
extern "C" void shim_260(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->saveLayer(_i1, _i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayer(SkRect * None, {nullptr});) */
extern "C" void shim_261(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->saveLayer(_i1, nullptr);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayer({nullptr}, SkPaint * None);) */
extern "C" void shim_262(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPaint *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->saveLayer(nullptr, _i1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayer({nullptr}, {nullptr});) */
extern "C" void shim_263(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->saveLayer(nullptr, nullptr);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayerAlpha({nullptr}, uint8_t None);) */
extern "C" void shim_264(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->saveLayerAlpha(nullptr, _a0);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayerAlpha(SkRect * None, uint8_t None);) */
extern "C" void shim_265(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->saveLayerAlpha(_i1, _a0);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void restore();) */
extern "C" void shim_266(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->restore();)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void restoreToCount(int None);) */
extern "C" void shim_267(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->restoreToCount(_a0);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void translate(SkScalar None, SkScalar None);) */
extern "C" void shim_268(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->translate(_a0, _a1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void scale(SkScalar None, SkScalar None);) */
extern "C" void shim_269(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->scale(_a0, _a1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void rotate(SkScalar None);) */
extern "C" void shim_270(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->rotate(_a0);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void rotate(SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_271(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->rotate(_a0, _a1, _a2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void skew(SkScalar None, SkScalar None);) */
extern "C" void shim_272(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->skew(_a0, _a1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void concat(SkMatrix None);) */
extern "C" void shim_273(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkMatrix *_i1 = reinterpret_cast<SkMatrix *>(in_ref[1]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkMatrix *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->concat(*_i1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void setMatrix(SkMatrix None);) */
extern "C" void shim_274(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkMatrix *_i1 = reinterpret_cast<SkMatrix *>(in_ref[1]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkMatrix *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->setMatrix(*_i1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void resetMatrix();) */
extern "C" void shim_275(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->resetMatrix();)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipRect(SkRect None, SkClipOp None, bool None);) */
extern "C" void shim_276(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkClipOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkClipOp::kDifference; break;
        case 1: _a0 = SkClipOp::kIntersect; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->clipRect(*_i1, _a0, _a1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipRRect(SkRRect None, SkClipOp None, bool None);) */
extern "C" void shim_277(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRRect *_i1 = reinterpret_cast<SkRRect *>(in_ref[1]);
    SkClipOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkClipOp::kDifference; break;
        case 1: _a0 = SkClipOp::kIntersect; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRRect *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->clipRRect(*_i1, _a0, _a1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipPath(SkPath None, SkClipOp None, bool None);) */
extern "C" void shim_278(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    SkClipOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkClipOp::kDifference; break;
        case 1: _a0 = SkClipOp::kIntersect; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPath *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->clipPath(*_i1, _a0, _a1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipRegion(SkRegion None, SkClipOp None);) */
extern "C" void shim_279(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRegion *_i1 = reinterpret_cast<SkRegion *>(in_ref[1]);
    SkClipOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkClipOp::kDifference; break;
        case 1: _a0 = SkClipOp::kIntersect; break;
    }
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRegion *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->clipRegion(*_i1, _a0);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPaint(SkPaint None);) */
extern "C" void shim_280(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPaint *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawPaint(*_i1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRect(SkRect None, SkPaint None);) */
extern "C" void shim_281(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawRect(*_i1, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRegion(SkRegion None, SkPaint None);) */
extern "C" void shim_282(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRegion *_i1 = reinterpret_cast<SkRegion *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRegion *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawRegion(*_i1, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawOval(SkRect None, SkPaint None);) */
extern "C" void shim_283(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawOval(*_i1, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRRect(SkRRect None, SkPaint None);) */
extern "C" void shim_284(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRRect *_i1 = reinterpret_cast<SkRRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawRRect(*_i1, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawDRRect(SkRRect None, SkRRect None, SkPaint None);) */
extern "C" void shim_285(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRRect *_i1 = reinterpret_cast<SkRRect *>(in_ref[1]);
    SkRRect *_i2 = reinterpret_cast<SkRRect *>(in_ref[2]);
    SkPaint *_i3 = reinterpret_cast<SkPaint *>(in_ref[3]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRRect *_o1;
    SkRRect *_o2;
    SkPaint *_o3;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawDRRect(*_i1, *_i2, *_i3);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawArc(SkRect None, SkScalar None, SkScalar None, bool None, SkPaint None);) */
extern "C" void shim_286(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawArc(*_i1, _a0, _a1, _a2, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPath(SkPath None, SkPaint None);) */
extern "C" void shim_287(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPath *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawPath(*_i1, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawTextBlob(sk_sp<SkTextBlob> None, SkScalar None, SkScalar None, SkPaint None);) */
extern "C" void shim_288(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkTextBlob> *_i1 = reinterpret_cast<sk_sp<SkTextBlob> *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkTextBlob> *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawTextBlob(*_i1, _a0, _a1, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, SkMatrix * None, SkPaint * None);) */
extern "C" void shim_289(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkPicture> *_i1 = reinterpret_cast<sk_sp<SkPicture> *>(in_ref[1]);
    SkMatrix *_i2 = reinterpret_cast<SkMatrix *>(in_ref[2]);
    SkPaint *_i3 = reinterpret_cast<SkPaint *>(in_ref[3]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkPicture> *_o1;
    SkMatrix *_o2;
    SkPaint *_o3;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawPicture(*_i1, _i2, _i3);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, SkMatrix * None, {nullptr});) */
extern "C" void shim_290(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkPicture> *_i1 = reinterpret_cast<sk_sp<SkPicture> *>(in_ref[1]);
    SkMatrix *_i2 = reinterpret_cast<SkMatrix *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkPicture> *_o1;
    SkMatrix *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawPicture(*_i1, _i2, nullptr);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, {nullptr}, SkPaint * None);) */
extern "C" void shim_291(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkPicture> *_i1 = reinterpret_cast<sk_sp<SkPicture> *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkPicture> *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawPicture(*_i1, nullptr, _i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, {nullptr}, {nullptr});) */
extern "C" void shim_292(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkPicture> *_i1 = reinterpret_cast<sk_sp<SkPicture> *>(in_ref[1]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkPicture> *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawPicture(*_i1, nullptr, nullptr);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawColor(SkColor None, SkBlendMode None);) */
extern "C" void shim_293(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    SkBlendMode _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 4)) % 32) {
        case 0: _a1 = SkBlendMode::kClear; break;
        case 1: _a1 = SkBlendMode::kSrc; break;
        case 2: _a1 = SkBlendMode::kDst; break;
        case 3: _a1 = SkBlendMode::kSrcOver; break;
        case 4: _a1 = SkBlendMode::kDstOver; break;
        case 5: _a1 = SkBlendMode::kSrcIn; break;
        case 6: _a1 = SkBlendMode::kDstIn; break;
        case 7: _a1 = SkBlendMode::kSrcOut; break;
        case 8: _a1 = SkBlendMode::kDstOut; break;
        case 9: _a1 = SkBlendMode::kSrcATop; break;
        case 10: _a1 = SkBlendMode::kDstATop; break;
        case 11: _a1 = SkBlendMode::kXor; break;
        case 12: _a1 = SkBlendMode::kPlus; break;
        case 13: _a1 = SkBlendMode::kModulate; break;
        case 14: _a1 = SkBlendMode::kScreen; break;
        case 15: _a1 = SkBlendMode::kOverlay; break;
        case 16: _a1 = SkBlendMode::kDarken; break;
        case 17: _a1 = SkBlendMode::kLighten; break;
        case 18: _a1 = SkBlendMode::kColorDodge; break;
        case 19: _a1 = SkBlendMode::kColorBurn; break;
        case 20: _a1 = SkBlendMode::kHardLight; break;
        case 21: _a1 = SkBlendMode::kSoftLight; break;
        case 22: _a1 = SkBlendMode::kDifference; break;
        case 23: _a1 = SkBlendMode::kExclusion; break;
        case 24: _a1 = SkBlendMode::kMultiply; break;
        case 25: _a1 = SkBlendMode::kHue; break;
        case 26: _a1 = SkBlendMode::kSaturation; break;
        case 27: _a1 = SkBlendMode::kColor; break;
        case 28: _a1 = SkBlendMode::kLuminosity; break;
        case 29: _a1 = SkBlendMode::kLastCoeffMode; break;
        case 30: _a1 = SkBlendMode::kLastSeparableMode; break;
        case 31: _a1 = SkBlendMode::kLastMode; break;
    }
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawColor(_a0, _a1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawLine(SkPoint None, SkPoint None, SkPaint None);) */
extern "C" void shim_294(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPoint *_i1 = reinterpret_cast<SkPoint *>(in_ref[1]);
    SkPoint *_i2 = reinterpret_cast<SkPoint *>(in_ref[2]);
    SkPaint *_i3 = reinterpret_cast<SkPaint *>(in_ref[3]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPoint *_o1;
    SkPoint *_o2;
    SkPaint *_o3;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawLine(*_i1, *_i2, *_i3);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawIRect(SkIRect None, SkPaint None);) */
extern "C" void shim_295(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkIRect *_i1 = reinterpret_cast<SkIRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkIRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawIRect(*_i1, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawCircle(SkPoint None, SkScalar None, SkPaint None);) */
extern "C" void shim_296(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPoint *_i1 = reinterpret_cast<SkPoint *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPoint *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawCircle(*_i1, _a0, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawArc(SkRect None, SkScalar None, SkScalar None, bool None, SkPaint None);) */
extern "C" void shim_297(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawArc(*_i1, _a0, _a1, _a2, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRoundRect(SkRect None, SkScalar None, SkScalar None, SkPaint None);) */
extern "C" void shim_298(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawRoundRect(*_i1, _a0, _a1, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_canvas_saveLayer) */
extern "C" void shim_299(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    sk_sp<SkImageFilter> *_i3 = reinterpret_cast<sk_sp<SkImageFilter> *>(in_ref[3]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    bool _a2 = *(static_cast<const char *>(context + 2)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
    SkPaint *_o2;
    sk_sp<SkImageFilter> *_o3;
	SkCanvas::SaveLayerRec saveLayerRec;
	if (_a0) saveLayerRec.fBounds = _i1;
	if (_a1) saveLayerRec.fPaint = _i2;
	if (_a2) saveLayerRec.fBackdrop = _i3->get();
	((SkCanvas *)_i0->active)->saveLayer(saveLayerRec);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=bundled_canvas_drawPoints) */
extern "C" void shim_300(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    float _a0[60];
    memcpy(&_a0, context + 0, 4 * 60);
    int _a1;
    memcpy(&_a1, context + 240, sizeof(int));
    SkCanvas::PointMode _a2;
    switch (*(reinterpret_cast<const unsigned char *>(context + 244)) % 3) {
        case 0: _a2 = SkCanvas::PointMode::kPoints_PointMode; break;
        case 1: _a2 = SkCanvas::PointMode::kLines_PointMode; break;
        case 2: _a2 = SkCanvas::PointMode::kPolygon_PointMode; break;
    }
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPaint *_o1;
	int count = _a1 % 30;
	SkPoint pts[30];
	for (int i = 0; i < count; ++i) {
	  pts[i] = SkPoint::Make(_a0[i*2], _a0[(i*2)+1]);
	}
	((SkCanvas *)_i0->active)->drawPoints(_a2, count, pts, *_i1);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_drawImage) */
extern "C" void shim_301(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkImage> *_o1;
    SkPaint *_o2;
	((SkCanvas *)_i0->active)->drawImage(_i1->get(), _a0, _a1, SkSamplingOptions(), _a2 ? _i2 : nullptr);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_drawImageRect) */
extern "C" void shim_302(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    SkRect *_i2 = reinterpret_cast<SkRect *>(in_ref[2]);
    SkRect *_i3 = reinterpret_cast<SkRect *>(in_ref[3]);
    SkPaint *_i4 = reinterpret_cast<SkPaint *>(in_ref[4]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkImage> *_o1;
    SkRect *_o2;
    SkRect *_o3;
    SkPaint *_o4;
	((SkCanvas *)_i0->active)->drawImageRect(_i1->get(), *_i2, *_i3, SkSamplingOptions(), _a0 ? _i4 : nullptr, _a1 ? SkCanvas::kStrict_SrcRectConstraint : SkCanvas::kFast_SrcRectConstraint);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	_o4 = _i4;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);
}


/* CPPScope(name=bundled_drawImageNine) */
extern "C" void shim_303(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    SkIRect *_i2 = reinterpret_cast<SkIRect *>(in_ref[2]);
    SkRect *_i3 = reinterpret_cast<SkRect *>(in_ref[3]);
    SkPaint *_i4 = reinterpret_cast<SkPaint *>(in_ref[4]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkImage> *_o1;
    SkIRect *_o2;
    SkRect *_o3;
    SkPaint *_o4;
	((SkCanvas *)_i0->active)->drawImageNine(_i1->get(), *_i2, *_i3, SkFilterMode::kNearest, _a0 ? _i4 : nullptr);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	_o4 = _i4;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);
}


/* CPPScope(name=bundled_canvas_drawImageLattice) */
extern "C" void shim_304(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    SkRect *_i2 = reinterpret_cast<SkRect *>(in_ref[2]);
    SkPaint *_i3 = reinterpret_cast<SkPaint *>(in_ref[3]);
    int _a0[6];
    memcpy(&_a0, context + 0, 4 * 6);
    int _a1[6];
    memcpy(&_a1, context + 24, 4 * 6);
    int _a2;
    memcpy(&_a2, context + 48, sizeof(int));
    int _a3;
    memcpy(&_a3, context + 52, sizeof(int));
    bool _a4 = *(static_cast<const char *>(context + 56)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkImage> *_o1;
    SkRect *_o2;
    SkPaint *_o3;
	SkCanvas::Lattice lattice{
	  _a0, 
	  _a1, 
	  nullptr, 
	  (_a2 % (6-2)) + 2,
	  (_a3 % (6-2)) + 2, 
	  nullptr, 
	  nullptr
	};
	((SkCanvas *)_i0->active)->drawImageLattice(_i1->get(), lattice, *_i2, SkFilterMode::kLinear, _a4 ? _i3 : nullptr);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=bundled_canvas_drawSimpleText) */
extern "C" void shim_305(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkFont *_i1 = reinterpret_cast<SkFont *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    float _a1;
    memcpy(&_a1, context + 128, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 132, sizeof(float));
    SkTextEncoding _a3;
    switch (*(reinterpret_cast<const unsigned char *>(context + 136)) % 4) {
        case 0: _a3 = SkTextEncoding::kUTF8; break;
        case 1: _a3 = SkTextEncoding::kUTF16; break;
        case 2: _a3 = SkTextEncoding::kUTF32; break;
        case 3: _a3 = SkTextEncoding::kGlyphID; break;
    }
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkFont *_o1;
    SkPaint *_o2;
	Fuzz f = Fuzz(_a0, 128);
	SkTDArray<uint8_t> text = make_fuzz_text(&f, *_i1, _a3);
	((SkCanvas *)_i0->active)->drawSimpleText(
	  text.begin(), 
	  SkToSizeT(text.count()),
	  _a3,
	  _a1,
	  _a2,
	  *_i1,
	  *_i2
	);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_canvas_drawVertices) */
extern "C" void shim_306(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    SkVertices::VertexMode _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 3) {
        case 0: _a0 = SkVertices::VertexMode::kTriangles_VertexMode; break;
        case 1: _a0 = SkVertices::VertexMode::kTriangleStrip_VertexMode; break;
        case 2: _a0 = SkVertices::VertexMode::kTriangleFan_VertexMode; break;
    }
    SkBlendMode _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 1)) % 32) {
        case 0: _a1 = SkBlendMode::kClear; break;
        case 1: _a1 = SkBlendMode::kSrc; break;
        case 2: _a1 = SkBlendMode::kDst; break;
        case 3: _a1 = SkBlendMode::kSrcOver; break;
        case 4: _a1 = SkBlendMode::kDstOver; break;
        case 5: _a1 = SkBlendMode::kSrcIn; break;
        case 6: _a1 = SkBlendMode::kDstIn; break;
        case 7: _a1 = SkBlendMode::kSrcOut; break;
        case 8: _a1 = SkBlendMode::kDstOut; break;
        case 9: _a1 = SkBlendMode::kSrcATop; break;
        case 10: _a1 = SkBlendMode::kDstATop; break;
        case 11: _a1 = SkBlendMode::kXor; break;
        case 12: _a1 = SkBlendMode::kPlus; break;
        case 13: _a1 = SkBlendMode::kModulate; break;
        case 14: _a1 = SkBlendMode::kScreen; break;
        case 15: _a1 = SkBlendMode::kOverlay; break;
        case 16: _a1 = SkBlendMode::kDarken; break;
        case 17: _a1 = SkBlendMode::kLighten; break;
        case 18: _a1 = SkBlendMode::kColorDodge; break;
        case 19: _a1 = SkBlendMode::kColorBurn; break;
        case 20: _a1 = SkBlendMode::kHardLight; break;
        case 21: _a1 = SkBlendMode::kSoftLight; break;
        case 22: _a1 = SkBlendMode::kDifference; break;
        case 23: _a1 = SkBlendMode::kExclusion; break;
        case 24: _a1 = SkBlendMode::kMultiply; break;
        case 25: _a1 = SkBlendMode::kHue; break;
        case 26: _a1 = SkBlendMode::kSaturation; break;
        case 27: _a1 = SkBlendMode::kColor; break;
        case 28: _a1 = SkBlendMode::kLuminosity; break;
        case 29: _a1 = SkBlendMode::kLastCoeffMode; break;
        case 30: _a1 = SkBlendMode::kLastSeparableMode; break;
        case 31: _a1 = SkBlendMode::kLastMode; break;
    }
    float _a2[200];
    memcpy(&_a2, context + 2, 4 * 200);
    float _a3[200];
    memcpy(&_a3, context + 802, 4 * 200);
    uint32_t _a4[100];
    memcpy(&_a4, context + 1602, 4 * 100);
    int _a5;
    memcpy(&_a5, context + 2002, sizeof(int));
    bool _a6 = *(static_cast<const char *>(context + 2006)) & 1;
    bool _a7 = *(static_cast<const char *>(context + 2007)) & 1;
    bool _a8 = *(static_cast<const char *>(context + 2008)) & 1;
    uint16_t _a9[200];
    memcpy(&_a9, context + 2009, 2 * 200);
    int _a10;
    memcpy(&_a10, context + 2409, sizeof(int));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPaint *_o1;
	int vertexCount = (_a5 % (100 - 3)) + 3;
	
	SkPoint vertices[100];
	SkPoint texs[100];
	
	for (int i = 0; i < vertexCount; ++i) {
	  vertices[i] = SkPoint::Make(_a2[i*2], _a2[(i*2)+1]);
	  texs[i] = SkPoint::Make(_a3[i*2], _a3[(i*2)+1]);
	}
	
	int indexCount = _a8 ? ((_a10 % 100) + vertexCount) : 0;
	
	((SkCanvas *)_i0->active)->drawVertices(SkVertices::MakeCopy(
	    _a0, vertexCount, vertices,
	    _a6 ? texs : nullptr,
	    _a7 ? _a4 : nullptr,
	    indexCount, _a9
	  ), _a1, *_i1
	);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_void drawColor(SkColor4f, SkBlendMode)) */
extern "C" void shim_307(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    SkBlendMode _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 4)) % 32) {
        case 0: _a1 = SkBlendMode::kClear; break;
        case 1: _a1 = SkBlendMode::kSrc; break;
        case 2: _a1 = SkBlendMode::kDst; break;
        case 3: _a1 = SkBlendMode::kSrcOver; break;
        case 4: _a1 = SkBlendMode::kDstOver; break;
        case 5: _a1 = SkBlendMode::kSrcIn; break;
        case 6: _a1 = SkBlendMode::kDstIn; break;
        case 7: _a1 = SkBlendMode::kSrcOut; break;
        case 8: _a1 = SkBlendMode::kDstOut; break;
        case 9: _a1 = SkBlendMode::kSrcATop; break;
        case 10: _a1 = SkBlendMode::kDstATop; break;
        case 11: _a1 = SkBlendMode::kXor; break;
        case 12: _a1 = SkBlendMode::kPlus; break;
        case 13: _a1 = SkBlendMode::kModulate; break;
        case 14: _a1 = SkBlendMode::kScreen; break;
        case 15: _a1 = SkBlendMode::kOverlay; break;
        case 16: _a1 = SkBlendMode::kDarken; break;
        case 17: _a1 = SkBlendMode::kLighten; break;
        case 18: _a1 = SkBlendMode::kColorDodge; break;
        case 19: _a1 = SkBlendMode::kColorBurn; break;
        case 20: _a1 = SkBlendMode::kHardLight; break;
        case 21: _a1 = SkBlendMode::kSoftLight; break;
        case 22: _a1 = SkBlendMode::kDifference; break;
        case 23: _a1 = SkBlendMode::kExclusion; break;
        case 24: _a1 = SkBlendMode::kMultiply; break;
        case 25: _a1 = SkBlendMode::kHue; break;
        case 26: _a1 = SkBlendMode::kSaturation; break;
        case 27: _a1 = SkBlendMode::kColor; break;
        case 28: _a1 = SkBlendMode::kLuminosity; break;
        case 29: _a1 = SkBlendMode::kLastCoeffMode; break;
        case 30: _a1 = SkBlendMode::kLastSeparableMode; break;
        case 31: _a1 = SkBlendMode::kLastMode; break;
    }
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((SkCanvas *)_i0->active)->drawColor(SkColor4f::FromColor(_a0), _a1);
	(_o0->active) = ((SkCanvas *)_i0->active);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_canvas_drawString) */
extern "C" void shim_308(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkFont *_i1 = reinterpret_cast<SkFont *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    float _a1;
    memcpy(&_a1, context + 128, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 132, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkFont *_o1;
    SkPaint *_o2;
	Fuzz f = Fuzz(_a0, 128);
	std::string str = make_fuzz_string(&f);
	((SkCanvas *)_i0->active)->drawString(str.c_str(), _a1, _a2, *_i1, *_i2);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_canvas_drawPatch) */
extern "C" void shim_309(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    float _a0[24];
    memcpy(&_a0, context + 0, 4 * 24);
    uint32_t _a1[4];
    memcpy(&_a1, context + 96, 4 * 4);
    float _a2[8];
    memcpy(&_a2, context + 112, 4 * 8);
    bool _a3 = *(static_cast<const char *>(context + 144)) & 1;
    SkBlendMode _a4;
    switch (*(reinterpret_cast<const unsigned char *>(context + 145)) % 32) {
        case 0: _a4 = SkBlendMode::kClear; break;
        case 1: _a4 = SkBlendMode::kSrc; break;
        case 2: _a4 = SkBlendMode::kDst; break;
        case 3: _a4 = SkBlendMode::kSrcOver; break;
        case 4: _a4 = SkBlendMode::kDstOver; break;
        case 5: _a4 = SkBlendMode::kSrcIn; break;
        case 6: _a4 = SkBlendMode::kDstIn; break;
        case 7: _a4 = SkBlendMode::kSrcOut; break;
        case 8: _a4 = SkBlendMode::kDstOut; break;
        case 9: _a4 = SkBlendMode::kSrcATop; break;
        case 10: _a4 = SkBlendMode::kDstATop; break;
        case 11: _a4 = SkBlendMode::kXor; break;
        case 12: _a4 = SkBlendMode::kPlus; break;
        case 13: _a4 = SkBlendMode::kModulate; break;
        case 14: _a4 = SkBlendMode::kScreen; break;
        case 15: _a4 = SkBlendMode::kOverlay; break;
        case 16: _a4 = SkBlendMode::kDarken; break;
        case 17: _a4 = SkBlendMode::kLighten; break;
        case 18: _a4 = SkBlendMode::kColorDodge; break;
        case 19: _a4 = SkBlendMode::kColorBurn; break;
        case 20: _a4 = SkBlendMode::kHardLight; break;
        case 21: _a4 = SkBlendMode::kSoftLight; break;
        case 22: _a4 = SkBlendMode::kDifference; break;
        case 23: _a4 = SkBlendMode::kExclusion; break;
        case 24: _a4 = SkBlendMode::kMultiply; break;
        case 25: _a4 = SkBlendMode::kHue; break;
        case 26: _a4 = SkBlendMode::kSaturation; break;
        case 27: _a4 = SkBlendMode::kColor; break;
        case 28: _a4 = SkBlendMode::kLuminosity; break;
        case 29: _a4 = SkBlendMode::kLastCoeffMode; break;
        case 30: _a4 = SkBlendMode::kLastSeparableMode; break;
        case 31: _a4 = SkBlendMode::kLastMode; break;
    }
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPaint *_o1;
	SkPoint cubics[12];
	for (int i = 0; i < 12; ++i) cubics[i] = SkPoint::Make(_a0[i*2], _a0[(i*2)+1]);
	SkPoint tex[4];
	for (int i = 0; i < 4; ++i) tex[i] = SkPoint::Make(_a2[i*2], _a2[(i*2)+1]);
	((SkCanvas *)_i0->active)->drawPatch(cubics, _a1, _a3 ? tex : nullptr, _a4, *_i1);
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void flush();) */
extern "C" void shim_310(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->flush();)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void save();) */
extern "C" void shim_311(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->save();)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayer(SkRect * None, SkPaint * None);) */
extern "C" void shim_312(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->saveLayer(_i1, _i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayer(SkRect * None, {nullptr});) */
extern "C" void shim_313(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->saveLayer(_i1, nullptr);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayer({nullptr}, SkPaint * None);) */
extern "C" void shim_314(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPaint *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->saveLayer(nullptr, _i1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayer({nullptr}, {nullptr});) */
extern "C" void shim_315(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->saveLayer(nullptr, nullptr);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayerAlpha({nullptr}, uint8_t None);) */
extern "C" void shim_316(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->saveLayerAlpha(nullptr, _a0);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayerAlpha(SkRect * None, uint8_t None);) */
extern "C" void shim_317(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->saveLayerAlpha(_i1, _a0);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void restore();) */
extern "C" void shim_318(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->restore();)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void restoreToCount(int None);) */
extern "C" void shim_319(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->restoreToCount(_a0);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void translate(SkScalar None, SkScalar None);) */
extern "C" void shim_320(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->translate(_a0, _a1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void scale(SkScalar None, SkScalar None);) */
extern "C" void shim_321(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->scale(_a0, _a1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void rotate(SkScalar None);) */
extern "C" void shim_322(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->rotate(_a0);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void rotate(SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_323(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->rotate(_a0, _a1, _a2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void skew(SkScalar None, SkScalar None);) */
extern "C" void shim_324(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->skew(_a0, _a1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void concat(SkMatrix None);) */
extern "C" void shim_325(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkMatrix *_i1 = reinterpret_cast<SkMatrix *>(in_ref[1]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkMatrix *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->concat(*_i1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void setMatrix(SkMatrix None);) */
extern "C" void shim_326(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkMatrix *_i1 = reinterpret_cast<SkMatrix *>(in_ref[1]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkMatrix *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->setMatrix(*_i1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void resetMatrix();) */
extern "C" void shim_327(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->resetMatrix();)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipRect(SkRect None, SkClipOp None, bool None);) */
extern "C" void shim_328(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkClipOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkClipOp::kDifference; break;
        case 1: _a0 = SkClipOp::kIntersect; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->clipRect(*_i1, _a0, _a1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipRRect(SkRRect None, SkClipOp None, bool None);) */
extern "C" void shim_329(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRRect *_i1 = reinterpret_cast<SkRRect *>(in_ref[1]);
    SkClipOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkClipOp::kDifference; break;
        case 1: _a0 = SkClipOp::kIntersect; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRRect *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->clipRRect(*_i1, _a0, _a1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipPath(SkPath None, SkClipOp None, bool None);) */
extern "C" void shim_330(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    SkClipOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkClipOp::kDifference; break;
        case 1: _a0 = SkClipOp::kIntersect; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPath *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->clipPath(*_i1, _a0, _a1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipRegion(SkRegion None, SkClipOp None);) */
extern "C" void shim_331(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRegion *_i1 = reinterpret_cast<SkRegion *>(in_ref[1]);
    SkClipOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkClipOp::kDifference; break;
        case 1: _a0 = SkClipOp::kIntersect; break;
    }
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRegion *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->clipRegion(*_i1, _a0);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPaint(SkPaint None);) */
extern "C" void shim_332(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPaint *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawPaint(*_i1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRect(SkRect None, SkPaint None);) */
extern "C" void shim_333(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawRect(*_i1, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRegion(SkRegion None, SkPaint None);) */
extern "C" void shim_334(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRegion *_i1 = reinterpret_cast<SkRegion *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRegion *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawRegion(*_i1, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawOval(SkRect None, SkPaint None);) */
extern "C" void shim_335(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawOval(*_i1, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRRect(SkRRect None, SkPaint None);) */
extern "C" void shim_336(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRRect *_i1 = reinterpret_cast<SkRRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawRRect(*_i1, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawDRRect(SkRRect None, SkRRect None, SkPaint None);) */
extern "C" void shim_337(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRRect *_i1 = reinterpret_cast<SkRRect *>(in_ref[1]);
    SkRRect *_i2 = reinterpret_cast<SkRRect *>(in_ref[2]);
    SkPaint *_i3 = reinterpret_cast<SkPaint *>(in_ref[3]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRRect *_o1;
    SkRRect *_o2;
    SkPaint *_o3;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawDRRect(*_i1, *_i2, *_i3);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawArc(SkRect None, SkScalar None, SkScalar None, bool None, SkPaint None);) */
extern "C" void shim_338(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawArc(*_i1, _a0, _a1, _a2, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPath(SkPath None, SkPaint None);) */
extern "C" void shim_339(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPath *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawPath(*_i1, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawTextBlob(sk_sp<SkTextBlob> None, SkScalar None, SkScalar None, SkPaint None);) */
extern "C" void shim_340(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkTextBlob> *_i1 = reinterpret_cast<sk_sp<SkTextBlob> *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkTextBlob> *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawTextBlob(*_i1, _a0, _a1, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, SkMatrix * None, SkPaint * None);) */
extern "C" void shim_341(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkPicture> *_i1 = reinterpret_cast<sk_sp<SkPicture> *>(in_ref[1]);
    SkMatrix *_i2 = reinterpret_cast<SkMatrix *>(in_ref[2]);
    SkPaint *_i3 = reinterpret_cast<SkPaint *>(in_ref[3]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkPicture> *_o1;
    SkMatrix *_o2;
    SkPaint *_o3;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawPicture(*_i1, _i2, _i3);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, SkMatrix * None, {nullptr});) */
extern "C" void shim_342(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkPicture> *_i1 = reinterpret_cast<sk_sp<SkPicture> *>(in_ref[1]);
    SkMatrix *_i2 = reinterpret_cast<SkMatrix *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkPicture> *_o1;
    SkMatrix *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawPicture(*_i1, _i2, nullptr);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, {nullptr}, SkPaint * None);) */
extern "C" void shim_343(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkPicture> *_i1 = reinterpret_cast<sk_sp<SkPicture> *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkPicture> *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawPicture(*_i1, nullptr, _i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, {nullptr}, {nullptr});) */
extern "C" void shim_344(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkPicture> *_i1 = reinterpret_cast<sk_sp<SkPicture> *>(in_ref[1]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkPicture> *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawPicture(*_i1, nullptr, nullptr);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawColor(SkColor None, SkBlendMode None);) */
extern "C" void shim_345(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    SkBlendMode _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 4)) % 32) {
        case 0: _a1 = SkBlendMode::kClear; break;
        case 1: _a1 = SkBlendMode::kSrc; break;
        case 2: _a1 = SkBlendMode::kDst; break;
        case 3: _a1 = SkBlendMode::kSrcOver; break;
        case 4: _a1 = SkBlendMode::kDstOver; break;
        case 5: _a1 = SkBlendMode::kSrcIn; break;
        case 6: _a1 = SkBlendMode::kDstIn; break;
        case 7: _a1 = SkBlendMode::kSrcOut; break;
        case 8: _a1 = SkBlendMode::kDstOut; break;
        case 9: _a1 = SkBlendMode::kSrcATop; break;
        case 10: _a1 = SkBlendMode::kDstATop; break;
        case 11: _a1 = SkBlendMode::kXor; break;
        case 12: _a1 = SkBlendMode::kPlus; break;
        case 13: _a1 = SkBlendMode::kModulate; break;
        case 14: _a1 = SkBlendMode::kScreen; break;
        case 15: _a1 = SkBlendMode::kOverlay; break;
        case 16: _a1 = SkBlendMode::kDarken; break;
        case 17: _a1 = SkBlendMode::kLighten; break;
        case 18: _a1 = SkBlendMode::kColorDodge; break;
        case 19: _a1 = SkBlendMode::kColorBurn; break;
        case 20: _a1 = SkBlendMode::kHardLight; break;
        case 21: _a1 = SkBlendMode::kSoftLight; break;
        case 22: _a1 = SkBlendMode::kDifference; break;
        case 23: _a1 = SkBlendMode::kExclusion; break;
        case 24: _a1 = SkBlendMode::kMultiply; break;
        case 25: _a1 = SkBlendMode::kHue; break;
        case 26: _a1 = SkBlendMode::kSaturation; break;
        case 27: _a1 = SkBlendMode::kColor; break;
        case 28: _a1 = SkBlendMode::kLuminosity; break;
        case 29: _a1 = SkBlendMode::kLastCoeffMode; break;
        case 30: _a1 = SkBlendMode::kLastSeparableMode; break;
        case 31: _a1 = SkBlendMode::kLastMode; break;
    }
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawColor(_a0, _a1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawLine(SkPoint None, SkPoint None, SkPaint None);) */
extern "C" void shim_346(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPoint *_i1 = reinterpret_cast<SkPoint *>(in_ref[1]);
    SkPoint *_i2 = reinterpret_cast<SkPoint *>(in_ref[2]);
    SkPaint *_i3 = reinterpret_cast<SkPaint *>(in_ref[3]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPoint *_o1;
    SkPoint *_o2;
    SkPaint *_o3;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawLine(*_i1, *_i2, *_i3);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	_o3 = _i3;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawIRect(SkIRect None, SkPaint None);) */
extern "C" void shim_347(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkIRect *_i1 = reinterpret_cast<SkIRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkIRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawIRect(*_i1, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawCircle(SkPoint None, SkScalar None, SkPaint None);) */
extern "C" void shim_348(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPoint *_i1 = reinterpret_cast<SkPoint *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPoint *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawCircle(*_i1, _a0, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawArc(SkRect None, SkScalar None, SkScalar None, bool None, SkPaint None);) */
extern "C" void shim_349(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawArc(*_i1, _a0, _a1, _a2, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRoundRect(SkRect None, SkScalar None, SkScalar None, SkPaint None);) */
extern "C" void shim_350(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkRect *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawRoundRect(*_i1, _a0, _a1, *_i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
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
    &shim_78,
    &shim_79,
    &shim_80,
    &shim_81,
    &shim_82,
    &shim_83,
    &shim_84,
    &shim_85,
    &shim_86,
    &shim_87,
    &shim_88,
    &shim_89,
    &shim_90,
    &shim_91,
    &shim_92,
    &shim_93,
    &shim_94,
    &shim_95,
    &shim_96,
    &shim_97,
    &shim_98,
    &shim_99,
    &shim_100,
    &shim_101,
    &shim_102,
    &shim_103,
    &shim_104,
    &shim_105,
    &shim_106,
    &shim_107,
    &shim_108,
    &shim_109,
    &shim_110,
    &shim_111,
    &shim_112,
    &shim_113,
    &shim_114,
    &shim_115,
    &shim_116,
    &shim_117,
    &shim_118,
    &shim_119,
    &shim_120,
    &shim_121,
    &shim_122,
    &shim_123,
    &shim_124,
    &shim_125,
    &shim_126,
    &shim_127,
    &shim_128,
    &shim_129,
    &shim_130,
    &shim_131,
    &shim_132,
    &shim_133,
    &shim_134,
    &shim_135,
    &shim_136,
    &shim_137,
    &shim_138,
    &shim_139,
    &shim_140,
    &shim_141,
    &shim_142,
    &shim_143,
    &shim_144,
    &shim_145,
    &shim_146,
    &shim_147,
    &shim_148,
    &shim_149,
    &shim_150,
    &shim_151,
    &shim_152,
    &shim_153,
    &shim_154,
    &shim_155,
    &shim_156,
    &shim_157,
    &shim_158,
    &shim_159,
    &shim_160,
    &shim_161,
    &shim_162,
    &shim_163,
    &shim_164,
    &shim_165,
    &shim_166,
    &shim_167,
    &shim_168,
    &shim_169,
    &shim_170,
    &shim_171,
    &shim_172,
    &shim_173,
    &shim_174,
    &shim_175,
    &shim_176,
    &shim_177,
    &shim_178,
    &shim_179,
    &shim_180,
    &shim_181,
    &shim_182,
    &shim_183,
    &shim_184,
    &shim_185,
    &shim_186,
    &shim_187,
    &shim_188,
    &shim_189,
    &shim_190,
    &shim_191,
    &shim_192,
    &shim_193,
    &shim_194,
    &shim_195,
    &shim_196,
    &shim_197,
    &shim_198,
    &shim_199,
    &shim_200,
    &shim_201,
    &shim_202,
    &shim_203,
    &shim_204,
    &shim_205,
    &shim_206,
    &shim_207,
    &shim_208,
    &shim_209,
    &shim_210,
    &shim_211,
    &shim_212,
    &shim_213,
    &shim_214,
    &shim_215,
    &shim_216,
    &shim_217,
    &shim_218,
    &shim_219,
    &shim_220,
    &shim_221,
    &shim_222,
    &shim_223,
    &shim_224,
    &shim_225,
    &shim_226,
    &shim_227,
    &shim_228,
    &shim_229,
    &shim_230,
    &shim_231,
    &shim_232,
    &shim_233,
    &shim_234,
    &shim_235,
    &shim_236,
    &shim_237,
    &shim_238,
    &shim_239,
    &shim_240,
    &shim_241,
    &shim_242,
    &shim_243,
    &shim_244,
    &shim_245,
    &shim_246,
    &shim_247,
    &shim_248,
    &shim_249,
    &shim_250,
    &shim_251,
    &shim_252,
    &shim_253,
    &shim_254,
    &shim_255,
    &shim_256,
    &shim_257,
    &shim_258,
    &shim_259,
    &shim_260,
    &shim_261,
    &shim_262,
    &shim_263,
    &shim_264,
    &shim_265,
    &shim_266,
    &shim_267,
    &shim_268,
    &shim_269,
    &shim_270,
    &shim_271,
    &shim_272,
    &shim_273,
    &shim_274,
    &shim_275,
    &shim_276,
    &shim_277,
    &shim_278,
    &shim_279,
    &shim_280,
    &shim_281,
    &shim_282,
    &shim_283,
    &shim_284,
    &shim_285,
    &shim_286,
    &shim_287,
    &shim_288,
    &shim_289,
    &shim_290,
    &shim_291,
    &shim_292,
    &shim_293,
    &shim_294,
    &shim_295,
    &shim_296,
    &shim_297,
    &shim_298,
    &shim_299,
    &shim_300,
    &shim_301,
    &shim_302,
    &shim_303,
    &shim_304,
    &shim_305,
    &shim_306,
    &shim_307,
    &shim_308,
    &shim_309,
    &shim_310,
    &shim_311,
    &shim_312,
    &shim_313,
    &shim_314,
    &shim_315,
    &shim_316,
    &shim_317,
    &shim_318,
    &shim_319,
    &shim_320,
    &shim_321,
    &shim_322,
    &shim_323,
    &shim_324,
    &shim_325,
    &shim_326,
    &shim_327,
    &shim_328,
    &shim_329,
    &shim_330,
    &shim_331,
    &shim_332,
    &shim_333,
    &shim_334,
    &shim_335,
    &shim_336,
    &shim_337,
    &shim_338,
    &shim_339,
    &shim_340,
    &shim_341,
    &shim_342,
    &shim_343,
    &shim_344,
    &shim_345,
    &shim_346,
    &shim_347,
    &shim_348,
    &shim_349,
    &shim_350,
};

