

#include <string.h>
#include <string>
#include <iostream>

unsigned long CURR_ID = 0;

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) { }

extern "C" void __attribute__((visibility ("default"))) shim_init() {
    CURR_ID = 0;

    std::cout << "#include \"./paragraph_util.h\"\n#include \"modules/skparagraph/include/ParagraphStyle.h\"\n#include \"modules/skparagraph/include/TextStyle.h\"\n#include \"modules/skparagraph/src/ParagraphBuilderImpl.h\"\n" << std::endl;
    std::cout << "\n#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))\n\nstruct GFUZZ_BUNDLE {\npublic:\n    void *active;\n    void *inactive;\n    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}\n};\n\n#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)\n" << std::endl;

    std::cout << "int main() {" << std::endl;
}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {
    std::cout << "}" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::skia::textlayout::ParagraphStyle();) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::ParagraphStyle *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_0" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new skia::textlayout::ParagraphStyle();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_0" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::void turnHintingOff();) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::ParagraphStyle *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_1" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->turnHintingOff();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_1" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::void setStrutStyle(skia::textlayout::StrutStyle None);) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::ParagraphStyle *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    skia::textlayout::StrutStyle *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_2" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setStrutStyle(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_2" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::void setTextDirection(skia::textlayout::TextDirection None);) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 2) {
        case 0: _a0 = "skia::textlayout::TextDirection::kRtl"; break;
        case 1: _a0 = "skia::textlayout::TextDirection::kLtr"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::ParagraphStyle *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_3" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setTextDirection(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_3" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::void setTextAlign(skia::textlayout::TextAlign None);) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 6) {
        case 0: _a0 = "skia::textlayout::TextAlign::kLeft"; break;
        case 1: _a0 = "skia::textlayout::TextAlign::kRight"; break;
        case 2: _a0 = "skia::textlayout::TextAlign::kCenter"; break;
        case 3: _a0 = "skia::textlayout::TextAlign::kJustify"; break;
        case 4: _a0 = "skia::textlayout::TextAlign::kStart"; break;
        case 5: _a0 = "skia::textlayout::TextAlign::kEnd"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::ParagraphStyle *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_4" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setTextAlign(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_4" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::void setMaxLines(size_t None);) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    size_t _a0;
    memcpy(&_a0, context + 0, sizeof(size_t));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::ParagraphStyle *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_5" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setMaxLines(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_5" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::void setEllipsis({u"\u2026"});) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::ParagraphStyle *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_6" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setEllipsis(u\"\\u2026\");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_6" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::void setHeight(SkScalar None);) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::ParagraphStyle *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_7" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setHeight(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_7" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::void setTextHeightBehavior(skia::textlayout::TextHeightBehavior None);) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 4) {
        case 0: _a0 = "skia::textlayout::TextHeightBehavior::kAll"; break;
        case 1: _a0 = "skia::textlayout::TextHeightBehavior::kDisableFirstAscent"; break;
        case 2: _a0 = "skia::textlayout::TextHeightBehavior::kDisableLastDescent"; break;
        case 3: _a0 = "skia::textlayout::TextHeightBehavior::kDisableAll"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::ParagraphStyle *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_8" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->setTextHeightBehavior(" << _a0 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_8" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphStyle::~skia::textlayout::ParagraphStyle();) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_9" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    } // end shim_9" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::StrutStyle::skia::textlayout::StrutStyle();) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::StrutStyle *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_10" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new skia::textlayout::StrutStyle();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_10" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::StrutStyle::~skia::textlayout::StrutStyle();) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_11" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    } // end shim_11" << std::endl;
}


