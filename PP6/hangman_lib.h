#ifndef HANGMAN_LIB_H
#define HANGMAN_LIB_H


// header files
#include <stdio.h>	// for printf() and scanf()
#include <time.h>	// for time()
#include <stdlib.h>	// for rand()
#include <ctype.h>	// for tolower()
#include <string.h>	// for strlen() and strcpy()
#include <stdbool.h>	// for bool type



// global constans
#define FRUITS_LEN 104
#define ATTEMPTS 6
#define MAX_FRUIT_SIZE 25
#define LEN_FRUITS 104
extern const char* FRUITS[LEN_FRUITS];



/**
 * Name: initializeRandom
 * Process: initialize the random number generator
 * Function input/parameters: none
 * Function output/parameters: none
 * Function output/returned: none
 * Dependencies: stdlib.h - srand
 * 				 time.h - time
 **/
void initializeRandom();



/**
 * Name: getSecretWord
 * Process: randomly generate a word from const array FRUITS[]
 * Function input/parameters: none
 * Function output/parameters: 
			secretWord[] - holds the string that will be guessed
 * Function output/returned:
			size - the length of the secret word
 * Dependencies:
			rand() - to randomize a selection from FRUITS[]
			strcpy() - to copy the selection from FRUITS to secretWord
 **/
int getSecretWord(char *secretWord);



/**
 * Name: buildOutputArray
 * Process: builds an array of empty values, same size as secret word
 * Function input/parameters:
			size - the length of the secret word
 * Function output/parameters: 
			secretWord[] - holds the string that will be guessed
 * Function output/returned:
			size - the length of the secret word
 * Dependencies: None
 **/
void buildOutputArray(int size, char *outputArray);



/**
 * Name: buildAttemptArray
 * Process: stores incorrect guesses in each pointer
 * Function input/parameters:
			size - the length of the secret word
 * Function output/parameters: 
			secretWord[] - holds the string that will be guessed
 * Function output/returned:
			size - the length of the secret word
 * Dependencies:
			rand() - to randomize a selection from FRUITS[]
 **/
void buildAttemptArray(char *attempts);


/**
 * Name: checkGuess
 * Process: checks if the letter guessed is in the secret word
 * Function input/parameters:
			guess - the letter the user has guessed
			secretWord - the string that we are checking
 * Function output/parameters: None
 * Function output/returned:
			T/F - whether or not the guess is correct
 * Dependencies: stdbool.h - for bool data type
 **/
bool checkGuess(char guess, const char *secretWord);


/**
 * Name: fillOutputArray
 * Process: fills the output array with every correct guess and its place
 * Function input/parameters:
			guess - the letter the user has guessed
			secretWord - the string that we are checking
 * Function output/parameters: 
			outputArray - each correct guess is recorded here
 * Function output/returned:
			T/F - whether or not the guess is repeated
 * Dependencies: stdbool.h - for bool data type
 **/
bool fillOutputArray(char guess, const char *secretWord, char *outputArray);


/**
 * Name: fillAttemptArray
 * Process: fills the attempts array with the user's incorrect guess
 * Function input/parameters:
			guess - the letter the user has guessed
 * Function output/parameters: 
			attempts - each incorrect guess is recorded here
 * Function output/returned:
			T/F - whether or not the guess is repeated
 * Dependencies: stdbool.h - for bool data type
 **/
bool fillAttemptsArray(char guess, char *attempts);


/**
 * Name: checkVictory
 * Process: checks if the user has correctly guessed the secret word
 * Function input/parameters:
			size - the size of the secret word
			outputArray - the user's correct guesses
 * Function output/parameters: None
 * Function output/returned:
			T/F - whether or not the user has won
 * Dependencies: stdbool.h - for bool data type
 **/
bool checkVictory(int size, char *outputArray);


/**
 * Name: checkVictory
 * Process: checks if the user has run out of attempts (lost)
 * Function input/parameters:
			attempts - the user's incorrect guesses
 * Function output/parameters: None
 * Function output/returned:
			T/F - whether or not the user has lost
 * Dependencies: stdbool.h - for bool data type
 **/
bool checkDefeat(char *attempts);


/**
 * Name: play
 * Process: controls the flow of the game
 * Function input/parameters: None
 * Function output/parameters:
			giveup - this parameter records if the user has given up
 * Function output/returned:
			T/F - whether or not the user has won
 * Dependencies: 
			stdbool.h - for bool data type
			tolower() - to lower capitalized characters
			puts() - to print strings to stdout
			fputs() - to print strings to stdout without \n
	---			uses for below functions listed above		---
			initializeRandom()
			getSecretWord()
			buildOutputArray()
			buildAttemptArray()
			checkGuess()
			fillOutputArray()
			fillAttemptArray()
			checkVictory()
			checkDefeat()
 **/
bool play(bool *giveup); 









#endif