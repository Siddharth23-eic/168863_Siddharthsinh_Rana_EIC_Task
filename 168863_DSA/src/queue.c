#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* Initialize queue */
void initqueue(Queue *q) {
    q->front = NULL;
    q->rear  = NULL;
}

/* Check if queue is empty */
bool isempty(Queue *q) {
    return (q->front == NULL);
}

/* Insert element at rear */
void enqueue(Queue *q, int32_t value) {
    Node *temp = malloc(sizeof(Node));
    if (!temp) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    temp->data = value;
    temp->next = NULL;

    /* If queue is empty, both front & rear become new node */
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    /* Attach new node to rear and update rear pointer */
    q->rear->next = temp;
    q->rear = temp;
}

/* Remove element from front */
int32_t dequeue(Queue *q) {
    if (isempty(q)) {
        printf("Queue underflow! Nothing to dequeue.\n");
        return -1;
    }

    Node *temp = q->front;
    int32_t value = temp->data;

    q->front = q->front->next;

    /* If queue becomes empty, rear must be NULL */
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

/* Peek at the front element without removing */
int32_t peek(Queue *q) {
    if (isempty(q)) {
        printf("Queue is empty! Nothing to peek.\n");
        return -1;
    }
    return q->front->data;
}

/* Print queue for debugging */
void printQueue(Queue *q) {
    Node *curr = q->front;

    printf("Queue: ");
    while (curr != NULL) {
        printf("%d%s", curr->data, curr->next ? " -> " : "");
        curr = curr->next;
    }
    printf("\n");
}

/* Free all nodes in queue */
void freeQueue(Queue *q) {
    Node *curr = q->front;
    Node *next;

    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }

    q->front = q->rear = NULL;
}
