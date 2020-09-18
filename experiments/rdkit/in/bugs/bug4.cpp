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
    RDKit::ROMol *var_0;
    { // begin shim_22
        var_0 = new RDKit::ROMol();
    } // end shim_22
    RDKit::Atom *var_1;
    { // begin shim_50
        var_1 = new RDKit::Atom();
    } // end shim_50
    RDKit::ROMol *var_2;
    RDKit::Atom *var_3;
    { // begin shim_5
        var_0->setAtomBookmark(var_1, 0);
        var_2 = var_0;
        var_3 = var_1;
    } // end shim_5
    RDKit::RWMol *var_4;
    { // begin shim_30
        var_4 = new RDKit::RWMol();
    } // end shim_30
    RDKit::RWMol *var_5;
    { // begin shim_26
        var_4->addAtom(var_3, 0, true);
        var_5 = var_4;
    } // end shim_26
    { // begin shim_31
        delete var_5;
    } // end shim_31
    RDKit::Atom *var_6;
    { // begin shim_50
        var_6 = new RDKit::Atom();
    } // end shim_50
    RDKit::ROMol *var_7;
    RDKit::Atom *var_8;
    { // begin shim_8
        var_2->clearAtomBookmark(0, var_6);
        var_7 = var_2;
        var_8 = var_6;
    } // end shim_8
    { // begin shim_24
        delete var_7;
    } // end shim_24
    { // begin shim_91
        delete var_8;
    } // end shim_91
}
