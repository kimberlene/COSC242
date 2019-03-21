#ifndef MYLIB_H_
#define MYLIB_H_

#include <stddef.h>

/**
 * Allocates the requested memory and returns a pointer to it.
 * The requested size is size bytes. The value of the space is indeterminate.
 * On success a pointer to the requested space is returned.
 * On failure a null pointer is returned. 
 * @param s: s is of type size_t , the amount of memory we need to allocate
   for the data structure 
**/
extern void *emalloc(size_t);

/**
 * Reallocates the requested memory if the capacity is full and returns a pointer to it.
 * Requested size is in bytes. The value of the space is indeterminate.
 * On success a pointer to the requested space is returned.
 * On failure a null pointer is returned.
 * @param s: s is of type size_t, the amount of extra memory we need to reallocate
   for the data structure.
 * @param p: It is the pointer to the data structure we need to reallocate memory to.
 **/
extern void *erealloc(void *, size_t);

#endif



