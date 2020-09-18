
#pragma once

typedef int point_coord;

enum PointType {
    POINT_SMALL,
    POINT_LARGE,
    POINT_CRASH,
};

struct Point {
public:
    PointType typ;
    point_coord x, y;

    Point(point_coord _x, point_coord _y): x(_x), y(_y) {}

    void set(PointType _typ) {
        typ = _typ;
    }

    static Point MakeZero() { 
        return Point {0,0};
    }

    void offset(point_coord _x, point_coord _y);
};
