#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_MAX 10000
#define WORD_MAX 100;


void insertion_sort(int *a, int n) {
    int x=0, y=0; 
    char* key;
    for(x=1; x<n; x++) {
        key = [x];
        y = x-1;
        while(y>=0 && strcmp(a[y],key)>0) {
            a[y+1] = a[y];
            y = y-1;
        }
        a[y+1] = key;
    }
    
}
int main(void) {
    char *my_array[ARRAY_MAX];
    char *word[WORD_MAX];
    int count = 0;
    int i=0;
  
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) { 
        count++;
    }

    insertion_sort(my_array, count);
    
    printf("Sorted String: \n");
    for(i=0; i<count; i++) {
        printf("%d\n", my_array[i]);
    }
    
    return EXIT_SUCCESS;
}
