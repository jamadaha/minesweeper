#include "Board.h"
#include <stdexcept>
#include <stdlib.h>

Board::Board(int bombCount, int sizeX, int sizeY) {
    this->bombCount = bombCount;
    this->sizeX = sizeX;
    this->sizeY = sizeY;

    if (sizeX == 0 || sizeY == 0)
        throw std::invalid_argument("Both width and height of board must be bigger than 0.\n");
    board = new Square[sizeX * sizeY];
    revealedBoard = new bool[sizeX * sizeY] { false };
}

Board::Square Board::GetSquare(int x, int y) {
    if (x < 0 || y < 0)
        throw std::invalid_argument("Cannot get a negative coordinate.\n");
    if (x >= sizeX || y >= sizeY)
        throw std::invalid_argument("Coordinates out of bounds\n");
    return board[x + y * sizeX];
}

bool Board::GetRevealedSquare(int x, int y) {
    if (x < 0 || y < 0)
        throw std::invalid_argument("Cannot get a negative coordinate.\n");
    if (x >= sizeX || y >= sizeY)
        throw std::invalid_argument("Coordinates out of bounds\n");
    return revealedBoard[x + y * sizeX];
}

bool Board::RevealSquare(int x, int y) {
    if (x < 0 || y < 0)
        throw std::invalid_argument("Cannot get a negative coordinate.\n");
    if (x >= sizeX || y >= sizeY)
        throw std::invalid_argument("Coordinates out of bounds\n");
    if (GetRevealedSquare(x, y))
        throw std::invalid_argument("Square already revealed\n");

    SetRevealedSquare(true, x, y);

    if (GetSquare(x, y) == Square::Bomb)
        return true;
    else
        return false;
}

bool Board::SetRevealedSquare(bool state, int x, int y) {
    if (x < 0 || y < 0)
        throw std::invalid_argument("Cannot get a negative coordinate.\n");
    if (x >= sizeX || y >= sizeY)
        throw std::invalid_argument("Coordinates out of bounds\n");
    revealedBoard[x + y * sizeX] = state;
}

void Board::SetSquare(Board::Square square, int x, int y) {
    if (x < 0 || y < 0)
        throw std::invalid_argument("Cannot set a negative coordinate.\n");
    if (x >= sizeX || y >= sizeY)
        throw std::invalid_argument("Coordinates out of bounds\n");
    board[x + y * sizeX] = square;
}

void Board::Generate() {
    Clear();
    PlaceBombs();
}

void Board::Clear() {
    for (int x = 0; x < sizeX; x++)
            for (int y = 0; y < sizeY; y++) {
                SetRevealedSquare(false, x, y);
                SetSquare(Board::Square::Empty, x, y);
            }
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