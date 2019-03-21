#include <stdio.h>
#include <stdlib.h>

# define ARRAY_SIZE 5

void min_max(int *a, int n, int *max, int *min) {
    int i=0;
    *min = a[i];
    for(i=0; i<n; i++) {
        if(a[i]> *max) {
            *max = a[i];
        }
        if(a[i]< *min) {
            *min = a[i];
        }
    }
}

void display_repeats(int *b, int z) {
    int s=0, s2=0, s3=0;
    int count=0;
    int *repeat_array;

    repeat_array = malloc(z * sizeof repeat_array[0]);
    /*if(NULL == repeat_array) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
        }*/
    /*int *repeat_array;*/
    for(s=0; s< z; s++) {
        for(s2=0; s2<z; s2++) {
            if(b[s] == b[s2]) {
                count++;
            }
        }
        repeat_array[s] = count;
        
        /*  printf("%d occurs %d times \n", b[s],count);
            }*/
        count = 0;
    }
    for(s3=0; s3<z; s3++) {
        printf("%d occurs %d times\n", b[s3], repeat_array[s3]);
    }
}

int main(void) {
    int *array1;
    int size = 0;
    int biggest=0, smallest=0;
    int x=0, y=0;

    printf("Enter size of array:");
    scanf("%d", &size);

    array1 = malloc(size * sizeof array1[0]);
    if (NULL == array1) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    /*repeat_array = malloc(size * sizeof repeat_array[0]);
    if(NULL == repeat_array) {
        fprintf(stderr, "memory allocation failed\n");
        return EXIT_FAILURE;
        }*/

    for(x=0; x<size; x++) {
        array1[x] = rand() % size;
    }

    for(y=0; y<size; y++) {
        printf("%d\n", array1[y]);
    }
    min_max(array1,size, &biggest, &smallest);
    printf("Max value: %d, Min value: %d\n", biggest, smallest);

    display_repeats(array1,size);
    
}
