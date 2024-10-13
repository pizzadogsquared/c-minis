//code by Elijah Sprouse

//header files
#include "battleship_lib.h"



void initializeRandom()
{
    // initalize random number generator
        // functions: srand, time
    srand(time(NULL));
}



void printMatrix(const char matrix[SIZE][SIZE])
{
	// iterate through the first dimension of the array
	for (int i = 0; i < SIZE; i++)
	{
		// iterate through the second dimension of the array
		for (int j = 0; j < SIZE; j++)
		{
			// print current 2D array element
				//function: printf
			printf("%c ", matrix[i][j]);
		}
		// print a newline character before going to next 1D element
			//function: printf
		printf("\n");
	}
}



void buildBoard(char board[SIZE][SIZE], char c)
{
	// iterate through the first dimension of the array
	for (int i = 0; i < SIZE; i++)
	{
		// iterate through the second dimension of the array
		for (int j = 0; j < SIZE; j++)
		{
			// build array by injecting char c into every
			//element across (i, j)
			board[i][j] = c;
		}
	}
}



bool isWater(const char board[SIZE][SIZE], int row, int col)
{
	// water is represented by char '0'. check if coordinates = water
	if (board[row][col] == '0')
	{
		// if they match, return true, because there is water at
		//the coordinates
		return true;
	}
	// otherwise, return false, because there is not water there
	return false;
}



void placeShipHorizontal(char board[SIZE][SIZE], int shipLength)
{
	//set checker to some number greater than 0 to enter while loop
	int checker = 1;
	while (checker > 0)
	{
		// reset checker counter. if it changes from here, the ship can't
		//be placed in its current generated spot
		checker = 0;
		
		// generate random values for row and col.
			//function: rand
		int row = rand() % SIZE;
		// col must be generated with the length of the ship in mind,
		// since the ship will be placed across columns (horizontally)
			//function: rand
		int col = rand() %(SIZE - shipLength + 1);
	
		//start check for if this position is valid by iterating through
		//every slot the ship would take up
		// iterate through the ship's length keeping i in range of col
		for (int i = col; i < (shipLength + col); i++)
		{
			// check if this current slot is already taken
			//(empty spots are marked with '0')
			if (board[row][i] != '0')
			{
				// if the slot is taken, increment checker.
				checker++;
			}
		}
		
		// check if the checker is unchanged.
		if (checker == 0)
		{
			// if so, the ship can be placed here without overwriting another
			// iterate through the ship's length keeping i in range of col
			for (int i = col; i < (shipLength + col); i++)
			{
				// convert shipLength to ASCII and overwrite empty space
				board[row][i] = shipLength + 48;
			}
		}
	}
}



void placeShipVertical(char board[SIZE][SIZE], int shipLength)
{
	//set checker to some number greater than 0 to enter while loop
	int checker = 1;
	while (checker > 0)
	{
		// reset checker counter. if it changes from here, the ship can't
		//be placed in its current generated spot
		checker = 0;
		
		// generate random values for row and col.
			//function: rand
		int col = rand() % SIZE;

		// row must be generated with the length of the ship in mind,
		// since the ship will be placed across rows (vertically)
			//function: rand
		int row = rand() %(SIZE - shipLength + 1);
	
		//start check for if this position is valid by iterating through
		//every slot the ship would take up
		// iterate through the ship's length keeping i in range of row
		for (int i = row; i < (shipLength + row); i++)
		{
			// check if this current slot is already taken
			//(empty spots are marked with '0')
			if (board[i][col] != '0')
			{
				// if the slot is taken, increment checker.
				checker++;
			}
		}
		
		// check if the checker is unchanged.
		if (checker == 0)
		{
			// if so, the ship can be placed here without overwriting another
			// iterate through the ship's length keeping i in range of row
			for (int i = row; i < (shipLength + row); i++)
			{
				// convert shipLength to ASCII and overwrite empty space
				board[i][col] = shipLength + 48;
			}
		}
	}
}



void fillBoard(char board[SIZE][SIZE])
{
	// initialize the shipsToPlace array, with the length of how many
	//ships it will place and the length of that ship in its element
	int shipsToPlace[] = {5, 4, 4, 3, 3, 3, 2, 2, 2, 2};
	
	// iterate through the array, using sizeof to reduce magic numbers
		//function: sizeof
	for (int i = 0; i < sizeof(shipsToPlace) / sizeof(shipsToPlace[0]); i++)
	{
		// randomly generate either a 0 or 1 to decide whether the ship will
		//be placed horizontally or vertically, respectively
		int shipFacing = rand() % 2;
		
		// check if the shipFacing value is 1
		if (shipFacing == 1)
		{
			// if so, the ship must be placed vertically,
			//as was decided randomly
				//function: placeShipVertical
			placeShipVertical(board, shipsToPlace[i]);
		}
		// otherwise, the shipFacing value must be 0
		else
		{
			//the ship must be placed horizontally
				//function: placeShipHorizontal
			placeShipHorizontal(board, shipsToPlace[i]);
		}
	}
}



void shoot(const char solution[SIZE][SIZE], char game[SIZE][SIZE],
			int row, int col)
{
		//function: isWater
	if (isWater(solution, row, col))
	{
		game[row][col] = 'W';
		printf("Miss!\n");
	}
	else
	{
		game[row][col] = 'S';
		printf("Ship!\n");
	}
}



bool checkVictory(const char solution[SIZE][SIZE],
					const char game[SIZE][SIZE])
{
	// iterate through the first dimension of the arrays
	for (int i = 0; i < SIZE; i++)
	{
		// iterate through the second dimension of the arrays
		for (int j = 0; j < SIZE; j++)
		{
			int shipOrWater  = solution[i][j] - 48;
			if ((shipOrWater > 0) && (game[i][j] != 'S') )
			{
				return false;
			}
		}
	}
	return true;
}










