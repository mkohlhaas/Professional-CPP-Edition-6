#pragma once

#include <cstddef>
#include <format>
#include <optional>
#include <stdexcept>
#include <utility>

using namespace std;

template <typename T, size_t WIDTH, size_t HEIGHT> class Grid
{
  public:
    Grid()          = default;
    virtual ~Grid() = default;

    // Explicitly default a copy constructor and copy assignment operator.
    Grid(const Grid &src)            = default;
    Grid &operator=(const Grid &rhs) = default;

    // Explicitly default a move constructor and move assignment operator.
    Grid(Grid &&src)            = default;
    Grid &operator=(Grid &&rhs) = default;

    optional<T>       &at(size_t x, size_t y);
    const optional<T> &at(size_t x, size_t y) const;

    size_t getHeight() const
    {
        return HEIGHT;
    }
    size_t getWidth() const
    {
        return WIDTH;
    }

  private:
    void verifyCoordinate(size_t x, size_t y) const;

    optional<T> m_cells[WIDTH][HEIGHT];
};

template <typename T, size_t WIDTH, size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= WIDTH)
    {
        throw out_of_range{format("x ({}) must be less than width ({}).", x, WIDTH)};
    }
    if (y >= HEIGHT)
    {
        throw out_of_range{format("y ({}) must be less than height ({}).", y, HEIGHT)};
    }
}

template <typename T, size_t WIDTH, size_t HEIGHT>
const optional<T> &Grid<T, WIDTH, HEIGHT>::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return m_cells[x][y];
}

template <typename T, size_t WIDTH, size_t HEIGHT> optional<T> &Grid<T, WIDTH, HEIGHT>::at(size_t x, size_t y)
{
    return const_cast<optional<T> &>(as_const(*this).at(x, y));
}
