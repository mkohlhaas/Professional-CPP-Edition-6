#include <string>
#include <utility>

using namespace std;

int main()
{
    string        str{"C++"};
    const string &constStr [[maybe_unused]]{as_const(str)};
    // auto constStr [[maybe_unused]]{as_const(str)};
}
