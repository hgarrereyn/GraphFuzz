#include <Eigen/Dense>


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



/* CPPScope(name=set) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    Eigen::MatrixXf *_o0;
	_i0->operator()(_a0, _a1) = _a2;
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::Eigen::MatrixXf(int None, int None);) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    Eigen::MatrixXf *_o0;
	_o0 = MAKE(Eigen::MatrixXf);
	Eigen::MatrixXf ref = Eigen::MatrixXf(_a0, _a1);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void operator+=(Eigen::MatrixXf None);) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    Eigen::MatrixXf *_i1 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[1]);
    Eigen::MatrixXf *_o0;
    Eigen::MatrixXf *_o1;
	_i0->operator+=(*_i1);
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void operator-=(Eigen::MatrixXf None);) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    Eigen::MatrixXf *_i1 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[1]);
    Eigen::MatrixXf *_o0;
    Eigen::MatrixXf *_o1;
	_i0->operator-=(*_i1);
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void operator*=(float None);) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    Eigen::MatrixXf *_o0;
	_i0->operator*=(_a0);
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void operator*=(Eigen::MatrixXf None);) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    Eigen::MatrixXf *_i1 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[1]);
    Eigen::MatrixXf *_o0;
    Eigen::MatrixXf *_o1;
	_i0->operator*=(*_i1);
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void operator*=(Eigen::VectorXf None);) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    Eigen::VectorXf *_i1 = reinterpret_cast<Eigen::VectorXf *>(in_ref[1]);
    Eigen::MatrixXf *_o0;
    Eigen::VectorXf *_o1;
	_i0->operator*=(*_i1);
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void operator/=(float None);) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    Eigen::MatrixXf *_o0;
	_i0->operator/=(_a0);
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void resize(int None, int None);) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    Eigen::MatrixXf *_o0;
	_i0->resize(_a0, _a1);
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void transpose();) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    Eigen::MatrixXf *_o0;
	_i0->transpose();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void conjugate();) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    Eigen::MatrixXf *_o0;
	_i0->conjugate();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void adjoint();) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    Eigen::MatrixXf *_o0;
	_i0->adjoint();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void transposeInPlace();) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    Eigen::MatrixXf *_o0;
	_i0->transposeInPlace();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::float sum();) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    Eigen::MatrixXf *_o0;
	_i0->sum();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::float prod();) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    Eigen::MatrixXf *_o0;
	_i0->prod();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::float mean();) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    Eigen::MatrixXf *_o0;
	_i0->mean();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::float minCoeff();) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    Eigen::MatrixXf *_o0;
	_i0->minCoeff();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::float maxCoeff();) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    Eigen::MatrixXf *_o0;
	_i0->maxCoeff();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::float trace();) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
    Eigen::MatrixXf *_o0;
	_i0->trace();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::Eigen::MatrixXf Eigen::Matrix2f();) */
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_o0;
	_o0 = MAKE(Eigen::MatrixXf);
	Eigen::MatrixXf ref = Eigen::Matrix2f();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::Eigen::MatrixXf Eigen::Matrix3f();) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_o0;
	_o0 = MAKE(Eigen::MatrixXf);
	Eigen::MatrixXf ref = Eigen::Matrix3f();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::Eigen::MatrixXf Eigen::Matrix4f();) */
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_o0;
	_o0 = MAKE(Eigen::MatrixXf);
	Eigen::MatrixXf ref = Eigen::Matrix4f();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::MatrixXf::~Eigen::MatrixXf();) */
extern "C" void shim_22(void **in_ref, void **out_ref, const char *context) {
    Eigen::MatrixXf *_i0 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[0]);
	free(_i0);
	
	                
}


/* CPPScope(name=set) */
extern "C" void shim_23(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_i0 = reinterpret_cast<Eigen::VectorXf *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    Eigen::VectorXf *_o0;
	_i0->operator()(_a0) = _a1;
	_o0 = _i0;
	
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::VectorXf::Eigen::VectorXf(int None);) */
extern "C" void shim_24(void **in_ref, void **out_ref, const char *context) {
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    Eigen::VectorXf *_o0;
	_o0 = MAKE(Eigen::VectorXf);
	Eigen::VectorXf ref = Eigen::VectorXf(_a0);
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::VectorXf::void operator+=(Eigen::VectorXf None);) */
extern "C" void shim_25(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_i0 = reinterpret_cast<Eigen::VectorXf *>(in_ref[0]);
    Eigen::VectorXf *_i1 = reinterpret_cast<Eigen::VectorXf *>(in_ref[1]);
    Eigen::VectorXf *_o0;
    Eigen::VectorXf *_o1;
	_i0->operator+=(*_i1);
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) Eigen::VectorXf::void operator-=(Eigen::VectorXf None);) */
extern "C" void shim_26(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_i0 = reinterpret_cast<Eigen::VectorXf *>(in_ref[0]);
    Eigen::VectorXf *_i1 = reinterpret_cast<Eigen::VectorXf *>(in_ref[1]);
    Eigen::VectorXf *_o0;
    Eigen::VectorXf *_o1;
	_i0->operator-=(*_i1);
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) Eigen::VectorXf::void operator*=(float None);) */
extern "C" void shim_27(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_i0 = reinterpret_cast<Eigen::VectorXf *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    Eigen::VectorXf *_o0;
	_i0->operator*=(_a0);
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::VectorXf::void operator*=(Eigen::MatrixXf None);) */
extern "C" void shim_28(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_i0 = reinterpret_cast<Eigen::VectorXf *>(in_ref[0]);
    Eigen::MatrixXf *_i1 = reinterpret_cast<Eigen::MatrixXf *>(in_ref[1]);
    Eigen::VectorXf *_o0;
    Eigen::MatrixXf *_o1;
	_i0->operator*=(*_i1);
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) Eigen::VectorXf::void operator*=(Eigen::VectorXf None);) */
extern "C" void shim_29(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_i0 = reinterpret_cast<Eigen::VectorXf *>(in_ref[0]);
    Eigen::VectorXf *_i1 = reinterpret_cast<Eigen::VectorXf *>(in_ref[1]);
    Eigen::VectorXf *_o0;
    Eigen::VectorXf *_o1;
	_i0->operator*=(*_i1);
	_o0 = _i0;
	_o1 = _i1;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) Eigen::VectorXf::void operator/=(float None);) */
