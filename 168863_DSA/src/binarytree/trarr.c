#include <stdio.h>
#include <stdint.h>

#define MAX 100

int32_t tree[MAX];
int32_t size = 0;

void insert(int32_t val){
    if(size >= MAX)
        return;
    
    tree[size++] = val;
}

void display(){
    for(int32_t i = 0; i < size; i++){
        printf("%d ", tree[i]);
    }
    printf("\n");
}

int32_t main(){
    int32_t n, num;
    printf("Enter number of element to add: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int32_t i = 0; i < n; i++){
        scanf("%d", &num);
        insert(num);
    }
    printf("Binary tree: ");
    display();
    return 0;
}