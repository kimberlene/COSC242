#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_LEN 10000
#define STRING_LEN 80

int main(void) {
    char word[STRING_LEN];
    char *wordlist[ARRAY_LEN];
    int num_words;
    

    while(num_words < ARRAY_LEN && 1 == scanf("%79s", word)) {
    }
}

void insertion_sort(int *a, int n) {
    int x=0, y=0; /*loop variables*/
    int key=0; /*variable to hold the current element of array before swap*/
    for(x=1; x<n; x++) {
        key = a[x];
        y = x-1;
        while(y>=0 && a[y]>key) {
            a[y+1] = a[y];
            y = y-1;
        }
        a[y+1] = key;
    }
    
}
