#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <string>
#include <unordered_map>

class CommandHandler {
    public:
    void AddCommand(std::string );
    void AddCommand(std::unordered_map<std::string, std::string> commands);


    void ParseCommand(std::string command);

    private:
    std::unordered_map<std::string, std::string> commands;
};

#endif