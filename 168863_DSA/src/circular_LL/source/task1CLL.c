/* Owner: Siddharthsinh Rana
    Date: 29-12-2025
    Topic : Circular Linked List
    Description:  Complete the missing code and apply coding standards.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "CLLtask.h"

int32_t task1CLL(void){
    struct Node* head = NULL;
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtBeginning(&head, 4);
    
    printf("Circular Linked List: ");
    display(head);
    
    deleteNode(&head, 2);
    printf("Circular Linked List after deleting 2: ");
    display(head);
    return 0;
}