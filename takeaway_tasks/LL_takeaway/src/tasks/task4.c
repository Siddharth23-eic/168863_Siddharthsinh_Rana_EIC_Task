/* Owner: Siddharthsinh Rana
 * Date: 02-01-2026
 * Topic: Linked List Takeaway Tasks
 * Description: Write a function int resize(matrix**) that doubles the rows and columns of the matrix. The old nodes need to be copied to the new matrix. Return 0 if success, 1 
if failure.
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
    if(!newM) {
        return 1;
    }
    
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

            insert(newM, n);

            temp = temp->rowPtr;
        }
    }

    freeMatrix(old);

    /* Updating the pointer */
    *M = newM;
    return 0;
}