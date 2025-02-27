#include <print>

using std::println;

int main()
{
    float myFloat{3.14f};
    int   i1{(int)myFloat};            // C-style (seen often in the wild)
    println("{}", i1);

    int i2{int(myFloat)};              // seldom seen
    println("{}", i2);

    int i3{static_cast<int>(myFloat)}; // preferred c++-style
    println("{}", i3);

    short someShort{16};
    long  someLong{someShort};         // no explicit cast needed
    println("{}", someLong);
}
