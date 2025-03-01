#pragma once

#include "SpreadsheetCell.h"
#include <cstddef>

class Spreadsheet
{
  public:
    Spreadsheet(std::size_t width, std::size_t height);
    Spreadsheet(const Spreadsheet &src);
    Spreadsheet(Spreadsheet &&src) noexcept;            // Move constructor
    ~Spreadsheet();

    Spreadsheet &operator=(const Spreadsheet &rhs);
    Spreadsheet &operator=(Spreadsheet &&rhs) noexcept; // Move assignment

    void             setCellAt(std::size_t x, std::size_t y, const SpreadsheetCell &cell);
    SpreadsheetCell &getCellAt(std::size_t x, std::size_t y);

    void swap(Spreadsheet &other) noexcept;

  private:
    void verifyCoordinate(std::size_t x, std::size_t y) const;
    void cleanup() noexcept;
    void moveFrom(Spreadsheet &src) noexcept;

    std::size_t       m_width{0};
    std::size_t       m_height{0};
    SpreadsheetCell **m_cells{nullptr};
};

void swap(Spreadsheet &first, Spreadsheet &second) noexcept;
