#include <filesystem>
#include <print>

using namespace std;
using namespace std::filesystem;

int main()
{
    path p{"D:\\Foo"};
    p.append("Bar");
    p /= "Bar";
    println("{}", p.string());
}
