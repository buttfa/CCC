#include <my_math.h>

int my_add(int x, int y) {
    return x + y;
}

int my_sub(int x, int y) {
    return x - y;
}

int my_mul(int x, int y) {
    return x * y;
}

int my_div(int x, int y) {
    return x / y;
}
int my_abs(int x) {
    return x < 0 ? -x : x;
}

int my_max(int x, int y) {
    return x > y ? x : y;
}

int my_min(int x, int y) {
    return x < y ? x : y;
}