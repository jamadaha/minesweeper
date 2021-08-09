#include <stdexcept>
#include <string>

#include "./../Command.cpp"

int main(int argc, char* argv[]) {
    std::string inputString = argv[2];
    try {
        Command{inputString};
    } catch (std::exception e) {
        if (!std::atoi(argv[1]))
            throw e;
        else
            exit(EXIT_SUCCESS);
    }
    if (std::atoi(argv[1]))
        throw std::logic_error("Expected an exception, yet test went through anyway.");
    else
        exit(EXIT_SUCCESS);
}