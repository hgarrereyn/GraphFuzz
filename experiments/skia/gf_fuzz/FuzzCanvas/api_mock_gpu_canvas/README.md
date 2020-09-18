
I found it difficult to link to the correct gpu dependencies outside of the Skia build system.

To build this harness, we need to copy some files into the Skia build tree and modify their build script.

Specifically we do the following:

1. Copy