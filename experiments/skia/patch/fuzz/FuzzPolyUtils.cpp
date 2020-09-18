/*
 * Copyright 2018 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifdef FUZZ_DRY
#define FUZZ_ENDPOINT(T) 0;
#else
#define FUZZ_ENDPOINT(T) T
#endif

#include "fuzz/Fuzz.h"

#include "include/private/SkTemplates.h"
#include "src/utils/SkPolyUtils.h"

void inline ignoreResult(bool ) {}

DEF_FUZZ(PolyUtils, fuzz) {
    int count;
    fuzz->nextRange(&count, 0, 512);
    SkAutoSTMalloc<64, SkPoint> polygon(count);
    for (int index = 0; index < count; ++index) {
        fuzz->next(&polygon[index].fX, &polygon[index].fY);
    }
    SkRect bounds;
    FUZZ_ENDPOINT(bounds.setBoundsCheck(polygon, count);)

    FUZZ_ENDPOINT(ignoreResult(SkGetPolygonWinding(polygon, count));
    ignoreResult(SkIsConvexPolygon(polygon, count));
    ignoreResult(SkIsSimplePolygon(polygon, count));)

    SkScalar inset;
    fuzz->next(&inset);
    SkTDArray<SkPoint> output;
    FUZZ_ENDPOINT(ignoreResult(SkInsetConvexPolygon(polygon, count, inset, &output));)

    SkScalar offset;
    fuzz->next(&offset);
    FUZZ_ENDPOINT(ignoreResult(SkOffsetSimplePolygon(polygon, count, bounds, offset, &output));)

    SkAutoSTMalloc<64, uint16_t> indexMap(count);
    for (int index = 0; index < count; ++index) {
        fuzz->next(&indexMap[index]);
    }
    SkTDArray<uint16_t> outputIndices;
    FUZZ_ENDPOINT(ignoreResult(SkTriangulateSimplePolygon(polygon, indexMap, count, &outputIndices));)
}
