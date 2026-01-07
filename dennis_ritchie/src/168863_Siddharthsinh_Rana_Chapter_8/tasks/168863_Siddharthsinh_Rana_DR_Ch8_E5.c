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
#include <unistd.h>
#include "dirent1.h"

#define MAX_PATH 1024

void fsize(const char *name);
void dirwalk(const char *dir, void (*fcn)(const char *));

void fsize(const char *name){
    struct stat st;

    /* lstat so symlinks don't explode recursion */
    if (lstat(name, &st) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }

    /* Print inode information */
    printf("%8lu %4ld %4d %4d %8ld %06o %s\n",
        (unsigned long)st.st_ino,     /* inode number */
        (long)st.st_nlink,            /* link count */
        st.st_uid,                    /* owner */
        st.st_gid,                    /* group */
        (long)st.st_size,             /* file size */
        st.st_mode & 07777,           /* permissions */
        name
    );

    /* Recurse AFTER printing */
    if (S_ISDIR(st.st_mode))
        dirwalk(name, fsize);
}

void dirwalk(const char *dir, void (*fcn)(const char *)){
    char path[MAX_PATH];
    CDIR *dp;
    CDirent *d;

    if ((dp = opendir_c(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }

    while ((d = readdir_c(dp)) != NULL) {

        if (strcmp(d->name, ".") == 0 || strcmp(d->name, "..") == 0)
            continue;

        if (snprintf(path, sizeof(path), "%s/%s", dir, d->name)
            >= sizeof(path)) {
            fprintf(stderr, "dirwalk: name too long: %s/%s\n", dir, d->name);
            continue;
        }

        fcn(path);
    }

    closedir_c(dp);
}

int32_t exercise8_5(int32_t argc, char *argv[]){
    if (argc == 1) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    while (--argc > 0)
        fsize(*++argv);

    return 0;
}