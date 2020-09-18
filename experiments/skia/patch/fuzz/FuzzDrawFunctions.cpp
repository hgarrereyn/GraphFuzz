/*
 * Copyright 2016 Mozilla Foundation
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
#include "include/core/SkBitmap.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkFont.h"
#include "include/core/SkImage.h"
#include "include/core/SkPath.h"
#include "include/core/SkSurface.h"
#include "include/core/SkTextBlob.h"
#include "include/core/SkTypeface.h"
#include "src/core/SkClipOpPriv.h"
#include "src/core/SkPaintPriv.h"

static const int kBmpSize = 24;
static const int kMaxX = 250;
static const int kMaxY = 250;
static const int kPtsLen = 10;
static const int kTxtLen = 5;

static void init_string(Fuzz* fuzz, char* str, size_t bufSize) {
    for (size_t i = 0; i < bufSize-1; ++i) {
        fuzz->nextRange(&str[i], 0x20, 0x7E); // printable ASCII
    }
    str[bufSize-1] = '\0';
}

// make_paint mostly borrowed from FilterFuzz.cpp
static void init_paint(Fuzz* fuzz, SkPaint* p) {
    bool b;
    fuzz->next(&b);
    FUZZ_ENDPOINT(p->setAntiAlias(b);)

    uint8_t tmp_u8;
    fuzz->nextRange(&tmp_u8, 0, (int)SkBlendMode::kLastMode);
    FUZZ_ENDPOINT(p->setBlendMode(static_cast<SkBlendMode>(tmp_u8));)

    SkColor co;
    fuzz->next(&co);
    FUZZ_ENDPOINT(p->setColor(co);)

    fuzz->next(&b);
    FUZZ_ENDPOINT(p->setDither(b);)

    fuzz->nextRange(&tmp_u8, 0, (int)SkPaint::kLast_Cap);
    FUZZ_ENDPOINT(p->setStrokeCap(static_cast<SkPaint::Cap>(tmp_u8));)

    fuzz->nextRange(&tmp_u8, 0, (int)SkPaint::kLast_Join);
    FUZZ_ENDPOINT(p->setStrokeJoin(static_cast<SkPaint::Join>(tmp_u8));)

    SkScalar sc;
    fuzz->next(&sc);
    FUZZ_ENDPOINT(p->setStrokeMiter(sc);)

    fuzz->next(&sc);
    FUZZ_ENDPOINT(p->setStrokeWidth(sc);)

    fuzz->nextRange(&tmp_u8, 0, (int)SkPaint::kStrokeAndFill_Style);
    FUZZ_ENDPOINT(p->setStyle(static_cast<SkPaint::Style>(tmp_u8));)
}

static void init_bitmap(Fuzz* fuzz, SkBitmap* bmp) {
    uint8_t colorType;
    fuzz->nextRange(&colorType, 0, (int)kLastEnum_SkColorType);
    // ColorType needs to match what the system configuration is.
    if (colorType == kRGBA_8888_SkColorType || colorType == kBGRA_8888_SkColorType) {
        colorType = kN32_SkColorType;
    }
    bool b;
    fuzz->next(&b);
    FUZZ_ENDPOINT(SkImageInfo info = SkImageInfo::Make(kBmpSize,
                                         kBmpSize,
                                         (SkColorType)colorType,
                                         b ? kOpaque_SkAlphaType : kPremul_SkAlphaType);)
    FUZZ_ENDPOINT(if (!bmp->tryAllocPixels(info)) {
        SkDEBUGF("Bitmap not allocated\n");
    })
    SkColor c;
    fuzz->next(&c);
    FUZZ_ENDPOINT(bmp->eraseColor(c);)

    fuzz->next(&b);
    SkPaint p;
    if (b) {
        init_paint(fuzz, &p);
    }
    else {
        fuzz->next(&c);
        FUZZ_ENDPOINT(p.setColor(c);)
    }
}

static void init_surface(Fuzz* fuzz, sk_sp<SkSurface>* s) {
    uint8_t x, y;
    fuzz->nextRange(&x, 1, kMaxX);
    fuzz->nextRange(&y, 1, kMaxY);
    FUZZ_ENDPOINT(*s = SkSurface::MakeRasterN32Premul(x, y);

    if (!*s) {
        // Was possibly too big for the memory constrained fuzzing environments
        *s = SkSurface::MakeNull(x, y);
    })
}


static void fuzz_drawText(Fuzz* fuzz, sk_sp<SkTypeface> typeface) {
    SkFont font(typeface);
    SkPaint p;
    init_paint(fuzz, &p);
    sk_sp<SkSurface> surface;
    init_surface(fuzz, &surface);

    char text[kTxtLen];
    init_string(fuzz, text, kTxtLen);

    SkScalar x, y;
    fuzz->next(&x, &y);
    // populate pts array
    SkPoint pts[kPtsLen];
    for (uint8_t i = 0; i < kPtsLen; ++i) {
        pts[i].set(x, y);
        x += font.getSize();
    }

    bool b;
    fuzz->next(&b);
    FUZZ_ENDPOINT(font.setForceAutoHinting(b);)
    fuzz->next(&b);
    FUZZ_ENDPOINT(font.setEmbeddedBitmaps(b);)
    fuzz->next(&b);
    FUZZ_ENDPOINT(font.setEmbolden(b);)
    fuzz->next(&b);
    FUZZ_ENDPOINT(font.setEdging(b ? SkFont::Edging::kAntiAlias : SkFont::Edging::kSubpixelAntiAlias);)
    fuzz->next(&b);
    FUZZ_ENDPOINT(font.setLinearMetrics(b);)
    fuzz->next(&b);
    FUZZ_ENDPOINT(font.setSubpixel(b);)
    fuzz->next(&x);
    FUZZ_ENDPOINT(font.setScaleX(x);)
    fuzz->next(&x);
    FUZZ_ENDPOINT(font.setSkewX(x);)
    fuzz->next(&x);
    FUZZ_ENDPOINT(font.setSize(x);)

    FUZZ_ENDPOINT(SkCanvas* cnv = surface->getCanvas();)
    fuzz->next(&x);
    fuzz->next(&y);
    FUZZ_ENDPOINT(cnv->drawTextBlob(SkTextBlob::MakeFromPosText(text, kTxtLen-1, pts, font), x, y, p);)
}

static void fuzz_drawCircle(Fuzz* fuzz) {
    SkPaint p;
    init_paint(fuzz, &p);
    sk_sp<SkSurface> surface;
    init_surface(fuzz, &surface);

    SkScalar a, b, c;
    fuzz->next(&a, &b, &c);
    FUZZ_ENDPOINT(surface->getCanvas()->drawCircle(a, b, c, p);)
}

static void fuzz_drawLine(Fuzz* fuzz) {
    SkPaint p;
    init_paint(fuzz, &p);
    sk_sp<SkSurface> surface;
    init_surface(fuzz, &surface);

    SkScalar a, b, c, d;
    fuzz->next(&a, &b, &c, &d);
    FUZZ_ENDPOINT(surface->getCanvas()->drawLine(a, b, c, d, p);)
}

static void fuzz_drawRect(Fuzz* fuzz) {
    SkPaint p;
    init_paint(fuzz, &p);
    sk_sp<SkSurface> surface;
    init_surface(fuzz, &surface);

    SkScalar a, b, c, d;
    fuzz->next(&a, &b, &c, &d);
    SkRect r;
    FUZZ_ENDPOINT(r = SkRect::MakeXYWH(a, b, c, d);)

    FUZZ_ENDPOINT(SkCanvas* cnv = surface->getCanvas();
    cnv->drawRect(r, p);)

    bool bl;
    fuzz->next(&bl);
    fuzz->next(&a, &b, &c, &d);
    FUZZ_ENDPOINT(r = SkRect::MakeXYWH(a, b, c, d);
    cnv->clipRect(r, kIntersect_SkClipOp, bl);)
}

static void fuzz_drawPath(Fuzz* fuzz) {
    SkPaint p;
    init_paint(fuzz, &p);
    sk_sp<SkSurface> surface;
    init_surface(fuzz, &surface);

    // TODO(kjlubick): put the ability to fuzz a path in shared file, with
    // other common things (e.g. rects, lines)
    uint8_t i, j;
    fuzz->nextRange(&i, 0, 10); // set i to number of operations to perform
    SkPath path;
    SkScalar a, b, c, d, e, f;
    for (int k = 0; k < i; ++k) {
        fuzz->nextRange(&j, 0, 5); // set j to choose operation to perform
        switch (j) {
            case 0:
                fuzz->next(&a, &b);
                FUZZ_ENDPOINT(path.moveTo(a, b);)
                break;
            case 1:
                fuzz->next(&a, &b);
                FUZZ_ENDPOINT(path.lineTo(a, b);)
                break;
            case 2:
                fuzz->next(&a, &b, &c, &d);
                FUZZ_ENDPOINT(path.quadTo(a, b, c, d);)
                break;
            case 3:
                fuzz->next(&a, &b, &c, &d, &e);
                FUZZ_ENDPOINT(path.conicTo(a, b, c, d, e);)
                break;
            case 4:
                fuzz->next(&a, &b, &c, &d, &e, &f);
                FUZZ_ENDPOINT(path.cubicTo(a, b, c, d, e, f);)
                break;
            case 5:
                fuzz->next(&a, &b, &c, &d, &e);
                FUZZ_ENDPOINT(path.arcTo(a, b, c, d, e);)
                break;
        }
    }
    path.close();

    FUZZ_ENDPOINT(SkCanvas* cnv = surface->getCanvas();
    cnv->drawPath(path, p);)

    bool bl;
    fuzz->next(&bl);
    FUZZ_ENDPOINT(cnv->clipPath(path, kIntersect_SkClipOp, bl);)
}

static void fuzz_drawImage(Fuzz* fuzz) {
    SkPaint p;
    init_paint(fuzz, &p);
    sk_sp<SkSurface> surface;
    init_surface(fuzz, &surface);
    SkBitmap bmp;
    init_bitmap(fuzz, &bmp);

    FUZZ_ENDPOINT(sk_sp<SkImage> image(bmp.asImage());)

    bool bl;
    fuzz->next(&bl);
    SkScalar a, b;
    fuzz->next(&a, &b);
    if (bl) {
        FUZZ_ENDPOINT(surface->getCanvas()->drawImage(image, a, b, SkSamplingOptions(), &p);)
    }
    else {
        FUZZ_ENDPOINT(SkRect dst = SkRect::MakeWH(a, b);)
        fuzz->next(&a, &b);
        FUZZ_ENDPOINT(SkRect src = SkRect::MakeWH(a, b);)
        uint8_t x;
        fuzz->nextRange(&x, 0, 1);
        FUZZ_ENDPOINT(SkCanvas::SrcRectConstraint cst = (SkCanvas::SrcRectConstraint)x;
        surface->getCanvas()->drawImageRect(image.get(), src, dst, SkSamplingOptions(), &p, cst);)
    }
}

static void fuzz_drawPaint(Fuzz* fuzz) {
    SkPaint l, p;
    init_paint(fuzz, &p);
    sk_sp<SkSurface> surface;
    init_surface(fuzz, &surface);

    FUZZ_ENDPOINT(surface->getCanvas()->drawPaint(p);)
}

DEF_FUZZ(DrawFunctions, fuzz) {
    uint8_t i;
    fuzz->next(&i);

    switch(i) {
        case 0: {
            FUZZ_ENDPOINT(sk_sp<SkTypeface> f = SkTypeface::MakeDefault();
            if (f == nullptr) {
              SkDebugf("Could not initialize font.\n");
              fuzz->signalBug();
            })
            SkDEBUGF("Fuzz DrawText\n");
            FUZZ_ENDPOINT(fuzz_drawText(fuzz, f);)
            return;
        }
        case 1:
            SkDEBUGF("Fuzz DrawRect\n");
            fuzz_drawRect(fuzz);
            return;
        case 2:
            SkDEBUGF("Fuzz DrawCircle\n");
            fuzz_drawCircle(fuzz);
            return;
        case 3:
            SkDEBUGF("Fuzz DrawLine\n");
            fuzz_drawLine(fuzz);
            return;
        case 4:
            SkDEBUGF("Fuzz DrawPath\n");
            fuzz_drawPath(fuzz);
            return;
        case 5:
            SkDEBUGF("Fuzz DrawImage/DrawImageRect\n");
            fuzz_drawImage(fuzz);
            return;
        case 6:
            SkDEBUGF("Fuzz DrawPaint\n");
            fuzz_drawPaint(fuzz);
            return;
    }
}
