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
  * ShareOppsUnitTest.h implementation file of ShareOppsUnitTest interface
  */

#ifndef SHARED_OPS_UNIT_TEST_H
#define SHARED_OPS_UNIT_TEST_H

#include <cassert>
#include "../SharedOps.h"
#include "../Direction.h"
#include "../Point.h"
#include "../Matrix4.h"
#include "../Matrix3.h"


/**
 * Test the Point vector resulting from adding the Direction d to the Point p
 * @param p is the Point vector
 * @param d is the Direction vector
 * @param expected is the value of the expected Point vector
 */
void testAddOperator(Point p, Direction d, Point expected);



/**
 * Test the Direction vector resulting from substracting the Point p to the Point q
 * @param p is the first Point vector
 * @param q is the second Point vector
 * @param expected is the value of the expected Direction vector
 */
void testSubOperator(Point p, Point q, Direction expected);



/**
 * Test the Direction vector resulting from multiplying the 4x4 transformation matrix t to the Direction d
 * @param t is the transformation matrix
 * @param d is the Direction vector
 * @param expected is the value of the expected Direction vector
 */
void testMultiplyMatrix4Direction(Matrix4 t, Direction d, Direction expected);



/**
 * Test the Point vector resulting from multiplying the 4x4 transformation matrix t to the Point p
 * @param t is the transformation matrix
 * @param p is the Point vector
 * @param expected is the value of the expected Point vector
 */
void testMultiplyMatrix4Point(Matrix4 t, Point p, Point expected);



/**
 * Test the Direction vector resulting from multiplying the 3x3 transformation matrix t to the Direction d
 * @param t is the transformation matrix
 * @param d is the Direction vector
 * @param expected is the value of the expected Direction vector
 */
void testMultiplyMatrix3Direction(Matrix3 t, Direction d, Direction expected);



/**
 * Test the Point vector resulting from multiplying the 3x3 transformation matrix t to the Point p
 * @param t is the transformation matrix
 * @param p is the Point vector
 * @param expected is the value of the expected Point vector
 */
void testMultiplyMatrix3Point(Matrix3 t, Point p, Point expected);


#endif 