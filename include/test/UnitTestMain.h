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
 * UnitTestMain.h interface file of UnitTestMain module
 */

#ifndef UNIT_TEST_MAIN_H
#define UNIT_TEST_MAIN_H

#include "DirectionUnitTest.h"
#include "InterplanetaryConnectionUnitTest.h"
#include "Matrix3UnitTest.h"
#include "Matrix4UnitTest.h"
#include "PlanetUnitTest.h"
#include "PlanetaryStationUnitTest.h"
#include "PointUnitTest.h"
#include "SharedOpsUnitTest.h"



/**
 * proves that all operations working with Direction vectors function correctly
 */
void runDirectionUnitTests();



/**
 * proves that all operations working with direction vectors and point vectors function correctly
 */
void runSharedOpsUnitTests();



/**
 * proves that all operations working with 3x3 transformation matrices work correctly
 */
void runMatrix3x3Test();



/**
 * proves that all operations working with 4x4 transformation matrices work correctly
 */
void runMatrix4x4Test();



/**
 * test that all the tests work correctly
 */
void runAllUnitTests();


#endif