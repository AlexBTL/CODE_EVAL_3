/* 
 * File:   Read.h
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#ifndef READ_H
#define	READ_H
#include "Random.h"

/**************************************************************/
/*                        DEFINE & TYPEDEF                    */
/**************************************************************/

#define CHARACTER_IGNORED '\n'
#define SIZE_BUFF_READ 10        // One more fore the end of table character

/**************************************************************/
/*                        PUBLIC FUNCTIONS                    */
/**************************************************************/

buffer_s Read(FILE *fp,buffer_s buffer2);
buffer_s GetValue(buffer_s buff, FILE *fp);

/**************************************************************/
/*                        PRIVATE FUNCTIONS                   */
/**************************************************************/

#endif	/* READ */
