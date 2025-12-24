#include <stdio.h>
#include <stdint.h>
#include "BT_TASK.h"
#include "binarytree.h"

void task3_tree_search(void){
    Tree *root = NULL;
    int32_t n, val, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int32_t i = 0; i < n; i++) {
        scanf("%d", &val);
        root = bt_insert(root, val);
    }

    printf("Enter value to search: ");
    scanf("%d", &key);

    if (bt_search(root, key))
        printf("Value found\n");
    else
        printf("Value not found\n");

    bt_free(root);
}