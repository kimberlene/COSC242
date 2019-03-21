#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "mylib.h"

void print_key(char *s){
    printf("%s\n", s);
}
int main(void) {
    char word[256];
    

    bst b = bst_new();

    while(1==scanf("%255s", word)) {
    printf("%s - Here\n", word);
    b = bst_insert(b,word);
        }
    printf("Inorder traversal\n");
    bst_inorder(b,print_key);
    printf("Deleting 5\n");
    b=bst_delete(b,"5");
    printf("5 deleted\n");
    printf("Preorder\n");
    bst_preorder(b,print_key);
    b=bst_free(b);

    return EXIT_SUCCESS;

    }   


