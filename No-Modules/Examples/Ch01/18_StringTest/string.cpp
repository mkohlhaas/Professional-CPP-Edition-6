#include <print>
#include <string>

using namespace std;

int main()
{
    string myString{"Hello, World"};
    println("The value of myString: {}", myString);
    println("The second letter: {}", myString[1]);
}
