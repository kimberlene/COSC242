/**
 * tree.c file for COSC242 assignment.
 * Written on Thursday the 13th of September
 * @author Joe Marshall marjo989
 * @author Rik Karmakar karri390
 * @author Kim Sharma shaki694
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "mylib.h"

/*Macro functions to check the colour of the RBT node */
#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour))
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour))

/*Enumerated type variable, to store the colour of the RBT node */
typedef enum {RED,BLACK} tree_colour;

static tree_t tree_type;

/**
 * Struct for tree node
 * *key: array of character pointers of the value in the node
 * colour: stores the colour of the RBT node
 * Frequecny: Stores the number of duplicate nodes
 * left: left subtree
 * right: right subtree
 **/
struct tree {
    char *key;
    tree_colour colour;
    int frequency;
    tree left;
    tree right;

};

/**
 * Creates a new tree
 * @param type stores the type of the tree - RBT or BST
 * @return null
 **/
tree tree_new(tree_t type){
    tree_type = type;
    return NULL;
 }

/**
 * Searches for a given key in the tree
 * @param t The tree to be searched
 * @param *key Key to be searched in the tree
 * @return returns 1 if the key is found, 0 if not
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
 * To free any memory allocated to the Struct tree
 * @param t the tree to be freed
 * @return returns the tree after deallocating memory associated with it
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
 * To perform inorder traversal of the tree
 * @param t the tree to be traversed in inorder fashion
 * @param void f function passed to tree_inorder
 * to print the root node of the tree
 **/
void tree_inorder(tree t, void f(int freq, char *str)){
    
    if(t == NULL){
        return;
    }
    tree_inorder(t->left,f);
    f(t->frequency, t->key);
    tree_inorder(t->right,f);
}
    
        
/**
 * To perform preorder traversal of the tree
 * @param t the tree to be traversed in preorder fashion
 * @param void f function passed to tree_preorder
 * to print the root node of the tree
 **/
void tree_preorder(tree t, void f(int freq, char *str)){
    if(t==NULL){
        return;
    }
    f(t->frequency, t->key);
    tree_preorder(t->left,f);
    tree_preorder(t->right,f);
}
/**
 * To change the colour of the root node
 * of the RBT to black if it is red
 * @param t the RBT whose root node will be checked for colour
 * @return t the tree after fix up 
 **/
tree root_to_black(tree t){
    if(IS_RED(t)){
        t->colour = BLACK;
    }
    return t;
}

/**
 * Static function to right rotate a RBT
 * @param r The rbt which needs right rotation
 * @return returns the tree after right rotation
 **/
static tree right_rotate(tree r){
    tree R = r; 
    tree temp = r;
    R = R->left; 
    temp->left = R->right; 
    R->right = temp;
    return R;
}

/**
 * Static function to left rotate a RBT
 * @param r The rbt which needs left rotation
 * @return returns the tree after left rotation
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
 * Static function to balance and recolour nodes
 * of RBT to fix violations
 * @param r the RBT which needs to be fixed
 * @return returns the RBT after fixing violations
 * and balancing it.
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
    /**Ensure that the root node is always black.*/
    if(IS_RED(r)){
        r->colour = BLACK;
    }
    return r;
}

/**
 * To insert a given key into the tree
 * and balancing and fixing violations if
 * it is a RBT
 * @param t the tree in which insertion will be performed
 * @param *str the key to be inserted
 * @return returns the tree after insertion
 **/
tree tree_insert(tree t,char *str){
    
        if(t == NULL){  
        t = emalloc(sizeof *t);   
        t->key = emalloc((strlen(str)+1) * sizeof(str[0]));
        strcpy(t->key, str);
        if(tree_type == RBT){
            t->colour = RED;
        }
        
        t->left = NULL;
        t->right = NULL;
        t->frequency = 1;
    }
    
 
    else if(strcmp(t->key,str)>0){
        t->left = tree_insert(t->left, str);   
    }else if (strcmp(t->key, str) < 0){
        t->right = tree_insert(t->right, str);   
    } else {
        t->frequency++;
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

