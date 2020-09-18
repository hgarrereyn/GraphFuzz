
// Modified from: skia/fuzz/FuzzSkParagraph.h

#include "modules/skparagraph/include/ParagraphBuilder.h"
#include "modules/skparagraph/include/TypefaceFontProvider.h"
#include "include/core/SkTypeface.h"
#include "src/core/SkOSFile.h"
#include "tools/Resources.h"
#include <string>

using namespace skia::textlayout;

// modified stub Fuzz class for fuzzing with context bytes
// (copied from skia/fuzz/Fuzz.[h,cpp])
class Fuzz {
private:
    const uint8_t *data;
    int size;
    int pos;
public:
    Fuzz(uint8_t *_data, int _size): data(_data), size(_size), pos(0) {}

    void nextBytes(void* n, size_t size) {
        uint8_t *p = (uint8_t *)n;
        if (size + this->pos > this->size) {
            int rem = this->size - this->pos;
            memcpy(p, this->data + this->pos, rem);
            memset(p + rem, 0, size - rem);
            this->pos += rem;
        } else {
            memcpy(p, this->data + this->pos, size);
            this->pos += size;
        }
    }

    template <typename T>
    void next(T* t) { this->nextBytes(t, sizeof(T)); }

    template <typename T, typename Min, typename Max>
    inline void nextRange(T* value, Min min, Max max) {
        // UBSAN worries if we make an enum with out of range values, even temporarily.
        using Raw = typename sk_strip_enum<T>::type;
        Raw raw;
        this->next(&raw);

        if (raw < (Raw)min) { raw = (Raw)min; }
        if (raw > (Raw)max) { raw = (Raw)max; }
        *value = (T)raw;
    }
};

class ResourceFontCollection : public FontCollection {
public:
    ResourceFontCollection(bool testOnly = false)
            : fFontsFound(false)
            , fResolvedFonts(0)
            , fResourceDir(GetResourcePath("fonts").c_str())
            , fFontProvider(sk_make_sp<TypefaceFontProvider>()) {
        std::vector<SkString> fonts;
        SkOSFile::Iter iter(fResourceDir.c_str());

        SkString path;
        while (iter.next(&path)) {
            if (path.endsWith("Roboto-Italic.ttf")) {
                fFontsFound = true;
            }
            fonts.emplace_back(path);
        }

        if (!fFontsFound) {
            // SkDebugf("Fonts not found, skipping all the tests\n");
            return;
        }
        // Only register fonts if we have to
        for (auto& font : fonts) {
            SkString file_path;
            file_path.printf("%s/%s", fResourceDir.c_str(), font.c_str());
            fFontProvider->registerTypeface(SkTypeface::MakeFromFile(file_path.c_str()));
        }

        if (testOnly) {
            this->setTestFontManager(std::move(fFontProvider));
        } else {
            this->setAssetFontManager(std::move(fFontProvider));
        }
        this->disableFontFallback();
    }

    size_t resolvedFonts() const { return fResolvedFonts; }

    // TODO: temp solution until we check in fonts
    bool fontsFound() const { return fFontsFound; }

private:
    bool fFontsFound;
    size_t fResolvedFonts;
    std::string fResourceDir;
    sk_sp<TypefaceFontProvider> fFontProvider;
};

const std::u16string COMBINING_DOWN = u"\u0316\u0317\u0318\u0319\u031c\u031d\u031e\u031f\u0320\u0324\u0325\u0326\u0329\u032a\u032b\u032c\u032d\u032e\u032f\u0330\u0331\u0332\u0333\u0339\u033a\u033b\u033c\u0345\u0347\u0348\u0349\u034d\u034e\u0353\u0354\u0355\u0356\u0359\u035a\u0323";
const std::u16string COMBINING_UP = u"\u030d\u030e\u0304\u0305\u033f\u0311\u0306\u0310\u0352\u0357\u0351\u0307\u0308\u030a\u0342\u0343\u0344\u034a\u034b\u034c\u0303\u0302\u030c\u0350\u0300\u0301\u030b\u030f\u0312\u0313\u0314\u033d\u0309\u0363\u0364\u0365\u0366\u0367\u0368\u0369\u036a\u036b\u036c\u036d\u036e\u035b\u0346\u031a";
const std::u16string COMBINING_MIDDLE = u"\u0315\u031b\u0340\u0341\u0358\u0321\u0322\u0327\u0328\u0334\u0335\u0336\u034f\u035c\u035d\u035e\u035f\u0360\u0362\u0338\u0337\u0361\u0489";

static void AddZalgoText(ParagraphBuilder* builder, char text[255], int text_length, Fuzz* fuzz) {
    std::u16string result;

    for (auto& c : std::string(text, text_length)) {
        result += c;
        uint8_t mark_count;
        fuzz->next(&mark_count);
        for (int i = 0; i < mark_count; i++) {
            uint8_t mark_type, mark_index;
            fuzz->next(&mark_type);
            fuzz->next(&mark_index);
            switch (mark_type % 3) {
                case 0:
                    result += COMBINING_UP[mark_index % COMBINING_UP.size()];
                    break;
                case 1:
                    result += COMBINING_MIDDLE[mark_index % COMBINING_MIDDLE.size()];
                    break;
                case 2:
                default:
                    result += COMBINING_DOWN[mark_index % COMBINING_DOWN.size()];
                    break;
            }
        }
    }
    builder->addText(result);
}
