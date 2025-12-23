/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 02/12/2025
 * Chapter: 8
 * Exercise: 8.5
 * Description: Modify the fsize program to print the other information contained in the inode entry.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "dirent1.h"

#define MAX_PATH 1024

void fsize(const char *name);
void dirwalk(const char *dir, void (*fcn)(const char *));

void fsize(const char *name)
{
    struct stat st;

    if (stat(name, &st) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }

    if ((st.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);

    printf("%8ld %8ld %8ld %8o %8d %8ld %s\n",
        (long)st.st_size, 
        (long)st.st_blocks,
        (long)st.st_blksize,
        st.st_mode,
        st.st_gid,
        (long)st.st_nlink,
        name
    );
}

void dirwalk(const char *dir, void (*fcn)(const char *))
{
    char path[MAX_PATH];
    CDIR *dp;
    CDirent *d;

    dp = opendir_c(dir);
    if (!dp) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }

    while ((d = readdir_c(dp)) != NULL) {

        if (strcmp(d->name, ".") == 0 || strcmp(d->name, "..") == 0)
            continue;

        if (snprintf(path, sizeof(path), "%s/%s", dir, d->name) >= sizeof(path)) {
            fprintf(stderr, "dirwalk: name too long: %s/%s\n", dir, d->name);
            continue;
        }

        fcn(path);
    }

    closedir_c(dp);
}

int32_t exercise8_5(int32_t argc, char *argv[]) {
    if (argc == 1){
        printf("Run it like -> ./a.out dirname");
        return 1;
    }
    else
        while (--argc > 0)
            fsize(*++argv);
    return 0;
}