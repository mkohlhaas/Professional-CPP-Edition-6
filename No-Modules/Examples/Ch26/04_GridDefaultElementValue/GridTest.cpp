#include "Grid.h"
#include "SpreadsheetCell.h"

int main()
{
    Grid<int>     myIntGrid;  // Initial value is int{}, i.e., 0
    Grid<int, 10> myIntGrid2; // Initial value is 10

    myIntGrid.at(1, 2) = 3;

    SpreadsheetCell defaultCell;
    // Grid<SpreadsheetCell, defaultCell> mySpreadsheet; // WILL NOT COMPILE
}
