#include <format>
#include <iostream>

using std::cout, std::format, std::endl;

int
main ()
{
  cout << "There are " << 219 << " ways I love you." << endl;
  cout << format ("There are {} ways I love you.", 219) << endl;
}
