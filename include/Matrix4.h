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

#ifndef MATRIX4_H
#define MATRIX4_H

#include "cmath"
#include "Direction.h"
#include "Point.h"

struct Matrix4
{
private:
    
    /**
     * Default builder without parameters
     */
     Matrix4();

public:

    float c[4][4];

    /**
     * Build a Direction type object
     * @param x x-coordinate
     * @param y y-coordinate
     * @param z z-coordinate
     * @returns a Direction type object
     */
     static Matrix4 translation(float x, float y, float z);




     static Matrix4 scale(float x, float y, float z);




     static Matrix4 rotationX(float theta);




     static Matrix4 rotationY(float theta);




     static Matrix4 rotationZ(float theta);




     static Matrix4 changeBase(Direction i, Direction j, Direction k, Point o);


     static Matrix4 inverse(Matrix4 a);
     

     friend Matrix4 operator* (Matrix4 a, Matrix4 b);


     /**
     * Checks if two Matrix4 matrixes are equal
     * @param m1 is the first matrix
     * @param m2 is the second matrix
     * @returns true if the two Matrix4 matrixes m1 and m2 are equal and
     *          false in any other case
     */
     friend bool operator == (Matrix4 m1, Matrix4 m2);


     friend void runSharedOpsUnitTests();

};



#endif