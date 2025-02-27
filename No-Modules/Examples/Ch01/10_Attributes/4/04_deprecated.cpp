#include <print>

[[deprecated("Unsafe function, please use xyz")]]
void func()
{
    std::println("I am deprecated!");
}

void xyz()
{
    std::println("I am up-to-date!");
}

int main()
{
    func();
}
