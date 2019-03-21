/**mylib.h file for COSC242 assignment.
   Written on Thursday the 13th of September
   @author Joe Marshall marjo989
   @author Rik Karmakar karri390
   @author Kim Sharma shaki694
*/

#ifndef MYLIB_H_
#define MYLIB_H_

#include <stddef.h>

extern void *emalloc(size_t);
extern void *erealloc(void *, size_t);
extern int getword(char *, int, FILE *);

#endif
