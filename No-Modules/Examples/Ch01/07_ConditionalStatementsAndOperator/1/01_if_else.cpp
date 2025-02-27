#include <print>

using std::println;

int main()
{
    int i{3};

    if (i > 4)
    {
        println("Greater than 4.");
    }
    else if (i > 2)
    {
        println("Greater than 2.");
    }
    else
    {
        println("Whatever.");
    }
}
