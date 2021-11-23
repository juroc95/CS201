//Juhwan Lee
//CS 201
//Assignment 2
//1 February 2021

//This program will accept a list of integers in the range [0...15] and turn on
//the corresponding bits in an unsigned short to output a result that shows set
//membership. This program ensures that each integer is in the correct range.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	char * end;	//end pointer
	for(int i = 1; i < argc; ++i)	//check range
	{
		int to_check = strtol(argv[i], &end, 10);
		if(to_check < 0 || to_check > 15)
		{
			printf("Not in the correct range. Program will exit.\n");
			exit(EXIT_FAILURE);	//abort
		}
	}
	int to_display = 0x8000;
	unsigned short bits = 0;
	for(int i = 1; i < argc; ++i)	//turns on the specified bits
	{
		bits |= (1 << strtol(argv[i], &end, 10));
	}
	int counter = 0;
	while(to_display > 0)
	{
		int display = (bits & to_display) != 0;	//if bit is 1 or 0
		printf("%d", display);	//display bit
		to_display >>= 1;	//right shit
		++counter;
		if(counter > 3)	//to display space
		{
			printf(" ");
			counter = 0;
		}
	}
	printf("\n");
	exit(EXIT_SUCCESS);
}
