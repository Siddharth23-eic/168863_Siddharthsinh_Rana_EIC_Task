#include <stdio.h>
#include <stdint.h>
#include "BT_TASK.h"
#include "binarytree.h"

void task3(void){
    Tree *root = NULL;
    int32_t n, val;

    /* Create tree */
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int32_t i = 0; i < n; i++) {
        scanf("%d", &val);
        root = bt_insert(root, val);
    }

    /* Search */
    printf("Enter value to search: ");
    scanf("%d", &val);

    if (bt_search(root, val))
        printf("Value found\n");
    else
        printf("Value not found\n");

    /* Insert */
    printf("Enter value to insert: ");
    scanf("%d", &val);
    root = bt_insert(root, val);

    printf("Inorder after insertion: ");
    bt_inorder(root);
    printf("\n");

    /* Delete */
    printf("Enter value to delete: ");
    scanf("%d", &val);
    root = bt_delete(root, val);

    printf("Inorder after deletion: ");
    bt_inorder(root);
    printf("\n");

    /* Cleanup */
    bt_free(root);
    return;
}
