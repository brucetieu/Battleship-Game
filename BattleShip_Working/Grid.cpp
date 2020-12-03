// Implement function declarations in Grid.h

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Grid.h"

using namespace std;

/**
 * Default constructor. Create the blank Grid.
 */
Grid::Grid() {
    for (row = 0; row < MAX_ROW; row++) {
        for (column = 0; column < MAX_COLUMN; column++) {
            GRID[row][column] = '#';
        }
    }
}

/**
 * Parameterized constructor which initializes the row and column of the Grid.
 * @param row
 * @param column
 */
Grid::Grid(int &row, int &column) {
    this->row = row;
    this->column = column;
}


/**
 * Get the row.
 * @return The row from 0-9.
 */
int Grid::getRow() const { return this->row; }

/**
 * Get the column.
 * @return The column from 0-9.
 */
int Grid::getColumn() const { return this->column; }

/**
 * Get the mapping of alphabets.
 * @return The vector.
 */
vector<char> Grid::getMAP() const { return MAP; }

/**
 * Print the column labels.
 */
void Grid::printColumnLabel() const {
    cout << setw(4);
    for (int i = 0; i < MAX_ROW; i++) {
        cout << i + 1 << " ";
    }
    cout << endl;
}

/**
 * Clear the Grid.
 */
Grid::~Grid() {
    for (row = 0; row < MAX_ROW; row++) {
        for (column = 0; column < MAX_COLUMN; column++) {
            GRID[row][column] = '#';
        }
    }
}

/**
 * Overload output stream << operator to print the Grid.
 * @param output The output stream.
 * @param grid The Grid object.
 * @return The ostream object.
 */
ostream& operator << (ostream& output, const Grid &grid) {
    int row, column;
    output << "=================================" << endl;
    grid.printColumnLabel();
    for (row = 0; row < Grid::MAX_ROW; row++) {
        output << grid.getMAP()[row] << "  ";
        for (column = 0; column < Grid::MAX_COLUMN; column++) {
            cout << grid.GRID[row][column] << " ";
        }
        output << endl;
    }
    output << "=================================" << endl;
    return output;
}