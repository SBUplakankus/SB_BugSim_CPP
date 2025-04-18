//
// Created by tremo on 13/04/2025.
//

#include "CsvParser.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "../Bugs/Crawler.h"
#include "../Bugs/Hopper.h"

namespace board {

    CsvParser::CsvParser() {
    }

    int CsvParser::maxHeight = 0;
    int CsvParser::maxWidth = 0;

    void CsvParser::parseLine(const string &line, vector<Bug*> &bugs) {
        string temp;
        stringstream ss(line);

        Bug *bug;

        // Get the first letter and check if it is C for Crawler
        getline(ss, temp, ',');
        if (temp == "C")
        {
            // Get the next value and save it to temp since it's an int
            getline(ss, temp, ',');
            // Set the structs value to the temp variable converted from a string to an int
            const int id = stoi(temp);

            getline(ss, temp, ',');
            const int posX = stoi(temp);
            if (posX > maxWidth)
            {
                maxWidth = posX;
            }
            getline(ss, temp, ',');
            const int posY = stoi(temp);
            if (posY > maxHeight)
            {
                maxHeight = posY;
            }
            getline(ss, temp, ',');
            const int direction = stoi(temp);
            getline(ss, temp, ',');
            const int size = stoi(temp);

            bug = new Crawler(id, posX, posY, direction, size);
        }
        else if (temp == "H")
        {
            // Get the next value and save it to temp since it's an int
            getline(ss, temp, ',');
            // Set the structs value to the temp variable converted from a string to an int
            const int id = stoi(temp);

            getline(ss, temp, ',');
            const int posX = stoi(temp);
            if (posX > maxWidth)
            {
                maxWidth = posX;
            }
            getline(ss, temp, ',');
            const int posY = stoi(temp);
            if (posY > maxHeight)
            {
                maxHeight = posY;
            }

            getline(ss, temp, ',');
            const int direction = stoi(temp);
            getline(ss, temp, ',');
            const int size = stoi(temp);
            getline(ss, temp, ',');
            const int hop = stoi(temp);

            bug = new Hopper(id, posX, posY, direction, size, hop);
        }
        else
        {
            cout << "Not a Crawler: " << temp << endl;
        }

        bugs.push_back(bug);
    }

    void CsvParser::load(const string &filename, vector<Bug*> &bugs) {
        if(ifstream fin(filename); fin)
        {
            string line;
            while(getline(fin, line))
            {
                parseLine(line, bugs);
            }
            fin.close();
        }
        else
        {
            cout << "Unable to open file" << endl;
        }
    }

    GameBoard* CsvParser::getBugsFromCsv(const string &filename) {
        vector<Bug *> bugs;
        load(filename, bugs);
        auto* board = new GameBoard(maxWidth, maxHeight, bugs);
        return board;
    }


} // board