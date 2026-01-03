#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "CLLtask.h"

Node* createNode(int32_t data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = newNode; /* Point to itself to make it circular */
    return newNode;
}

void insertAtBeginning(Node **head, int32_t data){
    Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
    }else{
        Node* temp = *head;
        while(temp->next != *head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtEnd(Node **head, int32_t data){
    Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
    }else{
        Node* temp = *head;
        while(temp->next != *head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void deleteNode(Node **head, int32_t data){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    Node *curr = *head, *prev = NULL;
    do{
        if(curr->data == data){
            if(prev == NULL){ /* Deleting Head node */
                Node* temp = *head;

                /* Only one node */
                if(curr->next == *head){
                    free(*head);
                    *head = NULL;
                    return;
                }
                
                /* Find last node */
                while(temp->next != *head){
                    temp = temp->next;
                }
                temp->next = curr->next;
                *head = curr->next;
                free(curr);
                return;
            }
            /* Deleting non-head node */
            else{
                prev->next = curr->next;
                free(curr);
                return;
            }
        }
        prev = curr;
        curr = curr->next;
    }while(curr != *head);
    printf("Node with data %d not found\n", data);
}

void display(Node *head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("(head: %d)\n", head->data);
}