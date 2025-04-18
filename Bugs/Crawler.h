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
    // https://www.youtube.com/watch?v=oz3f-ms-AJs Subclass Constructor
    Crawler(const int id, const string &type, const int posX, const int posY, const int direction, const int size)
        : Bug(id, type, posX, posY, direction, size){}

    void move(int &maxX, int &maxY) override;
    string toString() override;
    ~Crawler() override;
};

} // bugs

#endif //CRAWLER_H
