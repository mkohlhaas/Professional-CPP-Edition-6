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
    virtual ~Grid() = default;

    // Explicitly default a copy constructor and copy assignment operator.
    Grid(const Grid &src)            = default;
    Grid &operator=(const Grid &rhs) = default;

    // Explicitly default a move constructor and move assignment operator.
    Grid(Grid &&src)            = default;
    Grid &operator=(Grid &&rhs) = default;

    template <typename E> Grid(const Grid<E> &src);

    template <typename E> Grid &operator=(const Grid<E> &rhs);

    void swap(Grid &other) noexcept;

    // optional<T>& at(size_t x, size_t y);
    // const optional<T>& at(size_t x, size_t y) const;
    template <typename Self> auto &&at(this Self &&self, size_t x, size_t y);

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
    void verifyCoordinate(size_t x, size_t y) const;

    vector<optional<T>> m_cells;
    size_t              m_width{0}, m_height{0};
};

template <typename T> Grid<T>::Grid(size_t width, size_t height) : m_width{width}, m_height{height}
{
    m_cells.resize(m_width * m_height);
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

// template <typename T>
// const optional<T>& Grid<T>::at(size_t x, size_t y) const
//{
//	verifyCoordinate(x, y);
//	return m_cells[x + y * m_width];
// }
//
// template <typename T>
// optional<T>& Grid<T>::at(size_t x, size_t y)
//{
//	return const_cast<optional<T>&>(as_const(*this).at(x, y));
// }

// deducing 'this'
template <typename T> template <typename Self> auto &&Grid<T>::at(this Self &&self, size_t x, size_t y)
{
    self.verifyCoordinate(x, y);
    return forward_like<Self>(self.m_cells[x + y * self.m_width]);
}

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

template <typename T> void Grid<T>::swap(Grid &other) noexcept
{
    swap(m_width, other.m_width);
    swap(m_height, other.m_height);
    swap(m_cells, other.m_cells);
}

template <typename T> template <typename E> Grid<T> &Grid<T>::operator=(const Grid<E> &rhs)
{
    // Copy-and-swap idiom
    Grid<T> temp{rhs}; // Do all the work in a temporary instance.
    swap(temp);        // Commit the work with only non-throwing operations.
    return *this;
}
