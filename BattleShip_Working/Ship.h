#ifndef SHIP_H
#define SHIP_H
#include <string>
#include <vector>
#include "Grid.h"

/**
 * Store ships as a container.
 */
class Ship
{

public:
    std::string shipType, shipLocation, shipOrientation;
    int shipSize;
    std::vector<std::string> possibleShipLocations;
    Ship();
    Ship(std::string shipType, int shipSize, std::string shipLocation, std::string shipOrientation);
    Ship(std::string shipType, int shipSize, std::vector<std::string> possibleShipLocations);

};

#endif