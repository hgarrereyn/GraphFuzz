
#include <GraphMol/RDKitBase.h>
#include <GraphMol/SmilesParse/SmilesParse.h>
#include <GraphMol/SmilesParse/SmilesWrite.h>
#include <GraphMol/ChemTransforms/ChemTransforms.h>
#include <GraphMol/FileParsers/FileParsers.h>
#include <GraphMol/FileParsers/MolSupplier.h>
#include <GraphMol/Substruct/SubstructMatch.h>

int main() {
    RDKit::RWMol *ptr = RDKit::SmilesToMol("C[C@H](F)c1ccc(C#N)cc1");
    std::cout << ptr->getNumAtoms() << std::endl;
}
