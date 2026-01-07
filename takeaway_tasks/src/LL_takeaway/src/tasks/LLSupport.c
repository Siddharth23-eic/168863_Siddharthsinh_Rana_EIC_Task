/*  Owner: Siddharthsinh Rana
    Date: 02-01-2026
    topic: Linked list takeaway tasks
    Description: Supporting function for LL matrix tasks
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "smatrix.h"

void add_elements(matrix *M){
    int32_t r,c;
    double val;
    char choice;
        do{
        printf("\nEnter row col value: ");
        scanf("%d %d %lf", &r, &c, &val);

        if(r < 0 || r >= M->rows || c < 0 || c >= M->col){
            printf("invalid row or column\n");
        }else{
            node *n = malloc(sizeof(node));
            if(!n){
                printf("memory allocation failed\n");
                break;
            }
            n->row = r;
            n->col = c;
            n->value = val;
            n->rowPtr = n->colPtr = NULL;

            insertAtBeg(M, n);
        }
        printf("add another value?(y/n)");
        scanf(" %c", &choice);
        
    }while(choice == 'y' || choice == 'Y');
}

void printMatrix(matrix *mat)
{
    if (mat == NULL) {
        printf("Matrix is NULL\n");
        return;
    }

    for (int32_t i = 0; i < mat->rows; i++) {
        for (int32_t j = 0; j < mat->col; j++) {

            node *temp = mat->rowList[i];
            int found = 0;

            while (temp != NULL) {
                if (temp->col == j) {
                    printf("%.2f ", temp->value);
                    found = 1;
                    break;
                }
                temp = temp->rowPtr;
            }

            if (!found) {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void freeMatrix(matrix *mat){
    int32_t i;
    node *curr;
    node *next;

    if(mat == NULL){
        return;
    }

    for(i = 0; i < mat->rows; i++){
        curr = mat->rowList[i];
        while(curr != NULL){
            next = curr->rowPtr;
            free(curr);
            curr = next;
        }
    }
    free(mat->rowList);
    free(mat->colList);

    free(mat);
}