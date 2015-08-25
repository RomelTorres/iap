/*
 * =====================================================================================
 *
 *       Filename:  msort.c
 *
 *    Description:  Implementation of the merge sort algorithm
 *
 *        Version:  1.0
 *        Created:  16.08.2015 13:38:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Romel J. Torres (rtorres), torres.romel@gmail.com
 *   Organization:  -
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "msort.h"
#include "../utils/utils.h"

int main( int argc, char *argv[] )
{
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
	msort(src, 0, len - 1, MSORT_UP);
	print_arr(src, len);
	printf("Printing DOWN SORTED array\n");
	msort(src, 0, len - 1, MSORT_DOWN);
	print_arr(src, len);
	free(src);
	return EXIT_SUCCESS;
}

/* --------------------------------------------------------------------------*/
/*** @Synopsis  recursive merge sort with a run time of nlog(n)
 *
 * @Param src pointer to array to be sorted
 * @Param start starting point
 * @Param finish finishing point
 * @param mode UP or DOWN mode
 */
/*
 ----------------------------------------------------------------------------*/
void msort(int32_t *src, uint32_t start, uint32_t finish, m_mode_t mode)
{
	uint32_t q;
	if (start < finish){
		q = (uint32_t) (start + finish)/2 ;
		msort(src, start, q, mode);
		msort(src,q + 1, finish, mode);
		merge(src,start,q,finish, mode);
	}
}

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  sorts the sub arrays src[p..q] and src[q + 1..r], which are already 
 * sorted instances from src 
 *
 * @Param src pointer to the array to be sorted
 * @Param p starting point
 * @Param q divition point
 * @Param r finishing point
 */
/*
 ----------------------------------------------------------------------------*/
void merge(int32_t *src, uint32_t p, uint32_t q, uint32_t r, m_mode_t mode)
{
	uint32_t n1;
	uint32_t n2;
	uint32_t i;
	uint32_t j;
	uint32_t k;
	int32_t *L;
	int32_t *R;
	n1 = q - p + 1;
	n2 = r - q;
	L = (int32_t*) malloc(n1*sizeof(int32_t));
	R = (int32_t*) malloc(n2*sizeof(int32_t));
	/*TODO: change for memcpy  */
	for (i = 0; i < n1; i += 1){
		L[i] = src[p + i];
	}
	for ( j = 0; j < n2; j += 1 ){
		R[j] = src[q + j + 1];
	}
	/*TODO: rewrite the for loop to avoid the usage of sentinel cards*/
	if (mode == MSORT_UP) {
		L[n1] = INT32_MAX;
		R[n2] = INT32_MAX;
	}
	else {
		L[n1] = INT32_MIN;
		R[n2] = INT32_MIN;
	}
	i = 0;
	j = 0;
	for ( k = p; k <= r; k += 1 ) {
		if (((L[i] <= R[j]) && (mode == MSORT_UP)) ||
		    ((L[i] >= R[j]) && (mode == MSORT_DOWN))){
			src[k] = L[i];
			i = i + 1;
		}
		else{
			src[k] = R[j];
			j = j + 1;
		}
	}
	free(L);
	free(R);
}
