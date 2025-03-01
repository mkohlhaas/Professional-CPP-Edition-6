#include <fstream>
#include <iostream>
#include <iterator>
#include <print>

using namespace std;

int main()
{
    ifstream inputFile{"some_data.txt"};
    if (inputFile.fail())
    {
        println(cerr, "Unable to open file for reading.");
        return 1;
    }
    string fileContents{istreambuf_iterator<char>{inputFile}, istreambuf_iterator<char>{}};
    println("{}", fileContents);
}
