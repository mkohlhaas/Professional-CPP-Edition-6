#pragma once

#include <compare>
#include <string>
#include <string_view>

class SpreadsheetCell
{
  public:
    SpreadsheetCell() = default;
    SpreadsheetCell(double initialValue);
    explicit SpreadsheetCell(std::string_view initialValue);

    void set(double value);
    void set(std::string_view value);

    inline double getValue() const
    {
        return m_value;
    }
    inline std::string getString() const
    {
        return doubleToString(m_value);
    }

    static std::string doubleToString(double value);
    static double      stringToDouble(std::string_view value);

    SpreadsheetCell &operator+=(const SpreadsheetCell &rhs);
    SpreadsheetCell &operator-=(const SpreadsheetCell &rhs);
    SpreadsheetCell &operator*=(const SpreadsheetCell &rhs);
    SpreadsheetCell &operator/=(const SpreadsheetCell &rhs);

    [[nodiscard]] auto operator<=>(const SpreadsheetCell &) const = default;

    SpreadsheetCell  operator-() const;
    SpreadsheetCell &operator++();    // Prefix
    SpreadsheetCell  operator++(int); // Postfix
    SpreadsheetCell &operator--();    // Prefix
    SpreadsheetCell  operator--(int); // Postfix

  private:
    double m_value{0};
};

SpreadsheetCell operator+(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);
SpreadsheetCell operator-(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);
SpreadsheetCell operator*(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);
SpreadsheetCell operator/(const SpreadsheetCell &lhs, const SpreadsheetCell &rhs);
