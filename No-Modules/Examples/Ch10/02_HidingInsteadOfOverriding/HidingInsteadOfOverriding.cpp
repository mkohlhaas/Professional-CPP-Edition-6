#include <print>

using namespace std;

class Base
{
  public:
    void someFunction()
    {
        println("{}", __func__);
        println("Base::someFunction()");
    }

  protected:
    int m_protectedInt{0};

  private:
    int m_privateInt [[maybe_unused]]{0};
};

class Derived : public Base
{
  public:
    void someFunction()
    {
        println("{}", __func__);
        println("Derived::someFunction()");
    }

    void someOtherFunction()
    {
        println("{}", __func__);
        println("I can access base class data member m_protectedInt.");
        println("Its value is {}", m_protectedInt);
        // Error!
        // println("The value of m_privateInt is {}", m_privateInt);
    }
};

int main()
{
    {
        Derived myDerived;
        myDerived.someFunction();
    }

    {
        Derived myDerived;
        myDerived.someFunction();

        Base &ref{myDerived};
        ref.someFunction();
    }
}
