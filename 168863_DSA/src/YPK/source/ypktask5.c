/* Owner: Siddharthsinh Rana
   Date: 2024-06-25
   Topic: YPK
   Chapter 5 Task 5
   Description: Write a program to copy a binary search tree using recursion.
*/

#include <stdio.h>
#include <stdint.h>
#include "binarytree.h"
#include "ypk_task.h"

void bt_copy(Tree *src, Tree **dest){
    if(src == NULL){
        *dest = NULL;
        return;
    }

    *dest = malloc(sizeof(Tree));
    (*dest)->data = src->data;

    bt_copy(src->left, &((*dest)->left));
    bt_copy(src->right, &((*dest)->right));
}

void ypk_task5(){
    Tree *root = NULL;
    Tree *copy_root = NULL;
    int32_t n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter total %d node values:\n", n);
    for(int32_t i = 0; i < n; i++){
        int32_t val;
        scanf("%d", &val);
        root = bt_insert(root, val);
    }

    bt_copy(root, &copy_root);

    printf("Original Tree Inorder Traversal: ");
    bt_inorder(root);
    printf("\n");

    printf("Copied Tree Inorder Traversal: ");
    bt_inorder(copy_root);
    printf("\n");

    return;
}