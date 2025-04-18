//
// Created by tremo on 13/04/2025.
//

#include "Bug.h"

namespace bugs {

    Bug::Bug(const int id, const int posX, const int posY, const int direction, const int size) {
        this->id = id;
        const Position pos(posX, posY);
        this->position = pos;
        this->direction = direction;
        this->size = size;
        this->isAlive = true;
    }

    void Bug::move() {

    }

    Bug::~Bug() {

    }


    Position Bug::getPosition() const {
        return this->position;
    }


} // bugs