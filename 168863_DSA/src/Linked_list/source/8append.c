/* Owner: Siddharthsinh Rana
* Task: Data Structures
* Created Date: 10/12/2025
* Topic: Linked list 
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "LLtask.h"

void append(Node **list1, Node **list2){

    /* If list1 is empty, list1 becomes list2 */
    if(*list1 == NULL){
        *list1 = *list2;
        *list2 = NULL;
        return;
    }
    /* If list2 is empty, nothing to append */
    if(*list2 == NULL){
        return;
    }
    
    Node* a = *list1;
    /* Traverse to the LAST node of list1 */
    while(a->next != NULL){
        a = a->next;
    }
    /* Attach list2 at the end of list1 */
    a->next = *list2;
    /* list2 is now empty */
    *list2 = NULL;
}

void task8_append(){
    Node* listA = NULL;
    Node* listB = NULL;

    /* Building list A */
    build_list(&listA);

    /* Building list B */
    build_list(&listB);

    append(&listA, &listB);

    printlist(listA);

    return 0;
}