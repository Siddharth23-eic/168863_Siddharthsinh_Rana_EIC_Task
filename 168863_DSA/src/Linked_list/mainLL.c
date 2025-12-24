#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "LLtask.h"

int32_t mainLL(){
    int32_t task;

    while(1){
        printf("Select which task to run: ");
        printf("\n1. Count \n2. Get Nth \n3. Delete List \n4. Pop \n5. Insert Nth \n6. Sorted Insert \n7. Insert Sort \n8. Append \n9. Remove Duplicates \n10. Move Node\n");
        scanf("%d", &task);
        
        switch(task){
            case 0:
                printf("Exiting LL tasks...\n");
                return 0;
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
    }
    return 0;
}