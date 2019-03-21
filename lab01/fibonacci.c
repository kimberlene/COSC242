#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void) {
    /* variable declarations */
    int i = 0;
    int f = 0;
    int g = 1;
    int count = 0;
    int c = 0;
    /* a familiar "for loop" */
    for (i = 0; i < 40; i++) {
        printf("%8d ",g);
        count = g;
        g = g + f;
        f = count;
        c++;
        if (c==5){
            printf("\n");
            c = 0;
        }
    }
    return EXIT_SUCCESS; /* defined in stdlib.h */
}
