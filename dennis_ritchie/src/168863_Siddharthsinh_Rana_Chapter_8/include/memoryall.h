#ifndef MEMORY_ALL
#define MEMORY_ALL

typedef long Align;

union header {
    struct {
        union header *ptr;
        unsigned size;
    } s;
    Align x;
};

typedef union header Header;

#define NALLOC 1024
#define MAX_ALLOC 10000

/* Exported allocator API */
void myfree(void *ap);
void *mymalloc(unsigned nbytes);

/* bfree for exercise 8-8 (optional) */
int bfree(void *p, unsigned n);

#endif
