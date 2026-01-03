/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 29/12/2025
 * Chapter: 6
 * Exercise: 6.2
 * Description: abetical order each group of variable names that are identical in 
                the first 6 characters, but different somewhere thereafter.
                Don't count words within strings and comments. 
                Make 6 a parameter that can be set from the command line. 
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "chapter6func.h"
#include "treefunc.h"

/* C Keywords */
static const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof",
    "static", "struct", "switch", "typedef", "union", "unsigned", "void",
    "volatile", "while"
};

#define NUMKEYS (sizeof(keywords) / sizeof(keywords[0]))

static int32_t iskey(const char *word){
    for(int32_t i = 0; i < NUMKEYS; i++){
        if(strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int32_t exercise6_2() {
    Tree *root = NULL;
    char word[MAXWORD];
    int32_t type;
    
    while((type = g_word(word, MAXWORD)) != EOF){
        if(isalpha(word[0]) && !iskey(word)){
            root = addtree(root, word, 0);
        }
    }

    print_prefix_groups(root);
    freetree(root);
    return 0;
}