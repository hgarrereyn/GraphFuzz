#include <Geometry/point.h>
#include <GraphMol/Conformer.h>

int main() {
    RDKit::Conformer *conf = new RDKit::Conformer();
    RDGeom::Point3D *point = new RDGeom::Point3D();
    conf->setAtomPos(0xffffffff, *point);
}
