#include <iostream>

#include "Board/CsvParser.h"
using namespace std;
using namespace board;

int main() {
    cout << "Bug Sim" << endl;
    CsvParser parser;
    const GameBoard* gameBoard = parser.getBugsFromCsv("../Files/bugs.csv");
    cout << gameBoard->getBoardWidth() << endl;

    return 0;
}