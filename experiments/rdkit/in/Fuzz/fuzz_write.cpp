

#include <string.h>
#include <string>
#include <iostream>

unsigned long CURR_ID = 0;

extern "C" void __attribute__((visibility ("default"))) shim_init() {
    CURR_ID = 0;

    std::cout << "#include \"<Geometry/point.h>\"\n#include \"<GraphMol/Atom.h>\"\n#include \"<GraphMol/Bond.h>\"\n#include \"<GraphMol/Conformer.h>\"\n#include \"<GraphMol/ROMol.h>\"\n#include \"<GraphMol/RWMol.h>\"\n" << std::endl;
    std::cout << "\n#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))\n\nstruct GFUZZ_BUNDLE {\npublic:\n    void *active;\n    void *inactive;\n    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {};\n};\n\n#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)\n" << std::endl;

    std::cout << "int main() {" << std::endl;
}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {
    std::cout << "}" << std::endl;
}


/* CPPScope(name=void setAtomBookmark(RDKit::Atom *at, int mark)) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_0" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setAtomBookmark(" << "var_" << _i1 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_0" << std::endl;
}


/* CPPScope(name=void replaceAtomBookmark(RDKit::Atom *at, int mark)) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_1" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->replaceAtomBookmark(" << "var_" << _i1 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_1" << std::endl;
}


/* CPPScope(name=void setBondBookmark(RDKit::Bond *bond, int mark)) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_2" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setBondBookmark(" << "var_" << _i1 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_2" << std::endl;
}


/* CPPScope(name=RDKit::Conformer & getConformer(int id)) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_3" << std::endl;

    std::cout << "        RDKit::Conformer *conf = new RDKit::Conformer();\n        *conf = " << "var_" << _i0 << "->getConformer(" << _a0 << ");\n        " << "var_" << _o0 << " = BUNDLE(conf, " << "var_" << _i0 << ");" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_3" << std::endl;
}


/* CPPScope(name=unbundle_conformer) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_4" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = (RDKit::ROMol *)" << "var_" << _i0 << "->inactive;\n        delete " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_4" << std::endl;
}


/* CPPScope(name=unsigned int addConformer(RDKit::Conformer *conf, bool assignId)) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_5" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->addConformer(" << "var_" << _i1 << ", " << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_5" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::unsigned int getNumAtoms();) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_6" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getNumAtoms();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_6" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::unsigned int getNumAtoms(bool onlyExplicit);) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_7" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getNumAtoms(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_7" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::unsigned int getNumHeavyAtoms();) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_8" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getNumHeavyAtoms();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_8" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::unsigned int getNumBonds(bool onlyHeavy);) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_9" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getNumBonds(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_9" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::void clearAtomBookmark(int mark);) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_10" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->clearAtomBookmark(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_10" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::void clearAtomBookmark(int mark, const RDKit::Atom * atom);) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_11" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->clearAtomBookmark(" << _a0 << ", " << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_11" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::void clearAllAtomBookmarks();) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_12" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->clearAllAtomBookmarks();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_12" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::bool hasAtomBookmark(int mark);) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_13" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->hasAtomBookmark(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_13" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::void clearBondBookmark(int mark);) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_14" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->clearBondBookmark(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_14" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::void clearBondBookmark(int mark, const RDKit::Bond * bond);) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_15" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->clearBondBookmark(" << _a0 << ", " << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_15" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::void clearAllBondBookmarks();) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_16" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->clearAllBondBookmarks();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_16" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::bool hasBondBookmark(int mark);) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_17" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->hasBondBookmark(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_17" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::void removeConformer(unsigned int id);) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_18" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->removeConformer(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_18" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::void clearConformers();) */
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_19" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->clearConformers();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_19" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::unsigned int getNumConformers();) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_20" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getNumConformers();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_20" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::void clearComputedProps(bool includeRings);) */
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_21" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->clearComputedProps(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_21" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::void updatePropertyCache(bool strict);) */
extern "C" void shim_22(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_22" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->updatePropertyCache(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_22" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::bool needsUpdatePropertyCache();) */
extern "C" void shim_23(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_23" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->needsUpdatePropertyCache();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_23" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::RDKit::ROMol();) */
extern "C" void shim_24(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_24" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new RDKit::ROMol();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_24" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::RDKit::ROMol(const RDKit::ROMol & other, bool quickCopy, int confId);) */
extern "C" void shim_25(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    int _a1;
    memcpy(&_a1, context + 1, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_25" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new RDKit::ROMol(*" << "var_" << _i0 << ", " << (int)_a0 << ", " << _a1 << ");\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_25" << std::endl;
}


/* CPPScope(name=(auto) RDKit::ROMol::~RDKit::ROMol();) */
extern "C" void shim_26(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_26" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    } // end shim_26" << std::endl;
}


/* CPPScope(name=add_atom_copy) */
extern "C" void shim_27(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_27" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->addAtom(" << "var_" << _i1 << ", " << (int)_a0 << ", false);\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_27" << std::endl;
}


/* CPPScope(name=add_atom_owner) */
extern "C" void shim_28(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_28" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->addAtom(" << "var_" << _i1 << ", " << (int)_a0 << ", true);\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_28" << std::endl;
}


/* CPPScope(name=add_bond_copy) */
extern "C" void shim_29(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_29" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->addBond(" << "var_" << _i1 << ", false);\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_29" << std::endl;
}


/* CPPScope(name=add_bond_owner) */
extern "C" void shim_30(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_30" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->addBond(" << "var_" << _i1 << ", true);\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_30" << std::endl;
}


/* CPPScope(name=RDKit::Bond * createPartialBond(unsigned int beginAtomIdx, RDKit::Bond::BondType order)) */
extern "C" void shim_31(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    const char *_a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 4)) % 22) {
        case 0: _a1 = "RDKit::Bond::BondType::UNSPECIFIED"; break;
        case 1: _a1 = "RDKit::Bond::BondType::SINGLE"; break;
        case 2: _a1 = "RDKit::Bond::BondType::DOUBLE"; break;
        case 3: _a1 = "RDKit::Bond::BondType::TRIPLE"; break;
        case 4: _a1 = "RDKit::Bond::BondType::QUADRUPLE"; break;
        case 5: _a1 = "RDKit::Bond::BondType::QUINTUPLE"; break;
        case 6: _a1 = "RDKit::Bond::BondType::HEXTUPLE"; break;
        case 7: _a1 = "RDKit::Bond::BondType::ONEANDAHALF"; break;
        case 8: _a1 = "RDKit::Bond::BondType::TWOANDAHALF"; break;
        case 9: _a1 = "RDKit::Bond::BondType::THREEANDAHALF"; break;
        case 10: _a1 = "RDKit::Bond::BondType::FOURANDAHALF"; break;
        case 11: _a1 = "RDKit::Bond::BondType::FIVEANDAHALF"; break;
        case 12: _a1 = "RDKit::Bond::BondType::AROMATIC"; break;
        case 13: _a1 = "RDKit::Bond::BondType::IONIC"; break;
        case 14: _a1 = "RDKit::Bond::BondType::HYDROGEN"; break;
        case 15: _a1 = "RDKit::Bond::BondType::THREECENTER"; break;
        case 16: _a1 = "RDKit::Bond::BondType::DATIVEONE"; break;
        case 17: _a1 = "RDKit::Bond::BondType::DATIVE"; break;
        case 18: _a1 = "RDKit::Bond::BondType::DATIVEL"; break;
        case 19: _a1 = "RDKit::Bond::BondType::DATIVER"; break;
        case 20: _a1 = "RDKit::Bond::BondType::OTHER"; break;
        case 21: _a1 = "RDKit::Bond::BondType::ZERO"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_31" << std::endl;

    std::cout << "        RDKit::Bond *bond = " << "var_" << _i0 << "->createPartialBond(" << _a0 << ", " << _a1 << ");\n        " << "var_" << _o0 << " = BUNDLE(bond, " << "var_" << _i0 << ");" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_31" << std::endl;
}


