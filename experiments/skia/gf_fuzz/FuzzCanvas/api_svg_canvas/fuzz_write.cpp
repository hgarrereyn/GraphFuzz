

#include <string.h>
#include <string>
#include <iostream>

unsigned long CURR_ID = 0;

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) { }

extern "C" void __attribute__((visibility ("default"))) shim_init() {
    CURR_ID = 0;

    std::cout << "#include \"Sk1DPathEffect.h\"\n#include \"Sk2DPathEffect.h\"\n#include \"SkBlendMode.h\"\n#include \"SkBlurTypes.h\"\n#include \"SkCanvas.h\"\n#include \"SkClipOp.h\"\n#include \"SkColor.h\"\n#include \"SkColorFilter.h\"\n#include \"SkColorMatrixFilter.h\"\n#include \"SkCornerPathEffect.h\"\n#include \"SkDashPathEffect.h\"\n#include \"SkDiscretePathEffect.h\"\n#include \"SkFilterQuality.h\"\n#include \"SkFont.h\"\n#include \"SkFontMgr.h\"\n#include \"SkFontTypes.h\"\n#include \"SkGradientShader.h\"\n#include \"SkHighContrastFilter.h\"\n#include \"SkImage.h\"\n#include \"SkImageFilter.h\"\n#include \"SkImageFilters.h\"\n#include \"SkLumaColorFilter.h\"\n#include \"SkMaskFilter.h\"\n#include \"SkMatrix.h\"\n#include \"SkPaint.h\"\n#include \"SkPath.h\"\n#include \"SkPathEffect.h\"\n#include \"SkPathTypes.h\"\n#include \"SkPerlinNoiseShader.h\"\n#include \"SkPicture.h\"\n#include \"SkPictureRecorder.h\"\n#include \"SkPoint.h\"\n#include \"SkPoint3.h\"\n#include \"SkRRect.h\"\n#include \"SkRect.h\"\n#include \"SkRegion.h\"\n#include \"SkShader.h\"\n#include \"SkSize.h\"\n#include \"SkTableColorFilter.h\"\n#include \"SkTextBlob.h\"\n#include \"SkTileMode.h\"\n#include \"SkTypeface.h\"\n#include \"SkVertices.h\"\n#include \"fuzz_util.h\"\n#include \"include/svg/SkSVGCanvas.h\"\n#include \"private/SkTemplates.h\"\n" << std::endl;
    std::cout << "\n#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))\n\nstruct GFUZZ_BUNDLE {\npublic:\n    void *active;\n    void *inactive;\n    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}\n};\n\n#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)\n" << std::endl;

    std::cout << "int main() {" << std::endl;
}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {
    std::cout << "}" << std::endl;
}


/* CPPScope(name=api_null_canvas) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_0" << std::endl;

    std::cout << "        SkNullWStream *stream = new SkNullWStream();\n        SkRect bounds = SkRect::MakeIWH(150, 150);\n        std::unique_ptr<SkCanvas> *parent = MAKE(std::unique_ptr<SkCanvas>);\n        *parent = SkSVGCanvas::Make(bounds, stream);\n        SkCanvas *canvas = parent->get();\n        " << "var_" << _o0 << " = BUNDLE(canvas, parent);" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_0" << std::endl;
}


/* CPPScope(name=delete) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_1" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    } // end shim_1" << std::endl;
}


/* CPPScope(name=(auto) SkPoint::SkPoint Make(SkScalar x, SkScalar y);) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPoint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_2" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkPoint);\n        SkPoint ref = SkPoint::Make(" << _a0 << ", " << _a1 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_2" << std::endl;
}


/* CPPScope(name=(auto) SkPoint::~SkPoint();) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_3" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_3" << std::endl;
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
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_4" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkIRect);\n        SkIRect ref = SkIRect::MakeXYWH(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_4" << std::endl;
}


/* CPPScope(name=(auto) SkIRect::~SkIRect();) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_5" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_5" << std::endl;
}


/* CPPScope(name=(auto) SkISize::SkISize Make(int32_t w, int32_t h);) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    int32_t _a0;
    memcpy(&_a0, context + 0, sizeof(int32_t));
    int32_t _a1;
    memcpy(&_a1, context + 4, sizeof(int32_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkISize *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_6" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkISize);\n        SkISize ref = SkISize::Make(" << _a0 << ", " << _a1 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_6" << std::endl;
}


/* CPPScope(name=(auto) SkISize::~SkISize();) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_7" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_7" << std::endl;
}


/* CPPScope(name=make) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
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
    float _a6;
    memcpy(&_a6, context + 24, sizeof(float));
    float _a7;
    memcpy(&_a7, context + 28, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkRRect *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_8" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkRRect);\n        *" << "var_" << _o0 << " = SkRRect();\n        SkVector radii[4] = {\n          SkPoint::Make(" << _a0 << "," << _a1 << "),\n          SkPoint::Make(" << _a2 << "," << _a3 << "),\n          SkPoint::Make(" << _a4 << "," << _a5 << "),\n          SkPoint::Make(" << _a6 << "," << _a7 << ")\n        };\n        " << "var_" << _o0 << "->setRectRadii(*" << "var_" << _i0 << ", radii);\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_8" << std::endl;
}


/* CPPScope(name=(auto) SkRRect::~SkRRect();) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_9" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_9" << std::endl;
}


/* CPPScope(name=(auto) SkRegion::SkRegion();) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_10" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkRegion);\n        SkRegion ref = SkRegion();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_10" << std::endl;
}


/* CPPScope(name=(auto) SkRegion::void op(SkIRect None, SkRegion::Op None);) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 7) {
        case 0: _a0 = "SkRegion::Op::kDifference_Op"; break;
        case 1: _a0 = "SkRegion::Op::kIntersect_Op"; break;
        case 2: _a0 = "SkRegion::Op::kUnion_Op"; break;
        case 3: _a0 = "SkRegion::Op::kXOR_Op"; break;
        case 4: _a0 = "SkRegion::Op::kReverseDifference_Op"; break;
        case 5: _a0 = "SkRegion::Op::kReplace_Op"; break;
        case 6: _a0 = "SkRegion::Op::kLastOp"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_11" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->op(*" << "var_" << _i1 << ", " << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_11" << std::endl;
}


/* CPPScope(name=(auto) SkRegion::~SkRegion();) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_12" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_12" << std::endl;
}


/* CPPScope(name=void setAffine(SkScalar[6])) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_13" << std::endl;
    float _a0[6];
    memcpy(&_a0, context + 0, 4 * 6);
    std::cout << "    float _a0[6] = {";
    for (int i = 0; i < 6; ++i) {
        if (i % 16 == 0 && 6 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 6 - 1) std::cout << ", ";
    }
    if (6 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setAffine(" << "_a0" << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_13" << std::endl;
}


/* CPPScope(name=void set9(SkScalar[9])) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_14" << std::endl;
    float _a0[9];
    memcpy(&_a0, context + 0, 4 * 9);
    std::cout << "    float _a0[9] = {";
    for (int i = 0; i < 9; ++i) {
        if (i % 16 == 0 && 9 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 9 - 1) std::cout << ", ";
    }
    if (9 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->set9(" << "_a0" << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_14" << std::endl;
}


/* CPPScope(name=(auto) SkMatrix::void postTranslate(SkScalar None, SkScalar None);) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_15" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->postTranslate(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_15" << std::endl;
}


/* CPPScope(name=(auto) SkMatrix::SkMatrix I();) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_16" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkMatrix);\n        SkMatrix ref = SkMatrix::I();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_16" << std::endl;
}


/* CPPScope(name=(auto) SkMatrix::SkMatrix Translate(SkScalar None, SkScalar None);) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_17" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkMatrix);\n        SkMatrix ref = SkMatrix::Translate(" << _a0 << ", " << _a1 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_17" << std::endl;
}


/* CPPScope(name=(auto) SkMatrix::SkMatrix Scale(SkScalar None, SkScalar None);) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_18" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkMatrix);\n        SkMatrix ref = SkMatrix::Scale(" << _a0 << ", " << _a1 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_18" << std::endl;
}


/* CPPScope(name=(auto) SkMatrix::~SkMatrix();) */
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_19" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_19" << std::endl;
}


/* CPPScope(name=add_self_path_matrix) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkPath::AddPathMode::kAppend_AddPathMode"; break;
        case 1: _a0 = "SkPath::AddPathMode::kExtend_AddPathMode"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_20" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->addPath(*" << "var_" << _i0 << ", *" << "var_" << _i1 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_20" << std::endl;
}


/* CPPScope(name=add_self_path) */
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_21" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->addPath(*" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_21" << std::endl;
}


/* CPPScope(name=add_self_path_reverse) */
extern "C" void shim_22(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_22" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->reverseAddPath(*" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_22" << std::endl;
}


/* CPPScope(name=offset_self) */
extern "C" void shim_23(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_23" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->offset(" << _a0 << ", " << _a1 << ", " << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_23" << std::endl;
}


/* CPPScope(name=transform_self) */
extern "C" void shim_24(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_24" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->transform(*" << "var_" << _i1 << ", " << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_24" << std::endl;
}


