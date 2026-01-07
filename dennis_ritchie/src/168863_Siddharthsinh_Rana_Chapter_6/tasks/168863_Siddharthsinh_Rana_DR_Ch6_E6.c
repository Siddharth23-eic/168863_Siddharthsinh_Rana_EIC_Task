/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 30/12/2025
 * Chapter: 6
 * Exercise: 6.6
 * Description: Implement a simple version of the #define processor (i.e., no arguments) suitable for use with C programs, based on the routines of this section. You may also find getch and ungetch helpful. 
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "hashtab.h"

#define MAXWORD 100

static char buf[MAXWORD];
static int32_t bufp = 0;

/* getch: get a character from the buffer or from stdin */
int32_t getch_6(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push a character back onto the input */
void ungetch_6(int32_t c) {
    if (bufp >= MAXWORD)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* getword_6: Read next word or character */
int32_t getword_6(char *word, int32_t lim) {
    int32_t c;
    char *w = word;

    // Skip whitespace
    while ((c = getch_6()) == ' ' || c == '\t');

    // If not EOF, start reading the word
    if (c != EOF)
        *w++ = c;

    // Read the rest of the word
    if (isalpha(c) || c == '_') {
        for (; --lim > 0; w++) {
            if (!isalnum(*w = getch_6()) && *w != '_') {
                ungetch_6(*w);  // Push non-alphanumeric character back to buffer
                break;
            }
        }
    }

    *w = '\0';  // Null terminate the word
    return (w - word);  // Return the length of the word
}

/* Main function for exercise 6-6: #define preprocessor */
int32_t exercise6_6(void) {
    int c;
    char word[MAXWORD];
    nlist *np;

    while ((c = getch_6()) != EOF) {

        /* Handle #define */
        if (c == '#') {
            char directive[MAXWORD];
            getword_6(directive, MAXWORD);

            if (strcmp(directive, "define") == 0) {
                char name[MAXWORD];
                char defn[MAXWORD];

                getword_6(name, MAXWORD);

                /* read rest of line as definition */
                int i = 0;
                while ((c = getch_6()) != '\n' && c != EOF && i < MAXWORD - 1)
                    defn[i++] = c;
                defn[i] = '\0';

                install(name, defn);
            }
        }

        /* Identifier: replace if macro */
        else if (isalpha(c) || c == '_') {
            ungetch_6(c);
            getword_6(word, MAXWORD);

            if ((np = lookup(word)) != NULL)
                printf("%s", np->defn);
            else
                printf("%s", word);
        }

        /* Other characters */
        else {
            putchar(c);
        }
    }

    freetable();
    return 0;
}