//code by Elijah Sprouse

//header files
#include "yahtzee_lib.h"

void initializePlayer()
{
    // initalize random number generator
        // functions: srand, time
    srand(time(NULL));
	
}

char getChoice()
{
	//store the choice array as a single character
	char choice[0];
	
	//initialize the single character value
	char letterChoice;
	
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
			//function: printf
		printf("Invalid option. Please type 'y' to play or 'n' to exit: ");
		
		//read user input
			//function: scanf
		scanf("%s", choice);
	
		//transfer the single character array to the letterChoice variable
		//in lowercase
		letterChoice = tolower(choice[0]);
	}
	return letterChoice;
}

int rollDice()
{
    // generate the random number and constraint within range (1-6)
        // function: rand
    return rand() % NUM_SIDES + 1;
}


void countNumber(const int dice[], int counts[])
{
	// create a for loop for every number that can appear on a dice
	for (int countsIter = 0; countsIter < NUM_SIDES; countsIter++)
	{
		// create a for loop for every dice the user rolled
		for (int diceIter = 0; diceIter < NUM_DICE; diceIter++)
		{
			// check if the current dice roll matches the current
			//rolled number
			if ((countsIter + 1) == dice[diceIter])
			{
				// if the two are equal, then add 1 to the count of
				//how many times that dice roll has appeared
				counts[countsIter] += 1;
			}	
		}
	}
}


bool isYahtzee(const int dice[])
{
	// set a value to compare every other array value to
	int compare = dice[0];
	
	// iterate through every dice array value
	for (int i = 0; i < NUM_DICE; i++)
	{
		// if at least one dice roll is not equal to the first, then
		//logically, all dice rolls aren't equal, and the play isn't
		//a yahtzee.
		if (dice[i] != compare)
		{
			// return false because play isn't a yahtzee
			return false;
		}
	}
	
	// if the program was able to exit the for loop, then all of the
	//dice rolls were equal to the first one, meaning they are all equal
	//to each other. The play is a yahtzee.
	return true;
}
	


bool isFourOfAKind(const int counts[])
{
	// iterate through every counts array value
	for (int i = 0; i < NUM_SIDES; i++)
	{
		// check if the current array value is equal to 4, meaning
		// check if there were four dice rolls matching i + 1.
		if (counts[i] == 4)
		{
			// if so, the play is a four-of-a-kind
			return true;
		}
	
	}
	//if the program made it through the for loop without satisfying the
	//condition, then the play is not a four-of-a-kind
	return false;
}


bool hasTwoEqual(const int counts[])
{
	
	// iterate through every counts array value
	for (int i = 0; i < NUM_SIDES; i++)
	{
		// check if the current array value is equal to 2, meaning
		// check if there were two dice rolls matching i + 1.
		if (counts[i] == 2)
		{
			// if so, the play has two equal dice rolls
			return true;
		}

	}
	
	//if the program made it through the for loop without satisfying the
	//condition, then the play does not have two equal dice rolls
	return false;
}	
	
	

bool hasThreeEqual(const int counts[])
{
	
	// iterate through every counts array value
	for (int i = 0; i < NUM_SIDES; i++)
	{
		// check if the current array value is equal to 3, meaning
		// check if there were three dice rolls matching i + 1.
		if (counts[i] == 3)
		{
			// if so, the play has three equal dice rolls
			return true;
		}
	
	}
	
	//if the program made it through the for loop without satisfying the
	//condition, then the play does not have three equal dice rolls
	return false;
}	


bool isThreeOfAKind(const int counts[])
{
	//check if the there are three equal rolls for any given number.
		//function: hasThreeEqual
		//will return true/false
	if (hasThreeEqual(counts))
	{
		//if so, then check if the other rolls aren't equal to each other
			//function: hasTwoEqual
			//will return true/false
		if((hasTwoEqual(counts)) == false)
		{
			//if there are two unequal rolls and three equal rolls, then the
			//user has rolled a three-of-a-kind
			return true;
		}
		
		//if the previous conditions are false, then the user has not rolled
		//a three-of-a-kind.
		else
		{
			//the function ends and returns false
			return false;
		}
	}
	
	//if the previous conditions are false, then the user has not rolled
	//a three-of-a-kind.
	else
	{
		//the function ends and returns false
		return false;
	}
	
	//as a failsafe, return false at the end of the function.
	return false;
}

bool isFullHouse(const int counts[])
{
	//check if the there are three equal rolls for any given number.
		//function: hasThreeEqual
		//will return true/false
	if(hasThreeEqual(counts))
	{
		//if so, then check if the two other rolls are equal to each other
		//as well
			//function: hasTwoEqual
			//will return true/false
		if(hasTwoEqual(counts))
		{
			//if there are two equal rolls and three equal rolls, then the
			//user has rolled a full house
			return true;
		}
		
		//if the previous conditions are false, then the user has not rolled
		//a full house.
		else
		{
			//the function ends and returns false
			return false;
		}
	}
	
	// if the previous conditions are false, then the user has not rolled
	//a full house.
	else
	{
		//the function ends and returns false
		return false;
	}
	
	// as a failsafe, return false at the end of the function.
	return false;
}


