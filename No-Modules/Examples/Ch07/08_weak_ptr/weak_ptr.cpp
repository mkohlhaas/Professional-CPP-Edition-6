#include <memory>
#include <print>

using namespace std;

class Simple
{
  public:
    Simple()
    {
        println("Simple CON-structor called!");
    }
    ~Simple()
    {
        println("Simple DE-structor called!");
    }
};

void useResource(weak_ptr<Simple> &weakSimple)
{
    auto resource{weakSimple.lock()};

    if (resource)
    {
        println("Resource still alive.");
    }
    else
    {
        println("Resource has been freed!");
    }
}

int main()
{
    println("1");
    auto             sharedSimple{make_shared<Simple>()};
    weak_ptr<Simple> weakSimple{sharedSimple};

    // Try to use the weak_ptr.
    println("2");
    useResource(weakSimple);

    // Reset the shared_ptr.
    // Since there is only 1 shared_ptr to the Simple resource, this will
    // free the resource, even though there is still a weak_ptr alive.
    println("3");
    sharedSimple.reset();

    // Try to use the weak_ptr a second time.
    println("4");
    useResource(weakSimple);
}
