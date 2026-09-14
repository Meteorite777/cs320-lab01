#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Received %d args\n", argc);
    
    for (int i = 0; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    return 0;
}

