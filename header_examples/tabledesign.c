// tabledesig.c
#include "tabledesign.h"   // note the "" instead of <>

void printTableHeader(int numColumns, int columnLength)
{
    // processing
        // for each column
    for (int i = 0; i < numColumns; i++)
    {
        // print a column separator
            // function: printf
        printf("%c", COL_SEPARATOR);
        // for each character in the length
        for (int j = 0; j < columnLength; j++)
        {
            // print a row separator
                // function: printf
            printf("%c", ROW_SEPARATOR);
        }
    }
        // closes with a column separator and breaks a line
            // function: printf
    printf("%c\n", COL_SEPARATOR);
}

void printTableLine(int numColumns, int columnLength)
{
    // initialize function
        // calculate the number of row separators
    int totallength = numColumns * columnLength + (numColumns-1);
    
    // processing
        // print a column separator
            // function: printf
    printf("%c", COL_SEPARATOR);
        
        // for each column
    for (int i = 0; i < totallength; i++)
    {
        // print a row separator
            // function: printf
        printf("%c", ROW_SEPARATOR);
    }
        // closes with a column separator and breaks a line
            // function: printf
    printf("%c\n", COL_SEPARATOR);
}

void printTableRow(int numColumns, int columnLength, const char *rowData[])
{
    // processing
        // print a column separator
            // function: printf
    printf("%c", COL_SEPARATOR);
        // for each column
    for (int i = 0; i < numColumns; i++)
    {
        // print the data for the column and a column separator
            // function: printf
        printf("%-*s%c", columnLength, rowData[i], COL_SEPARATOR);
    }
        // break a line
            // function: printf
    printf("\n");
}
