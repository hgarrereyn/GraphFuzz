

#include <string.h>
#include <string>
#include <iostream>

unsigned long CURR_ID = 0;

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) { }

extern "C" void __attribute__((visibility ("default"))) shim_init() {
    CURR_ID = 0;

    std::cout << "#include \"<Eigen/Dense>\"\n" << std::endl;
    std::cout << "\n#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))\n\nstruct GFUZZ_BUNDLE {\npublic:\n    void *active;\n    void *inactive;\n    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}\n};\n\n#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)\n" << std::endl;

    std::cout << "int main() {" << std::endl;
}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {
    std::cout << "}" << std::endl;
}


/* CPPScope(name=set) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    float _a2;
    memcpy(&_a2, context + 8, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_0" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->operator()(" << _a0 << ", " << _a1 << ") = " << _a2 << ";\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_0" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::Eigen::MatrixXf(int None, int None);) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_1" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(Eigen::MatrixXf);\n        Eigen::MatrixXf ref = Eigen::MatrixXf(" << _a0 << ", " << _a1 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_1" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void operator+=(Eigen::MatrixXf None);) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_2" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->operator+=(*" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_2" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void operator-=(Eigen::MatrixXf None);) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_3" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->operator-=(*" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_3" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void operator*=(float None);) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_4" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->operator*=(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_4" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void operator*=(Eigen::MatrixXf None);) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_5" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->operator*=(*" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_5" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void operator*=(Eigen::VectorXf None);) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_6" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->operator*=(*" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_6" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void operator/=(float None);) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_7" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->operator/=(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_7" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void resize(int None, int None);) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    int _a1;
    memcpy(&_a1, context + 4, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_8" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->resize(" << _a0 << ", " << _a1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_8" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void transpose();) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_9" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->transpose();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_9" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void conjugate();) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_10" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->conjugate();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_10" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void adjoint();) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_11" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->adjoint();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_11" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::void transposeInPlace();) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_12" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->transposeInPlace();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_12" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::float sum();) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_13" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->sum();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_13" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::float prod();) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_14" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->prod();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_14" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::float mean();) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_15" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->mean();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_15" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::float minCoeff();) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_16" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->minCoeff();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_16" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::float maxCoeff();) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_17" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->maxCoeff();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_17" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::float trace();) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_18" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->trace();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_18" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::Eigen::MatrixXf Eigen::Matrix2f();) */
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_19" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(Eigen::MatrixXf);\n        Eigen::MatrixXf ref = Eigen::Matrix2f();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_19" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::Eigen::MatrixXf Eigen::Matrix3f();) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_20" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(Eigen::MatrixXf);\n        Eigen::MatrixXf ref = Eigen::Matrix3f();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_20" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::Eigen::MatrixXf Eigen::Matrix4f();) */
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_21" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(Eigen::MatrixXf);\n        Eigen::MatrixXf ref = Eigen::Matrix4f();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_21" << std::endl;
}


/* CPPScope(name=(auto) Eigen::MatrixXf::~Eigen::MatrixXf();) */
extern "C" void shim_22(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_22" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_22" << std::endl;
}


/* CPPScope(name=set) */
extern "C" void shim_23(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    float _a1;
    memcpy(&_a1, context + 4, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_23" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->operator()(" << _a0 << ") = " << _a1 << ";\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_23" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::Eigen::VectorXf(int None);) */
extern "C" void shim_24(void **in_ref, void **out_ref, const char *context) {
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_24" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(Eigen::VectorXf);\n        Eigen::VectorXf ref = Eigen::VectorXf(" << _a0 << ");\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_24" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::void operator+=(Eigen::VectorXf None);) */
extern "C" void shim_25(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_25" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->operator+=(*" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_25" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::void operator-=(Eigen::VectorXf None);) */
extern "C" void shim_26(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_26" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->operator-=(*" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_26" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::void operator*=(float None);) */
extern "C" void shim_27(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_27" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->operator*=(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_27" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::void operator*=(Eigen::MatrixXf None);) */
extern "C" void shim_28(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    Eigen::MatrixXf *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_28" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->operator*=(*" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_28" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::void operator*=(Eigen::VectorXf None);) */
extern "C" void shim_29(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o1 << ";" << std::endl;

    std::cout << "    { // begin shim_29" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->operator*=(*" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    } // end shim_29" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::void operator/=(float None);) */
extern "C" void shim_30(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    float _a0;
    memcpy(&_a0, context + 0, sizeof(float));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_30" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->operator/=(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_30" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::void resize(int None);) */
extern "C" void shim_31(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_31" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->resize(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_31" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::void transpose();) */
extern "C" void shim_32(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_32" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->transpose();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_32" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::float sum();) */
extern "C" void shim_33(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_33" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->sum();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_33" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::float prod();) */
extern "C" void shim_34(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_34" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->prod();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_34" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::float mean();) */
extern "C" void shim_35(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_35" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->mean();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_35" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::float minCoeff();) */
extern "C" void shim_36(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_36" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->minCoeff();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_36" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::float maxCoeff();) */
extern "C" void shim_37(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_37" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->maxCoeff();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_37" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::float trace();) */
extern "C" void shim_38(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_38" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->trace();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_38" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::Eigen::VectorXf Eigen::Vector2f();) */
extern "C" void shim_39(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_39" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(Eigen::VectorXf);\n        Eigen::VectorXf ref = Eigen::Vector2f();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_39" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::Eigen::VectorXf Eigen::Vector3f();) */
extern "C" void shim_40(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_40" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(Eigen::VectorXf);\n        Eigen::VectorXf ref = Eigen::Vector3f();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_40" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::Eigen::VectorXf Eigen::Vector4f();) */
extern "C" void shim_41(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Eigen::VectorXf *var_" << _o0 << ";" << std::endl;

    std::cout << "    { // begin shim_41" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = MAKE(Eigen::VectorXf);\n        Eigen::VectorXf ref = Eigen::Vector4f();\n        *" << "var_" << _o0 << " = ref;" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    } // end shim_41" << std::endl;
}


/* CPPScope(name=(auto) Eigen::VectorXf::~Eigen::VectorXf();) */
extern "C" void shim_42(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    { // begin shim_42" << std::endl;

    std::cout << "        free(" << "var_" << _i0 << ");" << std::endl;

    std::cout << "    } // end shim_42" << std::endl;
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

