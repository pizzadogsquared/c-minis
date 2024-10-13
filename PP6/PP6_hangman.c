//code by Elijah Sprouse

//header files
#include "hangman_lib.h"

//main program
int main()
{
	//initialize variables
		//boolean var "giveup"
	bool giveup = false;
	
		//store the choice array as a single character
	char choice[16];
	
		//initialize the single character value
	char letterChoice = 'y';
		
	//print a title message to the user
	puts("\n\n***************************\n"
		"Welcome to the Hangman Game\n"
		"***************************\n");
	
	//this function will run while the user still wants to play and
	//hasn't given up.
	while ((letterChoice == 'y') && (giveup != true))
	{
		//run the game; check if the user has won the game
		if(play(&giveup))
		{
			//print a message to the user
				//function: puts
			puts("You won the round! Well done!\n");
		}
	
		//if the user failed, this block will run.
		else
		{
			//run this block if the user gave up
			if(giveup)
			{
				//print a message to the user
					//function: puts
				puts("You gave up!");
				puts("Come back another time!\n");
				//end the program by returning success
				return 0;
			}
			//if the user didn't give up, but instead failed, this block
			//will run and the function will continue
			else
			{
				//print a message to the user
					//function: puts
				puts("You lost the round!\n");
			}
		}
	
		//prompt user input
			//function: puts
		puts("Do you want to play a new round? [y|n]");
	
		//read user input
			//function: scanf
		scanf("%s", choice);
	
		//transfer the single character array to the letterChoice variable
		//in lowercase
		letterChoice = tolower(choice[0]);
	
		//if the user hasn't given a valid choice that can be read, this while
		//loop will execute until they do.
		while ((letterChoice != 'y') && (letterChoice != 'n'))
		{
			//instruct the user on possible options
				//function: puts
			puts("I didn't get that. Please use y to yes and n to no.");
		
			//read user input
				//function: scanf
			scanf("%s", choice);
	
			//transfer the single character array to the letterChoice variable
			//in lowercase
			letterChoice = tolower(choice[0]);
		}
	
	
	
		// this block will run if the user doesn't want to play again.
		if(letterChoice == 'n')
		{
			//print a message to the user
				//function: puts
			puts("Come back another time!\n");
		}
	
	}
	
	//end the program by returning success
	return 0;
}