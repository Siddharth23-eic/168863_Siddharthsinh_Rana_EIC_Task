/* Owner: Siddharthsinh Rana 
   Date: 03/01/2026
   Topic: Binary tree takeaways
   Description: Functions to play the game Super 20.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "question_tree.h"

static char *readLine(FILE *fp){
    char buffer[512];

    if(!fgets(buffer, sizeof(buffer), fp)){
        return NULL;
    }

    buffer[strcspn(buffer, "\n")] = '\0';
    return strdup(buffer);
}

TreeGame *buildTree(FILE *fp){
    char *line = readLine(fp);
    if(!line){
        return NULL;
    }

    TreeGame *node = malloc(sizeof(TreeGame));
    node->yes = node->no = NULL;

    if(line[0] == 'Q'){
        node->data = strdup(line + 2);
        free(line);

        /* Sub tree for yes */
        node->yes = buildTree(fp);
        
        /* Sub tree for no */
        node->no = buildTree(fp);
    }else{
        node->data = strdup(line + 2);
        free(line);
    }
    return node;
}

static int askYN(const char *prompt){
    char answer[16];

    printf("%s (y/n): ", prompt);
    if(!fgets(answer, sizeof(answer), stdin)){
        return askYN(prompt);
    }

    if(tolower(answer[0]) == 'y'){
        return 1;
    }
    if(tolower(answer[0]) == 'n'){
        return 0;
    }

    printf("Please answer yes or no.\n");
    return askYN(prompt);
}

static void learn(TreeGame *node){
    char newObj[128];
    char newQue[128];

    printf("I lost. what were you thinking of? ");
    if(!fgets(newObj, sizeof(newObj), stdin)){
        return;
    }
    newObj[strcspn(newObj, "\n")] = '\0';

    printf("Give me a yes/no question to distingush %s from %s: \n", newObj, node->data);
    if(!fgets(newQue, sizeof(newObj), stdin)){
        return;
    }
    newQue[strcspn(newQue, "\n")] = '\0';

    int32_t answer = askYN("What is the answer for your object?");

    /* Old incorrect answer */
    TreeGame *oldAns = malloc(sizeof(TreeGame));
    oldAns->data = strdup(node->data);
    oldAns->yes = oldAns->no = NULL;
  
    /* New correct answer */
    TreeGame *newAns = malloc(sizeof(TreeGame));
    newAns->data = strdup(newObj);
    newAns->yes = newAns->no = NULL;

    /* Freeing old string */
    free(node->data);
    node->data = strdup(newQue);

    if(answer){
        node->yes = newAns;
        node->no = oldAns;
    }else{
        node->yes = oldAns;
        node->no = newAns;
    }
}

void playGame(TreeGame *root){
    if(!root->yes && !root->no){
        char guess[256];
        snprintf(guess, sizeof(guess), "Are you think of %s", root->data);

        if(askYN(guess)){
            printf("I win\n");
        }else{
            learn(root);
        }
        return;
    }

    if(askYN(root->data)){
        playGame(root->yes);
    }else{
        playGame(root->no);
    }
}

void writeTree(FILE *fp, TreeGame *root){
    if(!root){
        return;
    }

    if(root->yes && root->no){
        fprintf(fp, "Q:%s\n", root->data);
        writeTree(fp, root->yes);
        writeTree(fp, root->no);
    }else {
        fprintf(fp, "A:%s\n", root->data);
    }
}

void freeTree(TreeGame *root){
    if(!root){
        return;
    }
    freeTree(root->yes);
    freeTree(root->no);
    free(root->data);
    free(root);
}
