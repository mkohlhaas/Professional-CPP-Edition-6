#include <print>
#include <ranges>
#include <string_view>
#include <vector>

using namespace std;

void printRange(string_view message, auto &&range)
{
    println("{}{:n}", message, range);
}

int main()
{
    vector values{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printRange("Original sequence: ", values);

    auto result{values | views::filter([](const auto &value) { return value % 2 == 0; }) |
                views::transform([](const auto &value) { return value * 2.0; }) | views::drop(2) | views::reverse};
    printRange("Final sequence: ", result);
}
