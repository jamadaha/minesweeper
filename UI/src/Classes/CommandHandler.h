#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "Command.h"

#include <string>
#include <vector>

class CommandHandler {
    public:
    void AddCommand(std::string );
    void AddCommand(std::vector<Command> commands);


    void ParseInput(std::string Input);

    private:
    std::vector<Command> commands;
};

#endif