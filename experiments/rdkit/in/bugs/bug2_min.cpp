
#include <GraphMol/RWMol.h>
#include <GraphMol/Atom.h>

#include <iostream>

#define MAKE(t) dynamic_cast<t *>(static_cast<t *>(calloc(1, sizeof(t))))

int main() {
    RDKit::RWMol * mol = new RDKit::RWMol();

    RDKit::Atom *var_1;
    var_1 = MAKE(RDKit::Atom);
    *var_1 = RDKit::Atom(1);

    std::cout << var_1->getAtomicNum() << std::endl;
    RDKit::Atom *b = var_1->copy();

    mol->addAtom(var_1, 0, 0);
    
}
