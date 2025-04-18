//
// Created by tremo on 13/04/2025.
//

#include "GameBoard.h"

#include <iostream>
#include <ostream>

namespace board {

    GameBoard::GameBoard(const int width, const int height, const vector<Bug *> &bugs)
    {
        this->boardWidth = width;
        this->boardHeight = height;
        this->boardBugs = bugs;
        this->boardCells = initBoard(boardBugs);
    }

    int GameBoard::getBoardWidth() const
    {
        return this->boardWidth;
    }

    int GameBoard::getBoardHeight() const
    {
        return this->boardHeight;
    }

    string GameBoard::getPositionKey(const Position &pos)
    {
        return pos.toString();
    }

    unordered_map<string, vector<Bug*>> GameBoard::initBoard(const vector<Bug*> &bugs)
    {
        unordered_map<string, vector<Bug*>> boardCells;
        for (auto bug: bugs)
        {
            string key = getPositionKey(bug->getPosition());
            boardCells[key].push_back(bug);
        }
        return boardCells;
    }

    void GameBoard::displayAllBugs() const
    {
        cout << "Displaying bugs in the game." << endl;
        for (const auto bug: boardBugs)
        {
            cout << bug->toString() << endl;
        }
    }

    void GameBoard::tapBoard()
    {
        for (const auto bug: boardBugs)
        {
            if (bug->getIsAlive())
            {
                // Clear the old position vector
                string key = getPositionKey(bug->getPosition());
                boardCells[key].clear();

                // Move to bug and add to the new position vector
                bug->move(boardWidth, boardHeight);
                key = getPositionKey(bug->getPosition());
                boardCells[key].push_back(bug);

                // If there is more than 1 bug on the vector start a fight
                if (boardCells[key].size() > 1)
                {
                    fightBugs(boardCells[key].at(0), boardCells[key].at(1));
                    // https://www.w3schools.com/cpp/cpp_conditions_shorthand.asp Ternary Operator in C++
                    Bug *winningBug = boardCells[key].at(0)->getIsAlive() ? boardCells[key].at(0) : boardCells[key].at(1);
                    boardCells[key].clear();
                    boardCells[key].push_back(winningBug);
                }
            }
        }
    }

    void GameBoard::fightBugs(Bug *&bug1, Bug *&bug2) {
        const int bug1Size = bug1->getSize();
        const int bug2Size = bug2->getSize();

        if (bug1Size > bug2Size)
        {
            bug1->growBug(bug2Size);
            bug2->setIsAlive(false);
            bug2->setEatenBy(bug1->getId());
            // cout << "Bug " + to_string(bug1->getId()) + " ate " + to_string(bug2->getId()) << endl;
        }
        else if (bug2Size > bug1Size)
        {
            bug2->growBug(bug1Size);
            bug1->setIsAlive(false);
            bug1->setEatenBy(bug2->getId());
            // cout << "Bug " + to_string(bug2->getId()) + " ate " + to_string(bug1->getId()) << endl;
        }
        else
        {
            if (const int rng = rand() % 2; rng == 1)
            {
                bug1->growBug(bug2Size);
                bug2->setIsAlive(false);
                bug2->setEatenBy(bug1->getId());
                // cout << "Bug " + to_string(bug1->getId()) + " ate " + to_string(bug2->getId()) << endl;
            }
            else
            {
                bug2->growBug(bug1Size);
                bug1->setIsAlive(false);
                bug1->setEatenBy(bug2->getId());
                // cout << "Bug " + to_string(bug2->getId()) + " ate " + to_string(bug1->getId()) << endl;
            }
        }
    }


    void GameBoard::findBugById(const int bugId)
    {
        bool bugFound = false;
        for (const auto bug: boardBugs)
        {
            if (bug->getId() == bugId)
            {
                bugFound = true;
                cout << "Bug " + to_string(bugId) + " found." << endl;
                cout << bug->toString() << endl;
            }
        }
        if (!bugFound)
        {
            cout << "Bug " + to_string(bugId) + " not found." << endl;
        }
    }

    void GameBoard::displayBugsHistory() const
    {
        for (const auto bug: boardBugs)
        {
            cout << bug->historyToString() << endl;
        }
    }

    string GameBoard::getBugsHistory() const
    {
        string bugHistory;
        for (const auto bug: boardBugs)
        {
            bugHistory += bug->historyToString() + "\n";
        }
        return bugHistory;
    }

    void GameBoard::displayCellInfo(){
        for (int i = 0; i < boardWidth; i++) {
            for (int j = 0; j < boardHeight; j++) {
                Position pos(i, j);
                if (string key = getPositionKey(pos); isCellEmpty(key)) {
                    cout << pos.toString() + ", Empty" << endl;
                }
                else {
                    const auto bug = boardCells[key].at(0);
                    cout << pos.toString() + ", " + bug->getBugType() + " " + to_string(bug->getId()) << endl;
                }
            }
        }
    }

    bool GameBoard::isCellEmpty(const string &key) {
        bool empty = true;
        if (const int count = boardCells[key].size(); count > 0) {
            empty = false;
        }
        return empty;
    }


} // board