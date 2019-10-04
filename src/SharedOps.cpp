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
Point operator + (Point p, Direction d){
    return Point(p.c[0] + d.c[0], p.c[1] + d.c[1], p.c[2] + d.c[2]);
}



/**
 * Obtanis the result of subtracting the point p from point q as a direction
 * @param p is the origin point
 * @param q is the destination point
 * @returns the direction between both points
 */
Direction operator - (Point p, Point q){
    return Direction(p.c[0] - q.c[0], p.c[1] - q.c[1], p.c[2] - q.c[2]);
}



Direction operator * (Matrix4 t, Direction d){
    Direction r = Direction();
    r.c[0] = t.c[0][0] * d.c[0] + t.c[0][1] * d.c[1] + t.c[0][2] * d.c[2];
    r.c[1] = t.c[1][0] * d.c[0] + t.c[1][1] * d.c[1] + t.c[1][2] * d.c[2];
    r.c[2] = t.c[2][0] * d.c[0] + t.c[2][1] * d.c[1] + t.c[2][2] * d.c[2];
    return r;
}


Point operator * (Matrix4 t, Point p){
    Point r = Point();
    r.c[0] = t.c[0][0] * p.c[0] + t.c[0][1] * p.c[1] + t.c[0][2] * p.c[2] + t.c[0][3];
    r.c[1] = t.c[1][0] * p.c[0] + t.c[1][1] * p.c[1] + t.c[1][2] * p.c[2] + t.c[1][3];
    r.c[2] = t.c[2][0] * p.c[0] + t.c[2][1] * p.c[1] + t.c[2][2] * p.c[2] + t.c[2][3];
    return r;
}



Direction operator * (Matrix3 t, Direction d){
    Direction r = Direction();
    r.c[0] = t.c[0][0] * d.c[0] + t.c[0][1] * d.c[1] + t.c[0][2] * d.c[2];
    r.c[1] = t.c[1][0] * d.c[0] + t.c[1][1] * d.c[1] + t.c[1][2] * d.c[2];
    r.c[2] = t.c[2][0] * d.c[0] + t.c[2][1] * d.c[1] + t.c[2][2] * d.c[2];
    return r;
}


Point operator * (Matrix3 t, Point p){
    Point r = Point();
    r.c[0] = t.c[0][0] * p.c[0] + t.c[0][1] * p.c[1] + t.c[0][2] * p.c[2];
    r.c[1] = t.c[1][0] * p.c[0] + t.c[1][1] * p.c[1] + t.c[1][2] * p.c[2];
    r.c[2] = t.c[2][0] * p.c[0] + t.c[2][1] * p.c[1] + t.c[2][2] * p.c[2];
    return r;
}



