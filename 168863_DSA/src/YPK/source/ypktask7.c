/* Owner: Siddharthsinh Rana
   Date: 2024-06-29
   Topic: YPK
   Chapter 5 Task 7
   Description: Write a function to insert a node t as a left child of s in a threaded binary tree.
*/

#include <stdio.h>
#include <stdint.h>
#include "binarytree.h"
#include "ypk_task.h"

typedef struct node{
    int32_t data;
    struct node *left;
    struct node *right;
    int32_t lthread;
    int32_t rthread;
}TBT;

void insert_left(TBT *S, TBT *T){
    TBT *pred;

    /* T inherits all the left child of S */
    T->left = S->left;
    T->lthread = 1;

    /* Making S right child of T */
    T->right = S;
    T->rthread = 1;

    /* if p had predecessor, update it's right thread */
    if(S->lthread == 0){
        pred = S->left;
        if(pred != NULL && pred->rthread == 1){
            pred->right = T;
        }
    }
    /* Making T left child of P */
    S->left = T;
    S->lthread = 0;
}

void build_TBT(TBT **root, int32_t val){
    TBT *new_node = (TBT *)malloc(sizeof(TBT));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->lthread = 1;
    new_node->rthread = 1;

    if(*root == NULL){
        *root = new_node;
        return;
    }

    TBT *current = *root;
    TBT *parent = NULL;

    while(1){
        parent = current;
        if(val < current->data){
            if(current->lthread == 0){
                current = current->left;
            } else {
                insert_left(current, new_node);
                return;
            }
        } else {
            if(current->rthread == 0){
                current = current->right;
            } else {
                /* Insert as right child */
                new_node->right = current->right;
                new_node->rthread = 1;

                current->right = new_node;
                current->rthread = 0;
                return;
            }
        }
    }
}

void ypk_task7(){
    TBT *root = NULL;
    int32_t n, val;

    printf("Enter number of nodes for Threaded Binary Tree: ");
    scanf("%d", &n);
    printf("Enter elements for Threaded Binary Tree:\n");
    for(int32_t i = 0; i < n; i++){
        scanf("%d", &val);
        build_TBT(&root, val);
    }
}