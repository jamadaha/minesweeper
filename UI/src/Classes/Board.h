#ifndef BOARD_H
#define BOARD_H

class Board {
    public:
    Board(int bombCount, int sizeX, int sizeY);

    int GetSquare(int x, int y);
    void Generate();

    private:
    int bombCount;
    int sizeX;
    int sizeY;
    int *board;

    void PlaceBombs();
};

#endif