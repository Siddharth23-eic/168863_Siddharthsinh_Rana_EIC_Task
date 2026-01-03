/* Owner: Siddharthsinh Rana
   Date: 02-01-2026
   Topic: Linked List takeaway Tasks
   Description: This is the main file calling the exercise function.
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "smatrix.h"

int32_t mainLL(){
    int32_t rows, cols;
    double dup;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    matrix *matt = createMatrix(rows, cols);
    printMatrix(matt);
    
    add_elements(matt);
    printMatrix(matt);

    printf("Enter a value to check dup: ");
    scanf("%lf", &dup);

    if(duplicateValue(matt, dup))
        printf("Value %lf exist in matrix\n", dup);
    else
        printf("Value %lf doesn't exist in matrix\n", dup);

    resizeMatrix(&matt);
    printMatrix(matt);

    return 0;
}