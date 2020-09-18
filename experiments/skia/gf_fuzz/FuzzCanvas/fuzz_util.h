
#include "SkTypes.h"
#include "include/private/SkTFitsIn.h"
#include "include/core/SkFontTypes.h"
#include "include/private/SkTDArray.h"
#include "include/core/SkFont.h"
#include "src/utils/SkUTF.h"

#include <string>
#include <stdint.h>
#include "string.h"


typedef float SkScalar;

void fuzz_gradient_stops(SkScalar* pos, int colorCount) {
    SkScalar totalPos = 0;
    for (int i = 0; i < colorCount; ++i) {
        totalPos += pos[i];
    }
    totalPos = 1.0f / totalPos;
    for (int i = 0; i < colorCount; ++i) {
        pos[i] *= totalPos;
    }
    pos[colorCount - 1] = 1.0f;
}

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

constexpr int kMaxGlyphCount = 30;

static SkTDArray<uint8_t> make_fuzz_text(Fuzz* fuzz, const SkFont& font, SkTextEncoding encoding) {
    SkTDArray<uint8_t> array;
    if (SkTextEncoding::kGlyphID == encoding) {
        int glyphRange = font.getTypefaceOrDefault()->countGlyphs();
        if (glyphRange == 0) {
            // Some fuzzing environments have no fonts, so empty array is the best
            // we can do.
            return array;
        }
        int glyphCount;
        fuzz->nextRange(&glyphCount, 1, kMaxGlyphCount);
        SkGlyphID* glyphs = (SkGlyphID*)array.append(glyphCount * sizeof(SkGlyphID));
        for (int i = 0; i < glyphCount; ++i) {
            fuzz->nextRange(&glyphs[i], 0, glyphRange - 1);
        }
        return array;
    }
    static const SkUnichar ranges[][2] = {
        {0x0020, 0x007F},
        {0x00A1, 0x0250},
        {0x0400, 0x0500},
    };
    int32_t count = 0;
    for (size_t i = 0; i < SK_ARRAY_COUNT(ranges); ++i) {
        count += (ranges[i][1] - ranges[i][0]);
    }
    constexpr int kMaxLength = kMaxGlyphCount;
    SkUnichar buffer[kMaxLength];
    int length;
    fuzz->nextRange(&length, 1, kMaxLength);
    for (int j = 0; j < length; ++j) {
        int32_t value;
        fuzz->nextRange(&value, 0, count - 1);
        for (size_t i = 0; i < SK_ARRAY_COUNT(ranges); ++i) {
            if (value + ranges[i][0] < ranges[i][1]) {
                buffer[j] = value + ranges[i][0];
                break;
            } else {
                value -= (ranges[i][1] - ranges[i][0]);
            }
        }
    }
    switch (encoding) {
        case SkTextEncoding::kUTF8: {
            size_t utf8len = 0;
            for (int j = 0; j < length; ++j) {
                utf8len += SkUTF::ToUTF8(buffer[j], nullptr);
            }
            char* ptr = (char*)array.append(utf8len);
            for (int j = 0; j < length; ++j) {
                ptr += SkUTF::ToUTF8(buffer[j], ptr);
            }
        } break;
        case SkTextEncoding::kUTF16: {
            size_t utf16len = 0;
            for (int j = 0; j < length; ++j) {
                utf16len += SkUTF::ToUTF16(buffer[j]);
            }
            uint16_t* ptr = (uint16_t*)array.append(utf16len * sizeof(uint16_t));
            for (int j = 0; j < length; ++j) {
                ptr += SkUTF::ToUTF16(buffer[j], ptr);
            }
        } break;
        case SkTextEncoding::kUTF32:
            memcpy(array.append(length * sizeof(SkUnichar)), buffer, length * sizeof(SkUnichar));
            break;
        default:
            SkASSERT(false);
            break;
    }
    return array;
}

static std::string make_fuzz_string(Fuzz* fuzz) {
    int len;
    fuzz->nextRange(&len, 0, kMaxGlyphCount);
    std::string str(len, 0);
    for (int i = 0; i < len; i++) {
        fuzz->next(&str[i]);
    }
    return str;
}
