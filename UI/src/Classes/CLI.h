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
    // Command related
    void DisplayHelp(std::vector<std::string> allowedCommands);

    void Start(std::function<void(std::string)> onCommand);
};

#endif