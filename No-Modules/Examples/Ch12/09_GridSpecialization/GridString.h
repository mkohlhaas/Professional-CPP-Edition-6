#pragma once

#include "Grid.h"
#include <string>

using namespace std;

template <> class Grid<const char *>
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

    optional<string>       &at(size_t x, size_t y);
    const optional<string> &at(size_t x, size_t y) const;

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

    vector<optional<string>> m_cells;
    size_t                   m_width{0}, m_height{0};
};
