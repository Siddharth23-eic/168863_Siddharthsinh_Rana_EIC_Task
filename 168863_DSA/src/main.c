#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t mainLL();
int32_t mainQ();
int32_t mainSt();

int32_t main(){
    int32_t choice;

    while(1){
        printf("\nEnter a choice for the tasks\n");
        printf("0.EXIT 1.LL 2.Q 3.St 4.BT :\n");
        scanf("%d", &choice);
        
        switch(choice){
            case 0:
                printf("Exiting...\n");
                return 0;
            case 1:
                mainLL();
                break;
            case 2:
                mainQ();
                break;
            case 3:
                mainSt();
                break;
            case 4:
                break;
            default:
                printf("Wrong choice\n");
                return 1;
        }
    }
    return 0;
}