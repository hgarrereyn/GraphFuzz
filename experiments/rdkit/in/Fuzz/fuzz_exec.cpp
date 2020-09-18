#include <Geometry/point.h>
#include <GraphMol/Atom.h>
#include <GraphMol/Bond.h>
#include <GraphMol/Conformer.h>
#include <GraphMol/ROMol.h>
#include <GraphMol/RWMol.h>


#include <string.h>
#include <stdlib.h>
#include <cstdint>

extern "C" int graphfuzz_try();

extern "C" void __attribute__((visibility ("default"))) shim_init() {
    RDKit::ROMol mol;
}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {

}


#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))

struct GFUZZ_BUNDLE {
public:
    void *active;
    void *inactive;
    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {};
};

#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)



/* CPPScope(name=void setAtomBookmark(RDKit::Atom *at, int mark)) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    RDKit::Atom *_i1 = reinterpret_cast<RDKit::Atom *>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::ROMol *_o0;
	_i0->setAtomBookmark(_i1, _a0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=void replaceAtomBookmark(RDKit::Atom *at, int mark)) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    RDKit::Atom *_i1 = reinterpret_cast<RDKit::Atom *>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::ROMol *_o0;
	_i0->replaceAtomBookmark(_i1, _a0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=void setBondBookmark(RDKit::Bond *bond, int mark)) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    RDKit::Bond *_i1 = reinterpret_cast<RDKit::Bond *>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::ROMol *_o0;
	_i0->setBondBookmark(_i1, _a0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=RDKit::Conformer & getConformer(int id)) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    GFUZZ_BUNDLE *_o0;
	RDKit::Conformer *conf = new RDKit::Conformer();
	*conf = _i0->getConformer(_a0);
	_o0 = BUNDLE(conf, _i0);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=unbundle_conformer) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    RDKit::ROMol *_o0;
	_o0 = (RDKit::ROMol *)_i0->inactive;
	delete _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=unsigned int addConformer(RDKit::Conformer *conf, bool assignId)) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    RDKit::Conformer *_i1 = reinterpret_cast<RDKit::Conformer *>(in_ref[1]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::ROMol *_o0;
	_i0->addConformer(_i1, _a0);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::unsigned int getNumAtoms();) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    RDKit::ROMol *_o0;
	_i0->getNumAtoms();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::unsigned int getNumAtoms(bool onlyExplicit);) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::ROMol *_o0;
	_i0->getNumAtoms(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::unsigned int getNumHeavyAtoms();) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    RDKit::ROMol *_o0;
	_i0->getNumHeavyAtoms();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::unsigned int getNumBonds(bool onlyHeavy);) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::ROMol *_o0;
	_i0->getNumBonds(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::void clearAtomBookmark(int mark);) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::ROMol *_o0;
	_i0->clearAtomBookmark(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::void clearAtomBookmark(int mark, const RDKit::Atom * atom);) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    RDKit::Atom *_i1 = reinterpret_cast<RDKit::Atom *>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::ROMol *_o0;
    RDKit::Atom *_o1;
	_i0->clearAtomBookmark(_a0, _i1);
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) RDKit::ROMol::void clearAllAtomBookmarks();) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    RDKit::ROMol *_o0;
	_i0->clearAllAtomBookmarks();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::bool hasAtomBookmark(int mark);) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::ROMol *_o0;
	_i0->hasAtomBookmark(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::void clearBondBookmark(int mark);) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::ROMol *_o0;
	_i0->clearBondBookmark(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::void clearBondBookmark(int mark, const RDKit::Bond * bond);) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    RDKit::Bond *_i1 = reinterpret_cast<RDKit::Bond *>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::ROMol *_o0;
    RDKit::Bond *_o1;
	_i0->clearBondBookmark(_a0, _i1);
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) RDKit::ROMol::void clearAllBondBookmarks();) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    RDKit::ROMol *_o0;
	_i0->clearAllBondBookmarks();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::bool hasBondBookmark(int mark);) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::ROMol *_o0;
	_i0->hasBondBookmark(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::void removeConformer(unsigned int id);) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::ROMol *_o0;
	_i0->removeConformer(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::void clearConformers();) */
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    RDKit::ROMol *_o0;
	_i0->clearConformers();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::unsigned int getNumConformers();) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    RDKit::ROMol *_o0;
	_i0->getNumConformers();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::void clearComputedProps(bool includeRings);) */
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::ROMol *_o0;
	_i0->clearComputedProps(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::void updatePropertyCache(bool strict);) */
extern "C" void shim_22(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::ROMol *_o0;
	_i0->updatePropertyCache(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::bool needsUpdatePropertyCache();) */
extern "C" void shim_23(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    RDKit::ROMol *_o0;
	_i0->needsUpdatePropertyCache();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::RDKit::ROMol();) */
extern "C" void shim_24(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_o0;
	_o0 = new RDKit::ROMol();
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::ROMol::RDKit::ROMol(const RDKit::ROMol & other, bool quickCopy, int confId);) */
extern "C" void shim_25(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    int _a1;
    memcpy(&_a1, context + 1, sizeof(int));
    RDKit::ROMol *_o0;
    RDKit::ROMol *_o1;
	_o0 = new RDKit::ROMol(*_i0, _a0, _a1);
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) RDKit::ROMol::~RDKit::ROMol();) */
extern "C" void shim_26(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
	delete _i0;
	
	                
}


