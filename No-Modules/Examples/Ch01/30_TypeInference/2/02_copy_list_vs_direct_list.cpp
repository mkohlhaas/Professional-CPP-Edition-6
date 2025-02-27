#include <initializer_list>

int main()
{
    // Copy list initialization
    auto a [[maybe_unused]] = {11};     // initializer_list<int>
    auto b [[maybe_unused]] = {11, 22}; // initializer_list<int>

    // Direct list initialization
    auto c [[maybe_unused]]{11};
    // auto d{ 11, 22 };       // Error, too many elements.
}
