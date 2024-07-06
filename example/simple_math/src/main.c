#include <stdio.h>
#include <my_math.h>

int main() {
    int x = 10;
    int y = 7;
    
    printf("my_add(%d,%d) = %d\n", x, y, my_add(x, y));
    printf("my_sub(%d,%d) = %d\n", x, y, my_sub(x, y));
    printf("my_mul(%d,%d) = %d\n", x, y, my_mul(x, y));
    printf("my_div(%d,%d) = %d\n", x, y, my_div(x, y));


    printf("my_abs(%d) = %d\n", x, my_abs(x));
    printf("my_max(%d, %d) = %d\n", x, y, my_max(x, y));
    printf("my_min(%d, %d) = %d\n", x, y, my_min(x, y));

    return 0;
}
 