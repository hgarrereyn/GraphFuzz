#include "./paragraph_util.h"
#include "modules/skparagraph/include/ParagraphStyle.h"
#include "modules/skparagraph/include/TextStyle.h"
#include "modules/skparagraph/src/ParagraphBuilderImpl.h"


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



/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::skia::textlayout::ParagraphStyle();) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::ParagraphStyle *_o0;
	_o0 = new skia::textlayout::ParagraphStyle();
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::void turnHintingOff();) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::ParagraphStyle *_i0 = reinterpret_cast<skia::textlayout::ParagraphStyle *>(in_ref[0]);
    skia::textlayout::ParagraphStyle *_o0;
	FUZZ_ENDPOINT(_i0->turnHintingOff();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::void setStrutStyle(skia::textlayout::StrutStyle None);) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::ParagraphStyle *_i0 = reinterpret_cast<skia::textlayout::ParagraphStyle *>(in_ref[0]);
    skia::textlayout::StrutStyle *_i1 = reinterpret_cast<skia::textlayout::StrutStyle *>(in_ref[1]);
    skia::textlayout::ParagraphStyle *_o0;
    skia::textlayout::StrutStyle *_o1;
	FUZZ_ENDPOINT(_i0->setStrutStyle(*_i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::void setTextDirection(skia::textlayout::TextDirection None);) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::ParagraphStyle *_i0 = reinterpret_cast<skia::textlayout::ParagraphStyle *>(in_ref[0]);
    skia::textlayout::TextDirection _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = skia::textlayout::TextDirection::kRtl; break;
        case 1: _a0 = skia::textlayout::TextDirection::kLtr; break;
    }
    skia::textlayout::ParagraphStyle *_o0;
	FUZZ_ENDPOINT(_i0->setTextDirection(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::void setTextAlign(skia::textlayout::TextAlign None);) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::ParagraphStyle *_i0 = reinterpret_cast<skia::textlayout::ParagraphStyle *>(in_ref[0]);
    skia::textlayout::TextAlign _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 6) {
        case 0: _a0 = skia::textlayout::TextAlign::kLeft; break;
        case 1: _a0 = skia::textlayout::TextAlign::kRight; break;
        case 2: _a0 = skia::textlayout::TextAlign::kCenter; break;
        case 3: _a0 = skia::textlayout::TextAlign::kJustify; break;
        case 4: _a0 = skia::textlayout::TextAlign::kStart; break;
        case 5: _a0 = skia::textlayout::TextAlign::kEnd; break;
    }
    skia::textlayout::ParagraphStyle *_o0;
	FUZZ_ENDPOINT(_i0->setTextAlign(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::void setMaxLines(size_t None);) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::ParagraphStyle *_i0 = reinterpret_cast<skia::textlayout::ParagraphStyle *>(in_ref[0]);
    size_t _a0;
    memcpy(&_a0, context + 0, sizeof(size_t));
    skia::textlayout::ParagraphStyle *_o0;
	FUZZ_ENDPOINT(_i0->setMaxLines(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::void setEllipsis({u"\u2026"});) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::ParagraphStyle *_i0 = reinterpret_cast<skia::textlayout::ParagraphStyle *>(in_ref[0]);
    skia::textlayout::ParagraphStyle *_o0;
	FUZZ_ENDPOINT(_i0->setEllipsis(u"\u2026");)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::void setHeight(SkScalar None);) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::ParagraphStyle *_i0 = reinterpret_cast<skia::textlayout::ParagraphStyle *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    skia::textlayout::ParagraphStyle *_o0;
	FUZZ_ENDPOINT(_i0->setHeight(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::void setTextHeightBehavior(skia::textlayout::TextHeightBehavior None);) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::ParagraphStyle *_i0 = reinterpret_cast<skia::textlayout::ParagraphStyle *>(in_ref[0]);
    skia::textlayout::TextHeightBehavior _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 4) {
        case 0: _a0 = skia::textlayout::TextHeightBehavior::kAll; break;
        case 1: _a0 = skia::textlayout::TextHeightBehavior::kDisableFirstAscent; break;
        case 2: _a0 = skia::textlayout::TextHeightBehavior::kDisableLastDescent; break;
        case 3: _a0 = skia::textlayout::TextHeightBehavior::kDisableAll; break;
    }
    skia::textlayout::ParagraphStyle *_o0;
	FUZZ_ENDPOINT(_i0->setTextHeightBehavior(_a0);)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::~skia::textlayout::ParagraphStyle();) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::ParagraphStyle *_i0 = reinterpret_cast<skia::textlayout::ParagraphStyle *>(in_ref[0]);
	delete _i0;
	
	                
}


