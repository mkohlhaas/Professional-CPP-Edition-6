#include "Grid.h"
#include <print>

using namespace std;

constexpr size_t getHeight()
{
    return 10;
}

int main()
{
    // NOTE:
    // Grid<int, 10, 10> and Grid<int, 10, 11> are different types!

    Grid<int, 10, 10> myGrid;
    Grid<int, 10, 10> anotherGrid;
    myGrid.at(2, 3) = 42;
    anotherGrid     = myGrid;                        // assignment possible bc same type
    println("{}", anotherGrid.at(2, 3).value_or(0)); // 42

    const size_t          height{10};
    Grid<int, 10, height> testGrid;                  // compiles bc height is const

    Grid<double, 2, getHeight()> myDoubleGrid;       // compiles bc getHeight is constexpr
}
