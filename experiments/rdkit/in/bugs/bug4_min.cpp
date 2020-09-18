#include <GraphMol/Atom.h>
#include <GraphMol/RWMol.h>

int main() {
    RDKit::RWMol *mol1 = new RDKit::RWMol();
    RDKit::Atom *atom1 = new RDKit::Atom();
    mol1->setAtomBookmark(atom1, 0);

    RDKit::RWMol *mol2 = new RDKit::RWMol();
    mol2->addAtom(atom1, false, true);

    // atom1 is freed because mol2 has ownership
    delete mol2;

    RDKit::Atom *atom2 = new RDKit::Atom();

    // atom1 is used because mol1 has ownership
    mol1->clearAtomBookmark(0, atom2);
}
