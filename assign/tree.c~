#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "mylib.h"


#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour))
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour))


typedef enum {RED,BLACK} tree_colour;

/* tree_type stores the type of the tree - RBT or BST */
static tree_t tree_type;

/**
 * struct tree node
 * key is the node in the tree
 * colour is the colour of the nodes in an RBT
 * frequency stores the frequency of duplicate keys in the tree
 * left is the left nodes in the tree
 * right is the right nodes of the tree
 **/
struct tree {
    char *key;
    tree_colour colour;
    int frequency;
    tree left;
    tree right;
    
};

/**
 * creates a new tress of a specified type - RBT or BST
 * @param type is the type of desired tree
 * RBT for a Red Black Tree
 * BST for a Binary Search Tree
 **/
tree tree_new(tree_t type){
    tree_type = type;
    return NULL;
}

/**
 * searches the tree and returns 1 if the key is present
 * @param t is the tree being passed
 * @param key is the character to be searched in the tree
 **/
int tree_search(tree t,char *key){
    /*If the tree is empty then return 0 */
    if(t == NULL){
        return 0;
    }
    else if(strcmp(key, t->key)==0){
        return 1;
    }
    else if(strcmp(key, t->key)>0){
        return tree_search(t->right, key);
    }
    else {
        return tree_search(t->left, key);
    }
    return 0;   
}

/**
 * Memory allocated is being deallocated at the end of the program
 * @param t is the tree that needs its memory deallocated
 **/
tree tree_free(tree t){
    if(t==NULL){
        return t;
    }else{
        tree_free(t->left);
        tree_free(t->right);
        free(t->key);
        free(t);
        return t;
    }
}

/**
 * prints the nodes of the tree using Inorder traversal
 * @param t is the tree whose nodes are to be traversed
 * @param void f(char *str) is a method being passed which
   prints out the node
 **/
void tree_inorder(tree t, void f(char *str)){
    
    if(t == NULL){
        return;
    }
       tree_inorder(t->left,f);
    if(tree_type == RBT){
        if(IS_BLACK(t)){
        printf("Black: ");
        }
        else printf("Red: ");
    }
    f(t->key);
    tree_inorder(t->right,f);
}

/**
 * prints the nodes of the tree using Preorder traversal
 * @param t is the tree whose nodes are to be traversed
 * @param void f(char *str) is a method being passed which
   prints out the node
**/
void tree_preorder(tree t, void f(char *str)){
    if(t==NULL)return;
    if(tree_type == RBT){
        if(IS_BLACK(t)){
            printf("Black: ");
        }
        else printf("Red: ");
    }
    f(t->key);
    tree_preorder(t->left,f);
    tree_preorder(t->right,f);
}

/**
 * changes the colour of the root to Black if it is Red
 * @param t is the tree whose root node is being checheck
   to see if Black or Red
 **/
tree root_to_black(tree t){
    if(IS_RED(t)){
        t->colour = BLACK;
    }
    return t;
}
        
/**
 * rotates the RBT to the right in order to fix any violations
 * @param r is the red black tree node that is being rotated to the right
 **/
static tree right_rotate(tree r){
    tree R = r; 
    tree temp = r;
    /*Changed root of tree to point to its left child */
    R = R->left;
    /*Left child of temp(original root) points to right child of new root */
    temp->left = R->right; 
    R->right = temp;
    return R;
}

/**
 * rotates the RBT to the left in order to fix any violations
 * @param r is the red black tree node that is being rotated to the left
 **/
static tree left_rotate(tree r){
    tree R = r;
    tree temp = r;
    R = R->right;
    temp->right = R->left;
    R->left = temp;
    return R;
}

/**
 * balances the red black tree by recouloring nodes to fix violations
 * @param t is the red black tree that needs to be balanced
 **/
static tree rbt_fix(tree r){
    
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

/**
 * inserts nodes into the tree
 * @param t is the tree into which the node is being inserted
 * @param str is the key which is being inserted into the tree
 **/
tree tree_insert(tree t,char *str){

    if(tree_search(t,str) == 1) {
        t->frequency++;
    }
    
    if(t == NULL){  
        t = emalloc(sizeof *t);   
        t->key = emalloc((strlen(str)+1) * sizeof(str[0]));
        strcpy(t->key, str);
        if(tree_type == RBT){
            t->colour = RED;
        }
        
        t->left = NULL;
        t->right = NULL;
    }
    
    else if(strcmp(t->key,str)>0){
        t->left = tree_insert(t->left, str);   
    }
    else if (strcmp(t->key, str) < 0){
        t->right = tree_insert(t->right, str);   
    }

    if(tree_type == RBT){
        t = rbt_fix(t);
    }
    return t;
}

/**
 * Traverses the tree writing a DOT description about connections, and
 * possibly colours, to the given output stream.
 *
 * @param t the tree to output a DOT description of.
 * @param out the stream to write the DOT output to.
 */
static void tree_output_dot_aux(tree t, FILE *out) {
    if(t->key != NULL) {
        fprintf(out, "\"%s\"[label=\"{<f0>%s:%d|{<f1>|<f2>}}\"color=%s];\n",
                t->key, t->key, t->frequency,
                (RBT == tree_type && RED == t->colour) ? "red":"black");
    }
    if(t->left != NULL) {
        tree_output_dot_aux(t->left, out);
        fprintf(out, "\"%s\":f1 -> \"%s\":f0;\n", t->key, t->left->key);
    }
    if(t->right != NULL) {
        tree_output_dot_aux(t->right, out);
        fprintf(out, "\"%s\":f2 -> \"%s\":f0;\n", t->key, t->right->key);
    }
}


/* -*- mode:c -*- */

/* These functions should be added to your tree.c file */

/**
 * Output a DOT description of this tree to the given output stream.
 * DOT is a plain text graph description language (see www.graphviz.org).
 * You can create a viewable graph with the command
 *
 *    dot -Tpdf < graphfile.dot > graphfile.pdf
 *
 * You can also use png, ps, jpg, svg... instead of pdf
 *
 * @param t the tree to output the DOT description of.
 * @param out the stream to write the DOT description to.
 */
void tree_output_dot(tree t, FILE *out) {
    fprintf(out, "digraph tree {\nnode [shape = Mrecord, penwidth = 2];\n");
    tree_output_dot_aux(t, out);
    fprintf(out, "}\n");
}

