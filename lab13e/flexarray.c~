#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"
#include "sortnums.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

int main(void){
    int item;
    flexarray my_flexarray = flexarray_new();
    while(scanf("%d",&item)==1){
        flexarray_append(my_flexarray, item);
    }
    flexarray_sort(my_flexarray);
    flexarray_print(my_flexarray);
    flexarray_free(my_flexarray);

    return EXIT_SUCCESS;
}

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

void flexarray_sort(flexarray f){
selectionsort(f->items,f->itemcount);
}


void flexarray_free(flexarray f){
free(f->items);
free(f);
}


