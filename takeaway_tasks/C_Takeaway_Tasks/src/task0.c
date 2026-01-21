/* Owner: Siddharthsinh Rana
   Topic: C Take Away(File Encryption System)
   Date: 22/12/2025
   Task: 0
   Description: User Authentication(Register and login), Saving the user name in normal text and password in hash format in the users.db file. 
*/

#include "../include/system.h"

#define USERS_DB "users.db"

static void sha256_hash(const char *password, char *output_hex) {
    uint8_t hash[SHA256_DIGEST_LENGTH];
    SHA256((const uint8_t *)password, strlen(password), hash);

    for (uint8_t i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output_hex + (i * 2), "%02x", hash[i]);
    }
    output_hex[64] = '\0';
}

int32_t register_user(const char *username, const char *password) {
    if (!username || !password || strlen(username) == 0 || strlen(password) == 0){
        return 2;
    }
    FILE *fp = fopen(USERS_DB, "r");
    if (fp) {
        char line[256];
        while (fgets(line, sizeof(line), fp)) {
            if (strncmp(line, username, strlen(username)) == 0 && line[strlen(username)] == ':') {
                fclose(fp);
                return 1;
            }
        }
        fclose(fp);
    }

    fp = fopen(USERS_DB, "a");
    if (!fp){
        return 3;
    }

    char hash_hex[65];
    sha256_hash(password, hash_hex);
    fprintf(fp, "%s:%s\n", username, hash_hex);
    fclose(fp);
    chmod(USERS_DB, 0600);
    return 0;
}

int32_t login_user(const char *username, const char *password) {
    if (!username || !password || strlen(username) == 0 || strlen(password) == 0){
        return 2;
    }

    FILE *fp = fopen(USERS_DB, "r");
    if (!fp) {
        return 3;
    }

    char line[256];
    char hash_hex[65];
    sha256_hash(password, hash_hex);

    while (fgets(line, sizeof(line), fp)) {
        char *u = strtok(line, ":");
        char *h = strtok(NULL, "\n");
        if (u && h && strcmp(u, username) == 0) {
            fclose(fp);
            return (strcmp(h, hash_hex) == 0) ? 0 : 1;
        }
    }
    fclose(fp);
    return 3;
}
