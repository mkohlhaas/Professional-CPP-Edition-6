#include <print>

using std::println;

void addOneA(int i [[maybe_unused]])
{
    i++; // Has no real effect because this is a copy of the original
}

void addOneB(int &i)
{
    i++; // Actually changes the original variable
}

void swap(int &first, int &second)
{
    int temp{first};
    first  = second;
    second = temp;
}

int main()
{
    int myInt{7};
    addOneA(myInt);
    addOneB(myInt);

    int x{5}, y{6};
    println("{}", x);
    println("{}", y);

    println("=========================");

    swap(x, y);
    println("{}", x);
    println("{}", y);

    //  swap(3, 4); // DOES NOT COMPILE

    println("=========================");

    int *xp{&x}, *yp{&y};
    swap(*xp, *yp);
    println("{}", x);
    println("{}", y);
}
