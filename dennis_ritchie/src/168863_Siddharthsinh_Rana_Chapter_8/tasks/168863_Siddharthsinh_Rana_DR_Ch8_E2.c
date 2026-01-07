/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 02/12/2025
 * Chapter: 8
 * Exercise: 8.2
 * Description: Rewrite fopen and _fillbuf with fields instead of explicit bit operations. Compare code size and execution speed. 
 */

#include "ministdio.h"
#include <stdint.h>

int exercise8_2(int32_t argc, char *argv[]) {
    FILE *fp;
    int32_t chr;

    if(argc != 2){
        write(2, "Use it like this ./a.out filename\n", 34);
        return 1;        
    }
    fp = fopen(argv[1], "r");
    if(!fp){
        write(2, "Cannot open file\n", 17);
        return 1;
    }

    while((chr = getc(fp)) != EOF){
        write(1, &chr, 1);
    }
    
    return 0;
}

