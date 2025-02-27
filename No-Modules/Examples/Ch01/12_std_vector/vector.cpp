#include <print>
#include <vector>

using namespace std;

int main()
{
    // vector<int> myVector{ 11, 22 };
    vector myVector{11, 22}; // Using CTAD

    myVector.push_back(33);
    myVector.push_back(44);

    println("1st element: {}", myVector[0]);
    println("2nd element: {}", myVector[1]);
}
