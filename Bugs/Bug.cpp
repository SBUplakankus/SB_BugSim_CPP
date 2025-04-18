//
// Created by tremo on 13/04/2025.
//

#include "Bug.h"

namespace bugs
{

    Bug::Bug(const int id, const int posX, const int posY, const int direction, const int size) {
        this->id = id;
        const Position pos(posX, posY);
        this->position = pos;
        this->direction = direction;
        this->size = size;
        this->isAlive = true;
    }

    void Bug::move(int &maxX, int &maxY)
    {

    }

    Bug::~Bug()
    {

    }

    string Bug::toString() {
        return "Bug";
    }

    Position Bug::getPosition() const
    {
        return this->position;
    }

    int Bug::getDirection() const
    {
        return this->direction;
    }

    int Bug::getSize() const
    {
        return this->size;
    }

    void Bug::setPosition(const Position &position)
    {
        this->position = position;
    }

    int Bug::getId() const {
        return this->id;
    }

    string Bug::directionToString() const
    {
        string direction;
        switch (this->direction) {
            case 1:
                direction = "North";
                break;
            case 2:
                direction = "South";
                break;
            case 3:
                direction = "East";
                break;
            case 4:
                direction = "West";
                break;
            default:
                direction = "Invalid direction";
                break;
        }
        return direction;
    }

    string Bug::aliveToString() const {
        if (this->isAlive)
            return "Alive";

        return "Dead";
    }
} // bugs