

#include <string.h>
#include <string>
#include <iostream>

unsigned long CURR_ID = 0;

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) { }

extern "C" void __attribute__((visibility ("default"))) shim_init() {
    CURR_ID = 0;

    std::cout << "#include \"include/core/SkPath.h\"\n#include \"include/core/SkPathMeasure.h\"\n#include \"include/core/SkPoint.h\"\n#include \"include/core/SkRect.h\"\n" << std::endl;
    std::cout << "\n#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))\n\nstruct GFUZZ_BUNDLE {\npublic:\n    void *active;\n    void *inactive;\n    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}\n};\n\n#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)\n" << std::endl;

    std::cout << "int main() {" << std::endl;
}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {
    std::cout << "}" << std::endl;
}


/* CPPScope(name=(auto) SkPath::SkPath();) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_0" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkPath);\n        SkPath ref = SkPath();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_0" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void moveTo(SkScalar None, SkScalar None);) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_1" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->moveTo(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_1" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void lineTo(SkScalar None, SkScalar None);) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_2" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->lineTo(" << _a0 << ", " << _a1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_2" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void quadTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_3" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->quadTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_3" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void conicTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_4" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->conicTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_4" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void cubicTo(SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None, SkScalar None);) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
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

    std::cout << "    { // begin shim_5" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->cubicTo(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ", " << _a4 << ", " << _a5 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_5" << std::endl;
}


/* CPPScope(name=(auto) SkPath::void close();) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_6" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->close();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_6" << std::endl;
}


/* CPPScope(name=(auto) SkPath::SkRect getBounds();) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_7" << std::endl;

    std::cout << "        " << "var_" << _o1 << " = MAKE(SkRect);\n        *" << "var_" << _o1 << " = " << "var_" << _i0 << "->getBounds();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_7" << std::endl;
}


/* CPPScope(name=(auto) SkPath::~SkPath();) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_8" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_8" << std::endl;
}


/* CPPScope(name=(auto) SkPathMeasure::SkPathMeasure(const SkPath & path, bool forceClosed, SkScalar resScale);) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    float _a1;
    memcpy(&_a1, context + 1, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPathMeasure *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_9" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new SkPathMeasure(*" << "var_" << _i0 << ", " << (int)_a0 << ", " << _a1 << ");\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_9" << std::endl;
}


/* CPPScope(name=(auto) SkPathMeasure::bool getPosTan(SkScalar distance, SkPoint * position, SkVector * tangent);) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPathMeasure *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPoint *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    SkPoint *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_10" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->getPosTan(" << _a0 << ", " << "var_" << _i1 << ", " << "var_" << _i2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_10" << std::endl;
}


/* CPPScope(name=(auto) SkPathMeasure::bool getSegment(SkScalar startD, SkScalar stopD, SkPath * dst, bool startWithMoveTo);) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    bool _a2 = *(static_cast<const char *>(context + 8)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPathMeasure *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    SkPath *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_11" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->getSegment(" << _a0 << ", " << _a1 << ", " << "var_" << _i1 << ", " << (int)_a2 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_11" << std::endl;
}


/* CPPScope(name=(auto) SkPathMeasure::bool nextContour();) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPathMeasure *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_12" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->nextContour();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_12" << std::endl;
}


/* CPPScope(name=(auto) SkPathMeasure::~SkPathMeasure();) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_13" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    } // end shim_13" << std::endl;
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
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkRect *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_14" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkRect);\n        SkRect ref = SkRect::MakeXYWH(" << _a0 << ", " << _a1 << ", " << _a2 << ", " << _a3 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_14" << std::endl;
}


/* CPPScope(name=(auto) SkRect::~SkRect();) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_15" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_15" << std::endl;
}


/* CPPScope(name=(auto) SkPoint::SkPoint Make(SkScalar x, SkScalar y);) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    SkPoint *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_16" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(SkPoint);\n        SkPoint ref = SkPoint::Make(" << _a0 << ", " << _a1 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_16" << std::endl;
}


/* CPPScope(name=(auto) SkPoint::~SkPoint();) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_17" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_17" << std::endl;
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

