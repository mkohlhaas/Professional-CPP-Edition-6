#include "Grid.h"
#include "SpreadsheetCell.h"
#include <memory>
#include <string>
#include <vector>

using namespace std;

void processIntGrid(Grid<int> &grid [[maybe_unused]])
{
    // body omitted for brevity
    // ...
}

int main()
{
    Grid<int>    myIntGrid;            // Declares a grid that stores ints, using default arguments for the constructor.
    Grid<double> myDoubleGrid{11, 11}; // Declares an 11x11 Grid of doubles.

    myIntGrid.at(0, 0) = 10;
    int x [[maybe_unused]]{myIntGrid.at(0, 0).value_or(0)};

    Grid<int> grid2{myIntGrid}; // Copy constructor
    Grid<int> anotherIntGrid;
    anotherIntGrid = grid2;     // Assignment operator

    // Grid test;   // WILL NOT COMPILE
    // Grid<> test; // WILL NOT COMPILE

    processIntGrid(myIntGrid);

    Grid<SpreadsheetCell> mySpreadsheet;
    SpreadsheetCell       myCell{1.234};
    mySpreadsheet.at(3, 4) = myCell;

    Grid<const char *> myStringGrid;
    myStringGrid.at(2, 2) = "hello";

    Grid<vector<int>> gridOfVectors;
    vector<int>       myVector{1, 2, 3, 4};
    gridOfVectors.at(5, 6) = myVector;

    auto myGridOnFreeStore{make_unique<Grid<int>>(2, 2)}; // 2x2 Grid on the free store.
    myGridOnFreeStore->at(0, 0) = 10;
    int x2 [[maybe_unused]]{myGridOnFreeStore->at(0, 0).value_or(0)};

    // grid of grid
    Grid<Grid<int>> gridOfGridInts;
    Grid<int>       gridInt;
    gridOfGridInts.at(0, 0) = gridInt;
}

// Explicit class template instantiation.
//
// Explicit template instantiations help with finding errors, as they force all your class template member functions to
// be compiled even when unused.
template class Grid<string>;
