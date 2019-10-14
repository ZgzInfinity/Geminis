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
  * Direction.cpp implementation file of Direction module
  */

#include <cmath>
#include "../include/Direction.h"


/**
 * Build a Direction type object
 * @param x x-coordinate
 * @param y y-coordinate
 * @param z z-coordinate
 * @returns a Direction type object
 */
Direction::Direction(float x, float y, float z) {
    c[0] = x;
    c[1] = y;
    c[2] = z;
}


/**
 * Default builder without parameters
 */
Direction::Direction(){
    c[0] = 0;
    c[1] = 0;
    c[2] = 0;
}

string Direction::toString(){
    return "Direction(" + to_string(c[0]) + "," + to_string(c[1]) + "," + to_string(c[2]) + ")";
}


/**
 * Obtains the direction resulting from adding the Direction d to the Direction e 
 * @param d is the first direction
 * @param e is the second direction
 * @returns the direction resulting from adding the Direction e to the Direction d
 */
Direction operator + (Direction d, Direction e){
    return Direction(d.c[0] + e.c[0], d.c[1] + e.c[1], d.c[2] + e.c[2]);
}



/**
 * Gets the direction resulting from substracting the Direction d to the Direction e 
 * @param d is the first direction
 * @param e is the second direction
 * @returns the direction resulting from substracting the Direction e to the Direction d
 */
Direction operator - (Direction d, Direction e){
    return Direction(d.c[0] - e.c[0], d.c[1] - e.c[1], d.c[2] - e.c[2]);
}



/**
 * Gets the direction resulting from multiplying the Direction d by the scalar s
 * @param d is the direction
 * @param s is the scalar value
 * @returns the direction resulting from multiplying the Direction d by the scalar s
 */
Direction operator * (Direction d, float s){
    return Direction(d.c[0] * s, d.c[1] * s, d.c[2] * s);
}



/**
 * Gets the direction resulting from dividing the Direction d by the scalar s
 * @param d is the direction
 * @param s is the scalar value
 * @returns the direction resulting from dividing the Direction d by the scalar s
 */
Direction operator / (Direction d, float s){
    if(s != 0){
        return Direction(d.c[0] / s, d.c[1] / s, d.c[2] / s);
    }
    else{
        return Direction(-1, -1, -1); // Error, can't divide by 0
    }
}



/**
 * Checks if two Direction vectors are equal
 * @param d is the direction
 * @param s is the scalar value
 * @returns true if the two Direction vectors d and e are equal and
 *          false in any other case
 */
bool operator == (Direction d, Direction e){
    return abs(d.c[0] - e.c[0]) < 1e-5F && abs(d.c[1] - e.c[1]) < 1e-5F && abs(d.c[2] - e.c[2]) < 1e-5F;
}



/**
 * Gets the Direction modulus d
 * @param d is the direction
 * @returns the Direction modulus d
 */  
float mod(Direction d){
    return sqrt(d.c[0] * d.c[0] + d.c[1] * d.c[1] + d.c[2] * d.c[2]);
}



/**
 * Gets the scalar product from the Directions d and e
 * @param d is the direction
 * @param s is the scalar value
 * @returns he scalar product from the Directions d and e
 */
float dot(Direction d, Direction e){
    return d.c[0] * e.c[0] + d.c[1] * e.c[1] + d.c[2] * e.c[2];
}



/**
 * Gets the vector alar product from the Direction d and e
 * @param d is the first direction
 * @param e is the second direction
 * @returns the vector alar product from the Direction d and e
 */
Direction cross(Direction d, Direction e){
    return Direction(d.c[1] * e.c[2] - d.c[2] * e.c[1],
        d.c[2] * e.c[0] - d.c[0] * e.c[2], d.c[0] * e.c[1] - d.c[1] * e.c[0]);
}

