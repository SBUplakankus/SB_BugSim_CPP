//
// Created by tremo on 13/04/2025.
//

#ifndef BUG_H
#define BUG_H
#include <list>
#include <string>

using namespace std;

namespace bugs
{

    struct Position
    {
        int x;
        int y;

        Position(const int x, const int y) : x(x), y(y) {}

        string toString() const {
            return to_string(x) + ", " + to_string(y);
        }
    };

    class Bug
    {
        private:
        int id;
        Position position;
        int size;
        bool isAlive;
        list<Position> path;

        public:
        Bug(int id, Position position, int size);
        virtual ~Bug() = 0;

        virtual void move();

        /**
         * Check to see if the way in front of the bug is blocked
         * @return True = If Way is Blocked, False = If Way Isn't
         */
        bool isWayBlocked();

        // Getters
        Position getPosition() const;
        int getId() const;
        int getSize() const;
        bool getIsAlive() const;
        list<Position> getPath() const;

        // Setters
        void setSize(int size);
        void setIsAlive(bool isAlive);
        void setPosition(const Position& position);



    };

} // bugs

#endif //BUG_H
