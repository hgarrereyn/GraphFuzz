
#pragma once

#include "point.h"

struct Rect {
private:
    Point a, b;
    float val;

public:
    Rect(): a(0,0), b(0,0) {}
    void setA(Point &p) {a = p;};
    void setB(Point &p) {b = p;};
    void setVal(float v) {val = v;};
    int area();
    void fuzzFunc(int z);
};
