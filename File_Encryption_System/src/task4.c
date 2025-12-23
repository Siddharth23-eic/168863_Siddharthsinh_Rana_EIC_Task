/* Owner: Siddharthsinh Rana
   Topic: C Take Away(File Encryption System)
   Date: 22/12/2025
   Task: 4
   Description: Append the encrypted text into the file which is already encrypted.  
*/

#include "../include/system.h"

int32_t append_to_encrypted_file(const char *filename,
                                 uint16_t key,
                                 const char *new_data) {
    if (!filename || !new_data) return 2;

    char *old = read_encrypted_file(filename, key);
    if (!old) return 4;

    size_t new_len = strlen(old) + strlen(new_data) + 1;
    char *combined = malloc(new_len);
    strcpy(combined, old);
    strcat(combined, new_data);

    unlink(filename);
    int32_t res = create_encrypted_file(filename, combined, key, "unknown");

    free(old);
    free(combined);
    return res;
}