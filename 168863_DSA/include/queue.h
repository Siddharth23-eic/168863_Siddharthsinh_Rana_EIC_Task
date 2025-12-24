/* Owner: Siddharthsinh Rana
*  Date: 23/12/2025
*  Topic: Queue(using Linked list)
*  Description: A common .h file for the supporting function for queue.
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include <stdbool.h>

// Node of the queue
typedef struct node {
    int32_t data;
    struct node *next;
} Node;

// Queue structure holding front & rear pointers
typedef struct {
    Node *front;
    Node *rear;
} Queue;

/* Queue Function Prototypes */

void initqueue(Queue *q);
bool isempty(Queue *q);
void enqueue(Queue *q, int32_t value);
int32_t dequeue(Queue *q);
int32_t peek(Queue *q);
void printQueue(Queue *q);
void freeQueue(Queue *q);

#endif
