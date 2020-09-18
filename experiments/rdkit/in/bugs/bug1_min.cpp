#include <GraphMol/RWMol.h>

int main() {
    RDKit::RWMol *mol = new RDKit::RWMol();
    mol->beginBatchEdit();
    mol->addAtom(true);
    mol->commitBatchEdit();
}
