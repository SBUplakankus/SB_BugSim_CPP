#include <iostream>
#include "Board/CsvParser.h"
#include "Graphics/BoardDisplay.h"

using namespace std;
using namespace board;
using namespace graphics;

int main()
{
    cout << "Bug Sim" << endl;
    CsvParser parser;
    GameBoard* gameBoard = parser.getBugsFromCsv("../Files/bugs.csv");
    BoardDisplay gameDisplay;


    gameBoard->displayAllBugs();
    gameBoard->findBugById(2);
    gameBoard->displayCellInfo();
    gameDisplay.initBoardDisplay(gameBoard->getBugs(), gameBoard, gameBoard->getBoardWidth(), gameBoard->getBoardHeight());

    for (int i = 0; i < 10; i++)
    {
        gameBoard->tapBoard();
    }
    gameBoard->displayBugsHistory();
    parser.writeBugHistoryToFile(gameBoard);
    return 0;
}