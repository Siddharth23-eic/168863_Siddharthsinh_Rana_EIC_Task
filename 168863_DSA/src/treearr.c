#include <stdio.h>
#include <stdint.h>
#include "treearr.h"

/* Global storage */
int32_t treearr[TREEARR_MAX];
int32_t treearr_size = 0;

/* Initialize */
void treearr_init(void)
{
    treearr_size = 0;
}

/* Insert (level order) */
void treearr_insert(int32_t data)
{
    if (treearr_size >= TREEARR_MAX) {
        printf("Array tree full\n");
        return;
    }
    treearr[treearr_size++] = data;
}

/* Search (linear) */
int32_t treearr_search(int32_t data)
{
    for (int32_t i = 0; i < treearr_size; i++) {
        if (treearr[i] == data)
            return 1;
    }
    return 0;
}

/* Delete (replace with last node) */
void treearr_delete(int32_t data)
{
    for (int32_t i = 0; i < treearr_size; i++) {
        if (treearr[i] == data) {
            treearr[i] = treearr[treearr_size - 1];
            treearr_size--;
            return;
        }
    }
    printf("Element not found\n");
}

/* Traversals */
void treearr_inorder(int32_t index)
{
    if (index >= treearr_size)
        return;

    treearr_inorder(2 * index + 1);
    printf("%d ", treearr[index]);
    treearr_inorder(2 * index + 2);
}

void treearr_preorder(int32_t index)
{
    if (index >= treearr_size)
        return;

    printf("%d ", treearr[index]);
    treearr_preorder(2 * index + 1);
    treearr_preorder(2 * index + 2);
}

void treearr_postorder(int32_t index)
{
    if (index >= treearr_size)
        return;

    treearr_postorder(2 * index + 1);
    treearr_postorder(2 * index + 2);
    printf("%d ", treearr[index]);
}
