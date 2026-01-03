/* Owner: Siddharthsinh Rana
    Date: 29-12-2025
    Topic : Doubly Linked List
    Description: Task 1 test the working of DLL fucntions.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "DLLtask.h"

int32_t task1DLL(void){
    DLL* head = NULL;

    printf("Testing Append function:\n");
    d_append(&head, 10);
    d_append(&head, 20);
    printf("No of elements in DLL after d_append:%d\n", d_count(head));
    d_display(head);

    printf("\nTesting Add at Beginning function:");
    d_addatbeg(&head, 5); /* Add 5 at the beginning */
    printf("\nNo of elements in DLL after d_addatbeg: %d:\n", d_count(head));
    d_display(head);
    
    printf("\nTesting Add after function:");
    d_addafter(head, 1, 15); /* Add 15 after 1st node */
    printf("\nNo of elements in DLL after d_addafter: %d:\n", d_count(head));
    d_display(head);

    printf("\nTesting Delete function:");
    d_delete(&head, 20); /* Delete node with data 20 */
    printf("\nNo of elements in DLL after deletion: %d:\n", d_count(head));
    d_display(head);

    printf("\n");
    return 0;
}