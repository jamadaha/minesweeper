#include "UI.h"

#include "iostream"
#include "string"

UI::UI(int x, int y) {
    sizeX = x;
    sizeY = y;
    revealedSquares = new bool[sizeX * sizeY] {false};
}

void UI::DisplaySquareType(Board board) {
    for (int x = 0; x < board.sizeX; x++) {
        for (int y = 0; y < board.sizeY; y++) {
            printf("%d ", static_cast<int>(board.GetSquare(x, y)));
        }
        printf("\n");
    }
}

void UI::Display(Board board) {
    for (int x = 0; x < board.sizeX; x++) {
        for (int y = 0; y < board.sizeY; y++) {
            if (!revealedSquares[x + y * sizeX])
                printf("- ");
            else
                printf("%d ", static_cast<int>(board.GetSquare(x, y)));
        }
        printf("\n");
    }
}
