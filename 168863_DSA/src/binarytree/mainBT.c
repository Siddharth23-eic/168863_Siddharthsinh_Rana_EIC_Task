#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "BT_TASK.h"

int32_t mainBT(){
    int32_t task, c;
    while((c = getchar()) != '\n' && c != EOF);
    
    while(1){
        printf("\nSelect which task to run: ");
        printf("\n1. Tree Array Creation \n2. Tree Linked List Creation \n3. Tree Array Traversal \n4. Tree Linked List Traversal \n5. Full Tree Operations\n");
        scanf("%d", &task);
        
        switch(task){
            case 0:
                printf("Exiting Binary tree tasks...\n");
                return 0;
            case 1:
                task1_treearr();
                break;
            case 2:
                task1_treeLL();
                break;
            case 3:
                task2_treearr_traversal();
                break;
            case 4:
                task2_treell_traversal();
                break;
            case 5:
                task3();
                break;
            default:
                printf("Wrong choice for a task\n");
            break;
        }
    }
    return 0;
}