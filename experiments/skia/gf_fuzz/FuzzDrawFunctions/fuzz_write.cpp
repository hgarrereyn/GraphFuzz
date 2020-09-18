

#include <string.h>
#include <string>
#include <iostream>

unsigned long CURR_ID = 0;

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) { }

extern "C" void __attribute__((visibility ("default"))) shim_init() {
    CURR_ID = 0;

    std::cout << "#include \"SkBitmap.h\"\n#include \"SkBlendMode.h\"\n#include \"SkCanvas.h\"\n#include \"SkClipOp.h\"\n#include \"SkFilterQuality.h\"\n#include \"SkFont.h\"\n#include \"SkImage.h\"\n#include \"SkImageInfo.h\"\n#include \"SkPaint.h\"\n#include \"SkPath.h\"\n#include \"SkRect.h\"\n#include \"SkSurface.h\"\n#include \"SkTextBlob.h\"\n#include \"SkTypeface.h\"\n" << std::endl;
    std::cout << "\n#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))\n\nstruct GFUZZ_BUNDLE {\npublic:\n    void *active;\n    void *inactive;\n    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}\n};\n\n#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)\n" << std::endl;

    std::cout << "int main() {" << std::endl;
}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {
    std::cout << "}" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::SkPaint();) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_0" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkPaint);\n        SkPaint ref = SkPaint();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_0" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setAntiAlias(bool aa);) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_1" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setAntiAlias(" << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_1" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setBlendMode(SkBlendMode mode);) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 32) {
        case 0: _a0 = "SkBlendMode::kClear"; break;
        case 1: _a0 = "SkBlendMode::kSrc"; break;
        case 2: _a0 = "SkBlendMode::kDst"; break;
        case 3: _a0 = "SkBlendMode::kSrcOver"; break;
        case 4: _a0 = "SkBlendMode::kDstOver"; break;
        case 5: _a0 = "SkBlendMode::kSrcIn"; break;
        case 6: _a0 = "SkBlendMode::kDstIn"; break;
        case 7: _a0 = "SkBlendMode::kSrcOut"; break;
        case 8: _a0 = "SkBlendMode::kDstOut"; break;
        case 9: _a0 = "SkBlendMode::kSrcATop"; break;
        case 10: _a0 = "SkBlendMode::kDstATop"; break;
        case 11: _a0 = "SkBlendMode::kXor"; break;
        case 12: _a0 = "SkBlendMode::kPlus"; break;
        case 13: _a0 = "SkBlendMode::kModulate"; break;
        case 14: _a0 = "SkBlendMode::kScreen"; break;
        case 15: _a0 = "SkBlendMode::kOverlay"; break;
        case 16: _a0 = "SkBlendMode::kDarken"; break;
        case 17: _a0 = "SkBlendMode::kLighten"; break;
        case 18: _a0 = "SkBlendMode::kColorDodge"; break;
        case 19: _a0 = "SkBlendMode::kColorBurn"; break;
        case 20: _a0 = "SkBlendMode::kHardLight"; break;
        case 21: _a0 = "SkBlendMode::kSoftLight"; break;
        case 22: _a0 = "SkBlendMode::kDifference"; break;
        case 23: _a0 = "SkBlendMode::kExclusion"; break;
        case 24: _a0 = "SkBlendMode::kMultiply"; break;
        case 25: _a0 = "SkBlendMode::kHue"; break;
        case 26: _a0 = "SkBlendMode::kSaturation"; break;
        case 27: _a0 = "SkBlendMode::kColor"; break;
        case 28: _a0 = "SkBlendMode::kLuminosity"; break;
        case 29: _a0 = "SkBlendMode::kLastCoeffMode"; break;
        case 30: _a0 = "SkBlendMode::kLastSeparableMode"; break;
        case 31: _a0 = "SkBlendMode::kLastMode"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_2" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setBlendMode(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_2" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setColor(SkColor color);) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_3" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setColor(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_3" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setDither(bool dither);) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_4" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setDither(" << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_4" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setStrokeCap(SkPaint::Cap cap);) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = "SkPaint::Cap::kButt_Cap"; break;
        case 1: _a0 = "SkPaint::Cap::kRound_Cap"; break;
        case 2: _a0 = "SkPaint::Cap::kSquare_Cap"; break;
        case 3: _a0 = "SkPaint::Cap::kLast_Cap"; break;
        case 4: _a0 = "SkPaint::Cap::kDefault_Cap"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_5" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setStrokeCap(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_5" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setStrokeJoin(SkPaint::Join join);) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = "SkPaint::Join::kMiter_Join"; break;
        case 1: _a0 = "SkPaint::Join::kRound_Join"; break;
        case 2: _a0 = "SkPaint::Join::kBevel_Join"; break;
        case 3: _a0 = "SkPaint::Join::kLast_Join"; break;
        case 4: _a0 = "SkPaint::Join::kDefault_Join"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_6" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setStrokeJoin(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_6" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setStrokeMiter(SkScalar miter);) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_7" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setStrokeMiter(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_7" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setStrokeWidth(SkScalar width);) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_8" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setStrokeWidth(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_8" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setStyle(SkPaint::Style style);) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 3) {
        case 0: _a0 = "SkPaint::Style::kFill_Style"; break;
        case 1: _a0 = "SkPaint::Style::kStroke_Style"; break;
        case 2: _a0 = "SkPaint::Style::kStrokeAndFill_Style"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_9" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setStyle(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_9" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::~SkPaint();) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_10" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_10" << std::endl;
}


