#include "CommandHandler.h"

void CommandHandler::AddCommand(std::string command) {
    this->commands.push_back(Command(command));
};

