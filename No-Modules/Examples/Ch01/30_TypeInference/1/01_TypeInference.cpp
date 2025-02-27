#include <string>
#include <utility>

using namespace std;

const string  message{"Test"};
const string &foo()
{
    return message;
}

int main()
{
    // x is of type int
    auto x [[maybe_unused]]{123};

    // f1 is of type string
    auto f1 [[maybe_unused]]{foo()};

    // f2 is of type const string&
    const auto &f2 [[maybe_unused]]{foo()};

    string str{"C++"};
    // result is of type string!
    auto result{as_const(str)};

    int i{123};
    // p is of type int*
    // auto *p [[maybe_unused]]{&i};
    // p is of type int*
    auto p [[maybe_unused]]{&i};

    // int* const
    const auto p1 [[maybe_unused]]{&i};
    // int* const
    auto const p2 [[maybe_unused]]{&i};
    // const int*
    const auto *p3 [[maybe_unused]]{&i};
    // int* const
    auto *const p4 [[maybe_unused]]{&i};
    // const int* const
    const auto *const p5 [[maybe_unused]]{&i};
}
