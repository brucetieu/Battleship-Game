// Declare function declarations for creating the Board.

#ifndef GRID_H
#define GRID_H

#include <vector>
#include <ostream>

class Grid {
private:

    static const int MAX_ROW = 10;  // Board is 10 x 10
    static const int MAX_COLUMN = 10;
    int row, column;
    std::vector<char> MAP = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                             'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};  // List of alphabets to map a character to an index.


public:
    char GRID[MAX_ROW][MAX_COLUMN] = {{'0'}};  // Initialize empty 2D array.

    Grid();

    ~Grid();

    Grid(int &row, int &column);

    int getRow() const;

    int getColumn() const;

    void printColumnLabel() const;

    std::vector<char> getMAP() const;

    friend std::ostream &operator<<( std::ostream &output, const Grid &grid );  // Overload ostream >> operator.

};

#endif