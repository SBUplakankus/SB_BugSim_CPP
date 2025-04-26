//
// Created by tremo on 13/04/2025.
//

#ifndef BOARDDISPLAY_H
#define BOARDDISPLAY_H
#include <unordered_map>
#include <vector>
#include "../Bugs/Bug.h"
#include <SFML/Graphics.hpp>

#include "../Board/GameBoard.h"

using namespace std;
using namespace bugs;
using namespace sf;
using namespace board;

namespace graphics
{

class BoardDisplay
{
    private:
    int displayWidth = 1100;
    int displayHeight = 800;
    int menuWidth = 300;
    int buttonWidth = 250;
    int buttonHeight = 50;
    int buttonMargin = 20;

    string boardTitle = "Bug Sim";
    unordered_map<string, RectangleShape*> boardMap;
    vector<RectangleShape*> boardTiles;

    vector<Bug*> boardBugs;
    unordered_map<int, CircleShape*> bugCircleMap;

    int gridWidth;
    int gridHeight;
    RenderWindow* gameWindow;
    GameBoard* gameBoard;

    Color crawlerColor = Color::Blue;
    Color hopperColor = Color::Red;
    Color boardColor1 = Color(100,232,95, 255);
    Color boardColor2 = Color(100,242,115, 255);

    void createButtons(string buttonText, int posX, int posY);
    void displayBug(Bug *bug);

    public:
    void initBoardDisplay(const vector<Bug*> &bugs, GameBoard* &board,  const int gridX, const int gridY);
    void initBugCircles();
    void runDisplay();
    void updateBoardDisplay();
};

} // graphics

#endif //BOARDDISPLAY_H
