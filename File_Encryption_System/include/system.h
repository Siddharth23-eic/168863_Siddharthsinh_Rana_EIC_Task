#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <openssl/sha.h>

/* Task 0 */
int32_t register_user(const char *username, const char *password);
int32_t login_user(const char *username, const char *password);

/* Task 1 */
char *xor_encrypt(const char *input, uint16_t key);
char *xor_decrypt(const char *input, uint16_t key);

/* Task 2 */
int32_t create_encrypted_file(const char *filename,
                              const char *text,
                              uint16_t key,
                              const char *owner);

/* Task 3 */
char *read_encrypted_file(const char *filename, uint16_t key);

/* Task 4 */
int32_t append_to_encrypted_file(const char *filename,
                                 uint16_t key,
                                 const char *new_data);

/* Task 5 */
int32_t log_operation(const char *username,
                      const char *operation,
                      const char *filename);

/* Task 6 */
int32_t secure_delete(const char *filename, const char *username);

#endif
