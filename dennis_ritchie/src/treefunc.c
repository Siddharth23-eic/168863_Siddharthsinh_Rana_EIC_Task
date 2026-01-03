#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "treefunc.h"

/* line counter */
static int32_t lineno = 1;

int32_t get_lineno(void) {
    return lineno;
}

static char *strdup_c(const char *s) {
    char *p = (char *)malloc(strlen(s) + 1);
    if (p) {
        strcpy(p, s);
    }
    return p;
}

/* read next word, skipping comments and strings */
int32_t g_word(char *word, int32_t lim) {
    int32_t c, d;
    char *w = word;

    while ((c = getchar()) != EOF && isspace((unsigned char)c)) {
        if (c == '\n')
            lineno++;
    }

    if (c == EOF)
        return EOF;

    /* skip comments */
    if (c == '/') {
        d = getchar();
        if (d == '*') {
            int32_t prev = 0;
            while ((c = getchar()) != EOF) {
                if (prev == '*' && c == '/')
                    break;
                if (c == '\n')
                    lineno++;
                prev = c;
            }
            return g_word(word, lim);
        }
        ungetc(d, stdin);
    }

    /* skip strings and character constants */
    if (c == '"' || c == '\'') {
        int32_t quote = c;
        while ((c = getchar()) != EOF) {
            if (c == '\\')
                getchar();
            else if (c == quote)
                break;
            else if (c == '\n')
                lineno++;
        }
        return g_word(word, lim);
    }

    if (!isalpha((unsigned char)c) && c != '_')
        return c;

    *w++ = (char)c;
    while (--lim > 0) {
        c = getchar();
        if (!isalnum((unsigned char)c) && c != '_') {
            ungetc(c, stdin);
            break;
        }
        *w++ = (char)c;
    }

    *w = '\0';
    return word[0];
}

/* insert into tree */
Tree *addtree(Tree *root, const char *word, int32_t line) {
    char key[PREFIXLEN + 1];
    strncpy(key, word, PREFIXLEN);
    key[PREFIXLEN] = '\0';

    if (!root) {
        root = (Tree *)calloc(1, sizeof(Tree));
        strcpy(root->prefix, key);

        root->list = (Var *)calloc(1, sizeof(Var));
        root->list->name = strdup_c(word);
        root->list->count = 1;
        root->list->lines[0] = line;
        root->list->line_count = 1;

        return root;
    }

    int32_t cmp = strcmp(key, root->prefix);

    if (cmp == 0) {
        Var *v = root->list;
        while (v) {
            if (strcmp(v->name, word) == 0) {
                v->count++;
                if (v->line_count < MAXLINES)
                    v->lines[v->line_count++] = line;
                return root;
            }
            if (!v->next)
                break;
            v = v->next;
        }

        v->next = (Var *)calloc(1, sizeof(Var));
        v = v->next;
        v->name = strdup_c(word);
        v->count = 1;
        v->lines[0] = line;
        v->line_count = 1;
    }
    else if (cmp < 0) {
        root->left = addtree(root->left, word, line);
    }
    else {
        root->right = addtree(root->right, word, line);
    }

    return root;
}

/* ===== Exercise 6.2 ===== */
void print_prefix_groups(Tree *root) {
    if (!root) return;

    print_prefix_groups(root->left);

    if (root->list) {
        printf("%s:\n", root->prefix);
        for (Var *v = root->list; v; v = v->next)
            printf("    %s\n", v->name);
    }

    print_prefix_groups(root->right);
}

/* ===== Exercise 6.3 ===== */
void print_xref(Tree *root) {
    if (!root) return;

    print_xref(root->left);

    for (Var *v = root->list; v; v = v->next) {
        printf("%s: ", v->name);
        for (int32_t i = 0; i < v->line_count; i++) {
            if (i)
                printf(", ");
            printf("%d", v->lines[i]);
        }
        printf("\n");
    }

    print_xref(root->right);
}

void collect_vars(Tree *root, Var **arr, int *n) {
    if (root == NULL) return;
    collect_vars(root->left, arr, n);

    for (Var *v = root->list; v != NULL; v = v->next) {
        arr[*n] = v;
        (*n)++;
    }
    collect_vars(root->right, arr, n);
}

/* free memory */
void freetree(Tree *root) {
    if (!root) return;

    freetree(root->left);
    freetree(root->right);

    Var *v = root->list;
    while (v) {
        Var *tmp = v;
        v = v->next;
        free(tmp->name);
        free(tmp);
    }
    free(root);
}