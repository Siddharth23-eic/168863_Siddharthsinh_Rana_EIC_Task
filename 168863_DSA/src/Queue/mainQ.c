#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "Qtasks.h"

int32_t mainQ(){
    int32_t task, c;
    printf("\nEnter which task to run: ");
    scanf("%d", &task);
    while((c = getchar()) != '\n' && c != EOF);

    switch(task){
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
    return 0;
}