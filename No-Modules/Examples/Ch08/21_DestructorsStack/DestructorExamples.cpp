#include "SpreadsheetCell.h"
#include <print>

using namespace std;

int main()
{
    SpreadsheetCell myCell{1};

    if (myCell.getValue() == 1)
    {
        SpreadsheetCell anotherCell{2};
        println("1");
    } // anotherCell is destroyed as this block ends

    println("myCell: {}", myCell.getValue());

    {
        SpreadsheetCell myCell2{3};
        SpreadsheetCell anotherCell2{4}; // myCell2 constructed before anotherCell2
        println("2");
    } // anotherCell2 destroyed before myCell2
    println("3");
} // myCell is destroyed as this block ends
