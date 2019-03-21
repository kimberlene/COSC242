#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "mylib.h"

struct bst {
    char *key;
    bst left;
    bst right;
};
/* Create a new bst node */
bst bst_new(){
 
 return NULL;
}
/*Searches for a key in the bst */
int bst_search(bst b,char *key){
    /*If the tree is empty then return 0 */
    if(b == NULL){
     return 0;
 
 }
    else if(strcmp(key, b->key)==0){
        return 1;
    }
    else if(strcmp(key, b->key)>0){
        return bst_search(b->right, key);
    }
    else {
        return bst_search(b->left, key);
    }
    return 0;   
}

/*To insert a key in the BST */
bst bst_insert(bst b,char *str){
  /*If the bst is empty */  
  if(b== NULL){
    b = emalloc(sizeof *b);   
    b->key = emalloc((strlen(str)+1) * sizeof(str[0]));
    strcpy(b->key, str);
    b->left = NULL;
    b->right = NULL;
 } else if (strcmp(b->key,str)>0){
     b->left = bst_insert(b->left, str);   
 } else if (strcmp(b->key, str) < 0){
     /*If the key is greater than the key at node */
     b->right = bst_insert(b->right, str);   
 }

 return b;
}



/*Implenting inorder traversal */
void bst_inorder(bst b, void f(char *str)){
 if(b == NULL){
     return;
 }
 bst_inorder(b->left,f);
 f(b->key);
 bst_inorder(b->right,f);
 

}   
/*Implementing preorder traversal */
void bst_preorder(bst b, void f(char *str)){
 if(b==NULL)return;
 f(b->key);
 bst_preorder(b->left,f);
 bst_preorder(b->right,f);
  }

bst bst_delete(bst b, char *str){
    bst x;
    /*If the tree is null */
    if(b==NULL);

    /* Temporary pointer */
    /*bst x; */

    /*If key you wish to delete matches the key at node splice out the node*/
    else if(strcmp(b->key,str)==0){
        if(b->right == NULL && b->left ==NULL){
            free(b->key);
            free(b);
            return NULL;
        }
        /*One child */
        else if(b->left != NULL && b->right == NULL){
            bst temp = b->left;
            free(b->key);
            free(b);
            return temp;
        }
        /*One child */
        else if(b->left == NULL && b->right !=NULL){
            bst temp = b->right;
            free(b->key);
            free(b);
            return temp;
        }
        /*If node has two children , find the leftmost node of right subtree */
        else {
            x = b->right;
            while(x->left != NULL){
                x = x->left;
            }
            strcpy(b->key, x->key);
            b->right = bst_delete(b->right, x->key);
            return b;
        }
    }

    else if(strcmp(b->key,str)>0 && b->left!=NULL){
        b->left = bst_delete(b->left,str);
    }
    else if(strcmp(b->key,str)<0 && b->right != NULL){
        b->right = bst_delete(b->right,str);
    }

return b;

}




bst bst_free(bst b){
if(b==NULL)return b;
else {
    bst_free(b->left);
    bst_free(b->right);
    free(b->key);
    free(b);
    return b;
}
}























