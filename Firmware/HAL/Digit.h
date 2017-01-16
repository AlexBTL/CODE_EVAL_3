/* 
 * File:   Digit.h
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#ifndef DIGIT_H
#define	DIGIT_H

/**************************************************************/
/*                        DEFINE & TYPEDEF                    */
/**************************************************************/

#define ZERO 0xFC      //1111 1100
#define ONE 0x60       // 0110 0000
#define TWO 0xDA       // 1101 1010
#define THREE 0xF2     // 1111 0010
#define FOUR 0x67      // 0110 0111
#define FIVE 0xB6      // 1011 0110
#define SIX 0xDE       // 1011 1110
#define SEVEN 0xE0     // 1110 0000 
#define EIGHT 0xFE     // 1111 1110
#define NINE 0XFE     // A modifier
#define DOT 0x01       //00000001

/**************************************************************/
/*                        PUBLIC FUNCTIONS                    */
/**************************************************************/
uint8_t GetMask(char digit, uint8_t mask);
uint8_t ConvertUint(buffer_s buff);
int CheckDisplay(uint8_t mask, uint8_t value, int countFloat);
int WaitEndLineFloat(buffer_s buffer, int count);
/**************************************************************/
/*                        PRIVATE FUNCTIONS                   */
/**************************************************************/

#endif	/* DIGIT_H */