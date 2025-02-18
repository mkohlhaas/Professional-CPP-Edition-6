#include <string>

using namespace std;

void mysteryFunction(const string *someString [[maybe_unused]]) {
  // *someString = "Test"; // Will not compile.
}

int main() {
  string myString{"The string"};
  mysteryFunction(&myString); // &myString is a string*
}
