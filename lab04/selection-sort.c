#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

/*method that sorts the input array using selection sort*/
void selection_sort(int *a, int n) {
    int x=0, y=0; /*loop variables*/
    int t; /*swapping variable*/
    int min;/*stores the index of the smallest element in the array*/
    for(x=0; x<n; x++) {/*loop runs from x to to all elements of array*/
        min = x;
        for(y=x+1; y<n; y++) {/*loop runs from x+1 to end of array*/
            if(a[y]<a[min]){ /*checkes to find smallest element*/
                min = y;/*stores the index of smallest elememt in min */
            }
        }
        /*swapping to sort array*/
        t = a[x];
        a[x] = a[min];
        a[min] = t;
    }
}
    

int main(void) {
    int my_array[ARRAY_MAX];/*creates array with total elements declared in ARAAY_MAX*/
    int count = 0;/*variable used to store total elememts in array*/
    clock_t start, end;/*clock variables to calculate the time*/
    int i=0;
    
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++; /*count variable stores the length of the array*/
    }
    
    start = clock(); /*calculates the start time of the program*/
    selection_sort(my_array, count); /*calls the method selection sort which sorts the array*/
    end = clock();/*calculates when the program finished execution*/
    for(i=0; i<count; i++) {
        printf("%d\n", my_array[i]);
    }
 
    fprintf(stderr, "%d %f\n", count, (end-start) / (double)CLOCKS_PER_SEC);/*prints the timing information about the program*/
    return EXIT_SUCCESS;
}
