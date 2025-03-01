#pragma once

#include <cstddef>
#include <memory>
#include <vector>

using namespace std;

class GamePiece;
using pGamePiece = unique_ptr<GamePiece>;

class GamePiece
{
  public:
    virtual ~GamePiece()             = default;
    virtual pGamePiece clone() const = 0;
};

class GameBoard
{
  public:
    static constexpr size_t DefaultWidth{10};
    static constexpr size_t DefaultHeight{10};

    explicit GameBoard(size_t width = DefaultWidth, size_t height = DefaultHeight);
    GameBoard(const GameBoard &src);                 // copy constructor
    virtual ~GameBoard() = default;                  // virtual defaulted destructor
    GameBoard &operator=(const GameBoard &rhs);      // assignment operator
    GameBoard(GameBoard &&src)            = default; // Explicitly default a move constructor...
    GameBoard &operator=(GameBoard &&src) = default; // ...and move assignment operator.

    pGamePiece       &at(size_t x, size_t y);
    const pGamePiece &at(size_t x, size_t y) const;

    size_t getHeight() const
    {
        return m_height;
    }

    size_t getWidth() const
    {
        return m_width;
    }

    void swap(GameBoard &other) noexcept;

  private:
    void               verifyCoordinate(size_t x, size_t y) const;
    size_t             m_width{0};
    size_t             m_height{0};
    vector<pGamePiece> m_cells;
};

void swap(GameBoard &first, GameBoard &second) noexcept;
