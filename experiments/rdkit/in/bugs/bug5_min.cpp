#include <GraphMol/Atom.h>
#include <GraphMol/ROMol.h>

int main() {
    RDKit::Atom *atom = new RDKit::Atom();
    RDKit::ROMol *mol = new RDKit::ROMol();
    mol->getAtomDegree(atom);
}
