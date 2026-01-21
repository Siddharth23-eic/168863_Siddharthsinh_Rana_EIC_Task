/* Owner: Siddharthsinh Rana 
   Date: 03/01/2026
   Topic: Binary tree takeaways
   Description: Main file to run the super 20 game
*/


#include <stdio.h>
#include "question_tree.h"

int32_t main(){
    FILE *fp = fopen("Questions.txt", "r");
    if(!fp){
        perror("Questions.txt");
        return 1;
    }

    TreeGame *root = buildTree(fp);
    fclose(fp);

    playGame(root);

    fp = fopen("Questions.txt", "w");
    writeTree(fp, root);
    fclose(fp);

    freeTree(root);
    return 0;
}
