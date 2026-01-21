/* Owner: Siddharthsinh Rana
   Date: 02-01-2026
   Topic: Linked List takeaway Tasks
   Description: This is the main file calling the exercise functions of Linked List takeaway tasks.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "smatrix.h"

int main(void){
    int32_t rows, cols;
    double dup;
    char choice;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    matrix *matt = createMatrix(rows, cols);
    if (!matt) {
        printf("Matrix allocation failed\n");
        return 1;
    }
    printMatrix(matt);


    add_elements(matt);
    printMatrix(matt);

    printf("Enter a value to check dup: ");
    scanf("%lf", &dup);

    if (duplicateValue(matt, dup)){
        printf("Value %lf exists in matrix\n", dup);
    }else{
        printf("Value %lf doesn't exist in matrix\n", dup);
    }

    if (resizeMatrix(&matt) != 0) {
        printf("Resize failed\n");
        freeMatrix(matt);
        return 1;
    }

    printMatrix(matt);

    printf("Transpose matrix? (y or n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        if (transposeMatrix(&matt) == 0){
            printMatrix(matt);
        }else{
            printf("Transpose failed\n");
        }
    }

    freeMatrix(matt);
    return 0;
}
