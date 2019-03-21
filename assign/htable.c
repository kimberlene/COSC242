#include <stdio.h>
#include <stdlib.h>
#include "htable.h"
#include "mylib.h"
#include <string.h>

/**
 * struct for hashtable
 * keys is a pointer to a multi-dimensional array that holds hkeys of the hashtable
 * freqs
 * num_keys keeps a count of the number of keys in the hashtable
 * capacity is the maximum size of hastable
 **/
struct htablerec {
    char **keys;
    int *freqs;
    int num_keys;
    int capacity;
};

/**
 * creates a new hashtable
 @param capacity is the maximum number of keys the hashtable can hold
 **/
htable htable_new(int capacity){
    int i;
    
    htable result = emalloc(sizeof *result);
    
    result->capacity = capacity;
    result->num_keys = 0;

    /** Allocate space */
    result->freqs = emalloc(result->capacity * sizeof result->freqs[0]);
    result->keys = emalloc(result->capacity * sizeof result->keys[0]);

    /** Initialize values */
    for(i = 0; i < capacity; i++){
        result->freqs[i] = 0;
        result->keys[i] = NULL;
    }
    
    return result;
}

/**
 * converts the string value to integer type to do the hashing 
 * @param word the string to be converted to an interger
 **/
static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;
    
    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    
    return result;
}

/**
 * inserts keys into the hashtable
 * @param h is the hastable the keys get inserted into
 * @param str the character to be inserted into the hashtable
 **/
int htable_insert(htable h, char *str){
    int index = (htable_word_to_int(str)) % h->capacity;

    int temp;

    if(h->keys[index] == NULL){
        h->keys[index] = emalloc(strlen(str) + 1 * sizeof h->keys[0]);
        strcpy(h->keys[index], str);
        h->freqs[index]++;
        h->num_keys++;
        return 1;
    }else if(strcmp(h->keys[index], str) == 0){
        return ++h->freqs[index];
    }else{
        temp = index;
        while(h->keys[index] != NULL && strcmp(h->keys[index], str) != 0){
            index = (index + 1) % h->capacity;
                
            if(index == temp){
                return 0;
            }
        }
        if(h->keys[index] == NULL){
            h->keys[index] = emalloc(strlen(str) + 1 * sizeof h->keys[0]);
            strcpy(h->keys[index], str);
            h->freqs[index]++;
            h->num_keys++;
            return 1;
        }else{
            return ++h->freqs[index];
        }
    }         
}

/**
 * print the hashtable
 * @param h is the hastable to be printed
 * @param stream
 **/
void htable_print(htable h, FILE *stream){
    int i;
    for(i = 0; i < h->capacity; i++){
        if(h->keys[i] != NULL){
            fprintf(stream, "%d %s\n", h->freqs[i], h->keys[i]);
        }
    }
}

/**
 * the function searches the hashtable in order to find the desrired key
 * @param h is the hastable to be searched
 * @param str is the key which is being searched
 **/
int htable_search(htable h, char *str){
    int num_collisions = 0;

    int index = (htable_word_to_int(str)) % h->capacity;

    while(h->keys[index] != NULL && strcmp(h->keys[index], str) != 0){
        if(num_collisions == h->capacity){
            return 0;
        }

        index = index + 1 % h->capacity;

        num_collisions++;
    }

    return h->freqs[index];
}

/**
 * Memory is being deallocated at the end of the program
 *@param h is the hastable whose memory is beong deallocated
 **/
void htable_free(htable h){
    int c;
    /** Reverse order in which it was allocated */
    for(c = 0; c < h->capacity; c++){
        if(h->keys[c] != NULL ){
            free(h->keys[c]);
        }
    }            
    free(h->keys);
    free(h->freqs);
    free(h);
}
