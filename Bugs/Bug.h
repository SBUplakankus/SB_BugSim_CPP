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

        string toString() const
        {
            return "(" + to_string(x) + ", " + to_string(y) + ")";
        }
    };

    class Bug
    {
        private:
        int id;
        string bugType;
        int direction;
        Position position;
        int size;
        bool isAlive;
        int bugEatenBy;

    public:
        list<Position> path;
        Bug(int id, const string& type, int posX, int posY, int direction, int size);
        virtual ~Bug();
        virtual void move(int &maxX, int &maxY);
        virtual string toString();

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
        int getDirection() const;
        list<Position> getPath() const;
        string directionToString() const;
        string aliveToString() const;
        int getEatenBy() const;
        string getBugType() const;

        // Setters
        void setSize(int size);
        void setIsAlive(bool isAlive);
        void setPosition(const Position& position);
        void setDirection(int direction);
        void growBug(const int growAmount);
        void setEatenBy(const int eatenBy);
        void setBugType(const string &bugType);

        string pathToString() const;
        string historyToString() const;
    };

} // bugs

#endif //BUG_H
