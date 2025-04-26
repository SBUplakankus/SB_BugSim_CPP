//
// Created by tremo on 13/04/2025.
//

#include "Bug.h"

namespace bugs
{

    Bug::Bug(const int id, const string& type, const int posX, const int posY, const int direction, const int size)
    {
        this->id = id;
        this->bugType = type;
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

    string Bug::toString()
    {
        return "Bug";
    }

    bool Bug::getIsAlive() const
    {
        return this->isAlive;
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

    void Bug::setSize(const int size) {
        this->size = size;
    }

    void Bug::setIsAlive(const bool isAlive) {
        this->isAlive = isAlive;
    }


    void Bug::growBug(const int growAmount) {
        setSize(growAmount + getSize());
    }

    int Bug::getEatenBy() const {
        return bugEatenBy;
    }

    void Bug::setEatenBy(const int eatenBy) {
        bugEatenBy = eatenBy;
    }

    string Bug::getBugType() const {
        return bugType;
    }

    void Bug::setBugType(const string &bugType) {
        this->bugType = bugType;
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

    string Bug::aliveToString() const
    {
        if (this->isAlive)
            return "Alive";

        return "Dead";
    }

    void Bug::setDirection(const int direction)
    {
        this->direction = direction;
    }

    string Bug::pathToString() const {
        string returnString;
        for (auto position: path) {
            returnString += position.toString() + ", ";
        }
        return returnString;
    }


    string Bug::historyToString() const {
        return "Bug " + to_string(getId()) + ": " + pathToString() + " Eaten by " + to_string(getEatenBy());
    }

} // bugs