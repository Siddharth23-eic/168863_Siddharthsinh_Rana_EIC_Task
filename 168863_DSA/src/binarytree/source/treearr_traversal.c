#include <stdio.h>
#include <stdint.h>
#include "BT_TASK.h"
#include "treearr.h"

void task2_treearr_traversal(void){
    int32_t treearr[TREEARR_MAX];
    int32_t treearr_size;
    int32_t n, val;

    treearr_init(&treearr_size);

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int32_t i = 0; i < n; i++){
        scanf("%d", &val);
        treearr_insert(treearr, &treearr_size, val);
    }

    printf("Array tree traversals:\n");
    printf("Inorder: ");
    treearr_inorder(treearr, treearr_size, 0);

    printf("\nPreorder: ");
    treearr_preorder(treearr, treearr_size, 0);

    printf("\nPostorder: ");
    treearr_postorder(treearr, treearr_size, 0);

    printf("\n");
    return;
}
