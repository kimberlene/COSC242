#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"

struct htablerec {
    int capacity;
    int num_keys;
    char **keys;
};

htable htable_new(int capacity) {
    int i;
    htable result = emalloc(sizeof * result);
    result->capacity = capacity;
    result->num_keys = 0;
    result->keys = emalloc(result->capacity * sizeof (result->keys[0]));
 
    for(i=0;i<result->capacity;i++){
        result->keys[i] = NULL;
    }
    return result;
}

void htable_free(htable h) {
    int i;
    for(i=0;i<h->capacity;i++){
        free(h->keys[i]);
    }
    free(h->keys);
    free(h);
}
static unsigned int htable_word_to_int(char *word){
    unsigned int result = 0;

    while(*word!='\0'){
        result = (*word++ + 31 * result);
    }
    return result;
}

int htable_insert(htable h, char *key) {
    int index = htable_word_to_int(key) % h->capacity;
    int temp;
    int result;

    if(h->keys[index] == NULL){
        h->keys[index] = emalloc(strlen(key)+1 * sizeof h->keys[0]);
        strcpy(h->keys[index], key);
        result = 1;
    }
    else {
        temp = index;
        while(h->keys[index]!=NULL && strcmp(h->keys[index],key)!=0){
            
            index = (index+1)%h->capacity;
            if(index == temp){
                return 0;
            }
        }
        if(h->keys[index] == NULL){
            h->keys[index] = emalloc(strlen(key)+1 *sizeof h->keys[0]);
            strcpy(h->keys[index],key);
            result = 1;
        }
    }
    return result;
            
}
void htable_print(htable h, FILE *stream) {
    int i;
    for (i = 0; i < h->capacity; i++) {
        fprintf(stream, "%2d %s\n", i, h->keys[i] == NULL ? "" : h->keys[i]);
    }
    
}
