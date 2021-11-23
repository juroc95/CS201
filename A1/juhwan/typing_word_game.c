//Juhwan Lee
//CS201
//Homework 1
//This program is a typing word game

//Header
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#define SIZE 20
#ifndef timersub
#define timersub(a, b, result) \
	do{ \
		(result)->tv_sec = (a)->tv_sec - (b)->tv_sec; \
		(result)->tv_usec = (a)->tv_usec - (b)->tv_usec; \
		if((result)->tv_usec < 0){ \
			--(result)->tv_sec; \
			(result)->tv_usec += 1000000; \
		} \
	} while(0)
#endif //timersub

//Prototypes
void shuffle_array(int array[]);
int check_if_correct(int index, int i);

//Main
int main(){
	struct timeval time0, time1, time_diff;
	//start time
	gettimeofday(&time0, NULL);
	int array[9];

	srand((unsigned int)time(NULL));
	//get random integers
	shuffle_array(array);
	printf("This is a game that tests typing speed\n\n");
	printf("Type the following words:\n");
	int i = 0;
	//start game
	while(i != 9){
		if(check_if_correct(array[i], i) == 1)
			++i;
	}
	//end time
	gettimeofday(&time1, NULL);
	//get time spent
	timersub(&time1, &time0, &time_diff);
	printf("You took %ld seconds %06ld microseconds\n", time_diff.tv_sec, time_diff.tv_usec);

	exit(EXIT_SUCCESS);
}

//Random integer function
void shuffle_array(int array[]){
	for(int i = 0; i < 9; ++i){
		array[i] = i + 1;
	}
	for(int i = 0; i < 9; ++i){
		int temp = array[i];
		int random_index = rand() % 9;
		array[i] = array[random_index];
		array[random_index] = temp;
	}
}

//Check if correct function
int check_if_correct(int index, int i){
	char array1[SIZE] = "The";
	char array2[SIZE] = "quick";
	char array3[SIZE] = "brown";
	char array4[SIZE] = "fox";
	char array5[SIZE] = "jumps";
	char array6[SIZE] = "over";
	char array7[SIZE] = "the";
	char array8[SIZE] = "lazy";
	char array9[SIZE] = "dog";
	char user_input[SIZE];
	char c;

	if(index == 1){
		int flag = 0;
		printf("word #%d is The: ", i + 1);
		if(scanf("%20s", user_input) == 1){
			while((c = getchar()) != '\n' && c != EOF);
			if(strncmp(array1, user_input, 20) == 0)
				flag = 1;
			if(flag == 1)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	if(index == 2){
		int flag = 0;
		printf("word #%d is quick: ", i + 1);
		if(scanf("%20s", user_input) == 1){
			while((c = getchar()) != '\n' && c != EOF);
			if(strncmp(array2, user_input, 20) == 0)
				flag = 1;
			if(flag == 1)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	if(index == 3){
		int flag = 0;
		printf("word #%d is brown: ", i + 1);
		if(scanf("%20s", user_input) == 1){
			while((c = getchar()) != '\n' && c != EOF);
			if(strncmp(array3, user_input, 20) == 0)
				flag = 1;
			if(flag == 1)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	if(index == 4){
		int flag = 0;
		printf("word #%d is fox: ", i + 1);
		if(scanf("%20s", user_input) == 1){
			while((c = getchar()) != '\n' && c != EOF);
			if(strncmp(array4, user_input, 20) == 0)
				flag = 1;
			if(flag == 1)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	if(index == 5){
		int flag = 0;
		printf("word #%d is jumps: ", i + 1);
		if(scanf("%20s", user_input) == 1){
			while((c = getchar()) != '\n' && c != EOF);
			if(strncmp(array5, user_input, 20) == 0)
				flag = 1;
			if(flag == 1)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	if(index == 6){
		int flag = 0;
		printf("word #%d is over: ", i + 1);
		if(scanf("%20s", user_input) == 1){
			while((c = getchar()) != '\n' && c != EOF);
			if(strncmp(array6, user_input, 20) == 0)
				flag = 1;
			if(flag == 1)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	if(index == 7){
		int flag = 0;
		printf("word #%d is the: ", i + 1);
		if(scanf("%20s", user_input) == 1){
			while((c = getchar()) != '\n' && c != EOF);
			if(strncmp(array7, user_input, 20) == 0)
				flag = 1;
			if(flag == 1)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	if(index == 8){
		int flag = 0;
		printf("word #%d is lazy: ", i + 1);
		if(scanf("%20s", user_input) == 1){
			while((c = getchar()) != '\n' && c != EOF);
			if(strncmp(array8, user_input, 20) == 0)
				flag = 1;
			if(flag == 1)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	if(index == 9){
		int flag = 0;
		printf("word #%d is dog: ", i + 1);
		if(scanf("%20s", user_input) == 1){
			while((c = getchar()) != '\n' && c != EOF);
			if(strncmp(array9, user_input, 20) == 0)
				flag = 1;
			if(flag == 1)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	else
		return 0;
}

