/* Owner: Siddharthsinh Rana
 * Task: Data Structures
 * Created Date: 20/08/2025
 * Topic: Linked list 
 * Description: write a getNth() function that takes a linked list and an integer index and returns the data value stores in the node at the index position.
 * getNth() uses the C numbering convention fisrt node is at 0th index and so on. 
 */

#include <stdio.h>
#include <stdint.h>
#include "LinkedList.h"
#include "LLtask.h"

int32_t GetNth(Node* head, int32_t number){
   int32_t count = 0;
   while(head != NULL){
      if(count == number)
         return head->data;
      count++;
      head = head->next;
    }
    return -1;
 }

void task2_getnth(){
   Node* list = NULL;
   int32_t n;
   printf("Enter the index: ");
   scanf("%d", &n);
   
   build_list(&list);

   int32_t result = GetNth(list, 1);
   printf("Data at 1st position is %d.", result);
 }