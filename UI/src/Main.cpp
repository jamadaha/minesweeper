#include <stdlib.h>
#include <stdio.h>
#include "Classes/Board.h"
#include "Classes/UI.h"
#include "Classes/CommandHandler.h"
 
int main(int argc, char *argv[]) {
    srand(0);
    Board board = Board(5, 16, 16);
    board.Generate();
    UI ui = UI(16, 16);
    ui.Display(board);
    CommandHandler handler = CommandHandler();
    while (1) {
        
    }
}