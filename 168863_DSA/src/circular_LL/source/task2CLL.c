/* Owner: Siddharthsinh Rana
    Date: 29-12-2025
    Topic : Circular Linked List
    Description: Sum of all even numbers in a circular linked list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "CLLtask.h"

int32_t task2CLL(void){
    Node* head = NULL;
    
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);
    insertAtEnd(&head, 30);
    
    printf("Circular Linked List: ");
    display(head);

    int32_t sum = 0;
    if(head == NULL){
        printf("The list is empty.\n");
        return 0;
    }
    Node* curr = head;
    do{
        if((curr->data % 2) == 0){
            sum += curr->data;
        }
        curr = curr->next;
    }while(curr != head);

    printf("Sum of all even numbers in the circular linked list: %d\n", sum);
    return 0;
}