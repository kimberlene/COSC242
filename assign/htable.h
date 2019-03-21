#ifndef HTABLE_H_
#define HTABLE_H_

#include <stdio.h>

typedef struct htablerec *htable;

/**
 * Memory is being deallocated at the end of the program
 *@param h is the hastable whose memory is beong deallocated
 **/
extern void   htable_free(htable h);

/**
 * inserts keys into the hashtable
 * @param h is the hastable the keys get inserted into
 * @param str the character to be inserted into the hashtable
 **/
extern int    htable_insert(htable h, char *str);

/**
 * creates a new hashtable
 @param capacity is the maximum number of keys the hashtable can hold
**/
extern htable htable_new(int capacity);

/**
 * print the hashtable
 * @param h is the hastable to be printed
 * @param stream
 **/
extern void   htable_print(htable h, FILE *stream);

/**
 * the function searches the hashtable in order to find the desrired key
 * @param h is the hastable to be searched
 * @param str is the key which is being searched
 **/
extern int    htable_search(htable h, char *str);

#endif