/* CPPScope(name=add_atom_copy) */
extern "C" void shim_27(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    RDKit::Atom *_i1 = reinterpret_cast<RDKit::Atom *>(in_ref[1]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::RWMol *_o0;
    RDKit::Atom *_o1;
	_i0->addAtom(_i1, _a0, false);
	_o0 = _i0;
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=add_atom_owner) */
extern "C" void shim_28(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    RDKit::Atom *_i1 = reinterpret_cast<RDKit::Atom *>(in_ref[1]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::RWMol *_o0;
	_i0->addAtom(_i1, _a0, true);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=add_bond_copy) */
extern "C" void shim_29(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    RDKit::Bond *_i1 = reinterpret_cast<RDKit::Bond *>(in_ref[1]);
    RDKit::RWMol *_o0;
    RDKit::Bond *_o1;
	_i0->addBond(_i1, false);
	_o0 = _i0;
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=add_bond_owner) */
extern "C" void shim_30(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    RDKit::Bond *_i1 = reinterpret_cast<RDKit::Bond *>(in_ref[1]);
    RDKit::RWMol *_o0;
	_i0->addBond(_i1, true);
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=RDKit::Bond * createPartialBond(unsigned int beginAtomIdx, RDKit::Bond::BondType order)) */
extern "C" void shim_31(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    uint32_t _a0;
    memcpy(&_a0, context + 0, sizeof(uint32_t));
    RDKit::Bond::BondType _a1;
    switch (*(reinterpret_cast<const unsigned char *>(context + 4)) % 22) {
        case 0: _a1 = RDKit::Bond::BondType::UNSPECIFIED; break;
        case 1: _a1 = RDKit::Bond::BondType::SINGLE; break;
        case 2: _a1 = RDKit::Bond::BondType::DOUBLE; break;
        case 3: _a1 = RDKit::Bond::BondType::TRIPLE; break;
        case 4: _a1 = RDKit::Bond::BondType::QUADRUPLE; break;
        case 5: _a1 = RDKit::Bond::BondType::QUINTUPLE; break;
        case 6: _a1 = RDKit::Bond::BondType::HEXTUPLE; break;
        case 7: _a1 = RDKit::Bond::BondType::ONEANDAHALF; break;
        case 8: _a1 = RDKit::Bond::BondType::TWOANDAHALF; break;
        case 9: _a1 = RDKit::Bond::BondType::THREEANDAHALF; break;
        case 10: _a1 = RDKit::Bond::BondType::FOURANDAHALF; break;
        case 11: _a1 = RDKit::Bond::BondType::FIVEANDAHALF; break;
        case 12: _a1 = RDKit::Bond::BondType::AROMATIC; break;
        case 13: _a1 = RDKit::Bond::BondType::IONIC; break;
        case 14: _a1 = RDKit::Bond::BondType::HYDROGEN; break;
        case 15: _a1 = RDKit::Bond::BondType::THREECENTER; break;
        case 16: _a1 = RDKit::Bond::BondType::DATIVEONE; break;
        case 17: _a1 = RDKit::Bond::BondType::DATIVE; break;
        case 18: _a1 = RDKit::Bond::BondType::DATIVEL; break;
        case 19: _a1 = RDKit::Bond::BondType::DATIVER; break;
        case 20: _a1 = RDKit::Bond::BondType::OTHER; break;
        case 21: _a1 = RDKit::Bond::BondType::ZERO; break;
    }
    GFUZZ_BUNDLE *_o0;
	RDKit::Bond *bond = _i0->createPartialBond(_a0, _a1);
	_o0 = BUNDLE(bond, _i0);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=unbundle_bond) */
extern "C" void shim_32(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    RDKit::RWMol *_o0;
	_o0 = (RDKit::RWMol *)_i0->inactive;
	delete _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=RDKit::RWMol()) */
extern "C" void shim_33(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_o0;
	_o0 = new RDKit::RWMol();
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=destructor) */
extern "C" void shim_34(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
	delete _i0;
	
}


/* CPPScope(name=(auto) RDKit::RWMol::unsigned int addAtom(bool updateLabel);) */
extern "C" void shim_35(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::RWMol *_o0;
	_i0->addAtom(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::RWMol::void replaceAtom(unsigned int idx, RDKit::Atom * atom, bool updateLabel, bool preserveProps);) */
extern "C" void shim_36(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    RDKit::Atom *_i1 = reinterpret_cast<RDKit::Atom *>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    bool _a1 = *(static_cast<const char *>(context + 4)) & 1;
    bool _a2 = *(static_cast<const char *>(context + 5)) & 1;
    RDKit::RWMol *_o0;
    RDKit::Atom *_o1;
	_i0->replaceAtom(_a0, _i1, _a1, _a2);
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) RDKit::RWMol::void setActiveAtom(RDKit::Atom * atom);) */
extern "C" void shim_37(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    RDKit::Atom *_i1 = reinterpret_cast<RDKit::Atom *>(in_ref[1]);
    RDKit::RWMol *_o0;
    RDKit::Atom *_o1;
	_i0->setActiveAtom(_i1);
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) RDKit::RWMol::void setActiveAtom(unsigned int idx);) */
extern "C" void shim_38(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::RWMol *_o0;
	_i0->setActiveAtom(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::RWMol::void removeAtom(unsigned int idx);) */
extern "C" void shim_39(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::RWMol *_o0;
	_i0->removeAtom(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::RWMol::void removeAtom(RDKit::Atom * atom);) */
extern "C" void shim_40(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    RDKit::Atom *_i1 = reinterpret_cast<RDKit::Atom *>(in_ref[1]);
    RDKit::RWMol *_o0;
    RDKit::Atom *_o1;
	_i0->removeAtom(_i1);
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) RDKit::RWMol::unsigned int addBond(unsigned int beginAtomIdx, unsigned int endAtomIdx, RDKit::Bond::BondType order);) */
extern "C" void shim_41(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    RDKit::Bond::BondType _a2;
    switch (*(reinterpret_cast<const unsigned char *>(context + 8)) % 22) {
        case 0: _a2 = RDKit::Bond::BondType::UNSPECIFIED; break;
        case 1: _a2 = RDKit::Bond::BondType::SINGLE; break;
        case 2: _a2 = RDKit::Bond::BondType::DOUBLE; break;
        case 3: _a2 = RDKit::Bond::BondType::TRIPLE; break;
        case 4: _a2 = RDKit::Bond::BondType::QUADRUPLE; break;
        case 5: _a2 = RDKit::Bond::BondType::QUINTUPLE; break;
        case 6: _a2 = RDKit::Bond::BondType::HEXTUPLE; break;
        case 7: _a2 = RDKit::Bond::BondType::ONEANDAHALF; break;
        case 8: _a2 = RDKit::Bond::BondType::TWOANDAHALF; break;
        case 9: _a2 = RDKit::Bond::BondType::THREEANDAHALF; break;
        case 10: _a2 = RDKit::Bond::BondType::FOURANDAHALF; break;
        case 11: _a2 = RDKit::Bond::BondType::FIVEANDAHALF; break;
        case 12: _a2 = RDKit::Bond::BondType::AROMATIC; break;
        case 13: _a2 = RDKit::Bond::BondType::IONIC; break;
        case 14: _a2 = RDKit::Bond::BondType::HYDROGEN; break;
        case 15: _a2 = RDKit::Bond::BondType::THREECENTER; break;
        case 16: _a2 = RDKit::Bond::BondType::DATIVEONE; break;
        case 17: _a2 = RDKit::Bond::BondType::DATIVE; break;
        case 18: _a2 = RDKit::Bond::BondType::DATIVEL; break;
        case 19: _a2 = RDKit::Bond::BondType::DATIVER; break;
        case 20: _a2 = RDKit::Bond::BondType::OTHER; break;
        case 21: _a2 = RDKit::Bond::BondType::ZERO; break;
    }
    RDKit::RWMol *_o0;
	_i0->addBond(_a0, _a1, _a2);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::RWMol::unsigned int addBond(RDKit::Atom * beginAtom, RDKit::Atom * endAtom, RDKit::Bond::BondType order);) */
extern "C" void shim_42(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    RDKit::Atom *_i1 = reinterpret_cast<RDKit::Atom *>(in_ref[1]);
    RDKit::Atom *_i2 = reinterpret_cast<RDKit::Atom *>(in_ref[2]);
    RDKit::Bond::BondType _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 22) {
        case 0: _a0 = RDKit::Bond::BondType::UNSPECIFIED; break;
        case 1: _a0 = RDKit::Bond::BondType::SINGLE; break;
        case 2: _a0 = RDKit::Bond::BondType::DOUBLE; break;
        case 3: _a0 = RDKit::Bond::BondType::TRIPLE; break;
        case 4: _a0 = RDKit::Bond::BondType::QUADRUPLE; break;
        case 5: _a0 = RDKit::Bond::BondType::QUINTUPLE; break;
        case 6: _a0 = RDKit::Bond::BondType::HEXTUPLE; break;
        case 7: _a0 = RDKit::Bond::BondType::ONEANDAHALF; break;
        case 8: _a0 = RDKit::Bond::BondType::TWOANDAHALF; break;
        case 9: _a0 = RDKit::Bond::BondType::THREEANDAHALF; break;
        case 10: _a0 = RDKit::Bond::BondType::FOURANDAHALF; break;
        case 11: _a0 = RDKit::Bond::BondType::FIVEANDAHALF; break;
        case 12: _a0 = RDKit::Bond::BondType::AROMATIC; break;
        case 13: _a0 = RDKit::Bond::BondType::IONIC; break;
        case 14: _a0 = RDKit::Bond::BondType::HYDROGEN; break;
        case 15: _a0 = RDKit::Bond::BondType::THREECENTER; break;
        case 16: _a0 = RDKit::Bond::BondType::DATIVEONE; break;
        case 17: _a0 = RDKit::Bond::BondType::DATIVE; break;
        case 18: _a0 = RDKit::Bond::BondType::DATIVEL; break;
        case 19: _a0 = RDKit::Bond::BondType::DATIVER; break;
        case 20: _a0 = RDKit::Bond::BondType::OTHER; break;
        case 21: _a0 = RDKit::Bond::BondType::ZERO; break;
    }
    RDKit::RWMol *_o0;
    RDKit::Atom *_o1;
    RDKit::Atom *_o2;
	_i0->addBond(_i1, _i2, _a0);
	_o0 = _i0;
	_o1 = _i1;
	_o2 = _i2;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
    out_ref[2] = reinterpret_cast<void *>(_o2);
}


/* CPPScope(name=(auto) RDKit::RWMol::unsigned int finishPartialBond(unsigned int endAtomIdx, int bondBookmark, RDKit::Bond::BondType order);) */
extern "C" void shim_43(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    RDKit::Bond::BondType _a2;
    switch (*(reinterpret_cast<const unsigned char *>(context + 8)) % 22) {
        case 0: _a2 = RDKit::Bond::BondType::UNSPECIFIED; break;
        case 1: _a2 = RDKit::Bond::BondType::SINGLE; break;
        case 2: _a2 = RDKit::Bond::BondType::DOUBLE; break;
        case 3: _a2 = RDKit::Bond::BondType::TRIPLE; break;
        case 4: _a2 = RDKit::Bond::BondType::QUADRUPLE; break;
        case 5: _a2 = RDKit::Bond::BondType::QUINTUPLE; break;
        case 6: _a2 = RDKit::Bond::BondType::HEXTUPLE; break;
        case 7: _a2 = RDKit::Bond::BondType::ONEANDAHALF; break;
        case 8: _a2 = RDKit::Bond::BondType::TWOANDAHALF; break;
        case 9: _a2 = RDKit::Bond::BondType::THREEANDAHALF; break;
        case 10: _a2 = RDKit::Bond::BondType::FOURANDAHALF; break;
        case 11: _a2 = RDKit::Bond::BondType::FIVEANDAHALF; break;
        case 12: _a2 = RDKit::Bond::BondType::AROMATIC; break;
        case 13: _a2 = RDKit::Bond::BondType::IONIC; break;
        case 14: _a2 = RDKit::Bond::BondType::HYDROGEN; break;
        case 15: _a2 = RDKit::Bond::BondType::THREECENTER; break;
        case 16: _a2 = RDKit::Bond::BondType::DATIVEONE; break;
        case 17: _a2 = RDKit::Bond::BondType::DATIVE; break;
        case 18: _a2 = RDKit::Bond::BondType::DATIVEL; break;
        case 19: _a2 = RDKit::Bond::BondType::DATIVER; break;
        case 20: _a2 = RDKit::Bond::BondType::OTHER; break;
        case 21: _a2 = RDKit::Bond::BondType::ZERO; break;
    }
    RDKit::RWMol *_o0;
	_i0->finishPartialBond(_a0, _a1, _a2);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::RWMol::void removeBond(unsigned int beginAtomIdx, unsigned int endAtomIdx);) */
extern "C" void shim_44(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    RDKit::RWMol *_o0;
	_i0->removeBond(_a0, _a1);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::RWMol::void replaceBond(unsigned int idx, RDKit::Bond * bond, bool preserveProps);) */
extern "C" void shim_45(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    RDKit::Bond *_i1 = reinterpret_cast<RDKit::Bond *>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    bool _a1 = *(static_cast<const char *>(context + 4)) & 1;
    RDKit::RWMol *_o0;
    RDKit::Bond *_o1;
	_i0->replaceBond(_a0, _i1, _a1);
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) RDKit::RWMol::void clear();) */
extern "C" void shim_46(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    RDKit::RWMol *_o0;
	_i0->clear();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::RWMol::void beginBatchEdit();) */
