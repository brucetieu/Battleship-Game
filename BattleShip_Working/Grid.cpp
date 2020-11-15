#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Grid.h"

using namespace std;


Grid::Grid()
{

}

Grid::Grid(int &row, int &column) {
    this->row = row;
    this->column = column;
}

int Grid::getRow() const {
    return this->row;
}
int Grid::getColumn() const {
    return this->column;
}

vector<char> Grid::getMAP() {
    return MAP;
}

void Grid::createGrid()
{
    for (row = 0; row < MAX_ROW; row++)
    {
        for (column = 0; column < MAX_COLUMN; column++)
        {
            GRID[row][column] = '#';
        }
    }
}

void Grid::printGrid()
{
    printColumnLabel();
    for (row = 0; row < MAX_ROW; row++)
    {
        cout << MAP[row] << "  ";
        for (column = 0; column < MAX_COLUMN; column++)
        {   
            cout << GRID[row][column] << " ";
        }
        cout << endl;
    }
}

Grid Grid::chooseGridLoc(const std::string &choice) {

    // vector<char> map = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int x, y;
    
    for (int i = 1; i <= MAP.size(); i++) {
        if (choice[0] == MAP[i]) {
            x = i;
        }
    }
    
      y = stoi(choice.substr(1)) - 1;

    return Grid(x, y);
    
}

void Grid::updateGrid(Grid &grid) {
    GRID[grid.getRow()][grid.getColumn()] = 'X';
    printGrid();
}

void Grid::printColumnLabel() {
    cout << setw(4);
    for (int i = 0; i < MAX_ROW; i++) {
        cout << i + 1 << " ";
    }
    cout << endl;
}

void Grid::clearGrid() {
    for (row = 0; row < MAX_ROW; row++)
    {
        for (column = 0; column < MAX_COLUMN; column++)
        {
            GRID[row][column] = '#';
        }
    }
}