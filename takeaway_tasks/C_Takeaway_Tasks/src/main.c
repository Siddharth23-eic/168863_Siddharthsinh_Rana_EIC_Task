/* Owner: Siddharthsinh Rana 
   Date: 23/12/2025
   Topic: Binary tree takeaways
   Description: Main file for running the C takeaway tasks and all the related files.
*/

#include "../include/system.h"

int main(void) {
    char username[50];
    char password[50];
    int32_t choice = -1;
    int32_t logged_in = 0;


    /* ---------- First Menu for Login/Register ---------- */
    while(1){
        while(!logged_in){
            printf("Welcome!, Select one of the options: \n");
            printf("0. Exit\n1. Login\n2. Register\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if(choice == 0){
                printf("Exiting....\n");
                return 0;
            }
            else if(choice == 1){
                printf("Enter username: ");
                scanf("%49s", username);

                if(login_user(username, "dummy") == 3){
                    printf("Error: User does not exist.\n");
                    continue;
                }

                printf("Enter password: ");
                scanf("%49s", password);

                if(login_user(username, password) != 0){
                    printf("Error: Invalid credentials.\n");
                    continue;
                }

                printf("Login Successful!\n");
                logged_in = 1;
            }

            else if(choice == 2){
                printf("Enter new username: ");
                scanf("%49s", username);

                printf("Enter new password: ");
                scanf("%49s", password);

                if(register_user(username, password) != 0){
                    printf("Error: Registeration failed.\n");
                }else{
                    printf("Registration successful! please login.\n");
                }
            }
            else{
                printf("Invaid choice");
            }
        }
        /* ================= MAIN MENU ================= */
        while (logged_in) {
            printf("\n--- MAIN MENU ---\n");
            printf("0. Exit\n");
            printf("1. Terminal XOR encrypt/decrypt\n");
            printf("2. Create encrypted file\n");
            printf("3. Read encrypted file\n");
            printf("4. Append to encrypted file\n");
            printf("5. Secure delete file\n");
            printf("6. Logout\n");
            printf("Choice: ");
            scanf("%d", &choice);

            /* -------- EXIT PROGRAM -------- */
            if (choice == 0) {
                printf("Exiting...\n");
                return 0;
            }

            /* -------- XOR TERMINAL -------- */
            else if (choice == 1) {
                char text[256];
                uint16_t key;

                printf("Enter text: ");
                scanf(" %[^\n]", text);

                printf("Enter 16-bit key: ");
                scanf("%hu", &key);

                char *enc = xor_encrypt(text, key);
                if (!enc) {
                    printf("Encryption failed.\n");
                    continue;
                }

                char *dec = xor_decrypt(enc, key);

                printf("Encrypted: %s\n", enc);
                printf("Decrypted: %s\n", dec);

                free(enc);
                free(dec);
            }

            /* -------- CREATE FILE -------- */
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
                    printf("File created successfully.\n");
                    log_operation(username, "CREATE", filename);
                } else {
                    printf("Failed to create file.\n");
                }
            }

            /* -------- READ FILE -------- */
            else if (choice == 3) {
                char filename[100];
                uint16_t key;

                printf("Filename: ");
                scanf("%99s", filename);

                printf("Key: ");
                scanf("%hu", &key);

                char *data = read_encrypted_file(filename, key);
                if (!data) {
                    printf("Read failed (wrong key or file error).\n");
                } else {
                    printf("Decrypted content: %s\n", data);
                    log_operation(username, "READ", filename);
                    free(data);
                }
            }

            /* -------- APPEND FILE -------- */
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
                    printf("Append successful.\n");
                    log_operation(username, "APPEND", filename);
                } else {
                    printf("Append failed.\n");
                }
            }

            /* -------- DELETE FILE -------- */
            else if (choice == 5) {
                char filename[100];

                printf("Filename to delete: ");
                scanf("%99s", filename);

                if (secure_delete(filename, username) == 0) {
                    printf("File securely deleted.\n");
                    log_operation(username, "DELETE", filename);
                } else {
                    printf("Delete failed.\n");
                }
            }

            /* -------- LOGOUT -------- */
            else if (choice == 6) {
                printf("Logged out.\n");
                logged_in = 0;
            }

            else {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}