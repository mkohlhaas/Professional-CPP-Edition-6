#include <cstdlib>
#include <print>

using namespace std;

[[noreturn]]
void
forceProgramTermination ()
{
  println ("exiting...");
  exit (EXIT_FAILURE);
}

bool
isDongleAvailable ()
{
  // bool isAvailable{ false };
  bool isAvailable{ true };
  // Check whether a licensing dongle is available
  // ...
  return isAvailable;
}

bool
isFeatureLicensed (int featureId)
{
  if (!isDongleAvailable ())
    {
      // No licensing dongle found, abort program execution!
      forceProgramTermination ();
    }
  else
    {
      // Dongle available, perform license check of the given feature...
      bool isLicensed{ featureId == 42 };
      return isLicensed;
    }
}

int
main ()
{
  bool isLicensed{ isFeatureLicensed (42) };
  println ("is licensed: {}", isLicensed);
}
