#include "GameBoard.h"
#include <memory>
#include <print>
#include <utility>

using namespace std;

class ChessPiece : public GamePiece
{
  public:
    pGamePiece clone() const override
    {
        // Call the copy constructor to copy this instance
        return make_unique<ChessPiece>(*this);
    }
};

void processGameBoard(const GameBoard &board)
{
    const pGamePiece &pawn [[maybe_unused]]{board.at(0, 0)};
    println("Size of board: {}", board.getWidth() * board.getHeight());

    // doesn't compile:
    // board.at(1, 2) = std::make_unique<ChessPiece>();
}

int main()
{
    GameBoard chessBoard{8, 8};
    auto      pawn{make_unique<ChessPiece>()};

    chessBoard.at(0, 0) = std::move(pawn);
    chessBoard.at(0, 1) = make_unique<ChessPiece>();
    chessBoard.at(0, 1) = nullptr;

    // GameBoard board2;         // size of board: 100
    GameBoard board2{2, 2};       // size of board: 4
    board2 = chessBoard;          // size of board: 64
    processGameBoard(board2);     // "64"
    processGameBoard(chessBoard); // "64"
}
