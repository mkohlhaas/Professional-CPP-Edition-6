#include <print>

using namespace std;

class Base
{
  public:
    // Base()          = default;
    Base()
    {
        println("{}", __func__);
    }

    // virtual ~Base() = default;
    virtual ~Base()
    {
        println("{}", __func__);
    }
};

class Derived : public Base
{
  public:
    Derived()
    {
        println("{}", __func__);
        m_string = new char[30];
        println("m_string allocated");
    }

    ~Derived() override
    {
        println("{}", __func__);
        delete[] m_string;
        println("m_string deallocated");
    }

  private:
    char *m_string;
};

int main()
{
    println("1");
    Base *ptr{new Derived{}}; // m_string is allocated here

    println();

    println("2");
    delete ptr; // m_string is deallocated here
}
