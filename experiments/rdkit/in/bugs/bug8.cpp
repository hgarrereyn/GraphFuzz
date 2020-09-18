#include "<Geometry/point.h>"
#include "<GraphMol/Atom.h>"
#include "<GraphMol/Bond.h>"
#include "<GraphMol/Conformer.h>"
#include "<GraphMol/ROMol.h>"
#include "<GraphMol/RWMol.h>"


#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))

struct GFUZZ_BUNDLE {
public:
    void *active;
    void *inactive;
    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {};
};

#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)

int main() {
    RDKit::Atom *var_0;
    { // begin shim_52
        var_0 = new RDKit::Atom();
    } // end shim_52
    RDKit::RWMol *var_1;
    { // begin shim_32
        var_1 = new RDKit::RWMol();
    } // end shim_32
    RDKit::RWMol *var_2;
    { // begin shim_28
        var_1->addAtom(var_0, 1, true);
        var_2 = var_1;
    } // end shim_28
    RDKit::ROMol *var_3;
    { // begin shim_24
        var_3 = new RDKit::ROMol();
    } // end shim_24
    RDKit::RWMol *var_4;
    RDKit::Bond *var_5;
    { // begin shim_31
        var_5 = var_2->createPartialBond(0, RDKit::Bond::BondType::UNSPECIFIED);
        var_4 = var_2;
    } // end shim_31
    RDKit::ROMol *var_6;
    { // begin shim_97
        var_5->setOwningMol(*var_3);
        var_6 = var_3;
    } // end shim_97
    RDKit::RWMol *var_7;
    RDKit::Bond *var_8;
    { // begin shim_31
        var_8 = var_4->createPartialBond(0, RDKit::Bond::BondType::UNSPECIFIED);
        var_7 = var_4;
    } // end shim_31
    { // begin shim_33
        delete var_7;
    } // end shim_33
    RDKit::Bond *var_9;
    { // begin shim_115
        var_8->setEndAtomIdx(68714752);
        var_9 = var_8;
    } // end shim_115
    RDKit::ROMol *var_10;
    { // begin shim_96
        var_9->setOwningMol(var_6);
        var_10 = var_6;
    } // end shim_96
    { // begin shim_26
        delete var_10;
    } // end shim_26
}
