/* 
 * File:   Random.h
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#ifndef RANDOM_H
#define	RANDOM_H

/**************************************************************/
/*                        DEFINE & TYPEDEF                    */
/**************************************************************/

#define ALLOCATION_STEP 8
#define NUMBER_OF_TESTS 100
#define NUMBER_OF_DIGIT 11
#define SIZE_OF_WORDS 8
#define BASE_TEN 10
#define BASE_TWO 2
#define RANGE_RAND_NUMB 5

typedef struct Buffer_t
{
	int *p;
	char *pchar;
	int size;
	int indice;
} buffer_s;

typedef struct Counter_t
{
	int countRandomNumber;
   	int countNumberDisplay;
   	int nbZeroAfterDiv;
   	int countBeforeToGoTheLine;	
} counter_s;

/**************************************************************/
/*                        PUBLIC FUNCTIONS                    */
/**************************************************************/
void Random(FILE *fp);
/**************************************************************/
/*                        PRIVATE FUNCTIONS                   */
/**************************************************************/

#endif	/* RANDOM */