/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 30/12/2025
 * Chapter: 6
 * Exercise: 6.3
 * Description: Write a cross-referencer that prints a list of all words in a document, and for each word, a list of the line numbers on which it occurs. Remove noise words like ``the,'' ``and,'' and so on.
 */

#include <stdio.h>
#include <stdint.h>
#include "chapter6func.h"
#include "treefunc.h"

/* Noise words */
static const char *noise_words[] = {
    "the", "and", "is", "in", "at", "of", "a", "an", "to", "for", "on", "with", "as", "by", "that", "this", "it", NULL
};

/* Function to check if a word is a noise word */
static int32_t isnoise(const char *word) {
    for(int32_t i = 0; noise_words[i] != NULL; i++) {
        if(strcmp(word, noise_words[i]) == 0) {
            return 1; /* It's a noise word */
        }
    }
    return 0; /* Not a noise word */
}

int32_t exercise6_3(void) {
    Tree *root = NULL;
    char word[MAXWORD];

    while(g_word(word, MAXWORD) != EOF){
        if(isalpha(word[0]) && !isnoise(word)){
            root = addtree(root, word, get_lineno());
        }
    }

    print_xref(root);
    freetree(root);
    return 0;
}

