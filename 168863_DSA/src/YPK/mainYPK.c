/* Owner: Siddharthsinh Rana
   Date: 2024-06-25
   Topic: YPK
   Description: Main file to run YPK related tasks
*/

#include <stdio.h>
#include <stdint.h>
#include "ypk_task.h"

int32_t mainYPK(){
    int32_t task;
    while(1){
        printf("\nSelect which YPK task to run: ");
        printf("\n0. Exit \n1. YPK Task 3(Preorder no recursion) \n2. YPK Task 4(postorder no recursion) \n3. YPK Task 5(Copy BST recursion) \n4. YPK Task 6(Compare BST recursion) \n5. YPK Task 7(insert node t as a left child of s in threaded binary tree): \n");
        scanf("%d", &task);
        
        switch(task){
            case 0:
                printf("Exiting YPK tasks...\n");
                return 0;
            case 1:
                ypk_task3();
                break;
            case 2:
                ypk_task4();
                break;
            case 3:
                ypk_task5();
                break;
            case 4:
                ypk_task6();
                break;
            case 5:
                ypk_task7();
                break;
            default:
                printf("Wrong choice for a task\n");
            break;
        }
    }
}