#include "SkBitmap.h"
#include "SkBlendMode.h"
#include "SkCanvas.h"
#include "SkClipOp.h"
#include "SkFilterQuality.h"
#include "SkFont.h"
#include "SkImage.h"
#include "SkImageInfo.h"
#include "SkPaint.h"
#include "SkPath.h"
#include "SkRect.h"
#include "SkSurface.h"
#include "SkTextBlob.h"
#include "SkTypeface.h"


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



/* CPPScope(name=(auto) SkPaint::SkPaint();) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_o0;
	_o0 = MAKE(SkPaint);
	SkPaint ref = SkPaint();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPaint::void setAntiAlias(bool aa);) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    SkPaint *_o0;
	FUZZ_ENDPOINT(_i0->setAntiAlias(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPaint::void setBlendMode(SkBlendMode mode);) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkPaint::void setColor(SkColor color);) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    SkPaint *_o0;
	FUZZ_ENDPOINT(_i0->setColor(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPaint::void setDither(bool dither);) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    SkPaint *_o0;
	FUZZ_ENDPOINT(_i0->setDither(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPaint::void setStrokeCap(SkPaint::Cap cap);) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkPaint::void setStrokeJoin(SkPaint::Join join);) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkPaint::void setStrokeMiter(SkScalar miter);) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    SkPaint *_o0;
	FUZZ_ENDPOINT(_i0->setStrokeMiter(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPaint::void setStrokeWidth(SkScalar width);) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    SkPaint *_o0;
	FUZZ_ENDPOINT(_i0->setStrokeWidth(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPaint::void setStyle(SkPaint::Style style);) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkPaint::~SkPaint();) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    SkPaint *_i0 = reinterpret_cast<SkPaint *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) SkImageInfo::SkImageInfo Make(int width, int height, SkColorType ct, SkAlphaType at);) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    SkColorType _a2;
    switch (*(reinterpret_cast<const unsigned char *>(context + 8)) % 22) {
        case 0: _a2 = SkColorType::kUnknown_SkColorType; break;
        case 1: _a2 = SkColorType::kAlpha_8_SkColorType; break;
        case 2: _a2 = SkColorType::kRGB_565_SkColorType; break;
        case 3: _a2 = SkColorType::kARGB_4444_SkColorType; break;
        case 4: _a2 = SkColorType::kRGBA_8888_SkColorType; break;
        case 5: _a2 = SkColorType::kRGB_888x_SkColorType; break;
        case 6: _a2 = SkColorType::kBGRA_8888_SkColorType; break;
        case 7: _a2 = SkColorType::kRGBA_1010102_SkColorType; break;
        case 8: _a2 = SkColorType::kBGRA_1010102_SkColorType; break;
        case 9: _a2 = SkColorType::kRGB_101010x_SkColorType; break;
        case 10: _a2 = SkColorType::kBGR_101010x_SkColorType; break;
        case 11: _a2 = SkColorType::kGray_8_SkColorType; break;
        case 12: _a2 = SkColorType::kRGBA_F16Norm_SkColorType; break;
        case 13: _a2 = SkColorType::kRGBA_F16_SkColorType; break;
        case 14: _a2 = SkColorType::kRGBA_F32_SkColorType; break;
        case 15: _a2 = SkColorType::kR8G8_unorm_SkColorType; break;
        case 16: _a2 = SkColorType::kA16_float_SkColorType; break;
        case 17: _a2 = SkColorType::kR16G16_float_SkColorType; break;
        case 18: _a2 = SkColorType::kA16_unorm_SkColorType; break;
        case 19: _a2 = SkColorType::kR16G16_unorm_SkColorType; break;
        case 20: _a2 = SkColorType::kR16G16B16A16_unorm_SkColorType; break;
        case 21: _a2 = SkColorType::kLastEnum_SkColorType; break;
    }
    SkAlphaType _a3;
    switch (*(reinterpret_cast<const unsigned char *>(context + 9)) % 5) {
        case 0: _a3 = SkAlphaType::kUnknown_SkAlphaType; break;
        case 1: _a3 = SkAlphaType::kOpaque_SkAlphaType; break;
        case 2: _a3 = SkAlphaType::kPremul_SkAlphaType; break;
        case 3: _a3 = SkAlphaType::kUnpremul_SkAlphaType; break;
        case 4: _a3 = SkAlphaType::kLastEnum_SkAlphaType; break;
    }
    SkImageInfo *_o0;
	_o0 = MAKE(SkImageInfo);
	SkImageInfo ref = SkImageInfo::Make(_a0, _a1, _a2, _a3);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkImageInfo::~SkImageInfo();) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    SkImageInfo *_i0 = reinterpret_cast<SkImageInfo *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=sk_sp<SkImage> asImage()) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    SkBitmap *_i0 = reinterpret_cast<SkBitmap *>(in_ref[0]);
    SkBitmap *_o0;
    sk_sp<SkImage> *_o1;
	_o1 = MAKE(sk_sp<SkImage>);
	*_o1 = _i0->asImage();
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkBitmap::SkBitmap();) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    SkBitmap *_o0;
	_o0 = MAKE(SkBitmap);
	SkBitmap ref = SkBitmap();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkBitmap::bool tryAllocPixels(const SkImageInfo & info);) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    SkBitmap *_i0 = reinterpret_cast<SkBitmap *>(in_ref[0]);
    SkImageInfo *_i1 = reinterpret_cast<SkImageInfo *>(in_ref[1]);
    SkBitmap *_o0;
    SkImageInfo *_o1;
	FUZZ_ENDPOINT(_i0->tryAllocPixels(*_i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkBitmap::void eraseColor(SkColor c);) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    SkBitmap *_i0 = reinterpret_cast<SkBitmap *>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    SkBitmap *_o0;
	FUZZ_ENDPOINT(_i0->eraseColor(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkBitmap::~SkBitmap();) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    SkBitmap *_i0 = reinterpret_cast<SkBitmap *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=make_surface) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    uint8_t _a1;
    memcpy(&_a1, context + 1, sizeof(uint8_t));
    sk_sp<SkSurface> *_o0;
	int width = (_a0 % (250 - 1)) + 1;
	int height = (_a1 % (250 - 1)) + 1;
	_o0 = MAKE(sk_sp<SkSurface>);
	*_o0 = SkSurface::MakeRasterN32Premul(width, height);
	if (!*_o0) {
	  *_o0 = SkSurface::MakeNull(width, height);
	}
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=get_canvas) */
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkSurface> *_i0 = reinterpret_cast<sk_sp<SkSurface> *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0;
	SkCanvas *canvas = _i0->get()->getCanvas();
	_o0 = BUNDLE(canvas, _i0);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=delete) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
	delete _i0;
	
}


