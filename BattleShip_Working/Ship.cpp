#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Ship.h"

using namespace std;

Ship::Ship() {
    // ShipData shipData;
}

// Read in file into a data structure.
void Ship::readInShips() {
    ifstream infile;

    ShipData shipData;
    try {
        infile.open("ship_placement1_good.csv");

        while (infile.peek() != EOF) {
            getline(infile, shipData.shipType, ',');
            getline(infile, shipData.shipLocation, ',');
            getline(infile, shipData.shipOrientation, '\n');

            addSizeToShips(shipData);
            shipContainer.push_back(shipData);
        }
    }
    catch (int e) {
        cout << "Exception reading the file" << e << endl;
    }

    for (int i = 0; i < shipContainer.size(); i++) {
//        cout << shipContainer[i].shipType << endl;
//        cout << shipContainer[i].shipSize << endl;
//        cout << shipContainer[i].shipLocation << endl;
//        cout << shipContainer[i].shipOrientation << endl;
    }

    infile.close();
}

/**
 * Add sizes to each type of ship.
 * @param shipData
 */
void Ship::addSizeToShips(ShipData &shipData) {
    if (shipData.shipType == "Carrier") {
        shipData.shipSize = "5";
    } else if (shipData.shipSize == "Battleship") {
        shipData.shipSize = "4";
    } else if (shipData.shipSize == "Crusier") {
        shipData.shipSize = "3";
    } else if (shipData.shipSize == "Submarine") {
        shipData.shipSize = "2";
    } else if (shipData.shipSize == "Destroyer") {
        shipData.shipSize = "2";
    }
}

/**
 * Check ship placement is valid.
 * @param container
 * @return
 */
//bool Ship::checkShipPlacement(vector<ShipData> &container) {
//    for (int i = 0; i < container.size(); i++) {
//
//    }
//}

void Ship::placeShipOnGrid() {
    for (int i = 0; i < shipContainer.size(); i++) {
        Grid grid = chooseGridLoc(shipContainer[i].shipLocation);

        if (shipContainer[i].shipOrientation == "H") {
            for (int j = grid.getRow(); j < grid.getRow(); j++) {
                for (int k = grid.getColumn(); j < stoi(shipContainer[i].shipSize); k++) {
                    grid.GRID[j][k] = shipContainer[i].shipType[0];
                }
            }
        }
        else if (shipContainer[i].shipOrientation == "V") {
            for (int j = grid.getRow(); j < stoi(shipContainer[i].shipSize); j++) {
                for (int k = grid.getColumn(); k < grid.getColumn(); k++) {
                    grid.GRID[j][k] = shipContainer[i].shipType[0];
                }
            }
        }
    }
//    grid.createGrid();
    grid.printGrid();
}



