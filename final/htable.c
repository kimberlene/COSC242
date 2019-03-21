/**
 * htable.c file for COSC242 assignment.
 * Written on Thursday the 13th of September
 * @author Joe Marshall marjo989
 * @author Rik Karmakar karri390
 * @author Kim Sharma shaki694
 **/

#include <stdio.h>
#include <stdlib.h>
#include "htable.h"
#include "mylib.h"
#include <string.h>

/**
 * Struct for hashtable
 * **keys array of strings
 * *freqs array of integers counting duplicates
 * *stats array of integers to store related info
 * num_keys to store the number of keys
 * capacity size of the table
 * method collision resolution variable either LP, DH
 **/
struct htablerec {
    char **keys;
    int *freqs;
    int *stats;
    int num_keys;
    int capacity;
    hashing_t method;
};

/**
 * Makes a new hash table
 * @param capcity stores the size of the table
 * @param method collision resolution varibale
 * @return returns the new hash table 
 **/
htable htable_new(int capacity, hashing_t method){
    int i;
    
    htable result = emalloc(sizeof *result);

    result->method = method;    
    result->capacity = capacity;
    result->num_keys = 0;

    /** Allocate space */
    result->freqs = emalloc(result->capacity * sizeof result->freqs[0]);
    result->keys = emalloc(result->capacity * sizeof result->keys[0]);
    result->stats= emalloc(result->capacity * sizeof result->stats[0]);

    /** Initialize values */
    for(i = 0; i < capacity; i++){
        result->freqs[i] = 0;
        result->keys[i] = NULL;
    }
    
    return result;
}

/**
 * Calculates the step for double hashing
 * @param h the hashtable
 * @param i_key value used in the calculation
 * @return the number of positions to advance
 **/
static unsigned int htable_step(htable h, unsigned int i_key) {
    return 1 + (i_key % (h->capacity - 1));
}

/**
 * Converts the string to its integer equivalent
 * @param word the word we want to convert to int
 * @return returns the integer equivalent of word
 **/
static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;
    
    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    
    return result;
}

/**
 * Insert a key into the hashtable
 * @param h the hashtable
 * @param str the key to be inserted
 * @return returns 0 if full,otherwise frequency
 **/
int htable_insert(htable h, char *str){
    int index = (htable_word_to_int(str)) % h->capacity;

    int temp;

    /**Calculate the step*/
    unsigned int step = htable_step(h, index);

    int num_collisions = 0;

    if(h->keys[index] == NULL){
        h->keys[index] = emalloc(strlen(str) + 1 * sizeof h->keys[0]);
        strcpy(h->keys[index], str);
        h->freqs[index]++;
        h->stats[h->num_keys] = 0;
        h->num_keys++;
        return 1;
    }else if(strcmp(h->keys[index], str) == 0){
        return ++h->freqs[index];
    }else{
        temp = index;
        while(h->keys[index] != NULL && strcmp(h->keys[index], str) != 0){
            num_collisions++;
            
            /**Choose hashing method based on h->method*/
            if(h->method == LINEAR_P){
                index = (index + 1) % h->capacity;
            }else if(h->method == DOUBLE_H){
                index = (index + step) % h->capacity;
            }        
                
            if(index == temp){
                return 0;
            }
        }
        
        if(h->keys[index] == NULL){
            h->keys[index] = emalloc(strlen(str) + 1 * sizeof h->keys[0]);
            strcpy(h->keys[index], str);
            h->freqs[index]++;
            h->stats[h->num_keys] = num_collisions;
            h->num_keys++;
            return 1;
        }else{
            return ++h->freqs[index];
        }
    }         
}

/**
 * To print all the keys and frequencies
 * @param h hashtable
 * @param f function passed as an argument that prints
 * the hastable
 **/
void htable_print(htable h, void f(int freq, char *word)){
    int i;
    for(i = 0; i < h->capacity; i++){
        f(h->freqs[i], h->keys[i]);
    }
}

/**
 * To search for a key in the hashtable
 * @param h the hashtable to be searched
 * @param *str the key to be searched
 * @return returns 0 if key is not found
 * returns the frequency of the key
 * if it is found in the hashtable
 **/
int htable_search(htable h, char *str){
    int num_collisions = 0;

    int index = (htable_word_to_int(str)) % h->capacity;

    int step = htable_step(h, index);

    while(h->keys[index] != NULL && strcmp(h->keys[index], str) != 0){
        if(num_collisions == h->capacity){
            return 0;
        }

        index = (index + step) % h->capacity;

        num_collisions++;
    }

    return h->freqs[index];
}

/**
 * Free all memory associated with
 * the htable struct
 * @param h the hashtable to be freed
 **/
void htable_free(htable h){
    int c;
    /** Reverse order in which it was allocated */
    for(c = 0; c < h->capacity; c++){
        if(h->keys[c] != NULL ){
            free(h->keys[c]);
        }
    }
    free(h->stats);
    free(h->keys);
    free(h->freqs);
    free(h);
}

/**
 * To print the entire hashtable to *stream stream
 * @param h the hashtable
 * @param the stream to which the hashtable is printed
 **/
void htable_print_entire_table(htable h, FILE *stream){
    int i;

    fprintf(stream, "%5s %5s %5s   %s\n", "Pos", "Freq", "Coll", "Word");
    fprintf(stream, "----------------------------------------\n");
    
    
    for(i = 0; i < h->capacity; i++){
        if((h->keys[i]) != NULL){
            fprintf(stream, "%5d %5d %5d   %s\n", i, h->freqs[i], h->stats[i], h->keys[i]);
        }else{
            fprintf(stream, "%5d %5d %5d   %s\n", i, h->freqs[i], h->stats[i], "");
        }
    }
}

/**
 * Prints out a line of data from the hash table to reflect the state
 * the table was in when it was a certain percentage full.
 * Note: If the hashtable is less full than percent_full then no data
 * will be printed.
 *
 * @param h - the hash table.
 * @param stream - a stream to print the data to.
 * @param percent_full - the point at which to show the data from.
 */
static void print_stats_line(htable h, FILE *stream, int percent_full) {
    int current_entries = h->capacity * percent_full / 100;
    double average_collisions = 0.0;
    int at_home = 0;
    int max_collisions = 0;
    int i = 0;

    if (current_entries > 0 && current_entries <= h->num_keys) {
        for (i = 0; i < current_entries; i++) {
            if (h->stats[i] == 0) {
                at_home++;
            } 
            if (h->stats[i] > max_collisions) {
                max_collisions = h->stats[i];
            }
            average_collisions += h->stats[i];
        }
    
        fprintf(stream, "%4d %10d %10.1f %10.2f %11d\n", percent_full, 
                current_entries, at_home * 100.0 / current_entries,
                average_collisions / current_entries, max_collisions);
    }
}

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
void htable_print_stats(htable h, FILE *stream, int num_stats) {
    int i;

    fprintf(stream, "\n%s\n\n", 
            h->method == LINEAR_P ? "Linear Probing" : "Double Hashing"); 
    fprintf(stream, "Percent   Current   Percent    Average      Maximum\n");
    fprintf(stream, " Full     Entries   At Home   Collisions   Collisions\n");
    fprintf(stream, "-----------------------------------------------------\n");
    for (i = 1; i <= num_stats; i++) {
        print_stats_line(h, stream, 100 * i / num_stats);
    }
    fprintf(stream, "-----------------------------------------------------\n\n");
}



    

