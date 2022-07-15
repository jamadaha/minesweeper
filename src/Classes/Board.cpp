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
    if (IsOutOfBounds(x, y))
        throw std::invalid_argument("Coordinates out of bounds\n");
    return board[x + y * sizeX];
}

bool Board::GetRevealedSquare(int x, int y) {
    if (IsOutOfBounds(x, y))
        throw std::invalid_argument("Coordinates out of bounds\n");
    return revealedBoard[x + y * sizeX];
}

int Board::GetNeighbourBombCount(int x, int y) {
    int neighbourCount = 0;
    for (int xOffset = -1; xOffset <= 1; xOffset ++) {
        for (int yOffset = -1; yOffset <= 1; yOffset ++) {
            if (xOffset == 0 && yOffset == 0)
                continue;
            if (IsOutOfBounds(x + xOffset, y + yOffset))
                continue;

            if (GetSquare(x + xOffset, y + yOffset) == Square::Bomb)
                neighbourCount++;
        }
    }
    return neighbourCount;
}

bool Board::RevealSquare(int x, int y) {
    if (IsOutOfBounds(x, y))
        throw std::invalid_argument("Coordinates out of bounds\n");
    if (GetRevealedSquare(x, y))
        throw std::invalid_argument("Square already revealed\n");

    SetRevealedSquare(true, x, y);

    if (GetSquare(x, y) == Square::Bomb)
        return true;
    else if (GetNeighbourBombCount(x, y) == 0)
        RevealNeighbours(x, y);

    return false;
}

bool Board::IsOutOfBounds(int x, int y) {
    if (x < 0 || y < 0)
        return true;
    if (x >= sizeX || y >= sizeY)
        return true;
    return false;
}

void Board::SetRevealedSquare(bool state, int x, int y) {
    if (IsOutOfBounds(x, y))
        throw std::invalid_argument("Coordinates out of bounds\n");
    revealedBoard[x + y * sizeX] = state;
}

void Board::SetSquare(Board::Square square, int x, int y) {
    if (IsOutOfBounds(x, y))
        throw std::invalid_argument("Coordinates out of bounds\n");
    board[x + y * sizeX] = square;
}

void Board::Generate() {
    Clear();
    PlaceBombs();
}

void Board::RevealNeighbours(int x, int y) {
    for (int xOffset = -1; xOffset <= 1; xOffset ++) {
        for (int yOffset = -1; yOffset <= 1; yOffset ++) {
            if (xOffset == 0 && yOffset == 0)
                continue;
            if (IsOutOfBounds(x + xOffset, y + yOffset))
                continue;

            if (!GetRevealedSquare(x + xOffset, y + yOffset))
                RevealSquare(x + xOffset, y + yOffset);
        }
    }
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