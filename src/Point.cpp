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
  * Point.cpp implementation file of Point module
  */
#include "../include/Point.h"


/**
 * Build a Point type object
 * @param x x-coordinate
 * @param y y-coordinate
 * @param z z-coordinate
 * @returns a Point type object
 */
Point::Point(float x, float y, float z) {
    c[0] = x;
    c[1] = y;
    c[2] = z;
    c[3] = 1;
}


/**
 * Default builder without parameters
 */
Point::Point(){}

Point add(Point p, Point q){
  return Point(p.c[0] + q.c[0], p.c[1] + q.c[1], p.c[2] + q.c[2]);
}