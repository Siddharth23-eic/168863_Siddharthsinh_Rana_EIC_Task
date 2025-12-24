#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "LLtask.h"

int32_t mainLL(){
    int32_t task;
    printf("Enter which task to run: ");
    scanf("%d", &task);

    switch(task){
        case 1:
            task1_count();
            break;
        case 2:
            task2_getnth();
            break;
        case 3:
            task3_deletelist();
            break;
        case 4:
            task4_pop();
            break;
        case 5: 
            task5_insertnth();
            break;
        case 6:
            task6_sortedinsert();
            break;
        case 7:
            task7_insertsort();
            break;
        case 8:
            task8_append();
            break;
        case 9:
            task9_removedup();
            break;
        case 10:
            task10_movenode();
            break;

        default:
            printf("Wrong choice for a task\n");
            break;
    }
    return 0;
}