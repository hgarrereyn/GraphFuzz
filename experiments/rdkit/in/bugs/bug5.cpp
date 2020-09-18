#include "<GraphMol/Atom.h>"
#include "<GraphMol/Bond.h>"
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
    { // begin shim_50
        var_0 = new RDKit::Atom();
    } // end shim_50
    RDKit::ROMol *var_1;
    { // begin shim_22
        var_1 = new RDKit::ROMol();
    } // end shim_22
    RDKit::ROMol *var_2;
    RDKit::Atom *var_3;
    { // begin shim_3
        var_1->getAtomDegree(var_0);
        var_2 = var_1;
        var_3 = var_0;
    } // end shim_3
    { // begin shim_24
        delete var_2;
    } // end shim_24
    { // begin shim_91
        delete var_3;
    } // end shim_91
}
