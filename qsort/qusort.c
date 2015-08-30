/*
 * =====================================================================================
 *
 *       Filename:  qsort.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  30.08.2015 20:52:39
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
#include "qusort.h"
#include "../utils/utils.h"

int main(int argc, char *argv[]){
	size_t len;
	uint32_t i;
	int32_t *src;
	int32_t max;

	if(argc < 3){
		printf("Correct Usage msort len max\n");
		perror("Incorrect msort.c usage");
		return EXIT_FAILURE;
	}

	len = (size_t) atoi(argv[1]);
        max = (int32_t) atoi(argv[2]);
	printf("Creating random array of input %d and constrained to %d\n",
		(int) len, (int) max);
	src = cr_rnd_arr(len, max);
	print_arr(src,len);
	printf("Printing UP SORTED array\n");
	qusort(src, len,QSORT_UP);
	print_arr(src,len);
	printf("Printing DOWN SORTED array\n");
	qusort(src, len, QSORT_DOWN);
	print_arr(src,len);
	free(src);
	return EXIT_SUCCESS;
}

int32_t partition(int32_t *src, int32_t p, int32_t r, q_mode_t mode){
	int32_t x;
	int32_t i;
	uint32_t j;
	int32_t tmp;
	x = src[r];
	i = p - 1;
	for (j = p; j <= r - 1; j++) {
		if ((src[j] <= x) && (mode == QSORT_UP) ||
			(src[j] >= x) && (mode == QSORT_DOWN)) {
			i++;
			tmp = src[j];
			src[j] = src[i];
			src[i] = tmp;
		}
	}
	tmp = src[r];
	src[r] = src[i + 1];
	src[i + 1] = tmp;
	return (i + 1);
}

void quicksort(int32_t *src, int32_t p, int32_t r, q_mode_t mode){
	int32_t q;
	if (p < r) {
		q = partition(src, p, r, mode);
		quicksort(src, p, q - 1, mode);
		quicksort(src, q + 1, r, mode);
	}
}

void qusort(int32_t *src, size_t len, q_mode_t mode){
	quicksort(src, 0, len-1, mode);
}
