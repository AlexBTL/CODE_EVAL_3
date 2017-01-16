/* 
 * File:   DecimalToBinary.c
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "Memory.h"
#include "Read.h"
#include "Random.h"
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



static bool CheckSpace(char characterRead)
{
   if(characterRead != CHARACTER_IGNORED)           // If its not an empty line
   {
      return (false);
   }
   else
   {
      return (true);
   }
}

/**************************************************************/
/*                        PUBLIC FUNCTIONS                   */
/**************************************************************/

buffer_s GetValue(buffer_s buff, FILE *fp)
{
   int i;
   i = 0;
   while(i < SIZE_BUFF_READ -1 )
   {
      buff.pchar[SIZE_BUFF_READ - i - 1] = buff.pchar[SIZE_BUFF_READ - i - 2];
      i++;
   }
   buff.pchar[0] = fgetc(fp);
   return (buff); 
}

buffer_s Read(FILE *fp, buffer_s buffer2)                         
{                  
   buffer_s buffer1;
   char tab[SIZE_BUFF_READ] = {'0'};
   int indice;
    
   indice = 0;
   buffer1.pchar = tab; 

   while(!feof(fp))
   {
      buffer1 = GetValue(buffer1,fp);                                                                                                                                   
      if((buffer1.pchar[1] == ':')&&(buffer1.pchar[0] == ' '))
      {
         while((buffer1.pchar[0] != '\n') && (buffer1.pchar[0] != EOF))
         {
            buffer1 = GetValue(buffer1,fp);
            buffer2.pchar[indice] = (buffer1.pchar[0]);
            indice++;
         }
         indice++;
      }
   }
   return (buffer2);                                                           
}

