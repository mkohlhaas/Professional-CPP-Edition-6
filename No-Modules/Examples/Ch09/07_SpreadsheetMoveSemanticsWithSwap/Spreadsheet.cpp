#include "Spreadsheet.h"
#include <format>
#include <print>
#include <stdexcept>
#include <utility>

using namespace std;

Spreadsheet::Spreadsheet(size_t width, size_t height) : m_width{width}, m_height{height}
{
    println("Normal constructor");

    m_cells = new SpreadsheetCell *[m_width];
    for (size_t i{0}; i < m_width; ++i)
    {
        m_cells[i] = new SpreadsheetCell[m_height];
    }
}

Spreadsheet::~Spreadsheet()
{
    println("Destructor");
    for (size_t i{0}; i < m_width; ++i)
    {
        delete[] m_cells[i];
    }
    delete[] m_cells;
    m_cells = nullptr;
}

Spreadsheet::Spreadsheet(const Spreadsheet &src) : Spreadsheet{src.m_width, src.m_height}
{
    println("Copy constructor");

    // The ctor-initializer of this constructor delegates first to the
    // non-copy constructor to allocate the proper amount of memory.

    // The next step is to copy the data.
    for (size_t i{0}; i < m_width; ++i)
    {
        for (size_t j{0}; j < m_height; ++j)
        {
            m_cells[i][j] = src.m_cells[i][j];
        }
    }
}

void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= m_width)
    {
        throw out_of_range{format("x ({}) must be less than width ({}).", x, m_width)};
    }
    if (y >= m_height)
    {
        throw out_of_range{format("y ({}) must be less than height ({}).", y, m_height)};
    }
}

void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell &cell)
{
    verifyCoordinate(x, y);
    m_cells[x][y] = cell;
}

SpreadsheetCell &Spreadsheet::getCellAt(size_t x, size_t y)
{
    verifyCoordinate(x, y);
    return m_cells[x][y];
}

void Spreadsheet::swap(Spreadsheet &other) noexcept
{
    std::swap(m_width, other.m_width);
    std::swap(m_height, other.m_height);
    std::swap(m_cells, other.m_cells);
}

void swap(Spreadsheet &first, Spreadsheet &second) noexcept
{
    first.swap(second);
}

Spreadsheet &Spreadsheet::operator=(const Spreadsheet &rhs)
{
    println("Copy assignment operator");

    // Copy-and-swap idiom
    Spreadsheet temp{rhs}; // Do all the work in a temporary instance
    swap(temp);            // Commit the work with only non-throwing operations
    return *this;
}

// Move constructor
Spreadsheet::Spreadsheet(Spreadsheet &&src) noexcept
{
    println("Move constructor");

    swap(src);
}

// Move assignment operator
Spreadsheet &Spreadsheet::operator=(Spreadsheet &&rhs) noexcept
{
    println("Move assignment operator");

    auto moved{std::move(rhs)}; // Move rhs into moved (noexcept)
    swap(moved);                // Commit the work with only non-throwing operations
    return *this;
}
