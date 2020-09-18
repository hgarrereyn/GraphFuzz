
#include <cstring>
#include <vector>

class Foo {
public:
    Foo(): buffer(0) {}

    void write(char val) {
        buffer.push_back(val);
    }

    void check() {
        if (buffer.size() >= 4 && \
            buffer[0] == 'F' && \
            buffer[1] == 'U' && \
            buffer[2] == 'Z' && \
            buffer[3] == 'Z'
        ) {
            __builtin_trap();
        }
    }
private:
    std::vector<char> buffer;
};
