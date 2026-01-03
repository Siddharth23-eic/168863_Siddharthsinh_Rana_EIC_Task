/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 30/12/2025
 * Chapter: 6
 * Exercise: 6.5
 * Description: Write a function undef that will remove a name and definition from the table maintained by lookup and install.
 */

#include <stdio.h>
#include <stdint.h>
#include "hashtab.h"

int32_t exercise6_5(void) {
    /* Installing entries in the table */
    install("IN", "0");
    install("OUT", "1");

    printf("before_undef\n");
    printf("IN: %s\n", lookup("IN")->defn);
    printf("OUT: %s\n", lookup("OUT")->defn);

    undef_6("IN");
    
    printf("after_undef\n");
    if(lookup("IN") == NULL)
        printf("IN is undefined\n");

    freetable();
    return 0;
}