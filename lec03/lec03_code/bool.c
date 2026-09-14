#include <stdio.h>
#include <stdbool.h>

void true_or_false(int arg) {
    if (arg) {
        printf("%d: True\n", arg);
    } else {
        printf("%d: False\n", arg);
    }
}

int main(int argc, char *argv[]) {
    if (42) {
        printf("meaning of life\n");
    }

    true_or_false(1);
    true_or_false(0);

    int x = 4;
    true_or_false(x);

    true_or_false(true);
    true_or_false(false);

    return 0;
}
