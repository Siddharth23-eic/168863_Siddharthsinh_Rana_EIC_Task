/* Owner: Siddharthsinh Rana
    Date: 29-12-2025
    Topic : Doubly Linked List
    Description: Write a program to implement doubly linked list as circular linked list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "DLLtask.h"

DLL *dc_append(DLL **headref, int32_t num){
    DLL *new_node = (DLL *)malloc(sizeof(DLL));
    DLL *last = *headref;
    new_node->data = num;
    new_node->next = new_node;
    new_node->prev = new_node;

    if(*headref == NULL){
        *headref = new_node;
        return new_node;
    }
    while(last->next != *headref){
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
    new_node->next = *headref;
    (*headref)->prev = new_node;
    return new_node;
}

void dc_display(DLL *head){
    DLL *temp = head;
    if(temp == NULL){
        printf("List is empty.\n");
        return;
    }
    printf("Doubly circular linked list elements: \n");
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("\n");
}

DLL *dc_delete(DLL **headref, int32_t num){
    if(*headref == NULL){
        printf("List is empty.\n");
        return NULL;
    }
    DLL *curr = *headref;
    do{
        if(curr->data == num){
            /*single node*/
            if(curr->next == curr && curr->prev == curr){
                free(curr);
                *headref = NULL;
                return NULL;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            if(curr == *headref)
                *headref = curr->next;
            
            free(curr);
            return *headref;
        }
        curr = curr->next;
    }while(curr != *headref);

    printf("Node %d not found\n", num);
    return *headref;
}

int32_t task2DLL(void){
    DLL* head = NULL;

    printf("Testing Circular Append function:\n");
    dc_append(&head, 10);
    dc_append(&head, 20);
    dc_append(&head, 30);
    dc_append(&head, 40);
    printf("No of elements in Circular DLL after dc_append:\n");
    dc_display(head);

    printf("\nTesting Circular Delete function:");
    dc_delete(&head, 20); /* Delete node with data 20 */
    printf("\nNo of elements in Circular DLL after deletion:\n");
    dc_display(head);

    printf("\n");
    return 0;
}