#include <stdio.h>
#include "queue.h"
#include "Qtasks.h"

int32_t task2_3add1rem(void){
    int32_t count = 0;
    int32_t arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24};
    size_t len = sizeof(arr)/sizeof(arr[0]);
    Queue *q = malloc(sizeof(Queue));
    initqueue(q);

    for(int32_t i = 0; i < len; i++){
        enqueue(q, arr[i]);
        count++;
        if(count == 3){
            dequeue(q);
            count = 0;
        }
    }

    printQueue(&q);
    return 0;
}