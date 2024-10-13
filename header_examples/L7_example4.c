// header files
#include "tabledesign.h"

// main program
int main()
{
    // initialize program
        // define the number of columns and column length for the table
    int numColumns = 3;
    int columnLength = 12;
        // Define an array of row data
        // this is an array of strings, NO NEED TO UNDERSTAND THIS NOW!
    const char *rowData[] = {"Data 1", "Data 2", "Data 3"};

    // output
        // Print the table header
    printTableHeader(numColumns, columnLength);

        // Print a table line
    printTableLine(numColumns, columnLength);

        // Print a table row
    printTableRow(numColumns, columnLength, rowData);

    // end program
        // return success
    return 0;
}
