//
// Created by Bruce Tieu on 11/21/20.
//

#include "Human.h"
#include "Game.h"
#include "Ship.h"
#include <string>
#include <fstream>
#include "GridIndex.h"
#include <iostream>
#include <algorithm>
#include "Helpers.h"

using namespace std;

/**
 * Constructor - initialize ship object.
 */
Human::Human() {
    ship = new Ship();  // Dynamically create a new ship.
    hitCountComputer = 0; // Initialize the initial number of computer ships hit to be 0.
}

/**
 * Get the ship object.
 * @return The Ship object.
 */
Ship Human::getShip() {
    return *ship;
}

/**
 * Read in Ship type, location, and orientation into a vector of Ship objects.
 * @param filename The name of the ship placement configuration file.
 * @return A vector of Ship objects.
 */
vector <Ship> Human::readShipsFromFile(string filename) {
    ifstream infile;

    try {
        infile.open(filename);

        while (infile.peek() != EOF) {
            getline(infile, ship->shipType, ',');
            getline(infile, ship->shipLocation, ',');
            getline(infile, ship->shipOrientation, '\n');

            shipVector.push_back(*ship);
        }
    } catch (const ifstream::failure &e) {
        cout << "Error reading file" << endl;
    }
    _addSizeToShips();  // Add sizes to each ship.
    return shipVector;
}

/**
 * Add sizes to each type of ship. Add it to the private vector, shipVector in Player class.
 */
void Human::_addSizeToShips() {
    for (int i = 0; i < shipVector.size(); i++) {
        if (shipVector[i].shipType.find("Carrier") != string::npos) {
            shipVector[i].shipSize = 5;
        } else if (shipVector[i].shipType == "Battleship") {
            shipVector[i].shipSize = 4;
        } else if (shipVector[i].shipType == "Cruiser") {
            shipVector[i].shipSize = 3;
        } else if (shipVector[i].shipType == "Submarine") {
            shipVector[i].shipSize = 3;
        } else if (shipVector[i].shipType.find("Destroyer") != string::npos) {
            shipVector[i].shipSize = 2;
        }
    }
}


/**
 * Place the ships on the Board.
 * @param vecOfShips The vector of ships which were read from the file.
 * @param newVecOfShips The new vector of ships which contains all possible ship placement locations.
 * @return The grid showing the placement of ships, if placement is valid.
 */
Grid Human::placeShipsOnBoard(vector <Ship> &vecOfShips, vector <Ship> &newVecOfShips) {
    Grid grid;
    grid.createGrid(); // Create the blank board.

    // If all ships are included, in bounds, and don't overlap then load the ships onto the board.
    if (allShipsAreIncluded(vecOfShips) & shipsAreInBounds(newVecOfShips) & shipsDontOverlap(newVecOfShips)) {
        cout << "Ships can be placed on board." << endl;

        for (int i = 0; i < shipVector.size(); i++) {

            // Convert the location to be an integer.
            GridIndex indices = helpers.parseLocationToIndex(shipVector[i].shipLocation);

            // Fix rows, update columns if ship is horizontal.
            if (shipVector[i].shipOrientation.find("H") != std::string::npos) {
                for (int row = indices.row; row <= indices.row; row++) {
                    for (int col = indices.column; col < shipVector[i].shipSize + indices.column; col++) {
                        grid.GRID[row][col] = shipVector[i].shipType[0]; // Put the first letter of each ship in the Grid.
                    }
                }
            }
            // Fix columns, update rows if ship is vertical.
            else if (shipVector[i].shipOrientation.find("V") != std::string::npos) {
                for (int col = indices.column; col <= indices.column; col++) {
                    for (int row = indices.row; row < shipVector[i].shipSize + indices.row; row++) {
                        grid.GRID[row][col] = shipVector[i].shipType[0];
                    }
                }
            }
        }
    } else {
        cout << "Ships can not be placed on board. Try a different configuration. Change the config in your file or read in a different file." << endl;
        exit(1); // Exit program if there is an issue with the ships.
    }
    return grid;
}

/**
 * Allow human to fire.
 * @param choice The target (A1, A2, ... J10).
 * @param newGame The current game state.
 */
