/* 
 * File:   Compare.h
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#ifndef COMPARE_H
#define	COMPARE_H
#include "Random.h"
#include <stdint.h>


/**************************************************************/
/*                        DEFINE & TYPEDEF                    */
/**************************************************************/

/**************************************************************/
/*                        PUBLIC FUNCTIONS                    */
/**************************************************************/

void Compare(FILE *fp, buffer_s bufferFloat, uint8_t value, uint8_t mask);

/**************************************************************/
/*                        PRIVATE FUNCTIONS                   */
/**************************************************************/

#endif	/* COMPARE */
