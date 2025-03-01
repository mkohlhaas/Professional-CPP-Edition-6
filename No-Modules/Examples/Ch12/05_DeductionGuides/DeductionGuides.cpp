#include <string>
#include <utility>

using namespace std;

template <typename T> class SpreadsheetCell
{
  public:
    explicit SpreadsheetCell(T t) : m_content{std::move(t)}
    {
    }
    const T &getContent() const
    {
        return m_content;
    }

  private:
    T m_content;
};

// User-defined Deduction Guide
explicit SpreadsheetCell(const char *) -> SpreadsheetCell<string>;
// or:
// SpreadsheetCell(const char *) -> SpreadsheetCell<string>;

int main()
{
    // Class Template Argument Deduction
    string          myString{"Hello World!"};
    SpreadsheetCell cell{myString};
    SpreadsheetCell cell2{"test"};
}
