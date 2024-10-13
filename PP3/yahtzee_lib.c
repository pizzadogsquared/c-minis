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

int countNumber(
	int number, int dice1, int dice2, int dice3, int dice4, int dice5)
{
	// set placeholder value number to 0
		// variable "count" counts how many die match number
	int count = 0;
	
	// check if dice1 matches the number
	if (number == dice1)
	{
		// if so, raise count by 1
		count += 1;
	}
	
	//check if dice2 matches the number
	if (number == dice2)
	{
		// if so, raise count by 1
		count += 1;
	}
	
	//check if dice3 matches the number
	if (number == dice3)
	{
		// if so, raise count by 1
		count += 1;
	}
	
	//check if dice4 matches the number
	if (number == dice4)
	{
		// if so, raise count by 1
		count += 1;
	}
	
	//check if dice5 matches the number
	if (number == dice5)
	{
		// if so, raise count by 1
		count += 1;
	}
	
	// return the count of how many die match the number
	return count;
}

bool isYahtzee(int dice1, int dice2, int dice3, int dice4, int dice5)
{
	//check if each dice is equal to each other
	if ((dice1 == dice2) && (dice3 == dice4) && (dice2 == dice4)
		&& (dice4 == dice5))
	{
		//if so, the user scored a yahtzee, return true
		return true;
	}
	//if not, the user has not scored a yahtzee
	else
	{
		//the user has not scored a yahtzee, so return false
		return false;
	}
}

bool isFourOfAKind(
	int count1, int count2, int count3, int count4, int count5, int count6)
{
	//check how many 1s were rolled
	if (count1 == 4)
	{
		//if rolled 1s are equal to four, return true
		return true;
	}
	
	//check how many 2s were rolled
	else if (count2 == 4)
	{
		//if rolled 2s are equal to four, return true
		return true;
	}
		
	//check how many 3s were rolled
	else if (count3 == 4)
	{
		//if rolled 3s are equal to four, return true
		return true;
	}
		
	//check how many 4s were rolled
	else if (count4 == 4)
	{
		//if rolled 4s are equal to four, return true
		return true;
	}
		
	//check how many 5s were rolled
	else if (count5 == 4)
	{
		//if rolled 5s are equal to four, return true
		return true;
	}
	
		
	//check how many 6s were rolled
	else if (count6 == 4)
	{
		//if rolled 6s are equal to four, return true
		return true;
	}
	
	//if none of the previous conditions are true, user has not rolled
	// a four-of-a-king
	else
	{
		//return false, as there is no four-of-a-kind
		return false;
	}
}

bool hasTwoEqual(
	int count1, int count2, int count3, int count4, int count5, int count6)
{
	//check how many 1s were rolled
	if (count1 == 2)
	{
		//if rolled 1s are equal to two, return true
		return true;
	}
	
	//check how many 2s were rolled
	else if (count2 == 2)
	{
		//if rolled 2s are equal to two, return true
		return true;
	}
	
	//check how many 3s were rolled
	else if (count3 == 2)
	{
		//if rolled 3s are equal to two, return true
		return true;
	}
	
	//check how many 4s were rolled
	else if (count4 == 2)
	{
		//if rolled 4s are equal to two, return true
		return true;
	}
	
	//check how many 5s were rolled
	else if (count5 == 2)
	{
		//if rolled 5s are equal to two, return true
		return true;
	}
	
	//check how many 6s were rolled
	else if (count6 == 2)
	{
		//if rolled 6s are equal to two, return true
		return true;
	}
	
	//if none of the previous conditions are true, user has not rolled
	// two equal dice rolls
	else
	{
		//return false, as there are not two equal dice rolls
		return false;
	}
}

bool hasThreeEqual(
	int count1, int count2, int count3, int count4, int count5, int count6)
{
	//check how many 1s were rolled
	if (count1 == 3)
	{
		//if rolled 1s are equal to three, return true
		return true;
	}
	
	//check how many 2s were rolled
	else if (count2 == 3)
	{
		//if rolled 2s are equal to three, return true
		return true;
	}
	
	//check how many 3s were rolled
	else if (count3 == 3)
	{
		//if rolled 3s are equal to three, return true
		return true;
	}
	
	//check how many 4s were rolled
	else if (count4 == 3)
	{
		//if rolled 4s are equal to three, return true
		return true;
	}
	
	//check how many 5s were rolled
	else if (count5 == 3)
	{
		//if rolled 5s are equal to three, return true
		return true;
	}
	
	//check how many 6s were rolled
	else if (count6 == 3)
	{
		//if rolled 6s are equal to three, return true
		return true;
	}
	
	//if none of the previous conditions are true, user has not rolled
	// three equal dice rolls
	else
	{
		//return false, as there are not three equal dice rolls
		return false;
	}
}

