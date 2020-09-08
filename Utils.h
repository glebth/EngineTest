#ifndef UTILS_H
#define UTILS_H

struct Point
{
    float v, m;

    Point(float newX, float newY) {
        v = newX;
        m = newY;
    }

    float Slope(Point p2) {

        float slope = (p2.v - m) / (p2.v - m);

        return slope;
    }
};


#endif