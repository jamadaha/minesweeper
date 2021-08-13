#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Board.h"
#include "CLI.h"

#include <functional>
#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <sstream>
#include <iostream>

class Controller {
public:
    Controller(Board *board, CLI *cli);
    void OnCommandEntered(std::string input);

    void Start();

private:
    std::unordered_map<std::string, std::function<void(std::vector<std::string>)>> registeredCommands;
    Board *board;
    CLI *cli;

    void RegisterCommand(std::string command, std::function<void(std::vector<std::string>)> commandHandler);
    std::tuple<std::string, std::vector<std::string>> ParseCommand(std::string command);
    void OnHelpCommand(std::vector<std::string> arguments);
};

#endif