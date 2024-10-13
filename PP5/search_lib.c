//code by Elijah Sprouse

//header files
#include "search_lib.h"

void initializeRandom()
{
    // initalize random number generator
        // functions: srand, time
    srand(time(NULL));
	
}




void initializeList(dtype *list, int length, dtype value)
{
	//iterate foward through the length of the list
	for (int i = 0; i < length; i++)
	{
		list[i] = value;
	}
}




void initializeRandomList(dtype *list, int length, int min, int max)
{
	//iterate foward through the length of the list
	for (int i = 0; i < length; i++)
	{
		// generate the random number and constraint within range (1-6)
			// function: rand
		list[i] = (rand() % max) + min;

	}
}




bool isFullList(const dtype *list, int length, dtype empty_value)
{
	//iterate foward through the length of the list
	for (int i = 0; i < length; i++)
	{
		// check if the element has an empty value in it
		if (list[i] == EMPTY_VALUE)
		{
			// if so, it is not a full list. return false and end function
			return false;
		}
	}
	// if not, the function is full. return true and end function
	return true;
}




char getChoiceYN()
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
		printf("Invalid option. Please type 'y' to play or 'n' to exit:");
		
		//read user input
			//function: scanf
		scanf("%s", choice);
	
		//transfer the single character array to the letterChoice variable
		//in lowercase
		letterChoice = tolower(choice[0]);
	}
	return letterChoice;
}



int getNumberRange(dtype min, dtype max)
{
	//store the number choice as element
	int element;
	
	//read user input
		//function: scanf
	scanf(SPECIFIER, &element);
	
	//if the user hasn't given a valid choice that can be read, this while
	//loop will execute until they do.
	while ((element != 0) && ((min > element) || (max < element)))
	{
		//instruct the user on possible options
			//function: printf
		printf("Invalid option. Please enter a value within the range 1-3 (or 0 to exit): ");
		
		//read user input
			//function: scanf
		scanf(SPECIFIER, &element);
	}
	return element;
}



int getFirstOccurrence(dtype element, const dtype *myList)
{
	//iterate foward through the length of the list
	for (int i = 0; i < LENGTH; i++)
	{
		//check if the element in the index is equal to the value being
		//checked for
		if(myList[i] == element)
		{
			// if so, return the index + 1, from [1, LENGTH]
			return i + 1;
		}
	}
	// return the not found value if the element didn't occur
	return NOT_FOUND;
}



int getLastOccurrence(dtype element, const dtype *myList)
{
	//iterate backwards through the length of the list
	for (int i = LENGTH - 1; i >= 0; i--)
	{
		//check if the element in the index is equal to the value being
		//checked for
		if(myList[i] == element)
		{
			// if so, return the index + 1, from [1, LENGTH]
			return i + 1;
		}
	}
	// return the not found value if the element didn't occur
	return NOT_FOUND;
}



int getAllOccurrences(dtype element, const dtype *myList, dtype *occurrences)
{
	//define count variable to count how many times an element occurs
	int count = 0;
	//iterate foward through the length of the list
	for (int i = 0; i < LENGTH; i++)
	{
		//check if the element in the index is equal to the value being
		//checked for
		if(myList[i] == element)
		{
			//if so, set the next index of occurrences equal to the index + 1
			//from [1, LENGTH]
			occurrences[count] = i + 1;
			//increment count
			count++;
		}
	}
	
	// after for loop, check if the first value is empty
	if(occurrences[EMPTY_VALUE] == EMPTY_VALUE)
	{
		// return the not found value if the element didn't occur
		return NOT_FOUND;
	}
	// otherwise, the occurrences array includes an occurrence
	else
	{
		// return the count of how many occurrences there are in the array
		return count;
	}
}



void printContiguousList(const dtype *mylist, int length)
{
	//iterate foward through the length of the list
	for (int i = 0; i < length; i++)
	{
		// this block will run on every iteration of the for loop other
		//than the last one
		if (i != length - 1)
		{
			// print the element of the list with a comma
			printf(SPECIFIER ", ", mylist[i]);
		}
		// this block will only run on the last iteration of the for loop
		else
		{
			// print the lement of the list without a comma
			printf(SPECIFIER "\n", mylist[i]);
		}
	}
}



