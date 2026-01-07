#ifndef DIRENT1_H
#define DIRENT1_H

#include <sys/types.h>
#include <limits.h>

#ifndef NAME_MAX
#define NAME_MAX 255
#endif

typedef struct {
    ino_t ino;                 /* inode number */
    char  name[NAME_MAX + 1];  /* filename */
} CDirent;

typedef struct {
    void *sysdir;              /* DIR* internally */
} CDIR;

CDIR    *opendir_c(const char *dirname);
CDirent *readdir_c(CDIR *dp);
void    closedir_c(CDIR *dp);

#endif