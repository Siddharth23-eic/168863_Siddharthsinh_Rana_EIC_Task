/* Owner: Siddharthsinh Rana
 * Date: 02-01-2026
 * Topic: Linked List Takeaway Tasks
 * Description: Write a function int duplicatevalue(matrix* M, double value) that returns 1 if a  node with the value exists in the matrix. Return 0 if not.
*/

#include <stdio.h>
#include "smatrix.h"

int32_t resizeMatrix(matrix **M){
    if(M == NULL || *M == NULL){
        return 1;
    }

    matrix *old = *M;
    int32_t newR = old->rows * 2;
    int32_t newC = old->col * 2;

    /* Create new matrix with double length */
    matrix *newM = createMatrix(newR, newC);
    if(!newM) return 1;

    /* Copying existing node */
    for(int32_t i = 0; i < old->rows; i++){
        node *temp = old->rowList[i];
        while(temp != NULL){
            node *n = malloc(sizeof(node));
            if(!n){
                freeMatrix(newM);
                return 1;
            }

            n->row = temp->row;
            n->col = temp->col;
            n->value = temp->value;
            n->rowPtr = n->colPtr = NULL;

            insertAtBeg(newM, n);

            temp = temp->rowPtr;
        }
    }

    freeMatrix(old);

    /* Updating the pointer */
    *M = newM;
    return 0;
}