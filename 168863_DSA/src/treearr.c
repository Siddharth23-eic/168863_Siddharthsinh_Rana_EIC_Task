#include <stdio.h>
#include "treearr.h"

/* Initialize tree */
void treearr_init(int32_t *size){
    *size = 0;
}

/* Insert node (level order) */
void treearr_insert(int32_t arr[], int32_t *size, int32_t data){
    if (*size >= TREEARR_MAX) {
        printf("Tree is full\n");
        return;
    }

    arr[*size] = data;
    (*size)++;
}

/* Traversals */
void treearr_inorder(int32_t arr[], int32_t size, int32_t index){
    if (index >= size)
        return;

    treearr_inorder(arr, size, 2 * index + 1);
    printf("%d ", arr[index]);
    treearr_inorder(arr, size, 2 * index + 2);
}

void treearr_preorder(int32_t arr[], int32_t size, int32_t index){
    if (index >= size)
        return;

    printf("%d ", arr[index]);
    treearr_preorder(arr, size, 2 * index + 1);
    treearr_preorder(arr, size, 2 * index + 2);
}

void treearr_postorder(int32_t arr[], int32_t size, int32_t index){
    if (index >= size)
        return;

    treearr_postorder(arr, size, 2 * index + 1);
    treearr_postorder(arr, size, 2 * index + 2);
    printf("%d ", arr[index]);
}
