#include <print>
#include <string>
#include <vector>

using namespace std;

int
main ()
{
  vector<string> stringVector (10, "hello");
  println ("Vector elements: {}", stringVector);
}
