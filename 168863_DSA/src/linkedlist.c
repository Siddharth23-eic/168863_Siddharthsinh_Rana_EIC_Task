#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void push_node(Node **headref, int32_t data){
   struct node *newnode = malloc(sizeof(struct node));
   newnode->data = data;
   newnode->next = NULL;

   /* Checking list is empty */
   if(*headref == NULL){
      *headref = newnode;
      return;
   }

   /* Traverse to the end */
   struct node* curr = *headref;
   while(curr->next != NULL){
      curr = curr->next;
   }
   curr->next = newnode;
}

void printlist(Node *head){
    while (head){
        printf("%d%s", head->data, head->next ? "->" : "");
        head = head->next;
    }
    printf("\n");
}

void freelist(Node *head){
    Node *tmp;
    while (head){
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void build_list(Node **head){
    int32_t n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter total %d elements:\n",n);
    for (int32_t i = 0; i < n; i++) {
        scanf("%d", &value);
        push_node(head, value);
    } 
}

/* Inserts DATA into a sorted list (allocates new node) */
void sortedinsert(Node** headref, int32_t data){
    Node *newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;

    Node* curr = *headref;
    Node* prev = NULL;

    /* Insert at head */
    if(curr == NULL || curr->data >= data){
        newnode->next = curr;
        *headref = newnode;
        return;
    }

    /* Find position */
    while(curr != NULL && curr->data < data){
        prev = curr;
        curr = curr->next;
    }

    prev->next = newnode;
    newnode->next = curr;
}