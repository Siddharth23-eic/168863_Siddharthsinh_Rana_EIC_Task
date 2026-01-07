/* Owner: Siddharthsinh Rana
   Date: 05-02-2026
   Topic: Queue takwaway task
   Description: main file to run the queue tasks.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priorityQueue.h"

#define BUF_SIZE 1024

int32_t main(){
    PQ pq;
    PQ_init(&pq);

    char choice;
    char name[128];
    int32_t priority;
    char buffer[BUF_SIZE];

    while(1){
        printf("\n Current patient queue: \n");
        if(PQ_toString(&pq, buffer, sizeof(buffer)) >= 0){
            printf("%s", buffer);
        } else{
            printf("{}");
        }

        printf(PQ_isEmpty(&pq) ? " (empty)\n" : " (not empty)\n");
        printf("N)ew F)ront U)pgrade P)rocess C)lear Q)uit? ");
        if(scanf(" %c", &choice) != 1){
            printf("\nInput error.\n");
            break;
        }

        switch(choice){
            case 'N':
            case 'n':
                printf("Name? ");
                if(scanf("%127s", name) != 1){
                    break;
                }
                printf("Priority? ");
                if(scanf("%d", &priority) != 1){
                    break;
                }
                PQ_newPT(&pq, name, priority);
                break;

            case 'F':
            case 'f':
                if(!PQ_isEmpty(&pq)){
                    printf("%s (priority %d)\n", PQ_frontName(&pq), PQ_frontPriority(&pq));
                }
                break;
            
            case 'U':
            case 'u':
                printf("Name? ");
                if(scanf("%127s", name) != 1){
                    break;
                }
                printf("Priority? ");
                if(scanf("%d", &priority) != 1){
                    break;
                }
                PQ_upgradePT(&pq, name, priority);
                break;
            
            case 'P':
            case 'p':
                char *processed = PQ_processPT(&pq);
                if(processed){
                    printf("Processing patient: \"%s\"\n", processed);
                    free(processed);
                }
                break;

            case 'C':
            case 'c':
                PQ_clear(&pq);
                break;

            case 'Q':
            case 'q':
                PQ_free(&pq);
                printf("Exiting...\n");
                return 0;

            default:
            printf("Invalid choice.\n");
            break;
        }
    }

    PQ_free(&pq);
}
