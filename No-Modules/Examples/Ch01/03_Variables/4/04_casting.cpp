#include <print>

using std::println;

int
main ()
{
  float myFloat{ 3.14f };
  int   i1{ (int)myFloat };             // method 1
  println ("{}", i1);

  int i2{ int (myFloat) };              // method 2
  println ("{}", i2);

  int i3{ static_cast<int> (myFloat) }; // method 3
  println ("{}", i3);

  short someShort{ 16 };
  long  someLong{ someShort }; // no explicit cast needed
  println ("{}", someLong);
}
