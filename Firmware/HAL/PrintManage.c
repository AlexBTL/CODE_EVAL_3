/* 
 * File:   PrintManage.c
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
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
static void PrintRandomFloat(FILE *fp)
{
   int random1;
   int random2;
   int random3;
   random1 = rand() % RANGE_RAND_NUMB;
   random2 = rand() % RANGE_RAND_NUMB;
   random3 = rand() % RANGE_RAND_NUMB;
   fprintf(fp, ": %d.%d\n", (random1 * random2), (random3 * random1 + random2));
}

static int GoToLineOrSpace(int countBeforeToGoTheLine, FILE *fp)
{
   if(countBeforeToGoTheLine == 11)
   {  
         PrintRandomFloat(fp);
         countBeforeToGoTheLine = 0;
         fprintf(fp, "\n");
      }
      else
      {
      fprintf(fp, " ");
      }
      return (countBeforeToGoTheLine);   
}

/**************************************************************/
/*                          PUBLIC FUNCTIONS                  */
/**************************************************************/

counter_s PrintBinary(buffer_s buffer, counter_s counter, FILE *fp)                   // Print in reverse the table holding the binary conversion of the integers
{
   	int countDownPrint;
   	countDownPrint = SIZE_OF_WORDS - 1;
   	counter.countBeforeToGoTheLine ++;

   	while( countDownPrint >= 0 )
   	{
       	fprintf(fp, "%d", buffer.p[countDownPrint]);
      	countDownPrint--;
   	}
   	counter.countBeforeToGoTheLine = GoToLineOrSpace(counter.countBeforeToGoTheLine, fp);
   	counter.nbZeroAfterDiv = 0;
   	counter.countNumberDisplay = 0;
   	counter.countRandomNumber++;                             
   	return (counter);    
}



