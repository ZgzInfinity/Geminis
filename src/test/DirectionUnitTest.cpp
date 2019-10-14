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
  * DirectionUnitTest.cpp implementation file of DirectionUnitTest module
  */

#include <cmath>
#include "../../include/test/DirectionUnitTest.h"



/**
 * Test the Direction vector resulting from adding the Direction d to the Direction e
 * @param d is the first Direction vector
 * @param e is the second Direction vector
 * @param expected is the value of the expected Direction vector
 */
void testPlusOperator(Direction d, Direction e, Direction expected){
    Direction result = d + e;
    assert(result == expected);
}



/**
 * Test the Direction vector resulting from substracting the Direction d to the Direction e
 * @param d is the first Direction vector
 * @param e is the second Direction vector
 * @param expected is the value of the expected Direction vector 
 */
void testSubOperator(Direction d, Direction e, Direction expected){
    Direction result = d - e;
    assert(result == expected);
}



/**
 * Test the Direction vector resulting from multiplying the Direction d by the scalar s
 * @param d is the Direction vector
 * @param s is the scalar value
 * @param expected is the value of the expected vector 
 */
void testMultiplyOperator(Direction d, float s, Direction expected){
    Direction result = d * s;
    assert(result == expected);
}



/**
 * Test the Direction vector resulting from multiplying the Direction d by the scalar s
 * @param d is the Direction vector
 * @param s is the scalar value
 * @param expected is the value of the expected vector 
 */
void testDivOperator(Direction d, float s, Direction expected){
    Direction result = d / s;
    assert(result == expected);
}



/**
 * Test the calculation of the module of a Direction vector 
 * @param d is the Direction vector
 * @param expected is the value of the expected result
 */
void testMod(Direction d, float expected){
    float result = mod(d);
    assert(result == expected);
}



/**
 * Test the calculation of scalar product of the Direction vectors d and e 
 * @param d is the fisrt Direction vector 
 * @param e is the second Direction vector
 * @param expected is the value of the expected result
 */
void testDot(Direction d, Direction e, float expected){
    float result = dot(d, e);
    assert(result == expected);
}



/**
 * Test the calculation of cross product of the Direction vectors d and e 
 * @param d is the fisrt Direction vector 
 * @param e is the second Direction vector
 * @param f is the vector result of making the vector product of the vectors d and e
 */
void testCross(Direction d, Direction e, Direction f){
    Direction result = cross(d, e);
    assert(result == f);
}


