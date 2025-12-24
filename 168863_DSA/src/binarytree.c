#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

/* Insertion in binary tree */

Tree *bt_insert(Tree *root, int32_t data){
    if(root == NULL){
        Tree *node = malloc(sizeof(Tree));
        node->data = data;
        node->left = node->right = NULL;
        return node;
    }

    if(data < root->data)
        root->left = bt_insert(root->left, data);
    else
        root->right = bt_insert(root->right, data);

    return root;
}

/* Search */
int32_t bt_search(Tree *root, int32_t data){
    if(root == NULL)
        return 0;
    if(root->data == data)
        return 1;
    if(data < root->data)
        return bt_search(root->left, data);
    else
        return bt_search(root->right, data);
}

/* Traversal */
void bt_inorder(Tree *root){
    if(!root) return;
    bt_inorder(root->left);
    printf("%d", root->data);
    bt_inorder(root->right);
}

void bt_preorder(Tree *root){
    if(!root) return;
    printf("%d", root->data);
    bt_preorder(root->left);
    bt_preorder(root->right);
}

void bt_postorder(Tree *root){
    if(!root) return;
    bt_postorder(root->left);
    bt_postorder(root->right);
    printf("%d", root->data);
}

static Tree *find_min(Tree *root){
    while(root && root->left)
        root = root->left;
    return root;
}

Tree *bt_delete(Tree *root, int32_t data){
    if(!root)
        return NULL;
    
    if(data < root->data)
        root->left = bt_delete(root->left, data);
    else if(data > root->data)
        root->right = bt_delete(root->right, data);
    else{
        /* Node found */
        if(!root->left){
            Tree *temp = root->right;
            free(root);
            return temp;
        }
        else if(!root->right){
            Tree *temp = root->right;
            free(root);
            return temp;
        }
        Tree *temp = find_min(root->right);
        root->data = temp->data;
        root->right = bt_delete(root->right, temp->data);
    }
    return root;
}

/* Clean up */
void bt_free(Tree *root){
    if(!root) return;
    bt_free(root->left);
    bt_free(root->right);
    free(root);
}