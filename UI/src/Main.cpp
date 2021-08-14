#include <stdlib.h>
#include <stdio.h>
#include "Classes/Board.h"
#include "Classes/CLI.h"
#include "Classes/Controller.h"

int main(int argc, char *argv[]) {
    srand(0);
    Board board = Board(32, 8, 8);
    CLI cli = CLI();
    Controller controller = Controller(&board, &cli);
    controller.InitCommands();
    controller.Start();
}