#include <print>

using std::println;

int main()
{
    enum class Mode
    {
        Default,
        Custom,
        Standard
    };

    int  value{42};
    Mode mode{Mode::Standard};

    switch (mode)
    {
        using enum Mode;

    case Custom:
        value = 84;
        [[fallthrough]];
    case Standard:
    case Default:
        value = 21;
        println("value: {}", value);
        break;
    }
    println("value: {}", value);
}
