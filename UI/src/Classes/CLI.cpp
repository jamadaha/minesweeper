#include "CLI.h"

// Game related
void CLI::DisplayBoard(Board board) {

}

// Command related
void CLI::DisplayHelp(std::vector<std::string> allowedCommands) {
    printf("Available commands:\n");
    for (int i = 0; i < allowedCommands.capacity(); i++) 
        printf("%s\n", allowedCommands[i].c_str());
}

void CLI::Start(std::function<void(std::string)> onCommand) {
    std::string input;
    while (1) {
        std::getline (std::cin, input);
        onCommand(input);
    }
}