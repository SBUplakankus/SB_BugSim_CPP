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

    /**
     * Turn the position into a string so it can be used as a key for unordered maps
     * @param pos Position to Retrieve the Key From
     * @return A String containing the positions details
     */
    static string getPositionKey(const Position &pos);

    public:
    GameBoard(int width, int height, const vector<Bug*> &bugs);
    int getBoardWidth() const;
    int getBoardHeight() const;
    vector<Bug*> getBugs() const;
    void displayAllBugs() const;
    void findBugById(int bugId);

    /**
     * Initialise the Game Board with all the cell positions, placing each bug in the right cell
     * @param bugs The vector of bug pointers to assign to the map
     * @return Unordered Map using the positions as a key and storing the relevant at that position
     */
    static unordered_map<string, vector<Bug*>> initBoard(const vector<Bug*> &bugs);

    /**
     * Tap the board to progress the sim and move all the bugs
     */
    void tapBoard();

    /**
     * Initiate a fight between the two bugs, the loser gets eaten and the winner grows in size
     * @param bug1 Bug One to fight
     * @param bug2 Bug Two to fight
     */
    static void fightBugs(Bug* &bug1, Bug* &bug2);

    /**
     * Loop through all the bugs and display the history of all the bugs
     */
    void displayBugsHistory() const;

    /**
     * Get the history of all the bugs into a single string so it can be written onto the text file
     * @return A string containing the history of the bugs
     */
    string getBugsHistory() const;

    /**
     * Display all the cells and what bugs are in the vector
     */
    void displayCellInfo();

    /**
     * Check to see if the given cell is empty
     * @param key Position key to check
     * @return True if Empty, False is Occupied
     */
    bool isCellEmpty(const string &key);
};

} // board

#endif //GAMEBOARD_H
