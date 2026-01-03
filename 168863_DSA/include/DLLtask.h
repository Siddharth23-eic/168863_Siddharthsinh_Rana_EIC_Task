#ifndef DLL_TASK_H
#define DLL_TASK_H

#include <stdint.h>
typedef struct DLLNode {
    int data;
    struct DLLNode* prev;
    struct DLLNode* next;
} DLL;

/* Adds new node at the end of doubly linked list */
DLL* d_append(DLL **s, int32_t num);

/* Adds a new node at the beginning of the doubly linked list */
DLL* d_addatbeg(DLL **s, int32_t num);

/* Adds a new node after the specified number of nodes */
DLL* d_addafter(DLL *q, int32_t loc, int32_t num);

/* Display the content of the doubly Linked list */
void d_display(DLL *s);

/* Count the number of nodes present in the doubly linked list */
int32_t d_count(DLL *s);

/* Deletes the specified  node form the doubly Linked list */
DLL* d_delete(DLL **s, int32_t num);

/* Tasks */
int32_t task1DLL(void);
int32_t task2DLL(void);

#endif