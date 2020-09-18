
#include "include/core/SkRect.h"
#include "include/core/SkPoint.h"
#include "include/private/SkTemplates.h"
#include "src/utils/SkPolyUtils.h"

#define MAX_COUNT 512

class PolyTester {
public:
    PolyTester(int _count, SkScalar coords[MAX_COUNT * 2], uint16_t _indexMap[MAX_COUNT]) {
        count = _count % MAX_COUNT;
        ptr = (SkPoint *)calloc(count, sizeof(SkPoint));
        indexMap = (uint16_t *)calloc(count, sizeof(uint16_t));
        for (int i = 0; i < count; ++i) {
            ptr[i].fX = coords[i*2];
            ptr[i].fY = coords[(i*2)+1];
            indexMap[i] = _indexMap[i];
        }
    };

    ~PolyTester() {
        free(ptr);
        free(indexMap);
    }

    void test_SkGetPolygonWinding() {
        SkGetPolygonWinding(ptr, count);
    }

    void test_SkIsConvexPolygon() {
        SkIsConvexPolygon(ptr, count);
    }

    void test_SkIsSimplePolygon() {
        SkIsSimplePolygon(ptr, count);
    }

    void test_SkInsetConvexPolygon(SkScalar inset) {
        SkTDArray<SkPoint> output;
        SkInsetConvexPolygon(ptr, count, inset, &output);
    }

    void test_SkOffsetSimplePolygon(SkScalar offset) {
        SkRect bounds;
        bounds.setBoundsCheck(ptr, count);

        SkTDArray<SkPoint> output;
        SkOffsetSimplePolygon(ptr, count, bounds, offset, &output);
    }

    void test_SkTriangulateSimplePolygon() {
        SkTDArray<uint16_t> outputIndices;
        SkTriangulateSimplePolygon(ptr, indexMap, count, &outputIndices);
    }

private:
    SkPoint *ptr;
    uint16_t *indexMap;
    int count;
};
