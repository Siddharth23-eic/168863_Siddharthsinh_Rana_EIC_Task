/* Owner: Siddharthsinh Rana
 * Task: Data Structures
 * Created Date: 08/12/2025
 * Topic: Linked list 
 * Description: Write a Count() function that counts the number of times given int occurs in a list
 * given a list and an integer, returns the list{1,2,3}.
 */

#include <stdio.h>
#include <stdint.h>
#include "LinkedList.h"
#include "LLtask.h"

int32_t Count(Node* head, int32_t num){
    int count = 0;
    while(head != NULL){
        if(head->data == num){
            count++;
        }
        head = head->next;
    }
    return count;
}

void task1_count(){
    Node* Mylist = NULL;
    int32_t n;
    build_list(&Mylist);

    printf("Enter number to check occurance: ");
    scanf("%d", &n);
    int32_t result = Count(Mylist, n);
    printf("Number %d appeared %d times.\n",n, result);
    return 0;
}