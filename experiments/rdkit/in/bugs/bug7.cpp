#include <Geometry/point.h>
#include <GraphMol/Atom.h>
#include <GraphMol/Bond.h>
#include <GraphMol/Conformer.h>
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
    { // begin shim_8
        var_0->replaceAtomBookmark(var_1, 35783448);
        var_2 = var_0;
        var_3 = var_1;
    } // end shim_8
    RDKit::ROMol *var_4;
    RDKit::Atom *var_5;
    { // begin shim_8
        var_2->replaceAtomBookmark(var_3, 248);
        var_4 = var_2;
        var_5 = var_3;
    } // end shim_8
    { // begin shim_91
        delete var_5;
    } // end shim_91
    RDKit::ROMol *var_6;
    RDKit::ROMol *var_7;
    { // begin shim_23
        var_6 = new RDKit::ROMol(*var_4, 0, 8192);
        var_7 = var_4;
    } // end shim_23
    { // begin shim_24
        delete var_7;
    } // end shim_24
    { // begin shim_24
        delete var_6;
    } // end shim_24
}
