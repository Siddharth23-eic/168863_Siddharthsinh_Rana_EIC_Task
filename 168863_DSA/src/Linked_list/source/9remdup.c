#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "LLtask.h"

/* Remove Duplicates from sorted and unsorted list */
void RemoveDuplicates(Node *head) {
    if (head == NULL)
        return;

    int seen[1000] = {0};   /* assumes data in range [0,999] */
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL) {
        if (seen[curr->data]) {
            /* duplicate found */
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else {
            seen[curr->data] = 1;
            prev = curr;
            curr = curr->next;
        }
    }
}

void task9_removedup() {
    Node* head = NULL;
    build_list(&head);

    printf("\nOriginal list:\n");
    printlist(head);

    RemoveDuplicates(head);

    printf("\nList after removing duplicates:\n");
    printlist(head);

    freelist(head);
    return 0;
}
