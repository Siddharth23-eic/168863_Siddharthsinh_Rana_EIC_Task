#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct tree{
    int32_t data;
    struct tree *left;
    struct tree *right;
}Tree;

void insert(Tree **root, int32_t val){
    Tree *newnode = malloc(sizeof(Tree));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;

    if(*root == NULL){
        *root = newnode;
        return;
    }

    Tree *queue[100];
    int32_t front = 0;
    int32_t rear = 0;

    queue[rear++] = *root;

    while(front < rear){
        Tree *curr = queue[front++];

        if(curr->left == NULL){
            curr->left = newnode;
            return;
        }
        else{
            queue[rear++] = curr->left;
        }
        if(curr->right == NULL){
            curr->right = newnode;
            return;
        }else{
            queue[rear++] = curr->right;
        }
    }
}

int32_t main(){
    Tree *root = NULL;

    int32_t n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d data: ",n);
    for(int32_t i = 0; i < n; i++){
        int32_t val;
        scanf("%d", &val);
        insert(&root, val);
    }
    return 0;
}