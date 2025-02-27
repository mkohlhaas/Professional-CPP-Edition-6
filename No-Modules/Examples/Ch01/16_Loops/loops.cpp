#include <array>
#include <print>

using namespace std;

int main()
{
    {
        // The while loop
        int i{0};
        while (i < 5)
        {
            println("This is a while loop: {}", i);
            ++i;
        }
    }

    println();

    {
        // The do/while loop
        int i{100};
        do
        {
            println("This is a do-while loop: {}", i);
            ++i;
        } while (i < 5);
    }

    println();

    {
        // The for loop
        for (int i{0}; i < 5; ++i)
        {
            println("This is a for-loop: {}", i);
        }
    }

    println();

    {
        // The range-based for loop
        array arr{1, 2, 3, 4};
        for (int i : arr)
        {
            println("This is a range-based for-loop: {}", i);
        }
    }

    println();

    {
        // The range-based for loop with initializer
        for (array arr{1, 2, 3, 4}; int i : arr)
        {
            println("This is a range-based for-loop with initializer: {}", i);
        }
    }
}
