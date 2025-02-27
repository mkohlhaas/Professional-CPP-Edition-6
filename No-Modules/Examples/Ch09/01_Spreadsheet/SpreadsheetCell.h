#pragma once

#include <string>
#include <string_view>

using std::string, std::string_view;

class SpreadsheetCell
{
  public:
    SpreadsheetCell() = default;
    SpreadsheetCell(double initialValue);
    SpreadsheetCell(string_view initialValue);

    void   setValue(double value);
    double getValue() const;

    void   setString(string_view value);
    string getString() const;

  private:
    string doubleToString(double value) const;
    double stringToDouble(string_view value) const;

    double m_value{0};
};
