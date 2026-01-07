#include "ministdio.h"
#include <stdint.h>

FILE _iob[OPEN_MAX] = {
    {0, 0, 0, {1,0,0,0,0}, 0}, /* For read mode */
    {0, 0, 0, {0,1,0,0,0}, 1}, /* For write mode */
    {0, 0, 0, {0,1,1,0,0}, 2}, /* For write and unbuffered mode */
};

FILE *fopen(char *name, char *mode){
    int32_t fd;
    FILE *fp;

    for(fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if(!fp->flag.read && !fp->flag.write) /* Find free slot in _iob[] */
            break;
    
    if(fp >= _iob + OPEN_MAX)
        return NULL;

    if(*mode == 'r')
        fd = open(name, O_RDONLY);
    else if(*mode == 'w')
        fd = creat(name, 0666);
    else
        return NULL;

    if(fd == -1)
        return NULL;

    /* Preparing the FILE entry for a new open file */
    fp->fd = fd;
    fp->cunt = 0; /* No byte in buffer */
    fp->base = NULL; /* No buffer allocated yet */
    fp->ptr = NULL;

    fp->flag.read = (*mode == 'r');
    fp->flag.write = (*mode == 'w');
    fp->flag.unbuf = 0;
    fp->flag.eof = 0;
    fp->flag.err = 0;

    return fp;
}

int32_t _fillbuf(FILE *fp){
    int32_t bufsize;

    /* check if file is readble */
    if(!fp->flag.read || fp->flag.eof || fp->flag.err)
        return EOF;

    /* Choose buffer size */
    bufsize = fp->flag.unbuf ? 1 : BUFSIZ;

    if(fp->base == NULL){
        
        /* Allocate the buffer first time */
        fp->base = malloc(bufsize);
        if(!fp->base){
            fp->flag.err = 1;
            return EOF;
        }
    }

    fp->ptr = fp->base;
    fp->cunt = read(fp->fd, fp->ptr, bufsize);

    /* Setting flag eof and err */
    if(fp->cunt <= 0){
        fp->flag.eof = (fp->cunt == 0);
        fp->flag.err = (fp->cunt < 0);
        fp->cunt = 0;
        return EOF;
    }
    /* returns first character */
    fp->cunt--;
    return (unsigned char)*fp->ptr++;
}

int32_t _flushbuf(int32_t chr, FILE *fp){
    int32_t bufsize, n;

    /* check if file is writable */
    if(!fp->flag.write || fp->flag.eof || fp->flag.err)
        return EOF;

    /* Choosing the buffer size */
    bufsize = fp->flag.unbuf ? 1 : BUFSIZ;

    /* Allocate buffer if not allocated */
    if(fp->base == NULL){
        fp->base = malloc(bufsize);
        if(!fp->base){
            fp->flag.unbuf = 1; /* setting unbuf flag if buff is not allocated */
        } else{
            fp->ptr = fp->base;
            fp->cunt = bufsize - 1;
        }
    }

    /* If unbuf flag then write it */
    if(fp->flag.unbuf){
        char ch = chr;
        n = write(fp->fd, &ch, 1);
        if(n != 1){
            fp->flag.err = 1;
            return EOF;
        }
        return ch;
    }

    /* Write full buffer */
    n = write(fp->fd, fp->base, fp->ptr - fp->base);
    if(n != (fp->ptr - fp->base)){
        fp->flag.err = 1;
        return EOF;
    }

    /* Resetting the buffer */
    fp->ptr = fp->base;
    fp->cunt = bufsize - 1;
    *fp->ptr++ = chr;

    return chr;
}

int32_t fflush(FILE *fp){
    if(fp == NULL){
        /* flush all writable streams */
        for(fp = _iob; fp < _iob + OPEN_MAX; fp++)
            if(fp->flag.write)
                fflush(fp);
        return 0;
    }
    if(!fp->flag.write)
        return EOF;

    return _flushbuf(0, fp);
}

int32_t fclose(FILE *fp){
    int32_t temchr = 0;
    if(fp->flag.write)
        temchr = fflush(fp);
    
    close(fp->fd);

    /* Freeing the slots */
    fp->flag.read = 0;
    fp->flag.write = 0;
    fp->flag.unbuf = 0;
    fp->flag.eof = 0;
    fp->flag.err = 0;

    fp->cunt = 0;
    fp->ptr = NULL;
    fp->base = NULL;

    return temchr;
}

int32_t fseek(FILE *fp, long offset, int32_t origin){
    long position;

    /* If writing, flush first to avoid losing data */
    if(fp->flag.write){
        if(fflush(fp) == EOF)
            return EOF;
    }

    /* If reading, discard unread buffer */
    if(fp->flag.read){
        fp->cunt = 0;
        fp->ptr = fp->base;
        fp->flag.eof = 0;
    }

    /* Move file position */
    position = lseek(fp->fd, offset, origin);
    if(position == -1)
        return EOF;
    
    return 0;
}