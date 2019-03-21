/**
 * tree.h file for COSC242 assignment.
 * Written on Thursday the 13th of September
 * @author Joe Marshall marjo989
 * @author Rik Karmakar karri390
 * @author Kim Sharma shaki694
 **/

#ifndef TREE_H_
#define TREE_H_

typedef enum tree_e { BST, RBT } tree_t;
typedef struct tree *tree;

/**
 * To free any memory allocated to the Struct tree
 * @param t the tree to be freed
 * @return returns the tree after deallocating memory associated with it
 **/
extern tree tree_free(tree t);


/**
 * To perform inorder traversal of the tree
 * @param t the tree to be traversed in inorder fashion
 * @param void f function passed to tree_inorder
 * to print the root node of the tree
 **/
extern void tree_inorder(tree t, void f(int freq, char *str));


/**
 * To insert a given key into the tree
 * and balancing and fixing violations if
 * it is a RBT
 * @param t the tree in which insertion will be performed
 * @param *str the key to be inserted
 * @return returns the tree after insertion
 **/
extern tree tree_insert(tree t,char *str);


/**
 * Creates a new tree
 * @param type stores the type of the tree - RBT or BST
 * @return null
 **/
extern tree tree_new(tree_t type);


/**
 * To change the colour of the root node
 * of the RBT to black if it is red
 * @param t the RBT whose root node will be checked for colour
 * @return t the tree after fix up 
 **/
extern tree root_to_black(tree t);


/**
 * To perform preorder traversal of the tree
 * @param t the tree to be traversed in preorder fashion
 * @param void f function passed to tree_preorder
 * to print the root node of the tree
 **/
extern void tree_preorder(tree t,void f(int freq, char *str));


/**
 * Searches for a given key in the tree
 * @param t The tree to be searched
 * @param *key Key to be searched in the tree
 * @return returns 1 if the key is found, 0 if not
 **/
extern int tree_search(tree t,char *str);


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
extern void tree_output_dot(tree t, FILE *out);

#endif
