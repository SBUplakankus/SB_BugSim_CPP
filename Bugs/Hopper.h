//
// Created by tremo on 13/04/2025.
//

#ifndef HOPPER_H
#define HOPPER_H
#include "Bug.h"

namespace bugs
{
    class Hopper final : public Bug
    {
        private:
        int hopLength;

        public:
        Hopper(const int id, const int posX, const int posY, const int direction, const int size, const int hopLength)
        : Bug(id, posX, posY, direction, size) {this->hopLength = hopLength;}
        void move(int &maxX, int &maxY) override;
        string toString() override;
        ~Hopper() override;
    };
}





#endif //HOPPER_H
