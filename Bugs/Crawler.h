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
    Crawler(int id, Position position, int size);
    void move() override;

    ~Crawler() override = default;

};

} // bugs

#endif //CRAWLER_H
