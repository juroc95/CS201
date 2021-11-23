//Juhwan Lee
//CS 201
//Assignment 4
//9 March 2021

//The goal of this assignment is to bring together several concepts discussed
//in class; namely, program arguments, data conversion, C structures, and
//pointers to functions. This assignment is to write a menu-based program
//that will perform operations on a list of program arguments based on the menu
//item selected by the user. This program will take up to 15 arguments.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//structures
//option list
typedef struct option_list
{
	int option_total;	//total number of options
	char ** menu_list;	//(array of array) option names
} option_list;

//argument list
typedef struct arg_list
{
	int arg_total;	//total number of arguments
	char ** user_input;	//(array of array) arguments from the user
} arg_list;

//function pointer
typedef double function_pointer(arg_list *);

//function table
typedef struct function_table
{
	char * name;	//option name
	function_pointer * to_call;	//function to call
} function_table;

//function prototypes
int print_menu(option_list * menu);
double exit_program(arg_list * to_ignore);
double addition(arg_list * to_add);
double subtraction(arg_list * to_sub);
double multiplication(arg_list * to_mult);
double division(arg_list * to_div);
double modulo(arg_list * to_mod);
double reverse(arg_list * to_turn);
void swap_char(char * to_reverse);
