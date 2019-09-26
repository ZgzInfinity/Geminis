#include "../include/SharedOps.h"

/**
 * 
 */
Point add(Point p, Direction d){
    return Point(p.c[0] + d.c[0], p.c[1] + d.c[1], p.c[2] + d.c[2]);
}

/**
 * 
 */
Direction sub(Point p, Point q){
    return Direction(p.c[0] - q.c[0], p.c[1] - q.c[1], p.c[2] - q.c[2]);
}