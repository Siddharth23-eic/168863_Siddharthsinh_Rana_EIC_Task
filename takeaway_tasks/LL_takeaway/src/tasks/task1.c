/* Owner: Siddharthsinh Rana
 * Date: 01-01-2026
 * Topic: Linked List Takeaway Tasks
 * Description: Suppose M is a matrix*, where matrix is as defined above. Write code to allocate enough space to initialize a matrix of n by m. 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "smatrix.h"

matrix *createMatrix(int32_t rows, int32_t columns){
    matrix *mat = (matrix *)malloc(sizeof(matrix));

    if(mat == NULL){
        printf("Failed to allocate memory to matrix.\n");
        return NULL;
    }

    /* Alloacte memory for the matrix row */
    mat->rowList = (node **)malloc(rows * sizeof(node *));
    if(mat->rowList == NULL){
        printf("Failed to allocate memory to the row.\n");
        free(mat);
        return NULL;
    }

    /* Allocate memory for the matrix column */
    mat->colList = (node **)malloc(columns * sizeof(node *));
    if(mat->colList == NULL){
        printf("Failed to allocate memory to the column.\n");
        free(mat->rowList);
        free(mat);
        return NULL;
    }

    /* Set all the rows to NULL */
    for(int32_t i = 0; i < rows; i++){
        mat->rowList[i] = NULL;
    }

    /* Set all the Columns to NULL */
    for(int32_t i = 0; i < columns; i++){
        mat->colList[i] = NULL;
    }

    mat->rows = rows;
    mat->col = columns;

    return mat;
}