/* CPPScope(name=unbundle_bond) */
extern "C" void shim_32(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_32" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = (RDKit::RWMol *)" << "var_" << _i0 << "->inactive;\n        delete " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_32" << std::endl;
}


/* CPPScope(name=RDKit::RWMol()) */
extern "C" void shim_33(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_33" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new RDKit::RWMol();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_33" << std::endl;
}


/* CPPScope(name=destructor) */
extern "C" void shim_34(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_34" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    } // end shim_34" << std::endl;
}


/* CPPScope(name=(auto) RDKit::RWMol::unsigned int addAtom(bool updateLabel);) */
extern "C" void shim_35(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_35" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->addAtom(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_35" << std::endl;
}


/* CPPScope(name=(auto) RDKit::RWMol::void replaceAtom(unsigned int idx, RDKit::Atom * atom, bool updateLabel, bool preserveProps);) */
extern "C" void shim_36(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    bool _a1 = *(static_cast<const char *>(context + 4)) & 1;
    bool _a2 = *(static_cast<const char *>(context + 5)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_36" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->replaceAtom(" << _a0 << ", " << "var_" << _i1 << ", " << (int)_a1 << ", " << (int)_a2 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_36" << std::endl;
}


/* CPPScope(name=(auto) RDKit::RWMol::void setActiveAtom(RDKit::Atom * atom);) */
extern "C" void shim_37(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_37" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setActiveAtom(" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_37" << std::endl;
}


/* CPPScope(name=(auto) RDKit::RWMol::void setActiveAtom(unsigned int idx);) */
extern "C" void shim_38(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_38" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setActiveAtom(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_38" << std::endl;
}


/* CPPScope(name=(auto) RDKit::RWMol::void removeAtom(unsigned int idx);) */
extern "C" void shim_39(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_39" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->removeAtom(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_39" << std::endl;
}


/* CPPScope(name=(auto) RDKit::RWMol::void removeAtom(RDKit::Atom * atom);) */
extern "C" void shim_40(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_40" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->removeAtom(" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_40" << std::endl;
}


/* CPPScope(name=(auto) RDKit::RWMol::unsigned int addBond(unsigned int beginAtomIdx, unsigned int endAtomIdx, RDKit::Bond::BondType order);) */
extern "C" void shim_41(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    const char *_a2;
    switch (*(reinterpret_cast<const unsigned char *>(context + 8)) % 22) {
        case 0: _a2 = "RDKit::Bond::BondType::UNSPECIFIED"; break;
        case 1: _a2 = "RDKit::Bond::BondType::SINGLE"; break;
        case 2: _a2 = "RDKit::Bond::BondType::DOUBLE"; break;
        case 3: _a2 = "RDKit::Bond::BondType::TRIPLE"; break;
        case 4: _a2 = "RDKit::Bond::BondType::QUADRUPLE"; break;
        case 5: _a2 = "RDKit::Bond::BondType::QUINTUPLE"; break;
        case 6: _a2 = "RDKit::Bond::BondType::HEXTUPLE"; break;
        case 7: _a2 = "RDKit::Bond::BondType::ONEANDAHALF"; break;
        case 8: _a2 = "RDKit::Bond::BondType::TWOANDAHALF"; break;
        case 9: _a2 = "RDKit::Bond::BondType::THREEANDAHALF"; break;
        case 10: _a2 = "RDKit::Bond::BondType::FOURANDAHALF"; break;
        case 11: _a2 = "RDKit::Bond::BondType::FIVEANDAHALF"; break;
        case 12: _a2 = "RDKit::Bond::BondType::AROMATIC"; break;
        case 13: _a2 = "RDKit::Bond::BondType::IONIC"; break;
        case 14: _a2 = "RDKit::Bond::BondType::HYDROGEN"; break;
        case 15: _a2 = "RDKit::Bond::BondType::THREECENTER"; break;
        case 16: _a2 = "RDKit::Bond::BondType::DATIVEONE"; break;
        case 17: _a2 = "RDKit::Bond::BondType::DATIVE"; break;
        case 18: _a2 = "RDKit::Bond::BondType::DATIVEL"; break;
        case 19: _a2 = "RDKit::Bond::BondType::DATIVER"; break;
        case 20: _a2 = "RDKit::Bond::BondType::OTHER"; break;
        case 21: _a2 = "RDKit::Bond::BondType::ZERO"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_41" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->addBond(" << _a0 << ", " << _a1 << ", " << _a2 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_41" << std::endl;
}


/* CPPScope(name=(auto) RDKit::RWMol::unsigned int addBond(RDKit::Atom * beginAtom, RDKit::Atom * endAtom, RDKit::Bond::BondType order);) */
extern "C" void shim_42(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _i2 = reinterpret_cast<unsigned long>(in_ref[2]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 22) {
        case 0: _a0 = "RDKit::Bond::BondType::UNSPECIFIED"; break;
        case 1: _a0 = "RDKit::Bond::BondType::SINGLE"; break;
        case 2: _a0 = "RDKit::Bond::BondType::DOUBLE"; break;
        case 3: _a0 = "RDKit::Bond::BondType::TRIPLE"; break;
        case 4: _a0 = "RDKit::Bond::BondType::QUADRUPLE"; break;
        case 5: _a0 = "RDKit::Bond::BondType::QUINTUPLE"; break;
        case 6: _a0 = "RDKit::Bond::BondType::HEXTUPLE"; break;
        case 7: _a0 = "RDKit::Bond::BondType::ONEANDAHALF"; break;
        case 8: _a0 = "RDKit::Bond::BondType::TWOANDAHALF"; break;
        case 9: _a0 = "RDKit::Bond::BondType::THREEANDAHALF"; break;
        case 10: _a0 = "RDKit::Bond::BondType::FOURANDAHALF"; break;
        case 11: _a0 = "RDKit::Bond::BondType::FIVEANDAHALF"; break;
        case 12: _a0 = "RDKit::Bond::BondType::AROMATIC"; break;
        case 13: _a0 = "RDKit::Bond::BondType::IONIC"; break;
        case 14: _a0 = "RDKit::Bond::BondType::HYDROGEN"; break;
        case 15: _a0 = "RDKit::Bond::BondType::THREECENTER"; break;
        case 16: _a0 = "RDKit::Bond::BondType::DATIVEONE"; break;
        case 17: _a0 = "RDKit::Bond::BondType::DATIVE"; break;
        case 18: _a0 = "RDKit::Bond::BondType::DATIVEL"; break;
        case 19: _a0 = "RDKit::Bond::BondType::DATIVER"; break;
        case 20: _a0 = "RDKit::Bond::BondType::OTHER"; break;
        case 21: _a0 = "RDKit::Bond::BondType::ZERO"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o1 << ";" << std::endl;
    unsigned long _o2 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o2 << ";" << std::endl;

    std::cout << "    { // begin shim_42" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->addBond(" << "var_" << _i1 << ", " << "var_" << _i2 << ", " << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";\n        " << "var_" << _o2 << " = " << "var_" << _i2 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);

    std::cout << "    } // end shim_42" << std::endl;
}


/* CPPScope(name=(auto) RDKit::RWMol::unsigned int finishPartialBond(unsigned int endAtomIdx, int bondBookmark, RDKit::Bond::BondType order);) */
extern "C" void shim_43(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    const char *_a2;
    switch (*(reinterpret_cast<const unsigned char *>(context + 8)) % 22) {
        case 0: _a2 = "RDKit::Bond::BondType::UNSPECIFIED"; break;
        case 1: _a2 = "RDKit::Bond::BondType::SINGLE"; break;
        case 2: _a2 = "RDKit::Bond::BondType::DOUBLE"; break;
        case 3: _a2 = "RDKit::Bond::BondType::TRIPLE"; break;
        case 4: _a2 = "RDKit::Bond::BondType::QUADRUPLE"; break;
        case 5: _a2 = "RDKit::Bond::BondType::QUINTUPLE"; break;
        case 6: _a2 = "RDKit::Bond::BondType::HEXTUPLE"; break;
        case 7: _a2 = "RDKit::Bond::BondType::ONEANDAHALF"; break;
        case 8: _a2 = "RDKit::Bond::BondType::TWOANDAHALF"; break;
        case 9: _a2 = "RDKit::Bond::BondType::THREEANDAHALF"; break;
        case 10: _a2 = "RDKit::Bond::BondType::FOURANDAHALF"; break;
        case 11: _a2 = "RDKit::Bond::BondType::FIVEANDAHALF"; break;
        case 12: _a2 = "RDKit::Bond::BondType::AROMATIC"; break;
        case 13: _a2 = "RDKit::Bond::BondType::IONIC"; break;
        case 14: _a2 = "RDKit::Bond::BondType::HYDROGEN"; break;
        case 15: _a2 = "RDKit::Bond::BondType::THREECENTER"; break;
        case 16: _a2 = "RDKit::Bond::BondType::DATIVEONE"; break;
        case 17: _a2 = "RDKit::Bond::BondType::DATIVE"; break;
        case 18: _a2 = "RDKit::Bond::BondType::DATIVEL"; break;
        case 19: _a2 = "RDKit::Bond::BondType::DATIVER"; break;
        case 20: _a2 = "RDKit::Bond::BondType::OTHER"; break;
        case 21: _a2 = "RDKit::Bond::BondType::ZERO"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_43" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->finishPartialBond(" << _a0 << ", " << _a1 << ", " << _a2 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_43" << std::endl;
}


/* CPPScope(name=(auto) RDKit::RWMol::void removeBond(unsigned int beginAtomIdx, unsigned int endAtomIdx);) */
extern "C" void shim_44(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_44" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->removeBond(" << _a0 << ", " << _a1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_44" << std::endl;
}


/* CPPScope(name=(auto) RDKit::RWMol::void replaceBond(unsigned int idx, RDKit::Bond * bond, bool preserveProps);) */
extern "C" void shim_45(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    bool _a1 = *(static_cast<const char *>(context + 4)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_45" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->replaceBond(" << _a0 << ", " << "var_" << _i1 << ", " << (int)_a1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_45" << std::endl;
}


/* CPPScope(name=(auto) RDKit::RWMol::void clear();) */
extern "C" void shim_46(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_46" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->clear();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_46" << std::endl;
}


/* CPPScope(name=(auto) RDKit::RWMol::void beginBatchEdit();) */
extern "C" void shim_47(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_47" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->beginBatchEdit();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_47" << std::endl;
}


/* CPPScope(name=(auto) RDKit::RWMol::void rollbackBatchEdit();) */
extern "C" void shim_48(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_48" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->rollbackBatchEdit();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_48" << std::endl;
}


/* CPPScope(name=(auto) RDKit::RWMol::void commitBatchEdit();) */
extern "C" void shim_49(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_49" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->commitBatchEdit();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_49" << std::endl;
}


/* CPPScope(name=(auto) RDKit::RWMol::void insertMol(const RDKit::ROMol & other);) */
extern "C" void shim_50(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_50" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->insertMol(*" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_50" << std::endl;
}


/* CPPScope(name=RDKit::Atom & operator=(const RDKit::Atom &other)) */
extern "C" void shim_51(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_51" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->operator=(*" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_51" << std::endl;
}


/* CPPScope(name=RDKit::Atom * copy() const) */
extern "C" void shim_52(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_52" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = " << "var_" << _i0 << "->copy();\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_52" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::RDKit::Atom();) */
extern "C" void shim_53(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_53" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new RDKit::Atom();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_53" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::RDKit::Atom(unsigned int num);) */
extern "C" void shim_54(void **in_ref, void **out_ref, const char *context) {
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_54" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new RDKit::Atom(" << _a0 << ");" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_54" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::RDKit::Atom(const RDKit::Atom & other);) */
extern "C" void shim_55(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_55" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new RDKit::Atom(*" << "var_" << _i0 << ");\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_55" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::int getAtomicNum();) */
extern "C" void shim_56(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_56" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getAtomicNum();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_56" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::void setAtomicNum(int newNum);) */
extern "C" void shim_57(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_57" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setAtomicNum(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_57" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::bool hasOwningMol();) */
extern "C" void shim_58(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_58" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->hasOwningMol();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_58" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::void getOwningMol();) */
extern "C" void shim_59(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_59" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getOwningMol();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_59" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getIdx();) */
extern "C" void shim_60(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_60" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getIdx();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_60" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::void setIdx(unsigned int index);) */
extern "C" void shim_61(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_61" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setIdx(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_61" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getDegree();) */
extern "C" void shim_62(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_62" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getDegree();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_62" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getTotalDegree();) */
extern "C" void shim_63(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_63" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getTotalDegree();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_63" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getTotalNumHs(bool includeNeighbors);) */
extern "C" void shim_64(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_64" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getTotalNumHs(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_64" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getTotalValence();) */
extern "C" void shim_65(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_65" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getTotalValence();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_65" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getNumImplicitHs();) */
extern "C" void shim_66(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_66" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getNumImplicitHs();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_66" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::int getExplicitValence();) */
extern "C" void shim_67(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_67" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getExplicitValence();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_67" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::int getImplicitValence();) */
extern "C" void shim_68(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_68" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getImplicitValence();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_68" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getNumRadicalElectrons();) */
extern "C" void shim_69(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_69" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getNumRadicalElectrons();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_69" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::void setNumRadicalElectrons(unsigned int num);) */
extern "C" void shim_70(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_70" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setNumRadicalElectrons(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_70" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::int getFormalCharge();) */
extern "C" void shim_71(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_71" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getFormalCharge();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_71" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::void setFormalCharge(int what);) */
extern "C" void shim_72(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_72" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setFormalCharge(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_72" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::void setNoImplicit(bool what);) */
extern "C" void shim_73(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_73" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setNoImplicit(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_73" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::bool getNoImplicit();) */
extern "C" void shim_74(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_74" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getNoImplicit();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_74" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::void setNumExplicitHs(unsigned int what);) */
extern "C" void shim_75(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_75" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setNumExplicitHs(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_75" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getNumExplicitHs();) */
extern "C" void shim_76(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_76" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getNumExplicitHs();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_76" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::void setIsAromatic(bool what);) */
extern "C" void shim_77(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_77" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setIsAromatic(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_77" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::bool getIsAromatic();) */
extern "C" void shim_78(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_78" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getIsAromatic();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_78" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::void setIsotope(unsigned int what);) */
extern "C" void shim_79(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_79" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setIsotope(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_79" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getIsotope();) */
extern "C" void shim_80(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_80" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getIsotope();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_80" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::void setChiralTag(RDKit::Atom::ChiralType what);) */
extern "C" void shim_81(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 4) {
        case 0: _a0 = "RDKit::Atom::ChiralType::CHI_UNSPECIFIED"; break;
        case 1: _a0 = "RDKit::Atom::ChiralType::CHI_TETRAHEDRAL_CW"; break;
        case 2: _a0 = "RDKit::Atom::ChiralType::CHI_TETRAHEDRAL_CCW"; break;
        case 3: _a0 = "RDKit::Atom::ChiralType::CHI_OTHER"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_81" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setChiralTag(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_81" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::void invertChirality();) */
extern "C" void shim_82(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_82" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->invertChirality();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_82" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::RDKit::Atom::ChiralType getChiralTag();) */
extern "C" void shim_83(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_83" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getChiralTag();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_83" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::void setHybridization(RDKit::Atom::HybridizationType what);) */
extern "C" void shim_84(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 8) {
        case 0: _a0 = "RDKit::Atom::HybridizationType::UNSPECIFIED"; break;
        case 1: _a0 = "RDKit::Atom::HybridizationType::S"; break;
        case 2: _a0 = "RDKit::Atom::HybridizationType::SP"; break;
        case 3: _a0 = "RDKit::Atom::HybridizationType::SP2"; break;
        case 4: _a0 = "RDKit::Atom::HybridizationType::SP3"; break;
        case 5: _a0 = "RDKit::Atom::HybridizationType::SP3D"; break;
        case 6: _a0 = "RDKit::Atom::HybridizationType::SP3D2"; break;
        case 7: _a0 = "RDKit::Atom::HybridizationType::OTHER"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_84" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setHybridization(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_84" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::RDKit::Atom::HybridizationType getHybridization();) */
extern "C" void shim_85(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_85" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getHybridization();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_85" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::bool hasQuery();) */
extern "C" void shim_86(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_86" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->hasQuery();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_86" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::bool Match(const RDKit::Atom * what);) */
extern "C" void shim_87(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_87" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->Match(" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_87" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::void updatePropertyCache(bool strict);) */
extern "C" void shim_88(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_88" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->updatePropertyCache(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_88" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::bool needsUpdatePropertyCache();) */
extern "C" void shim_89(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_89" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->needsUpdatePropertyCache();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_89" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::int calcExplicitValence(bool strict);) */
extern "C" void shim_90(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_90" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->calcExplicitValence(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_90" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::int calcImplicitValence(bool strict);) */
extern "C" void shim_91(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_91" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->calcImplicitValence(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_91" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::void setAtomMapNum(int mapno, bool strict);) */
extern "C" void shim_92(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    bool _a1 = *(static_cast<const char *>(context + 4)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_92" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setAtomMapNum(" << _a0 << ", " << (int)_a1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_92" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::int getAtomMapNum();) */
extern "C" void shim_93(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_93" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getAtomMapNum();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_93" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Atom::~RDKit::Atom();) */
extern "C" void shim_94(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_94" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    } // end shim_94" << std::endl;
}


/* CPPScope(name=RDKit::Bond & operator=(const RDKit::Bond &other)) */
extern "C" void shim_95(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_95" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->operator=(*" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_95" << std::endl;
}


/* CPPScope(name=RDKit::Bond * copy() const) */
extern "C" void shim_96(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_96" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = " << "var_" << _i0 << "->copy();\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_96" << std::endl;
}


/* CPPScope(name=void setOwningMol(RDKit::ROMol *other)) */
extern "C" void shim_97(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_97" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setOwningMol(" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_97" << std::endl;
}


/* CPPScope(name=void setOwningMol(RDKit::ROMol &other)) */
extern "C" void shim_98(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_98" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setOwningMol(*" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_98" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::RDKit::Bond();) */
extern "C" void shim_99(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_99" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new RDKit::Bond();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_99" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::RDKit::Bond(RDKit::Bond::BondType bT);) */
extern "C" void shim_100(void **in_ref, void **out_ref, const char *context) {
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 22) {
        case 0: _a0 = "RDKit::Bond::BondType::UNSPECIFIED"; break;
        case 1: _a0 = "RDKit::Bond::BondType::SINGLE"; break;
        case 2: _a0 = "RDKit::Bond::BondType::DOUBLE"; break;
        case 3: _a0 = "RDKit::Bond::BondType::TRIPLE"; break;
        case 4: _a0 = "RDKit::Bond::BondType::QUADRUPLE"; break;
        case 5: _a0 = "RDKit::Bond::BondType::QUINTUPLE"; break;
        case 6: _a0 = "RDKit::Bond::BondType::HEXTUPLE"; break;
        case 7: _a0 = "RDKit::Bond::BondType::ONEANDAHALF"; break;
        case 8: _a0 = "RDKit::Bond::BondType::TWOANDAHALF"; break;
        case 9: _a0 = "RDKit::Bond::BondType::THREEANDAHALF"; break;
        case 10: _a0 = "RDKit::Bond::BondType::FOURANDAHALF"; break;
        case 11: _a0 = "RDKit::Bond::BondType::FIVEANDAHALF"; break;
        case 12: _a0 = "RDKit::Bond::BondType::AROMATIC"; break;
        case 13: _a0 = "RDKit::Bond::BondType::IONIC"; break;
        case 14: _a0 = "RDKit::Bond::BondType::HYDROGEN"; break;
        case 15: _a0 = "RDKit::Bond::BondType::THREECENTER"; break;
        case 16: _a0 = "RDKit::Bond::BondType::DATIVEONE"; break;
        case 17: _a0 = "RDKit::Bond::BondType::DATIVE"; break;
        case 18: _a0 = "RDKit::Bond::BondType::DATIVEL"; break;
        case 19: _a0 = "RDKit::Bond::BondType::DATIVER"; break;
        case 20: _a0 = "RDKit::Bond::BondType::OTHER"; break;
        case 21: _a0 = "RDKit::Bond::BondType::ZERO"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_100" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new RDKit::Bond(" << _a0 << ");" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_100" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::RDKit::Bond(const RDKit::Bond & other);) */
extern "C" void shim_101(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_101" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new RDKit::Bond(*" << "var_" << _i0 << ");\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_101" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::RDKit::Bond::BondType getBondType();) */
extern "C" void shim_102(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_102" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getBondType();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_102" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::void setBondType(RDKit::Bond::BondType bT);) */
extern "C" void shim_103(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 22) {
        case 0: _a0 = "RDKit::Bond::BondType::UNSPECIFIED"; break;
        case 1: _a0 = "RDKit::Bond::BondType::SINGLE"; break;
        case 2: _a0 = "RDKit::Bond::BondType::DOUBLE"; break;
        case 3: _a0 = "RDKit::Bond::BondType::TRIPLE"; break;
        case 4: _a0 = "RDKit::Bond::BondType::QUADRUPLE"; break;
        case 5: _a0 = "RDKit::Bond::BondType::QUINTUPLE"; break;
        case 6: _a0 = "RDKit::Bond::BondType::HEXTUPLE"; break;
        case 7: _a0 = "RDKit::Bond::BondType::ONEANDAHALF"; break;
        case 8: _a0 = "RDKit::Bond::BondType::TWOANDAHALF"; break;
        case 9: _a0 = "RDKit::Bond::BondType::THREEANDAHALF"; break;
        case 10: _a0 = "RDKit::Bond::BondType::FOURANDAHALF"; break;
        case 11: _a0 = "RDKit::Bond::BondType::FIVEANDAHALF"; break;
        case 12: _a0 = "RDKit::Bond::BondType::AROMATIC"; break;
        case 13: _a0 = "RDKit::Bond::BondType::IONIC"; break;
        case 14: _a0 = "RDKit::Bond::BondType::HYDROGEN"; break;
        case 15: _a0 = "RDKit::Bond::BondType::THREECENTER"; break;
        case 16: _a0 = "RDKit::Bond::BondType::DATIVEONE"; break;
        case 17: _a0 = "RDKit::Bond::BondType::DATIVE"; break;
        case 18: _a0 = "RDKit::Bond::BondType::DATIVEL"; break;
        case 19: _a0 = "RDKit::Bond::BondType::DATIVER"; break;
        case 20: _a0 = "RDKit::Bond::BondType::OTHER"; break;
        case 21: _a0 = "RDKit::Bond::BondType::ZERO"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_103" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setBondType(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_103" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::void setIsAromatic(bool what);) */
extern "C" void shim_104(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_104" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setIsAromatic(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_104" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::bool getIsAromatic();) */
extern "C" void shim_105(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_105" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getIsAromatic();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_105" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::void setIsConjugated(bool what);) */
extern "C" void shim_106(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_106" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setIsConjugated(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_106" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::bool getIsConjugated();) */
extern "C" void shim_107(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_107" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getIsConjugated();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_107" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::bool hasOwningMol();) */
extern "C" void shim_108(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_108" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->hasOwningMol();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_108" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::void getOwningMol();) */
extern "C" void shim_109(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_109" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getOwningMol();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_109" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::unsigned int getIdx();) */
extern "C" void shim_110(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_110" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getIdx();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_110" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::void setIdx(unsigned int index);) */
extern "C" void shim_111(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_111" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setIdx(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_111" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::unsigned int getBeginAtomIdx();) */
extern "C" void shim_112(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_112" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getBeginAtomIdx();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_112" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::unsigned int getEndAtomIdx();) */
extern "C" void shim_113(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_113" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getEndAtomIdx();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_113" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::unsigned int getOtherAtomIdx(unsigned int thisIdx);) */
extern "C" void shim_114(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_114" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getOtherAtomIdx(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_114" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::void setBeginAtomIdx(unsigned int what);) */
extern "C" void shim_115(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_115" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setBeginAtomIdx(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_115" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::void setEndAtomIdx(unsigned int what);) */
extern "C" void shim_116(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_116" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setEndAtomIdx(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_116" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::void setBeginAtom(RDKit::Atom * at);) */
extern "C" void shim_117(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_117" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setBeginAtom(" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_117" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::void setEndAtom(RDKit::Atom * at);) */
extern "C" void shim_118(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_118" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setEndAtom(" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_118" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::bool hasQuery();) */
extern "C" void shim_119(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_119" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->hasQuery();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_119" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::void setBondDir(RDKit::Bond::BondDir what);) */
extern "C" void shim_120(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 7) {
        case 0: _a0 = "RDKit::Bond::BondDir::NONE"; break;
        case 1: _a0 = "RDKit::Bond::BondDir::BEGINWEDGE"; break;
        case 2: _a0 = "RDKit::Bond::BondDir::BEGINDASH"; break;
        case 3: _a0 = "RDKit::Bond::BondDir::ENDDOWNRIGHT"; break;
        case 4: _a0 = "RDKit::Bond::BondDir::ENDUPRIGHT"; break;
        case 5: _a0 = "RDKit::Bond::BondDir::EITHERDOUBLE"; break;
        case 6: _a0 = "RDKit::Bond::BondDir::UNKNOWN"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_120" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setBondDir(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_120" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::RDKit::Bond::BondDir getBondDir();) */
extern "C" void shim_121(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_121" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getBondDir();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_121" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::void setStereo(RDKit::Bond::BondStereo what);) */
extern "C" void shim_122(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 6) {
        case 0: _a0 = "RDKit::Bond::BondStereo::STEREONONE"; break;
        case 1: _a0 = "RDKit::Bond::BondStereo::STEREOANY"; break;
        case 2: _a0 = "RDKit::Bond::BondStereo::STEREOZ"; break;
        case 3: _a0 = "RDKit::Bond::BondStereo::STEREOE"; break;
        case 4: _a0 = "RDKit::Bond::BondStereo::STEREOCIS"; break;
        case 5: _a0 = "RDKit::Bond::BondStereo::STEREOTRANS"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_122" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setStereo(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_122" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::RDKit::Bond::BondStereo getStereo();) */
extern "C" void shim_123(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_123" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getStereo();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_123" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::void setStereoAtoms(unsigned int bgnIdx, unsigned int endIdx);) */
extern "C" void shim_124(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_124" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setStereoAtoms(" << _a0 << ", " << _a1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_124" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::void updatePropertyCache(bool strict);) */
extern "C" void shim_125(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Bond *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_125" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->updatePropertyCache(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_125" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Bond::~RDKit::Bond();) */
extern "C" void shim_126(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_126" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    } // end shim_126" << std::endl;
}


/* CPPScope(name=RDKit::Conformer & operator=(const RDKit::Conformer &other)) */
extern "C" void shim_127(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Conformer *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Conformer *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_127" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->operator=(*" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_127" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Conformer::RDKit::Conformer();) */
extern "C" void shim_128(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Conformer *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_128" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new RDKit::Conformer();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_128" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Conformer::RDKit::Conformer(unsigned int numAtoms);) */
extern "C" void shim_129(void **in_ref, void **out_ref, const char *context) {
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Conformer *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_129" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new RDKit::Conformer(" << _a0 << ");" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_129" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Conformer::RDKit::Conformer(const RDKit::Conformer & other);) */
extern "C" void shim_130(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Conformer *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Conformer *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_130" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new RDKit::Conformer(*" << "var_" << _i0 << ");\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_130" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Conformer::void resize(unsigned int size);) */
extern "C" void shim_131(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Conformer *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_131" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->resize(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_131" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Conformer::void reserve(unsigned int size);) */
extern "C" void shim_132(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Conformer *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_132" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->reserve(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_132" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Conformer::bool hasOwningMol();) */
extern "C" void shim_133(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Conformer *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_133" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->hasOwningMol();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_133" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Conformer::void getAtomPos(unsigned int atomId);) */
extern "C" void shim_134(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Conformer *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_134" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getAtomPos(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_134" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Conformer::void setAtomPos(unsigned int atomId, const RDGeom::Point3D & position);) */
extern "C" void shim_135(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Conformer *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDGeom::Point3D *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_135" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setAtomPos(" << _a0 << ", *" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_135" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Conformer::unsigned int getId();) */
extern "C" void shim_136(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Conformer *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_136" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getId();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_136" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Conformer::void setId(unsigned int id);) */
extern "C" void shim_137(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Conformer *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_137" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->setId(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_137" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Conformer::unsigned int getNumAtoms();) */
extern "C" void shim_138(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Conformer *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_138" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->getNumAtoms();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_138" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Conformer::bool is3D();) */
extern "C" void shim_139(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Conformer *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_139" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->is3D();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_139" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Conformer::void set3D(bool v);) */
extern "C" void shim_140(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::Conformer *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_140" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->set3D(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_140" << std::endl;
}


/* CPPScope(name=(auto) RDKit::Conformer::~RDKit::Conformer();) */
extern "C" void shim_141(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_141" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    } // end shim_141" << std::endl;
}


/* CPPScope(name=(auto) RDGeom::Point3D::RDGeom::Point3D();) */
extern "C" void shim_142(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDGeom::Point3D *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_142" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new RDGeom::Point3D();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_142" << std::endl;
}


/* CPPScope(name=(auto) RDGeom::Point3D::RDGeom::Point3D(const RDGeom::Point3D & other);) */
extern "C" void shim_143(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDGeom::Point3D *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDGeom::Point3D *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_143" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new RDGeom::Point3D(*" << "var_" << _i0 << ");\n        " << "var_" << _o1 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_143" << std::endl;
}


/* CPPScope(name=(auto) RDGeom::Point3D::unsigned int dimension();) */
extern "C" void shim_144(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDGeom::Point3D *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_144" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->dimension();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_144" << std::endl;
}


/* CPPScope(name=(auto) RDGeom::Point3D::void normalize();) */
extern "C" void shim_145(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDGeom::Point3D *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_145" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->normalize();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_145" << std::endl;
}


/* CPPScope(name=(auto) RDGeom::Point3D::~RDGeom::Point3D();) */
extern "C" void shim_146(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_146" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    } // end shim_146" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::void resize(unsigned int size);) */
extern "C" void shim_147(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_147" << std::endl;

    std::cout << "        " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << "->resize(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_147" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::void reserve(unsigned int size);) */
extern "C" void shim_148(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_148" << std::endl;

    std::cout << "        " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << "->reserve(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_148" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::bool hasOwningMol();) */
extern "C" void shim_149(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_149" << std::endl;

    std::cout << "        " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << "->hasOwningMol();\n        " << "var_" << _o0 << " = " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_149" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::void getAtomPos(unsigned int atomId);) */
extern "C" void shim_150(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_150" << std::endl;

    std::cout << "        " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << "->getAtomPos(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_150" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::void setAtomPos(unsigned int atomId, const RDGeom::Point3D & position);) */
extern "C" void shim_151(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDGeom::Point3D *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_151" << std::endl;

    std::cout << "        " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << "->setAtomPos(" << _a0 << ", *" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_151" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::unsigned int getId();) */
extern "C" void shim_152(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_152" << std::endl;

    std::cout << "        " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << "->getId();\n        " << "var_" << _o0 << " = " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_152" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::void setId(unsigned int id);) */
extern "C" void shim_153(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_153" << std::endl;

    std::cout << "        " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << "->setId(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_153" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::unsigned int getNumAtoms();) */
extern "C" void shim_154(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_154" << std::endl;

    std::cout << "        " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << "->getNumAtoms();\n        " << "var_" << _o0 << " = " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_154" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::bool is3D();) */
extern "C" void shim_155(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_155" << std::endl;

    std::cout << "        " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << "->is3D();\n        " << "var_" << _o0 << " = " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_155" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::void set3D(bool v);) */
extern "C" void shim_156(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_156" << std::endl;

    std::cout << "        " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << "->set3D(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Conformer *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_156" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::ROMol::void clearBondBookmark(int mark, const RDKit::Bond * bond);) */
extern "C" void shim_157(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::ROMol *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_157" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->clearBondBookmark(" << _a0 << ", " << "((RDKit::Bond *)var_" << _i1 << "->active)" << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "((RDKit::Bond *)var_" << _i1 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_157" << std::endl;
}


/* CPPScope(name=bundled_add_bond_copy) */
extern "C" void shim_158(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_158" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->addBond(" << "((RDKit::Bond *)var_" << _i1 << "->active)" << ", false);\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "((RDKit::Bond *)var_" << _i1 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_158" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::RWMol::void replaceBond(unsigned int idx, RDKit::Bond * bond, bool preserveProps);) */
extern "C" void shim_159(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    bool _a1 = *(static_cast<const char *>(context + 4)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    RDKit::RWMol *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_159" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->replaceBond(" << _a0 << ", " << "((RDKit::Bond *)var_" << _i1 << "->active)" << ", " << (int)_a1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "((RDKit::Bond *)var_" << _i1 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_159" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::RDKit::Bond::BondType getBondType();) */
extern "C" void shim_160(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_160" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->getBondType();\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_160" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setBondType(RDKit::Bond::BondType bT);) */
extern "C" void shim_161(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 22) {
        case 0: _a0 = "RDKit::Bond::BondType::UNSPECIFIED"; break;
        case 1: _a0 = "RDKit::Bond::BondType::SINGLE"; break;
        case 2: _a0 = "RDKit::Bond::BondType::DOUBLE"; break;
        case 3: _a0 = "RDKit::Bond::BondType::TRIPLE"; break;
        case 4: _a0 = "RDKit::Bond::BondType::QUADRUPLE"; break;
        case 5: _a0 = "RDKit::Bond::BondType::QUINTUPLE"; break;
        case 6: _a0 = "RDKit::Bond::BondType::HEXTUPLE"; break;
        case 7: _a0 = "RDKit::Bond::BondType::ONEANDAHALF"; break;
        case 8: _a0 = "RDKit::Bond::BondType::TWOANDAHALF"; break;
        case 9: _a0 = "RDKit::Bond::BondType::THREEANDAHALF"; break;
        case 10: _a0 = "RDKit::Bond::BondType::FOURANDAHALF"; break;
        case 11: _a0 = "RDKit::Bond::BondType::FIVEANDAHALF"; break;
        case 12: _a0 = "RDKit::Bond::BondType::AROMATIC"; break;
        case 13: _a0 = "RDKit::Bond::BondType::IONIC"; break;
        case 14: _a0 = "RDKit::Bond::BondType::HYDROGEN"; break;
        case 15: _a0 = "RDKit::Bond::BondType::THREECENTER"; break;
        case 16: _a0 = "RDKit::Bond::BondType::DATIVEONE"; break;
        case 17: _a0 = "RDKit::Bond::BondType::DATIVE"; break;
        case 18: _a0 = "RDKit::Bond::BondType::DATIVEL"; break;
        case 19: _a0 = "RDKit::Bond::BondType::DATIVER"; break;
        case 20: _a0 = "RDKit::Bond::BondType::OTHER"; break;
        case 21: _a0 = "RDKit::Bond::BondType::ZERO"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_161" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->setBondType(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_161" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setIsAromatic(bool what);) */
extern "C" void shim_162(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_162" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->setIsAromatic(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_162" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::bool getIsAromatic();) */
extern "C" void shim_163(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_163" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->getIsAromatic();\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_163" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setIsConjugated(bool what);) */
extern "C" void shim_164(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_164" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->setIsConjugated(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_164" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::bool getIsConjugated();) */
extern "C" void shim_165(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_165" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->getIsConjugated();\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_165" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::bool hasOwningMol();) */
extern "C" void shim_166(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_166" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->hasOwningMol();\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_166" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void getOwningMol();) */
extern "C" void shim_167(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_167" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->getOwningMol();\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_167" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::unsigned int getIdx();) */
extern "C" void shim_168(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_168" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->getIdx();\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_168" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setIdx(unsigned int index);) */
extern "C" void shim_169(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_169" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->setIdx(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_169" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::unsigned int getBeginAtomIdx();) */
extern "C" void shim_170(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_170" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->getBeginAtomIdx();\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_170" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::unsigned int getEndAtomIdx();) */
extern "C" void shim_171(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_171" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->getEndAtomIdx();\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_171" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::unsigned int getOtherAtomIdx(unsigned int thisIdx);) */
extern "C" void shim_172(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_172" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->getOtherAtomIdx(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_172" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setBeginAtomIdx(unsigned int what);) */
extern "C" void shim_173(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_173" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->setBeginAtomIdx(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_173" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setEndAtomIdx(unsigned int what);) */
extern "C" void shim_174(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_174" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->setEndAtomIdx(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_174" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setBeginAtom(RDKit::Atom * at);) */
extern "C" void shim_175(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_175" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->setBeginAtom(" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_175" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setEndAtom(RDKit::Atom * at);) */
extern "C" void shim_176(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    RDKit::Atom *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_176" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->setEndAtom(" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_176" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::bool hasQuery();) */
extern "C" void shim_177(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_177" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->hasQuery();\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_177" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setBondDir(RDKit::Bond::BondDir what);) */
extern "C" void shim_178(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 7) {
        case 0: _a0 = "RDKit::Bond::BondDir::NONE"; break;
        case 1: _a0 = "RDKit::Bond::BondDir::BEGINWEDGE"; break;
        case 2: _a0 = "RDKit::Bond::BondDir::BEGINDASH"; break;
        case 3: _a0 = "RDKit::Bond::BondDir::ENDDOWNRIGHT"; break;
        case 4: _a0 = "RDKit::Bond::BondDir::ENDUPRIGHT"; break;
        case 5: _a0 = "RDKit::Bond::BondDir::EITHERDOUBLE"; break;
        case 6: _a0 = "RDKit::Bond::BondDir::UNKNOWN"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_178" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->setBondDir(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_178" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::RDKit::Bond::BondDir getBondDir();) */
extern "C" void shim_179(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_179" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->getBondDir();\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_179" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setStereo(RDKit::Bond::BondStereo what);) */
extern "C" void shim_180(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    const char *_a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 6) {
        case 0: _a0 = "RDKit::Bond::BondStereo::STEREONONE"; break;
        case 1: _a0 = "RDKit::Bond::BondStereo::STEREOANY"; break;
        case 2: _a0 = "RDKit::Bond::BondStereo::STEREOZ"; break;
        case 3: _a0 = "RDKit::Bond::BondStereo::STEREOE"; break;
        case 4: _a0 = "RDKit::Bond::BondStereo::STEREOCIS"; break;
        case 5: _a0 = "RDKit::Bond::BondStereo::STEREOTRANS"; break;
    }
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_180" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->setStereo(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_180" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::RDKit::Bond::BondStereo getStereo();) */
extern "C" void shim_181(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_181" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->getStereo();\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_181" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setStereoAtoms(unsigned int bgnIdx, unsigned int endIdx);) */
extern "C" void shim_182(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_182" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->setStereoAtoms(" << _a0 << ", " << _a1 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_182" << std::endl;
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void updatePropertyCache(bool strict);) */
extern "C" void shim_183(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    unsigned long _o0 = CURR_ID++;
    std::cout << "    GFUZZ_BUNDLE *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_183" << std::endl;

    std::cout << "        " << "((RDKit::Bond *)var_" << _i0 << "->active)" << "->updatePropertyCache(" << (int)_a0 << ");\n        " << "var_" << _o0 << " = " << "((RDKit::Bond *)var_" << _i0 << "->active)" << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_183" << std::endl;
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
};

