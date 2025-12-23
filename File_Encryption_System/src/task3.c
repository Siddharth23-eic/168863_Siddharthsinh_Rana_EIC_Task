/* Owner: Siddharthsinh Rana
   Topic: C Take Away(File Encryption System)
   Date: 22/12/2025
   Task: 3
   Description: Read the encrypted text from the encrypted file provide appropriate key and display the decrypted text.  
*/

#include "../include/system.h"

char *read_encrypted_file(const char *filename, uint16_t key) {
    if (!filename) return NULL;

    FILE *fp = fopen(filename, "rb");
    if (!fp) return NULL;

    fseek(fp, -((long)sizeof(uint16_t)), SEEK_END);
    uint16_t stored_key;
    fread(&stored_key, sizeof(uint16_t), 1, fp);
    if (stored_key != key) {
        fclose(fp);
        return NULL;
    }

    long size = ftell(fp);
    rewind(fp);

    char *enc = malloc(size + 1);
    fread(enc, 1, size, fp);
    fclose(fp);
    enc[size] = '\0';

    char *dec = xor_decrypt(enc, key);
    free(enc);
    return dec;
}