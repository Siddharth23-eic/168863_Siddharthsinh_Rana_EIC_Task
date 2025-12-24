#include <stdio.h> 
#include <stdint.h> 
#include "queue.h"
#include "Qtasks.h" 

char exists(Queue *q, int32_t val){ 
    Node* curr = q->front; 
    while(curr != NULL){ 
        if(curr->data == val) 
            return '1'; 
        curr = curr->next; 
    } 
    return '0'; 
} 

int32_t task3_todo(){ 
    Queue *q = malloc(sizeof(Queue)); 
    initqueue(q); 
    
    int32_t value; 
    int32_t count = 0; 
    while(count < 10){ 
        scanf("%d", &value); 
        
        /* Check if the value exists in the list */ 
        if(exists(q, value) == '0'){ 
            enqueue(q, value); 
        } 
        count++; 
    } 
    
    printQueue(q);

    freeQueue(q);
    free(q);
    
    return 0; 
}
