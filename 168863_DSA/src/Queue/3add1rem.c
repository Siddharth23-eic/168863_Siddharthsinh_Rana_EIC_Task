#include <stdio.h>
#include <stdint.h>
#include "queue.h"

int32_t main(){
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

    printqueue(&q);
    return 0;
}