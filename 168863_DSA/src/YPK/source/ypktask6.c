/* Owner: Siddharthsinh Rana
   Date: 2024-06-29
   Topic: YPK
   Chapter 5 Task 6
   Description: Write a program to compare two binary search trees using recursion.
*/

#include <stdio.h>
#include <stdint.h>
#include "binarytree.h"
#include "ypk_task.h"

int32_t bt_compare(Tree *t1, Tree *t2){
    if(t1 == NULL && t2 == NULL){
        return 1;
    }
    if(t1 == NULL || t2 == NULL){
        return 0;
    }
    if(t1->data != t2->data){
        return 0;
    }
    return bt_compare(t1->left, t2->left) && bt_compare(t1->right, t2->right);
}

void ypk_task6(){
    Tree *t1 = NULL;
    Tree *t2 = NULL;

    int32_t result;
    int32_t m, n, val;

    printf("Enter number of nodes for first BST: ");
    scanf("%d", &m);
    printf("Enter elements for first BST:\n");
    for(int32_t i = 0; i < m; i++){
        scanf("%d", &val);
        t1 = bt_insert(t1, val);
    }
    
    printf("Enter number of nodes for second BST: ");
    scanf("%d", &n);
    printf("Enter elements for second BST:\n");
    for(int32_t i = 0; i < n; i++){
        scanf("%d", &val);
        t2 = bt_insert(t2, val);
    }

    result = bt_compare(t1, t2);
    if(result){
        printf("The two binary search trees are identical.\n");
    } else {
        printf("The two binary search trees are not identical.\n");
    }
}