bool isLargeStraight(const int counts[])
{
	// initialize placeholder array
	int noPlayCounter[L_STRAIGHT];
	
	// iterate through every index in the array.
	for (int i = 0; i < L_STRAIGHT; i++)
	{
		// set the value of the current indexed element to placeholder 0
		noPlayCounter[i] = 0;
	}
	
	// check if there is at least one dice roll for numbers 1 through 5
	for (int i = 0; i < (NUM_SIDES - 1); i++)
	{
		// if a count is equal to 0, it isn't a sequence of 5.
		if (counts[i] == 0)
		{
			// increment the element that indicates a missing sequence.
			noPlayCounter[0] += 1;
		}
	}

	// check if there is at least one dice roll for numbers 2 through 6
	for (int i = 1; i < NUM_SIDES; i++)
	{
		// if a count is equal to 0, it isn't a sequence of 5.
		if (counts[i] == 0)
		{
			// increment the element that indicates a missing sequence.
			noPlayCounter[1] += 1;
		}
	}
	
	//check if there aren't any skipped values in the previous sequences
	//(sequence 1-5 or 2-6).
	for (int i = 0; i < L_STRAIGHT; i++)
	{
		// if the counter is equal to 0, there is a sequence that is a
		// large straight.
		if (noPlayCounter[i] == 0)
		{
			// return true, because the function is a large straight
			return true;
		}
	}

	// if the previous conditions weren't satisfied, then the play is
	//a large straight. end the function and return true.
	return false;
}


bool isSmallStraight(const int counts[])
{
	// initialize placeholder array
	int noPlayCounter[S_STRAIGHT];
	
	// iterate through every index in the array.
	for (int i = 0; i < S_STRAIGHT; i++)
	{
		// set the value of the current indexed element to placeholder 0
		noPlayCounter[i] = 0;
	}
	
	// check if there is at least one dice roll for numbers 1 through 4
	for (int i = 0; i < (NUM_SIDES - 2); i++)
	{
		// if a count is equal to 0, it isn't a sequence of 4.
		if (counts[i] == 0)
		{
			// increment the element that indicates a missing sequence.
			noPlayCounter[0] += 1;
		}
	}

	// check if there is at least one dice roll for numbers 2 through 5
	for (int i = 1; i < (NUM_SIDES - 1); i++)
	{
		// if a count is equal to 0, it isn't a sequence of 4.
		if (counts[i] == 0)
		{
			// increment the element that indicates a missing sequence.
			noPlayCounter[1] += 1;
		}
	}
	
	// check if there is at least one dice roll for numbers 3 through 6
	for (int i = 2; i < NUM_SIDES; i++)
	{
		// if a count is equal to 0, it isn't a sequence of 4.
		if (counts[i] == 0)
		{
			// increment the element that indicates a missing sequence.
			noPlayCounter[2] += 1;
		}
	}
	
	//check if there aren't any skipped values in the previous sequences
	//(sequence 1-4 or 2-5 or 3-6).
	for (int i = 0; i < S_STRAIGHT; i++)
	{
		// if the counter is equal to 0, there is a sequence that is a
		// large straight.
		if (noPlayCounter[i] == 0)
		{
			// return true, because the function is a large straight
			return true;
		}
	}

	// if the previous conditions weren't satisfied, then the play is
	//a large straight. end the function and return true.
	return false;
}



int decidePlay(const int dice[])
{
	//check if the user has rolled a yahtzee
		//function: isYahtzee
		//will return true/false
	if(isYahtzee(dice))
	{
		//if the user has rolled a yahtzee, decidePlay will return the play
		return YAHTZEE;
	}
	
	//if not, the counts for how many of each dice roll showed up must
	//be calculated
	else
	{
		//initialize array counts[] with size NUM_SIDES
		int counts[NUM_SIDES];
		
		//use a for loop to fill counts[NUM_SIDES] with 0 in each element.
		for (int i = 0; i < NUM_SIDES; i++)
		{
			//set element i in array counts[] equal to 0
			counts[i] = 0;
		}
		
		//count how much 1 was rolled
			//function: countNumber
		countNumber(dice, counts);
		
		//first, check if the play is a four of a kind
			//function: isFourOfAKind
			//will return true/false
		if(isFourOfAKind(counts))
		{
			//if the user has rolled a four of a kind, decidePlay will
			//return the play
			return FOUR_OF_A_KIND;
		}
		
		//check if the play is a three of a kind
			//function: isThreeOfAKind
			//will return true/false
		else if(isThreeOfAKind(counts))
		{
			//if the user has rolled a three of a kind, decidePlay will
			//return the play
			return THREE_OF_A_KIND;
		}
		
		//check if the play is a full house
			//function: isFullHouse
			//will return true/false
		else if(isFullHouse(counts))
		{
			//if the user has rolled a full house, decidePlay will
			//return the play
			return FULL_HOUSE;
		}
		
		//check if the play is a large straight
			//function: isFullHouse
			//will return true/false
		else if(isLargeStraight(counts))
		{
			//if the user has rolled a large straight, decidePlay will
			//return the play
			return L_STRAIGHT;
		}
		
		//check if the play is a small straight
			//function: isFullHouse
			//will return true/false
		else if(isSmallStraight(counts))
		{
			//if the user has rolled a small straight, decidePlay will
			//return the play
			return S_STRAIGHT;
		}
		
		//if all previous blocks are false, the user has rolled no
		//valid plays
		else
		{
			//if the user has rolled no valid plays, decidePlay will
			//return that
			return NO_PLAY;
		}
	}
}





