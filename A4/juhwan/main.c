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

int main(int argc, char * argv[])
{
	//checking number of arguments
	if(argc < 3 || argc > 16)
	{
		printf("Incorrect number of arguments.\nArgument range: 2 - 15\n");
		exit(EXIT_FAILURE);	//abort
	}
	//option names
	char * list[] = {"Exit", "Addition", "Subtraction", "Multiplication", "Division", "Modulo", "Reverse Input"};
	int size = sizeof(list)/sizeof(list[0]);	//total number of options
	option_list * menu = malloc(sizeof(option_list));	//allocating memory for option list
	menu->option_total = size;	//assign total number of options
	menu->menu_list = malloc(size * sizeof(char*));	//allocating memory for option names
	//assign option names
	for(int i = 0; i < size; ++i)
	{
		int len = strlen(list[i]) + 1;
		menu->menu_list[i] = malloc(len);
		strncpy(menu->menu_list[i], list[i], len);
	}
	int flag = 0;
	int user_option = 0;
	do
	{
		//print menu
		user_option = print_menu(menu);
		//bound check
		if(user_option < 0 || user_option > 6)
		{
			printf("Please enter valid menu option.\n");
			flag = 1;
		}
		else
		{
			flag = 0;
		}
	} while(flag == 1);	//move on only if valid menu option
	argv++;
	int size2 = argc - 1;	//total number of arguments
	arg_list * user_arg_list = malloc(sizeof(arg_list));	//allocating memory for argument list
	user_arg_list->arg_total = size2;	//assign total number of arguments
	user_arg_list->user_input = malloc(size2 * sizeof(char*));	//allocating memory for arguments from the user
	//assign arguments from the user
	for(int i = 0; i < user_arg_list->arg_total; ++i)
	{
		int len = strlen(argv[i]) + 1;
		user_arg_list->user_input[i] = malloc(len);
		strncpy(user_arg_list->user_input[i], argv[i], len);
	}
	//assign function names and functions to function table
	function_table ft[] = {
		{"Exit", exit_program},
		{"Addition", addition},
		{"Subtraction", subtraction},
		{"Multiplication", multiplication},
		{"Division", division},
		{"Modulo", modulo},
		{"Reverse Input", reverse}
	};
	//call specific function using function pointer
	double result = (*ft[user_option].to_call)(user_arg_list);
	//reverse function includes print
	if(user_option != 6)
	{
		printf("Result: %f\n", result);
	}
	//ends program
	exit(EXIT_SUCCESS);
}









