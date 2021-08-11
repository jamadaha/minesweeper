#ifndef UI_H
#define UI_H

#include "Board.h"

class UI {
    public:
    UI(int x, int y);
    void DisplaySquareType(Board board);
    void Display(Board board);
    void Clear();
    void RevealSquare(int x, int y);

    private:
    int sizeX;
    int sizeY;
    bool *revealedSquares;

};

#endif