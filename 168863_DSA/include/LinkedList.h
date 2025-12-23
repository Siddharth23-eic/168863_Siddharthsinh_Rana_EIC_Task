#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdint.h>

typedef struct node{
    int32_t data;
    struct node* next;
}Node;

void printlist(Node *head);
void push_node(Node **headref, int32_t data);
void freelist(struct node* head);
void build_list(Node **head);

#endif