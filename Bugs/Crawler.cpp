//
// Created by tremo on 13/04/2025.
//

#include "Crawler.h"

#include <bits/stl_algo.h>
using namespace std;

namespace bugs
{
    void Crawler::move(int &maxX, int &maxY)
    {
        // Clamping https://stackoverflow.com/questions/9323903/most-efficient-elegant-way-to-clip-a-number
        Position pos = getPosition();
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
    }

    Crawler::~Crawler()
    {

    }

    string Crawler::toString() {
        return "Hopper " + to_string(getId()) + ": (" + to_string(getPosition().x) + "," + to_string(getPosition().y) +
            ") Size: " + to_string(getSize()) + " Direction: " + directionToString() + " Status: " + aliveToString();
    }

} // bugs