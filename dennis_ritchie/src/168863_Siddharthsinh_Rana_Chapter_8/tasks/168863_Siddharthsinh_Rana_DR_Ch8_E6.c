/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 02/12/2025
 * Chapter: 8
 * Exercise: 8.6
 * Description: The standard library function calloc(n,size) returns a pointer to n objects of size size, with the storage initialized to zero. Write calloc, by calling malloc or by modifying it.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void *calloc_c(size_t n, size_t size){
    size_t total = n * size;
    void *p = malloc(total);

    if(p == NULL)
        return NULL;
    
    /* manually set all bytes to zero */
    unsigned char *cp = p;
    for(size_t i = 0; i < total; i++)
        cp[i] = 0;
    
    return p;
}

int32_t exercise8_6(){
    size_t n, size;

    printf("Enter the number of elements: ");
    if (scanf("%zu", &n) != 1 || n == 0) {
        printf("Invalid input.");
        return 1;
    }

    printf("Enter the size of each element(in bytes): ");
    if (scanf("%zu", &size) != 1 || size == 0) {
        printf("Invalid input.");
        return 1;
    }

    size_t total = n * size;
    void *arr = calloc_c(n, size);
    if (!arr) {
        printf("Calloc_c failed\n");
        return 1;
    }

    unsigned char *bytes = (unsigned char *)arr;

    for (size_t i = 0; i < total; i++) {
        printf("%02X ", bytes[i]);
        if ((i + 1) % size == 0)
            printf(" ");
    }

    printf("\nFreeing memory...\n");
    free(arr);
    return 0;
}