/* CPPScope(name=(auto) skia::textlayout::StrutStyle::skia::textlayout::StrutStyle();) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::StrutStyle *_o0;
	_o0 = new skia::textlayout::StrutStyle();
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) skia::textlayout::StrutStyle::~skia::textlayout::StrutStyle();) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::StrutStyle *_i0 = reinterpret_cast<skia::textlayout::StrutStyle *>(in_ref[0]);
	delete _i0;
	
	                
}


/* CPPScope(name=AddASCIIText) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::ParagraphBuilderImpl *_i0 = reinterpret_cast<skia::textlayout::ParagraphBuilderImpl *>(in_ref[0]);
    char _a0[255];
    memcpy(&_a0, context + 0, 1 * 255);
    int _a1;
    memcpy(&_a1, context + 255, sizeof(int));
    skia::textlayout::ParagraphBuilderImpl *_o0;
	unsigned int textSize = _a1 % 255;
	_i0->addText(_a0, textSize);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=AddUnicodeText) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::ParagraphBuilderImpl *_i0 = reinterpret_cast<skia::textlayout::ParagraphBuilderImpl *>(in_ref[0]);
    char16_t _a0[255];
    memcpy(&_a0, context + 0, 2 * 255);
    int _a1;
    memcpy(&_a1, context + 510, sizeof(int));
    skia::textlayout::ParagraphBuilderImpl *_o0;
	unsigned int textSize = _a1 % 255;
	_i0->addText(std::u16string(_a0, textSize));
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=AddZalgo) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::ParagraphBuilderImpl *_i0 = reinterpret_cast<skia::textlayout::ParagraphBuilderImpl *>(in_ref[0]);
    char _a0[255];
    memcpy(&_a0, context + 0, 1 * 255);
    int _a1;
    memcpy(&_a1, context + 255, sizeof(int));
    uint8_t _a2[512];
    memcpy(&_a2, context + 259, 1 * 512);
    skia::textlayout::ParagraphBuilderImpl *_o0;
	unsigned int textSize = _a1 % 255;
	Fuzz f(_a2, 512);
	AddZalgoText(_i0, _a0, textSize, &f);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphBuilderImpl::skia::textlayout::ParagraphBuilderImpl(const skia::textlayout::ParagraphStyle & style, {sk_make_sp<ResourceFontCollection>()});) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::ParagraphStyle *_i0 = reinterpret_cast<skia::textlayout::ParagraphStyle *>(in_ref[0]);
    skia::textlayout::ParagraphBuilderImpl *_o0;
    skia::textlayout::ParagraphStyle *_o1;
	_o0 = new skia::textlayout::ParagraphBuilderImpl(*_i0, sk_make_sp<ResourceFontCollection>());
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphBuilderImpl::void pushStyle(skia::textlayout::TextStyle None);) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::ParagraphBuilderImpl *_i0 = reinterpret_cast<skia::textlayout::ParagraphBuilderImpl *>(in_ref[0]);
    skia::textlayout::TextStyle *_i1 = reinterpret_cast<skia::textlayout::TextStyle *>(in_ref[1]);
    skia::textlayout::ParagraphBuilderImpl *_o0;
    skia::textlayout::TextStyle *_o1;
	FUZZ_ENDPOINT(_i0->pushStyle(*_i1);)
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphBuilderImpl::void pop();) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::ParagraphBuilderImpl *_i0 = reinterpret_cast<skia::textlayout::ParagraphBuilderImpl *>(in_ref[0]);
    skia::textlayout::ParagraphBuilderImpl *_o0;
	FUZZ_ENDPOINT(_i0->pop();)
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphBuilderImpl::~skia::textlayout::ParagraphBuilderImpl();) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::ParagraphBuilderImpl *_i0 = reinterpret_cast<skia::textlayout::ParagraphBuilderImpl *>(in_ref[0]);
	delete _i0;
	
	                
}


/* CPPScope(name=void setFontFamilies_fixed) */
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::TextStyle *_i0 = reinterpret_cast<skia::textlayout::TextStyle *>(in_ref[0]);
    skia::textlayout::TextStyle *_o0;
	_i0->setFontFamilies({SkString("Roboto")});
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) skia::textlayout::TextStyle::skia::textlayout::TextStyle();) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::TextStyle *_o0;
	_o0 = new skia::textlayout::TextStyle();
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) skia::textlayout::TextStyle::~skia::textlayout::TextStyle();) */
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
    skia::textlayout::TextStyle *_i0 = reinterpret_cast<skia::textlayout::TextStyle *>(in_ref[0]);
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
};

