
from rdkit.Chem import AllChem as Chem

m = Chem.RWMol()
m.BeginBatchEdit()
m.AddAtom(Chem.Atom(1))
m.CommitBatchEdit()
