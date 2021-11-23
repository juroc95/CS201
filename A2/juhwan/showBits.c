//Juhwan Lee
//CS 201
//Assignment 2
//1 February 2021

//This program will accept two hexadecimal 32-bit integers and display which bits
//the two numbers both have set to 1. It will print the bit numbers as well as the
//resulting number in hexadecimal, signed integer and unsigned integer formats.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char * argv[])
{
	char * end;	//end pointer
	if(argc != 3)	//check if two arguments
	{
		printf("Error: please provide two hexadecimal numbers as arguments to the program.\n");
		exit(EXIT_FAILURE);	//abort
	}
	uint32_t common = (strtol(argv[1], &end, 16) & strtol(argv[2], &end, 16));	//find common
	uint32_t to_display = 0x1;
	printf("Bits ");
	for(int i = 0; i < 32; ++i)
	{
		uint32_t display = (common & to_display) != 0;	//if bit is 1 or 0
		if(display)	//if it is 1
		{
			printf("%d", i);	//display bit position
			printf(", ");
		}
		to_display <<= 1;	//left shit
	}
	printf("in common. ");
	printf("Hexadecimal: %X, ", common);
	printf("Signed: %d, ", common);
	printf("Unsigned: %u.\n", common);

	exit(EXIT_SUCCESS);
}
