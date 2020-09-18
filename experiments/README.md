
# GraphFuzz Experiments

All images are built on the `graphfuzz_base` image described in `./base/Dockerfile`.

Run `./build base` to build the base image then `./build xyz` to build experiment `xyz` (see list below). The resulting image will be tagged `graphfuzz_xyz`.

Once built, invoke `docker run` manually, or use the helper `run` script to start an interactive shell. I.e. with `./run xyz`. 

For example, to build and run the Skia experiment from scratch, run:
```
./build base
./build skia
./run skia
```

## Open Source Targets

- skia
- rdkit

## Examples

- asdf