/* CPPScope(name=(auto) SkPath::SkPath();) */
extern "C" void shim_25(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_25" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkPath);\n        SkPath ref = SkPath();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_25" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void moveTo(SkScalar None, SkScalar None);) */
extern "C" void shim_26(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_26" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->moveTo(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_26" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void rMoveTo(SkScalar None, SkScalar None);) */
extern "C" void shim_27(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_27" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->rMoveTo(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_27" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void lineTo(SkScalar None, SkScalar None);) */
extern "C" void shim_28(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_28" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->lineTo(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_28" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void rLineTo(SkScalar None, SkScalar None);) */
extern "C" void shim_29(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_29" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->rLineTo(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_29" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void quadTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_30(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_30" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->quadTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_30" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void rQuadTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_31(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_31" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->rQuadTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_31" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void conicTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_32(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_32" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->conicTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_32" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void rConicTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_33(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_33" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->rConicTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_33" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void cubicTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_34(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_34" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->cubicTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ", " << _a5 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_34" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void rCubicTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_35(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_35" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->rCubicTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ", " << _a5 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_35" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void arcTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_36(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_36" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->arcTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_36" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void arcTo(SkRect None, SkScalar None, SkScalar None, bool None);) */
extern "C" void shim_37(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_37" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->arcTo(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", " << (int)_a2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_37" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void close();) */
extern "C" void shim_38(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_38" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->close();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_38" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addRect(SkRect None, SkPathDirection None);) */
extern "C" void shim_39(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkPathDirection::kCW"; break;
        case 1: _a0 = "SkPathDirection::kCCW"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_39" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addRect(*" << "var_" << _i1 << ", " << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_39" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addRect(SkRect None, SkPathDirection None, unsigned int None);) */
extern "C" void shim_40(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkPathDirection::kCW"; break;
        case 1: _a0 = "SkPathDirection::kCCW"; break;
    }
    int _a1;
    memcpy(&_a1, context + 1, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_40" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addRect(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_40" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addOval(SkRect None, SkPathDirection None);) */
extern "C" void shim_41(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkPathDirection::kCW"; break;
        case 1: _a0 = "SkPathDirection::kCCW"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_41" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addOval(*" << "var_" << _i1 << ", " << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_41" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addOval(SkRect None, SkPathDirection None, unsigned int None);) */
extern "C" void shim_42(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkPathDirection::kCW"; break;
        case 1: _a0 = "SkPathDirection::kCCW"; break;
    }
    int _a1;
    memcpy(&_a1, context + 1, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_42" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addOval(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_42" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addCircle(SkScalar None, SkScalar None, SkScalar None, SkPathDirection None);) */
extern "C" void shim_43(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    const char *_a3;
    switch (*(reinterpret_cast<const unsigned char *>(context + 12)) % 2) {
        case 0: _a3 = "SkPathDirection::kCW"; break;
        case 1: _a3 = "SkPathDirection::kCCW"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_43" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addCircle(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_43" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addArc(SkRect None, SkScalar None, SkScalar None);) */
extern "C" void shim_44(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_44" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addArc(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_44" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addRoundRect(SkRect None, SkScalar None, SkScalar None, SkPathDirection None);) */
extern "C" void shim_45(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    const char *_a2;
    switch (*(reinterpret_cast<const unsigned char *>(context + 8)) % 2) {
        case 0: _a2 = "SkPathDirection::kCW"; break;
        case 1: _a2 = "SkPathDirection::kCCW"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_45" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addRoundRect(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", " << _a2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_45" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addRRect(SkRRect None, SkPathDirection None);) */
extern "C" void shim_46(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkPathDirection::kCW"; break;
        case 1: _a0 = "SkPathDirection::kCCW"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_46" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addRRect(*" << "var_" << _i1 << ", " << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_46" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addRRect(SkRRect None, SkPathDirection None, unsigned int None);) */
extern "C" void shim_47(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkPathDirection::kCW"; break;
        case 1: _a0 = "SkPathDirection::kCCW"; break;
    }
    int _a1;
    memcpy(&_a1, context + 1, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_47" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addRRect(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_47" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addPath(SkPath None, SkMatrix None, SkPath::AddPathMode None);) */
extern "C" void shim_48(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkPath::AddPathMode::kAppend_AddPathMode"; break;
        case 1: _a0 = "SkPath::AddPathMode::kExtend_AddPathMode"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_48" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addPath(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ", " << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_48" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void reverseAddPath(SkPath None);) */
extern "C" void shim_49(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_49" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->reverseAddPath(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_49" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void offset(SkScalar None, SkScalar None, SkPath * None);) */
extern "C" void shim_50(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_50" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->offset(" << _a0 << ", " << _a1 << ", " << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_50" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void transform(SkMatrix None, SkPath * None);) */
extern "C" void shim_51(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_51" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->transform(*" << "var_" << _i1 << ", " << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_51" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void setLastPt(SkScalar None, SkScalar None);) */
extern "C" void shim_52(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_52" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setLastPt(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_52" << std::endl;
}


/* CPPScope(name=(auto) SkPath::~SkPath();) */
extern "C" void shim_53(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_53" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_53" << std::endl;
}


/* CPPScope(name=make_fuzz_image) */
extern "C" void shim_54(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_54" << std::endl;
    uint16_t _a0[2];
    memcpy(&_a0, context + 0, 2 * 2);
    std::cout << "    uint16_t _a0[2] = {";
    for (int i = 0; i < 2; ++i) {
        if (i % 16 == 0 && 2 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 2 - 1) std::cout << ", ";
    }
    if (2 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint32_t _a1[64];
    memcpy(&_a1, context + 4, 4 * 64);
    std::cout << "    uint32_t _a1[64] = {";
    for (int i = 0; i < 64; ++i) {
        if (i % 16 == 0 && 64 > 16) std::cout << std::endl << "        ";
        std::cout << _a1[i];
        if (i < 64 - 1) std::cout << ", ";
    }
    if (64 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint32_t _a2[64];
    memcpy(&_a2, context + 260, 4 * 64);
    std::cout << "    uint32_t _a2[64] = {";
    for (int i = 0; i < 64; ++i) {
        if (i % 16 == 0 && 64 > 16) std::cout << std::endl << "        ";
        std::cout << _a2[i];
        if (i < 64 - 1) std::cout << ", ";
    }
    if (64 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImage>);\n        unsigned int w = " << "_a0" << "[0];\n        unsigned int h = " << "_a0" << "[1];\n        SkAutoTMalloc<SkPMColor> data(w * h);\n        SkPixmap pixmap(SkImageInfo::MakeN32Premul(w, h), data.get(), w * sizeof(SkPMColor));\n        int n = w * h;\n        if (n > 0) {\n          for (int i = 0; i < 64; ++i) {\n            data[" << "_a1" << "[i] % n] = SkPreMultiplyColor(" << "_a2" << "[i]);\n          }\n        }\n        (void)data.release();\n        *" << "var_" << _o0 << " = SkImage::MakeFromRaster(pixmap, [](const void* p, void*) { sk_free((void*)p); }, nullptr);" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_54" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImage>::~sk_sp<SkImage>();) */
extern "C" void shim_55(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_55" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_55" << std::endl;
}


/* CPPScope(name=nullptr) */
extern "C" void shim_56(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkColorFilter> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_56" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkColorFilter>);" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_56" << std::endl;
}


/* CPPScope(name=sk_sp<SkColorFilter> makeComposed) */
extern "C" void shim_57(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkColorFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkColorFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkColorFilter> *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_57" << std::endl;

    std::cout << "        " << "var_" << _o2 << " = MAKE(sk_sp<SkColorFilter>);\n        if (*" << "var_" << _i0 << " != nullptr) *" << "var_" << _o2 << " = (*" << "var_" << _i0 << ")->makeComposed(*" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_57" << std::endl;
}


/* CPPScope(name=SkColorFilters::Matrix) */
extern "C" void shim_58(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkColorFilter> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_58" << std::endl;
    float _a0[20];
    memcpy(&_a0, context + 0, 4 * 20);
    std::cout << "    float _a0[20] = {";
    for (int i = 0; i < 20; ++i) {
        if (i % 16 == 0 && 20 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 20 - 1) std::cout << ", ";
    }
    if (20 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkColorFilter>);\n        *" << "var_" << _o0 << " = SkColorFilters::Matrix(" << "_a0" << ");" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_58" << std::endl;
}


/* CPPScope(name=SkHighContrastFilter::Make) */
extern "C" void shim_59(void **in_ref, void **out_ref, const char *context) {
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 1)) % 3) {
        case 0: _a1 = "SkHighContrastConfig::InvertStyle::kNoInvert"; break;
        case 1: _a1 = "SkHighContrastConfig::InvertStyle::kInvertBrightness"; break;
        case 2: _a1 = "SkHighContrastConfig::InvertStyle::kInvertLightness"; break;
    }
    float _a2;
    memcpy(&_a2, context + 2, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkColorFilter> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_59" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkColorFilter>);\n        *" << "var_" << _o0 << " = SkHighContrastFilter::Make(SkHighContrastConfig(" << (int)_a0 << ", " << _a1 << ", " << _a2 << "));" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_59" << std::endl;
}


/* CPPScope(name=sk_sp<SkColorFilter> SkTableColorFilter::Make) */
extern "C" void shim_60(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkColorFilter> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_60" << std::endl;
    uint8_t _a0[256];
    memcpy(&_a0, context + 0, 1 * 256);
    std::cout << "    uint8_t _a0[256] = {";
    for (int i = 0; i < 256; ++i) {
        if (i % 16 == 0 && 256 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 256 - 1) std::cout << ", ";
    }
    if (256 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkColorFilter>);\n        *" << "var_" << _o0 << " = SkTableColorFilter::Make(" << "_a0" << ");" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_60" << std::endl;
}


/* CPPScope(name=sk_sp<SkColorFilter> SkTableColorFilter::MakeARGB) */
extern "C" void shim_61(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkColorFilter> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_61" << std::endl;
    uint8_t _a0[256];
    memcpy(&_a0, context + 0, 1 * 256);
    std::cout << "    uint8_t _a0[256] = {";
    for (int i = 0; i < 256; ++i) {
        if (i % 16 == 0 && 256 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 256 - 1) std::cout << ", ";
    }
    if (256 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint8_t _a1[256];
    memcpy(&_a1, context + 256, 1 * 256);
    std::cout << "    uint8_t _a1[256] = {";
    for (int i = 0; i < 256; ++i) {
        if (i % 16 == 0 && 256 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a1[i];
        if (i < 256 - 1) std::cout << ", ";
    }
    if (256 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint8_t _a2[256];
    memcpy(&_a2, context + 512, 1 * 256);
    std::cout << "    uint8_t _a2[256] = {";
    for (int i = 0; i < 256; ++i) {
        if (i % 16 == 0 && 256 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a2[i];
        if (i < 256 - 1) std::cout << ", ";
    }
    if (256 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint8_t _a3[256];
    memcpy(&_a3, context + 768, 1 * 256);
    std::cout << "    uint8_t _a3[256] = {";
    for (int i = 0; i < 256; ++i) {
        if (i % 16 == 0 && 256 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a3[i];
        if (i < 256 - 1) std::cout << ", ";
    }
    if (256 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkColorFilter>);\n        *" << "var_" << _o0 << " = SkTableColorFilter::MakeARGB(" << "_a0" << ", " << "_a1" << ", " << "_a2" << ", " << "_a3" << ");" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_61" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkColorFilter>::sk_sp<SkColorFilter> SkColorFilters::Blend(SkColor None, SkBlendMode None);) */
extern "C" void shim_62(void **in_ref, void **out_ref, const char *context) {
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 4)) % 32) {
        case 0: _a1 = "SkBlendMode::kClear"; break;
        case 1: _a1 = "SkBlendMode::kSrc"; break;
        case 2: _a1 = "SkBlendMode::kDst"; break;
        case 3: _a1 = "SkBlendMode::kSrcOver"; break;
        case 4: _a1 = "SkBlendMode::kDstOver"; break;
        case 5: _a1 = "SkBlendMode::kSrcIn"; break;
        case 6: _a1 = "SkBlendMode::kDstIn"; break;
        case 7: _a1 = "SkBlendMode::kSrcOut"; break;
        case 8: _a1 = "SkBlendMode::kDstOut"; break;
        case 9: _a1 = "SkBlendMode::kSrcATop"; break;
        case 10: _a1 = "SkBlendMode::kDstATop"; break;
        case 11: _a1 = "SkBlendMode::kXor"; break;
        case 12: _a1 = "SkBlendMode::kPlus"; break;
        case 13: _a1 = "SkBlendMode::kModulate"; break;
        case 14: _a1 = "SkBlendMode::kScreen"; break;
        case 15: _a1 = "SkBlendMode::kOverlay"; break;
        case 16: _a1 = "SkBlendMode::kDarken"; break;
        case 17: _a1 = "SkBlendMode::kLighten"; break;
        case 18: _a1 = "SkBlendMode::kColorDodge"; break;
        case 19: _a1 = "SkBlendMode::kColorBurn"; break;
        case 20: _a1 = "SkBlendMode::kHardLight"; break;
        case 21: _a1 = "SkBlendMode::kSoftLight"; break;
        case 22: _a1 = "SkBlendMode::kDifference"; break;
        case 23: _a1 = "SkBlendMode::kExclusion"; break;
        case 24: _a1 = "SkBlendMode::kMultiply"; break;
        case 25: _a1 = "SkBlendMode::kHue"; break;
        case 26: _a1 = "SkBlendMode::kSaturation"; break;
        case 27: _a1 = "SkBlendMode::kColor"; break;
        case 28: _a1 = "SkBlendMode::kLuminosity"; break;
        case 29: _a1 = "SkBlendMode::kLastCoeffMode"; break;
        case 30: _a1 = "SkBlendMode::kLastSeparableMode"; break;
        case 31: _a1 = "SkBlendMode::kLastMode"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkColorFilter> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_62" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkColorFilter>);\n        sk_sp<SkColorFilter> ref = SkColorFilters::Blend(" << _a0 << ", " << _a1 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_62" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkColorFilter>::sk_sp<SkColorFilter> SkColorMatrixFilter::MakeLightingFilter(SkColor None, SkColor None);) */
extern "C" void shim_63(void **in_ref, void **out_ref, const char *context) {
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    uint32_t _a1;
    memcpy(&_a1, context + 4, sizeof(uint32_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkColorFilter> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_63" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkColorFilter>);\n        sk_sp<SkColorFilter> ref = SkColorMatrixFilter::MakeLightingFilter(" << _a0 << ", " << _a1 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_63" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkColorFilter>::sk_sp<SkColorFilter> SkLumaColorFilter::Make();) */
extern "C" void shim_64(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkColorFilter> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_64" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkColorFilter>);\n        sk_sp<SkColorFilter> ref = SkLumaColorFilter::Make();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_64" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkColorFilter>::~sk_sp<SkColorFilter>();) */
extern "C" void shim_65(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_65" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_65" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::SkPaint();) */
extern "C" void shim_66(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_66" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkPaint);\n        SkPaint ref = SkPaint();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_66" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setAntiAlias(bool None);) */
extern "C" void shim_67(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_67" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setAntiAlias(" << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_67" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setDither(bool None);) */
extern "C" void shim_68(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_68" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setDither(" << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_68" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setColor(SkColor None);) */
extern "C" void shim_69(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_69" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setColor(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_69" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setBlendMode(SkBlendMode None);) */
extern "C" void shim_70(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_70" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setBlendMode(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_70" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setStyle(SkPaint::Style None);) */
extern "C" void shim_71(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 3) {
        case 0: _a0 = "SkPaint::Style::kFill_Style"; break;
        case 1: _a0 = "SkPaint::Style::kStroke_Style"; break;
        case 2: _a0 = "SkPaint::Style::kStrokeAndFill_Style"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_71" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setStyle(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_71" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setShader(sk_sp<SkShader> None);) */
extern "C" void shim_72(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_72" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setShader(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_72" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setPathEffect(sk_sp<SkPathEffect> None);) */
extern "C" void shim_73(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPathEffect> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_73" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setPathEffect(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_73" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setMaskFilter(sk_sp<SkMaskFilter> None);) */
extern "C" void shim_74(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkMaskFilter> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_74" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setMaskFilter(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_74" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setImageFilter(sk_sp<SkImageFilter> None);) */
extern "C" void shim_75(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_75" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setImageFilter(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_75" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setColorFilter(sk_sp<SkColorFilter> None);) */
extern "C" void shim_76(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkColorFilter> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_76" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setColorFilter(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_76" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setStrokeWidth(SkScalar None);) */
extern "C" void shim_77(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_77" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setStrokeWidth(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_77" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setStrokeMiter(SkScalar None);) */
extern "C" void shim_78(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_78" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setStrokeMiter(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_78" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setStrokeCap(SkPaint::Cap None);) */
extern "C" void shim_79(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_79" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setStrokeCap(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_79" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::void setStrokeJoin(SkPaint::Join None);) */
extern "C" void shim_80(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_80" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setStrokeJoin(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_80" << std::endl;
}


/* CPPScope(name=(auto) SkPaint::~SkPaint();) */
extern "C" void shim_81(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_81" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_81" << std::endl;
}


/* CPPScope(name=(auto) SkFont::SkFont();) */
extern "C" void shim_82(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_82" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkFont);\n        SkFont ref = SkFont();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_82" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setTypeface(sk_sp<SkTypeface> None);) */
extern "C" void shim_83(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkTypeface> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_83" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setTypeface(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_83" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setSize(SkScalar None);) */
extern "C" void shim_84(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_84" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setSize(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_84" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setScaleX(SkScalar None);) */
extern "C" void shim_85(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_85" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setScaleX(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_85" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setSkewX(SkScalar None);) */
extern "C" void shim_86(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_86" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setSkewX(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_86" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setLinearMetrics(bool None);) */
extern "C" void shim_87(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_87" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setLinearMetrics(" << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_87" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setSubpixel(bool None);) */
extern "C" void shim_88(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_88" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setSubpixel(" << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_88" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setEmbeddedBitmaps(bool None);) */
extern "C" void shim_89(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_89" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setEmbeddedBitmaps(" << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_89" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setForceAutoHinting(bool None);) */
extern "C" void shim_90(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_90" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setForceAutoHinting(" << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_90" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setEmbolden(bool None);) */
extern "C" void shim_91(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_91" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setEmbolden(" << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_91" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setHinting(SkFontHinting None);) */
extern "C" void shim_92(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 4) {
        case 0: _a0 = "SkFontHinting::kNone"; break;
        case 1: _a0 = "SkFontHinting::kSlight"; break;
        case 2: _a0 = "SkFontHinting::kNormal"; break;
        case 3: _a0 = "SkFontHinting::kFull"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_92" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setHinting(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_92" << std::endl;
}


/* CPPScope(name=(auto) SkFont::void setEdging(SkFont::Edging None);) */
extern "C" void shim_93(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 3) {
        case 0: _a0 = "SkFont::Edging::kAlias"; break;
        case 1: _a0 = "SkFont::Edging::kAntiAlias"; break;
        case 2: _a0 = "SkFont::Edging::kSubpixelAntiAlias"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_93" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setEdging(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_93" << std::endl;
}


/* CPPScope(name=(auto) SkFont::~SkFont();) */
extern "C" void shim_94(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_94" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_94" << std::endl;
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
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_95" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkRect);\n        SkRect ref = SkRect::MakeXYWH(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_95" << std::endl;
}


/* CPPScope(name=(auto) SkRect::~SkRect();) */
extern "C" void shim_96(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_96" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_96" << std::endl;
}


/* CPPScope(name=(auto) SkPoint3::SkPoint3 Make(SkScalar x, SkScalar y, SkScalar z);) */
extern "C" void shim_97(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPoint3 *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_97" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkPoint3);\n        SkPoint3 ref = SkPoint3::Make(" << _a0 << ", " << _a1 << ", " << _a2 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_97" << std::endl;
}


/* CPPScope(name=(auto) SkPoint3::~SkPoint3();) */
extern "C" void shim_98(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_98" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_98" << std::endl;
}


/* CPPScope(name=canvas_saveLayer) */
extern "C" void shim_99(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    bool _a2 = *(static_cast<const char *>(context + 2)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_99" << std::endl;

    std::cout << "        SkCanvas::SaveLayerRec saveLayerRec;\n        if (" << (int)_a0 << ") saveLayerRec.fBounds = " << "var_" << _i1 << ";\n        if (" << (int)_a1 << ") saveLayerRec.fPaint = " << "var_" << _i2 << ";\n        if (" << (int)_a2 << ") saveLayerRec.fBackdrop = " << "var_" << _i3 << "->get();\n        " << "var_" << _i0 << "->saveLayer(saveLayerRec);\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_99" << std::endl;
}


/* CPPScope(name=canvas_drawPoints) */
extern "C" void shim_100(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a1;
    memcpy(&_a1, context + 240, sizeof(int));
    const char *_a2;
    switch (*(reinterpret_cast<const unsigned char *>(context + 244)) % 3) {
        case 0: _a2 = "SkCanvas::PointMode::kPoints_PointMode"; break;
        case 1: _a2 = "SkCanvas::PointMode::kLines_PointMode"; break;
        case 2: _a2 = "SkCanvas::PointMode::kPolygon_PointMode"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_100" << std::endl;
    float _a0[60];
    memcpy(&_a0, context + 0, 4 * 60);
    std::cout << "    float _a0[60] = {";
    for (int i = 0; i < 60; ++i) {
        if (i % 16 == 0 && 60 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 60 - 1) std::cout << ", ";
    }
    if (60 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        int count = " << _a1 << " % 30;\n        SkPoint pts[30];\n        for (int i = 0; i < count; ++i) {\n          pts[i] = SkPoint::Make(" << "_a0" << "[i*2], " << "_a0" << "[(i*2)+1]);\n        }\n        " << "var_" << _i0 << "->drawPoints(" << _a2 << ", count, pts, *" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_100" << std::endl;
}


/* CPPScope(name=drawImage) */
extern "C" void shim_101(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_101" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->drawImage(" << "var_" << _i1 << "->get(), " << _a0 << ", " << _a1 << ", SkSamplingOptions(), " << (int)_a2 << " ? " << "var_" << _i2 << " : nullptr);\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_101" << std::endl;
}


/* CPPScope(name=drawImageRect) */
extern "C" void shim_102(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _i4 = reinterpret_cast<unsigned long>(in_ref[4]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
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

    std::cout << "    { // begin shim_102" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->drawImageRect(" << "var_" << _i1 << "->get(), *" << "var_" << _i2 << ", *" << "var_" << _i3 << ", SkSamplingOptions(), " << (int)_a0 << " ? " << "var_" << _i4 << " : nullptr, " << (int)_a1 << " ? SkCanvas::kStrict_SrcRectConstraint : SkCanvas::kFast_SrcRectConstraint);\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";\n        " << "var_" << _o4 << " = " << "var_" << _i4 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);

    std::cout << "    } // end shim_102" << std::endl;
}


/* CPPScope(name=drawImageNine) */
extern "C" void shim_103(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _i4 = reinterpret_cast<unsigned long>(in_ref[4]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o3 << ";" << std::endl;
    unsigned long _o4 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o4 << ";" << std::endl;

    std::cout << "    { // begin shim_103" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->drawImageNine(" << "var_" << _i1 << "->get(), *" << "var_" << _i2 << ", *" << "var_" << _i3 << ", SkFilterMode::kNearest, " << (int)_a0 << " ? " << "var_" << _i4 << " : nullptr);\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";\n        " << "var_" << _o4 << " = " << "var_" << _i4 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);

    std::cout << "    } // end shim_103" << std::endl;
}


/* CPPScope(name=canvas_drawImageLattice) */
extern "C" void shim_104(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    int _a2;
    memcpy(&_a2, context + 48, sizeof(int));
    int _a3;
    memcpy(&_a3, context + 52, sizeof(int));
    bool _a4 = *(static_cast<const char *>(context + 56)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_104" << std::endl;
    int _a0[6];
    memcpy(&_a0, context + 0, 4 * 6);
    std::cout << "    int _a0[6] = {";
    for (int i = 0; i < 6; ++i) {
        if (i % 16 == 0 && 6 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 6 - 1) std::cout << ", ";
    }
    if (6 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    int _a1[6];
    memcpy(&_a1, context + 24, 4 * 6);
    std::cout << "    int _a1[6] = {";
    for (int i = 0; i < 6; ++i) {
        if (i % 16 == 0 && 6 > 16) std::cout << std::endl << "        ";
        std::cout << _a1[i];
        if (i < 6 - 1) std::cout << ", ";
    }
    if (6 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        SkCanvas::Lattice lattice{\n          " << "_a0" << ", \n          " << "_a1" << ", \n          nullptr, \n          (" << _a2 << " % (6-2)) + 2,\n          (" << _a3 << " % (6-2)) + 2, \n          nullptr, \n          nullptr\n        };\n        " << "var_" << _i0 << "->drawImageLattice(" << "var_" << _i1 << "->get(), lattice, *" << "var_" << _i2 << ", SkFilterMode::kLinear, " << (int)_a4 << " ? " << "var_" << _i3 << " : nullptr);\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_104" << std::endl;
}


/* CPPScope(name=canvas_drawSimpleText) */
extern "C" void shim_105(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a1;
    memcpy(&_a1, context + 128, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 132, sizeof(float));
    const char *_a3;
    switch (*(reinterpret_cast<const unsigned char *>(context + 136)) % 4) {
        case 0: _a3 = "SkTextEncoding::kUTF8"; break;
        case 1: _a3 = "SkTextEncoding::kUTF16"; break;
        case 2: _a3 = "SkTextEncoding::kUTF32"; break;
        case 3: _a3 = "SkTextEncoding::kGlyphID"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_105" << std::endl;
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    std::cout << "    uint8_t _a0[128] = {";
    for (int i = 0; i < 128; ++i) {
        if (i % 16 == 0 && 128 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 128 - 1) std::cout << ", ";
    }
    if (128 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        Fuzz f = Fuzz(" << "_a0" << ", 128);\n        SkTDArray<uint8_t> text = make_fuzz_text(&f, *" << "var_" << _i1 << ", " << _a3 << ");\n        " << "var_" << _i0 << "->drawSimpleText(\n          text.begin(), \n          SkToSizeT(text.count()),\n          " << _a3 << ",\n          " << _a1 << ",\n          " << _a2 << ",\n          *" << "var_" << _i1 << ",\n          *" << "var_" << _i2 << "\n        );\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_105" << std::endl;
}


/* CPPScope(name=canvas_drawVertices) */
extern "C" void shim_106(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 3) {
        case 0: _a0 = "SkVertices::VertexMode::kTriangles_VertexMode"; break;
        case 1: _a0 = "SkVertices::VertexMode::kTriangleStrip_VertexMode"; break;
        case 2: _a0 = "SkVertices::VertexMode::kTriangleFan_VertexMode"; break;
    }
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 1)) % 32) {
        case 0: _a1 = "SkBlendMode::kClear"; break;
        case 1: _a1 = "SkBlendMode::kSrc"; break;
        case 2: _a1 = "SkBlendMode::kDst"; break;
        case 3: _a1 = "SkBlendMode::kSrcOver"; break;
        case 4: _a1 = "SkBlendMode::kDstOver"; break;
        case 5: _a1 = "SkBlendMode::kSrcIn"; break;
        case 6: _a1 = "SkBlendMode::kDstIn"; break;
        case 7: _a1 = "SkBlendMode::kSrcOut"; break;
        case 8: _a1 = "SkBlendMode::kDstOut"; break;
        case 9: _a1 = "SkBlendMode::kSrcATop"; break;
        case 10: _a1 = "SkBlendMode::kDstATop"; break;
        case 11: _a1 = "SkBlendMode::kXor"; break;
        case 12: _a1 = "SkBlendMode::kPlus"; break;
        case 13: _a1 = "SkBlendMode::kModulate"; break;
        case 14: _a1 = "SkBlendMode::kScreen"; break;
        case 15: _a1 = "SkBlendMode::kOverlay"; break;
        case 16: _a1 = "SkBlendMode::kDarken"; break;
        case 17: _a1 = "SkBlendMode::kLighten"; break;
        case 18: _a1 = "SkBlendMode::kColorDodge"; break;
        case 19: _a1 = "SkBlendMode::kColorBurn"; break;
        case 20: _a1 = "SkBlendMode::kHardLight"; break;
        case 21: _a1 = "SkBlendMode::kSoftLight"; break;
        case 22: _a1 = "SkBlendMode::kDifference"; break;
        case 23: _a1 = "SkBlendMode::kExclusion"; break;
        case 24: _a1 = "SkBlendMode::kMultiply"; break;
        case 25: _a1 = "SkBlendMode::kHue"; break;
        case 26: _a1 = "SkBlendMode::kSaturation"; break;
        case 27: _a1 = "SkBlendMode::kColor"; break;
        case 28: _a1 = "SkBlendMode::kLuminosity"; break;
        case 29: _a1 = "SkBlendMode::kLastCoeffMode"; break;
        case 30: _a1 = "SkBlendMode::kLastSeparableMode"; break;
        case 31: _a1 = "SkBlendMode::kLastMode"; break;
    }
    int _a5;
    memcpy(&_a5, context + 2002, sizeof(int));
    bool _a6 = *(static_cast<const char *>(context + 2006)) & 1;
    bool _a7 = *(static_cast<const char *>(context + 2007)) & 1;
    bool _a8 = *(static_cast<const char *>(context + 2008)) & 1;
    int _a10;
    memcpy(&_a10, context + 2409, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_106" << std::endl;
    float _a2[200];
    memcpy(&_a2, context + 2, 4 * 200);
    std::cout << "    float _a2[200] = {";
    for (int i = 0; i < 200; ++i) {
        if (i % 16 == 0 && 200 > 16) std::cout << std::endl << "        ";
        std::cout << _a2[i];
        if (i < 200 - 1) std::cout << ", ";
    }
    if (200 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    float _a3[200];
    memcpy(&_a3, context + 802, 4 * 200);
    std::cout << "    float _a3[200] = {";
    for (int i = 0; i < 200; ++i) {
        if (i % 16 == 0 && 200 > 16) std::cout << std::endl << "        ";
        std::cout << _a3[i];
        if (i < 200 - 1) std::cout << ", ";
    }
    if (200 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint32_t _a4[100];
    memcpy(&_a4, context + 1602, 4 * 100);
    std::cout << "    uint32_t _a4[100] = {";
    for (int i = 0; i < 100; ++i) {
        if (i % 16 == 0 && 100 > 16) std::cout << std::endl << "        ";
        std::cout << _a4[i];
        if (i < 100 - 1) std::cout << ", ";
    }
    if (100 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint16_t _a9[200];
    memcpy(&_a9, context + 2009, 2 * 200);
    std::cout << "    uint16_t _a9[200] = {";
    for (int i = 0; i < 200; ++i) {
        if (i % 16 == 0 && 200 > 16) std::cout << std::endl << "        ";
        std::cout << _a9[i];
        if (i < 200 - 1) std::cout << ", ";
    }
    if (200 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        int vertexCount = (" << _a5 << " % (100 - 3)) + 3;\n        \n        SkPoint vertices[100];\n        SkPoint texs[100];\n        \n        for (int i = 0; i < vertexCount; ++i) {\n          vertices[i] = SkPoint::Make(" << "_a2" << "[i*2], " << "_a2" << "[(i*2)+1]);\n          texs[i] = SkPoint::Make(" << "_a3" << "[i*2], " << "_a3" << "[(i*2)+1]);\n        }\n        \n        int indexCount = " << (int)_a8 << " ? ((" << _a10 << " % 100) + vertexCount) : 0;\n        \n        " << "var_" << _i0 << "->drawVertices(SkVertices::MakeCopy(\n            " << _a0 << ", vertexCount, vertices,\n            " << (int)_a6 << " ? texs : nullptr,\n            " << (int)_a7 << " ? " << "_a4" << " : nullptr,\n            indexCount, " << "_a9" << "\n          ), " << _a1 << ", *" << "var_" << _i1 << "\n        );\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_106" << std::endl;
}


/* CPPScope(name=void drawColor(SkColor4f, SkBlendMode)) */
extern "C" void shim_107(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 4)) % 32) {
        case 0: _a1 = "SkBlendMode::kClear"; break;
        case 1: _a1 = "SkBlendMode::kSrc"; break;
        case 2: _a1 = "SkBlendMode::kDst"; break;
        case 3: _a1 = "SkBlendMode::kSrcOver"; break;
        case 4: _a1 = "SkBlendMode::kDstOver"; break;
        case 5: _a1 = "SkBlendMode::kSrcIn"; break;
        case 6: _a1 = "SkBlendMode::kDstIn"; break;
        case 7: _a1 = "SkBlendMode::kSrcOut"; break;
        case 8: _a1 = "SkBlendMode::kDstOut"; break;
        case 9: _a1 = "SkBlendMode::kSrcATop"; break;
        case 10: _a1 = "SkBlendMode::kDstATop"; break;
        case 11: _a1 = "SkBlendMode::kXor"; break;
        case 12: _a1 = "SkBlendMode::kPlus"; break;
        case 13: _a1 = "SkBlendMode::kModulate"; break;
        case 14: _a1 = "SkBlendMode::kScreen"; break;
        case 15: _a1 = "SkBlendMode::kOverlay"; break;
        case 16: _a1 = "SkBlendMode::kDarken"; break;
        case 17: _a1 = "SkBlendMode::kLighten"; break;
        case 18: _a1 = "SkBlendMode::kColorDodge"; break;
        case 19: _a1 = "SkBlendMode::kColorBurn"; break;
        case 20: _a1 = "SkBlendMode::kHardLight"; break;
        case 21: _a1 = "SkBlendMode::kSoftLight"; break;
        case 22: _a1 = "SkBlendMode::kDifference"; break;
        case 23: _a1 = "SkBlendMode::kExclusion"; break;
        case 24: _a1 = "SkBlendMode::kMultiply"; break;
        case 25: _a1 = "SkBlendMode::kHue"; break;
        case 26: _a1 = "SkBlendMode::kSaturation"; break;
        case 27: _a1 = "SkBlendMode::kColor"; break;
        case 28: _a1 = "SkBlendMode::kLuminosity"; break;
        case 29: _a1 = "SkBlendMode::kLastCoeffMode"; break;
        case 30: _a1 = "SkBlendMode::kLastSeparableMode"; break;
        case 31: _a1 = "SkBlendMode::kLastMode"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_107" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->drawColor(SkColor4f::FromColor(" << _a0 << "), " << _a1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_107" << std::endl;
}


/* CPPScope(name=canvas_drawString) */
extern "C" void shim_108(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a1;
    memcpy(&_a1, context + 128, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 132, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_108" << std::endl;
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    std::cout << "    uint8_t _a0[128] = {";
    for (int i = 0; i < 128; ++i) {
        if (i % 16 == 0 && 128 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 128 - 1) std::cout << ", ";
    }
    if (128 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        Fuzz f = Fuzz(" << "_a0" << ", 128);\n        std::string str = make_fuzz_string(&f);\n        " << "var_" << _i0 << "->drawString(str.c_str(), " << _a1 << ", " << _a2 << ", *" << "var_" << _i1 << ", *" << "var_" << _i2 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_108" << std::endl;
}


/* CPPScope(name=canvas_drawPatch) */
extern "C" void shim_109(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    bool _a3 = *(static_cast<const char *>(context + 144)) & 1;
    const char *_a4;
    switch (*(reinterpret_cast<const unsigned char *>(context + 145)) % 32) {
        case 0: _a4 = "SkBlendMode::kClear"; break;
        case 1: _a4 = "SkBlendMode::kSrc"; break;
        case 2: _a4 = "SkBlendMode::kDst"; break;
        case 3: _a4 = "SkBlendMode::kSrcOver"; break;
        case 4: _a4 = "SkBlendMode::kDstOver"; break;
        case 5: _a4 = "SkBlendMode::kSrcIn"; break;
        case 6: _a4 = "SkBlendMode::kDstIn"; break;
        case 7: _a4 = "SkBlendMode::kSrcOut"; break;
        case 8: _a4 = "SkBlendMode::kDstOut"; break;
        case 9: _a4 = "SkBlendMode::kSrcATop"; break;
        case 10: _a4 = "SkBlendMode::kDstATop"; break;
        case 11: _a4 = "SkBlendMode::kXor"; break;
        case 12: _a4 = "SkBlendMode::kPlus"; break;
        case 13: _a4 = "SkBlendMode::kModulate"; break;
        case 14: _a4 = "SkBlendMode::kScreen"; break;
        case 15: _a4 = "SkBlendMode::kOverlay"; break;
        case 16: _a4 = "SkBlendMode::kDarken"; break;
        case 17: _a4 = "SkBlendMode::kLighten"; break;
        case 18: _a4 = "SkBlendMode::kColorDodge"; break;
        case 19: _a4 = "SkBlendMode::kColorBurn"; break;
        case 20: _a4 = "SkBlendMode::kHardLight"; break;
        case 21: _a4 = "SkBlendMode::kSoftLight"; break;
        case 22: _a4 = "SkBlendMode::kDifference"; break;
        case 23: _a4 = "SkBlendMode::kExclusion"; break;
        case 24: _a4 = "SkBlendMode::kMultiply"; break;
        case 25: _a4 = "SkBlendMode::kHue"; break;
        case 26: _a4 = "SkBlendMode::kSaturation"; break;
        case 27: _a4 = "SkBlendMode::kColor"; break;
        case 28: _a4 = "SkBlendMode::kLuminosity"; break;
        case 29: _a4 = "SkBlendMode::kLastCoeffMode"; break;
        case 30: _a4 = "SkBlendMode::kLastSeparableMode"; break;
        case 31: _a4 = "SkBlendMode::kLastMode"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_109" << std::endl;
    float _a0[24];
    memcpy(&_a0, context + 0, 4 * 24);
    std::cout << "    float _a0[24] = {";
    for (int i = 0; i < 24; ++i) {
        if (i % 16 == 0 && 24 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 24 - 1) std::cout << ", ";
    }
    if (24 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint32_t _a1[4];
    memcpy(&_a1, context + 96, 4 * 4);
    std::cout << "    uint32_t _a1[4] = {";
    for (int i = 0; i < 4; ++i) {
        if (i % 16 == 0 && 4 > 16) std::cout << std::endl << "        ";
        std::cout << _a1[i];
        if (i < 4 - 1) std::cout << ", ";
    }
    if (4 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    float _a2[8];
    memcpy(&_a2, context + 112, 4 * 8);
    std::cout << "    float _a2[8] = {";
    for (int i = 0; i < 8; ++i) {
        if (i % 16 == 0 && 8 > 16) std::cout << std::endl << "        ";
        std::cout << _a2[i];
        if (i < 8 - 1) std::cout << ", ";
    }
    if (8 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        SkPoint cubics[12];\n        for (int i = 0; i < 12; ++i) cubics[i] = SkPoint::Make(" << "_a0" << "[i*2], " << "_a0" << "[(i*2)+1]);\n        SkPoint tex[4];\n        for (int i = 0; i < 4; ++i) tex[i] = SkPoint::Make(" << "_a2" << "[i*2], " << "_a2" << "[(i*2)+1]);\n        " << "var_" << _i0 << "->drawPatch(cubics, " << "_a1" << ", " << (int)_a3 << " ? tex : nullptr, " << _a4 << ", *" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_109" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void flush();) */
extern "C" void shim_110(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_110" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->flush();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_110" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void save();) */
extern "C" void shim_111(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_111" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->save();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_111" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void saveLayer(SkRect * None, SkPaint * None);) */
extern "C" void shim_112(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_112" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->saveLayer(" << "var_" << _i1 << ", " << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_112" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void saveLayer(SkRect * None, {nullptr});) */
extern "C" void shim_113(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_113" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->saveLayer(" << "var_" << _i1 << ", nullptr);)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_113" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void saveLayer({nullptr}, SkPaint * None);) */
extern "C" void shim_114(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_114" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->saveLayer(nullptr, " << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_114" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void saveLayer({nullptr}, {nullptr});) */
extern "C" void shim_115(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_115" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->saveLayer(nullptr, nullptr);)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_115" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void saveLayerAlpha({nullptr}, uint8_t None);) */
extern "C" void shim_116(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_116" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->saveLayerAlpha(nullptr, " << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_116" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void saveLayerAlpha(SkRect * None, uint8_t None);) */
extern "C" void shim_117(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_117" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->saveLayerAlpha(" << "var_" << _i1 << ", " << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_117" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void restore();) */
extern "C" void shim_118(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_118" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->restore();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_118" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void restoreToCount(int None);) */
extern "C" void shim_119(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_119" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->restoreToCount(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_119" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void translate(SkScalar None, SkScalar None);) */
extern "C" void shim_120(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_120" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->translate(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_120" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void scale(SkScalar None, SkScalar None);) */
extern "C" void shim_121(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_121" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->scale(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_121" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void rotate(SkScalar None);) */
extern "C" void shim_122(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_122" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->rotate(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_122" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void rotate(SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_123(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_123" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->rotate(" << _a0 << ", " << _a1 << ", " << _a2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_123" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void skew(SkScalar None, SkScalar None);) */
extern "C" void shim_124(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_124" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->skew(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_124" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void concat(SkMatrix None);) */
extern "C" void shim_125(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_125" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->concat(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_125" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void setMatrix(SkMatrix None);) */
extern "C" void shim_126(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_126" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setMatrix(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_126" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void resetMatrix();) */
extern "C" void shim_127(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_127" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->resetMatrix();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_127" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void clipRect(SkRect None, SkClipOp None, bool None);) */
extern "C" void shim_128(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkClipOp::kDifference"; break;
        case 1: _a0 = "SkClipOp::kIntersect"; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_128" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->clipRect(*" << "var_" << _i1 << ", " << _a0 << ", " << (int)_a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_128" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void clipRRect(SkRRect None, SkClipOp None, bool None);) */
extern "C" void shim_129(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkClipOp::kDifference"; break;
        case 1: _a0 = "SkClipOp::kIntersect"; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_129" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->clipRRect(*" << "var_" << _i1 << ", " << _a0 << ", " << (int)_a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_129" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void clipPath(SkPath None, SkClipOp None, bool None);) */
extern "C" void shim_130(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkClipOp::kDifference"; break;
        case 1: _a0 = "SkClipOp::kIntersect"; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_130" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->clipPath(*" << "var_" << _i1 << ", " << _a0 << ", " << (int)_a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_130" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void clipRegion(SkRegion None, SkClipOp None);) */
extern "C" void shim_131(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkClipOp::kDifference"; break;
        case 1: _a0 = "SkClipOp::kIntersect"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_131" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->clipRegion(*" << "var_" << _i1 << ", " << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_131" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawPaint(SkPaint None);) */
extern "C" void shim_132(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_132" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawPaint(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_132" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawRect(SkRect None, SkPaint None);) */
extern "C" void shim_133(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_133" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawRect(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_133" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawRegion(SkRegion None, SkPaint None);) */
extern "C" void shim_134(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_134" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawRegion(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_134" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawOval(SkRect None, SkPaint None);) */
extern "C" void shim_135(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_135" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawOval(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_135" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawRRect(SkRRect None, SkPaint None);) */
extern "C" void shim_136(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_136" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawRRect(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_136" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawDRRect(SkRRect None, SkRRect None, SkPaint None);) */
extern "C" void shim_137(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkRRect *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_137" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawDRRect(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ", *" << "var_" << _i3 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_137" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawArc(SkRect None, SkScalar None, SkScalar None, bool None, SkPaint None);) */
extern "C" void shim_138(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_138" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawArc(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", " << (int)_a2 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_138" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawPath(SkPath None, SkPaint None);) */
extern "C" void shim_139(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_139" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawPath(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_139" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawTextBlob(sk_sp<SkTextBlob> None, SkScalar None, SkScalar None, SkPaint None);) */
extern "C" void shim_140(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_140" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawTextBlob(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_140" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, SkMatrix * None, SkPaint * None);) */
extern "C" void shim_141(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPicture> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_141" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawPicture(*" << "var_" << _i1 << ", " << "var_" << _i2 << ", " << "var_" << _i3 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_141" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, SkMatrix * None, {nullptr});) */
extern "C" void shim_142(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPicture> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_142" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawPicture(*" << "var_" << _i1 << ", " << "var_" << _i2 << ", nullptr);)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_142" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, {nullptr}, SkPaint * None);) */
extern "C" void shim_143(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPicture> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_143" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawPicture(*" << "var_" << _i1 << ", nullptr, " << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_143" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, {nullptr}, {nullptr});) */
extern "C" void shim_144(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPicture> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_144" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawPicture(*" << "var_" << _i1 << ", nullptr, nullptr);)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_144" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawColor(SkColor None, SkBlendMode None);) */
extern "C" void shim_145(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 4)) % 32) {
        case 0: _a1 = "SkBlendMode::kClear"; break;
        case 1: _a1 = "SkBlendMode::kSrc"; break;
        case 2: _a1 = "SkBlendMode::kDst"; break;
        case 3: _a1 = "SkBlendMode::kSrcOver"; break;
        case 4: _a1 = "SkBlendMode::kDstOver"; break;
        case 5: _a1 = "SkBlendMode::kSrcIn"; break;
        case 6: _a1 = "SkBlendMode::kDstIn"; break;
        case 7: _a1 = "SkBlendMode::kSrcOut"; break;
        case 8: _a1 = "SkBlendMode::kDstOut"; break;
        case 9: _a1 = "SkBlendMode::kSrcATop"; break;
        case 10: _a1 = "SkBlendMode::kDstATop"; break;
        case 11: _a1 = "SkBlendMode::kXor"; break;
        case 12: _a1 = "SkBlendMode::kPlus"; break;
        case 13: _a1 = "SkBlendMode::kModulate"; break;
        case 14: _a1 = "SkBlendMode::kScreen"; break;
        case 15: _a1 = "SkBlendMode::kOverlay"; break;
        case 16: _a1 = "SkBlendMode::kDarken"; break;
        case 17: _a1 = "SkBlendMode::kLighten"; break;
        case 18: _a1 = "SkBlendMode::kColorDodge"; break;
        case 19: _a1 = "SkBlendMode::kColorBurn"; break;
        case 20: _a1 = "SkBlendMode::kHardLight"; break;
        case 21: _a1 = "SkBlendMode::kSoftLight"; break;
        case 22: _a1 = "SkBlendMode::kDifference"; break;
        case 23: _a1 = "SkBlendMode::kExclusion"; break;
        case 24: _a1 = "SkBlendMode::kMultiply"; break;
        case 25: _a1 = "SkBlendMode::kHue"; break;
        case 26: _a1 = "SkBlendMode::kSaturation"; break;
        case 27: _a1 = "SkBlendMode::kColor"; break;
        case 28: _a1 = "SkBlendMode::kLuminosity"; break;
        case 29: _a1 = "SkBlendMode::kLastCoeffMode"; break;
        case 30: _a1 = "SkBlendMode::kLastSeparableMode"; break;
        case 31: _a1 = "SkBlendMode::kLastMode"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_145" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawColor(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_145" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawLine(SkPoint None, SkPoint None, SkPaint None);) */
extern "C" void shim_146(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPoint *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_146" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawLine(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ", *" << "var_" << _i3 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_146" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawIRect(SkIRect None, SkPaint None);) */
extern "C" void shim_147(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_147" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawIRect(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_147" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawCircle(SkPoint None, SkScalar None, SkPaint None);) */
extern "C" void shim_148(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_148" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawCircle(*" << "var_" << _i1 << ", " << _a0 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_148" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawArc(SkRect None, SkScalar None, SkScalar None, bool None, SkPaint None);) */
extern "C" void shim_149(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkCanvas *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_149" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawArc(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", " << (int)_a2 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_149" << std::endl;
}


/* CPPScope(name=(auto) SkCanvas::void drawRoundRect(SkRect None, SkScalar None, SkScalar None, SkPaint None);) */
extern "C" void shim_150(void **in_ref, void **out_ref, const char *context) {
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
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_150" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->drawRoundRect(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_150" << std::endl;
}


/* CPPScope(name=begin_recording_canvas) */
extern "C" void shim_151(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_151" << std::endl;

    std::cout << "        SkPictureRecorder *recorder = new SkPictureRecorder();\n        SkCanvas *canvas = recorder->beginRecording(" << _a0 << ", " << _a1 << ");\n        " << "var_" << _o0 << " = BUNDLE(canvas, recorder);" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_151" << std::endl;
}


/* CPPScope(name=end_recording_canvas) */
extern "C" void shim_152(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkPicture> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_152" << std::endl;

    std::cout << "        SkPictureRecorder *recorder = (SkPictureRecorder *)" << "var_" << _i0 << "->inactive;\n        delete " << "var_" << _i0 << ";\n        " << "var_" << _o0 << " = MAKE(sk_sp<SkPicture>);\n        *" << "var_" << _o0 << " = recorder->finishRecordingAsPicture();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_152" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkPicture>::~sk_sp<SkPicture>();) */
extern "C" void shim_153(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_153" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_153" << std::endl;
}


/* CPPScope(name=nullptr) */
extern "C" void shim_154(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_154" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkShader>);" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_154" << std::endl;
}


/* CPPScope(name=SkImage::makeShader) */
extern "C" void shim_155(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = "SkTileMode::kClamp"; break;
        case 1: _a0 = "SkTileMode::kRepeat"; break;
        case 2: _a0 = "SkTileMode::kMirror"; break;
        case 3: _a0 = "SkTileMode::kDecal"; break;
        case 4: _a0 = "SkTileMode::kLastTileMode"; break;
    }
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 1)) % 5) {
        case 0: _a1 = "SkTileMode::kClamp"; break;
        case 1: _a1 = "SkTileMode::kRepeat"; break;
        case 2: _a1 = "SkTileMode::kMirror"; break;
        case 3: _a1 = "SkTileMode::kDecal"; break;
        case 4: _a1 = "SkTileMode::kLastTileMode"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_155" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkShader>);\n        if (*" << "var_" << _i0 << " != nullptr) *" << "var_" << _o0 << " = (*" << "var_" << _i0 << ")->makeShader(" << _a0 << ", " << _a1 << ", SkSamplingOptions(), *" << "var_" << _i1 << ");\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_155" << std::endl;
}


/* CPPScope(name=SkShader::makeWithLocalMatrix) */
extern "C" void shim_156(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_156" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkShader>);\n        if (*" << "var_" << _i0 << " != nullptr) *" << "var_" << _o0 << " = (*" << "var_" << _i0 << ")->makeWithLocalMatrix(*" << "var_" << _i1 << ");\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_156" << std::endl;
}


/* CPPScope(name=SkShader::makeWithColorFilter) */
extern "C" void shim_157(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkColorFilter> *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_157" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkShader>);\n        if (*" << "var_" << _i0 << " != nullptr) *" << "var_" << _o0 << " = (*" << "var_" << _i0 << ")->makeWithColorFilter(*" << "var_" << _i1 << ");\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_157" << std::endl;
}


/* CPPScope(name=SkPicture::makeShader) */
extern "C" void shim_158(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = "SkTileMode::kClamp"; break;
        case 1: _a0 = "SkTileMode::kRepeat"; break;
        case 2: _a0 = "SkTileMode::kMirror"; break;
        case 3: _a0 = "SkTileMode::kDecal"; break;
        case 4: _a0 = "SkTileMode::kLastTileMode"; break;
    }
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 1)) % 5) {
        case 0: _a1 = "SkTileMode::kClamp"; break;
        case 1: _a1 = "SkTileMode::kRepeat"; break;
        case 2: _a1 = "SkTileMode::kMirror"; break;
        case 3: _a1 = "SkTileMode::kDecal"; break;
        case 4: _a1 = "SkTileMode::kLastTileMode"; break;
    }
    bool _a2 = *(static_cast<const char *>(context + 2)) & 1;
    bool _a3 = *(static_cast<const char *>(context + 3)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPicture> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_158" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkShader>);\n        if (*" << "var_" << _i0 << " != nullptr) {\n          if (" << (int)_a2 << " && " << (int)_a3 << ")\n            *" << "var_" << _o0 << " = (*" << "var_" << _i0 << ")->makeShader(" << _a0 << ", " << _a1 << ", SkFilterMode::kNearest, " << "var_" << _i1 << ", " << "var_" << _i2 << ");\n          else if (" << (int)_a2 << ")\n            *" << "var_" << _o0 << " = (*" << "var_" << _i0 << ")->makeShader(" << _a0 << ", " << _a1 << ", SkFilterMode::kNearest, " << "var_" << _i1 << ", nullptr);\n          else if (" << (int)_a3 << ")\n            *" << "var_" << _o0 << " = (*" << "var_" << _i0 << ")->makeShader(" << _a0 << ", " << _a1 << ", SkFilterMode::kNearest, nullptr, " << "var_" << _i2 << ");\n          else\n            *" << "var_" << _o0 << " = (*" << "var_" << _i0 << ")->makeShader(" << _a0 << ", " << _a1 << ", SkFilterMode::kNearest, nullptr, nullptr);\n        }\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_158" << std::endl;
}


/* CPPScope(name=SkGradientShader::MakeLinear) */
extern "C" void shim_159(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a4;
    switch (*(reinterpret_cast<const unsigned char *>(context + 112)) % 5) {
        case 0: _a4 = "SkTileMode::kClamp"; break;
        case 1: _a4 = "SkTileMode::kRepeat"; break;
        case 2: _a4 = "SkTileMode::kMirror"; break;
        case 3: _a4 = "SkTileMode::kDecal"; break;
        case 4: _a4 = "SkTileMode::kLastTileMode"; break;
    }
    int _a6;
    memcpy(&_a6, context + 115, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_159" << std::endl;
    float _a0[2];
    memcpy(&_a0, context + 0, 4 * 2);
    std::cout << "    float _a0[2] = {";
    for (int i = 0; i < 2; ++i) {
        if (i % 16 == 0 && 2 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 2 - 1) std::cout << ", ";
    }
    if (2 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    float _a1[2];
    memcpy(&_a1, context + 8, 4 * 2);
    std::cout << "    float _a1[2] = {";
    for (int i = 0; i < 2; ++i) {
        if (i % 16 == 0 && 2 > 16) std::cout << std::endl << "        ";
        std::cout << _a1[i];
        if (i < 2 - 1) std::cout << ", ";
    }
    if (2 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint32_t _a2[12];
    memcpy(&_a2, context + 16, 4 * 12);
    std::cout << "    uint32_t _a2[12] = {";
    for (int i = 0; i < 12; ++i) {
        if (i % 16 == 0 && 12 > 16) std::cout << std::endl << "        ";
        std::cout << _a2[i];
        if (i < 12 - 1) std::cout << ", ";
    }
    if (12 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    float _a3[12];
    memcpy(&_a3, context + 64, 4 * 12);
    std::cout << "    float _a3[12] = {";
    for (int i = 0; i < 12; ++i) {
        if (i % 16 == 0 && 12 > 16) std::cout << std::endl << "        ";
        std::cout << _a3[i];
        if (i < 12 - 1) std::cout << ", ";
    }
    if (12 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
bool _a5[2];
for (int i = 0; i < 2; ++i) _a5[i] = *(static_cast<const char *>(context + 113 + i)) & 1;
    std::cout << "    bool _a5[2] = {";
    for (int i = 0; i < 2; ++i) {
        if (i % 16 == 0 && 2 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a5[i];
        if (i < 2 - 1) std::cout << ", ";
    }
    if (2 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkShader>);\n        \n        SkPoint pts[2] = {\n          SkPoint::Make(" << "_a0" << "[0], " << "_a0" << "[1]),\n          SkPoint::Make(" << "_a1" << "[0], " << "_a1" << "[1]),\n        };\n        \n        int colorCount = " << _a6 << ";\n        if (colorCount < 2) colorCount = 2;\n        if (colorCount > 12) colorCount = 12;\n        \n        fuzz_gradient_stops(" << "_a3" << ", colorCount);\n        \n        if (" << "_a5" << "[0] && " << "_a5" << "[1])\n          *" << "var_" << _o0 << " = SkGradientShader::MakeLinear(pts, " << "_a2" << ", " << "_a3" << ", colorCount, " << _a4 << ", 0, " << "var_" << _i0 << ");\n        else if (" << "_a5" << "[0])\n          *" << "var_" << _o0 << " = SkGradientShader::MakeLinear(pts, " << "_a2" << ", " << "_a3" << ", colorCount, " << _a4 << ", 0, nullptr);\n        else if (" << "_a5" << "[1])\n          *" << "var_" << _o0 << " = SkGradientShader::MakeLinear(pts, " << "_a2" << ", nullptr, colorCount, " << _a4 << ", 0, " << "var_" << _i0 << ");\n        else\n          *" << "var_" << _o0 << " = SkGradientShader::MakeLinear(pts, " << "_a2" << ", nullptr, colorCount, " << _a4 << ", 0, nullptr);\n        \n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_159" << std::endl;
}


/* CPPScope(name=SkGradientShader::MakeRadial) */
extern "C" void shim_160(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a1;
    memcpy(&_a1, context + 8, sizeof(float));
    const char *_a4;
    switch (*(reinterpret_cast<const unsigned char *>(context + 108)) % 5) {
        case 0: _a4 = "SkTileMode::kClamp"; break;
        case 1: _a4 = "SkTileMode::kRepeat"; break;
        case 2: _a4 = "SkTileMode::kMirror"; break;
        case 3: _a4 = "SkTileMode::kDecal"; break;
        case 4: _a4 = "SkTileMode::kLastTileMode"; break;
    }
    int _a6;
    memcpy(&_a6, context + 111, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_160" << std::endl;
    float _a0[2];
    memcpy(&_a0, context + 0, 4 * 2);
    std::cout << "    float _a0[2] = {";
    for (int i = 0; i < 2; ++i) {
        if (i % 16 == 0 && 2 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 2 - 1) std::cout << ", ";
    }
    if (2 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint32_t _a2[12];
    memcpy(&_a2, context + 12, 4 * 12);
    std::cout << "    uint32_t _a2[12] = {";
    for (int i = 0; i < 12; ++i) {
        if (i % 16 == 0 && 12 > 16) std::cout << std::endl << "        ";
        std::cout << _a2[i];
        if (i < 12 - 1) std::cout << ", ";
    }
    if (12 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    float _a3[12];
    memcpy(&_a3, context + 60, 4 * 12);
    std::cout << "    float _a3[12] = {";
    for (int i = 0; i < 12; ++i) {
        if (i % 16 == 0 && 12 > 16) std::cout << std::endl << "        ";
        std::cout << _a3[i];
        if (i < 12 - 1) std::cout << ", ";
    }
    if (12 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
bool _a5[2];
for (int i = 0; i < 2; ++i) _a5[i] = *(static_cast<const char *>(context + 109 + i)) & 1;
    std::cout << "    bool _a5[2] = {";
    for (int i = 0; i < 2; ++i) {
        if (i % 16 == 0 && 2 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a5[i];
        if (i < 2 - 1) std::cout << ", ";
    }
    if (2 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkShader>);\n        \n        SkPoint center = SkPoint::Make(" << "_a0" << "[0], " << "_a0" << "[1]);\n        \n        int colorCount = " << _a6 << ";\n        if (colorCount < 2) colorCount = 2;\n        if (colorCount > 12) colorCount = 12;\n        \n        fuzz_gradient_stops(" << "_a3" << ", colorCount);\n        \n        if (" << "_a5" << "[0] && " << "_a5" << "[1])\n          *" << "var_" << _o0 << " = SkGradientShader::MakeRadial(center, " << _a1 << ", " << "_a2" << ", " << "_a3" << ", colorCount, " << _a4 << ", 0, " << "var_" << _i0 << ");\n        else if (" << "_a5" << "[0])\n          *" << "var_" << _o0 << " = SkGradientShader::MakeRadial(center, " << _a1 << ", " << "_a2" << ", " << "_a3" << ", colorCount, " << _a4 << ", 0, nullptr);\n        else if (" << "_a5" << "[1])\n          *" << "var_" << _o0 << " = SkGradientShader::MakeRadial(center, " << _a1 << ", " << "_a2" << ", nullptr, colorCount, " << _a4 << ", 0, " << "var_" << _i0 << ");\n        else\n          *" << "var_" << _o0 << " = SkGradientShader::MakeRadial(center, " << _a1 << ", " << "_a2" << ", nullptr, colorCount, " << _a4 << ", 0, nullptr);\n        \n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_160" << std::endl;
}


/* CPPScope(name=SkGradientShader::MakeTwoPointConical) */
extern "C" void shim_161(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a4;
    switch (*(reinterpret_cast<const unsigned char *>(context + 120)) % 5) {
        case 0: _a4 = "SkTileMode::kClamp"; break;
        case 1: _a4 = "SkTileMode::kRepeat"; break;
        case 2: _a4 = "SkTileMode::kMirror"; break;
        case 3: _a4 = "SkTileMode::kDecal"; break;
        case 4: _a4 = "SkTileMode::kLastTileMode"; break;
    }
    int _a6;
    memcpy(&_a6, context + 123, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_161" << std::endl;
    float _a0[4];
    memcpy(&_a0, context + 0, 4 * 4);
    std::cout << "    float _a0[4] = {";
    for (int i = 0; i < 4; ++i) {
        if (i % 16 == 0 && 4 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 4 - 1) std::cout << ", ";
    }
    if (4 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    float _a1[2];
    memcpy(&_a1, context + 16, 4 * 2);
    std::cout << "    float _a1[2] = {";
    for (int i = 0; i < 2; ++i) {
        if (i % 16 == 0 && 2 > 16) std::cout << std::endl << "        ";
        std::cout << _a1[i];
        if (i < 2 - 1) std::cout << ", ";
    }
    if (2 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint32_t _a2[12];
    memcpy(&_a2, context + 24, 4 * 12);
    std::cout << "    uint32_t _a2[12] = {";
    for (int i = 0; i < 12; ++i) {
        if (i % 16 == 0 && 12 > 16) std::cout << std::endl << "        ";
        std::cout << _a2[i];
        if (i < 12 - 1) std::cout << ", ";
    }
    if (12 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    float _a3[12];
    memcpy(&_a3, context + 72, 4 * 12);
    std::cout << "    float _a3[12] = {";
    for (int i = 0; i < 12; ++i) {
        if (i % 16 == 0 && 12 > 16) std::cout << std::endl << "        ";
        std::cout << _a3[i];
        if (i < 12 - 1) std::cout << ", ";
    }
    if (12 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
bool _a5[2];
for (int i = 0; i < 2; ++i) _a5[i] = *(static_cast<const char *>(context + 121 + i)) & 1;
    std::cout << "    bool _a5[2] = {";
    for (int i = 0; i < 2; ++i) {
        if (i % 16 == 0 && 2 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a5[i];
        if (i < 2 - 1) std::cout << ", ";
    }
    if (2 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkShader>);\n        \n        SkPoint start = SkPoint::Make(" << "_a0" << "[0], " << "_a0" << "[1]);\n        SkPoint end = SkPoint::Make(" << "_a0" << "[2], " << "_a0" << "[3]);\n        \n        int colorCount = " << _a6 << ";\n        if (colorCount < 2) colorCount = 2;\n        if (colorCount > 12) colorCount = 12;\n        \n        fuzz_gradient_stops(" << "_a3" << ", colorCount);\n        \n        if (" << "_a5" << "[0] && " << "_a5" << "[1])\n          *" << "var_" << _o0 << " = SkGradientShader::MakeTwoPointConical(start, " << "_a1" << "[0], end, " << "_a1" << "[1], " << "_a2" << ", " << "_a3" << ", colorCount, " << _a4 << ", 0, " << "var_" << _i0 << ");\n        else if (" << "_a5" << "[0])\n          *" << "var_" << _o0 << " = SkGradientShader::MakeTwoPointConical(start, " << "_a1" << "[0], end, " << "_a1" << "[1], " << "_a2" << ", " << "_a3" << ", colorCount, " << _a4 << ", 0, nullptr);\n        else if (" << "_a5" << "[1])\n          *" << "var_" << _o0 << " = SkGradientShader::MakeTwoPointConical(start, " << "_a1" << "[0], end, " << "_a1" << "[1], " << "_a2" << ", nullptr, colorCount, " << _a4 << ", 0, " << "var_" << _i0 << ");\n        else\n          *" << "var_" << _o0 << " = SkGradientShader::MakeTwoPointConical(start, " << "_a1" << "[0], end, " << "_a1" << "[1], " << "_a2" << ", nullptr, colorCount, " << _a4 << ", 0, nullptr);\n        \n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_161" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkShader>::sk_sp<SkShader> SkShaders::Empty();) */
extern "C" void shim_162(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_162" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkShader>);\n        sk_sp<SkShader> ref = SkShaders::Empty();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_162" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkShader>::sk_sp<SkShader> SkShaders::Color(SkColor None);) */
extern "C" void shim_163(void **in_ref, void **out_ref, const char *context) {
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_163" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkShader>);\n        sk_sp<SkShader> ref = SkShaders::Color(" << _a0 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_163" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkShader>::sk_sp<SkShader> SkShaders::Blend(SkBlendMode None, sk_sp<SkShader> None, sk_sp<SkShader> None);) */
extern "C" void shim_164(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
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
    std::cout << "    sk_sp<SkShader> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_164" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkShader>);\n        sk_sp<SkShader> ref = SkShaders::Blend(" << _a0 << ", *" << "var_" << _i0 << ", *" << "var_" << _i1 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_164" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkShader>::sk_sp<SkShader> SkPerlinNoiseShader::MakeTurbulence(SkScalar None, SkScalar None, int None, SkScalar None, SkISize * None);) */
extern "C" void shim_165(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    int _a2;
    memcpy(&_a2, context + 8, sizeof(int));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkISize *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_165" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkShader>);\n        sk_sp<SkShader> ref = SkPerlinNoiseShader::MakeTurbulence(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << "var_" << _i0 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_165" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkShader>::sk_sp<SkShader> SkPerlinNoiseShader::MakeFractalNoise(SkScalar None, SkScalar None, int None, SkScalar None, SkISize * None);) */
extern "C" void shim_166(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    int _a2;
    memcpy(&_a2, context + 8, sizeof(int));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkISize *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_166" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkShader>);\n        sk_sp<SkShader> ref = SkPerlinNoiseShader::MakeFractalNoise(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << "var_" << _i0 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_166" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkShader>::~sk_sp<SkShader>();) */
extern "C" void shim_167(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_167" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_167" << std::endl;
}


/* CPPScope(name=nullptr) */
extern "C" void shim_168(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkPathEffect> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_168" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkPathEffect>);" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_168" << std::endl;
}


/* CPPScope(name=SkDashPathEffect::Make) */
extern "C" void shim_169(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkPathEffect> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_169" << std::endl;
    float _a2[20];
    memcpy(&_a2, context + 8, 4 * 20);
    std::cout << "    float _a2[20] = {";
    for (int i = 0; i < 20; ++i) {
        if (i % 16 == 0 && 20 > 16) std::cout << std::endl << "        ";
        std::cout << _a2[i];
        if (i < 20 - 1) std::cout << ", ";
    }
    if (20 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkPathEffect>);\n        int count = " << _a0 << ";\n        if (count < 0) count = 0;\n        if (count > 20) count = 20;\n        *" << "var_" << _o0 << " = SkDashPathEffect::Make(" << "_a2" << ", count, " << _a1 << ");" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_169" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkPathEffect>::sk_sp<SkPathEffect> SkPathEffect::MakeSum(sk_sp<SkPathEffect> None, sk_sp<SkPathEffect> None);) */
extern "C" void shim_170(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkPathEffect> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPathEffect> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkPathEffect> *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_170" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkPathEffect>);\n        sk_sp<SkPathEffect> ref = SkPathEffect::MakeSum(*" << "var_" << _i0 << ", *" << "var_" << _i1 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_170" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkPathEffect>::sk_sp<SkPathEffect> SkPathEffect::MakeCompose(sk_sp<SkPathEffect> None, sk_sp<SkPathEffect> None);) */
extern "C" void shim_171(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkPathEffect> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPathEffect> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkPathEffect> *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_171" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkPathEffect>);\n        sk_sp<SkPathEffect> ref = SkPathEffect::MakeCompose(*" << "var_" << _i0 << ", *" << "var_" << _i1 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_171" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkPathEffect>::sk_sp<SkPathEffect> SkPath1DPathEffect::Make(SkPath None, SkScalar None, SkScalar None, SkPath1DPathEffect::Style None);) */
extern "C" void shim_172(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    const char *_a2;
    switch (*(reinterpret_cast<const unsigned char *>(context + 8)) % 3) {
        case 0: _a2 = "SkPath1DPathEffect::Style::kTranslate_Style"; break;
        case 1: _a2 = "SkPath1DPathEffect::Style::kRotate_Style"; break;
        case 2: _a2 = "SkPath1DPathEffect::Style::kMorph_Style"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkPathEffect> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_172" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkPathEffect>);\n        sk_sp<SkPathEffect> ref = SkPath1DPathEffect::Make(*" << "var_" << _i0 << ", " << _a0 << ", " << _a1 << ", " << _a2 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_172" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkPathEffect>::sk_sp<SkPathEffect> SkLine2DPathEffect::Make(SkScalar None, SkMatrix None);) */
extern "C" void shim_173(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkPathEffect> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_173" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkPathEffect>);\n        sk_sp<SkPathEffect> ref = SkLine2DPathEffect::Make(" << _a0 << ", *" << "var_" << _i0 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_173" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkPathEffect>::sk_sp<SkPathEffect> SkPath2DPathEffect::Make(SkMatrix None, SkPath None);) */
extern "C" void shim_174(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkPathEffect> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_174" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkPathEffect>);\n        sk_sp<SkPathEffect> ref = SkPath2DPathEffect::Make(*" << "var_" << _i0 << ", *" << "var_" << _i1 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_174" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkPathEffect>::sk_sp<SkPathEffect> SkCornerPathEffect::Make(SkScalar None);) */
extern "C" void shim_175(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkPathEffect> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_175" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkPathEffect>);\n        sk_sp<SkPathEffect> ref = SkCornerPathEffect::Make(" << _a0 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_175" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkPathEffect>::sk_sp<SkPathEffect> SkDiscretePathEffect::Make(SkScalar None, SkScalar None, uint32_t None);) */
extern "C" void shim_176(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    uint32_t _a2;
    memcpy(&_a2, context + 8, sizeof(uint32_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkPathEffect> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_176" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkPathEffect>);\n        sk_sp<SkPathEffect> ref = SkDiscretePathEffect::Make(" << _a0 << ", " << _a1 << ", " << _a2 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_176" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkPathEffect>::~sk_sp<SkPathEffect>();) */
extern "C" void shim_177(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_177" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_177" << std::endl;
}


/* CPPScope(name=nullptr) */
extern "C" void shim_178(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkMaskFilter> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_178" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkMaskFilter>);" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_178" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkMaskFilter>::sk_sp<SkMaskFilter> SkMaskFilter::MakeBlur(SkBlurStyle None, SkScalar None, bool None);) */
extern "C" void shim_179(void **in_ref, void **out_ref, const char *context) {
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = "SkBlurStyle::kNormal_SkBlurStyle"; break;
        case 1: _a0 = "SkBlurStyle::kSolid_SkBlurStyle"; break;
        case 2: _a0 = "SkBlurStyle::kOuter_SkBlurStyle"; break;
        case 3: _a0 = "SkBlurStyle::kInner_SkBlurStyle"; break;
        case 4: _a0 = "SkBlurStyle::kLastEnum_SkBlurStyle"; break;
    }
    float _a1;
    memcpy(&_a1, context + 1, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 5)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkMaskFilter> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_179" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkMaskFilter>);\n        sk_sp<SkMaskFilter> ref = SkMaskFilter::MakeBlur(" << _a0 << ", " << _a1 << ", " << (int)_a2 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_179" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkMaskFilter>::~sk_sp<SkMaskFilter>();) */
extern "C" void shim_180(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_180" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_180" << std::endl;
}


/* CPPScope(name=nullptr) */
extern "C" void shim_181(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkTypeface> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_181" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkTypeface>);" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_181" << std::endl;
}


/* CPPScope(name=fetch_font_style) */
extern "C" void shim_182(void **in_ref, void **out_ref, const char *context) {
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    uint32_t _a1;
    memcpy(&_a1, context + 4, sizeof(uint32_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkTypeface> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_182" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkTypeface>);\n        auto fontMugger = SkFontMgr::RefDefault();\n        int familyCount = fontMugger->countFamilies();\n        sk_sp<SkFontStyleSet> family(fontMugger->createStyleSet(" << _a0 << " % familyCount));\n        int styleCount = family->count();\n        *" << "var_" << _o0 << " = sk_sp<SkTypeface>(family->createTypeface(" << _a1 << " % styleCount));" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_182" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkTypeface>::~sk_sp<SkTypeface>();) */
extern "C" void shim_183(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_183" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_183" << std::endl;
}


/* CPPScope(name=nullptr) */
extern "C" void shim_184(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_184" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_184" << std::endl;
}


/* CPPScope(name=SkImageFilters::MatrixTransform) */
extern "C" void shim_185(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = "SkFilterQuality::kNone_SkFilterQuality"; break;
        case 1: _a0 = "SkFilterQuality::kLow_SkFilterQuality"; break;
        case 2: _a0 = "SkFilterQuality::kMedium_SkFilterQuality"; break;
        case 3: _a0 = "SkFilterQuality::kHigh_SkFilterQuality"; break;
        case 4: _a0 = "SkFilterQuality::kLast_SkFilterQuality"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_185" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        *" << "var_" << _o0 << " = SkImageFilters::MatrixTransform(*" << "var_" << _i1 << ", SkSamplingOptions(" << _a0 << "), *" << "var_" << _i0 << ");\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_185" << std::endl;
}


/* CPPScope(name=SkImageFilters::Image) */
extern "C" void shim_186(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = "SkFilterQuality::kNone_SkFilterQuality"; break;
        case 1: _a0 = "SkFilterQuality::kLow_SkFilterQuality"; break;
        case 2: _a0 = "SkFilterQuality::kMedium_SkFilterQuality"; break;
        case 3: _a0 = "SkFilterQuality::kHigh_SkFilterQuality"; break;
        case 4: _a0 = "SkFilterQuality::kLast_SkFilterQuality"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_186" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        *" << "var_" << _o0 << " = SkImageFilters::Image(*" << "var_" << _i0 << ", *" << "var_" << _i1 << ", *" << "var_" << _i2 << ", SkSamplingOptions(" << _a0 << "));\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_186" << std::endl;
}


/* CPPScope(name=SkImageFilters::MatrixConvolution) */
extern "C" void shim_187(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    uint8_t _a1;
    memcpy(&_a1, context + 1, sizeof(uint8_t));
    float _a3;
    memcpy(&_a3, context + 102, sizeof(float));
    float _a4;
    memcpy(&_a4, context + 106, sizeof(float));
    uint8_t _a5;
    memcpy(&_a5, context + 110, sizeof(uint8_t));
    uint8_t _a6;
    memcpy(&_a6, context + 111, sizeof(uint8_t));
    const char *_a7;
    switch (*(reinterpret_cast<const unsigned char *>(context + 112)) % 5) {
        case 0: _a7 = "SkTileMode::kClamp"; break;
        case 1: _a7 = "SkTileMode::kRepeat"; break;
        case 2: _a7 = "SkTileMode::kMirror"; break;
        case 3: _a7 = "SkTileMode::kDecal"; break;
        case 4: _a7 = "SkTileMode::kLastTileMode"; break;
    }
    bool _a8 = *(static_cast<const char *>(context + 113)) & 1;
    bool _a9 = *(static_cast<const char *>(context + 114)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_187" << std::endl;
    float _a2[25];
    memcpy(&_a2, context + 2, 4 * 25);
    std::cout << "    float _a2[25] = {";
    for (int i = 0; i < 25; ++i) {
        if (i % 16 == 0 && 25 > 16) std::cout << std::endl << "        ";
        std::cout << _a2[i];
        if (i < 25 - 1) std::cout << ", ";
    }
    if (25 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        int32_t n = (" << (int)_a0 << " % (5-1)) + 1;\n        int32_t m = (" << (int)_a1 << " % (5-1)) + 1;\n        int32_t offsetX = (" << (int)_a5 << " % n);\n        int32_t offsetY = (" << (int)_a6 << " % n);\n        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        *" << "var_" << _o0 << " = SkImageFilters::MatrixConvolution(\n          SkISize{n, m}, " << "_a2" << ", " << _a3 << ", " << _a4 << ", SkIPoint{offsetX, offsetY},\n          " << _a7 << ", " << (int)_a8 << ", *" << "var_" << _i0 << ", " << (int)_a9 << " ? " << "var_" << _i1 << " : nullptr\n        );\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_187" << std::endl;
}


/* CPPScope(name=merge_1) */
extern "C" void shim_188(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_188" << std::endl;

    std::cout << "        sk_sp<SkImageFilter> ifs[] = {*" << "var_" << _i0 << "};\n        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        *" << "var_" << _o0 << " = SkImageFilters::Merge(ifs, 1, " << (int)_a0 << " ? " << "var_" << _i1 << " : nullptr);\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_188" << std::endl;
}


/* CPPScope(name=merge_2) */
extern "C" void shim_189(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_189" << std::endl;

    std::cout << "        sk_sp<SkImageFilter> ifs[] = {*" << "var_" << _i0 << ", *" << "var_" << _i1 << "};\n        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        *" << "var_" << _o0 << " = SkImageFilters::Merge(ifs, 2, " << (int)_a0 << " ? " << "var_" << _i2 << " : nullptr);\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_189" << std::endl;
}


/* CPPScope(name=merge_3) */
extern "C" void shim_190(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o3 << ";" << std::endl;
    unsigned long _o4 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o4 << ";" << std::endl;

    std::cout << "    { // begin shim_190" << std::endl;

    std::cout << "        sk_sp<SkImageFilter> ifs[] = {*" << "var_" << _i0 << ", *" << "var_" << _i1 << ", *" << "var_" << _i2 << "};\n        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        *" << "var_" << _o0 << " = SkImageFilters::Merge(ifs, 3, " << (int)_a0 << " ? " << "var_" << _i3 << " : nullptr);\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o4 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);

    std::cout << "    } // end shim_190" << std::endl;
}


/* CPPScope(name=merge_4) */
extern "C" void shim_191(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _i4 = reinterpret_cast<unsigned long>(in_ref[4]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o3 << ";" << std::endl;
    unsigned long _o4 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o4 << ";" << std::endl;
    unsigned long _o5 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o5 << ";" << std::endl;

    std::cout << "    { // begin shim_191" << std::endl;

    std::cout << "        sk_sp<SkImageFilter> ifs[] = {*" << "var_" << _i0 << ", *" << "var_" << _i1 << ", *" << "var_" << _i2 << ", *" << "var_" << _i3 << "};\n        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        *" << "var_" << _o0 << " = SkImageFilters::Merge(ifs, 4, " << (int)_a0 << " ? " << "var_" << _i4 << " : nullptr);\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o4 << " = " << "var_" << _i3 << ";\n        " << "var_" << _o5 << " = " << "var_" << _i4 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);
    out_ref[5] = reinterpret_cast<void *>(_o5);

    std::cout << "    } // end shim_191" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DistantLitDiffuse(SkPoint3 p, SkColor lightColor, SkScalar surfaceScale, SkScalar k, sk_sp<SkImageFilter> input, SkIRect * cropRect);) */
extern "C" void shim_192(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint3 *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_192" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::DistantLitDiffuse(*" << "var_" << _i0 << ", " << _a0 << ", " << _a1 << ", " << _a2 << ", *" << "var_" << _i1 << ", " << "var_" << _i2 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_192" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DistantLitDiffuse(SkPoint3 p, SkColor lightColor, SkScalar surfaceScale, SkScalar k, sk_sp<SkImageFilter> input, {nullptr});) */
extern "C" void shim_193(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint3 *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_193" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::DistantLitDiffuse(*" << "var_" << _i0 << ", " << _a0 << ", " << _a1 << ", " << _a2 << ", *" << "var_" << _i1 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_193" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::PointLitDiffuse(SkPoint3 p, SkColor lightColor, SkScalar surfaceScale, SkScalar k, sk_sp<SkImageFilter> input, SkIRect * cropRect);) */
extern "C" void shim_194(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint3 *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_194" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::PointLitDiffuse(*" << "var_" << _i0 << ", " << _a0 << ", " << _a1 << ", " << _a2 << ", *" << "var_" << _i1 << ", " << "var_" << _i2 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_194" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::PointLitDiffuse(SkPoint3 p, SkColor lightColor, SkScalar surfaceScale, SkScalar k, sk_sp<SkImageFilter> input, {nullptr});) */
extern "C" void shim_195(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint3 *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_195" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::PointLitDiffuse(*" << "var_" << _i0 << ", " << _a0 << ", " << _a1 << ", " << _a2 << ", *" << "var_" << _i1 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_195" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::SpotLitDiffuse(SkPoint3 p, SkPoint3 q, SkScalar specularExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar k, sk_sp<SkImageFilter> input, SkIRect * cropRect);) */
extern "C" void shim_196(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
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
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint3 *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPoint3 *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o3 << ";" << std::endl;
    unsigned long _o4 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o4 << ";" << std::endl;

    std::cout << "    { // begin shim_196" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::SpotLitDiffuse(*" << "var_" << _i0 << ", *" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ", *" << "var_" << _i2 << ", " << "var_" << _i3 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o4 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);

    std::cout << "    } // end shim_196" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::SpotLitDiffuse(SkPoint3 p, SkPoint3 q, SkScalar specularExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar k, sk_sp<SkImageFilter> input, {nullptr});) */
extern "C" void shim_197(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
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
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint3 *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPoint3 *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_197" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::SpotLitDiffuse(*" << "var_" << _i0 << ", *" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ", *" << "var_" << _i2 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_197" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DistantLitSpecular(SkPoint3 p, SkColor lightColor, SkScalar surfaceScale, SkScalar k, SkScalar shininess, sk_sp<SkImageFilter> input, SkIRect * cropRect);) */
extern "C" void shim_198(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint3 *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_198" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::DistantLitSpecular(*" << "var_" << _i0 << ", " << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", *" << "var_" << _i1 << ", " << "var_" << _i2 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_198" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DistantLitSpecular(SkPoint3 p, SkColor lightColor, SkScalar surfaceScale, SkScalar k, SkScalar shininess, sk_sp<SkImageFilter> input, {nullptr});) */
extern "C" void shim_199(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint3 *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_199" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::DistantLitSpecular(*" << "var_" << _i0 << ", " << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", *" << "var_" << _i1 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_199" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::PointLitSpecular(SkPoint3 p, SkColor lightColor, SkScalar surfaceScale, SkScalar k, SkScalar shininess, sk_sp<SkImageFilter> input, SkIRect * cropRect);) */
extern "C" void shim_200(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint3 *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_200" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::PointLitSpecular(*" << "var_" << _i0 << ", " << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", *" << "var_" << _i1 << ", " << "var_" << _i2 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_200" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::PointLitSpecular(SkPoint3 p, SkColor lightColor, SkScalar surfaceScale, SkScalar k, SkScalar shininess, sk_sp<SkImageFilter> input, {nullptr});) */
extern "C" void shim_201(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint3 *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_201" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::PointLitSpecular(*" << "var_" << _i0 << ", " << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", *" << "var_" << _i1 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_201" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::SpotLitSpecular(SkPoint3 p, SkPoint3 q, SkScalar specularExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar k, SkScalar shininess, sk_sp<SkImageFilter> input, SkIRect * cropRect);) */
extern "C" void shim_202(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
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
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint3 *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPoint3 *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o3 << ";" << std::endl;
    unsigned long _o4 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o4 << ";" << std::endl;

    std::cout << "    { // begin shim_202" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::SpotLitSpecular(*" << "var_" << _i0 << ", *" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ", " << _a5 << ", *" << "var_" << _i2 << ", " << "var_" << _i3 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o4 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);

    std::cout << "    } // end shim_202" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::SpotLitSpecular(SkPoint3 p, SkPoint3 q, SkScalar specularExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar k, SkScalar shininess, sk_sp<SkImageFilter> input, {nullptr});) */
extern "C" void shim_203(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
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
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint3 *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPoint3 *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_203" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::SpotLitSpecular(*" << "var_" << _i0 << ", *" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ", " << _a5 << ", *" << "var_" << _i2 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_203" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Blur(SkScalar None, SkScalar None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_204(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_204" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Blur(" << _a0 << ", " << _a1 << ", *" << "var_" << _i0 << ", " << "var_" << _i1 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_204" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Blur(SkScalar None, SkScalar None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_205(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_205" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Blur(" << _a0 << ", " << _a1 << ", *" << "var_" << _i0 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_205" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::AlphaThreshold(SkRegion None, SkScalar None, SkScalar None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_206(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_206" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::AlphaThreshold(*" << "var_" << _i0 << ", " << _a0 << ", " << _a1 << ", *" << "var_" << _i1 << ", " << "var_" << _i2 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_206" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::AlphaThreshold(SkRegion None, SkScalar None, SkScalar None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_207(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_207" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::AlphaThreshold(*" << "var_" << _i0 << ", " << _a0 << ", " << _a1 << ", *" << "var_" << _i1 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_207" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Arithmetic(float None, float None, float None, float None, bool None, sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_208(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 12, sizeof(float));
    bool _a4 = *(static_cast<const char *>(context + 16)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_208" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Arithmetic(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << (int)_a4 << ", *" << "var_" << _i0 << ", *" << "var_" << _i1 << ", " << "var_" << _i2 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_208" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Arithmetic(float None, float None, float None, float None, bool None, sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_209(void **in_ref, void **out_ref, const char *context) {
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
    bool _a4 = *(static_cast<const char *>(context + 16)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_209" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Arithmetic(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << (int)_a4 << ", *" << "var_" << _i0 << ", *" << "var_" << _i1 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_209" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::ColorFilter(sk_sp<SkColorFilter> None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_210(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkColorFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_210" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::ColorFilter(*" << "var_" << _i0 << ", *" << "var_" << _i1 << ", " << "var_" << _i2 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_210" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::ColorFilter(sk_sp<SkColorFilter> None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_211(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkColorFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_211" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::ColorFilter(*" << "var_" << _i0 << ", *" << "var_" << _i1 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_211" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Compose(sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None);) */
extern "C" void shim_212(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_212" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Compose(*" << "var_" << _i0 << ", *" << "var_" << _i1 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_212" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DisplacementMap(SkColorChannel None, SkColorChannel None, SkScalar None, sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_213(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = "SkColorChannel::kR"; break;
        case 1: _a0 = "SkColorChannel::kG"; break;
        case 2: _a0 = "SkColorChannel::kB"; break;
        case 3: _a0 = "SkColorChannel::kA"; break;
        case 4: _a0 = "SkColorChannel::kLastEnum"; break;
    }
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 1)) % 5) {
        case 0: _a1 = "SkColorChannel::kR"; break;
        case 1: _a1 = "SkColorChannel::kG"; break;
        case 2: _a1 = "SkColorChannel::kB"; break;
        case 3: _a1 = "SkColorChannel::kA"; break;
        case 4: _a1 = "SkColorChannel::kLastEnum"; break;
    }
    float _a2;
    memcpy(&_a2, context + 2, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_213" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::DisplacementMap(" << _a0 << ", " << _a1 << ", " << _a2 << ", *" << "var_" << _i0 << ", *" << "var_" << _i1 << ", " << "var_" << _i2 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_213" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DisplacementMap(SkColorChannel None, SkColorChannel None, SkScalar None, sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_214(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 5) {
        case 0: _a0 = "SkColorChannel::kR"; break;
        case 1: _a0 = "SkColorChannel::kG"; break;
        case 2: _a0 = "SkColorChannel::kB"; break;
        case 3: _a0 = "SkColorChannel::kA"; break;
        case 4: _a0 = "SkColorChannel::kLastEnum"; break;
    }
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 1)) % 5) {
        case 0: _a1 = "SkColorChannel::kR"; break;
        case 1: _a1 = "SkColorChannel::kG"; break;
        case 2: _a1 = "SkColorChannel::kB"; break;
        case 3: _a1 = "SkColorChannel::kA"; break;
        case 4: _a1 = "SkColorChannel::kLastEnum"; break;
    }
    float _a2;
    memcpy(&_a2, context + 2, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_214" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::DisplacementMap(" << _a0 << ", " << _a1 << ", " << _a2 << ", *" << "var_" << _i0 << ", *" << "var_" << _i1 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_214" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DropShadowOnly(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkColor None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_215(void **in_ref, void **out_ref, const char *context) {
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
    uint32_t _a4;
    memcpy(&_a4, context + 16, sizeof(uint32_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_215" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::DropShadowOnly(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ", *" << "var_" << _i0 << ", " << "var_" << _i1 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_215" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DropShadowOnly(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkColor None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_216(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
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
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_216" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::DropShadowOnly(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ", *" << "var_" << _i0 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_216" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DropShadow(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkColor None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_217(void **in_ref, void **out_ref, const char *context) {
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
    uint32_t _a4;
    memcpy(&_a4, context + 16, sizeof(uint32_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_217" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::DropShadow(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ", *" << "var_" << _i0 << ", " << "var_" << _i1 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_217" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::DropShadow(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkColor None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_218(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
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
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_218" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::DropShadow(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ", *" << "var_" << _i0 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_218" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Image(sk_sp<SkImage> None);) */
extern "C" void shim_219(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_219" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Image(*" << "var_" << _i0 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_219" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Magnifier(SkRect None, SkScalar None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_220(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_220" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Magnifier(*" << "var_" << _i0 << ", " << _a0 << ", *" << "var_" << _i1 << ", " << "var_" << _i2 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_220" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Magnifier(SkRect None, SkScalar None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_221(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_221" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Magnifier(*" << "var_" << _i0 << ", " << _a0 << ", *" << "var_" << _i1 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_221" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Merge(sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_222(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_222" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Merge(*" << "var_" << _i0 << ", *" << "var_" << _i1 << ", " << "var_" << _i2 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_222" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Merge(sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_223(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_223" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Merge(*" << "var_" << _i0 << ", *" << "var_" << _i1 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_223" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Dilate(int None, int None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_224(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_224" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Dilate(" << _a0 << ", " << _a1 << ", *" << "var_" << _i0 << ", " << "var_" << _i1 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_224" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Dilate(int None, int None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_225(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_225" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Dilate(" << _a0 << ", " << _a1 << ", *" << "var_" << _i0 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_225" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Erode(int None, int None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_226(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_226" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Erode(" << _a0 << ", " << _a1 << ", *" << "var_" << _i0 << ", " << "var_" << _i1 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_226" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Erode(int None, int None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_227(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_227" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Erode(" << _a0 << ", " << _a1 << ", *" << "var_" << _i0 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_227" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Offset(SkScalar None, SkScalar None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_228(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_228" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Offset(" << _a0 << ", " << _a1 << ", *" << "var_" << _i0 << ", " << "var_" << _i1 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_228" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Offset(SkScalar None, SkScalar None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_229(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_229" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Offset(" << _a0 << ", " << _a1 << ", *" << "var_" << _i0 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_229" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Paint(SkPaint None, SkIRect * None);) */
extern "C" void shim_230(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_230" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Paint(*" << "var_" << _i0 << ", " << "var_" << _i1 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_230" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Paint(SkPaint None, {nullptr});) */
extern "C" void shim_231(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_231" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Paint(*" << "var_" << _i0 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_231" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Picture(sk_sp<SkPicture> None);) */
extern "C" void shim_232(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPicture> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_232" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Picture(*" << "var_" << _i0 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_232" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Picture(sk_sp<SkPicture> None, SkRect None);) */
extern "C" void shim_233(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPicture> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_233" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Picture(*" << "var_" << _i0 << ", *" << "var_" << _i1 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_233" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Tile(SkRect None, SkRect None, sk_sp<SkImageFilter> None);) */
extern "C" void shim_234(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_234" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Tile(*" << "var_" << _i0 << ", *" << "var_" << _i1 << ", *" << "var_" << _i2 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_234" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Blend(SkBlendMode None, sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None, SkIRect * None);) */
extern "C" void shim_235(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
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
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_235" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Blend(" << _a0 << ", *" << "var_" << _i0 << ", *" << "var_" << _i1 << ", " << "var_" << _i2 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_235" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Blend(SkBlendMode None, sk_sp<SkImageFilter> None, sk_sp<SkImageFilter> None, {nullptr});) */
extern "C" void shim_236(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
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
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_236" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Blend(" << _a0 << ", *" << "var_" << _i0 << ", *" << "var_" << _i1 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_236" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Shader(sk_sp<SkShader> None, SkIRect * None);) */
extern "C" void shim_237(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_237" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Shader(*" << "var_" << _i0 << ", " << "var_" << _i1 << ");\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_237" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::sk_sp<SkImageFilter> SkImageFilters::Shader(sk_sp<SkShader> None, {nullptr});) */
extern "C" void shim_238(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkShader> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_238" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkImageFilter>);\n        sk_sp<SkImageFilter> ref = SkImageFilters::Shader(*" << "var_" << _i0 << ", nullptr);\n        *" << "var_" << _o0 << " = ref;\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_238" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkImageFilter>::~sk_sp<SkImageFilter>();) */
extern "C" void shim_239(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_239" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_239" << std::endl;
}


/* CPPScope(name=(auto) sk_sp<SkTextBlob>::~sk_sp<SkTextBlob>();) */
extern "C" void shim_240(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_240" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_240" << std::endl;
}


/* CPPScope(name=SkTextBlobBuilder) */
extern "C" void shim_241(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkTextBlobBuilder *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_241" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new SkTextBlobBuilder();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_241" << std::endl;
}


/* CPPScope(name=delete) */
extern "C" void shim_242(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_242" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    } // end shim_242" << std::endl;
}


/* CPPScope(name=make) */
extern "C" void shim_243(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    sk_sp<SkTextBlob> *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_243" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(sk_sp<SkTextBlob>);\n        *" << "var_" << _o0 << " = " << "var_" << _i0 << "->make();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_243" << std::endl;
}


/* CPPScope(name=allocRun) */
extern "C" void shim_244(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 128)) % 4) {
        case 0: _a1 = "SkTextEncoding::kUTF8"; break;
        case 1: _a1 = "SkTextEncoding::kUTF16"; break;
        case 2: _a1 = "SkTextEncoding::kUTF32"; break;
        case 3: _a1 = "SkTextEncoding::kGlyphID"; break;
    }
    float _a2;
    memcpy(&_a2, context + 129, sizeof(float));
    float _a3;
    memcpy(&_a3, context + 133, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkTextBlobBuilder *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_244" << std::endl;
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    std::cout << "    uint8_t _a0[128] = {";
    for (int i = 0; i < 128; ++i) {
        if (i % 16 == 0 && 128 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 128 - 1) std::cout << ", ";
    }
    if (128 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        Fuzz f(" << "_a0" << ", 128);\n        SkTDArray<uint8_t> text = make_fuzz_text(&f, *" << "var_" << _i1 << ", " << _a1 << ");\n        int glyphCount = " << "var_" << _i1 << "->countText(text.begin(), SkToSizeT(text.count()), " << _a1 << ");\n        const void* textPtr = text.begin();\n        size_t textLen =  SkToSizeT(text.count());\n        \n        const SkTextBlobBuilder::RunBuffer* buffer;\n        buffer = &" << "var_" << _i0 << "->allocRun(*" << "var_" << _i1 << ", glyphCount, " << _a2 << ", " << _a3 << ");\n        " << "var_" << _i1 << "->textToGlyphs(textPtr, textLen, " << _a1 << ", buffer->glyphs, glyphCount);\n        \n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_244" << std::endl;
}


/* CPPScope(name=allocRunPosH) */
extern "C" void shim_245(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 128)) % 4) {
        case 0: _a1 = "SkTextEncoding::kUTF8"; break;
        case 1: _a1 = "SkTextEncoding::kUTF16"; break;
        case 2: _a1 = "SkTextEncoding::kUTF32"; break;
        case 3: _a1 = "SkTextEncoding::kGlyphID"; break;
    }
    float _a2;
    memcpy(&_a2, context + 129, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkTextBlobBuilder *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_245" << std::endl;
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    std::cout << "    uint8_t _a0[128] = {";
    for (int i = 0; i < 128; ++i) {
        if (i % 16 == 0 && 128 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 128 - 1) std::cout << ", ";
    }
    if (128 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    float _a3[32];
    memcpy(&_a3, context + 133, 4 * 32);
    std::cout << "    float _a3[32] = {";
    for (int i = 0; i < 32; ++i) {
        if (i % 16 == 0 && 32 > 16) std::cout << std::endl << "        ";
        std::cout << _a3[i];
        if (i < 32 - 1) std::cout << ", ";
    }
    if (32 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        Fuzz f(" << "_a0" << ", 128);\n        SkTDArray<uint8_t> text = make_fuzz_text(&f, *" << "var_" << _i1 << ", " << _a1 << ");\n        int glyphCount = " << "var_" << _i1 << "->countText(text.begin(), SkToSizeT(text.count()), " << _a1 << ");\n        const void* textPtr = text.begin();\n        size_t textLen =  SkToSizeT(text.count());\n        \n        const SkTextBlobBuilder::RunBuffer* buffer;\n        buffer = &" << "var_" << _i0 << "->allocRunPosH(*" << "var_" << _i1 << ", glyphCount, " << _a2 << ");\n        " << "var_" << _i1 << "->textToGlyphs(textPtr, textLen, " << _a1 << ", buffer->glyphs, glyphCount);\n        \n        for (int i = 0; (i < glyphCount) && (i < 32); ++i) {\n          buffer->pos[i] = " << "_a3" << "[i];\n        }\n        \n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_245" << std::endl;
}


/* CPPScope(name=allocRunPos) */
extern "C" void shim_246(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 128)) % 4) {
        case 0: _a1 = "SkTextEncoding::kUTF8"; break;
        case 1: _a1 = "SkTextEncoding::kUTF16"; break;
        case 2: _a1 = "SkTextEncoding::kUTF32"; break;
        case 3: _a1 = "SkTextEncoding::kGlyphID"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkTextBlobBuilder *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_246" << std::endl;
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    std::cout << "    uint8_t _a0[128] = {";
    for (int i = 0; i < 128; ++i) {
        if (i % 16 == 0 && 128 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 128 - 1) std::cout << ", ";
    }
    if (128 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    float _a2[64];
    memcpy(&_a2, context + 129, 4 * 64);
    std::cout << "    float _a2[64] = {";
    for (int i = 0; i < 64; ++i) {
        if (i % 16 == 0 && 64 > 16) std::cout << std::endl << "        ";
        std::cout << _a2[i];
        if (i < 64 - 1) std::cout << ", ";
    }
    if (64 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        Fuzz f(" << "_a0" << ", 128);\n        SkTDArray<uint8_t> text = make_fuzz_text(&f, *" << "var_" << _i1 << ", " << _a1 << ");\n        int glyphCount = " << "var_" << _i1 << "->countText(text.begin(), SkToSizeT(text.count()), " << _a1 << ");\n        const void* textPtr = text.begin();\n        size_t textLen =  SkToSizeT(text.count());\n        \n        const SkTextBlobBuilder::RunBuffer* buffer;\n        buffer = &" << "var_" << _i0 << "->allocRunPos(*" << "var_" << _i1 << ", glyphCount);\n        " << "var_" << _i1 << "->textToGlyphs(textPtr, textLen, " << _a1 << ", buffer->glyphs, glyphCount);\n        \n        for (int i = 0; (i < (glyphCount * 2)) && (i < 64); ++i) {\n          buffer->pos[i] = " << "_a2" << "[i];\n        }\n        \n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_246" << std::endl;
}


/* CPPScope(name=bundled_canvas_saveLayer) */
extern "C" void shim_247(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    bool _a2 = *(static_cast<const char *>(context + 2)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_247" << std::endl;

    std::cout << "        SkCanvas::SaveLayerRec saveLayerRec;\n        if (" << (int)_a0 << ") saveLayerRec.fBounds = " << "var_" << _i1 << ";\n        if (" << (int)_a1 << ") saveLayerRec.fPaint = " << "var_" << _i2 << ";\n        if (" << (int)_a2 << ") saveLayerRec.fBackdrop = " << "var_" << _i3 << "->get();\n        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->saveLayer(saveLayerRec);\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_247" << std::endl;
}


/* CPPScope(name=bundled_canvas_drawPoints) */
extern "C" void shim_248(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a1;
    memcpy(&_a1, context + 240, sizeof(int));
    const char *_a2;
    switch (*(reinterpret_cast<const unsigned char *>(context + 244)) % 3) {
        case 0: _a2 = "SkCanvas::PointMode::kPoints_PointMode"; break;
        case 1: _a2 = "SkCanvas::PointMode::kLines_PointMode"; break;
        case 2: _a2 = "SkCanvas::PointMode::kPolygon_PointMode"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_248" << std::endl;
    float _a0[60];
    memcpy(&_a0, context + 0, 4 * 60);
    std::cout << "    float _a0[60] = {";
    for (int i = 0; i < 60; ++i) {
        if (i % 16 == 0 && 60 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 60 - 1) std::cout << ", ";
    }
    if (60 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        int count = " << _a1 << " % 30;\n        SkPoint pts[30];\n        for (int i = 0; i < count; ++i) {\n          pts[i] = SkPoint::Make(" << "_a0" << "[i*2], " << "_a0" << "[(i*2)+1]);\n        }\n        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPoints(" << _a2 << ", count, pts, *" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_248" << std::endl;
}


/* CPPScope(name=bundled_drawImage) */
extern "C" void shim_249(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_249" << std::endl;

    std::cout << "        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawImage(" << "var_" << _i1 << "->get(), " << _a0 << ", " << _a1 << ", SkSamplingOptions(), " << (int)_a2 << " ? " << "var_" << _i2 << " : nullptr);\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_249" << std::endl;
}


/* CPPScope(name=bundled_drawImageRect) */
extern "C" void shim_250(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _i4 = reinterpret_cast<unsigned long>(in_ref[4]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
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

    std::cout << "    { // begin shim_250" << std::endl;

    std::cout << "        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawImageRect(" << "var_" << _i1 << "->get(), *" << "var_" << _i2 << ", *" << "var_" << _i3 << ", SkSamplingOptions(), " << (int)_a0 << " ? " << "var_" << _i4 << " : nullptr, " << (int)_a1 << " ? SkCanvas::kStrict_SrcRectConstraint : SkCanvas::kFast_SrcRectConstraint);\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";\n        " << "var_" << _o4 << " = " << "var_" << _i4 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);

    std::cout << "    } // end shim_250" << std::endl;
}


/* CPPScope(name=bundled_drawImageNine) */
extern "C" void shim_251(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _i4 = reinterpret_cast<unsigned long>(in_ref[4]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o3 << ";" << std::endl;
    unsigned long _o4 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o4 << ";" << std::endl;

    std::cout << "    { // begin shim_251" << std::endl;

    std::cout << "        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawImageNine(" << "var_" << _i1 << "->get(), *" << "var_" << _i2 << ", *" << "var_" << _i3 << ", SkFilterMode::kNearest, " << (int)_a0 << " ? " << "var_" << _i4 << " : nullptr);\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";\n        " << "var_" << _o4 << " = " << "var_" << _i4 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);

    std::cout << "    } // end shim_251" << std::endl;
}


/* CPPScope(name=bundled_canvas_drawImageLattice) */
extern "C" void shim_252(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    int _a2;
    memcpy(&_a2, context + 48, sizeof(int));
    int _a3;
    memcpy(&_a3, context + 52, sizeof(int));
    bool _a4 = *(static_cast<const char *>(context + 56)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_252" << std::endl;
    int _a0[6];
    memcpy(&_a0, context + 0, 4 * 6);
    std::cout << "    int _a0[6] = {";
    for (int i = 0; i < 6; ++i) {
        if (i % 16 == 0 && 6 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 6 - 1) std::cout << ", ";
    }
    if (6 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    int _a1[6];
    memcpy(&_a1, context + 24, 4 * 6);
    std::cout << "    int _a1[6] = {";
    for (int i = 0; i < 6; ++i) {
        if (i % 16 == 0 && 6 > 16) std::cout << std::endl << "        ";
        std::cout << _a1[i];
        if (i < 6 - 1) std::cout << ", ";
    }
    if (6 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        SkCanvas::Lattice lattice{\n          " << "_a0" << ", \n          " << "_a1" << ", \n          nullptr, \n          (" << _a2 << " % (6-2)) + 2,\n          (" << _a3 << " % (6-2)) + 2, \n          nullptr, \n          nullptr\n        };\n        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawImageLattice(" << "var_" << _i1 << "->get(), lattice, *" << "var_" << _i2 << ", SkFilterMode::kLinear, " << (int)_a4 << " ? " << "var_" << _i3 << " : nullptr);\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_252" << std::endl;
}


/* CPPScope(name=bundled_canvas_drawSimpleText) */
extern "C" void shim_253(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a1;
    memcpy(&_a1, context + 128, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 132, sizeof(float));
    const char *_a3;
    switch (*(reinterpret_cast<const unsigned char *>(context + 136)) % 4) {
        case 0: _a3 = "SkTextEncoding::kUTF8"; break;
        case 1: _a3 = "SkTextEncoding::kUTF16"; break;
        case 2: _a3 = "SkTextEncoding::kUTF32"; break;
        case 3: _a3 = "SkTextEncoding::kGlyphID"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_253" << std::endl;
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    std::cout << "    uint8_t _a0[128] = {";
    for (int i = 0; i < 128; ++i) {
        if (i % 16 == 0 && 128 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 128 - 1) std::cout << ", ";
    }
    if (128 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        Fuzz f = Fuzz(" << "_a0" << ", 128);\n        SkTDArray<uint8_t> text = make_fuzz_text(&f, *" << "var_" << _i1 << ", " << _a3 << ");\n        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawSimpleText(\n          text.begin(), \n          SkToSizeT(text.count()),\n          " << _a3 << ",\n          " << _a1 << ",\n          " << _a2 << ",\n          *" << "var_" << _i1 << ",\n          *" << "var_" << _i2 << "\n        );\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_253" << std::endl;
}


/* CPPScope(name=bundled_canvas_drawVertices) */
extern "C" void shim_254(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 3) {
        case 0: _a0 = "SkVertices::VertexMode::kTriangles_VertexMode"; break;
        case 1: _a0 = "SkVertices::VertexMode::kTriangleStrip_VertexMode"; break;
        case 2: _a0 = "SkVertices::VertexMode::kTriangleFan_VertexMode"; break;
    }
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 1)) % 32) {
        case 0: _a1 = "SkBlendMode::kClear"; break;
        case 1: _a1 = "SkBlendMode::kSrc"; break;
        case 2: _a1 = "SkBlendMode::kDst"; break;
        case 3: _a1 = "SkBlendMode::kSrcOver"; break;
        case 4: _a1 = "SkBlendMode::kDstOver"; break;
        case 5: _a1 = "SkBlendMode::kSrcIn"; break;
        case 6: _a1 = "SkBlendMode::kDstIn"; break;
        case 7: _a1 = "SkBlendMode::kSrcOut"; break;
        case 8: _a1 = "SkBlendMode::kDstOut"; break;
        case 9: _a1 = "SkBlendMode::kSrcATop"; break;
        case 10: _a1 = "SkBlendMode::kDstATop"; break;
        case 11: _a1 = "SkBlendMode::kXor"; break;
        case 12: _a1 = "SkBlendMode::kPlus"; break;
        case 13: _a1 = "SkBlendMode::kModulate"; break;
        case 14: _a1 = "SkBlendMode::kScreen"; break;
        case 15: _a1 = "SkBlendMode::kOverlay"; break;
        case 16: _a1 = "SkBlendMode::kDarken"; break;
        case 17: _a1 = "SkBlendMode::kLighten"; break;
        case 18: _a1 = "SkBlendMode::kColorDodge"; break;
        case 19: _a1 = "SkBlendMode::kColorBurn"; break;
        case 20: _a1 = "SkBlendMode::kHardLight"; break;
        case 21: _a1 = "SkBlendMode::kSoftLight"; break;
        case 22: _a1 = "SkBlendMode::kDifference"; break;
        case 23: _a1 = "SkBlendMode::kExclusion"; break;
        case 24: _a1 = "SkBlendMode::kMultiply"; break;
        case 25: _a1 = "SkBlendMode::kHue"; break;
        case 26: _a1 = "SkBlendMode::kSaturation"; break;
        case 27: _a1 = "SkBlendMode::kColor"; break;
        case 28: _a1 = "SkBlendMode::kLuminosity"; break;
        case 29: _a1 = "SkBlendMode::kLastCoeffMode"; break;
        case 30: _a1 = "SkBlendMode::kLastSeparableMode"; break;
        case 31: _a1 = "SkBlendMode::kLastMode"; break;
    }
    int _a5;
    memcpy(&_a5, context + 2002, sizeof(int));
    bool _a6 = *(static_cast<const char *>(context + 2006)) & 1;
    bool _a7 = *(static_cast<const char *>(context + 2007)) & 1;
    bool _a8 = *(static_cast<const char *>(context + 2008)) & 1;
    int _a10;
    memcpy(&_a10, context + 2409, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_254" << std::endl;
    float _a2[200];
    memcpy(&_a2, context + 2, 4 * 200);
    std::cout << "    float _a2[200] = {";
    for (int i = 0; i < 200; ++i) {
        if (i % 16 == 0 && 200 > 16) std::cout << std::endl << "        ";
        std::cout << _a2[i];
        if (i < 200 - 1) std::cout << ", ";
    }
    if (200 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    float _a3[200];
    memcpy(&_a3, context + 802, 4 * 200);
    std::cout << "    float _a3[200] = {";
    for (int i = 0; i < 200; ++i) {
        if (i % 16 == 0 && 200 > 16) std::cout << std::endl << "        ";
        std::cout << _a3[i];
        if (i < 200 - 1) std::cout << ", ";
    }
    if (200 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint32_t _a4[100];
    memcpy(&_a4, context + 1602, 4 * 100);
    std::cout << "    uint32_t _a4[100] = {";
    for (int i = 0; i < 100; ++i) {
        if (i % 16 == 0 && 100 > 16) std::cout << std::endl << "        ";
        std::cout << _a4[i];
        if (i < 100 - 1) std::cout << ", ";
    }
    if (100 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint16_t _a9[200];
    memcpy(&_a9, context + 2009, 2 * 200);
    std::cout << "    uint16_t _a9[200] = {";
    for (int i = 0; i < 200; ++i) {
        if (i % 16 == 0 && 200 > 16) std::cout << std::endl << "        ";
        std::cout << _a9[i];
        if (i < 200 - 1) std::cout << ", ";
    }
    if (200 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        int vertexCount = (" << _a5 << " % (100 - 3)) + 3;\n        \n        SkPoint vertices[100];\n        SkPoint texs[100];\n        \n        for (int i = 0; i < vertexCount; ++i) {\n          vertices[i] = SkPoint::Make(" << "_a2" << "[i*2], " << "_a2" << "[(i*2)+1]);\n          texs[i] = SkPoint::Make(" << "_a3" << "[i*2], " << "_a3" << "[(i*2)+1]);\n        }\n        \n        int indexCount = " << (int)_a8 << " ? ((" << _a10 << " % 100) + vertexCount) : 0;\n        \n        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawVertices(SkVertices::MakeCopy(\n            " << _a0 << ", vertexCount, vertices,\n            " << (int)_a6 << " ? texs : nullptr,\n            " << (int)_a7 << " ? " << "_a4" << " : nullptr,\n            indexCount, " << "_a9" << "\n          ), " << _a1 << ", *" << "var_" << _i1 << "\n        );\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_254" << std::endl;
}


/* CPPScope(name=bundled_void drawColor(SkColor4f, SkBlendMode)) */
extern "C" void shim_255(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 4)) % 32) {
        case 0: _a1 = "SkBlendMode::kClear"; break;
        case 1: _a1 = "SkBlendMode::kSrc"; break;
        case 2: _a1 = "SkBlendMode::kDst"; break;
        case 3: _a1 = "SkBlendMode::kSrcOver"; break;
        case 4: _a1 = "SkBlendMode::kDstOver"; break;
        case 5: _a1 = "SkBlendMode::kSrcIn"; break;
        case 6: _a1 = "SkBlendMode::kDstIn"; break;
        case 7: _a1 = "SkBlendMode::kSrcOut"; break;
        case 8: _a1 = "SkBlendMode::kDstOut"; break;
        case 9: _a1 = "SkBlendMode::kSrcATop"; break;
        case 10: _a1 = "SkBlendMode::kDstATop"; break;
        case 11: _a1 = "SkBlendMode::kXor"; break;
        case 12: _a1 = "SkBlendMode::kPlus"; break;
        case 13: _a1 = "SkBlendMode::kModulate"; break;
        case 14: _a1 = "SkBlendMode::kScreen"; break;
        case 15: _a1 = "SkBlendMode::kOverlay"; break;
        case 16: _a1 = "SkBlendMode::kDarken"; break;
        case 17: _a1 = "SkBlendMode::kLighten"; break;
        case 18: _a1 = "SkBlendMode::kColorDodge"; break;
        case 19: _a1 = "SkBlendMode::kColorBurn"; break;
        case 20: _a1 = "SkBlendMode::kHardLight"; break;
        case 21: _a1 = "SkBlendMode::kSoftLight"; break;
        case 22: _a1 = "SkBlendMode::kDifference"; break;
        case 23: _a1 = "SkBlendMode::kExclusion"; break;
        case 24: _a1 = "SkBlendMode::kMultiply"; break;
        case 25: _a1 = "SkBlendMode::kHue"; break;
        case 26: _a1 = "SkBlendMode::kSaturation"; break;
        case 27: _a1 = "SkBlendMode::kColor"; break;
        case 28: _a1 = "SkBlendMode::kLuminosity"; break;
        case 29: _a1 = "SkBlendMode::kLastCoeffMode"; break;
        case 30: _a1 = "SkBlendMode::kLastSeparableMode"; break;
        case 31: _a1 = "SkBlendMode::kLastMode"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_255" << std::endl;

    std::cout << "        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawColor(SkColor4f::FromColor(" << _a0 << "), " << _a1 << ");\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_255" << std::endl;
}


/* CPPScope(name=bundled_canvas_drawString) */
extern "C" void shim_256(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a1;
    memcpy(&_a1, context + 128, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 132, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_256" << std::endl;
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    std::cout << "    uint8_t _a0[128] = {";
    for (int i = 0; i < 128; ++i) {
        if (i % 16 == 0 && 128 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 128 - 1) std::cout << ", ";
    }
    if (128 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        Fuzz f = Fuzz(" << "_a0" << ", 128);\n        std::string str = make_fuzz_string(&f);\n        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawString(str.c_str(), " << _a1 << ", " << _a2 << ", *" << "var_" << _i1 << ", *" << "var_" << _i2 << ");\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_256" << std::endl;
}


/* CPPScope(name=bundled_canvas_drawPatch) */
extern "C" void shim_257(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    bool _a3 = *(static_cast<const char *>(context + 144)) & 1;
    const char *_a4;
    switch (*(reinterpret_cast<const unsigned char *>(context + 145)) % 32) {
        case 0: _a4 = "SkBlendMode::kClear"; break;
        case 1: _a4 = "SkBlendMode::kSrc"; break;
        case 2: _a4 = "SkBlendMode::kDst"; break;
        case 3: _a4 = "SkBlendMode::kSrcOver"; break;
        case 4: _a4 = "SkBlendMode::kDstOver"; break;
        case 5: _a4 = "SkBlendMode::kSrcIn"; break;
        case 6: _a4 = "SkBlendMode::kDstIn"; break;
        case 7: _a4 = "SkBlendMode::kSrcOut"; break;
        case 8: _a4 = "SkBlendMode::kDstOut"; break;
        case 9: _a4 = "SkBlendMode::kSrcATop"; break;
        case 10: _a4 = "SkBlendMode::kDstATop"; break;
        case 11: _a4 = "SkBlendMode::kXor"; break;
        case 12: _a4 = "SkBlendMode::kPlus"; break;
        case 13: _a4 = "SkBlendMode::kModulate"; break;
        case 14: _a4 = "SkBlendMode::kScreen"; break;
        case 15: _a4 = "SkBlendMode::kOverlay"; break;
        case 16: _a4 = "SkBlendMode::kDarken"; break;
        case 17: _a4 = "SkBlendMode::kLighten"; break;
        case 18: _a4 = "SkBlendMode::kColorDodge"; break;
        case 19: _a4 = "SkBlendMode::kColorBurn"; break;
        case 20: _a4 = "SkBlendMode::kHardLight"; break;
        case 21: _a4 = "SkBlendMode::kSoftLight"; break;
        case 22: _a4 = "SkBlendMode::kDifference"; break;
        case 23: _a4 = "SkBlendMode::kExclusion"; break;
        case 24: _a4 = "SkBlendMode::kMultiply"; break;
        case 25: _a4 = "SkBlendMode::kHue"; break;
        case 26: _a4 = "SkBlendMode::kSaturation"; break;
        case 27: _a4 = "SkBlendMode::kColor"; break;
        case 28: _a4 = "SkBlendMode::kLuminosity"; break;
        case 29: _a4 = "SkBlendMode::kLastCoeffMode"; break;
        case 30: _a4 = "SkBlendMode::kLastSeparableMode"; break;
        case 31: _a4 = "SkBlendMode::kLastMode"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_257" << std::endl;
    float _a0[24];
    memcpy(&_a0, context + 0, 4 * 24);
    std::cout << "    float _a0[24] = {";
    for (int i = 0; i < 24; ++i) {
        if (i % 16 == 0 && 24 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 24 - 1) std::cout << ", ";
    }
    if (24 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint32_t _a1[4];
    memcpy(&_a1, context + 96, 4 * 4);
    std::cout << "    uint32_t _a1[4] = {";
    for (int i = 0; i < 4; ++i) {
        if (i % 16 == 0 && 4 > 16) std::cout << std::endl << "        ";
        std::cout << _a1[i];
        if (i < 4 - 1) std::cout << ", ";
    }
    if (4 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    float _a2[8];
    memcpy(&_a2, context + 112, 4 * 8);
    std::cout << "    float _a2[8] = {";
    for (int i = 0; i < 8; ++i) {
        if (i % 16 == 0 && 8 > 16) std::cout << std::endl << "        ";
        std::cout << _a2[i];
        if (i < 8 - 1) std::cout << ", ";
    }
    if (8 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        SkPoint cubics[12];\n        for (int i = 0; i < 12; ++i) cubics[i] = SkPoint::Make(" << "_a0" << "[i*2], " << "_a0" << "[(i*2)+1]);\n        SkPoint tex[4];\n        for (int i = 0; i < 4; ++i) tex[i] = SkPoint::Make(" << "_a2" << "[i*2], " << "_a2" << "[(i*2)+1]);\n        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPatch(cubics, " << "_a1" << ", " << (int)_a3 << " ? tex : nullptr, " << _a4 << ", *" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_257" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void flush();) */
extern "C" void shim_258(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_258" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->flush();)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_258" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void save();) */
extern "C" void shim_259(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_259" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->save();)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_259" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayer(SkRect * None, SkPaint * None);) */
extern "C" void shim_260(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_260" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->saveLayer(" << "var_" << _i1 << ", " << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_260" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayer(SkRect * None, {nullptr});) */
extern "C" void shim_261(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_261" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->saveLayer(" << "var_" << _i1 << ", nullptr);)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_261" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayer({nullptr}, SkPaint * None);) */
extern "C" void shim_262(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_262" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->saveLayer(nullptr, " << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_262" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayer({nullptr}, {nullptr});) */
extern "C" void shim_263(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_263" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->saveLayer(nullptr, nullptr);)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_263" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayerAlpha({nullptr}, uint8_t None);) */
extern "C" void shim_264(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_264" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->saveLayerAlpha(nullptr, " << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_264" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayerAlpha(SkRect * None, uint8_t None);) */
extern "C" void shim_265(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_265" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->saveLayerAlpha(" << "var_" << _i1 << ", " << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_265" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void restore();) */
extern "C" void shim_266(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_266" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->restore();)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_266" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void restoreToCount(int None);) */
extern "C" void shim_267(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_267" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->restoreToCount(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_267" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void translate(SkScalar None, SkScalar None);) */
extern "C" void shim_268(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_268" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->translate(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_268" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void scale(SkScalar None, SkScalar None);) */
extern "C" void shim_269(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_269" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->scale(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_269" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void rotate(SkScalar None);) */
extern "C" void shim_270(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_270" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->rotate(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_270" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void rotate(SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_271(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_271" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->rotate(" << _a0 << ", " << _a1 << ", " << _a2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_271" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void skew(SkScalar None, SkScalar None);) */
extern "C" void shim_272(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_272" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->skew(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_272" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void concat(SkMatrix None);) */
extern "C" void shim_273(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_273" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->concat(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_273" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void setMatrix(SkMatrix None);) */
extern "C" void shim_274(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_274" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->setMatrix(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_274" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void resetMatrix();) */
extern "C" void shim_275(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_275" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->resetMatrix();)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_275" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipRect(SkRect None, SkClipOp None, bool None);) */
extern "C" void shim_276(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkClipOp::kDifference"; break;
        case 1: _a0 = "SkClipOp::kIntersect"; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_276" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->clipRect(*" << "var_" << _i1 << ", " << _a0 << ", " << (int)_a1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_276" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipRRect(SkRRect None, SkClipOp None, bool None);) */
extern "C" void shim_277(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkClipOp::kDifference"; break;
        case 1: _a0 = "SkClipOp::kIntersect"; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_277" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->clipRRect(*" << "var_" << _i1 << ", " << _a0 << ", " << (int)_a1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_277" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipPath(SkPath None, SkClipOp None, bool None);) */
extern "C" void shim_278(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkClipOp::kDifference"; break;
        case 1: _a0 = "SkClipOp::kIntersect"; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_278" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->clipPath(*" << "var_" << _i1 << ", " << _a0 << ", " << (int)_a1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_278" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipRegion(SkRegion None, SkClipOp None);) */
extern "C" void shim_279(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkClipOp::kDifference"; break;
        case 1: _a0 = "SkClipOp::kIntersect"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_279" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->clipRegion(*" << "var_" << _i1 << ", " << _a0 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_279" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPaint(SkPaint None);) */
extern "C" void shim_280(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_280" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPaint(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_280" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRect(SkRect None, SkPaint None);) */
extern "C" void shim_281(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_281" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawRect(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_281" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRegion(SkRegion None, SkPaint None);) */
extern "C" void shim_282(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_282" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawRegion(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_282" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawOval(SkRect None, SkPaint None);) */
extern "C" void shim_283(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_283" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawOval(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_283" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRRect(SkRRect None, SkPaint None);) */
extern "C" void shim_284(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_284" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawRRect(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_284" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawDRRect(SkRRect None, SkRRect None, SkPaint None);) */
extern "C" void shim_285(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkRRect *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_285" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawDRRect(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ", *" << "var_" << _i3 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_285" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawArc(SkRect None, SkScalar None, SkScalar None, bool None, SkPaint None);) */
extern "C" void shim_286(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_286" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawArc(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", " << (int)_a2 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_286" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPath(SkPath None, SkPaint None);) */
extern "C" void shim_287(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_287" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPath(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_287" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawTextBlob(sk_sp<SkTextBlob> None, SkScalar None, SkScalar None, SkPaint None);) */
extern "C" void shim_288(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_288" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawTextBlob(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_288" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, SkMatrix * None, SkPaint * None);) */
extern "C" void shim_289(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPicture> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_289" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPicture(*" << "var_" << _i1 << ", " << "var_" << _i2 << ", " << "var_" << _i3 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_289" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, SkMatrix * None, {nullptr});) */
extern "C" void shim_290(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPicture> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_290" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPicture(*" << "var_" << _i1 << ", " << "var_" << _i2 << ", nullptr);)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_290" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, {nullptr}, SkPaint * None);) */
extern "C" void shim_291(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPicture> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_291" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPicture(*" << "var_" << _i1 << ", nullptr, " << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_291" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, {nullptr}, {nullptr});) */
extern "C" void shim_292(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPicture> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_292" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPicture(*" << "var_" << _i1 << ", nullptr, nullptr);)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_292" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawColor(SkColor None, SkBlendMode None);) */
extern "C" void shim_293(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 4)) % 32) {
        case 0: _a1 = "SkBlendMode::kClear"; break;
        case 1: _a1 = "SkBlendMode::kSrc"; break;
        case 2: _a1 = "SkBlendMode::kDst"; break;
        case 3: _a1 = "SkBlendMode::kSrcOver"; break;
        case 4: _a1 = "SkBlendMode::kDstOver"; break;
        case 5: _a1 = "SkBlendMode::kSrcIn"; break;
        case 6: _a1 = "SkBlendMode::kDstIn"; break;
        case 7: _a1 = "SkBlendMode::kSrcOut"; break;
        case 8: _a1 = "SkBlendMode::kDstOut"; break;
        case 9: _a1 = "SkBlendMode::kSrcATop"; break;
        case 10: _a1 = "SkBlendMode::kDstATop"; break;
        case 11: _a1 = "SkBlendMode::kXor"; break;
        case 12: _a1 = "SkBlendMode::kPlus"; break;
        case 13: _a1 = "SkBlendMode::kModulate"; break;
        case 14: _a1 = "SkBlendMode::kScreen"; break;
        case 15: _a1 = "SkBlendMode::kOverlay"; break;
        case 16: _a1 = "SkBlendMode::kDarken"; break;
        case 17: _a1 = "SkBlendMode::kLighten"; break;
        case 18: _a1 = "SkBlendMode::kColorDodge"; break;
        case 19: _a1 = "SkBlendMode::kColorBurn"; break;
        case 20: _a1 = "SkBlendMode::kHardLight"; break;
        case 21: _a1 = "SkBlendMode::kSoftLight"; break;
        case 22: _a1 = "SkBlendMode::kDifference"; break;
        case 23: _a1 = "SkBlendMode::kExclusion"; break;
        case 24: _a1 = "SkBlendMode::kMultiply"; break;
        case 25: _a1 = "SkBlendMode::kHue"; break;
        case 26: _a1 = "SkBlendMode::kSaturation"; break;
        case 27: _a1 = "SkBlendMode::kColor"; break;
        case 28: _a1 = "SkBlendMode::kLuminosity"; break;
        case 29: _a1 = "SkBlendMode::kLastCoeffMode"; break;
        case 30: _a1 = "SkBlendMode::kLastSeparableMode"; break;
        case 31: _a1 = "SkBlendMode::kLastMode"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_293" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawColor(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_293" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawLine(SkPoint None, SkPoint None, SkPaint None);) */
extern "C" void shim_294(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPoint *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_294" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawLine(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ", *" << "var_" << _i3 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_294" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawIRect(SkIRect None, SkPaint None);) */
extern "C" void shim_295(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_295" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawIRect(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_295" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawCircle(SkPoint None, SkScalar None, SkPaint None);) */
extern "C" void shim_296(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_296" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawCircle(*" << "var_" << _i1 << ", " << _a0 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_296" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawArc(SkRect None, SkScalar None, SkScalar None, bool None, SkPaint None);) */
extern "C" void shim_297(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_297" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawArc(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", " << (int)_a2 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_297" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRoundRect(SkRect None, SkScalar None, SkScalar None, SkPaint None);) */
extern "C" void shim_298(void **in_ref, void **out_ref, const char *context) {
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
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_298" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawRoundRect(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_298" << std::endl;
}


/* CPPScope(name=bundled_canvas_saveLayer) */
extern "C" void shim_299(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    bool _a2 = *(static_cast<const char *>(context + 2)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    sk_sp<SkImageFilter> *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_299" << std::endl;

    std::cout << "        SkCanvas::SaveLayerRec saveLayerRec;\n        if (" << (int)_a0 << ") saveLayerRec.fBounds = " << "var_" << _i1 << ";\n        if (" << (int)_a1 << ") saveLayerRec.fPaint = " << "var_" << _i2 << ";\n        if (" << (int)_a2 << ") saveLayerRec.fBackdrop = " << "var_" << _i3 << "->get();\n        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->saveLayer(saveLayerRec);\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_299" << std::endl;
}


/* CPPScope(name=bundled_canvas_drawPoints) */
extern "C" void shim_300(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a1;
    memcpy(&_a1, context + 240, sizeof(int));
    const char *_a2;
    switch (*(reinterpret_cast<const unsigned char *>(context + 244)) % 3) {
        case 0: _a2 = "SkCanvas::PointMode::kPoints_PointMode"; break;
        case 1: _a2 = "SkCanvas::PointMode::kLines_PointMode"; break;
        case 2: _a2 = "SkCanvas::PointMode::kPolygon_PointMode"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_300" << std::endl;
    float _a0[60];
    memcpy(&_a0, context + 0, 4 * 60);
    std::cout << "    float _a0[60] = {";
    for (int i = 0; i < 60; ++i) {
        if (i % 16 == 0 && 60 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 60 - 1) std::cout << ", ";
    }
    if (60 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        int count = " << _a1 << " % 30;\n        SkPoint pts[30];\n        for (int i = 0; i < count; ++i) {\n          pts[i] = SkPoint::Make(" << "_a0" << "[i*2], " << "_a0" << "[(i*2)+1]);\n        }\n        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPoints(" << _a2 << ", count, pts, *" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_300" << std::endl;
}


/* CPPScope(name=bundled_drawImage) */
extern "C" void shim_301(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_301" << std::endl;

    std::cout << "        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawImage(" << "var_" << _i1 << "->get(), " << _a0 << ", " << _a1 << ", SkSamplingOptions(), " << (int)_a2 << " ? " << "var_" << _i2 << " : nullptr);\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_301" << std::endl;
}


/* CPPScope(name=bundled_drawImageRect) */
extern "C" void shim_302(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _i4 = reinterpret_cast<unsigned long>(in_ref[4]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
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

    std::cout << "    { // begin shim_302" << std::endl;

    std::cout << "        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawImageRect(" << "var_" << _i1 << "->get(), *" << "var_" << _i2 << ", *" << "var_" << _i3 << ", SkSamplingOptions(), " << (int)_a0 << " ? " << "var_" << _i4 << " : nullptr, " << (int)_a1 << " ? SkCanvas::kStrict_SrcRectConstraint : SkCanvas::kFast_SrcRectConstraint);\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";\n        " << "var_" << _o4 << " = " << "var_" << _i4 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);

    std::cout << "    } // end shim_302" << std::endl;
}


/* CPPScope(name=bundled_drawImageNine) */
extern "C" void shim_303(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _i4 = reinterpret_cast<unsigned long>(in_ref[4]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o3 << ";" << std::endl;
    unsigned long _o4 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o4 << ";" << std::endl;

    std::cout << "    { // begin shim_303" << std::endl;

    std::cout << "        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawImageNine(" << "var_" << _i1 << "->get(), *" << "var_" << _i2 << ", *" << "var_" << _i3 << ", SkFilterMode::kNearest, " << (int)_a0 << " ? " << "var_" << _i4 << " : nullptr);\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";\n        " << "var_" << _o4 << " = " << "var_" << _i4 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);
    out_ref[4] = reinterpret_cast<void *>(_o4);

    std::cout << "    } // end shim_303" << std::endl;
}


/* CPPScope(name=bundled_canvas_drawImageLattice) */
extern "C" void shim_304(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    int _a2;
    memcpy(&_a2, context + 48, sizeof(int));
    int _a3;
    memcpy(&_a3, context + 52, sizeof(int));
    bool _a4 = *(static_cast<const char *>(context + 56)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkImage> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_304" << std::endl;
    int _a0[6];
    memcpy(&_a0, context + 0, 4 * 6);
    std::cout << "    int _a0[6] = {";
    for (int i = 0; i < 6; ++i) {
        if (i % 16 == 0 && 6 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 6 - 1) std::cout << ", ";
    }
    if (6 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    int _a1[6];
    memcpy(&_a1, context + 24, 4 * 6);
    std::cout << "    int _a1[6] = {";
    for (int i = 0; i < 6; ++i) {
        if (i % 16 == 0 && 6 > 16) std::cout << std::endl << "        ";
        std::cout << _a1[i];
        if (i < 6 - 1) std::cout << ", ";
    }
    if (6 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        SkCanvas::Lattice lattice{\n          " << "_a0" << ", \n          " << "_a1" << ", \n          nullptr, \n          (" << _a2 << " % (6-2)) + 2,\n          (" << _a3 << " % (6-2)) + 2, \n          nullptr, \n          nullptr\n        };\n        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawImageLattice(" << "var_" << _i1 << "->get(), lattice, *" << "var_" << _i2 << ", SkFilterMode::kLinear, " << (int)_a4 << " ? " << "var_" << _i3 << " : nullptr);\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_304" << std::endl;
}


/* CPPScope(name=bundled_canvas_drawSimpleText) */
extern "C" void shim_305(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a1;
    memcpy(&_a1, context + 128, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 132, sizeof(float));
    const char *_a3;
    switch (*(reinterpret_cast<const unsigned char *>(context + 136)) % 4) {
        case 0: _a3 = "SkTextEncoding::kUTF8"; break;
        case 1: _a3 = "SkTextEncoding::kUTF16"; break;
        case 2: _a3 = "SkTextEncoding::kUTF32"; break;
        case 3: _a3 = "SkTextEncoding::kGlyphID"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_305" << std::endl;
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    std::cout << "    uint8_t _a0[128] = {";
    for (int i = 0; i < 128; ++i) {
        if (i % 16 == 0 && 128 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 128 - 1) std::cout << ", ";
    }
    if (128 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        Fuzz f = Fuzz(" << "_a0" << ", 128);\n        SkTDArray<uint8_t> text = make_fuzz_text(&f, *" << "var_" << _i1 << ", " << _a3 << ");\n        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawSimpleText(\n          text.begin(), \n          SkToSizeT(text.count()),\n          " << _a3 << ",\n          " << _a1 << ",\n          " << _a2 << ",\n          *" << "var_" << _i1 << ",\n          *" << "var_" << _i2 << "\n        );\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_305" << std::endl;
}


/* CPPScope(name=bundled_canvas_drawVertices) */
extern "C" void shim_306(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 3) {
        case 0: _a0 = "SkVertices::VertexMode::kTriangles_VertexMode"; break;
        case 1: _a0 = "SkVertices::VertexMode::kTriangleStrip_VertexMode"; break;
        case 2: _a0 = "SkVertices::VertexMode::kTriangleFan_VertexMode"; break;
    }
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 1)) % 32) {
        case 0: _a1 = "SkBlendMode::kClear"; break;
        case 1: _a1 = "SkBlendMode::kSrc"; break;
        case 2: _a1 = "SkBlendMode::kDst"; break;
        case 3: _a1 = "SkBlendMode::kSrcOver"; break;
        case 4: _a1 = "SkBlendMode::kDstOver"; break;
        case 5: _a1 = "SkBlendMode::kSrcIn"; break;
        case 6: _a1 = "SkBlendMode::kDstIn"; break;
        case 7: _a1 = "SkBlendMode::kSrcOut"; break;
        case 8: _a1 = "SkBlendMode::kDstOut"; break;
        case 9: _a1 = "SkBlendMode::kSrcATop"; break;
        case 10: _a1 = "SkBlendMode::kDstATop"; break;
        case 11: _a1 = "SkBlendMode::kXor"; break;
        case 12: _a1 = "SkBlendMode::kPlus"; break;
        case 13: _a1 = "SkBlendMode::kModulate"; break;
        case 14: _a1 = "SkBlendMode::kScreen"; break;
        case 15: _a1 = "SkBlendMode::kOverlay"; break;
        case 16: _a1 = "SkBlendMode::kDarken"; break;
        case 17: _a1 = "SkBlendMode::kLighten"; break;
        case 18: _a1 = "SkBlendMode::kColorDodge"; break;
        case 19: _a1 = "SkBlendMode::kColorBurn"; break;
        case 20: _a1 = "SkBlendMode::kHardLight"; break;
        case 21: _a1 = "SkBlendMode::kSoftLight"; break;
        case 22: _a1 = "SkBlendMode::kDifference"; break;
        case 23: _a1 = "SkBlendMode::kExclusion"; break;
        case 24: _a1 = "SkBlendMode::kMultiply"; break;
        case 25: _a1 = "SkBlendMode::kHue"; break;
        case 26: _a1 = "SkBlendMode::kSaturation"; break;
        case 27: _a1 = "SkBlendMode::kColor"; break;
        case 28: _a1 = "SkBlendMode::kLuminosity"; break;
        case 29: _a1 = "SkBlendMode::kLastCoeffMode"; break;
        case 30: _a1 = "SkBlendMode::kLastSeparableMode"; break;
        case 31: _a1 = "SkBlendMode::kLastMode"; break;
    }
    int _a5;
    memcpy(&_a5, context + 2002, sizeof(int));
    bool _a6 = *(static_cast<const char *>(context + 2006)) & 1;
    bool _a7 = *(static_cast<const char *>(context + 2007)) & 1;
    bool _a8 = *(static_cast<const char *>(context + 2008)) & 1;
    int _a10;
    memcpy(&_a10, context + 2409, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_306" << std::endl;
    float _a2[200];
    memcpy(&_a2, context + 2, 4 * 200);
    std::cout << "    float _a2[200] = {";
    for (int i = 0; i < 200; ++i) {
        if (i % 16 == 0 && 200 > 16) std::cout << std::endl << "        ";
        std::cout << _a2[i];
        if (i < 200 - 1) std::cout << ", ";
    }
    if (200 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    float _a3[200];
    memcpy(&_a3, context + 802, 4 * 200);
    std::cout << "    float _a3[200] = {";
    for (int i = 0; i < 200; ++i) {
        if (i % 16 == 0 && 200 > 16) std::cout << std::endl << "        ";
        std::cout << _a3[i];
        if (i < 200 - 1) std::cout << ", ";
    }
    if (200 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint32_t _a4[100];
    memcpy(&_a4, context + 1602, 4 * 100);
    std::cout << "    uint32_t _a4[100] = {";
    for (int i = 0; i < 100; ++i) {
        if (i % 16 == 0 && 100 > 16) std::cout << std::endl << "        ";
        std::cout << _a4[i];
        if (i < 100 - 1) std::cout << ", ";
    }
    if (100 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint16_t _a9[200];
    memcpy(&_a9, context + 2009, 2 * 200);
    std::cout << "    uint16_t _a9[200] = {";
    for (int i = 0; i < 200; ++i) {
        if (i % 16 == 0 && 200 > 16) std::cout << std::endl << "        ";
        std::cout << _a9[i];
        if (i < 200 - 1) std::cout << ", ";
    }
    if (200 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        int vertexCount = (" << _a5 << " % (100 - 3)) + 3;\n        \n        SkPoint vertices[100];\n        SkPoint texs[100];\n        \n        for (int i = 0; i < vertexCount; ++i) {\n          vertices[i] = SkPoint::Make(" << "_a2" << "[i*2], " << "_a2" << "[(i*2)+1]);\n          texs[i] = SkPoint::Make(" << "_a3" << "[i*2], " << "_a3" << "[(i*2)+1]);\n        }\n        \n        int indexCount = " << (int)_a8 << " ? ((" << _a10 << " % 100) + vertexCount) : 0;\n        \n        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawVertices(SkVertices::MakeCopy(\n            " << _a0 << ", vertexCount, vertices,\n            " << (int)_a6 << " ? texs : nullptr,\n            " << (int)_a7 << " ? " << "_a4" << " : nullptr,\n            indexCount, " << "_a9" << "\n          ), " << _a1 << ", *" << "var_" << _i1 << "\n        );\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_306" << std::endl;
}


/* CPPScope(name=bundled_void drawColor(SkColor4f, SkBlendMode)) */
extern "C" void shim_307(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 4)) % 32) {
        case 0: _a1 = "SkBlendMode::kClear"; break;
        case 1: _a1 = "SkBlendMode::kSrc"; break;
        case 2: _a1 = "SkBlendMode::kDst"; break;
        case 3: _a1 = "SkBlendMode::kSrcOver"; break;
        case 4: _a1 = "SkBlendMode::kDstOver"; break;
        case 5: _a1 = "SkBlendMode::kSrcIn"; break;
        case 6: _a1 = "SkBlendMode::kDstIn"; break;
        case 7: _a1 = "SkBlendMode::kSrcOut"; break;
        case 8: _a1 = "SkBlendMode::kDstOut"; break;
        case 9: _a1 = "SkBlendMode::kSrcATop"; break;
        case 10: _a1 = "SkBlendMode::kDstATop"; break;
        case 11: _a1 = "SkBlendMode::kXor"; break;
        case 12: _a1 = "SkBlendMode::kPlus"; break;
        case 13: _a1 = "SkBlendMode::kModulate"; break;
        case 14: _a1 = "SkBlendMode::kScreen"; break;
        case 15: _a1 = "SkBlendMode::kOverlay"; break;
        case 16: _a1 = "SkBlendMode::kDarken"; break;
        case 17: _a1 = "SkBlendMode::kLighten"; break;
        case 18: _a1 = "SkBlendMode::kColorDodge"; break;
        case 19: _a1 = "SkBlendMode::kColorBurn"; break;
        case 20: _a1 = "SkBlendMode::kHardLight"; break;
        case 21: _a1 = "SkBlendMode::kSoftLight"; break;
        case 22: _a1 = "SkBlendMode::kDifference"; break;
        case 23: _a1 = "SkBlendMode::kExclusion"; break;
        case 24: _a1 = "SkBlendMode::kMultiply"; break;
        case 25: _a1 = "SkBlendMode::kHue"; break;
        case 26: _a1 = "SkBlendMode::kSaturation"; break;
        case 27: _a1 = "SkBlendMode::kColor"; break;
        case 28: _a1 = "SkBlendMode::kLuminosity"; break;
        case 29: _a1 = "SkBlendMode::kLastCoeffMode"; break;
        case 30: _a1 = "SkBlendMode::kLastSeparableMode"; break;
        case 31: _a1 = "SkBlendMode::kLastMode"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_307" << std::endl;

    std::cout << "        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawColor(SkColor4f::FromColor(" << _a0 << "), " << _a1 << ");\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_307" << std::endl;
}


/* CPPScope(name=bundled_canvas_drawString) */
extern "C" void shim_308(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a1;
    memcpy(&_a1, context + 128, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 132, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkFont *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_308" << std::endl;
    uint8_t _a0[128];
    memcpy(&_a0, context + 0, 1 * 128);
    std::cout << "    uint8_t _a0[128] = {";
    for (int i = 0; i < 128; ++i) {
        if (i % 16 == 0 && 128 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 128 - 1) std::cout << ", ";
    }
    if (128 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        Fuzz f = Fuzz(" << "_a0" << ", 128);\n        std::string str = make_fuzz_string(&f);\n        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawString(str.c_str(), " << _a1 << ", " << _a2 << ", *" << "var_" << _i1 << ", *" << "var_" << _i2 << ");\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_308" << std::endl;
}


/* CPPScope(name=bundled_canvas_drawPatch) */
extern "C" void shim_309(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    bool _a3 = *(static_cast<const char *>(context + 144)) & 1;
    const char *_a4;
    switch (*(reinterpret_cast<const unsigned char *>(context + 145)) % 32) {
        case 0: _a4 = "SkBlendMode::kClear"; break;
        case 1: _a4 = "SkBlendMode::kSrc"; break;
        case 2: _a4 = "SkBlendMode::kDst"; break;
        case 3: _a4 = "SkBlendMode::kSrcOver"; break;
        case 4: _a4 = "SkBlendMode::kDstOver"; break;
        case 5: _a4 = "SkBlendMode::kSrcIn"; break;
        case 6: _a4 = "SkBlendMode::kDstIn"; break;
        case 7: _a4 = "SkBlendMode::kSrcOut"; break;
        case 8: _a4 = "SkBlendMode::kDstOut"; break;
        case 9: _a4 = "SkBlendMode::kSrcATop"; break;
        case 10: _a4 = "SkBlendMode::kDstATop"; break;
        case 11: _a4 = "SkBlendMode::kXor"; break;
        case 12: _a4 = "SkBlendMode::kPlus"; break;
        case 13: _a4 = "SkBlendMode::kModulate"; break;
        case 14: _a4 = "SkBlendMode::kScreen"; break;
        case 15: _a4 = "SkBlendMode::kOverlay"; break;
        case 16: _a4 = "SkBlendMode::kDarken"; break;
        case 17: _a4 = "SkBlendMode::kLighten"; break;
        case 18: _a4 = "SkBlendMode::kColorDodge"; break;
        case 19: _a4 = "SkBlendMode::kColorBurn"; break;
        case 20: _a4 = "SkBlendMode::kHardLight"; break;
        case 21: _a4 = "SkBlendMode::kSoftLight"; break;
        case 22: _a4 = "SkBlendMode::kDifference"; break;
        case 23: _a4 = "SkBlendMode::kExclusion"; break;
        case 24: _a4 = "SkBlendMode::kMultiply"; break;
        case 25: _a4 = "SkBlendMode::kHue"; break;
        case 26: _a4 = "SkBlendMode::kSaturation"; break;
        case 27: _a4 = "SkBlendMode::kColor"; break;
        case 28: _a4 = "SkBlendMode::kLuminosity"; break;
        case 29: _a4 = "SkBlendMode::kLastCoeffMode"; break;
        case 30: _a4 = "SkBlendMode::kLastSeparableMode"; break;
        case 31: _a4 = "SkBlendMode::kLastMode"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_309" << std::endl;
    float _a0[24];
    memcpy(&_a0, context + 0, 4 * 24);
    std::cout << "    float _a0[24] = {";
    for (int i = 0; i < 24; ++i) {
        if (i % 16 == 0 && 24 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 24 - 1) std::cout << ", ";
    }
    if (24 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint32_t _a1[4];
    memcpy(&_a1, context + 96, 4 * 4);
    std::cout << "    uint32_t _a1[4] = {";
    for (int i = 0; i < 4; ++i) {
        if (i % 16 == 0 && 4 > 16) std::cout << std::endl << "        ";
        std::cout << _a1[i];
        if (i < 4 - 1) std::cout << ", ";
    }
    if (4 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    float _a2[8];
    memcpy(&_a2, context + 112, 4 * 8);
    std::cout << "    float _a2[8] = {";
    for (int i = 0; i < 8; ++i) {
        if (i % 16 == 0 && 8 > 16) std::cout << std::endl << "        ";
        std::cout << _a2[i];
        if (i < 8 - 1) std::cout << ", ";
    }
    if (8 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        SkPoint cubics[12];\n        for (int i = 0; i < 12; ++i) cubics[i] = SkPoint::Make(" << "_a0" << "[i*2], " << "_a0" << "[(i*2)+1]);\n        SkPoint tex[4];\n        for (int i = 0; i < 4; ++i) tex[i] = SkPoint::Make(" << "_a2" << "[i*2], " << "_a2" << "[(i*2)+1]);\n        " << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPatch(cubics, " << "_a1" << ", " << (int)_a3 << " ? tex : nullptr, " << _a4 << ", *" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_309" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void flush();) */
extern "C" void shim_310(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_310" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->flush();)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_310" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void save();) */
extern "C" void shim_311(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_311" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->save();)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_311" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayer(SkRect * None, SkPaint * None);) */
extern "C" void shim_312(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_312" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->saveLayer(" << "var_" << _i1 << ", " << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_312" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayer(SkRect * None, {nullptr});) */
extern "C" void shim_313(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_313" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->saveLayer(" << "var_" << _i1 << ", nullptr);)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_313" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayer({nullptr}, SkPaint * None);) */
extern "C" void shim_314(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_314" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->saveLayer(nullptr, " << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_314" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayer({nullptr}, {nullptr});) */
extern "C" void shim_315(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_315" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->saveLayer(nullptr, nullptr);)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_315" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayerAlpha({nullptr}, uint8_t None);) */
extern "C" void shim_316(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_316" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->saveLayerAlpha(nullptr, " << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_316" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void saveLayerAlpha(SkRect * None, uint8_t None);) */
extern "C" void shim_317(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    uint8_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint8_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_317" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->saveLayerAlpha(" << "var_" << _i1 << ", " << (int)_a0 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_317" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void restore();) */
extern "C" void shim_318(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_318" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->restore();)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_318" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void restoreToCount(int None);) */
extern "C" void shim_319(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_319" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->restoreToCount(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_319" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void translate(SkScalar None, SkScalar None);) */
extern "C" void shim_320(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_320" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->translate(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_320" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void scale(SkScalar None, SkScalar None);) */
extern "C" void shim_321(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_321" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->scale(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_321" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void rotate(SkScalar None);) */
extern "C" void shim_322(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_322" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->rotate(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_322" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void rotate(SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_323(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_323" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->rotate(" << _a0 << ", " << _a1 << ", " << _a2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_323" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void skew(SkScalar None, SkScalar None);) */
extern "C" void shim_324(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_324" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->skew(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_324" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void concat(SkMatrix None);) */
extern "C" void shim_325(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_325" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->concat(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_325" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void setMatrix(SkMatrix None);) */
extern "C" void shim_326(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_326" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->setMatrix(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_326" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void resetMatrix();) */
extern "C" void shim_327(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_327" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->resetMatrix();)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_327" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipRect(SkRect None, SkClipOp None, bool None);) */
extern "C" void shim_328(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkClipOp::kDifference"; break;
        case 1: _a0 = "SkClipOp::kIntersect"; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_328" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->clipRect(*" << "var_" << _i1 << ", " << _a0 << ", " << (int)_a1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_328" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipRRect(SkRRect None, SkClipOp None, bool None);) */
extern "C" void shim_329(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkClipOp::kDifference"; break;
        case 1: _a0 = "SkClipOp::kIntersect"; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_329" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->clipRRect(*" << "var_" << _i1 << ", " << _a0 << ", " << (int)_a1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_329" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipPath(SkPath None, SkClipOp None, bool None);) */
extern "C" void shim_330(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkClipOp::kDifference"; break;
        case 1: _a0 = "SkClipOp::kIntersect"; break;
    }
    bool _a1 = *(static_cast<const char *>(context + 1)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_330" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->clipPath(*" << "var_" << _i1 << ", " << _a0 << ", " << (int)_a1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_330" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void clipRegion(SkRegion None, SkClipOp None);) */
extern "C" void shim_331(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "SkClipOp::kDifference"; break;
        case 1: _a0 = "SkClipOp::kIntersect"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_331" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->clipRegion(*" << "var_" << _i1 << ", " << _a0 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_331" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPaint(SkPaint None);) */
extern "C" void shim_332(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_332" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPaint(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_332" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRect(SkRect None, SkPaint None);) */
extern "C" void shim_333(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_333" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawRect(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_333" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRegion(SkRegion None, SkPaint None);) */
extern "C" void shim_334(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_334" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawRegion(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_334" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawOval(SkRect None, SkPaint None);) */
extern "C" void shim_335(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_335" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawOval(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_335" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRRect(SkRRect None, SkPaint None);) */
extern "C" void shim_336(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_336" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawRRect(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_336" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawDRRect(SkRRect None, SkRRect None, SkPaint None);) */
extern "C" void shim_337(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkRRect *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_337" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawDRRect(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ", *" << "var_" << _i3 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_337" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawArc(SkRect None, SkScalar None, SkScalar None, bool None, SkPaint None);) */
extern "C" void shim_338(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_338" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawArc(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", " << (int)_a2 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_338" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPath(SkPath None, SkPaint None);) */
extern "C" void shim_339(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_339" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPath(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_339" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawTextBlob(sk_sp<SkTextBlob> None, SkScalar None, SkScalar None, SkPaint None);) */
extern "C" void shim_340(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_340" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawTextBlob(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_340" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, SkMatrix * None, SkPaint * None);) */
extern "C" void shim_341(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPicture> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_341" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPicture(*" << "var_" << _i1 << ", " << "var_" << _i2 << ", " << "var_" << _i3 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_341" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, SkMatrix * None, {nullptr});) */
extern "C" void shim_342(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPicture> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_342" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPicture(*" << "var_" << _i1 << ", " << "var_" << _i2 << ", nullptr);)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_342" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, {nullptr}, SkPaint * None);) */
extern "C" void shim_343(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPicture> *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_343" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPicture(*" << "var_" << _i1 << ", nullptr, " << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_343" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawPicture(sk_sp<SkPicture> None, {nullptr}, {nullptr});) */
extern "C" void shim_344(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    sk_sp<SkPicture> *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_344" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawPicture(*" << "var_" << _i1 << ", nullptr, nullptr);)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_344" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawColor(SkColor None, SkBlendMode None);) */
extern "C" void shim_345(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 4)) % 32) {
        case 0: _a1 = "SkBlendMode::kClear"; break;
        case 1: _a1 = "SkBlendMode::kSrc"; break;
        case 2: _a1 = "SkBlendMode::kDst"; break;
        case 3: _a1 = "SkBlendMode::kSrcOver"; break;
        case 4: _a1 = "SkBlendMode::kDstOver"; break;
        case 5: _a1 = "SkBlendMode::kSrcIn"; break;
        case 6: _a1 = "SkBlendMode::kDstIn"; break;
        case 7: _a1 = "SkBlendMode::kSrcOut"; break;
        case 8: _a1 = "SkBlendMode::kDstOut"; break;
        case 9: _a1 = "SkBlendMode::kSrcATop"; break;
        case 10: _a1 = "SkBlendMode::kDstATop"; break;
        case 11: _a1 = "SkBlendMode::kXor"; break;
        case 12: _a1 = "SkBlendMode::kPlus"; break;
        case 13: _a1 = "SkBlendMode::kModulate"; break;
        case 14: _a1 = "SkBlendMode::kScreen"; break;
        case 15: _a1 = "SkBlendMode::kOverlay"; break;
        case 16: _a1 = "SkBlendMode::kDarken"; break;
        case 17: _a1 = "SkBlendMode::kLighten"; break;
        case 18: _a1 = "SkBlendMode::kColorDodge"; break;
        case 19: _a1 = "SkBlendMode::kColorBurn"; break;
        case 20: _a1 = "SkBlendMode::kHardLight"; break;
        case 21: _a1 = "SkBlendMode::kSoftLight"; break;
        case 22: _a1 = "SkBlendMode::kDifference"; break;
        case 23: _a1 = "SkBlendMode::kExclusion"; break;
        case 24: _a1 = "SkBlendMode::kMultiply"; break;
        case 25: _a1 = "SkBlendMode::kHue"; break;
        case 26: _a1 = "SkBlendMode::kSaturation"; break;
        case 27: _a1 = "SkBlendMode::kColor"; break;
        case 28: _a1 = "SkBlendMode::kLuminosity"; break;
        case 29: _a1 = "SkBlendMode::kLastCoeffMode"; break;
        case 30: _a1 = "SkBlendMode::kLastSeparableMode"; break;
        case 31: _a1 = "SkBlendMode::kLastMode"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_345" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawColor(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_345" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawLine(SkPoint None, SkPoint None, SkPaint None);) */
extern "C" void shim_346(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _i3 = reinterpret_cast<unsigned long>(in_ref[3]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPoint *var_" << _o2 << ";" << std::endl;
    unsigned long _o3 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o3 << ";" << std::endl;

    std::cout << "    { // begin shim_346" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawLine(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ", *" << "var_" << _i3 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";\n        " << "var_" << _o3 << " = " << "var_" << _i3 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
    out_ref[3] = reinterpret_cast<void *>(_o3);

    std::cout << "    } // end shim_346" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawIRect(SkIRect None, SkPaint None);) */
extern "C" void shim_347(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_347" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawIRect(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_347" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawCircle(SkPoint None, SkScalar None, SkPaint None);) */
extern "C" void shim_348(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_348" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawCircle(*" << "var_" << _i1 << ", " << _a0 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_348" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawArc(SkRect None, SkScalar None, SkScalar None, bool None, SkPaint None);) */
extern "C" void shim_349(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_349" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawArc(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", " << (int)_a2 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_349" << std::endl;
}


/* CPPScope(name=bundled_(auto) SkCanvas::void drawRoundRect(SkRect None, SkScalar None, SkScalar None, SkPaint None);) */
extern "C" void shim_350(void **in_ref, void **out_ref, const char *context) {
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
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPaint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_350" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "((SkCanvas *)var_" << _i0 << "->active)" << "->drawRoundRect(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "((SkCanvas *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_350" << std::endl;
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

