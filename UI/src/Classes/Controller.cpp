#include "Controller.h"
#include <exception>

Controller::Controller(Board *board, CLI *cli) {
    this->board = board;
    this->cli = cli;

    RegisterCommand("-h", std::bind(&Controller::OnHelpCommand, this, std::placeholders::_1));
    RegisterCommand("-help", std::bind(&Controller::OnHelpCommand, this, std::placeholders::_1));
}

void Controller::OnCommandEntered(std::string input) {
    std::tuple<std::string, std::vector<std::string>> command = ParseCommand(input);
    std::function<void(std::vector<std::string>)> handler;
    try {
        handler = registeredCommands[std::get<0>(command)];
        
        if (handler == nullptr)
            throw std::exception("Unregistered command");

        handler(std::get<1>(command));
    } catch (std::exception e) {
        printf("Error: %s", e.what());
    }
    
    //printf("%s, %s\n", std::get<0>(command).c_str(), std::get<1>(command)[0].c_str());
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

void Controller::RegisterCommand(std::string command, std::function<void(std::vector<std::string>)> commandHandler) {
    registeredCommands.emplace(command, commandHandler);
}

void Controller::OnHelpCommand(std::vector<std::string> arguments) {
    printf("Ehh..\n");
}

void Controller::Start() {
    cli->Start(std::bind(&Controller::OnCommandEntered, this, std::placeholders::_1));
}