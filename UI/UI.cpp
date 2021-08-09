// Attempts to follow the GNU coding conventions for command line arguments http://www.gnu.org/prep/standards/standards.html#Command_002dLine-Interfaces





#include "UI.h"

#include "iostream"
#include "string"

UI::UI() {
    std::cout << "What\n";
    std::string input;
    std::cin >> input;
    std::cout << input;
}
