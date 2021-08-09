#ifndef BOARD_H
#define BOARD_H

class Board {
    public:
    enum Square {
        None,
        Empty,
        Bomb  
    };
    
    Board(int bombCount, int sizeX, int sizeY);

    Square GetSquare(int x, int y);
    
    void Generate();

    private:
    int bombCount;
    int sizeX;
    int sizeY;
    Square *board;

    void SetSquare(Square square, int x, int y);

    void Clear();
    void PlaceBombs();
};

#endif