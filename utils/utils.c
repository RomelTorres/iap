/*
 * =====================================================================================
 *
 *       Filename:  utils.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  16.08.2015 15:04:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Romel J. Torres (rtorres), torres.romel@gmail.com
 *   Organization:  -
 *
 * =====================================================================================
 */

#include <math.h>
#include <stdint.h>
#include <stdio.h>
/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  Creates a constrained random array
 *
 * @Param len the array size
 * @Param cnt the constraint
 *
 * @Returns pointer to the random array
 */
/*
 ----------------------------------------------------------------------------*/
int32_t *cr_rnd_arr(size_t len, int32_t cnt)
{
	int32_t i;
	int32_t *rnd_arr;
	rnd_arr = malloc(len * sizeof(int32_t));
	for( i= 0; i < len; i++){
		rnd_arr[i] = (int32_t) (rand() % (2*cnt) - cnt);
	}
	return rnd_arr;
}


/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  prints an array
 *
 * @Param arr pointer to the array
 * @Param len length of the array
 */
/*
 ----------------------------------------------------------------------------*/
void print_arr(int32_t *arr, size_t len){
	int32_t i;
	for ( i = 0; i < len, i++){
		printf(" %d",arr[i]);
	}
	printf("\n");
}
