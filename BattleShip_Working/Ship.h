#ifndef SHIP_H
#define SHIP_H
#include <string>
#include <vector>
#include "Grid.h"

class Ship
{
// private:
    struct ShipData
    {
        std::string shipType;
        std::string shipSize;
        std::string shipOrientation;
        std::string shipLocation;
    };
    std::vector<ShipData> shipContainer;
    Grid grid;

public:
    Ship();
    void readInShips();
    bool checkShipPlacement(vector<ShipData> &container);
    void addSizeToShips(ShipData &shipData);
    void populateGrid(ShipData &shipData);
};

#endif