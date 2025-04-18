//
// Created by tremo on 13/04/2025.
//

#ifndef CRAWLER_H
#define CRAWLER_H
#include "Bug.h"

namespace bugs
{

class Crawler final : public Bug
{
    public:
    Crawler(const int id, const int posX, const int posY, const int direction, const int size)
        : Bug(id, posX, posY, direction, size){}

    void move() override;
    ~Crawler() override;

};

} // bugs

#endif //CRAWLER_H