extern "C" void shim_47(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    RDKit::RWMol *_o0;
	_i0->beginBatchEdit();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::RWMol::void rollbackBatchEdit();) */
extern "C" void shim_48(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    RDKit::RWMol *_o0;
	_i0->rollbackBatchEdit();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::RWMol::void commitBatchEdit();) */
extern "C" void shim_49(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    RDKit::RWMol *_o0;
	_i0->commitBatchEdit();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::RWMol::void insertMol(const RDKit::ROMol & other);) */
extern "C" void shim_50(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    RDKit::ROMol *_i1 = reinterpret_cast<RDKit::ROMol *>(in_ref[1]);
    RDKit::RWMol *_o0;
    RDKit::ROMol *_o1;
	_i0->insertMol(*_i1);
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=RDKit::Atom & operator=(const RDKit::Atom &other)) */
extern "C" void shim_51(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_i1 = reinterpret_cast<RDKit::Atom *>(in_ref[1]);
    RDKit::Atom *_o0;
    RDKit::Atom *_o1;
	_i0->operator=(*_i1);
	_o0 = _i0;
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=RDKit::Atom * copy() const) */
extern "C" void shim_52(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
    RDKit::Atom *_o1;
	_o0 = _i0->copy();
	_o1 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) RDKit::Atom::RDKit::Atom();) */
