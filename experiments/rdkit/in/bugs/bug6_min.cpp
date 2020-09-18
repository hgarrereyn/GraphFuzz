#include <GraphMol/Bond.h>
#include <GraphMol/RWMol.h>

int main() {
    RDKit::RWMol *mol = new RDKit::RWMol();
    RDKit::Atom *atom = new RDKit::Atom();
    mol->addAtom(atom, true, true);
    RDKit::Bond *bond = mol->createPartialBond(0, RDKit::Bond::BondType::SINGLE);
    delete mol;
    bond->setEndAtomIdx(1);
}
