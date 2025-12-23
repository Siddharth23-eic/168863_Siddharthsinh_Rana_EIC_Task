#include "dirent1.h"
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>  

/* open directory */
CDIR *opendir_c(const char *dirname){
    DIR *dp = opendir(dirname);
    if (!dp) return NULL;

    CDIR *cd = malloc(sizeof(CDIR));
    if (!cd) {
        closedir(dp);
        return NULL;
    }

    cd->sysdir = dp;
    return cd;
}

/* close directory */
void closedir_c(CDIR *cd)
{
    if (!cd) return;
    
    closedir((DIR *)cd->sysdir);
    free(cd);
}

/* read next entry */
CDirent *readdir_c(CDIR *cd)
{
    static CDirent d;
    struct dirent *entry = readdir((DIR *)cd->sysdir);

    if (!entry) return NULL;

    d.ino = entry->d_ino;
    strncpy(d.name, entry->d_name, NAME_MAX);
    d.name[NAME_MAX] = '\0';

    return &d;
}
