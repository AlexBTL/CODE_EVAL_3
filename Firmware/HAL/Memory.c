/* 
 * File:   Conversion.c
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Memory.h"
#include "Random.h"

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
/*                        PUBLIC FUNCTIONS                    */
/**************************************************************/

void MemoryCheck(buffer_s buffer) // AL GOOD mais le programme s'arette pas en cas d'erreur car tu test bien l'echec mais quand tu apelle cette fonction tu lis pas la valeur de retour de cette fonction donc ca sert a rien 
{
   if(buffer.p == NULL)
   {
      fprintf(stdout, "\nError 04 : Allocation memory fail\n");
      exit(0);
   }
}

buffer_s MemoryAdd(buffer_s memory)                     // Add some memory space if the number is bigger
{
   buffer_s moreMemory;

   moreMemory.p = memory.p;
   moreMemory.size = memory.size;
   moreMemory.p = (int*)realloc(memory.p, (ALLOCATION_STEP) * sizeof(int));
   MemoryCheck(moreMemory);
   return (moreMemory);
}
