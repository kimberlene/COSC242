/**mylib.c file for COSC242 assignment.
   Written on Thursday the 13th of September
   @author Joe Marshall marjo989
   @author Rik Karmakar karri390
   @author Kim Sharma shaki694
*/

#include <stdio.h> /* for fprintf */
#include <stdlib.h> /* for size_t, malloc, realloc, exit */
#include "mylib.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>

/**getword method
   @param s the string
   @param limit the maximum length
   @param stream the stream to read from
*/
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
        } else if ('\'' == c) {
            limit++;
        } else {
            break;
        }
    }
    *w = '\0';
    return w - s;
}

/**Our version of the malloc function*/
void *emalloc(size_t s) {
    void *result = malloc(s);
    if(NULL == result){
	fprintf(stderr, "Memory allocation failed!\n");
	exit(EXIT_FAILURE);
    }
    return result;
}

/**Our version of the realloc function*/
void *erealloc(void *p, size_t s) {
    void *result = realloc(p, s);
    if(NULL == result){
	fprintf(stderr, "Memory allocation failed!\n");
	exit(EXIT_FAILURE);
    }
    return result;
}
