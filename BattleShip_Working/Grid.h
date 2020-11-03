#ifndef GRID_H
#define GRID_H
#include <vector>
#include "Point.h"

class Grid
{
private:
    static const int MAX_ROW = 10;
    static const int MAX_COLUMN = 10;
//    char GRID[MAX_ROW][MAX_COLUMN] = {{'0'}};
    int row, column;
    std::string location;
//    const std::vector<char> MAP = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};


public:
    Point point;
    char GRID[MAX_ROW][MAX_COLUMN] = {{'0'}};
    const std::vector<char> MAP = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    Grid();
    Grid(int &row, int &column);
    int getRow() const;
    int getColumn() const;
    void createGrid();
    void printGrid();
    Grid chooseGridLoc(const std::string &choice);
    void updateGrid(Grid &grid);
    void printColumnLabel();
    void clearGrid();

};

#endif