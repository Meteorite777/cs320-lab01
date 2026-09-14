/*
 * Be careful when omitting braces!
 * Just because you can, doesn't mean you should!
 */
#include <stdio.h>
int main(int argc, char *argv[]) {
    int x = 0;
    if (x == 0)
        printf("x is 0\n");
    if (x != 0){ // careful!
        printf("x not 0 line 1\n");
        printf("x not 0 line 2\n");
    }
    return 0;
}
