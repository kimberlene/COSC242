#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

int main(void){
    int item;
    flexarray my_flexarray = flexarray_new();
    while(scanf("%d",&item)==1){
        flexarray_append(my_flexarray, item);
    }
    flexarray_sort(my_flexarray);
    flexarray_print(my_flexarray);
    flexarray_free(my_flexarray);

    return EXIT_SUCCESS;
}
