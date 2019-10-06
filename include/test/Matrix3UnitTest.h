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
 * Matrix3UnitTest.h interface file of Matrix3UnitTest module
 */

#ifndef MATRIX3_UNIT_TEST_H
#define MATRIX3_UNIT_TEST_H

#include <cassert>
#include <cmath>
#include "../Direction.h"
#include "../Point.h"
#include "../Matrix3.h"



/**
 * test the scaling matrix calculation using the coefficients x, y and z
 * @param x is the first coefficient
 * @param y is the second coefficient
 * @param z is the third coefficient
 * @param expected is the expected escalation matrix
 */ 
void testScale(float x, float y, float z, Matrix3 expected);



/**
 * test the calculation of the rotation matrix on the x-axis using the rotation angle theta
 * @param theta is the rotation angle
 * @param expected is the expected escalation matrix
 */ 
void testRotationX(float theta, Matrix3 expected);



/**
 * test the calculation of the rotation matrix on the y-axis using the rotation angle theta
 * @param theta is the rotation angle
 * @param expected is the expected escalation matrix
 */
void testRotationY(float theta, Matrix3 expected);



/**
 * test the calculation of the rotation matrix on the z-axis using the rotation angle theta
 * @param theta is the rotation angle
 * @param expected is the expected escalation matrix
 */
void testRotationZ(float theta, Matrix3 expected);



/**
 * test the base change matrix calculation using the Direction vectors of the new base i, j and k 
 * @param i is the first Direction vector of the base
 * @param j is the second Direction vector of the base
 * @param k is the third Direction vector of the base
 * @param expected is the expected matrix of applying the base change
 */
void testChangeBase(Direction i, Direction j, Direction k, Matrix3 expected);



/**
 * test the calculation of an inverse 3x3 matrix
 * @param a is the 3x3 matrix 
 * @param expected is the expected inverse matrix
 */
void testInverse(Matrix3 a, Matrix3 expected);



/**
 * Test the Matrix3 matrix resulting from muliplying the Matrix3 m1 by the Matrix3 m2
 * @param m1 is the first Matrix3 matrix
 * @param m2 is the second Matrix3 matrix
 * @param expected is the value of the expected Matrix3 matrix
 */
void testMulOperator(Matrix3 m1, Matrix3 m2, Matrix3 expected);

#endif