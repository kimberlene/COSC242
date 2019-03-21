#include <stdio.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"
struct htablerec {
    int capacity;
    int num_keys;
    char **keys;
};
static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;
    while (*word != ’\0’) {
        result = (*word++ + 31 * result);

    }
    return result;
}
static unsigned int htable_hash(htable h, unsigned int i_key) {
    return i_key % h->capacity;
}
htable htable_new(int capacity) {
    htable result = emalloc(sizeof *result);
    result->capacity = capacity;
    result->num_keys = 0;
    result->keys = emalloc(result->capacity * sizeof(h-> keys[0]));
    for(i =0; i<result->capacity;i++) {
        result->keys[i] = NULL;
    }
    return result;
}
void htable_free(htable h) {
    int i;
    for(i=0; i< h->capacity; i++) {
        free(h->keys[i]);
    }
    free(h->keys);
    free(h);
}
int htable_insert(htable h, char *key) {
    

}
void htable_print(htable h, FILE *stream) {
    for (i = 0; i < h->capacity; i++) {
        fprintf(stream, "%2d %s\n", i, h->keys[i] == NULL ? "" : h->keys[i]);
    }
}
