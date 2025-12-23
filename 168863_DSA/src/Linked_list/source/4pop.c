/* Owner: Siddharthsinh Rana
 * Task: Data Structures
 * Created Date: 09/12/2025
 * Topic: Linked list
 * Description: Write a Pop() function that is the inverse of Push(). Pop() takes a non-empty list, deletes
 *      the head node, and returns the head node's data. If all you ever used were Push() and
 *      Pop(), then here linked list would really look like a stack.
 *
 *      If Pop()  fails then, there is not a node to pop.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "LinkedList.h"
#include "LLtask.h"

void push4(Node **headref, int32_t data){
   Node *newnode = malloc(sizeof(Node));
   if(!newnode){
      printf("Malloc failed!\n");
      return;
   }

   newnode->data = data;
   newnode->next = *headref;
   *headref = newnode;
}

int32_t pop(Node **headref){
    if (*headref == NULL) {
        printf("pop failed: list is empty\n");
        return -1;
    }

    Node *temp = *headref;
    int32_t val = temp->data;

    *headref = temp->next;
    free(temp);
    return val;
}

void task4_pop(){
   struct node *head = NULL;
   int32_t n, num;
   printf("Enter number of nodes: ");
   scanf("%d", &n);
   
   for(int32_t i = 0; i < n; i++){
      scanf("%d", &num);
      push4(&head, num);
   }

   printlist(head);
   for(int32_t i = 0; i < n; i++){
      printf("Popped: %d\n", pop(&head));
   }
   pop(&head);
}