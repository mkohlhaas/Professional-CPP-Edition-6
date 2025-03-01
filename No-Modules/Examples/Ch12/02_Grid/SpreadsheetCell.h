#pragma once

#include <string>
#include <string_view>

using namespace std;

class SpreadsheetCell
{
  public:
    SpreadsheetCell() = default;
    SpreadsheetCell(double initialValue);
    SpreadsheetCell(string_view initialValue);

    void set(double value);
    void set(string_view value);

    double getValue() const;
    string getString() const;

    SpreadsheetCell &operator+=(const SpreadsheetCell &rhs);
    SpreadsheetCell &operator-=(const SpreadsheetCell &rhs);
    SpreadsheetCell &operator*=(const SpreadsheetCell &rhs);
    SpreadsheetCell &operator/=(const SpreadsheetCell &rhs);

    [[nodiscard]] auto operator<=>(const SpreadsheetCell &) const = default;

  private:
    static string doubleToString(double value);
    static double stringToDouble(string_view value);
    double        m_value{0};
};

SpreadsheetCell operator+(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);
SpreadsheetCell operator-(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);
SpreadsheetCell operator*(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);
SpreadsheetCell operator/(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);
