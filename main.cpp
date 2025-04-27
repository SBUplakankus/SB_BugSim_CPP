#include <iostream>
#include "Board/CsvParser.h"
#include "Graphics/BoardDisplay.h"

using namespace std;
using namespace board;
using namespace graphics;

int main()
{
    cout << "Welcome to the Bug Sim" << endl;
    CsvParser parser;
    GameBoard* gameBoard;
    BoardDisplay gameDisplay;
    bool appRunning = true;
    bool gameBoardReady = false;
    int userInput;

    while (appRunning)
    {
        cout << "---------- Please select an Option -----------" << endl;
        cout << "1: Initialize Bug Board" << endl << "2: Display all Bugs" << endl << "3: Find a Bug by ID" << endl <<
        "4: Run Bug Simulation" << endl << "5: Display Life History of all Bugs" << endl << "6: Display Cell Info" <<
            endl << "7: Exit" << endl;

        cin >> userInput;

        switch (userInput)
        {
            case 1:
                gameBoard = parser.getBugsFromCsv("../Files/bugs.csv");
                gameBoardReady = true;
                cout << "Bug Board Initialized" << endl;
                break;
            case 2:
                if (gameBoardReady)
                {
                    gameBoard->displayAllBugs();
                }
                else {cout << "Bug Board Not Yet Initialized" << endl;}
                break;
            case 3:
                if (gameBoardReady)
                    {
                    cout << "Please enter a bug ID" << endl;
                    int bugID;
                    cin >> bugID;
                    gameBoard->findBugById(bugID);
                }
                else {cout << "Bug Board Not Yet Initialized" << endl;}
                break;
            case 4:
                if (gameBoardReady)
                {
                    cout << "Press 'Space' to progress the sim" << endl;
                    gameDisplay.initBoardDisplay(gameBoard->getBugs(), gameBoard, gameBoard->getBoardWidth(), gameBoard->getBoardHeight());
                }
                else {cout << "Bug Board Not Yet Initialized" << endl;}
                break;
            case 5:
                if (gameBoardReady)
                {
                    gameBoard->displayBugsHistory();
                }
                else {cout << "Bug Board Not Yet Initialized" << endl;}
                break;
            case 6:
                if (gameBoardReady)
                {
                    gameBoard->displayCellInfo();
                }
                else {cout << "Bug Board Not Yet Initialized" << endl;}
                break;
            case 7:
                appRunning = false;
                cout << "Exiting Application" << endl;
                break;
            default:
                cout << "Invalid Option, Please Try Again." << endl;
                break;
        }

        if (gameBoardReady)
        {
            parser.writeBugHistoryToFile(gameBoard);
        }
    }
    return 0;
}