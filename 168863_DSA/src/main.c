#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t mainLL();
int32_t mainQ();
int32_t mainSt();
int32_t mainBT();
int32_t mainYPK();
int32_t mainCLL();
int32_t mainDLL();

int32_t main(){
    int32_t choice;

    while(1){
        printf("\nEnter a choice for the tasks\n");
        printf("0.EXIT\n1.LL\n2.QUEUE\n3.STACK\n4.BT\n5.YPK\n6.CLL:\n7.DLL\n");
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
            case 6:
                mainCLL();
                break;
            case 7:
                mainDLL();
                break;
            default:
                printf("Wrong choice\n");
                return 1;
        }
    }
    return 0;
}