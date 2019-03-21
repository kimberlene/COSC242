/**
 * htable.h file for COSC242 assignment.
 * Written on Thursday the 13th of September
 * @author Joe Marshall marjo989
 * @author Rik Karmakar karri390
 * @author Kim Sharma shaki694
 **/

#ifndef HTABLE_H_
#define HTABLE_H_

#include <stdio.h>

typedef struct htablerec *htable;
typedef enum hashing_e { LINEAR_P, DOUBLE_H } hashing_t;

/**
 * Free all memory associated with
 * the htable struct
 * @param h the hashtable to be freed
 **/
extern void   htable_free(htable h);


/**
 * Insert a key into the hashtable
 * @param h the hashtable
 * @param str the key to be inserted
 * @return returns 0 if full,otherwise frequency
 **/
extern int    htable_insert(htable h, char *str);


/**
 * Makes a new hash table
 * @param capcity stores the size of the table
 * @param method collision resolution varibale
 * @return returns the new hash table 
 **/
extern htable htable_new(int capacity, hashing_t method);


/**
 * To print all the keys and frequencies
 * @param h hashtable
 * @param f function passed as an argument that prints
 * the hastable
 **/
extern void   htable_print(htable h, void f(int freq, char *word));


/**
 * To search for a key in the hashtable
 * @param h the hashtable to be searched
 * @param *str the key to be searched
 * @return returns 0 if key is not found
 * returns the frequency of the key
 * if it is found in the hashtable
 **/
extern int    htable_search(htable h, char *str);


/**
 * To print the entire hashtable to *stream stream
 * @param h the hashtable
 * @param the stream to which the hashtable is printed
 **/
extern void   htable_print_entire_table(htable h, FILE *stream);


/**
 * Prints out a table showing what the following attributes were like
 * at regular intervals (as determined by num_stats) while the
 * hashtable was being built.
 *
 * @li Percent At Home - how many keys were placed without a collision
 * occurring.
 * @li Average Collisions - how many collisions have occurred on
 *  average while placing all of the keys so far.
 * @li Maximum Collisions - the most collisions that have occurred
 * while placing a key.
 *
 * @param h the hashtable to print statistics summary from.
 * @param stream the stream to send output to.
 * @param num_stats the maximum number of statistical snapshots to print.
 */
extern void   htable_print_stats(htable h, FILE *stream, int num_stats);


#endif
