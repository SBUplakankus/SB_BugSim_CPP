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
    unordered_map<pair<int,int>, vector<Bug*>> boardCells;

    public:
    void initBoard();
};

} // board

#endif //GAMEBOARD_H
