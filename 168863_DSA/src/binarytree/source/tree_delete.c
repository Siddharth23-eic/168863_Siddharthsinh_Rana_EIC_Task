#include <stdio.h>
#include <stdint.h>
#include "BT_TASK.h"
#include "binarytree.h"

void task3_tree_delete(void){
    Tree *root = NULL;
    int32_t n, val, del;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int32_t i = 0; i < n; i++) {
        scanf("%d", &val);
        root = bt_insert(root, val);
    }

    printf("Enter value to delete: ");
    scanf("%d", &del);

    root = bt_delete(root, del);

    printf("Inorder after deletion: ");
    bt_inorder(root);
    printf("\n");

    bt_free(root);
}