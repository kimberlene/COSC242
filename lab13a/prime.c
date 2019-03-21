#include <stdlib.h>
#include <stdio.h>

int is_prime(int num) {
    int i=2;
    for(i=2; i<num; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1; 
 }

int main(void) {
    int candidate = 2;
    int num_p = 0;
    while( num_p<200) {
        if(is_prime(candidate)) {
        printf("%5d", candidate);
        num_p++;
        if((num_p) % 10 == 0) {
            printf("\n");
        }
        }
        candidate++;
        
    }
    return EXIT_SUCCESS;
}
