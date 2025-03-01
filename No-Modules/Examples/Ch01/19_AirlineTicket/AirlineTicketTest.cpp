#include "AirlineTicket.h"
#include <print>

using namespace std;

int main()
{
    AirlineTicket myTicket; // Stack-based AirlineTicket
    println("This ticket will cost ${}.", myTicket.calculatePriceInDollars());

    myTicket.setPassengerName("Sherman T. Socketwrench");
    myTicket.setNumberOfMiles(700);
    double cost{myTicket.calculatePriceInDollars()};
    println("This ticket will cost ${}.", cost);
}
