/* Owner: Siddharthsinh Rana
   Date: 2024-06-25
   Topic: YPK
   Chapter 5 Task 4
   Description: Write a program to travers a binary tree using postorder traversal method without recursion.
*/

#include <stdio.h>
#include <stdint.h>
#include "binarytree.h"
#include "ypk_task.h"

#define STACK_SIZE 100

void postorder_norec(Tree *root){
    if(root == NULL)
        return;
    Tree *stack1[STACK_SIZE];
    /* Using 2nd stack as in post order we have to traverse the left right and root */
    Tree *stack2[STACK_SIZE]; 
    int32_t top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while(top1 >= 0){
        Tree *node = stack1[top1--];
        stack2[++top2] = node;

        /* Push left */
        if(node->left)
            stack1[++top1] = node->left;
        
        /* Push right */
        if(node->right)
            stack1[++top1] = node->right;
    }
    while(top2 >= 0){
        Tree *node = stack2[top2--];
        printf("%d ", node->data);
    }
}

void ypk_task4(){
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

    printf("Postorder Traversal without recursion: ");
    postorder_norec(root);
    printf("\n");
    return;
}