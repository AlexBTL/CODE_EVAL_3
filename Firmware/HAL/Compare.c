/* 
 * File:   Compare.c
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
#include "Compare.h"
#include "Digit.h"

/**************************************************************/
/*                         PUBLIC DATA                        */
/**************************************************************/
/**************************************************************/
/*                         PRIVATE DATA                       */
/**************************************************************/
/**************************************************************/
/*                         PRIVATE FUNCTIONS                  */
/**************************************************************/

static buffer_s WaitEndLineBinary(buffer_s buffer, FILE *fp)
{
   while((buffer.pchar[0] != '\n') && (buffer.pchar[0] != EOF))  // On attend la prochaine salve de digit
   {
      buffer = GetValue(buffer,fp);
   }
   return (buffer); 
}

static int DiplayAllow(int indice)
{
   printf("result : 1\n");
   indice++;
   return (indice);
}

static buffer_s DiplayImpossible(buffer_s buffer, FILE *fp)
{
   printf("result : 0\n");          
   buffer = WaitEndLineBinary(buffer, fp);
   return (buffer);
}

static void BufferInit(buffer_s *bufferBinary, buffer_s *bufferFloat)
{
   bufferBinary->pchar = (char*)calloc(SIZE_BUFF_READ, sizeof(char));
   bufferBinary->p = (int*)calloc(SIZE_BUFF_READ, sizeof(int));
   bufferFloat->indice = 0; 
}
/**************************************************************/
/*                        PUBLIC FUNCTIONS                   */
/**************************************************************/

void Compare(FILE *fp, buffer_s bufferFloat, uint8_t value, uint8_t mask)                         
{
   buffer_s bufferBinary;        
   BufferInit(&bufferBinary, &bufferFloat);
   
   while(!feof(fp))
   {
      bufferBinary = GetValue(bufferBinary,fp);                               // On recupere la buffer des 8 bits contenant un digit                                                                                                                               
   	if((bufferBinary.pchar[0] == ' ')||(bufferBinary.pchar[0] == ':'))      // Si l'on est a la fin d'un digit
   	{
         value = ConvertUint(bufferBinary);                                   // On convertit le tableau de bit char -> Int et on en fait un uint8_t
         mask = GetMask(bufferFloat.pchar[bufferFloat.indice], mask);         // On recupere la valeur du mask en fonction du nombre lu dans buffer2
         bufferFloat.indice = CheckDisplay(mask, value, bufferFloat.indice);  // Si la valeur convertis et affichable 
         if(bufferFloat.pchar[bufferFloat.indice] == '\n')                    // Si la suivante est un saut de ligne, le nombre a ete affiche avec success
         {
            bufferFloat.indice = DiplayAllow(bufferFloat.indice);
            bufferBinary = WaitEndLineBinary(bufferBinary, fp);
         }
         if(bufferBinary.pchar[0] == ':')                                      // Si on arrive a la fin des 11 Digits
         {         
            bufferBinary = DiplayImpossible(bufferBinary, fp);
            bufferFloat.indice = WaitEndLineFloat(bufferFloat, bufferFloat.indice);
         }
      }
   }                                                                 
}