/* CPPScope(name=(auto) sk_sp<SkSurface>::~sk_sp<SkSurface>();) */
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkSurface> *_i0 = reinterpret_cast<sk_sp<SkSurface> *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) SkFont::SkFont();) */
extern "C" void shim_22(void **in_ref, void **out_ref, const char *context) {
    SkFont *_o0;
	_o0 = MAKE(SkFont);
	SkFont ref = SkFont();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::SkFont(sk_sp<SkTypeface> typeface);) */
extern "C" void shim_23(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkTypeface> *_i0 = reinterpret_cast<sk_sp<SkTypeface> *>(in_ref[0]);
    SkFont *_o0;
    sk_sp<SkTypeface> *_o1;
	_o0 = MAKE(SkFont);
	SkFont ref = SkFont(*_i0);
	*_o0 = ref;
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkFont::void setForceAutoHinting(bool forceAutoHinting);) */
extern "C" void shim_24(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setForceAutoHinting(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::void setEmbeddedBitmaps(bool embeddedBitmaps);) */
extern "C" void shim_25(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setEmbeddedBitmaps(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::void setEmbolden(bool embolden);) */
extern "C" void shim_26(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setEmbolden(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::void setEdging(SkFont::Edging edging);) */
extern "C" void shim_27(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkFont::void setLinearMetrics(bool linearMetrics);) */
extern "C" void shim_28(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setLinearMetrics(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::void setSubpixel(bool subpixel);) */
extern "C" void shim_29(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setSubpixel(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::void setScaleX(SkScalar scaleX);) */
extern "C" void shim_30(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setScaleX(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::void setSkewX(SkScalar skewX);) */
extern "C" void shim_31(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setSkewX(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::void setSize(SkScalar textSize);) */
extern "C" void shim_32(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    SkFont *_o0;
	FUZZ_ENDPOINT(_i0->setSize(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkFont::~SkFont();) */
extern "C" void shim_33(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=sk_sp<SkTypeface> MakeDefault()) */
extern "C" void shim_34(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkTypeface> *_o0;
	_o0 = MAKE(sk_sp<SkTypeface>);
	*_o0 = SkTypeface::MakeDefault();
	if (*_o0 == nullptr) abort();
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) sk_sp<SkTypeface>::~sk_sp<SkTypeface>();) */
extern "C" void shim_35(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkTypeface> *_i0 = reinterpret_cast<sk_sp<SkTypeface> *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=drawImageRect) */
extern "C" void shim_36(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    SkRect *_i2 = reinterpret_cast<SkRect *>(in_ref[2]);
    SkRect *_i3 = reinterpret_cast<SkRect *>(in_ref[3]);
    SkPaint *_i4 = reinterpret_cast<SkPaint *>(in_ref[4]);
    SkCanvas::SrcRectConstraint _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkCanvas::SrcRectConstraint::kStrict_SrcRectConstraint; break;
        case 1: _a0 = SkCanvas::SrcRectConstraint::kFast_SrcRectConstraint; break;
    }
    SkCanvas *_o0;
    sk_sp<SkImage> *_o1;
    SkRect *_o2;
    SkRect *_o3;
    SkPaint *_o4;
	_i0->drawImageRect(_i1->get(), *_i2, *_i3, SkSamplingOptions(), _i4, _a0);
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


/* CPPScope(name=(auto) SkCanvas::void drawCircle(SkScalar cx, SkScalar cy, SkScalar radius, const SkPaint & paint);) */
extern "C" void shim_37(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    SkCanvas *_o0;
    SkPaint *_o1;
	FUZZ_ENDPOINT(_i0->drawCircle(_a0, _a1, _a2, *_i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkCanvas::void drawLine(SkScalar x0, SkScalar y0, SkScalar x1, SkScalar y1, const SkPaint & paint);) */
extern "C" void shim_38(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    SkCanvas *_o0;
    SkPaint *_o1;
	FUZZ_ENDPOINT(_i0->drawLine(_a0, _a1, _a2, _a3, *_i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkCanvas::void drawRect(const SkRect & rect, const SkPaint & paint);) */
extern "C" void shim_39(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkCanvas::void clipRect(const SkRect & rect, SkClipOp op, bool doAntiAlias);) */
extern "C" void shim_40(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkClipOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 7) {
        case 0: _a0 = SkClipOp::kDifference; break;
        case 1: _a0 = SkClipOp::kIntersect; break;
        case 2: _a0 = SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway2; break;
        case 3: _a0 = SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway3; break;
        case 4: _a0 = SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway4; break;
        case 5: _a0 = SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway5; break;
        case 6: _a0 = SkClipOp::kMax_EnumValue; break;
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


/* CPPScope(name=(auto) SkCanvas::void drawPath(const SkPath & path, const SkPaint & paint);) */
extern "C" void shim_41(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkCanvas::void clipPath(const SkPath & path, SkClipOp op, bool doAntiAlias);) */
extern "C" void shim_42(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    SkClipOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 7) {
        case 0: _a0 = SkClipOp::kDifference; break;
        case 1: _a0 = SkClipOp::kIntersect; break;
        case 2: _a0 = SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway2; break;
        case 3: _a0 = SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway3; break;
        case 4: _a0 = SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway4; break;
        case 5: _a0 = SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway5; break;
        case 6: _a0 = SkClipOp::kMax_EnumValue; break;
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


/* CPPScope(name=(auto) SkCanvas::void drawPaint(const SkPaint & paint);) */
extern "C" void shim_43(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkCanvas::void drawImage(const sk_sp<SkImage> & image, SkScalar x, SkScalar y, {SkSamplingOptions()}, const SkPaint * paint);) */
extern "C" void shim_44(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkCanvas *_o0;
    sk_sp<SkImage> *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(_i0->drawImage(*_i1, _a0, _a1, SkSamplingOptions(), _i2);)
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) SkCanvas::void drawImage(const sk_sp<SkImage> & image, SkScalar x, SkScalar y, {SkSamplingOptions()}, {nullptr});) */
extern "C" void shim_45(void **in_ref, void **out_ref, const char *context) {
    SkCanvas *_i0 = reinterpret_cast<SkCanvas *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkCanvas *_o0;
    sk_sp<SkImage> *_o1;
	FUZZ_ENDPOINT(_i0->drawImage(*_i1, _a0, _a1, SkSamplingOptions(), nullptr);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkCanvas::void drawTextBlob(const sk_sp<SkTextBlob> & blob, SkScalar x, SkScalar y, const SkPaint & paint);) */
extern "C" void shim_46(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkRect::constexpr SkRect MakeXYWH(SkScalar x, SkScalar y, SkScalar w, SkScalar h);) */
extern "C" void shim_47(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkRect::constexpr SkRect MakeWH(SkScalar w, SkScalar h);) */
extern "C" void shim_48(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    SkRect *_o0;
	_o0 = MAKE(SkRect);
	SkRect ref = SkRect::MakeWH(_a0, _a1);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkRect::~SkRect();) */
extern "C" void shim_49(void **in_ref, void **out_ref, const char *context) {
    SkRect *_i0 = reinterpret_cast<SkRect *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) SkPath::SkPath();) */
extern "C" void shim_50(void **in_ref, void **out_ref, const char *context) {
    SkPath *_o0;
	_o0 = MAKE(SkPath);
	SkPath ref = SkPath();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::void moveTo(SkScalar x, SkScalar y);) */
extern "C" void shim_51(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkPath::void lineTo(SkScalar x, SkScalar y);) */
extern "C" void shim_52(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkPath::void quadTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2);) */
extern "C" void shim_53(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkPath::void conicTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w);) */
extern "C" void shim_54(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkPath::SkPath & cubicTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3);) */
extern "C" void shim_55(void **in_ref, void **out_ref, const char *context) {
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
    SkPath *_o1;
	_o1 = MAKE(SkPath);
	*_o1 = _i0->cubicTo(_a0, _a1, _a2, _a3, _a4, _a5);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) SkPath::void arcTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar radius);) */
extern "C" void shim_56(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=(auto) SkPath::void close();) */
extern "C" void shim_57(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
    SkPath *_o0;
	FUZZ_ENDPOINT(_i0->close();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) SkPath::~SkPath();) */
extern "C" void shim_58(void **in_ref, void **out_ref, const char *context) {
    SkPath *_i0 = reinterpret_cast<SkPath *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) sk_sp<SkImage>::~sk_sp<SkImage>();) */
extern "C" void shim_59(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkImage> *_i0 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=sk_sp<SkTextBlob> MakeFromPosText(const void *text, size_t byteLength, const SkPoint pos[], const SkFont &font)) */
extern "C" void shim_60(void **in_ref, void **out_ref, const char *context) {
    SkFont *_i0 = reinterpret_cast<SkFont *>(in_ref[0]);
    char _a0;
    memcpy(&_a0, context + 0, sizeof(char));
    char _a1;
    memcpy(&_a1, context + 1, sizeof(char));
    char _a2;
    memcpy(&_a2, context + 2, sizeof(char));
    char _a3;
    memcpy(&_a3, context + 3, sizeof(char));
    char _a4;
    memcpy(&_a4, context + 4, sizeof(char));
    float _a5;
    memcpy(&_a5, context + 5, sizeof(float));
    float _a6;
    memcpy(&_a6, context + 9, sizeof(float));
    float _a7;
    memcpy(&_a7, context + 13, sizeof(float));
    float _a8;
    memcpy(&_a8, context + 17, sizeof(float));
    float _a9;
    memcpy(&_a9, context + 21, sizeof(float));
    float _a10;
    memcpy(&_a10, context + 25, sizeof(float));
    float _a11;
    memcpy(&_a11, context + 29, sizeof(float));
    float _a12;
    memcpy(&_a12, context + 33, sizeof(float));
    float _a13;
    memcpy(&_a13, context + 37, sizeof(float));
    float _a14;
    memcpy(&_a14, context + 41, sizeof(float));
    SkFont *_o0;
    sk_sp<SkTextBlob> *_o1;
	char text[5];
	text[0] = _a0;
	text[1] = _a1;
	text[2] = _a2;
	text[3] = _a3;
	text[4] = _a4;
	SkPoint pts[5];
	pts[0].set(_a5,_a6);
	pts[1].set(_a7,_a8);
	pts[2].set(_a9,_a10);
	pts[3].set(_a11,_a12);
	pts[4].set(_a13,_a14);
	_o1 = MAKE(sk_sp<SkTextBlob>);
	*_o1 = SkTextBlob::MakeFromPosText(text, 4, pts, *_i0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) sk_sp<SkTextBlob>::~sk_sp<SkTextBlob>();) */
extern "C" void shim_61(void **in_ref, void **out_ref, const char *context) {
    sk_sp<SkTextBlob> *_i0 = reinterpret_cast<sk_sp<SkTextBlob> *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=bundled_drawImageRect) */
extern "C" void shim_62(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    SkRect *_i2 = reinterpret_cast<SkRect *>(in_ref[2]);
    SkRect *_i3 = reinterpret_cast<SkRect *>(in_ref[3]);
    SkPaint *_i4 = reinterpret_cast<SkPaint *>(in_ref[4]);
    SkCanvas::SrcRectConstraint _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = SkCanvas::SrcRectConstraint::kStrict_SrcRectConstraint; break;
        case 1: _a0 = SkCanvas::SrcRectConstraint::kFast_SrcRectConstraint; break;
    }
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkImage> *_o1;
    SkRect *_o2;
    SkRect *_o3;
    SkPaint *_o4;
	((SkCanvas *)_i0->active)->drawImageRect(_i1->get(), *_i2, *_i3, SkSamplingOptions(), _i4, _a0);
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


/* CPPScope(name=bundled_(auto) SkCanvas::void drawCircle(SkScalar cx, SkScalar cy, SkScalar radius, const SkPaint & paint);) */
extern "C" void shim_63(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPaint *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawCircle(_a0, _a1, _a2, *_i1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawLine(SkScalar x0, SkScalar y0, SkScalar x1, SkScalar y1, const SkPaint & paint);) */
extern "C" void shim_64(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPaint *_i1 = reinterpret_cast<SkPaint *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    SkPaint *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawLine(_a0, _a1, _a2, _a3, *_i1);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRect(const SkRect & rect, const SkPaint & paint);) */
extern "C" void shim_65(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=bundled_(auto) SkCanvas::void clipRect(const SkRect & rect, SkClipOp op, bool doAntiAlias);) */
extern "C" void shim_66(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkRect *_i1 = reinterpret_cast<SkRect *>(in_ref[1]);
    SkClipOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 7) {
        case 0: _a0 = SkClipOp::kDifference; break;
        case 1: _a0 = SkClipOp::kIntersect; break;
        case 2: _a0 = SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway2; break;
        case 3: _a0 = SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway3; break;
        case 4: _a0 = SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway4; break;
        case 5: _a0 = SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway5; break;
        case 6: _a0 = SkClipOp::kMax_EnumValue; break;
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


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPath(const SkPath & path, const SkPaint & paint);) */
extern "C" void shim_67(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=bundled_(auto) SkCanvas::void clipPath(const SkPath & path, SkClipOp op, bool doAntiAlias);) */
extern "C" void shim_68(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    SkPath *_i1 = reinterpret_cast<SkPath *>(in_ref[1]);
    SkClipOp _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 7) {
        case 0: _a0 = SkClipOp::kDifference; break;
        case 1: _a0 = SkClipOp::kIntersect; break;
        case 2: _a0 = SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway2; break;
        case 3: _a0 = SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway3; break;
        case 4: _a0 = SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway4; break;
        case 5: _a0 = SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway5; break;
        case 6: _a0 = SkClipOp::kMax_EnumValue; break;
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


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPaint(const SkPaint & paint);) */
extern "C" void shim_69(void **in_ref, void **out_ref, const char *context) {
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


/* CPPScope(name=bundled_(auto) SkCanvas::void drawImage(const sk_sp<SkImage> & image, SkScalar x, SkScalar y, {SkSamplingOptions()}, const SkPaint * paint);) */
extern "C" void shim_70(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    SkPaint *_i2 = reinterpret_cast<SkPaint *>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkImage> *_o1;
    SkPaint *_o2;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawImage(*_i1, _a0, _a1, SkSamplingOptions(), _i2);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	_o2 = _i2;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawImage(const sk_sp<SkImage> & image, SkScalar x, SkScalar y, {SkSamplingOptions()}, {nullptr});) */
extern "C" void shim_71(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    sk_sp<SkImage> *_i1 = reinterpret_cast<sk_sp<SkImage> *>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    sk_sp<SkImage> *_o1;
	FUZZ_ENDPOINT(((SkCanvas *)_i0->active)->drawImage(*_i1, _a0, _a1, SkSamplingOptions(), nullptr);)
	(_o0->active) = ((SkCanvas *)_i0->active);
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawTextBlob(const sk_sp<SkTextBlob> & blob, SkScalar x, SkScalar y, const SkPaint & paint);) */
extern "C" void shim_72(void **in_ref, void **out_ref, const char *context) {
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
};