/* CPPScope(name=AddASCIIText) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a1;
    memcpy(&_a1, context + 255, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::ParagraphBuilderImpl *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_12" << std::endl;
    char _a0[255];
    memcpy(&_a0, context + 0, 1 * 255);
    std::cout << "    char _a0[255] = {";
    for (int i = 0; i < 255; ++i) {
        if (i % 16 == 0 && 255 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 255 - 1) std::cout << ", ";
    }
    if (255 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        unsigned int textSize = " << _a1 << " % 255;\n        " << "var_" << _i0 << "->addText(" << "_a0" << ", textSize);\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_12" << std::endl;
}


/* CPPScope(name=AddUnicodeText) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a1;
    memcpy(&_a1, context + 510, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::ParagraphBuilderImpl *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_13" << std::endl;
    char16_t _a0[255];
    memcpy(&_a0, context + 0, 2 * 255);
    std::cout << "    char16_t _a0[255] = {";
    for (int i = 0; i < 255; ++i) {
        if (i % 16 == 0 && 255 > 16) std::cout << std::endl << "        ";
        std::cout << _a0[i];
        if (i < 255 - 1) std::cout << ", ";
    }
    if (255 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        unsigned int textSize = " << _a1 << " % 255;\n        " << "var_" << _i0 << "->addText(std::u16string(" << "_a0" << ", textSize));\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_13" << std::endl;
}


/* CPPScope(name=AddZalgo) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a1;
    memcpy(&_a1, context + 255, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::ParagraphBuilderImpl *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_14" << std::endl;
    char _a0[255];
    memcpy(&_a0, context + 0, 1 * 255);
    std::cout << "    char _a0[255] = {";
    for (int i = 0; i < 255; ++i) {
        if (i % 16 == 0 && 255 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a0[i];
        if (i < 255 - 1) std::cout << ", ";
    }
    if (255 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;
    uint8_t _a2[512];
    memcpy(&_a2, context + 259, 1 * 512);
    std::cout << "    uint8_t _a2[512] = {";
    for (int i = 0; i < 512; ++i) {
        if (i % 16 == 0 && 512 > 16) std::cout << std::endl << "        ";
        std::cout << (int)_a2[i];
        if (i < 512 - 1) std::cout << ", ";
    }
    if (512 > 16) std::cout << std::endl << "    ";
    std::cout << "};" << std::endl;

    std::cout << "        unsigned int textSize = " << _a1 << " % 255;\n        Fuzz f(" << "_a2" << ", 512);\n        AddZalgoText(" << "var_" << _i0 << ", " << "_a0" << ", textSize, &f);\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_14" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphBuilderImpl::skia::textlayout::ParagraphBuilderImpl(const skia::textlayout::ParagraphStyle & style, {sk_make_sp<ResourceFontCollection>()});) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::ParagraphBuilderImpl *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    skia::textlayout::ParagraphStyle *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_15" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new skia::textlayout::ParagraphBuilderImpl(*" << "var_" << _i0 << ", sk_make_sp<ResourceFontCollection>());\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_15" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphBuilderImpl::void pushStyle(skia::textlayout::TextStyle None);) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::ParagraphBuilderImpl *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    skia::textlayout::TextStyle *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_16" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->pushStyle(*" << "var_" << _i1 << ");)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_16" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphBuilderImpl::void pop();) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::ParagraphBuilderImpl *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_17" << std::endl;

    std::cout << "        FUZZ_ENDPOINT(" << "var_" << _i0 << "->pop();)\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_17" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::ParagraphBuilderImpl::~skia::textlayout::ParagraphBuilderImpl();) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_18" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    } // end shim_18" << std::endl;
}


/* CPPScope(name=void setFontFamilies_fixed) */
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::TextStyle *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_19" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setFontFamilies({SkString(\"Roboto\")});\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_19" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::TextStyle::skia::textlayout::TextStyle();) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    skia::textlayout::TextStyle *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_20" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new skia::textlayout::TextStyle();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_20" << std::endl;
}


/* CPPScope(name=(auto) skia::textlayout::TextStyle::~skia::textlayout::TextStyle();) */
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_21" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    } // end shim_21" << std::endl;
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

