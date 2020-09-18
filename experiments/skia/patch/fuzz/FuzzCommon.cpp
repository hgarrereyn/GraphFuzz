/*
 * Copyright 2018 Google Inc.
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
#include "fuzz/FuzzCommon.h"

// We don't always want to test NaNs and infinities.
static void fuzz_nice_float(Fuzz* fuzz, float* f) {
    float v;
    fuzz->next(&v);
    constexpr float kLimit = 1.0e35f;  // FLT_MAX?
    *f = (v == v && v <= kLimit && v >= -kLimit) ? v : 0.0f;
}

template <typename... Args>
static void fuzz_nice_float(Fuzz* fuzz, float* f, Args... rest) {
    fuzz_nice_float(fuzz, f);
    fuzz_nice_float(fuzz, rest...);
}

static void fuzz_nice_rect(Fuzz* fuzz, SkRect* r) {
    fuzz_nice_float(fuzz, &r->fLeft, &r->fTop, &r->fRight, &r->fBottom);
    FUZZ_ENDPOINT(r->sort();)
}

// allows some float values for path points
void FuzzNicePath(Fuzz* fuzz, SkPath* path, int maxOps) {
    if (maxOps <= 0 || fuzz->exhausted() || path->countPoints() > 100000) {
        return;
    }
    uint8_t fillType;
    fuzz->nextRange(&fillType, 0, (uint8_t)SkPathFillType::kInverseEvenOdd);
    FUZZ_ENDPOINT(path->setFillType((SkPathFillType)fillType);)
    uint8_t numOps;
    fuzz->nextRange(&numOps, 0, maxOps);
    for (uint8_t i = 0; i < numOps; ++i) {
        // When we start adding the path to itself, the fuzzer can make an
        // exponentially long path, which causes timeouts.
        if (path->countPoints() > 100000) {
            return;
        }
        // How many items in the switch statement below.
        constexpr uint8_t PATH_OPERATIONS = 32;
        uint8_t op;
        fuzz->nextRange(&op, 0, PATH_OPERATIONS);
        bool test;
        SkPath p;
        SkMatrix m;
        SkRRect rr;
        SkRect r;
        SkPathDirection dir;
        unsigned int ui;
        SkScalar a, b, c, d, e, f;
        switch (op) {
            case 0:
                fuzz_nice_float(fuzz, &a, &b);
                FUZZ_ENDPOINT(path->moveTo(a, b);)
                break;
            case 1:
                fuzz_nice_float(fuzz, &a, &b);
                FUZZ_ENDPOINT(path->rMoveTo(a, b);)
                break;
            case 2:
                fuzz_nice_float(fuzz, &a, &b);
                FUZZ_ENDPOINT(path->lineTo(a, b);)
                break;
            case 3:
                fuzz_nice_float(fuzz, &a, &b);
                FUZZ_ENDPOINT(path->rLineTo(a, b);)
                break;
            case 4:
                fuzz_nice_float(fuzz, &a, &b, &c, &d);
                FUZZ_ENDPOINT(path->quadTo(a, b, c, d);)
                break;
            case 5:
                fuzz_nice_float(fuzz, &a, &b, &c, &d);
                FUZZ_ENDPOINT(path->rQuadTo(a, b, c, d);)
                break;
            case 6:
                fuzz_nice_float(fuzz, &a, &b, &c, &d, &e);
                FUZZ_ENDPOINT(path->conicTo(a, b, c, d, e);)
                break;
            case 7:
                fuzz_nice_float(fuzz, &a, &b, &c, &d, &e);
                FUZZ_ENDPOINT(path->rConicTo(a, b, c, d, e);)
                break;
            case 8:
                fuzz_nice_float(fuzz, &a, &b, &c, &d, &e, &f);
                FUZZ_ENDPOINT(path->cubicTo(a, b, c, d, e, f);)
                break;
            case 9:
                fuzz_nice_float(fuzz, &a, &b, &c, &d, &e, &f);
                FUZZ_ENDPOINT(path->rCubicTo(a, b, c, d, e, f);)
                break;
            case 10:
                fuzz_nice_float(fuzz, &a, &b, &c, &d, &e);
                FUZZ_ENDPOINT(path->arcTo(a, b, c, d, e);)
                break;
            case 11:
                fuzz_nice_float(fuzz, &a, &b);
                fuzz_nice_rect(fuzz, &r);
                fuzz->next(&test);
                FUZZ_ENDPOINT(path->arcTo(r, a, b, test);)
                break;
            case 12:
                FUZZ_ENDPOINT(path->close();)
                break;
            case 13:
                fuzz_nice_rect(fuzz, &r);
                fuzz->nextRange(&ui, 0, 1);
                dir = static_cast<SkPathDirection>(ui);
                FUZZ_ENDPOINT(path->addRect(r, dir);)
                break;
            case 14:
                fuzz->nextRange(&ui, 0, 1);
                dir = static_cast<SkPathDirection>(ui);
                fuzz_nice_rect(fuzz, &r);
                fuzz->next(&ui);
                FUZZ_ENDPOINT(path->addRect(r, dir, ui);)
                break;
            case 15:
                fuzz->nextRange(&ui, 0, 1);
                dir = static_cast<SkPathDirection>(ui);
                fuzz_nice_rect(fuzz, &r);
                FUZZ_ENDPOINT(path->addOval(r, dir);)
                break;
            case 16:
                fuzz->nextRange(&ui, 0, 1);
                dir = static_cast<SkPathDirection>(ui);
                fuzz_nice_rect(fuzz, &r);
                fuzz->next(&ui);
                FUZZ_ENDPOINT(path->addOval(r, dir, ui);)
                break;
            case 17:
                fuzz->nextRange(&ui, 0, 1);
                dir = static_cast<SkPathDirection>(ui);
                fuzz_nice_float(fuzz, &a, &b, &c);
                FUZZ_ENDPOINT(path->addCircle(a, b, c, dir);)
                break;
            case 18:
                fuzz_nice_rect(fuzz, &r);
                fuzz_nice_float(fuzz, &a, &b);
                FUZZ_ENDPOINT(path->addArc(r, a, b);)
                break;
            case 19:
                fuzz_nice_float(fuzz, &a, &b);
                fuzz_nice_rect(fuzz, &r);
                fuzz->nextRange(&ui, 0, 1);
                dir = static_cast<SkPathDirection>(ui);
                FUZZ_ENDPOINT(path->addRoundRect(r, a, b, dir);)
                break;
            case 20:
                FuzzNiceRRect(fuzz, &rr);
                fuzz->nextRange(&ui, 0, 1);
                dir = static_cast<SkPathDirection>(ui);
                FUZZ_ENDPOINT(path->addRRect(rr, dir);)
                break;
            case 21:
                fuzz->nextRange(&ui, 0, 1);
                dir = static_cast<SkPathDirection>(ui);
                FuzzNiceRRect(fuzz, &rr);
                FUZZ_ENDPOINT(path->addRRect(rr, dir, ui);)
                break;
            case 22: {
                fuzz->nextRange(&ui, 0, 1);
                SkPath::AddPathMode mode = static_cast<SkPath::AddPathMode>(ui);
                FuzzNiceMatrix(fuzz, &m);
                FuzzNicePath(fuzz, &p, maxOps-1);
                FUZZ_ENDPOINT(path->addPath(p, m, mode);)
                break;
            }
            case 23: {
                fuzz->nextRange(&ui, 0, 1);
                SkPath::AddPathMode mode = static_cast<SkPath::AddPathMode>(ui);
                FuzzNiceMatrix(fuzz, &m);
                FUZZ_ENDPOINT(path->addPath(*path, m, mode);)
                break;
            }
            case 24:
                FuzzNicePath(fuzz, &p, maxOps-1);
                FUZZ_ENDPOINT(path->reverseAddPath(p);)
                break;
            case 25:
                FUZZ_ENDPOINT(path->addPath(*path);)
                break;
            case 26:
                FUZZ_ENDPOINT(path->reverseAddPath(*path);)
                break;
            case 27:
                fuzz_nice_float(fuzz, &a, &b);
                FUZZ_ENDPOINT(path->offset(a, b, path);)
                break;
            case 28:
                FuzzNicePath(fuzz, &p, maxOps-1);
                fuzz_nice_float(fuzz, &a, &b);
                FUZZ_ENDPOINT(p.offset(a, b, path);)
                break;
            case 29:
                FuzzNiceMatrix(fuzz, &m);
                FUZZ_ENDPOINT(path->transform(m, path);)
                break;
            case 30:
                FuzzNicePath(fuzz, &p, maxOps-1);
                FuzzNiceMatrix(fuzz, &m);
                FUZZ_ENDPOINT(p.transform(m, path);)
                break;
            case 31:
                fuzz_nice_float(fuzz, &a, &b);
                FUZZ_ENDPOINT(path->setLastPt(a, b);)
                break;

            default:
                SkASSERT(false);
                break;
        }
        FUZZ_ENDPOINT(SkASSERTF(       path->isValid(),        "path->isValid() failed at op %d, case %d", i, op);)
    }
}

// allows all float values for path points
void FuzzEvilPath(Fuzz* fuzz, SkPath* path, int last_verb) {
  while (!fuzz->exhausted()) {
    // Use a uint8_t to conserve bytes.  This makes our "fuzzed bytes footprint"
    // smaller, which leads to more efficient fuzzing.
    uint8_t operation;
    fuzz->next(&operation);
    SkScalar a,b,c,d,e,f;

    switch (operation % (last_verb + 1)) {
      case SkPath::Verb::kMove_Verb:
        fuzz->next(&a, &b);
        FUZZ_ENDPOINT(path->moveTo(a, b);)
        break;

      case SkPath::Verb::kLine_Verb:
        fuzz->next(&a, &b);
        FUZZ_ENDPOINT(path->lineTo(a, b);)
        break;

      case SkPath::Verb::kQuad_Verb:
        fuzz->next(&a, &b, &c, &d);
        FUZZ_ENDPOINT(path->quadTo(a, b, c, d);)
        break;

      case SkPath::Verb::kConic_Verb:
        fuzz->next(&a, &b, &c, &d, &e);
        FUZZ_ENDPOINT(path->conicTo(a, b, c, d, e);)
        break;

      case SkPath::Verb::kCubic_Verb:
        fuzz->next(&a, &b, &c, &d, &e, &f);
        FUZZ_ENDPOINT(path->cubicTo(a, b, c, d, e, f);)
        break;

      case SkPath::Verb::kClose_Verb:
        FUZZ_ENDPOINT(path->close();)
        break;

      case SkPath::Verb::kDone_Verb:
        // In this case, simply exit.
        return;
    }
  }
}

void FuzzNiceRRect(Fuzz* fuzz, SkRRect* rr) {
    SkRect r;
    fuzz_nice_rect(fuzz, &r);

    SkVector radii[4];
    for (SkVector& vec : radii) {
        fuzz->nextRange(&vec.fX, 0.0f, 1.0f);
        vec.fX *= 0.5f * r.width();
        fuzz->nextRange(&vec.fY, 0.0f, 1.0f);
        vec.fY *= 0.5f * r.height();
    }
    FUZZ_ENDPOINT(rr->setRectRadii(r, radii);)
    FUZZ_ENDPOINT(SkASSERT(rr->isValid());)
}

void FuzzNiceMatrix(Fuzz* fuzz, SkMatrix* m) {
    constexpr int kArrayLength = 9;
    SkScalar buffer[kArrayLength];
    int matrixType;
    fuzz->nextRange(&matrixType, 0, 4);
    switch (matrixType) {
        case 0:  // identity
            FUZZ_ENDPOINT(*m = SkMatrix::I();)
            return;
        case 1:  // translate
            fuzz->nextRange(&buffer[0], -4000.0f, 4000.0f);
            fuzz->nextRange(&buffer[1], -4000.0f, 4000.0f);
            FUZZ_ENDPOINT(*m = SkMatrix::Translate(buffer[0], buffer[1]);)
            return;
        case 2:  // translate + scale
            fuzz->nextRange(&buffer[0], -400.0f, 400.0f);
            fuzz->nextRange(&buffer[1], -400.0f, 400.0f);
            fuzz->nextRange(&buffer[2], -4000.0f, 4000.0f);
            fuzz->nextRange(&buffer[3], -4000.0f, 4000.0f);
            FUZZ_ENDPOINT(*m = SkMatrix::Scale(buffer[0], buffer[1]);)
            FUZZ_ENDPOINT(m->postTranslate(buffer[2], buffer[3]);)
            return;
        case 3:  // affine
            fuzz->nextN(buffer, 6);
            FUZZ_ENDPOINT(m->setAffine(buffer);)
            return;
        case 4:  // perspective
            fuzz->nextN(buffer, kArrayLength);
            FUZZ_ENDPOINT(m->set9(buffer);)
            return;
        default:
            SkASSERT(false);
            return;
    }
}

void FuzzNiceRegion(Fuzz* fuzz, SkRegion* region, int maxN) {
    uint8_t N;
    fuzz->nextRange(&N, 0, maxN);
    for (uint8_t i = 0; i < N; ++i) {
        SkIRect r;
        SkRegion::Op op;
        // Avoid the sentinel value used by Region.
        fuzz->nextRange(&r.fLeft,   -2147483646, 2147483646);
        fuzz->nextRange(&r.fTop,    -2147483646, 2147483646);
        fuzz->nextRange(&r.fRight,  -2147483646, 2147483646);
        fuzz->nextRange(&r.fBottom, -2147483646, 2147483646);
        FUZZ_ENDPOINT(r.sort();)
        fuzz->nextEnum(&op, SkRegion::kLastOp);
        FUZZ_ENDPOINT(if (!region->op(r, op)) {
            return;
        })
    }
}
