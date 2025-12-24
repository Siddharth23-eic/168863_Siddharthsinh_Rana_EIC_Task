#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdint.h>

/* Binary Tree Node */
typedef struct Node {
    int32_t data;
    struct Node *left;
    struct Node *right;
} Tree;

/* Core Operations */
Tree* bt_insert(Tree *root, int32_t data);
int32_t bt_search(Tree *root, int32_t data);
Tree* bt_delete(Tree *root, int32_t data);

/* Traversals */
void bt_inorder(Tree *root);
void bt_preorder(Tree *root);
void bt_postorder(Tree *root);

/* Utility */
void bt_free(Tree *root);

#endif
