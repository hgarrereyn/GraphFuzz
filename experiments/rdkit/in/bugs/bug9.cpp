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
    { // begin shim_24
        var_0 = new RDKit::ROMol();
    } // end shim_24
    RDKit::Conformer *var_1;
    { // begin shim_128
        var_1 = new RDKit::Conformer();
    } // end shim_128
    RDKit::ROMol *var_2;
    { // begin shim_5
        var_0->addConformer(var_1, 0);
        var_2 = var_0;
    } // end shim_5
    GFUZZ_BUNDLE *var_3;
    { // begin shim_3
        RDKit::Conformer *conf = new RDKit::Conformer();
        *conf = var_2->getConformer(0);
        var_3 = BUNDLE(conf, var_2);
    } // end shim_3
    RDGeom::Point3D *var_4;
    { // begin shim_142
        var_4 = new RDGeom::Point3D();
    } // end shim_142
    GFUZZ_BUNDLE *var_5;
    RDGeom::Point3D *var_6;
    { // begin shim_151
        ((RDKit::Conformer *)var_3->active)->setAtomPos(-1, *var_4);
        var_5 = ((RDKit::Conformer *)var_3->active);
        var_6 = var_4;
    } // end shim_151
    GFUZZ_BUNDLE *var_7;
    RDGeom::Point3D *var_8;
    { // begin shim_151
        ((RDKit::Conformer *)var_5->active)->setAtomPos(0, *var_6);
        var_7 = ((RDKit::Conformer *)var_5->active);
        var_8 = var_6;
    } // end shim_151
    { // begin shim_146
        delete var_8;
    } // end shim_146
    RDKit::ROMol *var_9;
    { // begin shim_4
        var_9 = (RDKit::ROMol *)var_7->inactive;
        delete var_7;
    } // end shim_4
    { // begin shim_26
        delete var_9;
    } // end shim_26
}
