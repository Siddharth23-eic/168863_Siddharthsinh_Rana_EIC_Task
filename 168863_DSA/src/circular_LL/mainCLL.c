#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "CLLtask.h"

int32_t mainCLL(){
    int32_t task;

    while(1){
        printf("Select which task to run: ");
        printf("\n0. Exit \n1. Insert/Delete \n2. Sum of all even num in CLL\n");
        scanf("%d", &task);
        
        switch(task){
            case 0:
                printf("Exiting CLL tasks...\n");
                return 0;
            case 1:
                task1CLL();
                break;
            case 2:
                task2CLL();
                break;

            default:
                printf("Wrong choice for a task\n");
                break;
        }
    }
    return 0;
}