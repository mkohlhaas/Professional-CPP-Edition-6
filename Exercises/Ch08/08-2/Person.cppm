export module person;

import std;

//// To make the following line work, a default constructor is needed.
//// Person persons[3];

export class Person
{
public:
	explicit Person(const std::string& firstName, const std::string& lastName)
		: m_firstName{ firstName }, m_lastName{ lastName }
	{}

	Person() = default;    //// Explicitly defaulted default constructor.

	const std::string& getFirstName() const { return m_firstName; }
	void setFirstName(const std::string& firstName) { m_firstName = firstName; }

	const std::string& getLastName() const { return m_lastName; }
	void setLastName(const std::string& lastName) { m_lastName = lastName; }

private:
	std::string m_firstName;
	std::string m_lastName;
};

//// NOTE: the above solution uses "const std::string&" as type for the
////       parameters. This is not always optimal. You could use
////       std::string_view as parameter type, but this is not always
////       optimal either.
////       The optimal solution is to pass std::string by value and move
////       from the parameter. This is explained in the section
////       "Optimal Way to Pass Arguments to Functions" in Chapter 9.
////       See the solution for Exercise 8-1 for an example of using
////       that technique.
