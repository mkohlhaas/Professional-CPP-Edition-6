#pragma once

#include <cstddef>
#include <format>
#include <optional>
#include <stdexcept>
#include <utility>
#include <vector>

using namespace std;

template <typename T> class Grid
{
  public:
    explicit Grid(size_t width = DefaultWidth, size_t height = DefaultHeight);
    Grid(const Grid &src)            = default; // copy constructor
    Grid &operator=(const Grid &rhs) = default; // copy assignment operator
    Grid(Grid &&src)                 = default; // move constructor
    Grid &operator=(Grid &&rhs)      = default; // move assignment operator
    virtual ~Grid()                  = default;

    // member function templates
    template <typename E> Grid(const Grid<E> &src);
    template <typename E> Grid &operator=(const Grid<E> &rhs);

    void swap(Grid &other) noexcept;

    optional<T>       &at(size_t x, size_t y);
    const optional<T> &at(size_t x, size_t y) const;

    size_t getHeight() const
    {
        return m_height;
    }
    size_t getWidth() const
    {
        return m_width;
    }

    static constexpr size_t DefaultWidth{10};
    static constexpr size_t DefaultHeight{10};

  private:
    void                verifyCoordinate(size_t x, size_t y) const;
    size_t              m_width{0};
    size_t              m_height{0};
    vector<optional<T>> m_cells;
};

template <typename T>
Grid<T>::Grid(size_t width, size_t height) : m_width{width}, m_height{height}, m_cells(m_width * m_height)
{
    // m_cells.resize(m_width * m_height);
}

template <typename T> void Grid<T>::verifyCoordinate(size_t x, size_t y) const
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

template <typename T> const optional<T> &Grid<T>::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return m_cells[x + y * m_width];
}

template <typename T> optional<T> &Grid<T>::at(size_t x, size_t y)
{
    return const_cast<optional<T> &>(as_const(*this).at(x, y));
}

// First class template headerm
// then member template header:
// template <typename T> template <typename E>
// Not: template <typename T, typename E>
template <typename T> template <typename E> Grid<T>::Grid(const Grid<E> &src) : Grid{src.getWidth(), src.getHeight()}
{
    // The ctor-initializer of this constructor delegates first to the
    // non-copy constructor to allocate the proper amount of memory.

    // The next step is to copy the data.
    for (size_t i{0}; i < m_width; ++i)
    {
        for (size_t j{0}; j < m_height; ++j)
        {
            at(i, j) = src.at(i, j);
        }
    }
}

// template <typename T> void Grid<T>::swap(Grid &other) noexcept
// same (makes types evident for reader):
template <typename T> void Grid<T>::swap(Grid<T> &other) noexcept
{
    // need std::swap!!!
    std::swap(m_width, other.m_width);
    std::swap(m_height, other.m_height);
    std::swap(m_cells, other.m_cells);
}

template <typename T> template <typename E> Grid<T> &Grid<T>::operator=(const Grid<E> &rhs)
{
    // Copy-and-swap idiom
    Grid<T> temp{rhs}; // Converts Grid<E> (rhs) to Grid<T> (temp)
    swap(temp);        // Commit the work with only non-throwing operations.
    return *this;
}
