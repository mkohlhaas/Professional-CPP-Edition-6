#include "employee.h"

#include <print>

using namespace std;

int
main ()
{
  Employee anEmployee;
  anEmployee.firstInitial   = 'J';
  anEmployee.lastInitial    = 'D';
  anEmployee.employeeNumber = 42;
  anEmployee.salary         = 80000;

  println ("Employee: {}{}", anEmployee.firstInitial, anEmployee.lastInitial);
  println ("Number: {}", anEmployee.employeeNumber);
  println ("Salary: ${}", anEmployee.salary);

  println ();

  Employee anotherEmployee{ 'M', 'K', 42, 90000 };
  println ("Employee: {}{}", anotherEmployee.firstInitial, anotherEmployee.lastInitial);
  println ("Number: {}", anotherEmployee.employeeNumber);
  println ("Salary: ${}", anotherEmployee.salary);
}
