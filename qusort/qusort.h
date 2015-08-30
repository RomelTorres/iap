/*
 * =====================================================================================
 *
 *       Filename:  qsort.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  30.08.2015 21:28:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Romel J. Torres (rtorres), torres.romel@gmail.com
 *   Organization:  -
 *
 * =====================================================================================
 */
typedef enum q_mode_t {QSORT_UP, QSORT_DOWN} q_mode_t;

int32_t partition(int32_t *src, int32_t p, int32_t r, q_mode_t mode);
void quicksort(int32_t *src, int32_t p, int32_t r, q_mode_t mode);
void qusort(int32_t *src, size_t len, q_mode_t mode);