/* CPPScope(name=(auto) SkImageInfo::SkImageInfo Make(int width, int height, SkColorType ct, SkAlphaType at);) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    const char *_a2;
    switch (*(reinterpret_cast<const unsigned char *>(context + 8)) % 22) {
        case 0: _a2 = "SkColorType::kUnknown_SkColorType"; break;
        case 1: _a2 = "SkColorType::kAlpha_8_SkColorType"; break;
        case 2: _a2 = "SkColorType::kRGB_565_SkColorType"; break;
        case 3: _a2 = "SkColorType::kARGB_4444_SkColorType"; break;
        case 4: _a2 = "SkColorType::kRGBA_8888_SkColorType"; break;
        case 5: _a2 = "SkColorType::kRGB_888x_SkColorType"; break;
        case 6: _a2 = "SkColorType::kBGRA_8888_SkColorType"; break;
        case 7: _a2 = "SkColorType::kRGBA_1010102_SkColorType"; break;
        case 8: _a2 = "SkColorType::kBGRA_1010102_SkColorType"; break;
        case 9: _a2 = "SkColorType::kRGB_101010x_SkColorType"; break;
        case 10: _a2 = "SkColorType::kBGR_101010x_SkColorType"; break;
        case 11: _a2 = "SkColorType::kGray_8_SkColorType"; break;
        case 12: _a2 = "SkColorType::kRGBA_F16Norm_SkColorType"; break;
        case 13: _a2 = "SkColorType::kRGBA_F16_SkColorType"; break;
        case 14: _a2 = "SkColorType::kRGBA_F32_SkColorType"; break;
        case 15: _a2 = "SkColorType::kR8G8_unorm_SkColorType"; break;
        case 16: _a2 = "SkColorType::kA16_float_SkColorType"; break;
        case 17: _a2 = "SkColorType::kR16G16_float_SkColorType"; break;
        case 18: _a2 = "SkColorType::kA16_unorm_SkColorType"; break;
        case 19: _a2 = "SkColorType::kR16G16_unorm_SkColorType"; break;
        case 20: _a2 = "SkColorType::kR16G16B16A16_unorm_SkColorType"; break;
        case 21: _a2 = "SkColorType::kLastEnum_SkColorType"; break;
    }
    const char *_a3;
    switch (*(reinterpret_cast<const unsigned char *>(context + 9)) % 5) {
        case 0: _a3 = "SkAlphaType::kUnknown_SkAlphaType"; break;
        case 1: _a3 = "SkAlphaType::kOpaque_SkAlphaType"; break;
        case 2: _a3 = "SkAlphaType::kPremul_SkAlphaType"; break;
        case 3: _a3 = "SkAlphaType::kUnpremul_SkAlphaType"; break;
        case 4: _a3 = "SkAlphaType::kLastEnum_SkAlphaType"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkImageInfo *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_11" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkImageInfo);\n        SkImageInfo ref = SkImageInfo::Make(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_11" << std::endl;
}


/* CPPScope(name=(auto) SkImageInfo::~SkImageInfo();) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_12" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_12" << std::endl;
}


/* CPPScope(name=sk_sp<SkImage> asImage()) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkBitmap *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_13" << std::endl;

    std::cout << "        " << "var_" << _o1 << " = MAKE(sk_sp<SkImage>);\n        *" << "var_" << _o1 << " = " << "var_" << _i0 << "->asImage();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_13" << std::endl;
}


/* CPPScope(name=(auto) SkBitmap::SkBitmap();) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkBitmap *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_14" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkBitmap);\n        SkBitmap ref = SkBitmap();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_14" << std::endl;
}


/* CPPScope(name=(auto) SkBitmap::bool tryAllocPixels(const SkImageInfo & info);) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkBitmap *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkImageInfo *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_15" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->tryAllocPixels(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_15" << std::endl;
}


/* CPPScope(name=(auto) SkBitmap::void eraseColor(SkColor c);) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkBitmap *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_16" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->eraseColor(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_16" << std::endl;
}


/* CPPScope(name=(auto) SkBitmap::~SkBitmap();) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_17" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_17" << std::endl;
}


/* CPPScope(name=make_surface) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    uint8_t _a1;
    memcpy(&_a1, context + 1, sizeof(uint8_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkSurface> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_18" << std::endl;

    std::cout << "        int width = (" << (int)_a0 << " % (250 - 1)) + 1;\n        int height = (" << (int)_a1 << " % (250 - 1)) + 1;\n        " << "var_" << _o0 << " = MAKE(sk_sp<SkSurface>);\n        *" << "var_" << _o0 << " = SkSurface::MakeRasterN32Premul(width, height);\n        if (!*" << "var_" << _o0 << ") {\n          *" << "var_" << _o0 << " = SkSurface::MakeNull(width, height);\n        }" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_18" << std::endl;
}


/* CPPScope(name=get_canvas) */
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_19" << std::endl;

    std::cout << "        SkCanvas *canvas = " << "var_" << _i0 << "->get()->getCanvas();\n        " << "var_" << _o0 << " = BUNDLE(canvas, " << "var_" << _i0 << ");" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_19" << std::endl;
}


