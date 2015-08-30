/*
 * =====================================================================================
 *
 *       Filename:  heap.c
 *
 *    Description:  Introduction to algorithms: Heap implementation
 *
 *        Version:  1.0
 *        Created:  25.08.2015 22:39:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Romel J. Torres (rtorres), torres.romel@gmail.com
 *   Organization:  -
 *
 * =====================================================================================
 */


#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "hsort.h"

int main(int argc, char *argv[])
{
	int32_t *src;
	int32_t max;
	size_t len;
	int32_t i;
	if(argc < 3){
		printf("Correct Usage hsort len max\n");
		perror("Incorrect hsort.c usage");
		return EXIT_FAILURE;
	}
	len = (size_t) atoi(argv[1]);
	max = (int32_t) atoi(argv[2]);
	printf("Creating random array of length %d and contrained to %d\n",
	       (int) len, (int) max);
	src = cr_rnd_arr(len,max);
	print_arr(src, len);
	max_heap_sort(src,len);
	print_arr(src,len);
	free(src);
	return EXIT_SUCCESS;
}

void max_heapify(heap *max_heap, int32_t i){
	uint32_t L;
	uint32_t R;
	uint32_t largest;
	uint32_t tmp;
	L = 2*i + 1;
	R = 2*i + 2;
	if ((L < max_heap->size) &&
	    *(max_heap->head + L) > *(max_heap->head + i))
		largest = L;
	else
		largest = i;
	if ((R < max_heap->size) &&
	    *(max_heap->head + R) > *(max_heap->head + largest))
		largest = R;
	if (largest != i){
		tmp = *(max_heap->head + i);
		*(max_heap->head + i) = *(max_heap->head + largest);
		*(max_heap->head + largest) = tmp;
		max_heapify(max_heap,largest);
	}
}

heap *build_max_heap(int32_t *src, size_t len){
	heap *max_heap;
	int32_t i;
	max_heap = (heap *) malloc(sizeof(heap));
	max_heap->size = len;
	max_heap->head = src;
	for (i = len/2 - 1; i >= 0; i--){
		max_heapify(max_heap, i);
	}
	return max_heap;
}

int32_t heap_extract_max(heap *max_heap, int32_t *max){
	if (max_heap->size < 1){
		perror("Max heap underflow\n");
		return EXIT_FAILURE;
	}
	else {
		*max = *(max_heap->head);
		*(max_heap->head) = *(max_heap->head + max_heap->size - 1);
		max_heap->size--;
		max_heapify(max_heap,0);
		return EXIT_SUCCESS;
	}
}

void max_heap_sort(int32_t *src, size_t len){
	heap *max_heap;
	int32_t i;
	int32_t tmp;
	max_heap = build_max_heap(src,len);
	for (i = len - 1; i >= 1; i--) {
		tmp = *(max_heap->head);
		*(max_heap->head) = *(max_heap->head + i);
		*(max_heap->head + i) = tmp;
		max_heap->size--;
		max_heapify(max_heap,0);
	}
	free(max_heap);
}
