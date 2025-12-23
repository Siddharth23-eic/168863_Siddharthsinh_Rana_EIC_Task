#include "include/system.h"

int main(void) {
    char username[50];
    char password[50];
    int32_t choice = -1;

    /* ---------- First Menu for Login/Register ---------- */
    printf("Welcome! Please choose an option:\n");
    printf("1. Login\n");
    printf("2. Register\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        /* User Login */
        printf("Enter username: ");
        scanf("%49s", username);

        /* Check if user exists */
        if (login_user(username, "dummy") == 3) {
            printf("Error: User does not exist. Exiting.\n");
            return 1;
        }

        /* Now ask for the password */
        printf("Enter password: ");
        scanf("%49s", password);

        /* Validate login credentials */
        if (login_user(username, password) != 0) {
            printf("Login failed. Incorrect username or password.\n");
            return 1;
        }
        printf("Login successful!\n");
    }

    else if (choice == 2) {
        /* User Registration */
        printf("Enter new username: ");
        scanf("%49s", username);

        printf("Enter new password: ");
        scanf("%49s", password);

        /* Register user */
        if (register_user(username, password) != 0) {
            printf("Registration failed.\n");
            return 1;
        }
        printf("Registration successful. Please run the program again to log in.\n");
        return 0; // Exit after successful registration
    }

    else {
        printf("Invalid choice. Exiting...\n");
        return 1; // Exit if the user doesn't choose 1 or 2
    }

    /* ---------- Main Menu After Successful Login ---------- */
    while (1) {
        printf("\n--- MENU ---\n");
        printf("0. Exit\n");
        printf("1. Terminal XOR encrypt/decrypt\n");
        printf("2. Create encrypted file\n");
        printf("3. Read encrypted file\n");
        printf("4. Append to encrypted file\n");
        printf("5. Secure delete file\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting...\n");
            break;
        }

        /* ---------- Option 1: Terminal XOR encrypt/decrypt ---------- */
        if (choice == 1) {
            char text[256];
            uint16_t key;

            printf("Enter text: ");
            scanf(" %[^\n]", text);
            printf("Enter 16-bit key: ");
            scanf("%hu", &key);

            char *enc = xor_encrypt(text, key);
            if (!enc) {
                printf("Encryption failed\n");
                continue;
            }

            char *dec = xor_decrypt(enc, key);
            printf("Encrypted: %s\n", enc);
            printf("Decrypted: %s\n", dec);

            free(enc);
            free(dec);
        }

        /* ---------- Option 2: Create encrypted file ---------- */
        else if (choice == 2) {
            char filename[100];
            char text[256];
            uint16_t key;

            printf("Filename: ");
            scanf("%99s", filename);
            printf("Text: ");
            scanf(" %[^\n]", text);
            printf("Key: ");
            scanf("%hu", &key);

            if (create_encrypted_file(filename, text, key, username) == 0) {
                printf("File created successfully\n");
                log_operation(username, "CREATE", filename);
            } else {
                printf("Failed to create file\n");
            }
        }

        /* ---------- Option 3: Read encrypted file ---------- */
        else if (choice == 3) {
            char filename[100];
            uint16_t key;

            printf("Filename: ");
            scanf("%99s", filename);
            printf("Key: ");
            scanf("%hu", &key);

            char *data = read_encrypted_file(filename, key);
            if (!data) {
                printf("Read failed (wrong key or file error)\n");
            } else {
                printf("Decrypted content: %s\n", data);
                log_operation(username, "READ", filename);
                free(data);
            }
        }

        /* ---------- Option 4: Append to encrypted file ---------- */
        else if (choice == 4) {
            char filename[100];
            char text[256];
            uint16_t key;

            printf("Filename: ");
            scanf("%99s", filename);
            printf("Append text: ");
            scanf(" %[^\n]", text);
            printf("Key: ");
            scanf("%hu", &key);

            if (append_to_encrypted_file(filename, key, text) == 0) {
                printf("Append successful\n");
                log_operation(username, "APPEND", filename);
            } else {
                printf("Append failed\n");
            }
        }

        /* ---------- Option 5: Secure delete file ---------- */
        else if (choice == 5) {
            char filename[100];

            printf("Filename to delete: ");
            scanf("%99s", filename);

            if (secure_delete(filename, username) == 0) {
                printf("File securely deleted\n");
                log_operation(username, "DELETE", filename);
            } else {
                printf("Delete failed\n");
            }
        }

        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
