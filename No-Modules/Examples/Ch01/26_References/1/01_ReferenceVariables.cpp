#include <ostream>
#include <print>
#include <string>
#include <utility>

using namespace std;

string getString() { return "Hello world!"; }

int main() {
  int x{3}, y{4}, z{5};
  int &xRef{x};
  xRef = 10;
  //  int& emptyRef; // DOES NOT COMPILE!

  xRef = y; // changes value of x to 4. Doesn't make xRef refer to y.

  int &zRef{z};
  zRef = xRef; // Assigns values, not references

  const int &zRef2 [[maybe_unused]]{z};
  //  zRef2 = 4; // DOES NOT COMPILE

  //  int& unnamedRef1{ 5 };   // DOES NOT COMPILE
  const int &unnamedRef2 [[maybe_unused]]{5}; // Works as expected

  // string& string1{ getString() };    // DOES NOT COMPILE
  const string &string2 [[maybe_unused]]{getString()}; // Works as expected

  int *intP{nullptr};
  int *&ptrRef{intP};
  ptrRef = new int;
  println("{}", *ptrRef); // 0
  *ptrRef = 5;
  println("{}", *ptrRef); // 5
  delete ptrRef;
  println("{}", *ptrRef); // -1290575983 (some random value)
  ptrRef = nullptr;
  // println("{}", *ptrRef); // segmentation fault

  int *xPtr{&xRef}; // address of a reference is pointer to value
  *xPtr = 100;

  pair myPair{"hello", 5};
  const auto &[theString, theInt]{myPair}; // Decompose into references-to-const
  println("{}", theString);                // hello
  println("{}", theInt);                   // 5
}
