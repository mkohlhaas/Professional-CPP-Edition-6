#include <print>

using namespace std;

class Demo
{
  public:
    int get()
    {
        return 5;
    }
};

int get()
{
    return 10;
}

namespace NS
{
int get()
{
    return 20;
}
} // namespace NS

int main()
{
    Demo d;
    println("class:            {}", d.get());   // 5
    println("namespace:        {}", NS::get()); // 20
    println("global namespace: {}", ::get());   // 10
    println("global namespace: {}", get());     // 10
}
