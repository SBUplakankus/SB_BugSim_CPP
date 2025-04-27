//
// Created by tremo on 27/04/2025.
//

#ifndef DRINKER_H
#define DRINKER_H
#include "Bug.h"

namespace bugs {

class Drinker final : public Bug {
    public:
    Drinker(const int id, const string &type, const int posX, const int posY, const int direction, const int size)
        : Bug(id, type, posX, posY, direction, size){}
    void move(int &maxX, int &maxY) override;
    string toString() override;
    ~Drinker() override;
};

} // bugs

#endif //DRINKER_H
