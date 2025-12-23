#ifndef DIRENT_H
#define DIRENT_H

#define NAME_MAX 255

typedef struct {
    long ino;                  /* inode number */
    char name[NAME_MAX + 1];   /* filename */
} CDirent;

typedef struct {
    void *sysdir;
} CDIR;

CDIR    *opendir_c(const char *dirname);
CDirent *readdir_c(CDIR *dp);
void    closedir_c(CDIR *dp);

#endif