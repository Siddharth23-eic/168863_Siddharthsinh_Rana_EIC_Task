/* Owner: Siddharthsinh Rana 
* Task: Data Structures 
* Created Date: 11/12/2025 
* Topic: Queue 
* Description: A palindrome is a string that reads the same backward as forward, 
e.g. "ABCBA" or "Madam, I'm Adam". 
Your application will read strings from the user, 
and for each string the user inputs, 
it should print a message indicating to the user whether or not the string is a palindrome. 
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "queue.h"

#define SIZE 1000

int main() {
    Queue org, rev;
    initqueue(&org);
    initqueue(&rev);

    char str[SIZE], clean[SIZE];
    fgets(str, SIZE, stdin);

    int n = 0;

    /*Filtering the alphabet part and converting it to the lower */
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            clean[n++] = tolower(str[i]);
        }
    }

    /* Original String */
    for (int i = 0; i < n; i++) {
        enqueue(&org, clean[i]);
    }

    /* Storing in reverse order */
    for (int i = n - 1; i >= 0; i--) {
        enqueue(&rev, clean[i]);
    }

    /* Comaparing two queues */
    while (!isempty(&org) && !isempty(&rev)) {
        if (dequeue(&org) != dequeue(&rev)) {
            printf("Not palindrome\n");
            return 0;
        }
    }

    printf("Palindrome\n");
    return 0;
}
