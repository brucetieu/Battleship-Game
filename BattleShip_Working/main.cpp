#include <iostream>
#include <string>
#include "Grid.h"
#include "Ship.h"

using namespace std;

//char Grid::GRID[MAX_ROW][MAX_COLUMN] = {{'0'}};
//std::vector<char> Grid::MAP = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int main()
{
//    Grid grid;
//    grid.createGrid();
//    grid.printGrid();

    Ship ship;
    ship.readInShips();
    ship.placeShipOnGrid();

//    grid.printGrid();

    
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