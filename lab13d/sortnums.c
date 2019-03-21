#include <stdlib.h>
#include <stdio.h>
#include "flexarray.h"

int main(void) {
    int item;
    flexarray my_flexarray = flexarray_new();
    while (1 == scanf("%d", &item)) {
        flexarray_append(my_flexarray, item);
    }
    flexarray_sort(my_flexarray);
    flexarray_print(my_flexarray);
    flexarray_free(my_flexarray);
    return EXIT_SUCCESS;
}































/*void insertionsort(int *a, int n) {
    int i=0, j=0, k=0;
    int key=0;

    for(i=1; i<n; i++) {
        key = a[i];
        j=i-1;

        if(i==(n/2)){
            for(k=0; k<n; k++) {
                fprintf(stderr,"%d\n",a[k]);
            }
        }

        while(j>=0 && a[j]>key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        
    }

    }*/