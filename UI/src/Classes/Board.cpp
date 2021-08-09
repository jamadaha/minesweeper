#include "Board.h"
#include <stdexcept>
#include <stdlib.h>

Board::Board(int bombCount, int sizeX, int sizeY) {
    this->bombCount = bombCount;
    this->sizeX = sizeX;
    this->sizeY = sizeY;

    if (sizeX == 0 || sizeY == 0)
        throw std::invalid_argument("Both width and height of board must be bigger than 0.");
    board = new Square[sizeX * sizeY];
}

Board::Square Board::GetSquare(int x, int y) {
    if (x < 0 || y < 0)
        throw std::invalid_argument("Cannot get a negative coordinate.");
    if (x >= sizeX || y >= sizeY)
        throw std::invalid_argument("Coordinates out of bounds");
    return board[x + y * sizeX];
}

void Board::SetSquare(Board::Square square, int x, int y) {
    if (x < 0 || y < 0)
        throw std::invalid_argument("Cannot set a negative coordinate.");
    if (x >= sizeX || y >= sizeY)
        throw std::invalid_argument("Coordinates out of bounds");
    board[x + y * sizeX] = square;
}

void Board::Generate() {
    Clear();
    PlaceBombs();
}

void Board::Clear() {
    for (int x = 0; x < sizeX; x++)
            for (int y = 0; y < sizeY; y++) 
                SetSquare(Board::Square::Empty, x, y);
}

void Board::PlaceBombs() {
    int placedBombCount = 0;
    while (placedBombCount < bombCount) {
        int ranX = rand() % sizeX;
        int ranY = rand() % sizeY;
        if (GetSquare(ranX, ranY) == Board::Square::Empty) {
            SetSquare(Board::Square::Bomb, ranX, ranY);
            placedBombCount++;
        }
    }
}