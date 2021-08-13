#include "Controller.h"
#include <exception>

Controller::Controller(Board *board, CLI *cli) {
    this->board = board;
    this->cli = cli;

    RegisterCommand("-h", "Shows available commands", std::bind(&Controller::OnHelpCommand, this, std::placeholders::_1));
    RegisterCommand("-help", "Shows available commands", std::bind(&Controller::OnHelpCommand, this, std::placeholders::_1));
}

void Controller::OnCommandEntered(std::string input) {
    std::tuple<std::string, std::vector<std::string>> command = ParseCommand(input);
    std::function<void(std::vector<std::string>)> handler;
    try {
        handler = std::get<1>(registeredCommands[std::get<0>(command)]);

        if (handler == nullptr)
            throw std::exception("Unregistered command");

        handler(std::get<1>(command));
    } catch (std::exception e) {
        printf("Error: %s", e.what());
    }
}

std::tuple<std::string, std::vector<std::string>> Controller::ParseCommand(std::string commandString) {
    std::istringstream iss(commandString);
    std::string tempString;
    std::string command = "";
    std::vector<std::string> arguments;
    while (std::getline(iss, tempString, ' ')) {
        if (command.length() > 0)
            arguments.push_back(tempString);
        else
            command = tempString;
    }
    return std::tuple<std::string, std::vector<std::string>>(command, arguments);
}

void Controller::RegisterCommand(std::string command, std::string explanation, std::function<void(std::vector<std::string>)> commandHandler) {
    registeredCommands.emplace(command, std::tuple<std::string, std::function<void(std::vector<std::string>)>>(explanation, commandHandler));
}

void Controller::OnHelpCommand(std::vector<std::string> arguments) {
    std::vector<std::tuple<std::string, std::string>> availableCommands;
    for (auto k : registeredCommands)
        availableCommands.push_back(std::tuple<std::string, std::string>(k.first, std::get<0>(k.second)));

    cli->DisplayHelp(availableCommands);
}

void Controller::Start() {
    cli->Start(std::bind(&Controller::OnCommandEntered, this, std::placeholders::_1));
}