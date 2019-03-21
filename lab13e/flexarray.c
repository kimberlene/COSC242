#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};



/**Error checking malloc function **/
void *emalloc(size_t s){
void *result = malloc(s);
if(NULL == result){
fprintf(stderr,"Memory allocation failed\n");
exit(EXIT_FAILURE);
}
return result;
}


/**Error checking realloction function**/
void *erealloc(void *p,size_t s){
void *result = realloc(p,s);
if(NULL == result){
    fprintf(stderr,"MEMORY ALLOCATION FAILED\n");
    exit(EXIT_FAILURE);
}
return result;
}


flexarray flexarray_new(){

flexarray result = emalloc(sizeof *result);
result->capacity = 2;
result->itemcount = 0;
result->items = emalloc(result->capacity * sizeof result->items[0]);
return result;
}

void flexarray_append(flexarray f,int item){
if(f->itemcount == f->capacity){
f->capacity += f->capacity;
f->items = erealloc(f->items, f->capacity*sizeof f->items[0]);
}
f->items[f->itemcount++] = item;
}


void flexarray_print(flexarray f){
int i;
for(i=0;i<f->itemcount;i++){
printf("%d\n",f->items[i]);
}
}

void selectionsort(int *a, int n) {
    int i=0, j=0, k=0, min=0, temp=0;
    for(i=0; i<n-1; i++) {
        min = i;
        for(j=i+1; j<n; j++) {
            if(a[j]<a[min]) {
                min=j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        if(i==(n/2)-1) {
            for(k=0;k<n;k++) {
                fprintf(stderr, "%d\n",a[k]);
            }
        }
    }
}


void flexarray_sort(flexarray f){
selectionsort(f->items,f->itemcount);
}


void flexarray_free(flexarray f){
free(f->items);
free(f);
}


