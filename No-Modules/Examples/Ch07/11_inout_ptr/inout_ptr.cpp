#include <memory>
#include <print>

using namespace std;

using errorcode = int;

errorcode my_alloc(int value, int **data)
{
    *data = new int{value};
    println("Allocated");
    return 0;
}

errorcode my_free(int *data)
{
    delete data;
    println("Freed");
    return 0;
}

int main()
{
    {
        unique_ptr<int, decltype(&my_free)> myIntSmartPtr(nullptr, my_free);
        int                                *data{nullptr};
        println("1");
        my_alloc(42, &data);
        println("2");
        myIntSmartPtr.reset(data);
    }

    {
        unique_ptr<int, decltype(&my_free)> myIntSmartPtr(nullptr, my_free);
        println("3");
        my_alloc(42, inout_ptr(myIntSmartPtr));
        println("4");
    }
}
