/* Owner: Siddharthsinh Rana
 * Date : 02-01-2026
 * Topic: All takeaway tasks
 * Description: The global main file
*/

#include <stdio.h>
#include <stdint.h>

int32_t mainLL();

int32_t main(){
    int32_t choice;

    printf("Enter \n 0. Exit\n 1. LLTakeaway\n");
    scanf("%d", &choice);

    if(choice == 0){
        printf("Exiting.....");
        return 0;
    }

    switch (choice){
    case 1:
        mainLL();
        break;
    
    default:
        printf("Wrong choice");
        break;
    }

    return 0;
}