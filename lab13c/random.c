#include <stdio.h>
#include <stdlib.h>

void repeats(int *a, int n) {
    int *r;
    int x=0, y=0;
    int count=0;

    r = malloc(n * sizeof r[0]);
    for(x=0;x<n;x++){
        r[x]=-1;
    }
    for(x=0; x<n; x++) {
        count=1;
        for(y=x+1; y<n; y++) {
            if(a[x] == a[y]) {
                count++;
                r[y]=0;
            }
        }
        if(r[x]!=0) {
        r[x] = count;
        }
    }
    
    for(x=0; x<n; x++) {
        if(r[x]>1) {
            printf("%d occurs %d times\n",a[x],r[x]); 
        }
    }
    free(r);
}

void sort(int *a, int n) {
    int i=0, j=0;
    int key=0;
    for(i=1;i<n;i++){
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main(void) {
    int array_size = 0;
    int *a;
    int i=0;

    printf("Enter the size of the array:\n");
    scanf("%d", &array_size);

    a = malloc(array_size * sizeof a[0]);
    if(NULL == a) {
        fprintf(stderr, "memory allocation failed \n");
        return EXIT_FAILURE;
    }

    for(i=0; i<array_size; i++) {
        a[i] = rand() % array_size;
    }
    printf("What's in the array:\n");
    for(i=0; i<array_size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    sort(a, array_size);
    repeats(a, array_size);

    free(a);

    return EXIT_SUCCESS;
}
