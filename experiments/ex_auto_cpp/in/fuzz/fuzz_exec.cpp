#include "point.h"
#include "rect.h"


#include <string.h>
#include <stdlib.h>
#include <cstdint>

extern "C" int graphfuzz_try();
extern "C" void graphfuzz_bail();

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) {

}

extern "C" void __attribute__((visibility ("default"))) shim_init() {

}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {

}


#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))

struct GFUZZ_BUNDLE {
public:
    void *active;
    void *inactive;
    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}
};

#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)



/* CPPScope(name=(auto) Point::Point(point_coord _x, point_coord _y);) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    Point *_o0;
	_o0 = MAKE(Point);
	Point ref = Point(_a0, _a1);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Point::void set(PointType _typ);) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    Point *_i0 = reinterpret_cast<Point *>(in_ref[0]);
    PointType _a0;
    switch (*(reinterpret_cast<const unsigned char *>(context + 0)) % 3) {
        case 0: _a0 = PointType::POINT_SMALL; break;
        case 1: _a0 = PointType::POINT_LARGE; break;
        case 2: _a0 = PointType::POINT_CRASH; break;
    }
    Point *_o0;
	_i0->set(_a0);
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Point::void offset(point_coord _x, point_coord _y);) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    Point *_i0 = reinterpret_cast<Point *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    Point *_o0;
	_i0->offset(_a0, _a1);
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Point::Point MakeZero();) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    Point *_o0;
	_o0 = MAKE(Point);
	Point ref = Point::MakeZero();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Point::~Point();) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    Point *_i0 = reinterpret_cast<Point *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=(auto) Rect::Rect();) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    Rect *_o0;
	_o0 = MAKE(Rect);
	Rect ref = Rect();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Rect::void setA(Point & p);) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    Rect *_i0 = reinterpret_cast<Rect *>(in_ref[0]);
    Point *_i1 = reinterpret_cast<Point *>(in_ref[1]);
    Rect *_o0;
    Point *_o1;
	_i0->setA(*_i1);
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) Rect::void setB(Point & p);) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    Rect *_i0 = reinterpret_cast<Rect *>(in_ref[0]);
    Point *_i1 = reinterpret_cast<Point *>(in_ref[1]);
    Rect *_o0;
    Point *_o1;
	_i0->setB(*_i1);
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) Rect::void setVal(float v);) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    Rect *_i0 = reinterpret_cast<Rect *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    Rect *_o0;
	_i0->setVal(_a0);
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Rect::int area();) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    Rect *_i0 = reinterpret_cast<Rect *>(in_ref[0]);
    Rect *_o0;
	_i0->area();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Rect::void fuzzFunc(int z);) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    Rect *_i0 = reinterpret_cast<Rect *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    Rect *_o0;
	_i0->fuzzFunc(_a0);
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Rect::~Rect();) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    Rect *_i0 = reinterpret_cast<Rect *>(in_ref[0]);
	free(_i0);
	
	                
}


void __attribute__((visibility ("default"))) (*FUZZER_SHIMS[])(void **, void **, const char *) = {
    &shim_0,
    &shim_1,
    &shim_2,
    &shim_3,
    &shim_4,
    &shim_5,
    &shim_6,
    &shim_7,
    &shim_8,
    &shim_9,
    &shim_10,
    &shim_11,
};

