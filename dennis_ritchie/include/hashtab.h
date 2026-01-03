#ifndef HASHTAB_H
#define HASHTAB_H

#include <stdint.h>

#define HASHSIZE 101

/* Structure for storing table entries */
typedef struct nlist {
    struct nlist *next;    /* next entry in chain */
    char *name;            /* defined name */
    char *defn;            /* replacement text */
} nlist;

extern nlist *hashtab[HASHSIZE];  /* hash table */

/* Function declarations */
unsigned hash(char *s);
nlist *lookup(char *s);
nlist *install(char *name, char *defn);
void undef_6(char *name);
void freetable(void);

#endif  /* HASHTAB_H */