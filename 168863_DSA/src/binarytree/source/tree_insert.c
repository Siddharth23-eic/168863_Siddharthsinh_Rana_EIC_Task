#include <stdio.h>
#include <stdint.h>
#include "BT_TASK.h"
#include "binarytree.h"

void task3_tree_insert(void)
{
    Tree *root = NULL;
    int32_t n, val, newval;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int32_t i = 0; i < n; i++) {
        scanf("%d", &val);
        root = bt_insert(root, val);
    }

    printf("Enter value to insert: ");
    scanf("%d", &newval);

    root = bt_insert(root, newval);

    printf("Inorder after insertion: ");
    bt_inorder(root);
    printf("\n");

    bt_free(root);
}
