#ifndef MYLIB_H_
#define MYLIB_H_

#include <stddef.h>

void *emalloc(size_t s);
void *erealloc(void *p,size_t s);
int getword(char *s,int limit, FILE *stream);

#endif

