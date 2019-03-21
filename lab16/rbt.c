#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rbt.h"
#include "mylib.h"

typedef enum {RED,BLACK} rbt_colour;

struct rbt {
    char *key;
    rbt_colour colour;/**Needs to be red on creation of nodes*/
    rbt left;
    rbt right;
};

#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour))
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour))

/* Create a new rbt node */
rbt rbt_new(){
    return NULL;
}

/*Searches for a key in the rbt */
int rbt_search(rbt b,char *key){
    /*If the tree is empty then return 0 */
    if(b == NULL){
        return 0;
    }else if(strcmp(key, b ->key)==0){
        return 1;
    }else if(strcmp(key, b ->key)>0){
        return rbt_search(b ->right, key);
    }else {
        return rbt_search(b ->left, key);
    }
    return 0;   
}

/*NEW METHOD RBT RIGHT ROTATE */
static rbt right_rotate(rbt r){
    rbt R = r; 
    rbt temp = r;
    R = R->left; /*Changed root of tree to point to its left child */
    temp->left = R->right; /*Left child of temp(original root) points to right child of new root */
    R->right = temp;
    return R;
}

/*NEW METHOD RBT LEFT ROTATE */
static rbt left_rotate(rbt r){
    rbt R = r;
    rbt temp = r;
    R = R->right;
    temp->right = R->left;
    R->left = temp;
    return R;
}

static rbt rbt_fix(rbt r){
    
    if(IS_RED(r->left) && IS_RED((r->left)->left)){
        if(IS_RED(r->right)){
            r->colour = RED;
            (r->left)->colour = BLACK;
            (r->right)->colour = BLACK;
        }
        else {
            r = right_rotate(r);
            r->colour = BLACK;
            (r->right)->colour = RED;
        }
    }
     if(IS_RED(r->left) && IS_RED((r->left)->right)){
        if(IS_RED(r->right)){
            r->colour = RED;
            (r->left)->colour = BLACK;
            (r->right)->colour = BLACK;
        }
        else {
            r->left = left_rotate(r->left);
            r = right_rotate(r);
            r->colour = BLACK;
            (r->right)->colour = RED;
        }
    }
    
    
    if(IS_RED(r->right) && IS_RED((r->right)->left)){
        if(IS_RED(r->left)){
            r->colour = RED;
            (r->left)->colour = BLACK;
            (r->right)->colour = BLACK;
        }
        else {
            r->right = right_rotate(r->right);
            r = left_rotate(r);
            r->colour = BLACK;
            (r->left)->colour = RED;
        }
    }
    if(IS_RED(r->right) && IS_RED((r->right)->right)){
        if(IS_RED(r->left)){
            r->colour = RED;
            (r->left)->colour = BLACK;
            (r->right)->colour = BLACK;
        }
        else {
            r = left_rotate(r);
            r->colour = BLACK;
            (r->left)->colour = RED;
        }
    }

    
    return r;
}

/*To insert a key in the rbt */
rbt rbt_insert(rbt r,char *str){
    /*If the rbt is empty */

    if(r== NULL){  
        r = emalloc(sizeof *r);   
        r->key = emalloc((strlen(str)+1) * sizeof(str[0]));
        strcpy(r->key, str);
        r->colour = RED;
        r->left = NULL;
        r->right = NULL;
    }else if (strcmp(r->key,str)>0){
        r->left = rbt_insert(r->left, str);   
    }else if (strcmp(r->key, str) < 0){
        r->right = rbt_insert(r->right, str);   
    }

    r = rbt_fix(r);
    return r;
}

void test_colour(rbt r){
    if(IS_BLACK(r)){
        printf("Black: ");
    }
    else printf("Red: ");
}

/*Implenting inorder traversal */
void rbt_inorder(rbt b, void f(char *str)){
    if(b == NULL){
        return;
    }

    rbt_inorder(b->left,f);
    if(IS_BLACK(b)){
        printf("Black: ");
    }
    else printf("Red: ");
    f(b->key);
    rbt_inorder(b->right,f);
}

/*Implementing preorder traversal */
void rbt_preorder(rbt b, void f(char *str)){
    if(b==NULL)return;

    if(IS_BLACK(b)){
        printf("Black: ");
    }
    else printf("Red: ");
    f(b->key);
    rbt_preorder(b->left,f);
    rbt_preorder(b->right,f);
}

rbt rbt_free(rbt b){
    if(b==NULL){
        return b;
    }else{
        rbt_free(b->left);
        rbt_free(b->right);
        free(b->key);
        free(b);
        return b;
    }
}

























