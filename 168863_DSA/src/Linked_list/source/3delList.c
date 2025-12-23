/* Owner: Siddharthsinh Rana
 * Task: Data Structures
 * Created Date: 20/08/2025
 * Topic: Linked list 
 * Description: Write a Count() function that counts the number of times given int occurs in a list
 * given a list and an integer, returns the list{1,2,3}.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "LLtask.h"

void deleteList(Node **head){
    Node *curr = *head;
    Node *tmp;

    while(curr != NULL){
        tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    *head = NULL;
}

void task3_deletelist(){
    Node* Mylist = NULL;
    
    build_list(&Mylist);
    printlist(Mylist);

    deleteList(&Mylist);
    printlist(Mylist);
}