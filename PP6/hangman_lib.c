//code by Elijah Sprouse

//header files
#include "hangman_lib.h"

const char* FRUITS[104] = {"abiu",  "acai", "acerola", "akebi", "ackee", 
    "apple", "apricot", "araza", "avocado", "banana", "bilberry", "blackberry",
    "blackcurrant", "blueberry", "boysenberry", "breadfruit", "canistel",
    "cashew", "cempedak", "cherimoya", "cherry", "cloudberry", "coconut",
    "cranberry", "currant", "damson", "date", "dragonfruit", "pitaya", "durian",
    "elderberry", "feijoa", "fig", "gooseberry", "grape", "raisin",
    "grapefruit", "guava", "honeyberry", "huckleberry", "jabuticaba", "plinia",
    "jackfruit", "jambul", "jostaberry", "jujube", "kiwano", "kiwifruit",
    "kumquat", "lemon", "lime", "loganberry", "longan", "loquat", "lulo",
    "lychee", "mango", "mangosteen", "marionberry", "melon", "cantaloupe",
    "galia", "melon", "honeydew", "watermelon", "mulberry", "nance",
    "nectarine", "orange", "clementine", "mandarine", "tangerine", "papaya",
    "passionfruit", "pawpaw", "peach", "pear", "persimmon", "plantain", "plum", 
    "prune", "pineapple", "pineberry", "plumcot", "pluot", "pomegranate",
    "pomelo", "quince", "raspberry", "salmonberry", "rambutan", "redcurrant",
    "salak", "sapodilla", "sapote", "satsuma", "soursop", "strawberry",
    "tamarillo", "tamarind", "tangelo", "tayberry", "ximenia", "yuzu"};




void initializeRandom()
{
    // initalize random number generator
        // functions: srand, time
    srand(time(NULL));
}



int getSecretWord(char *secretWord)
{
	//copy a random word from array of strings FRUITS to secretWord[]
		//function: strcpy
	strcpy(secretWord, FRUITS[rand() % FRUITS_LEN]);
	
	//return length of copied string
	return strlen(secretWord);
}



void buildOutputArray(int size, char *outputArray)
{
	//iterate through the size of the secret word
	for (int i = 0; i < (size + 1); i++)
	{
		// this block will run on every iteration but the last
		if (i != size)
		{
			//fill each array index with underscores
			outputArray[i] = '_';
		}
		
		//this block will run on the last iteration
		else
		{
			//the element will become a null indicator
			outputArray[i] = '\0';
		}
	}
}




void buildAttemptArray(char *attempts)
{
	//iterate through the allotted attempts (array)
	for (int i = 0; i < (ATTEMPTS + 1); i++)
	{
		//this block will run on every iteration but the last
		if (i != ATTEMPTS)
		{
			//fill each array index with an asterik
			attempts[i] = '*';
		}
		
		//this block will run on the last iteration
		else
		{
			//the element will become a null indicator
			attempts[i] = '\0';
		}
	}
}
	
	
	
bool checkGuess(char guess, const char *secretWord)
{
	//this loop will iterate through the size of the secret word
	for (int i = 0; i < strlen(secretWord); i++)
	{
		// if the user guessed a letter that is contained in the secret word
		//return true and end the function
		if (guess == secretWord[i])
		{
			//the user has guessed correctly, return true
			return true;
		}
	}
	
	//return false and end the function if the user has not guessed a
	//letter in the secret word
	return false;
}



bool fillOutputArray(char guess, const char *secretWord, char *outputArray)
{
	//placeholder variable to indicate the output array was changed
	int isChanged = 0;
	
	//iterate through the size of the secret word
	for (int i = 0; i < strlen(secretWord); i++)
	{
		//if the user guessed a letter in the secret word, this block will
		//run
		if (guess == secretWord[i])
		{
			//this block will run if the guess is unique
			if (outputArray[i] != guess)
			{
				//set the corresponding index of the output array equal to
				//that of the guess, matching the secret word.
				outputArray[i] = guess;
			
			
				//record the fact that the output has changed
				isChanged = 1;
			}
		}
	}
	
	//check if the user has changed the output array by guessing correctly
	if (isChanged == 1)
	{
		//if so, all changes have been recorded, so end function and
		//return true
		return true;
	}
	
	//the user has not changed the output, so return false
	return false;
}



bool fillAttemptsArray(char guess, char *attempts)
{
	//iterate through the allotted attempts (array)
	for (int i = 0; i < (ATTEMPTS + 1); i++)
	{
		//this block will run if the user has already guessed this
		if (guess == attempts[i])
		{
			//the user has made a repeated guess, so return false
			return false;
		}
		//this block will run if the user has not made a repeated guess
		else if ('*' == attempts[i])
		{
			//record this guess in the next free index in attempts[]
			attempts[i] = guess;
			
			//the user has made a repeated guess, so return true.
			return true;
		}
	}
	
	//safe return in case the for loop somehow exits without
	//fulfilling the conditions
	return true;
}



