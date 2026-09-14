#include <stdio.h>

int main(int argc, char *argv[]) {
    int x = 0;
    int y;

    printf("before: x=%d, y=%d, ", x, y);
    x++;
    y += x;
    printf(" after: x=%d, y=%d\n", x, y);

    return 0;
}
