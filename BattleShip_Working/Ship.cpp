#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Ship.h"
#include <typeinfo>

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

//            addSizeToShips(shipData);
            shipContainer.push_back(shipData);
        }
    }
    catch (int e) {
        cout << "Exception reading the file" << e << endl;
    }

    addSizeToShips();

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
void Ship::addSizeToShips() {
    for (int i = 0; i < shipContainer.size(); i++) {
        if (shipContainer[i].shipType == "Carrier") {
            shipContainer[i].shipSize = "5";
        } else if (shipContainer[i].shipType == "Battleship") {
            shipContainer[i].shipSize = "4";
        } else if (shipContainer[i].shipType == "Cruiser") {
            shipContainer[i].shipSize = "3";
        } else if (shipContainer[i].shipType == "Submarine") {
            shipContainer[i].shipSize = "2";
        } else if (shipContainer[i].shipType == "Destroyer") {
            shipContainer[i].shipSize = "2";
        }
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
    Grid grid;
    Point point;
    grid.createGrid();

    for (int i = 0; i < shipContainer.size(); i++) {
        point = point.parseLocationToPoint(shipContainer[i].shipLocation);
        cout << point.xCoord << ", " << point.yCoord << endl;
        cout << shipContainer[i].shipType << endl;
        if (shipContainer[i].shipOrientation.find("H") != std::string::npos) {

            for (int j = point.xCoord; j <= point.xCoord; j++) {
                for (int k = point.yCoord; k <= stoi(shipContainer[i].shipSize); k++) {
                    grid.GRID[j][k] = shipContainer[i].shipType[0];

                }
            }
        }
        else if (shipContainer[i].shipOrientation.find("V") != std::string::npos) {

            for (int j = point.yCoord; j <= stoi(shipContainer[i].shipSize); j++) {
                for (int k = point.xCoord; k <= point.xCoord; k++) {
                    grid.GRID[j][k] = shipContainer[i].shipType[0];
                }
            }
        }
    }

    grid.printGrid();
}
