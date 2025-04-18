#include <iostream>

#include "Board/CsvParser.h"
using namespace std;
using namespace board;

int main()
{
    cout << "Bug Sim" << endl;
    CsvParser parser;
    GameBoard* gameBoard = parser.getBugsFromCsv("../Files/bugs.csv");
    gameBoard->displayAllBugs();
    gameBoard->findBugById(2);
    for (int i = 0; i < 10; i++) {
        gameBoard->tapBoard();
    }
    gameBoard->displayBugsHistory();
    parser.writeBugHistoryToFile(gameBoard);
    return 0;
}