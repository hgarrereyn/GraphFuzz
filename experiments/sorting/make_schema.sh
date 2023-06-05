#!/bin/bash

# Context is graphfuzz/experiments/ex_auto_cpp
pdir=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
cd "$pdir"

# Run Doxygen to extract C++ metadata:
mkdir -p ./doxygen_output
gfuzz doxygen --inputs ./in/lib --output ./doxygen_output

# Process the Doxygen XML and generate a GraphFuzz schema:
gfuzz schema infer ./doxygen_output/xml ./in/auto_schema.yaml

# Cleanup doxygen output:
rm -rf ./doxygen_output

# Generate fuzzer harnesses from the schema:
mkdir -p ./in/fuzz
gfuzz gen cpp ./in/auto_schema.yaml ./in/fuzz