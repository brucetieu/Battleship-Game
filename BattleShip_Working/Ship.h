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

    // Specify the types of ships which are available.
    static const std::string CARRIER;
    static const std::string BATTLESHIP;
    static const std::string CRUISER;
    static const std::string SUBMARINE;
    static const std::string DESTROYER;

    static const std::string HORIZONTAL;
    static const std::string VERTICAL;

    std::string shipType, shipLocation, shipOrientation;
    int shipSize;
    std::vector<std::string> possibleShipLocations;
    Ship();
    Ship(std::string shipType, int shipSize, std::string shipLocation, std::string shipOrientation);
    Ship(std::string shipType, int shipSize, std::vector<std::string> possibleShipLocations);

};

#endif