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
    unordered_map<string, vector<Bug*>> boardCells;
    static string getPositionKey(const Position &pos);

    public:
    GameBoard(const int width, const int height, const vector<Bug*> &bugs);

    static unordered_map<string, vector<Bug*>> initBoard(const vector<Bug*> &bugs);
    int getBoardWidth() const;
    int getBoardHeight() const;
    void displayAllBugs() const;
    void tapBoard();
    void findBugById(const int bugId);

    static void fightBugs(Bug* &bug1, Bug* &bug2);
    void displayBugsHistory() const;
    string getBugsHistory() const;
    vector<Bug*> getBugs() const;
    void displayCellInfo();
    bool isCellEmpty(const string &key);
};

} // board

#endif //GAMEBOARD_H
