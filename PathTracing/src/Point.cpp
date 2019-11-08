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
}


/**
 * Default builder without parameters
 */
Point::Point(){
    c[0] = 0;
    c[1] = 0;
    c[2] = 0;
}

string Point::toString(){
    return "Point(" + to_string(c[0]) + "," + to_string(c[1]) + "," + to_string(c[2]) + ")";
}


/**
 * Checks if two POint vectors are equal
 * @param d is the Point p
 * @param q is the Point q
 * @returns true if the two Point vectors p and q are equal and
 *          false in any other case
 */
bool operator == (Point p, Point q){
    return abs(p.c[0] - q.c[0]) < 1e-5F && abs(p.c[1] - q.c[1]) < 1e-5F && abs(p.c[2] - q.c[2]) < 1e-5F;
}

