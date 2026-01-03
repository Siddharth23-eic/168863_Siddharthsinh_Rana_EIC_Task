/* Owner: Siddharthsinh Rana
 * Date: 02-01-2026
 * Topic: Linked List Takeaway Tasks
 * Description: Write a function int duplicatevalue(matrix* M, double value) that returns 1 if a  node with the value exists in the matrix. Return 0 if not.
*/

#include <stdio.h>
#include "smatrix.h"

int32_t duplicateValue(matrix *M, double val){
    if(M == NULL){
        return 0;
    }

    for(int32_t i = 0; i < M->rows; i++){
        node *temp = M->rowList[i];
        while(temp != NULL){
            if(temp->value == val){
                return 1;
            }
            temp = temp->rowPtr;
        }
    }
    return 0;
}