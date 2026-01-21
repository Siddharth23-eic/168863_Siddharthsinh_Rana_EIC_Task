/* Owner: Siddharthsinh Rana 
   Date: 02/01/2026
   Topic: Linked List(Sparse matrix) takeaways
   Description: Header file for Linked List(Sparse Matrix) takeaway tasks.
*/

#ifndef S_MATRIX_H
#define S_MATRIX_H

#include <stdint.h>

typedef struct node{
    int32_t col;
    int32_t row;
    double value;
    struct node *rowPtr;
    struct node *colPtr;
}node;

typedef struct matrix{
    node **rowList;
    node **colList;
    int32_t rows;
    int32_t col;
}matrix;

/* Task 1: Allocate memory */
matrix *createMatrix(int32_t rows, int32_t columns);

/* Task 2: Insert a node at the beginning of the row and column list */
void insert(matrix *mat, node* ptr);

/* Task 3: Check if a value exist in the matrix(Duplicate value checking) */
int32_t duplicateValue(matrix *M, double value);

/* Task 4: Resixe the matrix(double the rows and columns) */
int32_t resizeMatrix(matrix **M);

/* Task 5: Transpose the matrix (Swap cols and rows) */
int32_t transposeMatrix(matrix **M);

/* Free matrix */
void freeMatrix(matrix *mat);

/* Function print the matrix */
void printMatrix(matrix *mat);

void add_elements(matrix *M);

#endif