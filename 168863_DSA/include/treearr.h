#ifndef TREEARR_H
#define TREEARR_H

#include <stdint.h>

#define TREEARR_MAX 100

/* Create / insert */
void treearr_init(int32_t *size);
void treearr_insert(int32_t arr[], int32_t *size, int32_t data);

/* Traversals */
void treearr_inorder(int32_t arr[], int32_t size, int32_t index);
void treearr_preorder(int32_t arr[], int32_t size, int32_t index);
void treearr_postorder(int32_t arr[], int32_t size, int32_t index);

#endif
