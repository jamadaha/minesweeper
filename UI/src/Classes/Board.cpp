#include "Board.h"
#include <stdexcept>

Board::Board(int bombCount, int sizeX, int sizeY) {
    this->bombCount = bombCount;
    this->sizeX = sizeX;
    this->sizeY = sizeY;

    if (sizeX == 0 || sizeY == 0)
        throw std::invalid_argument("Both width and height of board must be bigger than 0.");
    board = new int[sizeX * sizeY];
}

int Board::GetSquare(int x, int y) {
    return board[x + y * sizeX];
}