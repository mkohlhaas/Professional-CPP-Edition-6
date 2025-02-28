#include <print>

using namespace std;

class Base
{
  public:
    virtual void someFunction();

  protected:
    int m_protectedInt{0};

  private:
    int m_privateInt [[maybe_unused]]{0};
};

void Base::someFunction()
{
    println("{}", __func__);
    println("This is Base's version of someFunction().");
}

class Derived : public Base
{
  public:
    void someFunction() override; // Overrides Base's someFunction()

    virtual void someOtherFunction()
    {
        println("{}", __func__);
        println("This is someOtherFunction from Derived.");
        println("I can access base class data member m_protectedInt.");
        println("Its value is {}", m_protectedInt);
        // Error!
        // println("The value of m_privateInt is {}", m_privateInt);
    }
};

void Derived::someFunction()
{
    println("{}", __func__);
    println("This is Derived's version of someFunction().");
}

int main()
{
    {
        println("1");
        Base myBase;
        myBase.someFunction(); // Calls Base's version of someFunction().
    }

    println();

    {
        println("2");
        Derived myDerived;
        myDerived.someFunction(); // Calls Derived's version of someFunction()
    }

    println();

    {
        println("3");
        Derived myDerived;
        Base   &ref{myDerived};
        ref.someFunction(); // Calls Derived's version of someFunction()
    }

    println();

    {
        println("4");
        Derived myDerived;
        myDerived.someOtherFunction(); // This is fine.
        Base &ref [[maybe_unused]]{myDerived};
        // Error:
        // ref.someOtherFunction();
    }

    println();

    {
        println("5");
        Derived myDerived;
        Base    assignedObject{myDerived}; // Assigns a Derived to a Base.
        assignedObject.someFunction();     // Calls Base's version of someFunction()
    }
}
