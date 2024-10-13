//code by Elijah Sprouse

// header files
#include "yahtzee_lib.h"

// main program
int main()
{
    // initialize program
        // initialize the random number generator
            // function: initializePlayer
    initializePlayer();
        // declare variables to hold the dice
    int dice1, dice2, dice3, dice4, dice5;

        // declare the variable to store the user's choice
    char choice;
        // inialize the variable that stores the play
    int play = NO_PLAY;

        // print a title
    printf("\nWelcome to Simple Yahtzee!\n");
    printf("==========================\n\n");

    // begin game
        // prompt the user for the play
            // function: printf
    printf("Do you want to roll the dice (y/n): ");
        // wait for user input
            // function: getChoice
    choice = getChoice();

        // TODO 1: create a loop that runs while the user wants to continue
        while (choice == 'y')
		{
            // TODO 2: roll the dice (one at a time)
			//roll dice 1
				//function: rollDice()
			dice1 = rollDice();
			//roll dice 2
				//function: rollDice()
			dice2 = rollDice();
			//roll dice 3
				//function: rollDice()
			dice3 = rollDice();
			//roll dice 4
				//function: rollDice()
			dice4 = rollDice();
			//roll dice 5
				//function: rollDice()
			dice5 = rollDice();
			
            // TODO 3: print the dice
			
			//tell the user what they rolled
				//function: printf
			printf("Your roll: %d, %d, %d, ", dice1, dice2, dice3);
			printf("%d, %d\n", dice4, dice5);
			
            // TODO 4: call the function decidePlay and store the result in
            //         the play variable
			
			// record what play the user got by using their dice rolls
				//function: decidePlay()
			play = decidePlay(dice1, dice2, dice3, dice4, dice5);
            // TODO 5: evaluate the play variable and print the appropriate 
            //         message
			//if the user rolled no valid plays, this block will run
			if (play == NO_PLAY)
			{
				//tell the user they rolled no valid plays
					//function: printf
				printf("You rolled no particular play.");
			}
			
			//if the user rolled a small straight, this block will run
			else if (play == S_STRAIGHT)
			{
				//tell the user they rolled a small straight
					//function: printf
				printf("You rolled a Small Straight!");
			}
			
			//if the user rolled a large straight, this block will run
			else if (play == L_STRAIGHT)
			{
				//tell the user they rolled a large straight
					//function: printf
				printf("You rolled a Large Straight!");
			}
			
			//if the user rolled a full house, this block will run
			else if (play == FULL_HOUSE)
			{
				//tell the user they rolled a full house
					//function: printf
				printf("You rolled a Full House!");
			}
			
			//if the user rolled a three of a kind, this block will run
			else if (play == THREE_OF_A_KIND)
			{
				//tell the user they rolled a three of a kind
					//function: printf
				printf("You rolled a Three of a Kind!");
			}
			
			//if the user rolled a four of a kind, this block will run
			else if (play == FOUR_OF_A_KIND)
			{
				//tell the user they rolled a four of a kind
					//function: printf
				printf("You rolled a Four of a Kind!");
			}
			
			//if all previous conditions are false, the user has rolled a
			//yahtzee, and this block will run
			else
			{
				//tell the user they rolled a yahtzee
					//function: printf
				printf("You rolled a Yahtzee!");
			}
			
		// prompt the user for continuing
            // function: printf
        printf("\n\nPlay again? (y/n): ");
        // Read the choice
            // function: getChoice
        choice = getChoice();
        }

    // END OF TODO 1: loop

    // End program
        // print a message
            // function: printf
    printf("\nThanks for playing Yahtzee!\n");
        // return success
    return 0;
}
