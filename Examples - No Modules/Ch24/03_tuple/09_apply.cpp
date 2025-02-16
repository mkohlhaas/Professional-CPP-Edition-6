#include <functional>
#include <print>
#include <tuple>

using namespace std;

int
add (int a, int b)
{
  return a + b;
}

int
main ()
{
  println ("{}", apply (add, tuple{ 39, 3 }));
}