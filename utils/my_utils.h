/*
 * string_utils.h
 *
 *  Created on: 2023. 3. 23.
 *      Author: hwyi
 */

#ifndef UTILS_STRING_UTILS_H_
#define UTILS_STRING_UTILS_H_

#define USE_DOUBLE
#define USE_LONG
#define BUF_SIZE    32

#ifdef USE_DOUBLE
typedef double FLOAT;
#else
typedef float FLOAT;
#endif

#ifdef USE_LONG
typedef long    INT;
#else
typedef int     INT;
#endif


char *int_2_str(INT n);

#endif /* UTILS_STRING_UTILS_H_ */
