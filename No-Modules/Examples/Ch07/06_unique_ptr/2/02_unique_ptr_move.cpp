#include <memory>
#include <print>
#include <utility>

using namespace std;

class Foo {
public:
  Foo(unique_ptr<int> data) : m_data{std::move(data)} {
    println("Creating Foo.");
  }

private:
  unique_ptr<int> m_data;
};

int main() {
  println("1");
  auto myIntSmartPtr{make_unique<int>(42)};
  println("2");
  Foo f{std::move(myIntSmartPtr)};
}
