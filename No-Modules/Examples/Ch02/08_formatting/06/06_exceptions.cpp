#include <format>
#include <iostream>
#include <print>

using namespace std;

int main()
{
    try
    {
        int number{42};
        vprint_unicode(cout, "An integer: {5}", make_format_args(number));
    }
    catch (const format_error &ex)
    {
        println("{}", ex.what());
    }
}
