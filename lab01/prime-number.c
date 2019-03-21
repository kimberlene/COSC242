#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* dclare variables */
int candidate = 0;
int n = 0;
int num_printed = 0;
int c = 0;
int is_prime(int candidate) {
    for(n = 2; n <= candidate/2; n++){
        if(candidate % n == 0)
            return 0;
    }
    return 1;
}

int main(void){
    candidate = 2;
    num_printed = 0;
    while(num_printed < 100) {
        if(is_prime(candidate)){
            printf("%5d ", candidate);
            num_printed++;
            c++;
            
            if (c %5==0){
                printf("\n");
                
            }
    }
        
        candidate = candidate + 1;
}
    return EXIT_SUCCESS;
}
