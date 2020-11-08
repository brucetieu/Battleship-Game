//
// Created by Bruce Tieu on 11/7/20.
//

#include "Helpers.h"
#include "GridIndex.h"
#include <string>
#include <vector>

using namespace std;

/**
 * Parse ship location into (row, column). eg A1 -> "11"
 * @param location The location in the file.
 * @return A GridIndex struct.
 */
GridIndex Helpers::parseShipLocation(string &location) {

    GridIndex gridIndex;
    vector<char> map = grid.getMAP();

    // Loop through map, assign first character of location to be the index of the map.
    for (int i = 0; i <= map.size(); i++) {
        if (location[0] == map[i]) {
            gridIndex.row = i;
        }
    }
    // Convert second character to be an integer.
    gridIndex.column = stoi(location.substr(1)) - 1;

    // Return the struct.
    return gridIndex;
}

/**
 * Check if the location is valid.
 * @param gridIndex The matrix indexes (row, column)
 * @return true if the location is good, false otherwise.
 */
bool Helpers::checkLocationOfShip(GridIndex &gridIndex) {

    // If any of the indexes are outside the bounds of the Grid, return false.
    if (gridIndex.row > 10 || gridIndex.column > 10 || gridIndex.row < 0 || gridIndex.column < 0) {
        return false;
    }
    return true;

}
