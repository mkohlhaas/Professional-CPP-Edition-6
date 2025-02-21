#include <memory>
#include <print>

using namespace std;

class Simple {
public:
  Simple() { println("Simple CON-structor called!"); }
  ~Simple() { println("Simple DE-structor called!"); }
};

void doubleDelete() {
  Simple *mySimple{new Simple{}};
  shared_ptr<Simple> smartPtr1(mySimple);
  shared_ptr<Simple> smartPtr2(mySimple);
}

void noDoubleDelete() {
  auto smartPtr1{make_shared<Simple>()};
  auto smartPtr2{smartPtr1};
}

int main() {
  // doubleDelete(); // BUG (causes a crash!)
  noDoubleDelete();
}
