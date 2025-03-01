#pragma once

#include "Grid.h"

template <typename T> class GameBoard : public Grid<T>
{
  public:
    // Inherit constructors from Grid<T>.
    using Grid<T>::Grid;

    void move(size_t xSrc, size_t ySrc, size_t xDest, size_t yDest);
};

template <typename T> void GameBoard<T>::move(size_t xSrc, size_t ySrc, size_t xDest, size_t yDest)
{
    Grid<T>::at(xDest, yDest) = std::move(Grid<T>::at(xSrc, ySrc));
    Grid<T>::at(xSrc, ySrc).reset(); // Reset source cell

    // Or:
    // this->at(xDest, yDest) = move(this->at(xSrc, ySrc));
    // this->at(xSrc, ySrc).reset();
}
