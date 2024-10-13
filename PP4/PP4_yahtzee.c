// header files
#include "yahtzee_lib.h"

// main program
int main()
{
    // initialize program
        // initialize the random number generator
            // function: initializePlayer
    initializePlayer();
        // declare variable to hold the dice
    int dice[NUM_DICE];

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
        
            // TODO 2: roll the dice to fill the array of dice

            // TODO 3: print the dice

            // TODO 4: call the function decidePlay and store the result in
            //         the play variable

            // TODO 5: evaluate the play variable and print the appropriate 
            //         message
        

        // prompt the user for continuing
            // function: printf
        printf("\nPlay again? (y/n): ");
        // Read the choice
            // function: getChoice
        choice = getChoice();
    
    // END OF TODO 1: loop

    // End program
        // print a message
            // function: printf
    printf("\nThanks for playing Yahtzee!\n");
        // return success
    return 0;
}
