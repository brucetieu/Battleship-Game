//
// Created by Bruce Tieu on 11/21/20.
// Implement function declarations in Human.h.
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
 * Constructor - initialize ship object and counter
 */
Human::Human() : ship(new Ship()),
                 hitCountComputer(0) {}

/**
 * Get the ship object.
 * @return The Ship object.
 */
Ship Human::getShip() { return *ship; }

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

    infile.close();  // Close the file.

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
        cout
                << "Ships can not be placed on board. Try a different configuration. Change the config in your file or read in a different file."
                << endl;
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

//    Helpers helpers;

    string parsedChoice = helpers.parseLocationToString(choice);
    GridIndex index = helpers.parseLocationToIndex(choice);

    // Human fires, loop through the vector of all possible ship locs and check if the target is in there.
    for (int i = 0; i < newGame.computerPossibleShipLocs.size(); i++) {
        for (int j = 0; j < newGame.computerPossibleShipLocs[i].possibleShipLocations.size(); j++) {
            if (parsedChoice == newGame.computerPossibleShipLocs[i].possibleShipLocations[j]) {

                // Private helper method which performs logic for hitting a computer ship.
                return _numComputerShipsHit(newGame, index, i, choice);
            }
        }
    }

    // Private helper method which performs logic for missing a computer ship.
    return _numComputerShipsMissed(newGame, index, choice);
}

/**
 * Perform required logic when a computer's ship is hit.
 * @param newGame The current game state.
 * @param index The row and column of the target.
 * @param i The current ship which was hit and stored in a vector.
 * @param choice The target the user decided to fire.
 * @return A tally of the number of ships hit.
 */
int Human::_numComputerShipsHit(Game &newGame, GridIndex &index, int &i, std::string &choice) {

    // If there's not already a mark on the Grid...
    if (newGame.trackerBoard.GRID[index.row][index.column] != 'O') {

        hitCountComputer += 1;  // Iterate the count by 1.
        newGame.computerPossibleShipLocs[i].shipSize--; // Decrement the size of ship by 1.

        // If the ship's size is 0, then the specific ship at this index (i) is sunk.
        if (newGame.computerPossibleShipLocs[i].shipSize == 0) {
            cout << newGame.computerPossibleShipLocs[i].shipType << " is sunk!" << endl;
        }

            // Otherwise, it's a hit, ship has not yet been sunk.
        else {
            cout << "Hit " << newGame.computerPossibleShipLocs[i].shipType << " at " << choice << "!" << endl;
        }
    }
        // If ship was already hit, then let the user know.
    else {
        cout << newGame.computerPossibleShipLocs[i].shipType << " is already hit!" << endl;
    }

    // Output the number of ships that were hit.
    cout << "Computer ships hit: " << hitCountComputer << endl;

    // Update the tracker grid with an 'O' to indicate that the ship was hit.
    newGame.trackerBoard.GRID[index.row][index.column] = 'O';

    // Print out the updated tracker grid.
    cout << "Your tracking grid: " << endl;
    newGame.trackerBoard.printGrid();

    return hitCountComputer;
}

/**
 * Perform required logic when there's a miss.
 * @param newGame The current game instance.
 * @param index The row and column of the ship's location.
 * @param choice The target which was fired.
 * @return A tally of the number of ships hit.
 */
int Human::_numComputerShipsMissed(Game &newGame, GridIndex &index, std::string &choice) {
    cout << choice << " is a miss! " << endl << endl;

    // Update your tracker with an 'X' to indicate a miss.
    newGame.trackerBoard.GRID[index.row][index.column] = 'X';

    // Print out updated human board along with the tracking grid.
    cout << "Your board:" << endl;
    newGame.humanBoard.printGrid();
    cout << endl;
    cout << "Your tracker board: " << endl;
    newGame.trackerBoard.printGrid();

    return hitCountComputer;
}