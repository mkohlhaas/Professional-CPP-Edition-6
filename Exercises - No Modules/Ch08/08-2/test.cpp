#include "Person.h"
#include <print>

using namespace std;

int main()
{
	Person person{ "John", "Doe" };
	println("{} {}", person.getFirstName(), person.getLastName());

	Person persons[3];
}
