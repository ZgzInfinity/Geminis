/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 

 /*
  * ShareOpps.cpp implementation file of ShareOpps module
  */

#include "../include/SharedOps.h"


/**
 * Gets the destination point resulting from adding the direction d to the point p 
 * @param p is the origin point
 * @param q is the destination point
 * @returns the point resulting from adding the address d to point p
 */
Point add(Point p, Direction d){
    return Point(p.c[0] + d.c[0], p.c[1] + d.c[1], p.c[2] + d.c[2]);
}



/**
 * Obtanis the result of subtracting the point p from point q as a direction
 * @param p is the origin point
 * @param q is the destination point
 * @returns the direction between both points
 */
Direction sub(Point p, Point q){
    return Direction(p.c[0] - q.c[0], p.c[1] - q.c[1], p.c[2] - q.c[2]);
}


Direction mul(Matrix t, Direction d){
    Direction r = Direction();
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            r.c[j] = r.c[j] + t.m[i][j] * d.c[j];
        }
    }
    return r;
}


Point mul(Matrix t, Point p){
    Point r = Point();
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            r.c[j] = r.c[j] + t.m[i][j] * p.c[j];
        }
    }
    return r;
}



