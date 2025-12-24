/* Owner: Siddharthsinh Rana
   Date: 2024-06-25
   Topic: YPK
   Chapter 5 Task 3
   Description: Write a program to travers a binary tree using preorder traversal method without recursion.
*/

#include <stdio.h>
#include <stdint.h>
#include "binarytree.h"
#include "ypk_task.h"

#define STACK_SIZE 100

void preorder_norec(Tree *root){
    if(root == NULL)
        return;
    
    Tree *stack[STACK_SIZE];
    int32_t top = -1;

    stack[++top] = root;

    while(top >= 0){
        Tree *node = stack[top--];
        printf("%d ", node->data);

        /* Push right */
        if(node->right)
            stack[++top] = node->right;
        
        /* Push left */
        if(node->left)
            stack[++top] = node->left;
    }
}

void ypk_task3(){
    Tree *root = NULL;
    int32_t n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter total %dnode values:\n", n);
    for(int32_t i = 0; i < n; i++){
        int32_t val;
        scanf("%d", &val);
        root = bt_insert(root, val);
    }

    printf("Preorder Traversal without recursion: ");
    preorder_norec(root);
    printf("\n");
    return;
}