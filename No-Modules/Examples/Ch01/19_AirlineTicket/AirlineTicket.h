#pragma once

#include <string>

using std::string;

class AirlineTicket
{

public:
  // AirlineTicket();
  //~AirlineTicket();

  double calculatePriceInDollars ();

  string getPassengerName ();
  void   setPassengerName (string name);

  int  getNumberOfMiles ();
  void setNumberOfMiles (int miles);

  bool hasEliteSuperRewardsStatus ();
  void setHasEliteSuperRewardsStatus (bool status);

private:
  // std::string m_passengerName;
  // int m_numberOfMiles;
  // bool m_hasEliteSuperRewardsStatus;
  string m_passengerName{ "Unknown Passenger" };
  int    m_numberOfMiles{ 0 };
  bool   m_hasEliteSuperRewardsStatus{ false };
};
