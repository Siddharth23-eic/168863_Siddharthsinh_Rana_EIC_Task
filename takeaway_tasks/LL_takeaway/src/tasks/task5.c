/* Owner: Siddharthsinh Rana
 * Date: 05-01-2026
 * Topic: Linked List Takeaway Tasks
 * Description: Write a function int transpose(matrix**) that takes the transpose of the matrix. Transpose of a matrix M is defined as a matrix M1 where rows of M are equivalent to columns of M1 and columns of M are equivalent to rows of M1. For example the transpose of M = {{1,2},{3,4}} is M1 = {{1,3},{2,4}}.
*/

#include <stdio.h>
#include "smatrix.h"

int32_t transposeMatrix(matrix **M){
    if(M == NULL || *M == NULL){
        return 1;
    }

    matrix *old = *M;

    matrix *T = createMatrix(old->col, old->rows);
    if(!T){
        return 1;
    }
    
    for(int32_t i = 0; i < old->rows; i++){
        node *curr = old->rowList[i];

        while(curr){
            node *n = malloc(sizeof(node));
            if(!n){
                freeMatrix(T);
                return 1;
            }

            n->row = curr->col;
            n->col = curr->row;
            n->value = curr->value;
            n->rowPtr = n->colPtr = NULL;

            insert(T, n);

            curr = curr->rowPtr;
        }
    }
    freeMatrix(old);

    *M = T;

    return 0;
}