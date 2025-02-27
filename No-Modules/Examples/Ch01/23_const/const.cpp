#include <print>
#include <string>

using std::string, std::println;

const int    versionNumberMajor [[maybe_unused]]{2};
const int    versionNumberMinor [[maybe_unused]]{1};
const string productName{"Super Hyper Net Modulator"};
const double PI [[maybe_unused]]{3.141592653589793238462};

void func(const int /* param */)
{
    // Not allowed to change param...
}

void constIntOne()
{
    const int *ip [[maybe_unused]];
    ip = new int[10];
    //  ip[4] = 5; // DOES NOT COMPILE!
}

void constIntTwo()
{
    int const *ip [[maybe_unused]];
    ip = new int[10];
    //  ip[4] = 5; // DOES NOT COMPILE!
}

void constPtrOne()
{
    int *const ip{nullptr};
    // ip = new int[10]; // DOES NOT COMPILE!
    ip[4] = 5; // Error: dereferencing a null pointer
}

void constPtrTwo()
{
    int *const ip{new int[10]};
    ip[4] = 5;
}

void constIntPtrOne()
{
    int const *const ip [[maybe_unused]]{nullptr};
}

void constIntPtrTwo()
{
    const int *const ip [[maybe_unused]]{nullptr};
}
// the same (more idiomatic):
void constIntPtrThr()
{
    int const *const ip [[maybe_unused]]{nullptr};
}

void manyLevelConst()
{
    const int *const *const *const ip [[maybe_unused]]{nullptr};
}

int main()
{
    int *ip;
    ip    = new int[10];
    ip[4] = 5;
    println("{}", ip[4]);
}