extern "C" void shim_53(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_o0;
	_o0 = new RDKit::Atom();
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::RDKit::Atom(unsigned int num);) */
extern "C" void shim_54(void **in_ref, void **out_ref, const char *context) {
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::Atom *_o0;
	_o0 = new RDKit::Atom(_a0);
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::RDKit::Atom(const RDKit::Atom & other);) */
extern "C" void shim_55(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
    RDKit::Atom *_o1;
	_o0 = new RDKit::Atom(*_i0);
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) RDKit::Atom::int getAtomicNum();) */
extern "C" void shim_56(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getAtomicNum();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::void setAtomicNum(int newNum);) */
extern "C" void shim_57(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::Atom *_o0;
	_i0->setAtomicNum(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::bool hasOwningMol();) */
extern "C" void shim_58(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->hasOwningMol();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::void getOwningMol();) */
extern "C" void shim_59(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getOwningMol();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getIdx();) */
extern "C" void shim_60(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getIdx();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::void setIdx(unsigned int index);) */
extern "C" void shim_61(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::Atom *_o0;
	_i0->setIdx(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getDegree();) */
extern "C" void shim_62(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getDegree();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getTotalDegree();) */
extern "C" void shim_63(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getTotalDegree();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getTotalNumHs(bool includeNeighbors);) */
extern "C" void shim_64(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::Atom *_o0;
	_i0->getTotalNumHs(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getTotalValence();) */
extern "C" void shim_65(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getTotalValence();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getNumImplicitHs();) */
extern "C" void shim_66(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getNumImplicitHs();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::int getExplicitValence();) */
extern "C" void shim_67(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getExplicitValence();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::int getImplicitValence();) */
extern "C" void shim_68(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getImplicitValence();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getNumRadicalElectrons();) */
extern "C" void shim_69(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getNumRadicalElectrons();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::void setNumRadicalElectrons(unsigned int num);) */
extern "C" void shim_70(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::Atom *_o0;
	_i0->setNumRadicalElectrons(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::int getFormalCharge();) */
extern "C" void shim_71(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getFormalCharge();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::void setFormalCharge(int what);) */
extern "C" void shim_72(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::Atom *_o0;
	_i0->setFormalCharge(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::void setNoImplicit(bool what);) */
extern "C" void shim_73(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::Atom *_o0;
	_i0->setNoImplicit(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::bool getNoImplicit();) */
extern "C" void shim_74(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getNoImplicit();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::void setNumExplicitHs(unsigned int what);) */
extern "C" void shim_75(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::Atom *_o0;
	_i0->setNumExplicitHs(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getNumExplicitHs();) */
extern "C" void shim_76(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getNumExplicitHs();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::void setIsAromatic(bool what);) */
extern "C" void shim_77(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::Atom *_o0;
	_i0->setIsAromatic(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::bool getIsAromatic();) */
extern "C" void shim_78(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getIsAromatic();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::void setIsotope(unsigned int what);) */
extern "C" void shim_79(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::Atom *_o0;
	_i0->setIsotope(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::unsigned int getIsotope();) */
extern "C" void shim_80(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getIsotope();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::void setChiralTag(RDKit::Atom::ChiralType what);) */
extern "C" void shim_81(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom::ChiralType _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 4) {
        case 0: _a0 = RDKit::Atom::ChiralType::CHI_UNSPECIFIED; break;
        case 1: _a0 = RDKit::Atom::ChiralType::CHI_TETRAHEDRAL_CW; break;
        case 2: _a0 = RDKit::Atom::ChiralType::CHI_TETRAHEDRAL_CCW; break;
        case 3: _a0 = RDKit::Atom::ChiralType::CHI_OTHER; break;
    }
    RDKit::Atom *_o0;
	_i0->setChiralTag(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::void invertChirality();) */
extern "C" void shim_82(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->invertChirality();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::RDKit::Atom::ChiralType getChiralTag();) */
extern "C" void shim_83(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getChiralTag();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::void setHybridization(RDKit::Atom::HybridizationType what);) */
extern "C" void shim_84(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom::HybridizationType _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 8) {
        case 0: _a0 = RDKit::Atom::HybridizationType::UNSPECIFIED; break;
        case 1: _a0 = RDKit::Atom::HybridizationType::S; break;
        case 2: _a0 = RDKit::Atom::HybridizationType::SP; break;
        case 3: _a0 = RDKit::Atom::HybridizationType::SP2; break;
        case 4: _a0 = RDKit::Atom::HybridizationType::SP3; break;
        case 5: _a0 = RDKit::Atom::HybridizationType::SP3D; break;
        case 6: _a0 = RDKit::Atom::HybridizationType::SP3D2; break;
        case 7: _a0 = RDKit::Atom::HybridizationType::OTHER; break;
    }
    RDKit::Atom *_o0;
	_i0->setHybridization(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::RDKit::Atom::HybridizationType getHybridization();) */
extern "C" void shim_85(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getHybridization();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::bool hasQuery();) */
extern "C" void shim_86(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->hasQuery();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::bool Match(const RDKit::Atom * what);) */
extern "C" void shim_87(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_i1 = reinterpret_cast<RDKit::Atom *>(in_ref[1]);
    RDKit::Atom *_o0;
    RDKit::Atom *_o1;
	_i0->Match(_i1);
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) RDKit::Atom::void updatePropertyCache(bool strict);) */
extern "C" void shim_88(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::Atom *_o0;
	_i0->updatePropertyCache(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::bool needsUpdatePropertyCache();) */
extern "C" void shim_89(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->needsUpdatePropertyCache();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::int calcExplicitValence(bool strict);) */
extern "C" void shim_90(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::Atom *_o0;
	_i0->calcExplicitValence(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::int calcImplicitValence(bool strict);) */
extern "C" void shim_91(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::Atom *_o0;
	_i0->calcImplicitValence(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::void setAtomMapNum(int mapno, bool strict);) */
extern "C" void shim_92(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    bool _a1 = *(static_cast<const char *>(context + 4)) & 1;
    RDKit::Atom *_o0;
	_i0->setAtomMapNum(_a0, _a1);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::int getAtomMapNum();) */
extern "C" void shim_93(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
    RDKit::Atom *_o0;
	_i0->getAtomMapNum();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Atom::~RDKit::Atom();) */
extern "C" void shim_94(void **in_ref, void **out_ref, const char *context) {
    RDKit::Atom *_i0 = reinterpret_cast<RDKit::Atom *>(in_ref[0]);
	delete _i0;
	
	                
}


/* CPPScope(name=RDKit::Bond & operator=(const RDKit::Bond &other)) */
extern "C" void shim_95(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Bond *_i1 = reinterpret_cast<RDKit::Bond *>(in_ref[1]);
    RDKit::Bond *_o0;
    RDKit::Bond *_o1;
	_i0->operator=(*_i1);
	_o0 = _i0;
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=RDKit::Bond * copy() const) */
extern "C" void shim_96(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Bond *_o0;
    RDKit::Bond *_o1;
	_o0 = _i0->copy();
	_o1 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=void setOwningMol(RDKit::ROMol *other)) */
extern "C" void shim_97(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::ROMol *_i1 = reinterpret_cast<RDKit::ROMol *>(in_ref[1]);
    RDKit::ROMol *_o0;
	_i0->setOwningMol(_i1);
	_o0 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=void setOwningMol(RDKit::ROMol &other)) */
extern "C" void shim_98(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::ROMol *_i1 = reinterpret_cast<RDKit::ROMol *>(in_ref[1]);
    RDKit::ROMol *_o0;
	_i0->setOwningMol(*_i1);
	_o0 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::RDKit::Bond();) */
extern "C" void shim_99(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_o0;
	_o0 = new RDKit::Bond();
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::RDKit::Bond(RDKit::Bond::BondType bT);) */
extern "C" void shim_100(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond::BondType _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 22) {
        case 0: _a0 = RDKit::Bond::BondType::UNSPECIFIED; break;
        case 1: _a0 = RDKit::Bond::BondType::SINGLE; break;
        case 2: _a0 = RDKit::Bond::BondType::DOUBLE; break;
        case 3: _a0 = RDKit::Bond::BondType::TRIPLE; break;
        case 4: _a0 = RDKit::Bond::BondType::QUADRUPLE; break;
        case 5: _a0 = RDKit::Bond::BondType::QUINTUPLE; break;
        case 6: _a0 = RDKit::Bond::BondType::HEXTUPLE; break;
        case 7: _a0 = RDKit::Bond::BondType::ONEANDAHALF; break;
        case 8: _a0 = RDKit::Bond::BondType::TWOANDAHALF; break;
        case 9: _a0 = RDKit::Bond::BondType::THREEANDAHALF; break;
        case 10: _a0 = RDKit::Bond::BondType::FOURANDAHALF; break;
        case 11: _a0 = RDKit::Bond::BondType::FIVEANDAHALF; break;
        case 12: _a0 = RDKit::Bond::BondType::AROMATIC; break;
        case 13: _a0 = RDKit::Bond::BondType::IONIC; break;
        case 14: _a0 = RDKit::Bond::BondType::HYDROGEN; break;
        case 15: _a0 = RDKit::Bond::BondType::THREECENTER; break;
        case 16: _a0 = RDKit::Bond::BondType::DATIVEONE; break;
        case 17: _a0 = RDKit::Bond::BondType::DATIVE; break;
        case 18: _a0 = RDKit::Bond::BondType::DATIVEL; break;
        case 19: _a0 = RDKit::Bond::BondType::DATIVER; break;
        case 20: _a0 = RDKit::Bond::BondType::OTHER; break;
        case 21: _a0 = RDKit::Bond::BondType::ZERO; break;
    }
    RDKit::Bond *_o0;
	_o0 = new RDKit::Bond(_a0);
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::RDKit::Bond(const RDKit::Bond & other);) */
extern "C" void shim_101(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Bond *_o0;
    RDKit::Bond *_o1;
	_o0 = new RDKit::Bond(*_i0);
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) RDKit::Bond::RDKit::Bond::BondType getBondType();) */
extern "C" void shim_102(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Bond *_o0;
	_i0->getBondType();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::void setBondType(RDKit::Bond::BondType bT);) */
extern "C" void shim_103(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Bond::BondType _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 22) {
        case 0: _a0 = RDKit::Bond::BondType::UNSPECIFIED; break;
        case 1: _a0 = RDKit::Bond::BondType::SINGLE; break;
        case 2: _a0 = RDKit::Bond::BondType::DOUBLE; break;
        case 3: _a0 = RDKit::Bond::BondType::TRIPLE; break;
        case 4: _a0 = RDKit::Bond::BondType::QUADRUPLE; break;
        case 5: _a0 = RDKit::Bond::BondType::QUINTUPLE; break;
        case 6: _a0 = RDKit::Bond::BondType::HEXTUPLE; break;
        case 7: _a0 = RDKit::Bond::BondType::ONEANDAHALF; break;
        case 8: _a0 = RDKit::Bond::BondType::TWOANDAHALF; break;
        case 9: _a0 = RDKit::Bond::BondType::THREEANDAHALF; break;
        case 10: _a0 = RDKit::Bond::BondType::FOURANDAHALF; break;
        case 11: _a0 = RDKit::Bond::BondType::FIVEANDAHALF; break;
        case 12: _a0 = RDKit::Bond::BondType::AROMATIC; break;
        case 13: _a0 = RDKit::Bond::BondType::IONIC; break;
        case 14: _a0 = RDKit::Bond::BondType::HYDROGEN; break;
        case 15: _a0 = RDKit::Bond::BondType::THREECENTER; break;
        case 16: _a0 = RDKit::Bond::BondType::DATIVEONE; break;
        case 17: _a0 = RDKit::Bond::BondType::DATIVE; break;
        case 18: _a0 = RDKit::Bond::BondType::DATIVEL; break;
        case 19: _a0 = RDKit::Bond::BondType::DATIVER; break;
        case 20: _a0 = RDKit::Bond::BondType::OTHER; break;
        case 21: _a0 = RDKit::Bond::BondType::ZERO; break;
    }
    RDKit::Bond *_o0;
	_i0->setBondType(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::void setIsAromatic(bool what);) */
extern "C" void shim_104(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::Bond *_o0;
	_i0->setIsAromatic(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::bool getIsAromatic();) */
extern "C" void shim_105(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Bond *_o0;
	_i0->getIsAromatic();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::void setIsConjugated(bool what);) */
extern "C" void shim_106(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::Bond *_o0;
	_i0->setIsConjugated(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::bool getIsConjugated();) */
extern "C" void shim_107(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Bond *_o0;
	_i0->getIsConjugated();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::bool hasOwningMol();) */
extern "C" void shim_108(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Bond *_o0;
	_i0->hasOwningMol();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::void getOwningMol();) */
extern "C" void shim_109(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Bond *_o0;
	_i0->getOwningMol();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::unsigned int getIdx();) */
extern "C" void shim_110(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Bond *_o0;
	_i0->getIdx();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::void setIdx(unsigned int index);) */
extern "C" void shim_111(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::Bond *_o0;
	_i0->setIdx(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::unsigned int getBeginAtomIdx();) */
extern "C" void shim_112(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Bond *_o0;
	_i0->getBeginAtomIdx();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::unsigned int getEndAtomIdx();) */
extern "C" void shim_113(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Bond *_o0;
	_i0->getEndAtomIdx();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::unsigned int getOtherAtomIdx(unsigned int thisIdx);) */
extern "C" void shim_114(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::Bond *_o0;
	_i0->getOtherAtomIdx(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::void setBeginAtomIdx(unsigned int what);) */
extern "C" void shim_115(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::Bond *_o0;
	_i0->setBeginAtomIdx(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::void setEndAtomIdx(unsigned int what);) */
extern "C" void shim_116(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::Bond *_o0;
	_i0->setEndAtomIdx(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::void setBeginAtom(RDKit::Atom * at);) */
extern "C" void shim_117(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Atom *_i1 = reinterpret_cast<RDKit::Atom *>(in_ref[1]);
    RDKit::Bond *_o0;
    RDKit::Atom *_o1;
	_i0->setBeginAtom(_i1);
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) RDKit::Bond::void setEndAtom(RDKit::Atom * at);) */
extern "C" void shim_118(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Atom *_i1 = reinterpret_cast<RDKit::Atom *>(in_ref[1]);
    RDKit::Bond *_o0;
    RDKit::Atom *_o1;
	_i0->setEndAtom(_i1);
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) RDKit::Bond::bool hasQuery();) */
extern "C" void shim_119(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Bond *_o0;
	_i0->hasQuery();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::void setBondDir(RDKit::Bond::BondDir what);) */
extern "C" void shim_120(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Bond::BondDir _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 7) {
        case 0: _a0 = RDKit::Bond::BondDir::NONE; break;
        case 1: _a0 = RDKit::Bond::BondDir::BEGINWEDGE; break;
        case 2: _a0 = RDKit::Bond::BondDir::BEGINDASH; break;
        case 3: _a0 = RDKit::Bond::BondDir::ENDDOWNRIGHT; break;
        case 4: _a0 = RDKit::Bond::BondDir::ENDUPRIGHT; break;
        case 5: _a0 = RDKit::Bond::BondDir::EITHERDOUBLE; break;
        case 6: _a0 = RDKit::Bond::BondDir::UNKNOWN; break;
    }
    RDKit::Bond *_o0;
	_i0->setBondDir(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::RDKit::Bond::BondDir getBondDir();) */
extern "C" void shim_121(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Bond *_o0;
	_i0->getBondDir();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::void setStereo(RDKit::Bond::BondStereo what);) */
extern "C" void shim_122(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Bond::BondStereo _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 6) {
        case 0: _a0 = RDKit::Bond::BondStereo::STEREONONE; break;
        case 1: _a0 = RDKit::Bond::BondStereo::STEREOANY; break;
        case 2: _a0 = RDKit::Bond::BondStereo::STEREOZ; break;
        case 3: _a0 = RDKit::Bond::BondStereo::STEREOE; break;
        case 4: _a0 = RDKit::Bond::BondStereo::STEREOCIS; break;
        case 5: _a0 = RDKit::Bond::BondStereo::STEREOTRANS; break;
    }
    RDKit::Bond *_o0;
	_i0->setStereo(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::RDKit::Bond::BondStereo getStereo();) */
extern "C" void shim_123(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    RDKit::Bond *_o0;
	_i0->getStereo();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::void setStereoAtoms(unsigned int bgnIdx, unsigned int endIdx);) */
extern "C" void shim_124(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    RDKit::Bond *_o0;
	_i0->setStereoAtoms(_a0, _a1);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::void updatePropertyCache(bool strict);) */
extern "C" void shim_125(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::Bond *_o0;
	_i0->updatePropertyCache(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Bond::~RDKit::Bond();) */
extern "C" void shim_126(void **in_ref, void **out_ref, const char *context) {
    RDKit::Bond *_i0 = reinterpret_cast<RDKit::Bond *>(in_ref[0]);
	delete _i0;
	
	                
}


/* CPPScope(name=RDKit::Conformer & operator=(const RDKit::Conformer &other)) */
extern "C" void shim_127(void **in_ref, void **out_ref, const char *context) {
    RDKit::Conformer *_i0 = reinterpret_cast<RDKit::Conformer *>(in_ref[0]);
    RDKit::Conformer *_i1 = reinterpret_cast<RDKit::Conformer *>(in_ref[1]);
    RDKit::Conformer *_o0;
    RDKit::Conformer *_o1;
	_i0->operator=(*_i1);
	_o0 = _i0;
	_o1 = _i1;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) RDKit::Conformer::RDKit::Conformer();) */
extern "C" void shim_128(void **in_ref, void **out_ref, const char *context) {
    RDKit::Conformer *_o0;
	_o0 = new RDKit::Conformer();
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Conformer::RDKit::Conformer(unsigned int numAtoms);) */
extern "C" void shim_129(void **in_ref, void **out_ref, const char *context) {
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::Conformer *_o0;
	_o0 = new RDKit::Conformer(_a0);
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Conformer::RDKit::Conformer(const RDKit::Conformer & other);) */
extern "C" void shim_130(void **in_ref, void **out_ref, const char *context) {
    RDKit::Conformer *_i0 = reinterpret_cast<RDKit::Conformer *>(in_ref[0]);
    RDKit::Conformer *_o0;
    RDKit::Conformer *_o1;
	_o0 = new RDKit::Conformer(*_i0);
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) RDKit::Conformer::void resize(unsigned int size);) */
extern "C" void shim_131(void **in_ref, void **out_ref, const char *context) {
    RDKit::Conformer *_i0 = reinterpret_cast<RDKit::Conformer *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::Conformer *_o0;
	_i0->resize(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Conformer::void reserve(unsigned int size);) */
extern "C" void shim_132(void **in_ref, void **out_ref, const char *context) {
    RDKit::Conformer *_i0 = reinterpret_cast<RDKit::Conformer *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::Conformer *_o0;
	_i0->reserve(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Conformer::bool hasOwningMol();) */
extern "C" void shim_133(void **in_ref, void **out_ref, const char *context) {
    RDKit::Conformer *_i0 = reinterpret_cast<RDKit::Conformer *>(in_ref[0]);
    RDKit::Conformer *_o0;
	_i0->hasOwningMol();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Conformer::void getAtomPos(unsigned int atomId);) */
extern "C" void shim_134(void **in_ref, void **out_ref, const char *context) {
    RDKit::Conformer *_i0 = reinterpret_cast<RDKit::Conformer *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::Conformer *_o0;
	_i0->getAtomPos(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Conformer::void setAtomPos(unsigned int atomId, const RDGeom::Point3D & position);) */
extern "C" void shim_135(void **in_ref, void **out_ref, const char *context) {
    RDKit::Conformer *_i0 = reinterpret_cast<RDKit::Conformer *>(in_ref[0]);
    RDGeom::Point3D *_i1 = reinterpret_cast<RDGeom::Point3D *>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::Conformer *_o0;
    RDGeom::Point3D *_o1;
	_i0->setAtomPos(_a0, *_i1);
	_o0 = _i0;
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) RDKit::Conformer::unsigned int getId();) */
extern "C" void shim_136(void **in_ref, void **out_ref, const char *context) {
    RDKit::Conformer *_i0 = reinterpret_cast<RDKit::Conformer *>(in_ref[0]);
    RDKit::Conformer *_o0;
	_i0->getId();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Conformer::void setId(unsigned int id);) */
extern "C" void shim_137(void **in_ref, void **out_ref, const char *context) {
    RDKit::Conformer *_i0 = reinterpret_cast<RDKit::Conformer *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::Conformer *_o0;
	_i0->setId(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Conformer::unsigned int getNumAtoms();) */
extern "C" void shim_138(void **in_ref, void **out_ref, const char *context) {
    RDKit::Conformer *_i0 = reinterpret_cast<RDKit::Conformer *>(in_ref[0]);
    RDKit::Conformer *_o0;
	_i0->getNumAtoms();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Conformer::bool is3D();) */
extern "C" void shim_139(void **in_ref, void **out_ref, const char *context) {
    RDKit::Conformer *_i0 = reinterpret_cast<RDKit::Conformer *>(in_ref[0]);
    RDKit::Conformer *_o0;
	_i0->is3D();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Conformer::void set3D(bool v);) */
extern "C" void shim_140(void **in_ref, void **out_ref, const char *context) {
    RDKit::Conformer *_i0 = reinterpret_cast<RDKit::Conformer *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    RDKit::Conformer *_o0;
	_i0->set3D(_a0);
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDKit::Conformer::~RDKit::Conformer();) */
extern "C" void shim_141(void **in_ref, void **out_ref, const char *context) {
    RDKit::Conformer *_i0 = reinterpret_cast<RDKit::Conformer *>(in_ref[0]);
	delete _i0;
	
	                
}


/* CPPScope(name=(auto) RDGeom::Point3D::RDGeom::Point3D();) */
extern "C" void shim_142(void **in_ref, void **out_ref, const char *context) {
    RDGeom::Point3D *_o0;
	_o0 = new RDGeom::Point3D();
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDGeom::Point3D::RDGeom::Point3D(const RDGeom::Point3D & other);) */
extern "C" void shim_143(void **in_ref, void **out_ref, const char *context) {
    RDGeom::Point3D *_i0 = reinterpret_cast<RDGeom::Point3D *>(in_ref[0]);
    RDGeom::Point3D *_o0;
    RDGeom::Point3D *_o1;
	_o0 = new RDGeom::Point3D(*_i0);
	_o1 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) RDGeom::Point3D::unsigned int dimension();) */
extern "C" void shim_144(void **in_ref, void **out_ref, const char *context) {
    RDGeom::Point3D *_i0 = reinterpret_cast<RDGeom::Point3D *>(in_ref[0]);
    RDGeom::Point3D *_o0;
	_i0->dimension();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDGeom::Point3D::void normalize();) */
extern "C" void shim_145(void **in_ref, void **out_ref, const char *context) {
    RDGeom::Point3D *_i0 = reinterpret_cast<RDGeom::Point3D *>(in_ref[0]);
    RDGeom::Point3D *_o0;
	_i0->normalize();
	_o0 = _i0;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) RDGeom::Point3D::~RDGeom::Point3D();) */
extern "C" void shim_146(void **in_ref, void **out_ref, const char *context) {
    RDGeom::Point3D *_i0 = reinterpret_cast<RDGeom::Point3D *>(in_ref[0]);
	delete _i0;
	
	                
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::void resize(unsigned int size);) */
extern "C" void shim_147(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Conformer *)_i0->active)->resize(_a0);
	(_o0->active) = ((RDKit::Conformer *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::void reserve(unsigned int size);) */
extern "C" void shim_148(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Conformer *)_i0->active)->reserve(_a0);
	(_o0->active) = ((RDKit::Conformer *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::bool hasOwningMol();) */
extern "C" void shim_149(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Conformer *)_i0->active)->hasOwningMol();
	(_o0->active) = ((RDKit::Conformer *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::void getAtomPos(unsigned int atomId);) */
extern "C" void shim_150(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Conformer *)_i0->active)->getAtomPos(_a0);
	(_o0->active) = ((RDKit::Conformer *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::void setAtomPos(unsigned int atomId, const RDGeom::Point3D & position);) */
extern "C" void shim_151(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    RDGeom::Point3D *_i1 = reinterpret_cast<RDGeom::Point3D *>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    RDGeom::Point3D *_o1;
	((RDKit::Conformer *)_i0->active)->setAtomPos(_a0, *_i1);
	(_o0->active) = ((RDKit::Conformer *)_i0->active);
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::unsigned int getId();) */
extern "C" void shim_152(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Conformer *)_i0->active)->getId();
	(_o0->active) = ((RDKit::Conformer *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::void setId(unsigned int id);) */
extern "C" void shim_153(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Conformer *)_i0->active)->setId(_a0);
	(_o0->active) = ((RDKit::Conformer *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::unsigned int getNumAtoms();) */
extern "C" void shim_154(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Conformer *)_i0->active)->getNumAtoms();
	(_o0->active) = ((RDKit::Conformer *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::bool is3D();) */
extern "C" void shim_155(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Conformer *)_i0->active)->is3D();
	(_o0->active) = ((RDKit::Conformer *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Conformer::void set3D(bool v);) */
extern "C" void shim_156(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Conformer *)_i0->active)->set3D(_a0);
	(_o0->active) = ((RDKit::Conformer *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::ROMol::void clearBondBookmark(int mark, const RDKit::Bond * bond);) */
extern "C" void shim_157(void **in_ref, void **out_ref, const char *context) {
    RDKit::ROMol *_i0 = reinterpret_cast<RDKit::ROMol *>(in_ref[0]);
    GFUZZ_BUNDLE *_i1 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    RDKit::ROMol *_o0;
    GFUZZ_BUNDLE *_o1 = (GFUZZ_BUNDLE *)in_ref[1];
	_i0->clearBondBookmark(_a0, ((RDKit::Bond *)_i1->active));
	_o0 = _i0;
	(_o1->active) = ((RDKit::Bond *)_i1->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_add_bond_copy) */
extern "C" void shim_158(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    GFUZZ_BUNDLE *_i1 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[1]);
    RDKit::RWMol *_o0;
    GFUZZ_BUNDLE *_o1 = (GFUZZ_BUNDLE *)in_ref[1];
	_i0->addBond(((RDKit::Bond *)_i1->active), false);
	_o0 = _i0;
	(_o1->active) = ((RDKit::Bond *)_i1->active);
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) RDKit::RWMol::void replaceBond(unsigned int idx, RDKit::Bond * bond, bool preserveProps);) */
extern "C" void shim_159(void **in_ref, void **out_ref, const char *context) {
    RDKit::RWMol *_i0 = reinterpret_cast<RDKit::RWMol *>(in_ref[0]);
    GFUZZ_BUNDLE *_i1 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[1]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    bool _a1 = *(static_cast<const char *>(context + 4)) & 1;
    RDKit::RWMol *_o0;
    GFUZZ_BUNDLE *_o1 = (GFUZZ_BUNDLE *)in_ref[1];
	_i0->replaceBond(_a0, ((RDKit::Bond *)_i1->active), _a1);
	_o0 = _i0;
	(_o1->active) = ((RDKit::Bond *)_i1->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::RDKit::Bond::BondType getBondType();) */
extern "C" void shim_160(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->getBondType();
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setBondType(RDKit::Bond::BondType bT);) */
extern "C" void shim_161(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    RDKit::Bond::BondType _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 22) {
        case 0: _a0 = RDKit::Bond::BondType::UNSPECIFIED; break;
        case 1: _a0 = RDKit::Bond::BondType::SINGLE; break;
        case 2: _a0 = RDKit::Bond::BondType::DOUBLE; break;
        case 3: _a0 = RDKit::Bond::BondType::TRIPLE; break;
        case 4: _a0 = RDKit::Bond::BondType::QUADRUPLE; break;
        case 5: _a0 = RDKit::Bond::BondType::QUINTUPLE; break;
        case 6: _a0 = RDKit::Bond::BondType::HEXTUPLE; break;
        case 7: _a0 = RDKit::Bond::BondType::ONEANDAHALF; break;
        case 8: _a0 = RDKit::Bond::BondType::TWOANDAHALF; break;
        case 9: _a0 = RDKit::Bond::BondType::THREEANDAHALF; break;
        case 10: _a0 = RDKit::Bond::BondType::FOURANDAHALF; break;
        case 11: _a0 = RDKit::Bond::BondType::FIVEANDAHALF; break;
        case 12: _a0 = RDKit::Bond::BondType::AROMATIC; break;
        case 13: _a0 = RDKit::Bond::BondType::IONIC; break;
        case 14: _a0 = RDKit::Bond::BondType::HYDROGEN; break;
        case 15: _a0 = RDKit::Bond::BondType::THREECENTER; break;
        case 16: _a0 = RDKit::Bond::BondType::DATIVEONE; break;
        case 17: _a0 = RDKit::Bond::BondType::DATIVE; break;
        case 18: _a0 = RDKit::Bond::BondType::DATIVEL; break;
        case 19: _a0 = RDKit::Bond::BondType::DATIVER; break;
        case 20: _a0 = RDKit::Bond::BondType::OTHER; break;
        case 21: _a0 = RDKit::Bond::BondType::ZERO; break;
    }
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->setBondType(_a0);
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setIsAromatic(bool what);) */
extern "C" void shim_162(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->setIsAromatic(_a0);
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::bool getIsAromatic();) */
extern "C" void shim_163(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->getIsAromatic();
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setIsConjugated(bool what);) */
extern "C" void shim_164(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->setIsConjugated(_a0);
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::bool getIsConjugated();) */
extern "C" void shim_165(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->getIsConjugated();
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::bool hasOwningMol();) */
extern "C" void shim_166(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->hasOwningMol();
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void getOwningMol();) */
extern "C" void shim_167(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->getOwningMol();
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::unsigned int getIdx();) */
extern "C" void shim_168(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->getIdx();
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setIdx(unsigned int index);) */
extern "C" void shim_169(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->setIdx(_a0);
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::unsigned int getBeginAtomIdx();) */
extern "C" void shim_170(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->getBeginAtomIdx();
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::unsigned int getEndAtomIdx();) */
extern "C" void shim_171(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->getEndAtomIdx();
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::unsigned int getOtherAtomIdx(unsigned int thisIdx);) */
extern "C" void shim_172(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->getOtherAtomIdx(_a0);
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setBeginAtomIdx(unsigned int what);) */
extern "C" void shim_173(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->setBeginAtomIdx(_a0);
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setEndAtomIdx(unsigned int what);) */
extern "C" void shim_174(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->setEndAtomIdx(_a0);
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setBeginAtom(RDKit::Atom * at);) */
extern "C" void shim_175(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    RDKit::Atom *_i1 = reinterpret_cast<RDKit::Atom *>(in_ref[1]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    RDKit::Atom *_o1;
	((RDKit::Bond *)_i0->active)->setBeginAtom(_i1);
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setEndAtom(RDKit::Atom * at);) */
extern "C" void shim_176(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    RDKit::Atom *_i1 = reinterpret_cast<RDKit::Atom *>(in_ref[1]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
    RDKit::Atom *_o1;
	((RDKit::Bond *)_i0->active)->setEndAtom(_i1);
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	_o1 = _i1;
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::bool hasQuery();) */
extern "C" void shim_177(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->hasQuery();
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setBondDir(RDKit::Bond::BondDir what);) */
extern "C" void shim_178(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    RDKit::Bond::BondDir _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 7) {
        case 0: _a0 = RDKit::Bond::BondDir::NONE; break;
        case 1: _a0 = RDKit::Bond::BondDir::BEGINWEDGE; break;
        case 2: _a0 = RDKit::Bond::BondDir::BEGINDASH; break;
        case 3: _a0 = RDKit::Bond::BondDir::ENDDOWNRIGHT; break;
        case 4: _a0 = RDKit::Bond::BondDir::ENDUPRIGHT; break;
        case 5: _a0 = RDKit::Bond::BondDir::EITHERDOUBLE; break;
        case 6: _a0 = RDKit::Bond::BondDir::UNKNOWN; break;
    }
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->setBondDir(_a0);
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::RDKit::Bond::BondDir getBondDir();) */
extern "C" void shim_179(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->getBondDir();
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setStereo(RDKit::Bond::BondStereo what);) */
extern "C" void shim_180(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    RDKit::Bond::BondStereo _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 6) {
        case 0: _a0 = RDKit::Bond::BondStereo::STEREONONE; break;
        case 1: _a0 = RDKit::Bond::BondStereo::STEREOANY; break;
        case 2: _a0 = RDKit::Bond::BondStereo::STEREOZ; break;
        case 3: _a0 = RDKit::Bond::BondStereo::STEREOE; break;
        case 4: _a0 = RDKit::Bond::BondStereo::STEREOCIS; break;
        case 5: _a0 = RDKit::Bond::BondStereo::STEREOTRANS; break;
    }
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->setStereo(_a0);
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::RDKit::Bond::BondStereo getStereo();) */
extern "C" void shim_181(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->getStereo();
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void setStereoAtoms(unsigned int bgnIdx, unsigned int endIdx);) */
extern "C" void shim_182(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->setStereoAtoms(_a0, _a1);
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=bundled_(auto) RDKit::Bond::void updatePropertyCache(bool strict);) */
extern "C" void shim_183(void **in_ref, void **out_ref, const char *context) {
    GFUZZ_BUNDLE *_i0 = reinterpret_cast<GFUZZ_BUNDLE *>(in_ref[0]);
    bool _a0 = *(static_cast<const char *>(context + 0)) & 1;
    GFUZZ_BUNDLE *_o0 = (GFUZZ_BUNDLE *)in_ref[0];
	((RDKit::Bond *)_i0->active)->updatePropertyCache(_a0);
	(_o0->active) = ((RDKit::Bond *)_i0->active);
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
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

