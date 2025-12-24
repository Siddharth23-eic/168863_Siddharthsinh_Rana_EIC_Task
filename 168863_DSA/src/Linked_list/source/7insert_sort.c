/* Owner: Siddharthsinh Rana
 * Task: Data Structures
 * Created Date: 10/12/2025
 * Topic: Linked list
 * Description:
 * SortedInsert + InsertSort
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "LLtask.h"

/* InsertSort using sortedinsert() */
void InsertSort(Node** headRef)
{
    Node* curr = *headRef;
    Node* sorted = NULL;

    while (curr != NULL) {
        sortedinsert(&sorted, curr->data);
        curr = curr->next;
    }

    *headRef = sorted;
}

void task7_insertsort(){
    Node* list = NULL;
    build_list(&list);

    printf("Original list:\n");
    printlist(list);

    InsertSort(&list);

    printf("Sorted list:\n");
    printlist(list);

    return;
}