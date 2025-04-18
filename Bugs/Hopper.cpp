//
// Created by tremo on 13/04/2025.
//

#include "Hopper.h"

#include <bits/stl_algo.h>
using namespace std;

namespace bugs {
    void Hopper::move(int &maxX, int &maxY)
    {
        Position pos = getPosition();
        switch (getDirection())
        {
            case 1: // UP
                pos.y = clamp(pos.y + hopLength, 0, maxY);
            break;
            case 2: // DOWN
                pos.y = clamp(pos.y - hopLength, 0, maxY);
            break;
            case 3: // Right
                pos.x = clamp(pos.x + hopLength, 0, maxX);
            break;
            case 4: // LEFT
                pos.x = clamp(pos.x - hopLength, 0, maxX);
            break;
            default:
                break;
        }
        setPosition(pos);
    }

    Hopper::~Hopper()
    {

    }

    string Hopper::toString()
    {
        return "Hopper " + to_string(getId()) + ": (" + to_string(getPosition().x) + "," + to_string(getPosition().y) +
            ") Size: " + to_string(getSize()) + " Direction: " + directionToString() + " Hop Length: " + to_string(hopLength)
                + " Status: " + aliveToString();
    }



}
