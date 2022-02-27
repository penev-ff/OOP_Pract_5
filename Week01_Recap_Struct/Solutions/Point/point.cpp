#include "point.hpp"

#include <iostream>
#include <cmath>

void read(Point &point)
{
    std::cin >> point.x >> point.y;
}

void print(const Point &point)
{
    std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
}

double distanceCentre(const Point &point)
{
    return sqrt(point.x * point.x + point.y * point.y);
}

double distanceFromTo(const Point &pointA, const Point &pointB)
{
    //   ______________________________________________
    // \/ (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)

    // https://en.wikipedia.org/wiki/Euclidean_distance

    int dx = pointA.x - pointB.x;
    int dy = pointA.y - pointB.y;

    return sqrt(pow(dx, 2) + pow(dy, 2));
}

bool isInsideCircle(unsigned int radius, const Point &point)
{
    double dist = distanceCentre(point);

    return dist <= radius;
}
