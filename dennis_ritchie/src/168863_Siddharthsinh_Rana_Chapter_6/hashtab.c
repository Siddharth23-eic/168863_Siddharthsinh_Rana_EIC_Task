#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtab.h"

/* Hash table */
nlist *hashtab[HASHSIZE];

/* Hash function to compute the hash value for the given string */
unsigned hash(char *s) {
    unsigned hashval = 0;
    for ( ; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

/* Lookup function to find a name in the hash table */
nlist *lookup(char *s) {
    nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;  /* found */
    return NULL;  /* not found */
}

/* Install function to add a name and its replacement text to the table */
nlist *install(char *name, char *defn) {
    nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) {  /* Not found */
        np = (nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {  /* Already there */
        free((void *) np->defn);  /* Free the previous definition */
    }
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

/* Remove a name and its definition from the hash table */
void undef_6(char *name) {
    unsigned hashval = hash(name);
    nlist *np = hashtab[hashval];
    nlist *prev = NULL;

    /* Search for the name in the list */
    while (np != NULL) {
        if (strcmp(name, np->name) == 0) {
            if (prev == NULL) {
                /* First element in the list */
                hashtab[hashval] = np->next;
            } else {
                /* Remove from middle or end of list */
                prev->next = np->next;
            }
            /* Free the memory used by the name and definition */
            free(np->name);
            free(np->defn);
            free(np);
            return;  /* Done */
        }
        prev = np;
        np = np->next;
    }

    printf("Name '%s' not found in the table.\n", name);  /* Not found */
}

/* Free all memory used by the hash table */
void freetable(void) {
    nlist *np, *prev;
    for (int i = 0; i < HASHSIZE; i++) {
        np = hashtab[i];
        while (np != NULL) {
            prev = np;
            np = np->next;
            free(prev->name);
            free(prev->defn);
            free(prev);
        }
        hashtab[i] = NULL;
    }
}