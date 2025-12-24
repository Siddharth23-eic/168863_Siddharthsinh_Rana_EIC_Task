#include <stdio.h>
#include <stdint.h>
#include "BT_TASK.h"
#include "binarytree.h"

void task1_treeLL(void){
    Tree *root = NULL;
    int32_t n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int32_t i = 0; i < n; i++) {
        scanf("%d", &val);
        root = bt_insert(root, val);
    }

    printf("The tree is(Traversed in inorder): \n");
    bt_inorder(root);
    printf("\n");

    bt_free(root);
    return;
}
