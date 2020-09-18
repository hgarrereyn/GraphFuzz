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
    RDKit::RWMol *var_0;
    { // begin shim_0
        var_0 = new RDKit::RWMol();
    } // end shim_0
    RDKit::RWMol *var_1;
    { // begin shim_9
        var_0->beginBatchEdit();
        var_1 = var_0;
    } // end shim_9
    RDKit::RWMol *var_2;
    { // begin shim_2
        var_1->addAtom(true);
        var_2 = var_1;
    } // end shim_2
    RDKit::RWMol *var_3;
    { // begin shim_11
        var_2->commitBatchEdit();
        var_3 = var_2;
    } // end shim_11
    { // begin shim_1
        delete var_3;
    } // end shim_1
}
