#ifndef UTILS_H
#define UTILS_H

struct Point
{
    float x, y;

    Point(float newX, float newY) {
        x = newX;
        y = newY;
    }

    float Slope(Point p2) {

        float slope = (p2.y - y) / (p2.x - x);

        return slope;
    }
};


#endif