// include guards
#ifndef TABLEDESIGN_H
#define TABLEDESIGN_H

// header files
#include <stdio.h>

// global constants
	//Character used for column separator.
#define COL_SEPARATOR '|'

	// Character used for row separator.
#define ROW_SEPARATOR '-'

/**
* Name: printTableHeader
* Process: prints a header line for a table where each column's length
*           can vary.
* Input parameters:   columnLengths - an integer number representing
                        the lengths of each column.
                    numColumns - the number of columns in the table.
* Output parameters:  none
* Output returned: none
* Dependencies: stdio.h
**/
void printTableHeader(int numColumns, int columnLength);


/**
* Name: printTableLine
* Process: Prints a line separator for the table.
* Input parameters: columnLengths - an integer number representing
                        the lengths of each column.
                    numColumns - the number of columns in the table.
* Output parameters:  none
* Output returned: none
* Dependencies: stdio.h
**/
void printTableLine(int numColumns, int columnLength);


/**
* Name: printTableRow
* Process: Prints a row of data for the table.
* Input parameters: columnLengths - an integer number representing
                        the lengths of each column.
                    numColumns - the number of columns in the table.
                    rowData - array of strings containing data for
                    	each column.
* Output parameters:  none
* Output returned: none
* Dependencies: stdio.h
**/
void printTableRow(int numColumns, int columnLength, const char *rowData[]);

#endif // TABLEDESIGN_H
