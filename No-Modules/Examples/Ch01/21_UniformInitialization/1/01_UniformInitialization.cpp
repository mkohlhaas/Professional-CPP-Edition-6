#include <string>
#include <vector>

using namespace std;

struct CircleStruct {
  int x, y;
  double radius;
};

class CircleClass {
public:
  CircleClass(int x, int y, double radius) : m_x{x}, m_y{y}, m_radius{radius} {}

private:
  int m_x [[maybe_unused]], m_y [[maybe_unused]];
  double m_radius [[maybe_unused]];
};

void func(int i [[maybe_unused]]) {
  // ...
}

class MyClass {
public:
  MyClass() : m_array{0, 1, 2, 3} {}

private:
  int m_array [[maybe_unused]][4];
};

struct Employee {
  char firstInitial;
  char lastInitial;
  int employeeNumber;
  int salary;
};

int main() {
  // Old pre-C++11 way
  CircleStruct myCircle1 [[maybe_unused]] = {10, 10, 2.5};
  CircleClass myCircle2(10, 10, 2.5);

  // C++11 uniform initialization
  CircleStruct myCircle3 [[maybe_unused]] = {10, 10, 2.5};
  CircleClass myCircle4 = {10, 10, 2.5};
  CircleStruct myCircle5 [[maybe_unused]]{10, 10, 2.5};
  CircleClass myCircle6{10, 10, 2.5};

  // Initializing a struct
  Employee anEmployee;
  anEmployee.firstInitial = 'J';
  anEmployee.lastInitial = 'D';
  anEmployee.employeeNumber = 42;
  anEmployee.salary = 80'000;

  // Initializing a struct with uniform initialization
  Employee anEmployee2 [[maybe_unused]]{'J', 'D', 42, 80'000};

  int a [[maybe_unused]] = 3;
  int b [[maybe_unused]] (3);
  int c [[maybe_unused]] = {3}; // Uniform initialization
  int d [[maybe_unused]]{3};    // Uniform initialization
  int e [[maybe_unused]]{};     // Uniform initialization, e will be 0

  Employee anEmployee3 [[maybe_unused]];
  Employee anEmployee4 [[maybe_unused]]{};

  // Narrowing
  int x [[maybe_unused]] = 3.14;
  func(3.14);

  // Preventing narrowing
  // int x{3.14};       // Error because narrowing
  // func({3.14});      // Error because narrowing

  // Create a MyClass object
  MyClass myClass;

  // Uniform initialization also works with vectors
  vector<string> myVec{"String 1", "String 2", "String 3"};
}
