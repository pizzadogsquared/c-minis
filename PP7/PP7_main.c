//code by Elijah Sprouse

//header files
#include "battleship_lib.h"

//main program
int main()
{
	//initialize variables
		//2D array solution[][] to hold the locations of ships and lengths
	char solution[SIZE][SIZE];
		//2D array game[][] to hold the user's attempted hits and misses
	char game[SIZE][SIZE];
		//useful newline character for print functions to increase readibility
	char*newLine = "\n";
		//initialize row and col values to hold user-entered coordinates
		//with placeholder 1
	int row = 1;
	int col = 1;	
	
	//intialize random number gen
		//function: initializeRandom
	initializeRandom();
	
	//create the bare solution board, filling everything with char 0
		//function: buildBoard
	buildBoard(solution, '0');
	
	//create the bare game board, filling everything with char _
		//function: buildBoard
	buildBoard(game, '_');
	
	//print a title message to the user
		//function: printf
	printf("Battleship Game");
	printf(newLine);
	printf("===============");
	printf(newLine);
	printf(newLine);
	printf("Game board:");
	printf(newLine);
	
	//print the board that the user will play on to the user
		//function: printMatrix
	printMatrix(game);
	
	//generate ships in random locations on the secret board
		//function: fillBoard
	fillBoard(solution);
	

	
	// this controls the game loop while the user hasn't won or chosen to
	//give up.
	while ( (checkVictory(solution, game) == false) &&
			( (row != -1) && (col != -1) ) )
	{
		//prompt for user input
			//function: printf
		printf("Enter the ROW (0-9) where you want ");
		printf("to shoot or -1 to give up: ");
		
		//read user input
			//function: scanf
		scanf("%d", &row);
		
		
		//	this while loop will run while the user keeps entering
		//invalid coordinates
		while ( (row < -1) || (row > (SIZE - 1)) )
		{
			//prompt for corrected user input
				//function: printf
			printf("Invalid input. ");
			printf("Please enter a number between 0 and 9.");
			printf(newLine);
			printf("Enter the ROW (0-9) where you want ");
			printf("to shoot or -1 to give up: ");
			
			//read user input
				//function: scanf
			scanf("%d", &row);
		}
		
		if ( (row != -1) && (col != -1) )
		{
			//prompt for user input
				//function: printf
			printf("Enter the COLUMN (0-9) where you want ");
			printf("to shoot or -1 to give up: ");
			
			//read user input
				//function: scanf
			scanf("%d", &col);
			
			//	this while loop will run while the user keeps entering
			//invalid coordinates
			while ( (col < -1) || (col > (SIZE - 1)) )
			{
				//prompt for corrected user input
					//function: printf
				printf("Invalid input. ");
				printf("Please enter a number between 0 and 9.");
				printf(newLine);
				printf("Enter the COLUMN (0-9) where you want ");
				printf("to shoot or -1 to give up: ");
			
				//read user input
					//function: scanf
				scanf("%d", &col);
			}
		
			// this block will run if the user hasn't given up
			if ( (row != -1) && (col != -1) )
			{
				//shoot at the position the user entered
					//function: shoot
				shoot(solution, game, row, col);
				
				//tell user this is the current result
					//function: printf
				printf("Current game board: ");
				printf(newLine);
				
				//show the user the result
					//function: printMatrix
				printMatrix(game);
			}
		}
	}
	
	//check if the user entered the ints for giving up in either row or col
	if ( (row == -1) || (col == -1) )
	{
		//if so, print a message
			//function: printf
		printf("You gave up. Here is the solution board: ");
		printf(newLine);
		
		//show the solution board
			//function: printMatrix
		printMatrix(solution);
	}
	
	// if the previous conditions are false, the user exited the
	//while loop without giving up, meaning they won.
	else
	{
		printf(newLine);
		printf("Congratulations! You sunk all of my battleships!");
	}
	
	//return success
	return 0;
	
}












