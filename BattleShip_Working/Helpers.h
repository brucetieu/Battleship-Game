//
// Created by Bruce Tieu on 11/7/20.
//

#ifndef BATTLESHIP_WORKING_HELPERS_H
#define BATTLESHIP_WORKING_HELPERS_H
#include "GridIndex.h"
#include "Grid.h"

/**
 * Helper class to check if ships can be arranged.
 */
class Helpers {

private:
    Grid grid;
public:

    GridIndex parseShipLocation(std::string &location);
    bool checkLocationOfShip(GridIndex &gridIndex);

};


#endif //BATTLESHIP_WORKING_HELPERS_H
