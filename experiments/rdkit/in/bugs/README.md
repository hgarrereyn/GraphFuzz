# Bugs

### bug1: SEGV in RWMol::commitBatchEdit (https://github.com/rdkit/rdkit/issues/4122)

```
After certain sequences of adding/removing atoms in a RWMol in batch edit mode, RWMol::commitBatchEdit can segfault. Depending on the call sequence, this either segfaults which crashes the program or performs a heap-buffer-overflow and reads unallocated heap memory (which is only detectible with ASAN).
```

### bug4: RWMol::setAtomBookmark can retain stale pointers and lead to UAF (https://github.com/rdkit/rdkit/issues/4126)

```
Invoking RWMol::setAtomBookmark implicitly copies an Atom pointer and subsequent calls to RWMol::clearAtomBookmark can invoke methods on the Atom (i.e. to check if the index matches the query index). However, this RWMol does not take ownership of the Atom pointer since the destructor will not free the Atom. Given this API, it appears to be legal to bookmark an atom in one RWMol while it is owned by a different RWMol which can lead to memory corruption as described below.

Note that similar behavior is probably possible with Bond ownership.
```

### bug5: SEGV in ROMol::getAtomDegree if atom is not in graph (https://github.com/rdkit/rdkit/issues/4127)

```
Invoking ROMol::getAtomDegree on an Atom * that is not contained in the molecule graph can segfault.
```
