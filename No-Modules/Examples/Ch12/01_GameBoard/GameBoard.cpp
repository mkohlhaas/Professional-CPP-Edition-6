#include "GameBoard.h"
#include <format>
#include <print>
#include <stdexcept>
#include <utility>

using namespace std;

GameBoard::GameBoard(size_t width, size_t height) : m_width{width}, m_height{height}, m_cells(m_width * m_height)
{
    std::println("Size of vector: {}", m_cells.size());
}

GameBoard::GameBoard(const GameBoard &src) : GameBoard{src.m_width, src.m_height}
{
    // copy the data
    for (size_t i{0}; i < m_cells.size(); ++i)
    {
        if (src.m_cells[i])
        {
            m_cells[i] = src.m_cells[i]->clone();
        }
    }
}

void GameBoard::verifyCoordinate(size_t x, size_t y) const
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

void GameBoard::swap(GameBoard &other) noexcept
{
    std::swap(m_width, other.m_width);
    std::swap(m_height, other.m_height);
    std::swap(m_cells, other.m_cells);
}

void swap(GameBoard &first, GameBoard &second) noexcept
{
    first.swap(second);
}

GameBoard &GameBoard::operator=(const GameBoard &rhs)
{
    // copy-and-swap idiom
    GameBoard temp{rhs};
    swap(temp);
    return *this;
}

const pGamePiece &GameBoard::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return m_cells[x + y * m_width];
}

pGamePiece &GameBoard::at(size_t x, size_t y)
{
    return const_cast<pGamePiece &>(as_const(*this).at(x, y));
}
