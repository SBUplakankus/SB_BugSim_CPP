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
        Hopper(int id, Position position, int size, int hopLength);
        void move() override;


    };
}





#endif //HOPPER_H
