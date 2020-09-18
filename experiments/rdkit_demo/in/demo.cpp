
#include <GraphMol/RWMol.h>
#include <GraphMol/Atom.h>

#include <iostream>

int main() {
    RDKit::RWMol mol;

    RDKit::Atom a1(6);
    a1.setIsAromatic(true);

    RDKit::Atom a2(7);

    // Add atom 1 and 2 to bookmark #123
    //
    // Bookmark #123: [a1, a2]
    mol.setAtomBookmark(&a1, 123);
    mol.setAtomBookmark(&a2, 123);

    for (RDKit::Atom *a : mol.getAllAtomsWithBookmark(123)) {
        std::cout << "Num: " << a->getAtomicNum() << ", aromatic: " << a->getIsAromatic() << std::endl;
    }

    // Remove atom 1 from bookmark #123
    mol.clearAtomBookmark(123, &a1);

    // Delete bookmark #123
    mol.clearAtomBookmark(123);
}