/* CPPScope(name=delete) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_20" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    } // end shim_20" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkSurface>::~sk_sp<SkSurface>();) */
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_21" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_21" << std::endl;
}


/* CPPScope(name=(auto) SkFont::SkFont();) */
extern "C" void shim_22(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_22" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkFont);\n        SkFont ref = SkFont();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_22" << std::endl;
}


/* CPPScope(name=(auto) SkFont::SkFont(sk_sp<SkTypeface> typeface);) */
extern "C" void shim_23(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkTypeface> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_23" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkFont);\n        SkFont ref = SkFont(*" << "var_" << _i0 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_23" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setForceAutoHinting(bool forceAutoHinting);) */
extern "C" void shim_24(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_24" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setForceAutoHinting(" << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_24" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setEmbeddedBitmaps(bool embeddedBitmaps);) */
extern "C" void shim_25(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_25" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setEmbeddedBitmaps(" << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_25" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setEmbolden(bool embolden);) */
extern "C" void shim_26(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_26" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setEmbolden(" << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_26" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setEdging(SkFont::Edging edging);) */
extern "C" void shim_27(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 3) {
        case 0: _a0 = "SkFont::Edging::kAlias"; break;
        case 1: _a0 = "SkFont::Edging::kAntiAlias"; break;
        case 2: _a0 = "SkFont::Edging::kSubpixelAntiAlias"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_27" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setEdging(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_27" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setLinearMetrics(bool linearMetrics);) */
extern "C" void shim_28(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_28" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setLinearMetrics(" << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_28" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setSubpixel(bool subpixel);) */
extern "C" void shim_29(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_29" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setSubpixel(" << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_29" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setScaleX(SkScalar scaleX);) */
extern "C" void shim_30(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_30" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setScaleX(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_30" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setSkewX(SkScalar skewX);) */
extern "C" void shim_31(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_31" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setSkewX(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_31" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setSize(SkScalar textSize);) */
extern "C" void shim_32(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_32" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setSize(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_32" << std::endl;
}


/* CPPScope(name=(auto) SkFont::~SkFont();) */
extern "C" void shim_33(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_33" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_33" << std::endl;
}


/* CPPScope(name=sk_sp<SkTypeface> MakeDefault()) */
extern "C" void shim_34(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkTypeface> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_34" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkTypeface>);\n        *" << "var_" << _o0 << " = SkTypeface::MakeDefault();\n        if (*" << "var_" << _o0 << " == nullptr) abort();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_34" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkTypeface>::~sk_sp<SkTypeface>();) */
extern "C" void shim_35(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_35" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_35" << std::endl;
}


/* CPPScope(name=drawImageRect) */
extern "C" void shim_36(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _i4 = reinterpret_cast<unsigned long>(in_ref[4]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkCanvas::SrcRectConstraint::kStrict_SrcRectConstraint"; break;
        case 1: _a0 = "SkCanvas::SrcRectConstraint::kFast_SrcRectConstraint"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o3 << ";" << std::endl;
    unsigned long _o4 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o4 << ";" << std::endl;

    std::cout << "    { // begin shim_36" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->drawImageRect(" << "var_" << _i1 << "->get(), *" << "var_" << _i2 << ", *" << "var_" << _i3 << ", SkSamplingOptions(), " << "var_" << _i4 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";\n        " << "var_" << _o4 << " = " << "var_" << _i4 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);

    std::cout << "    } // end shim_36" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawCircle(SkScalar cx, SkScalar cy, SkScalar radius, const SkPaint & paint);) */
extern "C" void shim_37(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_37" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawCircle(" << _a0 << ", " << _a1 << ", " << _a2 << ", *" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_37" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawLine(SkScalar x0, SkScalar y0, SkScalar x1, SkScalar y1, const SkPaint & paint);) */
extern "C" void shim_38(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_38" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawLine(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", *" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_38" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawRect(const SkRect & rect, const SkPaint & paint);) */
extern "C" void shim_39(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_39" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawRect(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_39" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void clipRect(const SkRect & rect, SkClipOp op, bool doAntiAlias);) */
extern "C" void shim_40(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 7) {
        case 0: _a0 = "SkClipOp::kDifference"; break;
        case 1: _a0 = "SkClipOp::kIntersect"; break;
        case 2: _a0 = "SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway2"; break;
        case 3: _a0 = "SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway3"; break;
        case 4: _a0 = "SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway4"; break;
        case 5: _a0 = "SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway5"; break;
        case 6: _a0 = "SkClipOp::kMax_EnumValue"; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_40" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->clipRect(*" << "var_" << _i1 << ", " << _a0 << ", " << (int)_a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_40" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawPath(const SkPath & path, const SkPaint & paint);) */
extern "C" void shim_41(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_41" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawPath(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_41" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void clipPath(const SkPath & path, SkClipOp op, bool doAntiAlias);) */
extern "C" void shim_42(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 7) {
        case 0: _a0 = "SkClipOp::kDifference"; break;
        case 1: _a0 = "SkClipOp::kIntersect"; break;
        case 2: _a0 = "SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway2"; break;
        case 3: _a0 = "SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway3"; break;
        case 4: _a0 = "SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway4"; break;
        case 5: _a0 = "SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway5"; break;
        case 6: _a0 = "SkClipOp::kMax_EnumValue"; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_42" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->clipPath(*" << "var_" << _i1 << ", " << _a0 << ", " << (int)_a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_42" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawPaint(const SkPaint & paint);) */
extern "C" void shim_43(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_43" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawPaint(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_43" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawImage(const sk_sp<SkImage> & image, SkScalar x, SkScalar y, {SkSamplingOptions()}, const SkPaint * paint);) */
extern "C" void shim_44(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_44" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawImage(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", SkSamplingOptions(), " << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_44" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawImage(const sk_sp<SkImage> & image, SkScalar x, SkScalar y, {SkSamplingOptions()}, {nullptr});) */
extern "C" void shim_45(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_45" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawImage(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", SkSamplingOptions(), nullptr);)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_45" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawTextBlob(const sk_sp<SkTextBlob> & blob, SkScalar x, SkScalar y, const SkPaint & paint);) */
extern "C" void shim_46(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkTextBlob> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_46" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawTextBlob(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_46" << std::endl;
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
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_47" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkRect);\n        SkRect ref = SkRect::MakeXYWH(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_47" << std::endl;
}


/* CPPScope(name=(auto) SkRect::constexpr SkRect MakeWH(SkScalar w, SkScalar h);) */
extern "C" void shim_48(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_48" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkRect);\n        SkRect ref = SkRect::MakeWH(" << _a0 << ", " << _a1 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_48" << std::endl;
}


/* CPPScope(name=(auto) SkRect::~SkRect();) */
extern "C" void shim_49(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_49" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_49" << std::endl;
}


/* CPPScope(name=(auto) SkPath::SkPath();) */
extern "C" void shim_50(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_50" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkPath);\n        SkPath ref = SkPath();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_50" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void moveTo(SkScalar x, SkScalar y);) */
extern "C" void shim_51(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_51" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->moveTo(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_51" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void lineTo(SkScalar x, SkScalar y);) */
extern "C" void shim_52(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_52" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->lineTo(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_52" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void quadTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2);) */
extern "C" void shim_53(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_53" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->quadTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_53" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void conicTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w);) */
extern "C" void shim_54(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
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
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_54" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->conicTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_54" << std::endl;
}


/* CPPScope(name=(auto) SkPath::SkPath & cubicTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3);) */
extern "C" void shim_55(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
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
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_55" << std::endl;

    std::cout << "        " << "var_" << _o1 << " = MAKE(SkPath);\n        *" << "var_" << _o1 << " = " << "var_" << _i0 << "->cubicTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ", " << _a5 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_55" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void arcTo(SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar radius);) */
extern "C" void shim_56(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
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
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_56" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->arcTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_56" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void close();) */
extern "C" void shim_57(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_57" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->close();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_57" << std::endl;
}


/* CPPScope(name=(auto) SkPath::~SkPath();) */
extern "C" void shim_58(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_58" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_58" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImage>::~sk_sp<SkImage>();) */
extern "C" void shim_59(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_59" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_59" << std::endl;
}


/* CPPScope(name=sk_sp<SkTextBlob> MakeFromPosText(const void *text, size_t byteLength, const SkPoint pos[], const SkFont &font)) */
extern "C" void shim_60(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
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
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkTextBlob> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_60" << std::endl;

    std::cout << "        char text[5];\n        text[0] = " << (int)_a0 << ";\n        text[1] = " << (int)_a1 << ";\n        text[2] = " << (int)_a2 << ";\n        text[3] = " << (int)_a3 << ";\n        text[4] = " << (int)_a4 << ";\n        SkPoint pts[5];\n        pts[0].set(" << _a5 << "," << _a6 << ");\n        pts[1].set(" << _a7 << "," << _a8 << ");\n        pts[2].set(" << _a9 << "," << _a10 << ");\n        pts[3].set(" << _a11 << "," << _a12 << ");\n        pts[4].set(" << _a13 << "," << _a14 << ");\n        " << "var_" << _o1 << " = MAKE(sk_sp<SkTextBlob>);\n        *" << "var_" << _o1 << " = SkTextBlob::MakeFromPosText(text, 4, pts, *" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_60" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkTextBlob>::~sk_sp<SkTextBlob>();) */
extern "C" void shim_61(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_61" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_61" << std::endl;
}


/* CPPScope(name=bundled_drawImageRect) */
extern "C" void shim_62(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _i4 = reinterpret_cast<unsigned long>(in_ref[4]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkCanvas::SrcRectConstraint::kStrict_SrcRectConstraint"; break;
        case 1: _a0 = "SkCanvas::SrcRectConstraint::kFast_SrcRectConstraint"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o3 << ";" << std::endl;
    unsigned long _o4 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o4 << ";" << std::endl;

    std::cout << "    { // begin shim_62" << std::endl;

    std::cout << "        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawImageRect(" << "var_" << _i1 << "->get(), *" << "var_" << _i2 << ", *" << "var_" << _i3 << ", SkSamplingOptions(), " << "var_" << _i4 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";\n        " << "var_" << _o4 << " = " << "var_" << _i4 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);

    std::cout << "    } // end shim_62" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawCircle(SkScalar cx, SkScalar cy, SkScalar radius, const SkPaint & paint);) */
extern "C" void shim_63(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_63" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawCircle(" << _a0 << ", " << _a1 << ", " << _a2 << ", *" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_63" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawLine(SkScalar x0, SkScalar y0, SkScalar x1, SkScalar y1, const SkPaint & paint);) */
extern "C" void shim_64(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_64" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawLine(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", *" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_64" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRect(const SkRect & rect, const SkPaint & paint);) */
extern "C" void shim_65(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_65" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawRect(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_65" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipRect(const SkRect & rect, SkClipOp op, bool doAntiAlias);) */
extern "C" void shim_66(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 7) {
        case 0: _a0 = "SkClipOp::kDifference"; break;
        case 1: _a0 = "SkClipOp::kIntersect"; break;
        case 2: _a0 = "SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway2"; break;
        case 3: _a0 = "SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway3"; break;
        case 4: _a0 = "SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway4"; break;
        case 5: _a0 = "SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway5"; break;
        case 6: _a0 = "SkClipOp::kMax_EnumValue"; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_66" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->clipRect(*" << "var_" << _i1 << ", " << _a0 << ", " << (int)_a1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_66" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPath(const SkPath & path, const SkPaint & paint);) */
extern "C" void shim_67(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_67" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPath(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_67" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipPath(const SkPath & path, SkClipOp op, bool doAntiAlias);) */
extern "C" void shim_68(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 7) {
        case 0: _a0 = "SkClipOp::kDifference"; break;
        case 1: _a0 = "SkClipOp::kIntersect"; break;
        case 2: _a0 = "SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway2"; break;
        case 3: _a0 = "SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway3"; break;
        case 4: _a0 = "SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway4"; break;
        case 5: _a0 = "SkClipOp::kExtraEnumNeedInternallyPleaseIgnoreWillGoAway5"; break;
        case 6: _a0 = "SkClipOp::kMax_EnumValue"; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_68" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->clipPath(*" << "var_" << _i1 << ", " << _a0 << ", " << (int)_a1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_68" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPaint(const SkPaint & paint);) */
extern "C" void shim_69(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_69" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPaint(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_69" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawImage(const sk_sp<SkImage> & image, SkScalar x, SkScalar y, {SkSamplingOptions()}, const SkPaint * paint);) */
extern "C" void shim_70(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_70" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawImage(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", SkSamplingOptions(), " << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_70" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawImage(const sk_sp<SkImage> & image, SkScalar x, SkScalar y, {SkSamplingOptions()}, {nullptr});) */
extern "C" void shim_71(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_71" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawImage(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", SkSamplingOptions(), nullptr);)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_71" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawTextBlob(const sk_sp<SkTextBlob> & blob, SkScalar x, SkScalar y, const SkPaint & paint);) */
extern "C" void shim_72(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkTextBlob> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_72" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawTextBlob(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_72" << std::endl;
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

