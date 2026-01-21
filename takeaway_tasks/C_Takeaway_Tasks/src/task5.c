/* Owner: Siddharthsinh Rana
   Topic: C Take Away(File Encryption System)
   Date: 22/12/2025
   Task: 5
   Description: Make a log of every operation happening in this secure file system.  
*/

#include "../include/system.h"

int32_t log_operation(const char *username,
                      const char *operation,
                      const char *filename) {
    if (!username || !operation || !filename) {
        return 1;
    }

    FILE *fp = fopen("operations.log", "a");
    if (!fp) {
        return 2;
    }

    time_t now = time(NULL);
    fprintf(fp, "%ld | %s | %s | %s\n",
            (int64_t)now, username, operation, filename);
    fclose(fp);
    chmod("operations.log", 0600);
    return 0;
}
