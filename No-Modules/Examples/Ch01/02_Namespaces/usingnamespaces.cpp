#include <print>

using std::println;

namespace mycode::nssub1::nssub2
{
void foo()
{
    println("foo() called in the mycode::nssub1::nssub2 namespace.");
}
} // namespace mycode::nssub1::nssub2

namespace subns = mycode::nssub1::nssub2;

namespace mycode
{
void foo()
{
    println("foo() called in the mycode namespace.");
}
} // namespace mycode

using namespace mycode;

// using namespace subns;

int main()
{
    mycode::foo();
    foo();
    mycode::nssub1::nssub2::foo();
    subns::foo();
}
