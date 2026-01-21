/* Owner: Siddharthsinh Rana
 * Date: 02-01-2026
 * Topic: Linked List Takeaway Tasks
 * Description:  Given a pointer to a node called ptr (assume all memory is allocated and node  initialized), write code to insert the node to the beginning of the each list.
*/

#include <stdio.h>
#include <stdint.h>
#include "smatrix.h"

void insert(matrix *mat, node *ptr){
    if(mat == NULL || ptr == NULL){
        return;
    }

    if(ptr->row >= mat->rows || ptr->col >= mat->col){
        return;
    }
    
    /* Insert node at beginning of row list */
    ptr->rowPtr = mat->rowList[ptr->row];
    mat->rowList[ptr->row] = ptr;
    
    /* Insert node at beginning of column */
    ptr->colPtr = mat->colList[ptr->col];
    mat->colList[ptr->col] = ptr;
}