#include <memory>
#include <print>

using namespace std;

class Foo
{
  public:
    Foo(int value) : m_data{value}
    {
    }
    int m_data;
};

int main()
{
    auto foo{make_shared<Foo>(42)};
    println("{}", foo->m_data);
    auto aliasing{shared_ptr<int>{foo, &foo->m_data}};
    // println("{}", aliasing->m_data);
}
