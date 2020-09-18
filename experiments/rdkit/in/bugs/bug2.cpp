
#include <GraphMol/RWMol.h>
#include <GraphMol/Atom.h>


#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))

struct GFUZZ_BUNDLE {
public:
    void *active;
    void *inactive;
    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {};
};

#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)

int main() {
    RDKit::RWMol *var_0;
    { // begin shim_0
        var_0 = new RDKit::RWMol();
    } // end shim_0
    RDKit::Atom *var_1;
    { // begin shim_17
        var_1 = MAKE(RDKit::Atom);
        RDKit::Atom ref = RDKit::Atom();
        *var_1 = ref;
    } // end shim_17
    RDKit::RWMol *var_2;
    RDKit::Atom *var_3;
    { // begin shim_3
        var_0->addAtom(var_1, 0, 0);
        var_2 = var_0;
        var_3 = var_1;
    } // end shim_3
    { // begin shim_1
        delete var_2;
    } // end shim_1
    { // begin shim_48
        free(var_3);
    } // end shim_48
}
