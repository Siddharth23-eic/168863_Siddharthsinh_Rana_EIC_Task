#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "Qtasks.h"

int32_t mainQ(){
    int32_t task, c;
    while((c = getchar()) != '\n' && c != EOF);
    
    while(1){
        printf("\nSelect which task to run: ");
        printf("\n1. Palindrome \n2. 3 Add 1 Rem \n3. ToDo \n");
        scanf("%d", &task);
        
        switch(task){
            case 0:
                printf("Exiting Queue tasks...\n");
                return 0;
            case 1:
                task1_palindrome();
                break;
            case 2:
                task2_3add1rem();
                break;
            case 3:
                task3_todo();
                break;
            default:
                printf("Wrong choice for a task\n");
            break;
        }
    }
}