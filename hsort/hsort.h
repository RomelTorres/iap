/*
 * =====================================================================================
 *
 *       Filename:  heap.h
 *
 *    Description:  Header file for the heap
 *
 *        Version:  1.0
 *        Created:  25.08.2015 22:41:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Romel J. Torres (rtorres), torres.romel@gmail.com
 *   Organization:  -
 *
 * =====================================================================================
 */
#include <stdint.h>

#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) x / 2

typedef enum h_mode_t {HSORT_UP, HSORT_DOWN} h_mode_t;

typedef struct heap {
	size_t size;
	int32_t *head;
} heap;

void max_heapify(heap *max_heap, int32_t i);
void min_heapify(heap *min_heap, int32_t i);
heap *build_max_heap(int32_t *src, size_t len);
heap *build_min_heap(int32_t *src, size_t len);
int32_t heap_extract_max(heap *max_heap, int32_t *max);
int32_t heap_extract_min(heap *min_heap, int32_t *min);
void max_heap_sort(int32_t *src, size_t len);
void min_heap_sort(int32_t *src, size_t len);
void hsort(int32_t *src, size_t len, h_mode_t mode);
