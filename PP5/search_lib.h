// inclusion guards
#ifndef SEARCH_LIB
#define SEARCH_LIB

// header files
#include <stdio.h>
#include <stdlib.h> // for rand, srand
#include <time.h> // for time
#include <ctype.h> // for tolower
#include <stdbool.h> // for bool data type

// global constants
// the lenght of the list
#define LENGTH 10
// value that represents when the value is not found
#define NOT_FOUND -1
// the format specifier for values in the list
#define SPECIFIER "%d"
// maximum value that the list can contain
#define RANGE_MAX 3
// minimum value that the list can contain
#define RANGE_MIN 1
// value that represents an empty position in the list
#define EMPTY_VALUE 0

// data type definition
typedef int dtype;
 
// function prototypes
/**
 * Name: initializeRandom
 * Process: initialize the random number generator
 * Function input/parameters: none
 * Function output/parameters: none
 * Function output/returned: none
 * Dependencies: stdlib.h - srand
 *               time.h - time
 **/
void initializeRandom();
/**
 * Name: initializeList
 * Process: initialize a list of a given length with a given value
 * Function input/parameters: length - the length of the list
 *                            value - the value to initialize the list with
 * Function output/parameters: list - a pointer to an array where the values
 *                             will be added
 * Function output/returned: none
 * Dependencies: none
 **/
void initializeList(dtype *list, int length, dtype value);
/**
 * Name: initializeRandomList
 * Process: initialize a list of a given length with random values within a 
 *          given range (inclusive)
 * Function input/parameters: length - the length of the list
 *                            min - the smallest value that list can contain
 *                            max - the largest value that list can contain
 * Function output/parameters: list - a pointer to an array where the values
 *                             will be added
 * Function output/returned: none
 * Dependencies: stdlib.h - rand
 **/
void initializeRandomList(dtype *list, int length, int min, int max);
/**
 * Name: isFullList
 * Process: check if the list is completely full by looking for the character
 *          that represent an empty value. The function returns false if the 
 *          empty value is found; otherwise, it returns true.
 * Function input/parameters: length - the length of the list
 *          empty_value - the value to search in the list as the empty position
 *          list - a pointer to an array to be checked
 * Function output/parameters: none
 * Function output/returned: true, if the list is full (empty value not found);
 *                           false, otherwise
 * Dependencies: none
 **/
bool isFullList(const dtype *list, int length, dtype empty_value);
/**
 * Name: getChoice
 * Process: reads and validates a lowercase character input, ensuring it is
 *          either 'y' or 'n'
 * Function input/parameters: none
 * Function output/parameters: none
 * Function output/returned: the read char value (either 'n' or 'y')
 * Dependencies: stdio.h - scanf, printf
 *               ctype.h - tolower
 **/
char getChoiceYN();
/**
 * Name: getNumberRange
 * Process: reads and validates an integer number, ensuring it is within the
 *          specified range, inclusive
 * Function input/parameters: min - smallest value that the number can be
 *                            max - greatest value that the number can be
 * Function output/parameters: none
 * Function output/returned: the read int value (within the range, inclusive)
 * Dependencies: stdio.h - scanf, printf
 **/
int getNumberRange(dtype min, dtype max);
/**
 * Name: getFirstOccurrence
 * Process: returns the position of the first occurrence of a given element
 *          in the given list
 * Function input/parameters: element - the element to be found in the list
 *          myList - the list where the element is searched for
 * Function output/parameters: none
 * Function output/returned: the index of the first ocurrence or NOT_FOUND if
 *          the value is not in the list
 * Dependencies: none
 **/
int getFirstOccurrence(dtype element, const dtype *myList);
/**
 * Name: getLastOccurrence
 * Process: returns the position of the last occurrence of a given element
 *          in the given list
 * Function input/parameters: element - the element to be found in the list
 *          myList - the list where the element is searched for
 * Function output/parameters: none
 * Function output/returned: the index of the last ocurrence or NOT_FOUND if
 *          the value is not in the list
 * Dependencies: none
 **/
int getLastOccurrence(dtype element, const dtype *myList);
/**
 * Name: getAllOccurrences
 * Process: fills in an output parameter (occurrences) with all the positions
 *          where a given element is found in a given list. 
 * Function input/parameters: element - the element to be found in the list
 *          myList - the list where the element is searched for
 * Function output/parameters: occurrences - the list where the positions of
 *          the occurrences are stored
 * Function output/returned: the number of occurrences found in the list or
 *          NOT_FOUND if none.
 * Dependencies: none
 **/
int getAllOccurrences(dtype element, const dtype *myList, dtype *occurrences);
/**
 * Name: printContiguousList
 * Process: prints all the elements of a given contiguous list in a single line,
 *          separated by comma 
 * Function input/parameters: myList - the list to be printed
 *                            length - the length of the list
 * Function output/parameters: none
 * Function output/returned: none
 * Dependencies: stdio.h - printf
 **/
void printContiguousList(const dtype *mylist, int length);

// end SEARCH_LIB
#endif