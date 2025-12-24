#include <stdio.h>
#include <stdint.h>
#include "BT_TASK.h"
#include "binarytree.h"

void task2_treell_traversal(void)
{
    Tree *root = NULL;
    int32_t n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int32_t i = 0; i < n; i++) {
        scanf("%d", &val);
        root = bt_insert(root, val);
    }

    printf("Inorder: ");
    bt_inorder(root);

    printf("\nPreorder: ");
    bt_preorder(root);

    printf("\nPostorder: ");
    bt_postorder(root);

    printf("\n");

    bt_free(root);
}
