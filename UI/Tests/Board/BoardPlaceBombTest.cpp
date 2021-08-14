#include <stdexcept>
#include <string>
#include <stdlib.h>

#include "./../src/Classes/Board.h"

int main(int argc, char* argv[]) {
    Board board = Board(std::atoi(argv[1]), std::atoi(argv[2]), std::atoi(argv[3]));
    board.Generate();
    int bombCount = 0;
    for (int x = 0; x < std::atoi(argv[2]); x++)
        for (int y = 0; y < std::atoi(argv[3]); y++)
            if (board.GetSquare(x, y) == Board::Square::Bomb)
                bombCount++;
    if (bombCount == std::atoi(argv[1]))
        exit(EXIT_SUCCESS);
    else
        exit(EXIT_FAILURE);
}