#include "SpreadsheetCell.h"
#include <charconv>

using namespace std;

namespace
{
string doubleToString(double value)
{
    return to_string(value);
}

double stringToDouble(string_view value)
{
    double number{0};
    from_chars(value.data(), value.data() + value.size(), number);
    return number;
}
} // namespace

SpreadsheetCell::SpreadsheetCell(double initialValue) : m_value{initialValue}
{
}

SpreadsheetCell::SpreadsheetCell(string_view initialValue) : m_value{stringToDouble(initialValue)}
{
}

void SpreadsheetCell::setValue(double value)
{
    m_value = value;
}

double SpreadsheetCell::getValue() const
{
    return m_value;
}

void SpreadsheetCell::setString(string_view value)
{
    m_value = stringToDouble(value);
}

string SpreadsheetCell::getString() const
{
    return doubleToString(m_value);
}
