/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 30/12/2025
 * Chapter: 6
 * Exercise: 6.4
 * Description: Write a program that prints the distinct words in its input sorted into decreasing order of frequency of occurance. Precede each word by it's count.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "treefunc.h"

#define MAXVARS 10000

static int32_t cmpfreq(const void *a, const void *b){
    Var *w1 = *(Var **)a;
    Var *w2 = *(Var **)b;
    return w2->count - w1->count;
}


int32_t exercise6_4(void){
    Tree *root = NULL;
    char word[MAXWORD];
    int32_t lineno;

    while (g_word(word, MAXWORD) != EOF) {
        lineno = get_lineno();
        root = addtree(root, word, get_lineno());
    }

    Var *array[MAXVARS];
    int32_t n = 0;

    collect_vars(root, array, &n);
    qsort(array, n, sizeof(Var *), cmpfreq);

    for (int32_t i = 0; i < n; i++)
        printf("%d %s\n", array[i]->count, array[i]->name);

    freetree(root);
    return 0;
}