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
#include "../utils/utils.h"

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
	printf("Printing UP SORTED array\n");
	hsort(src,len,HSORT_UP);
	print_arr(src,len);
	printf("Printing DOWN SORTED array\n");
	hsort(src,len,HSORT_DOWN);
	print_arr(src,len);
	free(src);
	return EXIT_SUCCESS;
}

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  Heap sort
 *
 * @Param src array to sort
 * @Param len length of the array to sort
 * @Param mode Up or Down sorting
 */
/*
 ----------------------------------------------------------------------------*/
void hsort(int32_t *src, size_t len, h_mode_t mode){
	if (mode == HSORT_UP)
		max_heap_sort(src,len);
	else
		min_heap_sort(src,len);
}

/* --------------------------------------------------------------------------*/
/**
 * @synopsis  it implements the max heapify function on a simple node of the 
 * heap (running time lg(n))
 *
 * @param max_heap the heap
 * @param i the node to heapify
 */
/*
 ----------------------------------------------------------------------------*/
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

/* --------------------------------------------------------------------------*/
/** 
* @synopsis  it implements the min heapify function on a simple node of the 
 * heap (running time lg(n))
 *
 * @param min_heap the heap
 * @param i the node to heapify
 */
/*
 ----------------------------------------------------------------------------*/
void min_heapify(heap *min_heap, int32_t i){
	uint32_t L;
	uint32_t R;
	uint32_t smallest;
	uint32_t tmp;
	L = 2*i + 1;
	R = 2*i + 2;
	if ((L < min_heap->size) &&
	    *(min_heap->head + L) < *(min_heap->head + i))
		smallest = L;
	else
		smallest = i;
	if ((R < min_heap->size) &&
	    *(min_heap->head + R) < *(min_heap->head + smallest))
		smallest = R;
	if (smallest != i){
		tmp = *(min_heap->head + i);
		*(min_heap->head + i) = *(min_heap->head + smallest);
		*(min_heap->head + smallest) = tmp;
		min_heapify(min_heap,smallest);
	}
}


/* --------------------------------------------------------------------------*/
/**
 * @Synopsis It builds a max heap from an arbitrary array (running time linear) 
 *
 * @Param src The arbitrary array
 * @Param len The size of the array
 *
 * @Returns   The max heap
 */
/*
 ----------------------------------------------------------------------------*/
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

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis It builds a min heap from an arbitrary array (running time linear)
 *
 * @Param src The arbitrary array
 * @Param len The size of the array
 *
 * @Returns   The min heap
 */
/*
 ----------------------------------------------------------------------------*/
heap *build_min_heap(int32_t *src, size_t len){
	heap *min_heap;
	int32_t i;
	min_heap = (heap *) malloc(sizeof(heap));
	min_heap->size = len;
	min_heap->head = src;
	for (i = len/2 - 1; i >= 0; i--){
		min_heapify(min_heap, i);
	}
	return min_heap;
}


/* --------------------------------------------------------------------------*/
/**
 * @Synopsis It extracts the maximum value of max heap (running time lg(n))
 *
 * @Param max_heap The heap
 * @Param max pointer to the address where we want to store the max value
 *
 * @Returns   EXIT_FAILURE if not found, EXIT_SUCCESS if everything alright
 */
/*
 ----------------------------------------------------------------------------*/
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

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  It extracts the minimum value of min heap (running time lg(n))
 *
 * @Param min_heap The heap
 * @Param min pointer to the address where we want to store the min value
 *
 * @Returns  EXIT_FAILURE if not found, EXIT_SUCCESS if everything alright
 */
/*
 ----------------------------------------------------------------------------*/
int32_t heap_extract_min(heap *min_heap, int32_t *min){
	if (min_heap->size < 1){
		perror("Min heap underflow\n");
		return EXIT_FAILURE;
	}
	else {
		*min = *(min_heap->head);
		*(min_heap->head) = *(min_heap->head + min_heap->size - 1);
		min_heap->size--;
		min_heapify(min_heap,0);
		return EXIT_SUCCESS;
	}
}


/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  Max heap sort based on a max heap
 *
 * @Param src the array to be max sorted
 * @Param len the size of the array
 */
/*
 ----------------------------------------------------------------------------*/
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

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  Min sort based on min heap
 *
 * @Param src The array to be min sorted
 * @Param len The size of the array
 */
/*
 ----------------------------------------------------------------------------*/
void min_heap_sort(int32_t *src, size_t len){
	heap *min_heap;
	int32_t i;
	int32_t tmp;
	min_heap = build_min_heap(src,len);
	for (i = len - 1; i >= 1; i--) {
		tmp = *(min_heap->head);
		*(min_heap->head) = *(min_heap->head + i);
		*(min_heap->head + i) = tmp;
		min_heap->size--;
		min_heapify(min_heap,0);
	}
	free(min_heap);
}

