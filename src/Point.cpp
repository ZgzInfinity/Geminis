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


/**
 * Checks if two POint vectors are equal
 * @param d is the Point p
 * @param q is the Point q
 * @returns true if the two Point vectors p and q are equal and
 *          false in any other case
 */
bool operator == (Point p, Point q){
    return p.c[0] == q.c[0] && p.c[1] == q.c[1] && p.c[2] == q.c[2];
}