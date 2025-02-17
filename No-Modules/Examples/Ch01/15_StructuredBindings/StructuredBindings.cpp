#include <array>
#include <print>
#include <utility>

using namespace std;

int
main ()
{
  {
    // Structured bindings with std::array.
    array values{ 11, 22, 33 };
    auto [x, y, z]{ values };
    println ("{}", x);
    println ("{}", y);
    println ("{}", z);
  }

  {
    // Structured bindings with struct.
    struct Point
    {
      double x;
      double y;
      double z;
    };
    Point point;
    point.x = 1.0;
    point.y = 2.0;
    point.z = 3.0;
    auto [x, y, z]{ point };
    println ("x: {}", x);
    println ("y: {}", y);
    println ("z: {}", z);
  }

  {
    // Structured bindings with std::pair.
    pair myPair{ "hello", 5 };
    auto [theString, theInt]{ myPair };
    println ("theString: {}", theString);
    println ("theInt: {}", theInt);
  }
}
