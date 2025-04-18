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

        if (pos.x == maxX || pos.y == maxY || pos.x == 0 || pos.y == 0) {
            int newDirection = rand() % 4 + 1;
            while (newDirection == getDirection()) {
                newDirection = rand() % 4 + 1;
            }
            setDirection(newDirection);
        }
    }

    Crawler::~Crawler()
    {

    }

    string Crawler::toString() {
        return "Crawler " + to_string(getId()) + ": (" + to_string(getPosition().x) + "," + to_string(getPosition().y) +
            "), Size: " + to_string(getSize()) + ", Direction: " + directionToString() + ", Status: " + aliveToString();
    }

} // bugs