int Human::humanFires(string &choice, Game &newGame) {

    Helpers helpers;

    string parsedChoice = helpers.parseLocationToString(choice);
    GridIndex index = helpers.parseLocationToIndex(choice);

    // Human fires, loop through the vector of all possible ship locs and check if the target is in there.
    for (int i = 0; i < newGame.computerPossibleShipLocs.size(); i++) {
        for (int j = 0; j < newGame.computerPossibleShipLocs[i].possibleShipLocations.size(); j++) {
            if (parsedChoice == newGame.computerPossibleShipLocs[i].possibleShipLocations[j]) {

                return _numComputerShipsHit(newGame, index, i, choice);
                // If location has not already been hit, then hit it.
//                if (newGame.trackerBoard.GRID[index.row][index.column] != 'O')  {
//                    hitCountComputer += 1;  // Iterate the count by 1.
//                    newGame.computerPossibleShipLocs[i].shipSize--; // Decrement the size of ship by 1.
//
//                    // If the ship's size is 0, then the specific ship is sunk.
//                    if (newGame.computerPossibleShipLocs[i].shipSize == 0) {
//                        cout << newGame.computerPossibleShipLocs[i].shipType << " is sunk!" << endl;
//                    }
//
//                    // Otherwise, it's a hit.
//                    else {
//                        cout << "Hit " << newGame.computerPossibleShipLocs[i].shipType << " at " << choice << "!" << endl;
//                    }
//                }
//                // If ship was already hit, then let the user know.
//                else {
//                    cout << newGame.computerPossibleShipLocs[i].shipType << " is already hit!" << endl;
//                }
//
//                cout << "Computer ships hit: " << hitCountComputer << endl;
//
//                newGame.trackerBoard.GRID[index.row][index.column] = 'O';
//                cout << "Your board: " << endl;
//                newGame.humanBoard.printGrid();
//                cout << "Your tracking grid: " << endl;
//                newGame.trackerBoard.printGrid();
//                return hitCountComputer;
            }
        }
    }

    return _numComputerShipsMissed(newGame, index, choice);
//    cout << choice << " is a miss! "<< endl << endl;
//    newGame.trackerBoard.GRID[index.row][index.column] = 'X';
//
//    cout << "Your board:" << endl;
//    newGame.humanBoard.printGrid();
//    cout << endl;
//    cout << "Your tracker board: " << endl;
//    newGame.trackerBoard.printGrid();
//
//    return hitCountComputer;
}

int Human::_numComputerShipsHit(Game &newGame, GridIndex &index, int i, std::string &choice) {
    if (newGame.trackerBoard.GRID[index.row][index.column] != 'O')  {
        hitCountComputer += 1;  // Iterate the count by 1.
        newGame.computerPossibleShipLocs[i].shipSize--; // Decrement the size of ship by 1.

        // If the ship's size is 0, then the specific ship is sunk.
        if (newGame.computerPossibleShipLocs[i].shipSize == 0) {
            cout << newGame.computerPossibleShipLocs[i].shipType << " is sunk!" << endl;
        }

        // Otherwise, it's a hit.
        else {
            cout << "Hit " << newGame.computerPossibleShipLocs[i].shipType << " at " << choice << "!" << endl;
        }
    }
        // If ship was already hit, then let the user know.
    else {
        cout << newGame.computerPossibleShipLocs[i].shipType << " is already hit!" << endl;
    }

    cout << "Computer ships hit: " << hitCountComputer << endl;

    newGame.trackerBoard.GRID[index.row][index.column] = 'O';
//    cout << "Your board: " << endl;
//    newGame.humanBoard.printGrid();
    cout << "Your tracking grid: " << endl;
    newGame.trackerBoard.printGrid();
    return hitCountComputer;
}

int Human::_numComputerShipsMissed(Game &newGame, GridIndex &index, std::string &choice) {
    cout << choice << " is a miss! "<< endl << endl;
    newGame.trackerBoard.GRID[index.row][index.column] = 'X';

    cout << "Your board:" << endl;
    newGame.humanBoard.printGrid();
    cout << endl;
    cout << "Your tracker board: " << endl;
    newGame.trackerBoard.printGrid();

    return hitCountComputer;
}