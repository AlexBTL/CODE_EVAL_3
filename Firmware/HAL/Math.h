/* 
 * File:   Math.h
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#ifndef MATH_H
#define	MATH_H

#include "Random.h"

/**************************************************************/
/*                        DEFINE & TYPEDEF                    */
/**************************************************************/

/**************************************************************/
/*                        PUBLIC FUNCTIONS                    */
/**************************************************************/

int power(int number, int power);

counter_s TestEqualZero(buffer_s buffer, counter_s counter);

int DecimalNumber(void);

int FunctionDivByTwo(buffer_s buffer, int nbZeroAfterDiv);

/**************************************************************/
/*                        PRIVATE FUNCTIONS                   */
/**************************************************************/

#endif	/* MATH_H */