// Declare function declarations for creating the Board.

#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid {
private:

    static const int MAX_ROW = 10;
    static const int MAX_COLUMN = 10;
    int row, column;
    std::vector<char> MAP = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                             'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


public:
    char GRID[MAX_ROW][MAX_COLUMN] = {{'0'}};

    Grid();

    ~Grid();

    Grid(int &row, int &column);

    int getRow() const;

    int getColumn() const;


    void printGrid();

    void printColumnLabel();

    std::vector<char> getMAP();

};

#endif