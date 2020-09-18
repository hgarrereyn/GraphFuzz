
#include <cstdlib>
#include <cassert>
#include <iostream>

#include "rect.h"


void Rect::fuzzFunc(int z) {
    if (z != 1337) return;

    if (this->a.typ != PointType::POINT_CRASH) return;
    if (this->b.typ != PointType::POINT_CRASH) return;

    if (this->area() != 100) return;

    if (val >= 0.7 && val < 0.8) {
        __builtin_trap();
    }
}

int Rect::area() {
    int width = abs(this->a.x - this->b.x);
    int height = abs(this->a.y - this->b.y);
    return width * height;
}
