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
 * Matrix.h interface file of the Matrix module
 */

#ifndef MATRIX4_UNIT_TEST_H
#define MATRIX4_UNIT_TEST_H

#include <cassert>

#include "cmath"
#include "../Direction.h"
#include "../Point.h"
#include "../Matrix4.h"


void testScale(float x, float y, float z, Matrix4 expected);



void testRotationX(float theta, Matrix4 expected);



void testRotationY(float theta, Matrix4 expected);



void testRotationZ(float theta, Matrix4 expected);



void testChangeBase(Direction i, Direction j, Direction k, Point o, Matrix4 expected);



void testInverse(Matrix4 a, Matrix4 expected);


/**
 * Test the Matrix4 matrix resulting from muliplying the Matrix4 m1 by the Matrix4 m2
 * @param m1 is the first Matrix4 matrix
 * @param m2 is the second Matrix4 matrix
 * @param expected is the value of the expected Matrix4 matrix
 */
void testMulOperator(Matrix4 m1, Matrix4 m2, Matrix4 expected);



#endif