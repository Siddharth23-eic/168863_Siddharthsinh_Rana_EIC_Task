/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 02/12/2025
 * Chapter: 8
 * Exercise: 8.3
 * Description: Design and write _flushbuf, fflush, and fclose.
 */

#include "ministdio.h"
#include <stdint.h>

int exercise8_3(int32_t argc, char* argv[]) {
    if(argc != 3){
        write(2, "Use it like this ./a.out ipfile opfile\n", 39);
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    if(!in || !out){
        write(2, "fopen error\n", 12);
        return 1;
    }

    int32_t ch;
    while((ch = getc(in)) != EOF)
        putc(ch, out);

    fclose(in);
    fclose(out);
    return 0;
}

