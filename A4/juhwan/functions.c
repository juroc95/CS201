//Juhwan Lee
//CS 201
//Assignment 4
//9 March 2021

//The goal of this assignment is to bring together several concepts discussed
//in class; namely, program arguments, data conversion, C structures, and
//pointers to functions. This assignment is to write a menu-based program
//that will perform operations on a list of program arguments based on the menu
//item selected by the user. This program will take up to 15 arguments.

#include "prototypes.h"

//print menu
int print_menu(option_list * menu)
{
	if(!menu || menu->option_total != 7)
	{
		return 0;
	}
	for(int i = 0; i < menu->option_total; ++i)
	{
		printf("%d. %s\n", i, menu->menu_list[i]);
	}
	int result;
	scanf("%d", &result);
	return result;
}

//exit
double exit_program(arg_list * to_ignore)
{
	printf("Exiting program.\n");
	exit(EXIT_SUCCESS);
}

//addition
double addition(arg_list * to_add)
{
	int sum = 0;
	char * end_ptr = NULL;
	printf("You are adding %d numbers together.\n", to_add->arg_total);
	for(int i = 0; i < to_add->arg_total; ++i)
	{
		sum += strtol(to_add->user_input[i], &end_ptr, 0);
	}
	return sum;
}

//subtraction
double subtraction(arg_list * to_sub)
{
	char * end_ptr = NULL;
	int sum = strtol(to_sub->user_input[0], &end_ptr, 0);
	printf("You are subtracting %d numbers.\n", to_sub->arg_total);
	for(int i = 1; i < to_sub->arg_total; ++i)
	{
		sum -= strtol(to_sub->user_input[i], &end_ptr, 0);
	}
	return sum;
}

//multiplication
double multiplication(arg_list * to_mult)
{
	int result = 1;
	char * end_ptr = NULL;
	printf("You are multiplying %d numbers together.\n", to_mult->arg_total);
	for(int i = 0; i < to_mult->arg_total; ++i)
	{
		result *= strtol(to_mult->user_input[i], &end_ptr, 0);
	}
	return result;
}

//division
double division(arg_list * to_div)
{
	double quotient = 0;
	char * end_ptr = NULL;
	printf("You are dividing %d numbers.\n", to_div->arg_total);
	if(to_div->arg_total > 2)
	{
		printf("Only the first two arguments are used for division.\n");
	}
	double numerator = (double)strtol(to_div->user_input[0], &end_ptr, 0);
	double denominator = (double)strtol(to_div->user_input[1], &end_ptr, 0);
	quotient = numerator/denominator;
	return quotient;
}

//modular
double modulo(arg_list * to_mod)
{
	int remain = 0;
	char * end_ptr = NULL;
	printf("You are modding %d numbers.\n", to_mod->arg_total);
	if(to_mod->arg_total > 2)
	{
		printf("Only the first two arguments are used for modulo.\n");
	}
	remain = strtol(to_mod->user_input[0], &end_ptr, 0) % strtol(to_mod->user_input[1], &end_ptr, 0);
	return remain;
}

//reverse
double reverse(arg_list * to_turn)
{
	printf("You are reversing %d words.\n", to_turn->arg_total);
	for(int i = 0; i < to_turn->arg_total; ++i)
	{
		swap_char(to_turn->user_input[i]);
	}
	for(int i = (to_turn->arg_total - 1); i >= 0; --i)
	{
		printf("%s ", to_turn->user_input[i]);
	}
	printf("\n");
	return 0;
}

//reverse strings
void swap_char(char * start)
{
	char temp;
	char * end = (start + strlen(start));
	while(--end > start)
	{
		temp = *start;
		*start++ = *end;
		*end = temp;
	}
}
