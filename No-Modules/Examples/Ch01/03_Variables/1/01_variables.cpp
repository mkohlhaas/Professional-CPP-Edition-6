#include <print>

using namespace std;

int
main ()
{
  int uninitializedInt;
  int initializedInt{ 7 };

  println ("{} is a random value.", uninitializedInt);
  println ("{} was assigned as an initial value.", initializedInt);

  // Zero Initialization
  float myFloat1{ 0 };
  println ("{}", myFloat1);

  int myInt1{ 0 };
  println ("{}", myInt1);

  float myFloat2{};
  println ("{}", myFloat2);

  int myInt2{};
  println ("{}", myInt2);
}
