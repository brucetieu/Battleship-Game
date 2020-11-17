#include <iostream>
#include <string>
#include "Grid.h"
#include "Ship.h"
#include "Helpers.h"
#include "Player.h"
#include "Computer.h"

using namespace std;

//char Grid::GRID[Grid::MAX_COLUMN][Grid::MAX_COLUMN] = {{'0'}};
int main()
{
//    Computer computer;
//    computer.generateCorrectPlacements();
//    computer.printRandShips();

//    Ship ship;
//    ship.readInShips();
    Player player;
    player.readShipsFromFile("ship_placement1_good.csv");
//    player.addSizeToShips();
//    player.replaceShipLocations();
//    player.checkAllShipsAreIncluded();
//    if (player.shipsAreInBounds()) {
//        cout << "In bounds" << endl;
//    } else cout << "Out of bounds" << endl;
    player.getPossibleShipLocations();
    Grid grid = player.placeShipsOnBoard();
    grid.printGrid();
//    if (player.shipsOverlap()) {
//        cout << "No overlap" << endl;
//    } else cout << "Overlap" << endl;
    player.printShipVector();
    
    // Grid grid;

    // grid.createGrid();

    // int i = 0;
    // while (i < 1)
    // {

    //     string x;
    //     cout << "Chose a location: ";
    //     cin >> x;

    //     Grid grid_ = grid.chooseGridLoc(x);
    //     grid.updateGrid(grid_);

    //     i++;
    // }

    // grid.clearGrid();
    // grid.printGrid();

    return 0;
}