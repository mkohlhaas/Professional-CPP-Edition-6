#include <optional>
#include <print>

using namespace std;

optional<int> getData(bool giveIt)
{
    if (giveIt)
    {
        return 42;
    }

    return nullopt; // or simply return {};
}

int main()
{
    // optional<int> data1{ getData (true) };
    // optional<int> data2{ getData (false) };
    optional data0{42};
    optional data1{getData(true)};
    optional data2{getData(false)};

    println("data3.has_value = {}", data0.has_value());
    println("data3.value = {}", data0.value());
    println("data3.value = {}", *data0);

    println("data1.has_value = {}", data1.has_value());
    if (!data2)
    {
        println("data2 has no value.");
    }

    println("data1.value = {}", data1.value());
    println("data1.value = {}", *data1);

    try
    {
        println("data2.value = {}", data2.value());
    }
    catch (const bad_optional_access &ex)
    {
        println("Exception: {}", ex.what());
    }

    println("data2.value = {}", data2.value_or(0));
}
