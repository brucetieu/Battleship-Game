//
// Created by Bruce Tieu on 11/7/20.
//

#ifndef BATTLESHIP_WORKING_HELPERS_H
#define BATTLESHIP_WORKING_HELPERS_H
#include "GridIndex.h"
#include "Grid.h"
#include <string>

/**
 * Helper class to check if ships can be arranged properly.s
 */
class Helpers {

private:
    Grid grid;  // Use Grid class throughout class.
public:

    GridIndex parseLocationToIndex(std::string &location);  // Parse a location to row and col.
    std::string parseLocationToString(std::string &location); // Parse location to row and col string representation.

    bool isAlphabet(std::string &choice);  // Check input is alphabetical.
    bool isInBound(std::string &choice);  // Check location is in bound.
    bool isRightLength(std::string &choice);  // Check string is within a certain correct range.
    bool isSpace(std::string &choice); // Check there are no spaces in the input.
    bool isEmpty(std::string &choice);  // Check that the input is not empty.

    std::string toUpper(std::string &str);  // Convert input to all uppercase.

};


#endif //BATTLESHIP_WORKING_HELPERS_H
