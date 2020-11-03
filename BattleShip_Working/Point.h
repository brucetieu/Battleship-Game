#ifndef POINT_H
#define POINT_H
#include <string>

class Point {

public:
    int xCoord;
    int yCoord;

    Point();
    Point(int xCoord, int yCoord);
    Point parseLocationToPoint(const std::string &choice);
};

#endif