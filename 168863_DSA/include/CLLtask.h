#ifndef CIRLL_TASK_H
#define CIRLL_TASK_H

#include <stdint.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Task 1: Complete the code */
int32_t task1CLL(void);

/* Sum of all even number stored in a circular linked list */
int32_t task2CLL(void);


/* Supportive function */
Node* createNode(int32_t data);
void insertAtBeginning(Node **head, int32_t data);
void insertAtEnd(Node **head, int32_t data);
void deleteNode(Node **head, int32_t data);
void display(Node *head);

#endif
