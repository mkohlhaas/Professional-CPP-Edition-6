#pragma once

#include "SpreadsheetCell.h"
#include <cstddef>

using std::size_t;

class Spreadsheet
{
  public:
    Spreadsheet(size_t width, size_t height);
    Spreadsheet(const Spreadsheet &src);
    ~Spreadsheet();

    Spreadsheet &operator=(const Spreadsheet &rhs);

    void             setCellAt(size_t x, size_t y, const SpreadsheetCell &cell);
    SpreadsheetCell &getCellAt(size_t x, size_t y);

    void swap(Spreadsheet &other) noexcept;

  private:
    void verifyCoordinate(size_t x, size_t y) const;
    // bool inRange(size_t value, size_t upper) const;

    size_t            m_width{0};
    size_t            m_height{0};
    SpreadsheetCell **m_cells{nullptr};
};

void swap(Spreadsheet &first, Spreadsheet &second) noexcept;
