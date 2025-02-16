#include <iostream>
#include <print>

using std::println, std::cerr;

int
main ()
{
  println ("Hello, World!");
  println ("There are {} ways I love you.", 219);
  println ("{} + {} = {}", 2, 4, 6);
  println ("{0} + {1} = {2}", 2, 4, 6);
  println (cerr, "Error: {}", 6);
}
