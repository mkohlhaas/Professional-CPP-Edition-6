#include <print>
#include <string_view>

#include "SpreadsheetCell.h"

using namespace std;

int main()
{
    SpreadsheetCell myCell{4};
    myCell = 5;
    myCell = "6"sv;

    println("Cell: {}", myCell.getValue());
}
