CC         = gcc 
XFLAGS     = -W -Wall -pedantic
INC1       = ./Firmware/HAL
INCDIRS    = -I ${INC1} 
CFLAGS     = ${INCDIRS} ${XFLAGS} 

Digit:  Main.o Random.o Memory.o Math.o PrintManage.o Read.o Compare.o Digit.o
	gcc -o Digit Main.o Random.o Memory.o Math.o PrintManage.o Read.o Compare.o Digit.o

Main.o: ./Firmware/APP/Main.c ./Firmware/HAL/Random.h ./Firmware/HAL/Memory.h ./Firmware/HAL/Read.h ./Firmware/HAL/Compare.h
	gcc -o Main.o -c ./Firmware/APP/Main.c ${CFLAGS}

Random.o: ./Firmware/HAL/Random.c ./Firmware/HAL/Random.h ./Firmware/HAL/Memory.h ./Firmware/HAL/Math.h ./Firmware/HAL/PrintManage.h
	gcc -o Random.o -c ./Firmware/HAL/Random.c ${CFLAGS}
	
Memory.o: ./Firmware/HAL/Memory.c ./Firmware/HAL/Random.h ./Firmware/HAL/Memory.h
	gcc -o Memory.o -c ./Firmware/HAL/Memory.c ${CFLAGS}				

Math.o: ./Firmware/HAL/Math.c ./Firmware/HAL/Random.h 
	gcc -o Math.o -c ./Firmware/HAL/Math.c ${CFLAGS}

PrintManage.o: ./Firmware/HAL/PrintManage.c ./Firmware/HAL/Random.h 
	gcc -o PrintManage.o -c ./Firmware/HAL/PrintManage.c ${CFLAGS}

Read.o: ./Firmware/HAL/Read.c ./Firmware/HAL/Random.h 
	gcc -o Read.o -c ./Firmware/HAL/Read.c ${CFLAGS}

Compare.o: ./Firmware/HAL/Compare.c ./Firmware/HAL/Random.h ./Firmware/HAL/Digit.h
	gcc -o Compare.o -c ./Firmware/HAL/Compare.c ${CFLAGS}

Digit.o: ./Firmware/HAL/Digit.c ./Firmware/HAL/Compare.h ./Firmware/HAL/Math.h 
	gcc -o Digit.o -c ./Firmware/HAL/Digit.c ${CFLAGS}