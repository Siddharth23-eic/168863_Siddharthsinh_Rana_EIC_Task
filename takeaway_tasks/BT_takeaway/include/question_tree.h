/* Owner: Siddharthsinh Rana 
   Date: 03/01/2026
   Topic: Binary tree takeaways
   Description: Header file for the functions related to question tree
*/

#ifndef QUESTION_TREE_H
#define QUESTION_TREE_H

#include <stdio.h>
#include <stdint.h>

typedef struct node{
    char *data;
    struct node *yes;
    struct node *no;
}TreeGame;

/* Tree construction */
TreeGame *buildTree(FILE *fp);

/* Playing game function */
void playGame(TreeGame *root);

/* save updated tree */
void writeTree(FILE *fp, TreeGame *root);

/* Cleanup */
void freeTree(TreeGame *root);

#endif