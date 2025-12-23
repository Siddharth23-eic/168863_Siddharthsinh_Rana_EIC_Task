/* Owner: Siddharthsinh Rana 
* Task: Data Structures 
* Created Date: 11/12/2025 
* Topic: Linked list 
* Description: This is a variant on Push(). Instead of creating a new node and pushing it onto the given list, MoveNode() takes two lists, removes the front node from the second list and pushes it onto the front of the first. 
*/ 
#include <stdio.h> 
#include <stdint.h> 
#include <stdlib.h> 

struct node{ 
    int32_t data; 
    struct node* next; 
}; 

void printlist(struct node* head) { 
    while (head != NULL) { 
        printf("%d%s", head->data, head->next ? "->" : ""); 
        head = head->next; } printf("\n"); 
} 

/* create list and push at the end */ 
void push(struct node **headref, int32_t data){ 
    struct node *newnode = malloc(sizeof(struct node)); 
    newnode->data = data; newnode->next = NULL; 
    
    /* Checking list is empty */ 
    if(*headref == NULL){ 
        *headref = newnode; return; 
    } 
    
    /* Traverse to the end */ 
    struct node* curr = *headref; 
    while(curr->next != NULL){ 
        curr = curr->next; 
    } 
    curr->next = newnode; 
} 

void pushnode(struct node **lista, struct node **listb){ 
    struct node* a = *lista; 
    struct node* b = *listb; 
    struct node* head = b; 
    head->next = a; 
    b = b->next; 
} 

int32_t main(){ 
    struct node* listA = NULL; 
    struct node* listB = NULL; 
    int32_t n, m; 
    
    printf("Enter a number of nodes for listA: "); 
    scanf("%d", &n); 
    
    printf("Enter a number of nodes for listB: "); 
    scanf("%d", &m); int32_t num; 
    
    /* Pushing data in ListA */ 
    printf("Enter total n data to push on listA\n"); 
    for(int32_t i = 0; i < n; i++){ 
        scanf("%d",&num); 
        push(&listA, num); 
    } 
    
    /* Pushing data in ListB */ 
    printf("Enter total n data to push on listB\n"); 
    for(int32_t i = 0; i < m; i++){ 
        scanf("%d",&num); 
        push(&listB, num); 
    } 
    
    pushnode(&listA, &listB); 
    printlist(listA); 
    printlist(listB); 
    return 0; 
}