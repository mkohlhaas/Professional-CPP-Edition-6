#include <print>

using std::println;

int main()
{
    println("{}", 123);       // decimal
    println("{}", 0x7b);      // hexadecimal
    println("{}", 0173);      // octal
    println("{}", 0b1111011); // binary

    // Doesn't work with the language server
    // println ("{}", 23'456'789);
    // println ("{}", 0.123456f);

    std::println("Hello, World!");
    std::println("Hello, "
                 "World!");
}
