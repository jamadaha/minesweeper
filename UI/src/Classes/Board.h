#ifndef BOARD_H
#define BOARD_H

class Board {
    public:
    enum Square {
        None,
        Empty,
        Bomb  
    };

    int sizeX;
    int sizeY;
    

    Board(int bombCount, int sizeX, int sizeY);

    Square GetSquare(int x, int y);
    bool GetRevealedSquare(int x, int y);

    // returns true on bomb
    bool RevealSquare(int x, int y);

    void Generate();

    private:
    int bombCount;
    Square *board;
    bool *revealedBoard;

    void SetRevealedSquare(bool state, int x, int y);
    void SetSquare(Square square, int x, int y);

    void Clear();
    void PlaceBombs();
};

#endif