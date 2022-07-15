#include <stdexcept>
#include <string>
#include <stdlib.h>

#include "./../../src/Classes/Board.h"

int main(int argc, char* argv[]) {
    try {
        Board board = Board(std::atoi(argv[2]), std::atoi(argv[3]), std::atoi(argv[4]));
        board.GetSquare(std::atoi(argv[5]), std::atoi(argv[6]));
    } catch (const std::exception& e) {
        if (!std::atoi(argv[1]))
            throw e;
        else
            exit(EXIT_SUCCESS);
    }
    if (std::atoi(argv[1]))
        throw std::logic_error("Expected an exception, yet test went through anyway.");
    else
        exit(EXIT_SUCCESS);
}