

class Test {
public:
    Test() {}
    void fuzz1(int a[4]) {
        if (a[2] == 3 && a[3] == 4) __builtin_trap();
    }
    void fuzz2(int a[32], float b[8]) {}
};
