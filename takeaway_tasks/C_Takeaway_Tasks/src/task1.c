/* Owner: Siddharthsinh Rana
   Topic: C Take Away(File Encryption System)
   Date: 22/12/2025
   Task: 1
   Description: Enreyption and decryption using xor operation with the 16 bit key and display both encrypted and Decrypted text in the terminal.  
*/

#include "../include/system.h"

char *xor_encrypt(const char *input, uint16_t key) {
    if (!input || strlen(input) == 0) {
        return NULL;
    }

    size_t len = strlen(input);
    char *out = malloc(len * 2 + 1);
    if (!out) {
        return NULL;
    }

    for (size_t i = 0; i < len; i++) {
        uint8_t x = ((uint8_t)input[i]) ^ (uint8_t)(key & 0xFF);
        sprintf(out + (i * 2), "%02x", x);
    }
    out[len * 2] = '\0';
    return out;
}

char *xor_decrypt(const char *input, uint16_t key) {
    if (!input || strlen(input) == 0) {
        return NULL;
    }

    size_t len = strlen(input) / 2;
    char *out = malloc(len + 1);
    if (!out) {
        return NULL;
    }

    for (size_t i = 0; i < len; i++) {
        uint32_t val;
        sscanf(input + (i * 2), "%02x", &val);
        out[i] = (char)((uint8_t)val ^ (uint8_t)(key & 0xFF));
    }
    out[len] = '\0';
    return out;
}
