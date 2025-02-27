#include <print>

int main()
{
    char board[3][3]{};
    board[0][0] = 'X'; // X puts marker in position (0,0).
    board[2][1] = 'O'; // O puts marker in position (2,1).
    std::println("{}", board[1][1]);
    std::println("{}", board[0][0]);
    std::println("{}", board[2][1]);
}
