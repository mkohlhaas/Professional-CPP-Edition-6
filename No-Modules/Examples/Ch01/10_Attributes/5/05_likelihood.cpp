#include <print>

using std::println;

int main()
{
    int value{1};
    if (value > 11) [[unlikely]]
    {
        println("if: unlikely");
    }
    else
    {
        println("if: likely");
    }

    switch (value)
    {
    [[likely]] case 1:
        println("switch: likely");
        break;
    case 2:
        println("switch: whatever");
        break;
    [[unlikely]] case 12:
        println("switch: unlikely");
        break;
    }
}
