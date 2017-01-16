/* 
 * File:   Math.c
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Random.h"
#include "Memory.h"
#include "Math.h"

/**************************************************************/
/*                         PUBLIC DATA                        */
/**************************************************************/

/**************************************************************/
/*                         PRIVATE DATA                       */
/**************************************************************/

/**************************************************************/
/*                         PRIVATE FUNCTIONS                  */
/**************************************************************/

/**************************************************************/
/*                          PUBLIC FUNCTIONS                  */
/**************************************************************/

int power(int number, int power)
{
	int i;
	int result;

	i = 1;
	result = 1;

	for(i=1; i<=power; i++)
	{ 
		result = result * number;
	}
	return (result);
}

counter_s TestEqualZero(buffer_s buffer, counter_s counter)
{
	counter.countNumberDisplay++;
   	if(buffer.p[counter.nbZeroAfterDiv] == 0)
   	{                                                                    
   		counter.nbZeroAfterDiv++;
   	}
   	return (counter); 
}

int DecimalNumber(void)        // Retourne le nombre de chiffre dans le nombre maximal possible pour le nombre de but signifie dans SIZE_OF_WORD
{
	int decimalNumber;
	int diviser;

	decimalNumber = 0;
	diviser = power(BASE_TWO, SIZE_OF_WORDS);

	while (diviser != 0)
	{
		diviser = diviser / BASE_TEN;
		decimalNumber++;
	}
	return (decimalNumber-1);
}

int FunctionDivByTwo(buffer_s buffer, int nbZeroAfterDiv)
{
   int temp;                                                           // Hold the temporary value allowing to use the conversion method
   int carry;
   int i;
   temp = 0;
   carry = 0;
   i = nbZeroAfterDiv;
   while(i < buffer.size)                        // indice        = 1  / 2  / 3               2  / 3         2  / 3        2  / 3            3       3      3        3                  
   { 
      temp = (10 * carry + buffer.p[i]);          // temp         <= 1  / 13 / 14              6  / 7         3 / 13        1  / 16           8       4      2        1
      buffer.p[i] = temp / 2;                     // bufferInt[]  <= 0  / 6  / 7               3  / 3         1  / 6        0  / 8            4       2      1        0
      carry = temp % 2;                           // carry        <= 1  / 1  / (0)             0  / (1)       1  / (1)      1  / (0)         (0)     (0)    (0)      (1)
      i++;                                        // indice       <= 2  / 3  / 4               3  / 4         3  / 4        3  / 4            4       4      4        4
   }
   return (carry);    
}