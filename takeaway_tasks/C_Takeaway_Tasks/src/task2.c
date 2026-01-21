/* Owner: Siddharthsinh Rana
   Topic: C Take Away(File Encryption System)
   Date: 22/12/2025
   Task: 2
   Description: Enter a plain text and key to encrypt plain text and then save the encrypted text in the file.  
*/

#include "../include/system.h"

int32_t create_encrypted_file(const char *filename,
                              const char *text,
                              uint16_t key,
                              const char *owner) {
    if (!filename || !text || !owner) {
        return 2;
    }
    if (access(filename, F_OK) == 0) {
        return 1;
    }

    int32_t fd = open(filename, O_CREAT | O_EXCL | O_WRONLY, 0600);
    if (fd < 0) {
        return 3;
    }

    char *enc = xor_encrypt(text, key);
    if (!enc) {
        close(fd);
        return 3;
    }

    write(fd, enc, strlen(enc));
    write(fd, &key, sizeof(uint16_t)); 
    close(fd);
    free(enc);

    FILE *pf = fopen("permissions.db", "a");
    if (pf) {
        fprintf(pf, "%s:%s:rw\n", filename, owner);
        fclose(pf);
        chmod("permissions.db", 0600);
    }
    return 0;
}