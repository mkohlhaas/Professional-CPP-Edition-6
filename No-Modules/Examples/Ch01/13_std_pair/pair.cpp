#include <print>
#include <utility>

using namespace std;

int
main ()
{
  // pair<double, int> myPair{ 1.23, 5 };
  pair myPair1{ 1.23, 5 }; // Using CTAD
  pair myPair2{ 4.24, 9 };
  println ("first: {}, second: {}", myPair1.first, myPair1.second);
  println ("first: {}, second: {}", myPair2.first, myPair2.second);
  myPair1.swap (myPair2);
  println ("first: {}, second: {}", myPair1.first, myPair1.second);
  println ("first: {}, second: {}", myPair2.first, myPair2.second);
}
