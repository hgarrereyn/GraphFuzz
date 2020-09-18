#include <GraphMol/Atom.h>
#include <GraphMol/Bond.h>
#include <GraphMol/ROMol.h>
#include <GraphMol/RWMol.h>


void foo(RDKit::Atom *atom) {
    RDKit::RWMol mol;
    mol.addAtom(atom, false, true);
    // mol destructor is called
}

int main() {
    RDKit::ROMol mol;
    RDKit::Atom *atom = new RDKit::Atom();
    mol.setAtomBookmark(atom, 0);

    foo(atom);

    RDKit::Atom *atom2 = new RDKit::Atom();
    mol.clearAtomBookmark(0, atom2);
}
