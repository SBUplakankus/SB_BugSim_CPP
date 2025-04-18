//
// Created by tremo on 13/04/2025.
//

#ifndef CSVPARSER_H
#define CSVPARSER_H
#include <string>
#include <vector>

#include "GameBoard.h"
#include "../Bugs/Bug.h"

using namespace std;
using namespace bugs;

namespace board {

class CsvParser
{
    // https://www.geeksforgeeks.org/static-keyword-cpp/ Static ints
    private:
    vector<Bug*> bugs;
    static int maxWidth;
    static int maxHeight;

    /**
     * @brief Parses through a line in the CSV file
     * @param line The line to parse
     * @param bugs Vector of Pointers to bugs to push a bug to
     * @param maxWidth Pass through the max width to see if it can be updated
     * @param maxHeight Pass through the max height to see if it can be updated
     */
    static void parseLine(const string &line, vector<Bug*> &bugs);

    /**
     * @brief Load data into a vector of Crawlers from a given CSV file name
     * @param filename Name of the CSV file to parse through
     * @param bugs Vector of Pointers to bugs to populate
     */
    static void load(const string &filename, vector<Bug*> &bugs);

    public:
    CsvParser();

    /**
     * Get a Vector of Crawlers from a given CSV file
     * @param filename Name of the CSV file to get data from
     * @return Vector of Pointers to Bugs created from the CSV Data
     */
    static GameBoard* getBugsFromCsv(const string &filename);

};

} // board

#endif //CSVPARSER_H
