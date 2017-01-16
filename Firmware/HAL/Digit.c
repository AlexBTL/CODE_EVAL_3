/* 
 * File:   Digit.c
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "Compare.h"
#include "Math.h"
#include "Digit.h"
#include "Read.h"

/**************************************************************/
/*                         PUBLIC DATA                        */
/**************************************************************/
/**************************************************************/
/*                         PRIVATE DATA                       */
/**************************************************************/
/**************************************************************/
/*                         PRIVATE FUNCTIONS                  */
/**************************************************************/

static uint8_t ResetMask(uint8_t mask)
{
   mask = 0x00;
   return (mask);
}

/**************************************************************/
/*                          PUBLIC FUNCTIONS                  */
/**************************************************************/

uint8_t GetMask(char digit, uint8_t mask)
{
   mask = ResetMask(mask);
   switch(digit)
   {
      case '0' : mask = ZERO;
         break;
      case '1' : mask = ONE;
         break;
      case '2' : mask = TWO;
         break;
      case '3' : mask = THREE;
         break;
      case '4' : mask = FOUR;
         break;
      case '5' : mask = FIVE;
         break;
      case '6' : mask = SIX;
         break;
      case '7' : mask = SEVEN;
         break;
      case '8' : mask = EIGHT;
         break;
      case '9' : mask = NINE;
         break;
      case '.' : mask = DOT;
         break;
   }
   return (mask);
}

uint8_t ConvertUint(buffer_s buff)
{
   int indice;
   uint8_t value;

   indice = 1;
   value = 0x00;

   while(indice < (SIZE_BUFF_READ - 1))
   {
      buff.p[indice] = buff.pchar[indice] - '0';
      value = value + (uint8_t)(buff.p[indice] * power(BASE_TWO,(indice-1)));
      indice++;
   }
   return (value);
}

int CheckDisplay(uint8_t mask, uint8_t value, int countFloat)
{
   if((mask & value) == mask)
   {
      countFloat++;
   }
   return (countFloat);
} 

int WaitEndLineFloat(buffer_s buffer, int count)
{
   while(buffer.pchar[count] != '\n')
   {
      count++;
   }
   return (count++); 
}