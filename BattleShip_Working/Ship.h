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
//private:
//    std::string shipType, shipSize, shipLocation, shipOrientation;

public:
    std::string shipType, shipSize, shipLocation, shipOrientation;
    std::vector<std::string> possibleShipLocations;
    Ship();
    Ship(std::string shipType, std::string shipSize, std::string shipLocation, std::string shipOrientation);
    Ship(std::string shipType, std::string shipSize, std::vector<std::string> possibleShipLocations);
//    void readInShips();
//    bool checkShipPlacement(vector<ShipData> &container);
//    void addSizeToShips(ShipData &shipData);
//    void populateGrid(ShipData &shipData);
};

#endif