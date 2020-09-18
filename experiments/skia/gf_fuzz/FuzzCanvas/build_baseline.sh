
echo "[*] Build baseline fuzzer."
/root/clang/bin/clang++ \
    /src/skia/fuzz/FuzzDrawFunctions.cpp \
    /src/skia/fuzz/oss_fuzz/FuzzDrawFunctions.cpp \
    /src/skia/fuzz/Fuzz.cpp \
    /src/skia/fuzz/FuzzCommon.cpp \
    -I /src/skia/ \
    -L /src/skia/out/asan/ -lskia \
    -Wl,-rpath,/src/skia/out/asan \
    -fsanitize=address,fuzzer \
    -o api_draw_functions

echo "[*] Build baseline fuzzer with coverage."
/root/clang/bin/clang++ \
    /src/skia/fuzz/FuzzDrawFunctions.cpp \
    /src/skia/fuzz/oss_fuzz/FuzzDrawFunctions.cpp \
    /src/skia/fuzz/Fuzz.cpp \
    /src/skia/fuzz/FuzzCommon.cpp \
    -I /src/skia/ \
    -L /src/skia/out/cov/ -lskia \
    -Wl,-rpath,/src/skia/out/cov \
    -fsanitize=address,fuzzer \
    -o api_draw_functions_cov
