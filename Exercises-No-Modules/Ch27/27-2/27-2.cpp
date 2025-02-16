#include <chrono>
#include <iostream>
#include <print>
#include <stop_token>
#include <thread>

using namespace std;
using namespace std::chrono;

void
beeper (stop_token token, duration<int> delay)
{
  while (!token.stop_requested ())
    {
      print ("\a");
      this_thread::sleep_for (delay);
    }
}

int
main ()
{
  jthread beepThread{ beeper, 3s };

  print ("Press enter to stop beeping");
  cin.ignore ();

  beepThread.request_stop ();
}
