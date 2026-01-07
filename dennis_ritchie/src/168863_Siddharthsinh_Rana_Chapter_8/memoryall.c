#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "memoryall.h"

static Header base;
static Header *freep = NULL;

/* initialize the free list on the first call */
static void init_freelist(void)
{
    if (!freep) {
        base.s.ptr = &base;
        base.s.size = 0;
        freep = &base;
    }
}

/* To check if it is a valid pointer or not */
static int32_t valid_ptr(void *ap)
{
    if (!ap)
        return 0;

    if ((unsigned long)ap % sizeof(Header) != 0)
        return 0;

    return 1;
}

/* Add memory block to malloc's free list(turn static or external arrays into heap memory) */
int32_t bfree(void *p, unsigned n){
    /* p must exist and n must fit at least one header */
    if(!p || n < sizeof(Header))
        return 0;
    
    /* Must be properly aligned to header */
    if((unsigned long)p % sizeof(Header) != 0)
        return 0;
    
    unsigned nunits = n / sizeof(Header);

    /* Build a header at the beginning op p */
    Header *bp = (Header *)p;
    bp->s.size = nunits;

    /* Insert the block into the free list */
    myfree((void *)(bp + 1));

    return nunits;
}

/* Merges with adjecent blocks if possible and returns a block to the free list */
void myfree(void *ap)
{
    init_freelist(); 

    if (!valid_ptr(ap)) {
        printf("Error: Invalid pointer passed to free.\n");
        return;
    }

    /* Move back one header to find start of block */
    Header *bp = (Header *)ap - 1;

    if (bp->s.size == 0) {
        printf("Error: Invalid pointer passed to free.\n");
        return;
    }

    Header *p;
    /* Finding correct inertion position */
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break;

    if (bp + bp->s.size == p->s.ptr)
        bp->s.ptr = p->s.ptr->s.ptr;
    else
        bp->s.ptr = p->s.ptr;

    if (p + p->s.size == bp)
        p->s.ptr = bp->s.ptr;
    else
        p->s.ptr = bp;

    /* Move freep forward */
    freep = p;
}

/* Request more memory from OS using sbrk() */
static Header *morecore(unsigned nu)
{
    if (nu < NALLOC)
        nu = NALLOC;

    /* request memory from OS */
    char *cp = sbrk(nu * sizeof(Header));
    if (cp == (char *) -1)
        return NULL;
    
    /* Build a header for newly allocated memory */
    Header *up = (Header *)cp;
    up->s.size = nu;

    /* Insert into free list */
    myfree((void *)(up + 1));
    return freep;
}

/* Allocates memory by serching the free list also splits blocks if needed */
void *mymalloc(unsigned nbytes)
{
    Header *p, *prevp;
    unsigned nunits;

    init_freelist();

    if (nbytes == 0 || nbytes > MAX_ALLOC) {
        printf("Error: Invalid allocation size %u bytes.\n", nbytes);
        return NULL;
    }

    nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;

    /* iterating the free list looking foa a big enough block */
    for (prevp = freep, p = prevp->s.ptr;; prevp = p, p = p->s.ptr) {

        if (p->s.size >= nunits) {

            /* Finding exact fit */
            if (p->s.size == nunits)
                prevp->s.ptr = p->s.ptr;

            /* Allocate tail at the end of larger block */
            else {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }

            freep = prevp;
            printf("Successful allocation of %u bytes.\n", nbytes);
            return (void *)(p + 1);
        }

        /* this for needing more memort */
        if (p == freep) {
            p = morecore(nunits);
            if (!p) {
                printf("Error: Invalid allocation size %u bytes.\n", nbytes);
                return NULL;
            }
        }
    }
}
