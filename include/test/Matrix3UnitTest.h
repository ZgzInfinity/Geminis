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

#ifndef MATRIX3_UNIT_TEST_H
#define MATRIX3_UNIT_TEST_H

#include <cassert>

#include "cmath"
#include "../Direction.h"
#include "../Point.h"
#include "../Matrix3.h"


void testScale(float x, float y, float z, Matrix3 expected);



void testRotationX(float theta, Matrix3 expected);



void testRotationY(float theta, Matrix3 expected);



void testRotationZ(float theta, Matrix3 expected);



void testChangeBase(Direction i, Direction j, Direction k, Matrix3 expected);



void testInverse(Matrix3 a, Matrix3 expected);


/**
 * Test the Matrix3 matrix resulting from muliplying the Matrix3 m1 by the Matrix3 m2
 * @param m1 is the first Matrix3 matrix
 * @param m2 is the second Matrix3 matrix
 * @param expected is the value of the expected Matrix3 matrix
 */
void testMulOperator(Matrix3 m1, Matrix3 m2, Matrix3 expected);

#endif