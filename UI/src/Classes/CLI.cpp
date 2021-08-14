#include "CLI.h"

// Game related
void CLI::DisplayBoard(Board board) {
    for (int y = board.sizeY - 1; y >= 0; y--) {
        for (int x = 0; x < board.sizeX; x++) {
            if (board.GetRevealedSquare(x, y))
                std::cout << board.GetSquare(x, y);
            else
                std::cout << '-';
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}

void CLI::DisplayGameOver() {
    std::cout << "You picked a bomb\n" << "Game Over!\n";
}

// Command related
void CLI::DisplayHelp(std::vector<std::tuple<std::string, std::string>> allowedCommands) {
    printf("Available commands:\n");
    for (int i = 0; i < allowedCommands.capacity(); i++) 
        printf("%s | %s\n", std::get<0>(allowedCommands[i]).c_str(), std::get<1>(allowedCommands[i]).c_str());
}

void CLI::Start(std::function<void(std::string)> onCommand) {
    std::string input;
    while (1) {
        std::getline (std::cin, input);
        onCommand(input);
    }
}