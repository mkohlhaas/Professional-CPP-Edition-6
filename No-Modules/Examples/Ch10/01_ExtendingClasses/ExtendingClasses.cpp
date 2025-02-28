#include <print>

using namespace std;

class Base
{
  public:
    void someFunction()
    {
        println("{}", __func__);
    }

  protected:
    int m_protectedInt{0};

  private:
    int m_privateInt [[maybe_unused]]{0};
};

class Derived : public Base
{
  public:
    void someOtherFunction()
    {
        println("{}", __func__);
        println("I can access base class data member m_protectedInt.");
        println("Its value is {}.", m_protectedInt);
        println("But I cannot access base class data member m_privateInt.");
        // println("The value of m_privateInt is {}", m_privateInt); // Error!
    }
};

int main()
{
    Derived myDerived;
    myDerived.someFunction();
    myDerived.someOtherFunction();

    Base myBase [[maybe_unused]];
    // myBase.someOtherFunction();  // Error! Base doesn't have a someOtherFunction().

    Base *base [[maybe_unused]]{new Derived{}}; // Create Derived, store in Base pointer.

    // Error!
    // base->someOtherFunction();
}
