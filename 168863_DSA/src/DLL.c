/* Owner: Siddharthsinh Rana
    Date: 29-12-2025
    Topic : Doubly Linked List
    Description: Common function implementation for doubly linked list operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "DLLtask.h"

/* Adds new node at the end of doubly linked list */
DLL* d_append(DLL **s, int32_t num){
    DLL* newNode = (DLL*)malloc(sizeof(DLL));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = num;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    /* If empty list then first node will be newNode */
    if(*s == NULL){
        *s = newNode;
    }else{ /* Traverse to the end and append */
        DLL* temp = *s;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return newNode;
}

/* Adds a new node at the beginning of the doubly linked list */
DLL* d_addatbeg(DLL **s, int32_t num){
    DLL* newNode = (DLL*)malloc(sizeof(DLL));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = num;
    newNode->next = *s;
    newNode->prev = NULL;
    if(*s != NULL){
        (*s)->prev = newNode;
    }
    *s = newNode;
    return newNode;
}

/* Adds a new node after the specified number of nodes */
DLL* d_addafter(DLL *q, int32_t loc, int32_t num){
    if(q == NULL){
        printf("The list is empty. Cannot add after location %d\n", loc);
        return NULL;
    }
    DLL* temp = q;
    for(int32_t i = 0; i < loc; i++){
        if(temp == NULL){
            printf("Location %d exceeds the list length\n", loc);
            return NULL;
        }
        temp = temp->next;
    }
    DLL* newNode = (DLL*)malloc(sizeof(DLL));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = num;
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != NULL){
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return newNode;
}

/* Display the content of the doubly Linked list */
void d_display(DLL *s){
    DLL* temp = s;
    if(temp == NULL){
        printf("The list is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Count the number of nodes present in the doubly linked list */
int32_t d_count(DLL *s){
    int32_t count = 0;
    DLL* temp = s;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}   

/* Deletes the specified  node form the doubly Linked list */
DLL* d_delete(DLL **s, int32_t num){
    if(*s == NULL){
        printf("The list is empty. Cannot delete %d\n", num);
        return NULL;
    }
    DLL* temp = *s;
    while(temp != NULL){
        if(temp->data == num){
            if(temp->prev != NULL){
                temp->prev->next = temp->next;
            }else{
                *s = temp->next; /* Deleting head node */
            }
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }
            free(temp);
            return *s;
        }
        temp = temp->next;
    }
    printf("Node with data %d not found in the list.\n", num);
    return *s;
}