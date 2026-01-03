#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "DLLtask.h"

int32_t mainDLL(){
    int32_t task;

    while(1){
        printf("Select which task to run: ");
        printf("\n0. Exit \n1. Test different fucntions \n2.Implement DLL as CLL\n");
        scanf("%d", &task);
        
        switch(task){
            case 0:
                printf("Exiting CLL tasks...\n");
                return 0;
            case 1:
                task1DLL();
                break;
            case 2:
                task2DLL();
                break;

            default:
                printf("Wrong choice for a task\n");
                break;
        }
    }
    return 0;
}