#include <print>
#include <utility>

using namespace std;

enum class PieceType
{
  King = 1,
  Queen,
  Rook = 10,
  Pawn
};

int
main ()
{
  {
    PieceType piece{ PieceType::King };

    auto underlyingValue{ to_underlying (piece) };
    println ("{}", underlyingValue);
  }

  {
    using PieceType::King;
    PieceType piece{ King };
    piece = PieceType::Queen;
    println ("{}", sizeof (piece));
  }

  {
    using enum PieceType;
    PieceType piece{ King };
    println ("{}", sizeof (piece));
  }
}
