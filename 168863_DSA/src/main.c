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
        printf("0.EXIT\n 1.LL\n 2.QUEUE\n 3.STACK\n 4.BT\n 5.YPK :\n");
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
                mainBT();
                break;
            case 5:
                mainYPK();
                break;
            default:
                printf("Wrong choice\n");
                return 1;
        }
    }
    return 0;
}