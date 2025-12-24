#include <stdio.h>
#include "BT_TASK.h"
#include "treearr.h"

void task2_treearr_traversal(void)
{
    printf("Inorder: ");
    treearr_inorder(0);

    printf("\nPreorder: ");
    treearr_preorder(0);

    printf("\nPostorder: ");
    treearr_postorder(0);

    printf("\n");
}
