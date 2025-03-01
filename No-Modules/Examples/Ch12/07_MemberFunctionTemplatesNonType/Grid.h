#pragma once

#include <cstddef>
#include <format>
#include <optional>
#include <stdexcept>
#include <utility>

using namespace std;

template <typename T, size_t WIDTH = 10, size_t HEIGHT = 10> class Grid
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

    template <typename E, size_t WIDTH2, size_t HEIGHT2> Grid(const Grid<E, WIDTH2, HEIGHT2> &src);

    template <typename E, size_t WIDTH2, size_t HEIGHT2> Grid &operator=(const Grid<E, WIDTH2, HEIGHT2> &rhs);

    void swap(Grid &other) noexcept;

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

template <typename T, size_t WIDTH, size_t HEIGHT>
template <typename E, size_t WIDTH2, size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT>::Grid(const Grid<E, WIDTH2, HEIGHT2> &src)
{
    for (size_t i{0}; i < WIDTH; ++i)
    {
        for (size_t j{0}; j < HEIGHT; ++j)
        {
            if (i < WIDTH2 && j < HEIGHT2)
            {
                m_cells[i][j] = src.at(i, j);
            }
            else
            {
                m_cells[i][j].reset(); // reset optional
            }
        }
    }
}

template <typename T, size_t WIDTH, size_t HEIGHT> void Grid<T, WIDTH, HEIGHT>::swap(Grid &other) noexcept
{
    std::swap(m_cells, other.m_cells);
}

template <typename T, size_t WIDTH, size_t HEIGHT>
template <typename E, size_t WIDTH2, size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT> &Grid<T, WIDTH, HEIGHT>::operator=(const Grid<E, WIDTH2, HEIGHT2> &rhs)
{
    // Copy-and-swap idiom
    Grid<T, WIDTH, HEIGHT> temp{rhs}; // Do all the work in a temporary instance.
    swap(temp);                       // Commit the work with only non-throwing operations.
    return *this;
}
