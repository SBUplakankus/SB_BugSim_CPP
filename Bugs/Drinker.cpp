//
// Created by tremo on 27/04/2025.
//

#include "Drinker.h"

#include <bits/stl_algo.h>

namespace bugs {

    void Drinker::move(int &maxX, int &maxY)
    {
        // Update the drinks position, clamping it inside the boundaries of the grid
        // The drinker randomly changes direction after every movement
        Position pos = getPosition();
        path.push_back(pos);
        switch (getDirection())
        {
            case 1: // UP
                pos.y = clamp(pos.y + 1, 0, maxY);
            break;
            case 2: // DOWN
                pos.y = clamp(pos.y - 1, 0, maxY);
            break;
            case 3: // Right
                pos.x = clamp(pos.x + 1, 0, maxX);
            break;
            case 4: // LEFT
                pos.x = clamp(pos.x - 1, 0, maxX);
            break;
            default:
                break;
        }
        setPosition(pos);

        int newDirection = rand() % 4 + 1;
        while (newDirection == getDirection())
        {
            newDirection = rand() % 4 + 1;
        }
        setDirection(newDirection);
    }


    Drinker::~Drinker() {

    }

    string Drinker::toString()
    {
        return getBugType() + " " + to_string(getId()) + ": (" + to_string(getPosition().x) + "," + to_string(getPosition().y) +
            "), Size: " + to_string(getSize()) + ", Direction: " + directionToString() + ", Status: " + aliveToString();
    }


} // bugs