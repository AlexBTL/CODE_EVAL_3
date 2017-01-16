/* 
 * File:   Main.c
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "Main.h"
#include "Random.h"
#include "Memory.h"
#include "Read.h"
#include "Compare.h"

/**************************************************************/
/*                         PUBLIC DATA                        */
/**************************************************************/

/**************************************************************/
/*                         PRIVATE DATA                       */
/**************************************************************/

/**************************************************************/
/*                         PRIVATE FUNCTIONS                  */
/**************************************************************/

static void Checkfopen(FILE *fp)
{
	if(fp == NULL)
	{
		fprintf(stdout, "\nError 00 : This file doesn't exist\n");
		exit(0); 
	}
}

static void Checkfclose(int close)
{
	if(close == EOF)
	{
		fprintf(stdout, "\nError 01 : This file did not closed properly\n");
		exit(0);
	}
}

static FILE *Process(FILE *fp)
{
	buffer_s buffer2;
	uint8_t value;
	uint8_t mask;

	buffer2.pchar = (char*)calloc(2000, sizeof(char));
	value = 0x00;
	mask = 0x00;

	Random(fp);
	rewind(fp);
	buffer2 = Read(fp, buffer2);
	rewind(fp);
	Compare(fp, buffer2, value, mask);
	return (fp);
}
/**************************************************************/
/*                         PUBLIC FUNCTIONS                   */
/**************************************************************/

int main(int argc, char *argv[])
{
	FILE *fp;
	int close;
 
	if(argc == NB_ARGUMENTS_WANTED)
	{
		fp = fopen(argv[1],"w+");
		Checkfopen(fp);
		fp = Process(fp);
		close = fclose(fp);
		Checkfclose(close);        		                      
	}
	if(argc > NB_ARGUMENTS_WANTED)
	{
		fprintf(stdout, "\nError 02 : Too many arguments\n");
		exit(0); 
	}
	if(argc < NB_ARGUMENTS_WANTED)
	{
		fprintf(stdout, "\nError 03 : Not enough arguments\n");
		exit(0); 
	}                                          
	return(0);
}
