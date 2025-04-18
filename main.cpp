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
    return 0;
}