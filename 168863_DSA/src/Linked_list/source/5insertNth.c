/* Owner: Siddharthsinh Rana 
* Task: Data Structures 
* Created Date: 09/12/2025 
* Topic: Linked list 
* Description: Function InsertNth() which can insert a new node at any index within a list. 
* Push() is similar, but can only insert a node at the head end of the list (index 0). 
* The caller may specify any index in the range [0..length], and the new node should be inserted so as to be at that index. 
*/ 

#include <stdio.h> 
#include <stdint.h> 
#include <stdlib.h>
#include "LinkedList.h"
#include "LLtask.h" 

void insert_at_n(Node **headref, int32_t index, int32_t data){
    Node *newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;

    Node *prev = NULL;
    Node *curr = *headref;

    if (index == 0){
        newnode->next = curr;
        *headref = newnode;
        return;
    }

    for (int32_t i = 0; i < index; i++){
        if (curr == NULL){
            printf("Insert at Nth failed: index out of bounds\n");
            free(newnode);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    prev->next = newnode;
    newnode->next = curr;
}

void task5_insertnth(){ 
    Node* head = NULL;
    build_list(&head);
    printf("Original list: ");
    printlist(head);

    insert_at_n(&head, 3, 24);
    printf("After inserting: "); 
    printlist(head); 
}
