#include <print>

int
main ()
{
  {
    int myArray[3];
    myArray[0] = 0;
    myArray[1] = 0;
    myArray[2] = 0;
    std::println ("{}", sizeof (myArray) / sizeof (myArray[0]));
  }

  {
    int myArray[3] = { 0 };
    std::println ("{}", sizeof (myArray) / sizeof (myArray[0]));
  }

  {
    int myArray[3] = {};
    std::println ("{}", sizeof (myArray) / sizeof (myArray[0]));
  }

  {
    int myArray[3]{};
    std::println ("{}", sizeof (myArray) / sizeof (myArray[0]));
  }

  {
    int myArray[]{ 1, 2, 3, 4 };
    std::println ("{}", sizeof (myArray) / sizeof (myArray[0]));
  }

  {
    int         myArray[3]{ 2 };
    std::size_t arraySize1{ std::size (myArray) };
    std::size_t arraySize2{ sizeof (myArray) / sizeof (myArray[0]) };
    std::println ("{}", arraySize1);
    std::println ("{}", arraySize2);
  }

  {
    char ticTacToeBoard[3][3];
    ticTacToeBoard[1][1] = 'o';
    std::println ("ticTacToeBoard: {}", sizeof (ticTacToeBoard) / sizeof (ticTacToeBoard[0]));
    std::println ("ticTacToeBoard: {}", std::size (ticTacToeBoard));
  }
}
