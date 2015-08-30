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

typedef struct heap {
	size_t size;
	int32_t *head;
} heap;

void max_heapify(heap *max_heap, int32_t i);
heap *build_max_heap(int32_t *src, size_t len);
int32_t heap_extract_max(heap *max_heap, int32_t *max);
void max_heap_sort(int32_t *src, size_t len);
