#include "Point.h"
#include "Grid.h"

Point::Point() {
    xCoord = 0;
    yCoord = 0;
}

Point::Point(int xCoord, int yCoord) {
    this->xCoord = xCoord;
    this->yCoord = yCoord;
}

Point Point::parseLocationToPoint(const std::string &choice) {
    Grid grid;
    int x, y;

    for (int i = 0; i <= grid.MAP.size(); i++) {
        if (choice[0] == grid.MAP[i]) {
            x = i;
        }
    }

    y = stoi(choice.substr(1)) - 1;

    return Point(x, y);
}
