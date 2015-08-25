/*
 * =====================================================================================
 *
 *       Filename:  isort.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  16.08.2015 00:22:38
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

typedef enum i_mode_t {ISORT_UP,ISORT_DOWN} i_mode_t;
void isort (int32_t *src, size_t len, i_mode_t mode);
