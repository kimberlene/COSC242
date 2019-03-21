#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

/**
 * allocates memory and returns a pointer
 * @param s is of type size_t , the amount of memory we need to allocate
 * for the data structure 
 **/
void *emalloc(size_t s){
    void *result = malloc(s);
    if(NULL == result){
        fprintf(stderr,"MEMORY ALLOCATION FAILED\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

