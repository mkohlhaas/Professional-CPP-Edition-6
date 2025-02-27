#include <print>

using std::println;

int main()
{
    int i{3};
    println("{}", (i > 2) ? "yes" : "no");
    println("{}", i > 2 ? "yes" : "no");
}
