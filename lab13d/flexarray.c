#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

void *emalloc(size_t s) {
    void *result = malloc(s);
    if(NULL==result) {
        fprintf(stderr,"memory allocation failed. \n");
        exit(EXIT_FAILURE);
    }
    return result;
    }

void *erealloc(int *p, size_t s) {
    void *result = realloc(p, s);
    if(result == NULL) {

        fprintf(stderr,"memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}

void flexarray_append(flexarray f, int num) {
    if (f->itemcount == f->capacity) {
        f->capacity = f->capacity + f->capacity;
        f->items = realloc(f->items, f->capacity * sizeof f->items[0]);
    }
    f->items[f->itemcount++] = num;
        /* do the old "double the capacity" trick */
        /* insert the item in the last free space */
}
void flexarray_print(flexarray f) {
    int i=0;
    for(i=0;i<f->itemcount;i++) {
        printf("%d\n",f->items[i]);
    }
    /* a "for" loop to print out each cell of f->items */
}

void insertionsort(int *a, int n) {
    int i=0, j=0, k=0, key=0;
    for(i=1; i<n; i++) {
        key=a[i];
        j=i-1;

        if(i==n/2) {
            for(k=0;k<n;k++){
                fprintf(stderr, "%d\n",a[k]);
            }
        }
        
        while(j>=0 && a[j]>key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
    
void flexarray_sort(flexarray f) {
    insertionsort(f->items, f->itemcount);
    /* mergesort would be good */
}
void flexarray_free(flexarray f) {
    free(f->items);
    free(f);
    /* free the memory associated with the flexarray */
}


