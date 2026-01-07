/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 02/12/2025
 * Chapter: 8
 * Exercise: 8.4
 * Description:
 */

#include "ministdio.h"
#include <stdint.h>

int exercise8_4(int32_t argc, char *argv[]) {
    if(argc != 2){
        write(2, "Use it like this -> ./a.out file\n", 33);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if(!fp){
        write(2, "Cannot open file\n", 17);
        return 1;
    }

    /* Printing First 10 character of file */
    write(1, "First 10 characters:\n", 21);

    for(int32_t i = 0; i < 10; i++){
        int32_t chr = getc(fp);
        if(chr == EOF) break;
        write(1, &chr, 1);
    }
    
    write(1, "\n\n", 2);

    /* Seek to position 20 */
    if (fseek(fp, 20, SEEK_SET) == EOF){
        write(2, "fseek failed\n", 13);
        fclose(fp);
        return 1;
    }

    write(1, "New first 10 characters after fseek\n", 37);
    for(int32_t i = 0; i < 10; i++){
        int32_t chr = getc(fp);
        if(chr == EOF) break;
        write(1, &chr, 1);
    }
    write(1, "\n", 1);
    
    fclose(fp);
    return 0;
}