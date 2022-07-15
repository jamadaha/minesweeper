#ifndef CLI_H
#define CLI_H

#include "Board.h"
#include <functional>
#include <vector>
#include <string>
#include <iostream>

class CLI {
    public:
    // Game related
    void DisplayBoard(Board board);
    void DisplayGameOver();
    
    // Command related
    void DisplayHelp(std::vector<std::tuple<std::string, std::string>> allowedCommands);

    void Start(std::function<void(std::string)> onCommand);
};

#endif