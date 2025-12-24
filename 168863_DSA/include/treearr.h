#ifndef TREEARR_H
#define TREEARR_H

#include <stdint.h>

#define TREEARR_MAX 100

/* Global array tree (defined in treearr.c) */
extern int32_t treearr[TREEARR_MAX];
extern int32_t treearr_size;

/* Core operations */
void treearr_init(void);
void treearr_insert(int32_t data);
int32_t treearr_search(int32_t data);
void treearr_delete(int32_t data);

/* Traversals */
void treearr_inorder(int32_t index);
void treearr_preorder(int32_t index);
void treearr_postorder(int32_t index);

#endif
