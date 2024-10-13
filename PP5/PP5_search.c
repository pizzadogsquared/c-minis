//code by Elijah Sprouse

//header files
#include "search_lib.h"

//main program
int main()
{
    // initialize program
        // initialize the random number generator
            // function: initializePlayer
	initializeRandom();
		//initialize variables
			//array list[] of ints, LENGTH indices long
	dtype list[LENGTH];
			//set int element equal to placeholder value within range
	dtype element = RANGE_MAX;
			//initialize int occurrence value, which will be used as a
			//placeholder for occurrence functions later
	dtype occurrence;
			//array occurrences[] of ints, LENGTH indices long
	dtype occurrences[LENGTH];
	// declare the variable to store the user's choice		
    char choice = 'y';

	// this block will run while the the user's choice is yes and the
	//element is not the escape value
	while ((choice == 'y') && (element != EMPTY_VALUE))
	{
		// initialize the list with empty values
			//function: initializeList
		initializeList(list, LENGTH, EMPTY_VALUE);
		// initialize the list with random values
			//function: initializeRandomList	
		initializeRandomList(list, LENGTH, RANGE_MIN, RANGE_MAX);

		// initialize occurrences list with empty values
			//function: initializeList
		initializeList(occurrences, LENGTH, EMPTY_VALUE);
			
			
		//set iteration value i equal to 0
		dtype count = 0;

		// this block will run while the the user's choice is yes, the
		//element is not the escape value, and the iterable value is within
		//the range of the array's elements.
		while ((count <= RANGE_MAX - RANGE_MIN) && (choice == 'y')
			&& (element != EMPTY_VALUE))
		{

			
			//get user input
				//prompt user for input
					//function: printf
			printf("\nEnter a number to search in the range [1-3], "
				"inclusive (0 to exit): ");
			//scan for user input
				//function: getNumberRange	
			element = getNumberRange(RANGE_MIN, RANGE_MAX);
			
			if (element != EMPTY_VALUE)
			{
			
			//print message to user
				//function: printf
			printf("\nSearching for %d:\n", element);
			
			// get first occurrence and place in occurrence value
				//function: getFirstOccurrence
			occurrence = getFirstOccurrence(element, list);
			
			// this block will run if the element doesn't occur in the list
			if (occurrence == NOT_FOUND)
			{
				//print a message to the user telling them that the value
				//doesn't occur
					//function: printf
				printf("\nValue not found!\n");
				
				//get user input
					//prompt user for input
						//function: printf		
				printf("\n\nDo you want to search for another value [y|n]? ");
				//scan for user input
					//function: getChoiceYN			
				choice = getChoiceYN();
			}
			
			//this block will run if the element has been found at least once
			else
			{
				//print a message to the user telling the first occurrence
					//function: printf
				printf("First Occurrence: " SPECIFIER "\n", occurrence);
				
				// get last occurrence and place in occurrence value
					//function: getLastOccurrence
				occurrence = getLastOccurrence(element, list);
				//print a message to the user telling the last occurrence
					//function: printf
				printf("Last Occurrence: " SPECIFIER "\n", occurrence);
				
				// set the occurrence value equal to the output of function
					//function: getAllOccurrences
				occurrence = getAllOccurrences(element, list, occurrences);
				
				// begin message to the user telling them all occurrences
					//function: printf
				printf("All Occurrences: ");
				// finish message to the user telling them all occurrences
					//function: printContiguousList
				printContiguousList(occurrences, occurrence);
				
				//print a message telling the user total occurrences
					//function: printf
				printf("Total Occurrences: " SPECIFIER "\n", occurrence);
				
				//get user input
					//prompt user for input
						//function: printf		
				printf("\nDo you want to search for another value [y|n]? ");
				//scan for user input
					//function: getChoiceYN			
				choice = getChoiceYN();
			}
			// increment count variable
			count++;
			}
		}
		
		
		if (count > RANGE_MAX - RANGE_MIN)
		{
			//print a message to the user telling them they have already searched all values
			printf("\nYou have already searched for all "
				"possible values in the list.\n");
			//get user input
				//prompt user for input
					//function: printf	
			printf("Do you want to generate new values for the list [y|n]? ");
			//scan for user input
				//function: getChoiceYN			
			choice = getChoiceYN();
			if (choice == 'n')
			{
				// print a message
					// function: printf
				printf("\nThanks for searching. Come back if needed!\n");
			}
		}
	}


    // End program
        // print a message
            // function: printf
	printf("Program ended.");
        // return success
    return 0;
}