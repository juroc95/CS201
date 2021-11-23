//Juhwan Lee
//CS 201
//Assignment 3
//15 February 2021

//The goal of this program is to implement an IEEE floating point parse for an
//arbitrary number of bit settings.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//prototypes
void check_hex(char * s);
void result(int frac_bits, int exp_bits, int parse);

//main
int main(int argc, char * argv[])
{
	if(argc != 4)	//check number of arguments
	{
		printf("Usage: fp_parse <# of frac_bits> <# of exp_bits>\n");
		exit(EXIT_FAILURE);	//abort
	}

	//variables
	int frac_bits = 0;
	int exp_bits = 0;
	int parse = 0;
	char hex_check[100];

	//argv to variables
	sscanf(argv[1], "%d", &frac_bits);
	sscanf(argv[2], "%d", &exp_bits);
	sscanf(argv[3], "%x", &parse);
	sscanf(argv[3], "%s", hex_check);

	check_hex(hex_check);	//check if argument 3 is hex digit
	result(frac_bits, exp_bits, parse);	//calling process function

	exit(EXIT_SUCCESS);	//exit
}

//check if argument 3 is hex digit
void check_hex(char * s)
{
	
	int n = strlen(s);	//variable for for loop
	for(int i = 0; i < n; ++i)
	{
		//if not hex digit
		if(isxdigit(s[i]) == 0)
		{
			printf("Argument 3 is not a hexadecimal number (%s).\n", s);
			exit(EXIT_FAILURE);	//abort
		}
	}
}

//process function
void result(int frac_bits, int exp_bits, int parse)
{
	//check number of fraction bits
	if(frac_bits < 2 || frac_bits > 10)
	{
		printf("Invalid number of fraction bits (%d). Should be between 2 and 10.\n", frac_bits);
		exit(EXIT_FAILURE);	//abort
	}
	//check number of exponent bits
	if(exp_bits < 3 || exp_bits > 5)
	{
		printf("Invalid number of exponent bits (%d). Should be between 3 and 5.\n", exp_bits);
		exit(EXIT_FAILURE);	//abort
	}
	int total_bits = 1 + exp_bits + frac_bits;	//total bits calculation
	int max_value = pow(2, total_bits) - 1;	//maximum value calculation
	//if hex digit is larger than max value
	if(parse > max_value)
	{
		printf("Number %x exceeds maximum number of bits. Only 7 allowed here.\n", parse);
		exit(EXIT_FAILURE);	//abort
	}
	//calculation for each field
	double frac = (parse & (int)(pow(2, frac_bits) - 1))/pow(2, frac_bits);
	double exp = ((parse >> frac_bits) & (int)(pow(2, exp_bits) - 1));
	double sign = ((parse >> (frac_bits + exp_bits)) & 1);
	//checking special cases
	if(exp == (pow(2, exp_bits) - 1))
	{
		if(frac)	//if NaN
		{
			printf("NaN\n");
			exit(EXIT_SUCCESS);	//exit
		}
		if(sign)	//if not NaN
		{
			printf("-");
		}
		else
		{
			printf("+");
		}
		printf("inf\n");
		exit(EXIT_SUCCESS);	//exit
	}
	double bias = (pow(2, (exp_bits - 1)) - 1);	//bias calculation
	double decimal = 0;	//result variable
	if(!exp)	//if denormalized case
	{
		decimal = pow(2, (1 - bias)) * frac;
	}
	else	//if normalized case
	{
		decimal = pow(2, (exp - bias)) * (1 + frac);
	}
	if(sign)	//adding - if needed
	{
		printf("-");
	}
	printf("%f\n", decimal);	//print floating point
	exit(EXIT_SUCCESS);	//exit
}
