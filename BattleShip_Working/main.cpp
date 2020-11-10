#include <iostream>
#include <string>
#include "Grid.h"
#include "Ship.h"
#include "Helpers.h"
#include "Player.h"

using namespace std;

int main()
{
//    Ship ship;
//    ship.readInShips();
    Player player;
    player.readShipsFromFile("ship_placement1_good.csv");
    player.addSizeToShips();
//    player.replaceShipLocations();
    player.checkAllShipsAreIncluded();
//    if (player.checkBoundsOfShipLocation()) {
//        cout << "True" << endl;
//    } else cout << "False" << endl;
    player.getPossibleShipLocations();
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