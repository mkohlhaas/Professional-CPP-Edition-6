#include <cstddef>
#include <print>

using namespace std;

class Simple {
public:
  Simple() { println("Simple CON-structor called!"); }
  ~Simple() { println("Simple DE-structor called!"); }
};

int main() {
  {
    // Constructor will be called 4 times.
    Simple *mySimpleArray{new Simple[4]};

    // use mySimpleArray
    // ...

    // Destructor will be called 4 times.
    delete[] mySimpleArray;
    mySimpleArray = nullptr;
  }

  println();

  {
    const size_t size{4};
    Simple **mySimplePtrArray{new Simple *[size]};

    // Allocate an object for each pointer.
    // Constructor will be called 4 times.
    for (size_t i{0}; i < size; ++i) {
      mySimplePtrArray[i] = new Simple{};
    }

    // use mySimplePtrArray ...
    // ...

    // Delete each allocated object.
    // Destructor will be called 4 times.
    for (size_t i{0}; i < size; ++i) {
      delete mySimplePtrArray[i];
      mySimplePtrArray[i] = nullptr;
    }

    // Delete the array itself.
    delete[] mySimplePtrArray;
    mySimplePtrArray = nullptr;
  }
}
