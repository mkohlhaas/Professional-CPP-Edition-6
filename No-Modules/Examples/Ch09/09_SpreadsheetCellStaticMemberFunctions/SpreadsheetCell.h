#pragma once

#include <string>
#include <string_view>

class SpreadsheetCell
{
  public:
    SpreadsheetCell() = default;
    SpreadsheetCell(double initialValue);
    SpreadsheetCell(std::string_view initialValue);

    void   setValue(double value);
    double getValue() const;

    void        setString(std::string_view value);
    std::string getString() const;

  private:
    static std::string doubleToString(double value);
    static double      stringToDouble(std::string_view value);

    double m_value{0};
};
