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
    // Set it up to have a menu panel to the side but didn't end up doing any buttons so it's set to 0

    private:
    int displayWidth = 900;
    int displayHeight = 900;
    int menuWidth = 0;
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
    Color drinkerColor = Color::Yellow;
    Color boardColor1 = Color(100,232,95, 255);
    Color boardColor2 = Color(100,242,115, 255);
    
    void createButtons(string buttonText, int posX, int posY);
    void displayBug(Bug *bug);

    public:

    /**
     * Initiate the graphical display of the board
     * @param bugs Reference to the vector of bugs from the board
     * @param board Reference to the game board containing the sim logic
     * @param gridX Size of the boards X Axis
     * @param gridY Size of the boards Y Axis
     */
    void initBoardDisplay(const vector<Bug*> &bugs, GameBoard* &board,  int gridX, int gridY);

    /**
     * Create the graphical circles for the bugs
     */
    void initBugCircles();

    /**
     * Run the graphical display
     */
    void runDisplay();

    /**
     * Update the positioning of the bugs on the board
     */
    void updateBoardDisplay();
};

} // graphics

#endif //BOARDDISPLAY_H
