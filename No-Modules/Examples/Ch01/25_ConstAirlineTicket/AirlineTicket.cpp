#include "AirlineTicket.h"

using namespace std;

double AirlineTicket::calculatePriceInDollars() const
{
    if (hasEliteSuperRewardsStatus())
    {
        return 0;
    }
    else
    {
        return getNumberOfMiles() * 0.1;
    }
}

string AirlineTicket::getPassengerName() const
{
    return m_passengerName;
}

void AirlineTicket::setPassengerName(string name)
{
    m_passengerName = name;
}

int AirlineTicket::getNumberOfMiles() const
{
    return m_numberOfMiles;
}

void AirlineTicket::setNumberOfMiles(int miles)
{
    m_numberOfMiles = miles;
}

bool AirlineTicket::hasEliteSuperRewardsStatus() const
{
    return m_hasEliteSuperRewardsStatus;
}

void AirlineTicket::setHasEliteSuperRewardsStatus(bool status)
{
    m_hasEliteSuperRewardsStatus = status;
}
