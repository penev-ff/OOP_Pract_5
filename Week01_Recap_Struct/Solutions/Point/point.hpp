#pragma once

struct Point
{
    int x;
    int y;
};

//
// Core
void read(Point &point);

void print(const Point &point);

double distanceCentre(const Point& point);

double distanceFromTo(const Point& pointA, const Point& pointB);
//

//
// Bonus
short quadrant(const Point&);

bool isInsideCircle(unsigned int radius, const Point& point);
//