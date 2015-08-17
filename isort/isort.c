/*
 * =====================================================================================
 *
 *       Filename:  isort.c
 *
 *    	Description: Implementation of the insertion sort algorithm
 *
 *        Version:  1.0
 *        Created:  16.08.2015 00:05:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Romel Torres (rtorres), torres.romel@gmail.com
 *        Company:  -
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include "isort.h"

/**
 * @brief main Example used for testing the algorithm, the correct usage ./isort max cnt. 
 * This creates a random array of size max constrained to -cnt to +cnt
 *
 * @return 
 */
int main ( int argc, char *argv[] )
{
	size_t len;
	uint32_t i;
	int32_t *src;
	int32_t max;
	if(argc < 3){
		printf("Correct Usage isort len max\n");
		perror("Incorrect isort.c usage");
		return EXIT_FAILURE;
	}
	srand(time(NULL));
	len = (size_t) atoi(argv[1]);
	max = (int32_t) atoi(argv[2]);
	printf("Creating random array of input %d and constrained to %d\n",
	       (int) len, (int) max);
	src = (int32_t *) malloc(sizeof(int32_t)*len);
	for (i = 0; i < len; i++)
	{
		//generate random number between -max and max
		src[i] = (int32_t) (rand() % (2*max) - max);
		printf("%d ",src[i]);
	}
	printf("\n");
	isort(src,len,ISORT_UP);
	printf("Printing sorted (up) array:\n");
	for ( i = 0; i < len; i += 1 ){
		printf("%d ",src[i]);
	}
	printf("\n");
	isort(src,len,ISORT_DOWN);
	printf("Printing sorted (down) array:\n");
	for ( i = 0; i < len; i += 1 ){
		printf("%d ",src[i]);
	}
	printf("\n");

	free(src);
	return EXIT_SUCCESS;
}

/**
 * @brief This function sorts an array using insertion sort (algorithm with a
 * O(n) running time.  
 *
 * @param src Pointer to the array
 * @param len Length of the array pointed by src
 * @param mode sorting modes: UP/DOWN
 */
void isort (int32_t *src, size_t len, smode_t mode)
{
	int32_t i;
	int32_t j;
	int32_t key;
	for ( j = 1; j < len; j++ ){
		key = src[j];
		i = j - 1;
		while ((i >= 0) && (((src[i] > key) && mode == ISORT_UP)|| ((
		src[i] < key) && mode == ISORT_DOWN))){
			src[i + 1] = src[i];
			i--;
		}
		src[i + 1] = key;
	}
}
