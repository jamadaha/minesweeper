#include <stdexcept>
#include <string>
#include <stdlib.h>
#include <sstream>

#include <vector>
#include <functional>

#include "./../src/Classes/Controller.h"

class TestHandler {
    public:
    Controller *controller;
    std::string command;
    std::string explanation;
    TestHandler(std::string command) {
        controller = new Controller(nullptr, nullptr);
        this->command = command;
        this->explanation = "";

        controller->RegisterCommand(command, explanation, std::bind(&TestHandler::TestCommand, this, std::placeholders::_1));
    }
    void TestCommand(std::vector<std::string> arguments) {

    }
};



int main(int argc, char* argv[]) {
    std::stringstream ss;
    auto old_buf = std::cout.rdbuf(ss.rdbuf());

    TestHandler handler = TestHandler(argv[2]);

    handler.controller->OnCommandEntered(argv[3]);

    std::cout.rdbuf(old_buf);
    std::string result = ss.str();

    if (std::atoi(argv[1])) {
        if (result.length() > 0) {
            exit(EXIT_SUCCESS);
        } else {
            printf("Expected an exception, yet test went through anyway.");
            exit(EXIT_FAILURE);
        }
    } else {
        if (result.length() > 0) {
            printf("Unexpected exception: %s\n", result);
            exit(EXIT_FAILURE);
        } else {
            exit(EXIT_SUCCESS);
        }
    }
}