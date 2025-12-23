#ifndef MINISTDIO_H
#define MINISTDIO_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/* Macros needed for the file operation */
#define NULL 0
#define EOF  (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20

/* bit-field flags */
typedef struct {
    unsigned read  : 1;
    unsigned write : 1;
    unsigned unbuf : 1;
    unsigned eof   : 1;
    unsigned err   : 1;
} Flags;

/* minimal FILE structure */
typedef struct _iobuf {
    int   cunt; /* Characters left in buffer */
    char *ptr; /* pointer to next unread character  */
    char *base; /* Pointer to buffer start */
    Flags flag; /* bit-field for bit masks */
    int   fd; /* File descriptor  */
} FILE;

/* global file table */
extern FILE _iob[OPEN_MAX];

/* macros for standard input, output and error */
#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

/* if data in buffer then return it else call _fillbuf */
#define getc(p)   (--(p)->cunt >= 0 ? *(p)->ptr++ : _fillbuf(p))
#define getchar() getc(stdin)

/* Writes characters in file else flush */
#define putc(x,p) (--(p)->cunt >= 0 ? (*(p)->ptr++ = (x)) : _flushbuf((x), (p)))
#define putchar(x) putc((x), stdout)


FILE *fopen(char *name, char *mode);
int32_t _fillbuf(FILE *fp);
int32_t _flushbuf(int32_t chr, FILE *fp);
int32_t fflush(FILE *fp);
int32_t fclose(FILE *fp);
int32_t fseek(FILE *fp, long offset, int origin);

#endif