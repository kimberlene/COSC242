#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 100
#define BUFF_SIZE 80

void *emalloc(size_t s) {
    void *result = malloc(s);
    if(NULL == result) {
        fprintf(stderr, "Memory allocation failed. \n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void print_big_words(char **words, int len, double avg) {
    if(len>0) {
        if(strlen(words[0])>avg) {
            printf("%s\n",words[0]);
        }
        print_big_words(words+1, len-1, avg);
     }
}

int main(void) {
    char *words[ARRAY_SIZE];
    char word[BUFF_SIZE];
    int count=0, i=0;
    double avg=0.0;

    while(count<ARRAY_SIZE && 1==scanf("%79s",word)) {
            words[count] = emalloc((strlen(word)+1) * sizeof word[0]);
            strcpy(words[count], word);
            avg = avg + strlen(word);
            count++;
        }
        if(count>0) {
            avg = avg/count;
            fprintf(stderr,"%.2f\n", avg);
            print_big_words(words, count, avg);
        }

        for(i=0; i<count; i++){
            free(words[i]);
        }
        return EXIT_SUCCESS;
                
}
