#include "Spreadsheet.h"

void printSpreadsheet(Spreadsheet s [[maybe_unused]])
{
    // code omitted for brevity
}

int main()
{
    {
        Spreadsheet s1{4, 3};
        printSpreadsheet(s1);
    }

    {
        Spreadsheet s1{2, 2}, s2{4, 3};
        s1 = s2;
    }

    SpreadsheetCell cell{2.2};
}
