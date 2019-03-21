#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#define ARRAY_MAX 10000

void merge_sort(int *a, int *w, int n) {
    int x1 = n/2;
    int x2 = n-n/2;
    int i,j;
    int *b= a+x2;
    
    if(n<=2) {
        return;
    }
    merge_sort(a, w, n/2);
    merge_sort((a+n/2), w, (n-(n/2)));

    while(i<x1 && j<x2){
        if(a[i]<b[j]){
            
        }
    }
}

int main(void) {
    int my_array[ARRAY_SIZE];
    clock_t start, end;
    int i, count=0;

    while(count<ARRAY_MAX && 1==scanf("%d", &my_array[count])) {
            count++ ;
    }
    start = clock();
    merge_sort(my_array, count);
    end = clock();

    for(i=0; i<count; i++) {
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end-start) / (double) CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
