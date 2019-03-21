#ifndef TREE_H_
#define TREE_H_

typedef enum tree_e { BST, RBT } tree_t;
typedef struct tree *tree;

/**
 * Memory allocated is being deallocated at the end of the program
 * @param t is the tree that needs its memory deallocated
 **/
extern tree tree_free(tree t);

/**
 * prints the nodes of the tree using Inorder traversal
 * @param t is the tree whose nodes are to be traversed
 * @param void f(char *str) is a method being passed which
 prints out the node
**/
extern void tree_inorder(tree t, void f(char *str));

/**
 * inserts nodes into the tree
 * @param t is the tree into which the node is being inserted
 * @param str is the key which is being inserted into the tree
 **/
extern tree tree_insert(tree t,char *str);

/**
 * creates a new tree of a specified type - RBT or BST
 * @param type is the type of desired tree
 * RBT for a Red Black Tree
 * BST for a Binary Search Tree
 **/
extern tree tree_new(tree_t type);

/**
 * changes the colour of the root to Black if it is Red
 * @param t is the tree whose root node is being checheck
 to see if Black or Red
**/
extern tree root_to_black(tree t);

/**
 * prints the nodes of the tree using Preorder traversal
 * @param t is the tree whose nodes are to be traversed
 * @param void f(char *str) is a method being passed which
 prints out the node
**/
extern void tree_preorder(tree t,void f(char *str));

/**
 * searches the tree and returns 1 if the key is present
 * @param t is the tree being passed
 * @param key is the character to be searched in the tree
 **/
extern int tree_search(tree t,char *str);

#endif
