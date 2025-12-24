#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node{
    int32_t data;
    struct node *next;
}Stack;

/* Top of stack */
Stack *top = NULL;

void pushSt(int32_t chr){
    Stack *newnode = malloc(sizeof(Stack));
    if(!newnode)
        return;
    
    newnode->data = chr;
    newnode->next = top;
    top = newnode;
}

int32_t popSt(){
    if(top == NULL)
        return '\0';
    
    Stack *temp = top;
    int32_t val = temp->data;

    top = top->next;
    free(temp);

    return val;
}

int32_t isMatching(int32_t open, int32_t close){
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int32_t mainSt(){
    char expr[100];

    printf("Enter expression\n");
    scanf("%s", expr);

    for(int32_t i = 0; expr[i] != '\0'; i++){
        int32_t chr = expr[i];

        if(chr == '(' || chr == '{' || chr == '['){
            pushSt(chr);
        }

        else if(chr == ')' || chr == '}' || chr == ']'){
            if(top == NULL){
                printf("Not Balanced\n");
                return 0;
            }

            int32_t popped = popSt();
            if(!isMatching(popped, chr)){
                printf("Not Balanced\n");
                return 0;
            }
        }
    }
    if(top == NULL)
        printf("Balance\n");
    else
        printf("Not Balanced\n");

    return 0;
}