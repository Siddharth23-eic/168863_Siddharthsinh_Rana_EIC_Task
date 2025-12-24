/* Owner: Siddharthsinh Rana 
* Task: Data Structures 
* Created Date: 11/12/2025 
* Topic: Linked list 
* Description: This is a variant on Push(). Instead of creating a new node and pushing it onto the given list, MoveNode() takes two lists, removes the front node from the second list and pushes it onto the front of the first. 
*/ 
#include <stdio.h> 
#include <stdint.h> 
#include <stdlib.h>
#include "LinkedList.h"
#include "LLtask.h"

void pushnode(Node **lista, Node **listb){ 
    if(*listb == NULL)
        return;
        
    Node *temp = *listb;
    *listb = temp->next;

    temp->next = *lista;
    *lista = temp;
} 

void task10_movenode(){ 
    Node* listA = NULL; 
    Node* listB = NULL; 

    /* Pushing data in ListA */ 
    build_list(&listA);
    /* Pushing data in ListB */ 
    build_list(&listB);

    printf("Before movig node: \n");
    printf("List A: ");
    printlist(listA);
    printf("List B: ");
    printlist(listB);
    
    pushnode(&listA, &listB);

    printf("After movig node: \n");
    printf("List A: ");
    printlist(listA);
    printf("List B: ");
    printlist(listB);

    freelist(listA);
    freelist(listB); 
}