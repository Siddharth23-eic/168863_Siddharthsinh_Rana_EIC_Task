/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 08/12/2025
 * Chapter: 8
 * Exercise: 8.8
 * Description: Write a routine bfree(p,n) that will free any arbitrary block p of n characters into the free list maintained by malloc and free. By using bfree, a user can add a static or external array to the free list at any time.
 */

#include <stdio.h>
#include <stdint.h>
#include "memoryall.h"

int32_t exercise8_8() {

    static char buffer[5000];

    printf("Adding static buffer to free list\n");
    bfree(buffer, sizeof(buffer));

    printf("allocating 400 bytes\n");
    void *p = mymalloc(400);

    if(p){
        printf("Allocation successful.\n");
    }
    else{
        printf("Allocation failed.\n");
    }

    printf("Freeing the allocated memory\n");
    if(p)
        myfree(p);
    return 0;
}

