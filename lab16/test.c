#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"
#include "mylib.h"

void print_key(char *s){
    printf("%s\n", s);
}
int main(void) {
    char word[256];
    rbt b = rbt_new();

    while(1==scanf("%255s", word)) {
        b = rbt_insert(b,word);
    }

    printf("*** Inorder ***\n");
    rbt_inorder(b, print_key);
    printf("\n*** Preorder ***\n");
    rbt_preorder(b,print_key);
    b=rbt_free(b);
    
    return EXIT_SUCCESS;

    }   
