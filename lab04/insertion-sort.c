#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

/*insertion sort function that takes the array to be sorted and its size to ssort it using insertion sort*/
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
int main(void) {
    int my_array[ARRAY_MAX];
    int count = 0;
    clock_t start, end;
    int i=0;
  
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++; /*the value stored in count is the length of the array*/
    }

    start = clock();
    insertion_sort(my_array, count);
    end = clock();

    for(i=0; i<count; i++) {
        printf("%d\n", my_array[i]);
    }
    
    fprintf(stderr, "%d %f\n", count, (end-start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
