/* Owner: Siddharthsinh Rana
   Date: 05-02-2026
   Topic: Queue takwaway task
   Description: Operations to be done in the Priority Queue
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priorityQueue.h"

/* Initialize */
void PQ_init(PQ *pq){
    if(pq)
        pq->front = NULL;
}

/* Clear queue */
void PQ_clear(PQ *pq){
    if(!pq)
        return;
    
    while(pq->front){
        PTnode *tmp = pq->front;
        pq->front = pq->front->next;
        free(tmp->name);
        free(tmp);
    }
}

/* Free queue */
void PQ_free(PQ *pq){
    PQ_clear(pq);
}

/* Check empty */
bool isEmpty(const PQ *pq){
    return pq->front == NULL;
}

/* Add new patient name */
void PQ_newPT(PQ *pq, const char *name, int32_t priority){
    if(!pq || !name)
        return;
    
    PTnode *n = malloc(sizeof(PTnode));
    if(!n)
        return;

    n->name = strdup(name);
    n->priority = priority;
    n->next = NULL;

    if(!pq->front || priority < pq->front->priority){
        n->next = pq->front;
        pq->front = n;
        return;
    }

    PTnode *curr = pq->front;
    while(curr->next && curr->next->priority <= priority){
        curr = curr->next;
    }

    n->next = curr->next;
    curr->next = n;
}

/* Process patient and remove highest priority element */
char *PQ_processPT(PQ *pq){
    if(PQ_isEmpty(pq)){
        printf("Error: Queue is empty.\n");
        return NULL;
    }

    PTnode *tmp = pq->front;
    char *name = strdup(tmp->name);

    pq->front = tmp->next;
    free(tmp->name);
    free(tmp);

    return name;
}

/* Peek front name */
char *PQ_frontName(const PQ *pq){
    if(PQ_isEmpty(pq)){
        printf("Error: Queue is empty.\n");
        return NULL;
    }
    return pq->front->name;
}

/* Peek priority */
int32_t PQ_frontPriority(const PQ *pq){
    if(PQ_isEmpty(pq)){
        printf("Error: queue is empty.\n");
        return NULL;
    }
    return pq->front->priority;
}

void PQ_upgradePT(PQ *pq, const char *name, int32_t newPriority){
    if(PQ_isEmpty(pq)){
        printf("Error: queue is empty.\n");
        return;
    }
    PTnode *curr = pq->front; 
    PTnode *prev = NULL;

    while(curr && strcmp(curr->name, name) != 0){
        prev = curr;
        curr = curr->next;
    }

    if(!curr){
        printf("Error: patient not found\n");
        return;
    }

    if(newPriority >= curr->priority){
        printf("Error: new priority is not more urgent.\n");
        return;
    }

    /* Detach node */
    if(!prev)
        pq->front = curr->next;
    else
        prev->next = curr->next;

    curr->priority = newPriority;
    curr->next = NULL;

    /* Re-insert */
    if(!pq->front || newPriority < pq->front->priority){
        curr->next = pq->front;
        pq->front = curr;
        return;
    }

    PTnode *walk = pq->front;
    while(walk->next && walk->next->priority <= newPriority)
        walk = walk->next;
    
    curr->next = walk->next;
    walk->next = curr;
}

/* Conver queue to string */
int32_t PQ_toString(const PQ *pq, char *buf, size_t buflen){
    if (!pq || !buf || buflen == 0)
        return -1;

    size_t used = 0;
    int written = snprintf(buf, buflen, "{");
    if (written < 0 || (size_t)written >= buflen)
        return -1;

    used += (size_t)written;
    PTnode *curr = pq->front;

    while (curr){
        written = snprintf(buf + used, buflen - used,"%d:%s%s", curr->priority, curr->name, curr->next ? ", " : "");
        if (written < 0 || (size_t)written >= buflen - used)
            return -1;

        used += (size_t)written;
        curr = curr->next;
    }

    if (used + 1 >= buflen)
        return -1;

    strcat(buf, "}");
    return (int)strlen(buf);
}
