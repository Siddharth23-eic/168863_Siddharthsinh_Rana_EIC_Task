#ifndef TREEFUNC_H
#define TREEFUNC_H

#include <stdint.h>

#define MAXWORD   1000
#define PREFIXLEN 6
#define MAXLINES  100
#define MAXVARS   10000


typedef struct var {
    char *name;
    int32_t count;             // Count of occurrences of the variable
    int32_t lines[MAXLINES];   // Array of line numbers
    int32_t line_count;        // Total number of lines
    struct var *next;          // Link to next Var in the list
} Var;

typedef struct tree {
    char prefix[PREFIXLEN + 1];    // Prefix for the tree node
    Var *list;                     // List of variables with the same prefix
    struct tree *left;             // Left subtree (for smaller values)
    struct tree *right;            // Right subtree (for larger values)
} Tree;

/* tokenizer */
int32_t g_word(char *word, int32_t lim);
int32_t get_lineno(void);

/* tree operations */
Tree *addtree(Tree *root, const char *word, int32_t lineno);
void print_prefix_groups(Tree *root);        /* ex 6-2 */
void print_xref(Tree *root);
void collect_vars(Tree *root, Var **arr, int32_t *n);
/* utils */
void freetree(Tree *root);

#endif
