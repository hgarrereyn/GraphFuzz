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
    RDKit::Bond *var_0;
    { // begin shim_94
        var_0 = new RDKit::Bond();
    } // end shim_94
    RDKit::ROMol *var_1;
    { // begin shim_22
        var_1 = new RDKit::ROMol();
    } // end shim_22
    RDKit::Bond *var_2;
    RDKit::ROMol *var_3;
    { // begin shim_105
        var_0->setOwningMol(var_1);
        var_2 = var_0;
        var_3 = var_1;
    } // end shim_105
    { // begin shim_24
        delete var_3;
    } // end shim_24
    RDKit::Bond *var_4;
    { // begin shim_112
        var_2->setBeginAtomIdx(0);
        var_4 = var_2;
    } // end shim_112
    { // begin shim_123
        delete var_4;
    } // end shim_123
}
