#include <string>
#include <vector>

using namespace std;

// void processVector(const vector<basic_string<char>>& vec)
//{
//	// ...
// }

// in stringfwd.h:
// typedef basic_string<char> string;
void processVector(const vector<string> &vec [[maybe_unused]]) {
  // ...
}

int main() {
  // vector<basic_string<char>> myVector;
  vector<string> myVector;
  processVector(myVector);
}
