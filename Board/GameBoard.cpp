//
// Created by tremo on 13/04/2025.
//

#include "GameBoard.h"

namespace board {

    GameBoard::GameBoard(const int width, const int height, const vector<Bug *> &bugs) {
        this->boardWidth = width;
        this->boardHeight = height;
        this->boardBugs = bugs;
        this->boardCells = initBoard(boardBugs);
    }

    int GameBoard::getBoardWidth() const {
        return this->boardWidth;
    }

    int GameBoard::getPositionKey(const Position &pos) {
        return pos.x * 100 + pos.y;
    }

    unordered_map<int, vector<Bug*>> GameBoard::initBoard(const vector<Bug*> &bugs) {
        unordered_map<int, vector<Bug*>> boardCells;
        for (auto bug: bugs) {
            int key = getPositionKey(bug->getPosition());
            boardCells[key].push_back(bug);
        }
        return boardCells;
    }

} // board