#include "GridString.h"

Grid<const char *>::Grid(size_t width, size_t height) : m_width{width}, m_height{height}
{
    m_cells.resize(m_width * m_height);
}

void Grid<const char *>::verifyCoordinate(size_t x, size_t y) const
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

const optional<string> &Grid<const char *>::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return m_cells[x + y * m_width];
}

optional<string> &Grid<const char *>::at(size_t x, size_t y)
{
    return const_cast<optional<string> &>(as_const(*this).at(x, y));
}
