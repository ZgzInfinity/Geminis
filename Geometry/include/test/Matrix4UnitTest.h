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
 * Matrix4UnitTest.h interface file of Matrix4UnitTest module
 */

#ifndef MATRIX4_UNIT_TEST_H
#define MATRIX4_UNIT_TEST_H

#include <cassert>
#include <cmath>
#include "../Direction.h"
#include "../Point.h"
#include "../Matrix4.h"



/**
 * test the scaling matrix calculation using the coefficients x, y and z
 * @param x is the first coefficient
 * @param y is the second coefficient
 * @param z is the third coefficient
 * @param expected is the expected escalation matrix
 */ 
void testScale(float x, float y, float z, Matrix4 expected);



/**
 * test the calculation of the rotation matrix on the x-axis using the rotation angle theta
 * @param theta is the rotation angle
 * @param expected is the expected escalation matrix
 */ 
void testRotationX(float theta, Matrix4 expected);



/**
 * test the calculation of the rotation matrix on the y-axis using the rotation angle theta
 * @param theta is the rotation angle
 * @param expected is the expected escalation matrix
 */
void testRotationY(float theta, Matrix4 expected);



/**
 * test the calculation of the rotation matrix on the z-axis using the rotation angle theta
 * @param theta is the rotation angle
 * @param expected is the expected escalation matrix
 */
void testRotationZ(float theta, Matrix4 expected);



/**
 * test the base change matrix calculation using the Direction vectors of the new base i, j and k 
 * @param i is the first Direction vector of the base
 * @param j is the second Direction vector of the base
 * @param k is the third Direction vector of the base
 * @param expected is the expected matrix of applying the base change
 */
void testChangeBase(Direction i, Direction j, Direction k, Point o, Matrix4 expected);



/**
 * test the calculation of an inverse 4x4 matrix
 * @param a is the 4x4 matrix 
 * @param expected is the expected inverse matrix
 */
//void testInverse(Matrix4 a, Matrix4 expected);

/**
 * test the calculation of 4x4 transpose matrix
 * @param a is the 4x4 matrix 
 * @param expected is the expected transpose matrix
 */
void testTrans(Matrix4 a, Matrix4 expected);



/**
 * Test the Matrix4 matrix resulting from muliplying the Matrix4 m1 by the Matrix4 m2
 * @param m1 is the first Matrix4 matrix
 * @param m2 is the second Matrix4 matrix
 * @param expected is the value of the expected Matrix4 matrix
 */
void testMulOperator(Matrix4 m1, Matrix4 m2, Matrix4 expected);



#endif