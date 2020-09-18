

#include <string.h>
#include <string>
#include <iostream>

unsigned long CURR_ID = 0;

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) { }

extern "C" void __attribute__((visibility ("default"))) shim_init() {
    CURR_ID = 0;

    std::cout << "#include \"SkMatrix.h\"\n#include \"SkPath.h\"\n#include \"SkPathTypes.h\"\n#include \"SkRRect.h\"\n#include \"include/core/SkPath.h\"\n#include \"include/core/SkRect.h\"\n#include \"include/core/SkRegion.h\"\n" << std::endl;
    std::cout << "\n#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))\n\nstruct GFUZZ_BUNDLE {\npublic:\n    void *active;\n    void *inactive;\n    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}\n};\n\n#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)\n" << std::endl;

    std::cout << "int main() {" << std::endl;
}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {
    std::cout << "}" << std::endl;
}


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
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_0" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkRect);\n        SkRect ref = SkRect::MakeXYWH(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_0" << std::endl;
}


/* CPPScope(name=(auto) SkRect::~SkRect();) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_1" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_1" << std::endl;
}


/* CPPScope(name=make) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_2" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkRRect);\n        *" << "var_" << _o0 << " = SkRRect();\n        SkVector radii[4] = {\n          SkPoint::Make(" << _a0 << "," << _a1 << "),\n          SkPoint::Make(" << _a2 << "," << _a3 << "),\n          SkPoint::Make(" << _a4 << "," << _a5 << "),\n          SkPoint::Make(" << _a6 << "," << _a7 << ")\n        };\n        " << "var_" << _o0 << "->setRectRadii(*" << "var_" << _i0 << ", radii);\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_2" << std::endl;
}


/* CPPScope(name=(auto) SkRRect::~SkRRect();) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_3" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_3" << std::endl;
}


/* CPPScope(name=void setAffine(SkScalar[6])) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_4" << std::endl;
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

    std::cout << "    } // end shim_4" << std::endl;
}


/* CPPScope(name=void set9(SkScalar[9])) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_5" << std::endl;
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

    std::cout << "    } // end shim_5" << std::endl;
}


/* CPPScope(name=(auto) SkMatrix::void postTranslate(SkScalar None, SkScalar None);) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_6" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->postTranslate(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_6" << std::endl;
}


/* CPPScope(name=(auto) SkMatrix::SkMatrix I();) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_7" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkMatrix);\n        SkMatrix ref = SkMatrix::I();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_7" << std::endl;
}


/* CPPScope(name=(auto) SkMatrix::SkMatrix Translate(SkScalar None, SkScalar None);) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_8" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkMatrix);\n        SkMatrix ref = SkMatrix::Translate(" << _a0 << ", " << _a1 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_8" << std::endl;
}


/* CPPScope(name=(auto) SkMatrix::SkMatrix Scale(SkScalar None, SkScalar None);) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_9" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkMatrix);\n        SkMatrix ref = SkMatrix::Scale(" << _a0 << ", " << _a1 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_9" << std::endl;
}


/* CPPScope(name=(auto) SkMatrix::~SkMatrix();) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_10" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_10" << std::endl;
}


/* CPPScope(name=add_self_path_matrix) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_11" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->addPath(*" << "var_" << _i0 << ", *" << "var_" << _i1 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_11" << std::endl;
}


/* CPPScope(name=add_self_path) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_12" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->addPath(*" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_12" << std::endl;
}


/* CPPScope(name=add_self_path_reverse) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_13" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->reverseAddPath(*" << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_13" << std::endl;
}


/* CPPScope(name=offset_self) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_14" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->offset(" << _a0 << ", " << _a1 << ", " << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_14" << std::endl;
}


/* CPPScope(name=transform_self) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_15" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->transform(*" << "var_" << _i1 << ", " << "var_" << _i0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_15" << std::endl;
}


/* CPPScope(name=(auto) SkPath::SkPath();) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_16" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkPath);\n        SkPath ref = SkPath();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_16" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void moveTo(SkScalar None, SkScalar None);) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_17" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->moveTo(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_17" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void rMoveTo(SkScalar None, SkScalar None);) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_18" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->rMoveTo(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_18" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void lineTo(SkScalar None, SkScalar None);) */
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_19" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->lineTo(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_19" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void rLineTo(SkScalar None, SkScalar None);) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_20" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->rLineTo(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_20" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void quadTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_21" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->quadTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_21" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void rQuadTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_22(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_22" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->rQuadTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_22" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void conicTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_23(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_23" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->conicTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_23" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void rConicTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_24(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_24" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->rConicTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_24" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void cubicTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_25(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_25" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->cubicTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ", " << _a5 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_25" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void rCubicTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_26(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_26" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->rCubicTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ", " << _a5 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_26" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void arcTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_27(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_27" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->arcTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_27" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void arcTo(SkRect None, SkScalar None, SkScalar None, bool None);) */
extern "C" void shim_28(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_28" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->arcTo(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", " << (int)_a2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_28" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void close();) */
extern "C" void shim_29(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_29" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->close();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_29" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addRect(SkRect None, SkPathDirection None);) */
extern "C" void shim_30(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_30" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addRect(*" << "var_" << _i1 << ", " << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_30" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addRect(SkRect None, SkPathDirection None, unsigned int None);) */
extern "C" void shim_31(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_31" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addRect(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_31" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addOval(SkRect None, SkPathDirection None);) */
extern "C" void shim_32(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_32" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addOval(*" << "var_" << _i1 << ", " << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_32" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addOval(SkRect None, SkPathDirection None, unsigned int None);) */
extern "C" void shim_33(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_33" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addOval(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_33" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addCircle(SkScalar None, SkScalar None, SkScalar None, SkPathDirection None);) */
extern "C" void shim_34(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_34" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addCircle(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_34" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addArc(SkRect None, SkScalar None, SkScalar None);) */
extern "C" void shim_35(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_35" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addArc(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_35" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addRoundRect(SkRect None, SkScalar None, SkScalar None, SkPathDirection None);) */
extern "C" void shim_36(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_36" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addRoundRect(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ", " << _a2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_36" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addRRect(SkRRect None, SkPathDirection None);) */
extern "C" void shim_37(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_37" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addRRect(*" << "var_" << _i1 << ", " << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_37" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addRRect(SkRRect None, SkPathDirection None, unsigned int None);) */
extern "C" void shim_38(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_38" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addRRect(*" << "var_" << _i1 << ", " << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_38" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void addPath(SkPath None, SkMatrix None, SkPath::AddPathMode None);) */
extern "C" void shim_39(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_39" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->addPath(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ", " << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_39" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void reverseAddPath(SkPath None);) */
extern "C" void shim_40(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_40" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->reverseAddPath(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_40" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void offset(SkScalar None, SkScalar None, SkPath * None);) */
extern "C" void shim_41(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_41" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->offset(" << _a0 << ", " << _a1 << ", " << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_41" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void transform(SkMatrix None, SkPath * None);) */
extern "C" void shim_42(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkMatrix *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_42" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->transform(*" << "var_" << _i1 << ", " << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_42" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void setLastPt(SkScalar None, SkScalar None);) */
extern "C" void shim_43(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_43" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setLastPt(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_43" << std::endl;
}


/* CPPScope(name=(auto) SkPath::~SkPath();) */
extern "C" void shim_44(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_44" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_44" << std::endl;
}


/* CPPScope(name=(auto) SkRegion::SkRegion();) */
extern "C" void shim_45(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_45" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkRegion);\n        SkRegion ref = SkRegion();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_45" << std::endl;
}


/* CPPScope(name=(auto) SkRegion::bool op(const SkIRect & rect, SkRegion::Op op);) */
extern "C" void shim_46(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 6) {
        case 0: _a0 = "SkRegion::Op::kDifference_Op"; break;
        case 1: _a0 = "SkRegion::Op::kIntersect_Op"; break;
        case 2: _a0 = "SkRegion::Op::kUnion_Op"; break;
        case 3: _a0 = "SkRegion::Op::kXOR_Op"; break;
        case 4: _a0 = "SkRegion::Op::kReverseDifference_Op"; break;
        case 5: _a0 = "SkRegion::Op::kReplace_Op"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_46" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->op(*" << "var_" << _i1 << ", " << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_46" << std::endl;
}


/* CPPScope(name=(auto) SkRegion::int computeRegionComplexity();) */
extern "C" void shim_47(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_47" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->computeRegionComplexity();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_47" << std::endl;
}


/* CPPScope(name=(auto) SkRegion::bool setPath(const SkPath & path, const SkRegion & clip);) */
extern "C" void shim_48(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_48" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setPath(*" << "var_" << _i1 << ", *" << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_48" << std::endl;
}


/* CPPScope(name=(auto) SkRegion::bool isComplex();) */
extern "C" void shim_49(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_49" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->isComplex();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_49" << std::endl;
}


/* CPPScope(name=(auto) SkRegion::bool contains(int32_t x, int32_t y);) */
extern "C" void shim_50(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int32_t _a0;
    memcpy(&_a0, context + 0, sizeof(int32_t));
    int32_t _a1;
    memcpy(&_a1, context + 4, sizeof(int32_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkRegion *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_50" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->contains(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_50" << std::endl;
}


/* CPPScope(name=(auto) SkRegion::~SkRegion();) */
extern "C" void shim_51(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_51" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_51" << std::endl;
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
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkIRect *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_52" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkIRect);\n        SkIRect ref = SkIRect::MakeLTRB(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_52" << std::endl;
}


/* CPPScope(name=(auto) SkIRect::~SkIRect();) */
extern "C" void shim_53(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_53" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_53" << std::endl;
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

