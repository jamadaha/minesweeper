#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

class Command {
    public:
    // assumes spaces as seperator
    Command(std::string command);
    Command(std::string command, std::vector<std::string> options, std::vector<std::string> arguments);

    private:
    std::string command = "";
    std::vector<std::string> options;
    std::vector<std::string> arguments;
};

#endif