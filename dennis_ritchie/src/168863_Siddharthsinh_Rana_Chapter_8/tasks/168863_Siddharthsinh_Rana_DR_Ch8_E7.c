#include <stdio.h>
#include <stdint.h>
#include "memoryall.h"

int32_t exercise8_7()
{
    printf("mymalloc(500)\n");
    void *p1 = mymalloc(500);

    printf("\nmymalloc(11000)\n");
    void *p2 = mymalloc(11000);

    printf("\nmyfree((void *)0x12345678)\n");
    myfree((void *)0x12345678);
    printf("\n");

    if (p1)
        myfree(p1);

    return 0;
}