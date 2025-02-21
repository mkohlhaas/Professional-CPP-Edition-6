#include <memory>
#include <print>

using namespace std;

class Simple {
public:
  Simple() { println("Simple CON-structor called!"); }
  ~Simple() { println("Simple DE-structor called!"); }
};

unique_ptr<Simple> create() {
  auto ptr{make_unique<Simple>()};
  // Do something with ptr...
  return ptr;
}

int main() {
  println("1");
  unique_ptr<Simple> mySmartPtr1{create()};
  println("2");
  auto mySmartPtr2{create()};
  println("3");
}
