#include "Command.h"

#include <stdexcept>


Command::Command(std::string command) {
    if (command.length() == 0)
        throw std::invalid_argument("No command written");
    if (command[0] == ' ')
        throw std::invalid_argument("No leading whitespace in commands");

    // 0 - Command
    // 1 - Option
    // 2 - Argument
    int type = 0;
    for (int i = 0; i < command.length(); i++) {
        switch (type)
        {
        case 0:
            if (command[i] == ' ')
                type++;
            else
                this->command += command[i];
            break;
        
        case 1:
            if (command[i] == ' ')
                break;
            if (command[i] != '-') {
                type++;
                i--;
            } else if (command.length() == i)
                return;
            else {
                std::string option = "";
                int ii = 1;
                // check for command - option
                if (command[i + ii] == ' ')
                    throw std::invalid_argument("No spaces between dash and option");

                while (i + ii < command.length() && command[i + ii] != ' ') {
                    option += command[i + ii];
                    ii++;
                }
                    
                this->options.push_back(option);
                i += ii;
            }
            break;

        case 2:
            if (i == command.length())
                return;
            
            // check for command argument -option
            if (command[i] == '-')
                throw std::invalid_argument("No dash in argument");

            if (command[i] != ' ') {
                std::string argument = "";
                int ii = 1;
                while (i + ii < command.length() && command[i + ii] != ' ') {
                    argument += command[i + ii];
                    ii++;
                }
                    
                this->arguments.push_back(argument);
            }
            break;

        default:
            throw std::logic_error("Unreachable code.");
            break;
        }
    }
}

Command::Command(std::string command, std::vector<std::string> options, std::vector<std::string> arguments) {
    this->command = command;
    this->options = options;
    this->arguments = arguments;
}