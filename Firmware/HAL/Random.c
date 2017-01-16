/* 
 * File:   Random.c
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Random.h"
#include "Memory.h"
#include "Math.h"
#include "PrintManage.h"

/**************************************************************/
/*                         PUBLIC DATA                        */
/**************************************************************/

/**************************************************************/
/*                         PRIVATE DATA                       */
/**************************************************************/

/**************************************************************/
/*                         PRIVATE FUNCTIONS                  */
/**************************************************************/
static void FreeBuffer(buffer_s buffer)
{
	free(buffer.p);
	if ( buffer.p != NULL)
  {
    fprintf(stdout, "\nError 05 : Free pointer fail\n");
    exit(0);
  }
}

static buffer_s FillBuffer(buffer_s buffer)      // Par exemple place le nombre 203 dans un buffer => buf[0]=2 buf[1]=0 buf[2]=3 
{
	int randomNumber;

	randomNumber = rand() % (power(BASE_TWO, SIZE_OF_WORDS) - 1);
	buffer.size = 0;

	buffer = MemoryAdd(buffer);

	while(buffer.size <= DecimalNumber())
	{
		buffer.p[buffer.size] = randomNumber / power(BASE_TEN, (DecimalNumber() - buffer.size));   //BASE_TEN ^ (DecimalNumber() - buffer.size)
		randomNumber = randomNumber - (buffer.p[buffer.size] * power(BASE_TEN, (DecimalNumber() - buffer.size)));
		buffer.size++;
	}
	while(buffer.p[0] == 0)
	{
		buffer.p[0] = buffer.p[1];
		buffer.p[1] = buffer.p[2];
		buffer.p[2] = 0;
		buffer.size--;
	}
	return (buffer);
}

static counter_s InitCounters(counter_s counter)
{
	counter.countRandomNumber = 0;
  counter.countNumberDisplay = 0;
  counter.nbZeroAfterDiv = 0;
  counter.countBeforeToGoTheLine = 0;
  return (counter);
}

static buffer_s InitBuffer(buffer_s buffer)
{
	buffer.p = (int*)calloc(ALLOCATION_STEP, sizeof(int));
  MemoryCheck(buffer);
  buffer.size = 0;	
  return (buffer);
}
/**************************************************************/
/*                          PUBLIC FUNCTIONS                  */
/**************************************************************/

void Random(FILE *fp)
{
	counter_s counter;
	buffer_s bufferInteger;
  buffer_s bufferBinary; 
	
	counter = InitCounters(counter);
	bufferInteger = InitBuffer(bufferInteger);
  bufferBinary = InitBuffer(bufferBinary);
  
	while(counter.countRandomNumber < (NUMBER_OF_TESTS * NUMBER_OF_DIGIT))
  {  		
   	bufferInteger = FillBuffer(bufferInteger);
   	while(counter.nbZeroAfterDiv < bufferInteger.size)                                                            // Exemple : number 134 (1000 0110)=> size 3  bufferInt = [1,3,4]                            
   	{  	 		
      bufferBinary.p[counter.countNumberDisplay] = FunctionDivByTwo(bufferInteger, counter.nbZeroAfterDiv);
      bufferBinary = MemoryAdd(bufferBinary);
      counter = TestEqualZero(bufferInteger, counter);
    }
    counter= PrintBinary(bufferBinary, counter, fp);
    memset(bufferBinary.p, 0, 7);
   	}
   	//FreeBuffer(bufferBinary);
   	//FreeBuffer(bufferInteger);
}
