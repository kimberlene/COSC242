#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

/**
 * Allocates the requested memory and returns a pointer to it.
 * The requested size is size bytes. The value of the space is indeterminate.
 * On success a pointer to the requested space is returned.
 * On failure a null pointer is returned. 
 * @param s: s is of type size_t , the amount of memory we need to allocate for the data structure 
 **/

void *emalloc(size_t s){
    void *result = malloc(s);
    if(NULL == result){
        fprintf(stderr,"Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

/**
 *Reallocates the requested memory if the capacity is full and returns a pointer to it.
 *Requested size is in bytes. The value of the space is indeterminate.
 *On success a pointer to the requested space is returned.
 *On failure a null pointer is returned.
 * @param s: s is of type size_t, the amount of extra memory we need to reallocate for the data structure.
 * @param p: It is the pointer to the data structure we need to reallocate memory to.
 **/
void *erealloc(void *p, size_t s){
    void *result = realloc(p,s);
    if(NULL == result){
        fprintf(stderr,"Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

int getword(char *s, int limit, FILE *stream) {
    int c;
    char *w = s;
    assert(limit > 0 && s != NULL && stream != NULL);
    /* skip to the start of the word */
    while (!isalnum(c = getc(stream)) && EOF != c)
        ;
    if (EOF == c) {
        return EOF;
    } else if (--limit > 0) { /* reduce limit by 1 to allow for the \0 */
        *w++ = tolower(c);
    }
    while (--limit > 0) {
        if (isalnum(c = getc(stream))) {
            *w++ = tolower(c);
        } else if (’\’’ == c) {
            limit++;
        } else {
            break;
        }
    }
    *w = ’\0’;
    return w - s;
}
