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
  * Point.h interface file of Point module
  */
#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

using namespace std;


/*
 * Definition of data type Point
 */
struct Point {
    // coordinate vector
    float c[3];

    /**
     * Build a Point type object
     * @param x x-coordinate
     * @param y y-coordinate
     * @param z z-coordinate
     * @returns a Point type object
     */
    Point(float x, float y, float z);

    string toString();

    /**
     * Default builder without parameters
     */
    Point();
};



/**
 * Checks if two POint vectors are equal
 * @param d is the Point p
 * @param q is the Point q
 * @returns true if the two Point vectors p and q are equal and
 *          false in any other case
 */
bool operator == (Point p, Point q);



#endif 