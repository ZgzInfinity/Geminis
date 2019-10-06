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
 * Matrix4.h interface file of the Matrix4 module
 */

#ifndef MATRIX4_H
#define MATRIX4_H

#include "cmath"
#include "Direction.h"
#include "Point.h"

struct Matrix4{


    float c[4][4];

    /**
     * Default builder without parameters
     */
     Matrix4();



    /**
     * Build a Direction type object
     * @param x x-coordinate
     * @param y y-coordinate
     * @param z z-coordinate
     * @returns a Direction type object
     */
     static Matrix4 translation(float x, float y, float z);



    /**
     * Obtains the scaling 3x3 matrix using the coefficients x,y and z
     * @param x is the first coefficient
     * @param y is the second coefficient
     * @param z is the third coefficient
     * returns the scaling 3x3 matrix using the coefficients x,y and z
     */
     static Matrix4 scale(float x, float y, float z);



    /**
     * Gets the rotation matrix on the x-axis with angle theta
     * @param theta is the angle
     * @returns the rotation matrix on the x-axis with angle theta
     */
     static Matrix4 rotationX(float theta);



    /**
     * Gets the rotation matrix on the y-axis with angle theta
     * @param theta is the angle
     * @returns the rotation matrix on the y-axis with angle theta
     */
     static Matrix4 rotationY(float theta);



    /**
     * Gets the rotation matrix on the z-axis with angle theta
     * @param theta is the angle
     * @returns the rotation matrix on the z-axis with angle theta
     */
     static Matrix4 rotationZ(float theta);



    /**
     * Gets the base change matrix using the address vectors i, j and k 
     * @param i is the first Direction vector
     * @param j is the second Direction vector
     * @param k is the third Direction vector
     * @returns the base change matrix using the address vectors i, j and k
     */
     static Matrix4 changeBase(Direction i, Direction j, Direction k, Point o);



    /**
     * Gets the inverse of a matrix
     * @param a is the matrix 
     * @returns the inverse matrix of the matrix a
     */
     static Matrix4 inverse(Matrix4 a);
     


    /**
     * Gets the 4x4 matrix resulting from multiplying matrices a and b
     * @param a is the first 4x4 matrix
     * @param b is the second 4x4 matrix
     * @returns the 4x4 matrix resulting from multiplying matrices a and b
     */
     friend Matrix4 operator * (Matrix4 a, Matrix4 b);



     /**
     * Checks if two Matrix4 matrixes are equal
     * @param m1 is the first matrix
     * @param m2 is the second matrix
     * @returns true if the two Matrix4 matrixes m1 and m2 are equal and
     *          false in any other case
     */
     friend bool operator == (Matrix4 m1, Matrix4 m2);



    /**
     * Checks all the operations that work with Direction and Point vectors
     */
     friend void runSharedOpsUnitTests();

};



#endif