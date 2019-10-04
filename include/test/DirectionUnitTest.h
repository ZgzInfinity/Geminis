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
  * DirectionUnitTest.h interface file of DirectionUnitTest module
  */


#ifndef DIRECTION_UNIT_TEST_H
#define DIRECTION_UNIT_TEST_H

#include <cassert>
#include "../Direction.h"


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
#include "../../include/test/DirectionUnitTest.h"


/**
 * Test the Direction vector resulting from substracting the Direction d to the Direction e
 * @param d is the first Direction vector
 * @param e is the second Direction vector
 * @param expected is the value of the expected Direction vector
 */
void testPlusOperator(Direction d, Direction e, Direction expected);



/**
 * Test the Direction vector resulting from substracting the Direction d to the Direction e
 * @param d is the first Direction vector
 * @param e is the second Direction vector
 * @param expected is the value of the expected Direction vector 
 */
void testSubOperator(Direction d, Direction e, Direction expected);



/**
 * Test the Direction vector resulting from multiplying the Direction d by the scalar s
 * @param d is the Direction vector
 * @param s is the scalar value
 * @param expected is the value of the expected vector 
 */
void testMultiplyOperator(Direction d, float s, Direction expected);



/**
 * Test the Direction vector resulting from multiplying the Direction d by the scalar s
 * @param d is the Direction vector
 * @param s is the scalar value
 * @param expected is the value of the expected vector 
 */
void testDivOperator(Direction d, float s, float expected);



/**
 * Test the calculation of the module of a Direction vector 
 * @param d is the Direction vector
 * @param expected is the value of the expected result
 */
void testMod(Direction d, float expected);



/**
 * Test the calculation of scalar product of the Direction vectors d and e 
 * @param d is the fisrt Direction vector 
 * @param e is the second Direction vector
 * @param expected is the value of the expected result
 */
void testDot(Direction d, Direction e, float expected);



/**
 * Test the calculation of scalar product using the modules of two 
 * vectors and the sine of the beta angle between them 
 * @param dmod is modulus of the fisrt Direction vector
 * @param emod is modulus of the second Direction vector
 * @param beta is the angle between d and e Direction vectors
 * @param expected is the value of the expected result
 */
void testDot(float dmod, float emod, float beta, float expected);



/**
 * Test the vector product in module of the Directions d and e and the sine of the beta angle between them
 * @param d is the first direction
 * @param e is the second direction
 * @param beta is the angle between d and e Direction vectors
 * @param expected is the value of the expected result
 */
void testCross(Direction d, Direction e, float beta, float expected);



/**
 * Test the vector product of the modules dmod and emod and the cosine of the beta angle between them
 * @param dmod is modulus of the fisrt Direction vector
 * @param emod is modulus of the second Direction vector
 * @param beta is the angle between d and e Direction vectors
 * @param expected is the value of the expected result
 */
void testCross(float dmod, float emod, float beta, float expected);



/**
 * Test the calculation of cross product of the Direction vectors d and e 
 * @param d is the fisrt Direction vector 
 * @param e is the second Direction vector
 * @param f is the vector result of making the vector product of the vectors d and e
 */
void testCross(Direction d, Direction e, Direction f);


#endif 