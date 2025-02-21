#include <memory>
#include <print>

using namespace std;

class Simple {
public:
  Simple() { println("Simple CON-structor called!"); }
  ~Simple() { println("Simple DE-structor called!"); }

  void go() {}
};

void leaky() {
  Simple *mySimplePtr{new Simple{}}; // BUG! Memory is never released!
  mySimplePtr->go();
}

void couldBeLeaky() {
  Simple *mySimplePtr{new Simple{}};
  mySimplePtr->go();
  delete mySimplePtr;
}

void notLeaky() {
  auto mySimpleSmartPtr{make_unique<Simple>()};
  mySimpleSmartPtr->go();
}

void processData(Simple *simple) {
  /* Use the simple pointer ... */
  simple->go();
}

int main() {
  println("1");
  leaky();
  println("2");
  couldBeLeaky();
  println("3");
  notLeaky();

  println("4");
  unique_ptr<Simple> mySimpleSmartPtr{new Simple{}};
  processData(mySimpleSmartPtr.get());

  println("5");
  mySimpleSmartPtr.reset(); // Free resource and set to nullptr
  println("6");
  mySimpleSmartPtr.reset(new Simple{}); // Free resource and set to a new

  println("7");
  mySimpleSmartPtr.reset(new Simple{}); // Free resource and set to a new
  println("8");
  Simple *simple{mySimpleSmartPtr.release()}; // Release ownership
  // Use the simple pointer...
  println("9");
  delete simple;
  simple = nullptr;
}
