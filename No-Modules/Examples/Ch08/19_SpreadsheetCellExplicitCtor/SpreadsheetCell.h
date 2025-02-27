#pragma once

#include <string>
#include <string_view>

using std::string, std::string_view;

class SpreadsheetCell
{
  public:
    SpreadsheetCell() = default;
    explicit SpreadsheetCell(double initialValue);
    explicit SpreadsheetCell(string_view initialValue);
    // SpreadsheetCell(const SpreadsheetCell &src);

    void   setValue(double value);
    double getValue() const;

    void   setString(std::string_view value);
    string getString() const;

  private:
    string doubleToString(double value) const;
    double stringToDouble(std::string_view value) const;

    double m_value{0};
};
