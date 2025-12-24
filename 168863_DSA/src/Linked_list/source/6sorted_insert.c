/* Owner: Siddharthsinh Rana
* Task: Data Structures
* Created Date: 10/12/2025
* Topic: Linked list 
* Description: Write a SortedInsert() function which given a list that is sorted in increasing order, and a

single node, inserts the node into the correct sorted position in the list. While Push()

allocates a new node to add to the list, SortedInsert() takes an existing node, and just

rearranges pointers to insert it into the list.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "LLtask.h"

void task6_sortedinsert(){
    Node* List = NULL;
    int32_t n,num;
    printf("Enter number of node: ");
    scanf("%d", &n);

    printf("Enter total %d node values: \n", n);
    for(int32_t i = 0; i < n; i++){
        scanf("%d", &num);
        sortedinsert(&List, num);
    }
    printlist(List);
    return;
}