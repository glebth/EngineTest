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

        float slope = (p2.m - m) / (p2.v - v);

        return slope;
    }
};


#endif