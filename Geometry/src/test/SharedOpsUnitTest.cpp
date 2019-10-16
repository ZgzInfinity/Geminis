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
  * ShareOppsUnitTest.cpp implementation file of ShareOppsUnitTest module
  */

#include "../../include/test/SharedOpsUnitTest.h"



/**
 * Test the Point vector resulting from adding the Direction d to the Point p
 * @param p is the Point vector
 * @param d is the Direction vector
 * @param expected is the value of the expected Point vector
 */
void testAddOperator(Point p, Direction d, Point expected){
    Point result = p + d;
    assert(result == expected);
}



/**
 * Test the Direction vector resulting from substracting the Point p to the Point q
 * @param p is the first Point vector
 * @param q is the second Point vector
 * @param expected is the value of the expected Direction vector
 */
void testSubOperator(Point p, Point q, Direction expected){
    Direction result = p - q;
    assert(result == expected);
}



/**
 * Test the Direction vector resulting from multiplying the 4x4 transformation matrix t to the Direction d
 * @param t is the transformation matrix
 * @param d is the Direction vector
 * @param expected is the value of the expected Direction vector
 */
void testMultiplyMatrix4Direction(Matrix4 t, Direction d, Direction expected){
    Direction result = t * d;
    assert(result == expected);
}



/**
 * Test the Point vector resulting from multiplying the 4x4 transformation matrix t to the Point p
 * @param t is the transformation matrix
 * @param p is the Point vector
 * @param expected is the value of the expected Point vector
 */
void testMultiplyMatrix4Point(Matrix4 t, Point p, Point expected){
    Point result = t * p;
    assert(result == expected);
}



/**
 * Test the Direction vector resulting from multiplying the 3x3 transformation matrix t to the Direction d
 * @param t is the transformation matrix
 * @param d is the Direction vector
 * @param expected is the value of the expected Direction vector
 */
void testMultiplyMatrix3Direction(Matrix3 t, Direction d, Direction expected){
    Direction result = t * d;
    assert(result == expected);
}



/**
 * Test the Point vector resulting from multiplying the 3x3 transformation matrix t to the Point p
 * @param t is the transformation matrix
 * @param p is the Point vector
 * @param expected is the value of the expected Point vector
 */
void testMultiplyMatrix3Point(Matrix3 t, Point p, Point expected){
    Point result = t * p;
    assert(result == expected);
}