bool isThreeOfAKind(
	int count1, int count2, int count3, int count4, int count5, int count6)
{
	//check if the there are three equal rolls for any given number.
		//function: hasThreeEqual
		//will return true/false
	if(hasThreeEqual(
		count1, count2, count3, count4, count5, count6))
	{
		//if so, then check if the other rolls aren't equal to each other
			//function: hasTwoEqual
			//will return true/false
		if(hasTwoEqual(
			count1, count2, count3, count4, count5, count6) == false)
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
}

bool isFullHouse(
	int count1, int count2, int count3, int count4, int count5, int count6)
{
	//check if the there are three equal rolls for any given number.
		//function: hasThreeEqual
		//will return true/false
	if(hasThreeEqual(
		count1, count2, count3, count4, count5, count6))
	{
		//if so, then check if the two other rolls are equal to each other
		//as well
			//function: hasTwoEqual
			//will return true/false
		if(hasTwoEqual(
			count1, count2, count3, count4, count5, count6))
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
	
	//if the previous conditions are false, then the user has not rolled
	//a full house.
	else
	{
		//the function ends and returns false
		return false;
	}
}

bool isLargeStraight(
	int count1, int count2, int count3, int count4, int count5, int count6)
{
	//logically, a large straight will either have a one in it, or a six.
	
	//first, check if there is at least one dice roll that shows one
	if (count1 > 0)
	{
		//if so, check if there are four consecutive dice rolls after that
		if ((count2 > 0) && (count3 > 0) && (count4 > 0) && (count5 > 0))
		{
			//if there are five consecutive rolls, this means that the user
			//has rolled a large straight.
			return true;
		}
		
		//if neither previous conditions are true, this block will run
		else
		{
			//if previous conditions are false, then the user has not rolled
			//a large straight
			return false;
		}
	}
	
	//if there is not a one in this straight, then there will be at least
	//one six if this is a large straight.
	else if (count6 > 0)
	{
		//if so, check if there are four consecutive dice rolls just before.
		if ((count2 > 0) && (count3 > 0) && (count4 > 0) && (count5 > 0))
		{
			//if there are five consecutive rolls, this means that the user
			//has rolled a large straight.
			return true;
		}
		
		//if neither previous conditions are true, this block will run
		else
		{
			//if previous conditions are false, then the user has not rolled
			//a large straight
			return false;
		}
	}
	
	//if neither previous conditions are true, this block will run
	else
	{
		//if previous conditions are false, then the user has not rolled
		//a large straight
		return false;
	}
}

bool isSmallStraight(
	int count1, int count2, int count3, int count4, int count5, int count6)
{
	//logically, there are three possible combinations for small straights
	
	//check if the combination has at least one dice roll for all rolls
	//from 1-4
	if ((count1 > 0) && (count2 > 0) && (count3 > 0) && (count4 > 0))
	{
		//if so, the user has rolled a small straight.
		return true;
	}
	
	//check if the combination has at least one dice roll for all rolls
	//from 2-5
	else if ((count2 > 0) && (count3 > 0) && (count4 > 0) && (count5 > 0))
	{
		//if so, the user has rolled a small straight.
		return true;
	}

	//check if the combination has at least one dice roll for all rolls
	//from 3-6
	else if ((count3 > 0) && (count4 > 0) && (count5 > 0) && (count6 > 0))
	{
		//if so, the user has rolled a small straight.
		return true;
	}
	
	//if all previous conditions are false, the user has not rolled a
	//small straight.
	else
	{
		//the user has not rolled a small straight, so the function returns
		//false
		return false;
	}
}

int decidePlay(int dice1, int dice2, int dice3, int dice4, int dice5)
{
	//check if the user has rolled a yahtzee
		//function: isYahtzee
		//will return true/false
	if(isYahtzee(dice1, dice2, dice3, dice4, dice5))
	{
		//if the user has rolled a yahtzee, decidePlay will return the play
		return YAHTZEE;
	}
	
	//if not, the counts for how many of each dice roll showed up must
	//be calculated
	else
	{
		//count how much 1 was rolled
			//function: countNumber
		int count1 = countNumber(1, dice1, dice2, dice3, dice4, dice5);
		//count how much 2 was rolled
			//function: countNumber
		int count2 = countNumber(2, dice1, dice2, dice3, dice4, dice5);
		//count how much 3 was rolled
			//function: countNumber
		int count3 = countNumber(3, dice1, dice2, dice3, dice4, dice5);
		//count how much 4 was rolled
			//function: countNumber
		int count4 = countNumber(4, dice1, dice2, dice3, dice4, dice5);
		//count how much 5 was rolled
			//function: countNumber
		int count5 = countNumber(5, dice1, dice2, dice3, dice4, dice5);
		//count how much 6 was rolled
			//function: countNumber
		int count6 = countNumber(6, dice1, dice2, dice3, dice4, dice5);
		
		//first, check if the play is a four of a kind
			//function: isFourOfAKind
			//will return true/false
		if(isFourOfAKind(
			count1, count2, count3, count4, count5, count6))
		{
			//if the user has rolled a four of a kind, decidePlay will
			//return the play
			return FOUR_OF_A_KIND;
		}
		
		//check if the play is a three of a kind
			//function: isThreeOfAKind
			//will return true/false
		else if(isThreeOfAKind(
			count1, count2, count3, count4, count5, count6))
		{
			//if the user has rolled a three of a kind, decidePlay will
			//return the play
			return THREE_OF_A_KIND;
		}
		
		//check if the play is a full house
			//function: isFullHouse
			//will return true/false
		else if(isFullHouse(
			count1, count2, count3, count4, count5, count6))
		{
			//if the user has rolled a full house, decidePlay will
			//return the play
			return FULL_HOUSE;
		}
		
		//check if the play is a large straight
			//function: isFullHouse
			//will return true/false
		else if(isLargeStraight(
			count1, count2, count3, count4, count5, count6))
		{
			//if the user has rolled a large straight, decidePlay will
			//return the play
			return L_STRAIGHT;
		}
		
		//check if the play is a small straight
			//function: isFullHouse
			//will return true/false
		else if(isSmallStraight(
			count1, count2, count3, count4, count5, count6))
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





