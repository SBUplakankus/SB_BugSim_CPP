//
// Created by tremo on 13/04/2025.
//

#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <string>
#include <unordered_map>
#include <vector>

#include "../Bugs/Bug.h"

using namespace std;
using namespace bugs;

namespace board
{

class GameBoard
{
    private:
    int boardWidth;
    int boardHeight;
    vector<Bug*> boardBugs;
    unordered_map<int, vector<Bug*>> boardCells;
    static int getPositionKey(const Position &pos);

    public:
    GameBoard(const int width, const int height, const vector<Bug*> &bugs);

    static unordered_map<int, vector<Bug*>> initBoard(const vector<Bug*> &bugs);
    int getBoardWidth() const;
    void displayAllBugs() const;
    void tapBoard();
    void findBugById(const int bugId);

    static void fightBugs(Bug* &bug1, Bug* &bug2);
    void displayBugsHistory() const;
};

} // board

#endif //GAMEBOARD_H
