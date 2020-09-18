#include <GraphMol/Atom.h>
#include <GraphMol/Bond.h>
#include <GraphMol/ROMol.h>
#include <GraphMol/RWMol.h>


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
    { // begin shim_50
        var_0 = new RDKit::Atom();
    } // end shim_50
    RDKit::RWMol *var_1;
    { // begin shim_30
        var_1 = new RDKit::RWMol();
    } // end shim_30
    RDKit::RWMol *var_2;
    { // begin shim_26
        var_1->addAtom(var_0, 0, true);
        var_2 = var_1;
    } // end shim_26
    RDKit::RWMol *var_3;
    RDKit::Bond *var_4;
    { // begin shim_29
        var_4 = var_2->createPartialBond(0, RDKit::Bond::BondType::DOUBLE);
        var_3 = var_2;
    } // end shim_29
    { // begin shim_31
        delete var_3;
    } // end shim_31
    RDKit::Bond *var_5;
    { // begin shim_113
        var_4->setEndAtomIdx(62976);
        var_5 = var_4;
    } // end shim_113
    { // begin shim_123
        delete var_5;
    } // end shim_123
}
