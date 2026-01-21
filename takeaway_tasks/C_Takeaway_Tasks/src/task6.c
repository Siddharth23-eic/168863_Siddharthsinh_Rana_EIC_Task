/* Owner: Siddharthsinh Rana
   Topic: C Take Away(File Encryption System)
   Date: 22/12/2025
   Task: 6
   Description: Create a secure delete checks file name and it's owner for the permission.db file and from that it will check that current user matches the owner name if yes then let user securely delete the file.
 */

#include "../include/system.h"

int32_t secure_delete(const char *filename, const char *username) {
    if (!filename || !username) {
        return 2;
    }
    if (access(filename, F_OK) != 0) {
        return 1;
    }

    FILE *fp = fopen(filename, "r+");
    if (!fp) {
        return 3;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    for (long i = 0; i < size; i++){
        fputc(0, fp);
    }

    fclose(fp);
    unlink(filename);
    return 0;
}
