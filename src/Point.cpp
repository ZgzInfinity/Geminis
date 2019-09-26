#include "../include/Point.h"

Point::Point(float x, float y, float z) {
    c[0] = x;
    c[1] = y;
    c[2] = z;
    c[3] = 1;
}