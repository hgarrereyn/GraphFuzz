
#include <GraphMol/Atom.h>
#include <GraphMol/Bond.h>
#include <GraphMol/ROMol.h>
#include <GraphMol/RWMol.h>


int main() {
    RDKit::Bond *bond = new RDKit::Bond();
    RDKit::ROMol *mol = new RDKit::ROMol();
    bond->setOwningMol(mol);
    delete mol;
    bond->setBeginAtomIdx(0);
}
