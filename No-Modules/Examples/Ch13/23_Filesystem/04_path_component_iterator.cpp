#include <filesystem>
#include <print>

using namespace std;
using namespace std::filesystem;

int main()
{
    path p{R"(C:\Foo\Bar)"};
    for (const auto &component : p)
    {
        println("{}", component.string());
    }
}