extern "C" void shim_30(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_i0 = reinterpret_cast<Eigen::VectorXf *>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    Eigen::VectorXf *_o0;
	_i0->operator/=(_a0);
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::VectorXf::void resize(int None);) */
extern "C" void shim_31(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_i0 = reinterpret_cast<Eigen::VectorXf *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    Eigen::VectorXf *_o0;
	_i0->resize(_a0);
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::VectorXf::void transpose();) */
extern "C" void shim_32(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_i0 = reinterpret_cast<Eigen::VectorXf *>(in_ref[0]);
    Eigen::VectorXf *_o0;
	_i0->transpose();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::VectorXf::float sum();) */
extern "C" void shim_33(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_i0 = reinterpret_cast<Eigen::VectorXf *>(in_ref[0]);
    Eigen::VectorXf *_o0;
	_i0->sum();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::VectorXf::float prod();) */
extern "C" void shim_34(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_i0 = reinterpret_cast<Eigen::VectorXf *>(in_ref[0]);
    Eigen::VectorXf *_o0;
	_i0->prod();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::VectorXf::float mean();) */
extern "C" void shim_35(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_i0 = reinterpret_cast<Eigen::VectorXf *>(in_ref[0]);
    Eigen::VectorXf *_o0;
	_i0->mean();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::VectorXf::float minCoeff();) */
extern "C" void shim_36(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_i0 = reinterpret_cast<Eigen::VectorXf *>(in_ref[0]);
    Eigen::VectorXf *_o0;
	_i0->minCoeff();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::VectorXf::float maxCoeff();) */
extern "C" void shim_37(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_i0 = reinterpret_cast<Eigen::VectorXf *>(in_ref[0]);
    Eigen::VectorXf *_o0;
	_i0->maxCoeff();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::VectorXf::float trace();) */
extern "C" void shim_38(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_i0 = reinterpret_cast<Eigen::VectorXf *>(in_ref[0]);
    Eigen::VectorXf *_o0;
	_i0->trace();
	_o0 = _i0;
	                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::VectorXf::Eigen::VectorXf Eigen::Vector2f();) */
extern "C" void shim_39(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_o0;
	_o0 = MAKE(Eigen::VectorXf);
	Eigen::VectorXf ref = Eigen::Vector2f();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::VectorXf::Eigen::VectorXf Eigen::Vector3f();) */
extern "C" void shim_40(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_o0;
	_o0 = MAKE(Eigen::VectorXf);
	Eigen::VectorXf ref = Eigen::Vector3f();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::VectorXf::Eigen::VectorXf Eigen::Vector4f();) */
extern "C" void shim_41(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_o0;
	_o0 = MAKE(Eigen::VectorXf);
	Eigen::VectorXf ref = Eigen::Vector4f();
	*_o0 = ref;
	
	                
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Eigen::VectorXf::~Eigen::VectorXf();) */
extern "C" void shim_42(void **in_ref, void **out_ref, const char *context) {
    Eigen::VectorXf *_i0 = reinterpret_cast<Eigen::VectorXf *>(in_ref[0]);
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
    &shim_12,
    &shim_13,
    &shim_14,
    &shim_15,
    &shim_16,
    &shim_17,
    &shim_18,
    &shim_19,
    &shim_20,
    &shim_21,
    &shim_22,
    &shim_23,
    &shim_24,
    &shim_25,
    &shim_26,
    &shim_27,
    &shim_28,
    &shim_29,
    &shim_30,
    &shim_31,
    &shim_32,
    &shim_33,
    &shim_34,
    &shim_35,
    &shim_36,
    &shim_37,
    &shim_38,
    &shim_39,
    &shim_40,
    &shim_41,
    &shim_42,
};

