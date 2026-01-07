#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct PTnode{
    char *name;
    int32_t priority;
    struct PTnode *next;
}PTnode;

typedef struct{
    PTnode *front;
}PQ;

/* Initialization /Clean up */
void PQ_init(PQ *pq);
void PQ_free(PQ *pq);
void PQ_clear(PQ *pq);

/* Core Operations */
void PQ_newPT(PQ *pq, const char *name, int32_t priority);

char *PQ_processPT(PQ *pq);

/* Reading only */
char *PQ_frontName(const PQ *pq);
int32_t PQ_frontPriority(const PQ *pq);

/* Update priority queue */
void PQ_upgradePT(PQ *pq, const char *name, int32_t newPriority);

/* Empty state check */
bool PQ_isEmpty(const PQ *pq);

/* Safe string conversion */
int32_t PQ_toString(const PQ *pq, char *buf, size_t buflen);

#endif