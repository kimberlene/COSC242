#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"


void print_key(char *s){
    printf("%s\n", s);
}
int main(void) {
    char word[256];
    tree b = tree_new(RBT);

    while(1==scanf("%255s", word)) {
        b = tree_insert(b,word);
    }
    b = root_to_black(b);

    printf("*** Inorder ***\n");
    tree_inorder(b, print_key);
    printf("\n*** Preorder ***\n");
    tree_preorder(b,print_key);
    b=tree_free(b);
    
    return EXIT_SUCCESS;

    }   