bool checkVictory(int size, char *outputArray)
{
	//iterate through the size of the secret word
	for (int i = 0; i < size; i++)
	{
		//check if there are any unguessed spaces left, indicated by an
		//underscore
		if ('_' == outputArray[i])
		{
			//if so, the user has not won yet; return false
			return false;
		}
	}
	
	//if no underscores have been found, the user has won; return true
	return true;
}



bool checkDefeat(char *attempts)
{
	//iterate through the allotted attempts
	for (int i = 0; i < (ATTEMPTS + 1); i++)
	{
		//if there is at least one asterik left, the user has not yet
		//used all of their allotted mistakes, and they are still in
		//the game
		if ('*' == attempts[i])
		{
			//return false because the user has not yet been defeated
			return false;
		}
	}
	
	//if no asteriks have been found, the user has used all of their
	//attempts; return true
	return true;
}



bool play(bool *giveup)
{
	//initialize variables
		//integer size indicating the size of the secret word
	int size;
		//initialize the single character value for guesses
	char guess;
		//initialize the secret word, with a char length of the max length
		//of the word it can be given from the pool of words in FRUITS[]
	char secretWord[MAX_FRUIT_SIZE];
		//initialize the attempts array, which will track the user's
		//incorrect guesses
	char attempts[ATTEMPTS + 1];
		//initialize the output array, which will track the user's
		//correct guesses
	char outputArray[MAX_FRUIT_SIZE];
		//initialize the guessRaw array, which will store the raw data
		//for the user's guess to be truncated
	char guessRaw[16];

	//initialize random number generator
		//function: initializeRandom
	initializeRandom();
	
	//obtain a secret word and its size
		//function: getSecretWord
	size = getSecretWord(secretWord);
	
	//obtain the output array
		//function: buildOutputArray
	buildOutputArray(size, outputArray);
	
	//obtain the attempts array
		//function: buildAttemptArray
	buildAttemptArray(attempts);
	

	//prompt user input
		//function: puts
	puts("Which letter? (0 to exit the game): ");
	
	//read user input
		//function: scanf
	scanf("%s", guessRaw);
	
	//transfer the single character in the array to the guess variable
	//in lowercase
	guess = tolower(guessRaw[0]);

	//iterate through the game while the user hasn't given up (indicating 0)
	while(guess != '0')
	{
	
		//check if the guess is correct
		if (checkGuess(guess, secretWord))
		{
			//if so, check if this guess is new
			if(fillOutputArray(guess, secretWord, outputArray))
			{
				//if so, print the correct guesses (outputArray)
					//function: puts
				puts(outputArray);
			}
		
			//if the guess is correct but the user has made a repeated guess,
			//run this block
			else
			{
				//tell the user they made a repeated guess
					//function: puts
				puts("Repeated guess. Try another letter!\n");
			}
		
			//check if the user has won the game
			if(checkVictory(size, outputArray))
			{
				//if so, the user hasn't given up; set giveup to false
				*giveup = false;
				
				//return true, indicating the player has won
				return true;
			}
		}
	
		//if guess is incorrect
		else
		{
			//print a message indicating the user has made a mistake
				//function: puts
			puts("The letter doesn't exist in the word.");
		
			//check if the guess has been made already
			if(fillAttemptsArray(guess, attempts))
			{
				//if the player is incorrect and this guess is new, tell them
					//functions: fputs, puts
				fputs("Mistakes: ", stdout);
				puts(attempts);
			}
		
			//if the guess is repeated, this block will run
			else
			{
				//tell the user they made a repeated guess
					//function: puts
				puts("Repeated guess. Try another letter!\n");
			}
			if(checkDefeat(attempts))
			{
				//tell the user they have lost
					//functions: fputs, puts
				fputs("The secret word was: ", stdout);
				puts(secretWord);
			
				//set giveup equal to false, because the player never gave up
				*giveup = false;
			
				//return false, indicating the player has lost.
				return false;
			}
		}
	
		//prompt user input
			//function: puts
		puts("\nWhich letter? (0 to exit the game): ");
	
		//read user input
			//function: scanf
		scanf("%s", guessRaw);
	
		//transfer the single character in the array to the guess variable
		//in lowercase
		guess = tolower(guessRaw[0]);
	}
	
	//this will run if the user has exited the while loop, which means
	//they've given up
	
	//set giveup equal to true
	*giveup = true;
	
	//return false, indicating the player has lost
	return false;
	
}








