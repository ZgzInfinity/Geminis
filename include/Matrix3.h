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
 * Matrix3.h interface file of the Matrix3 module
 */

#ifndef MATRIX3_H
#define MATRIX3_H

#include "cmath"
#include "Direction.h"
#include "Point.h"

struct Matrix3{


    float c[3][3];

    /**
     * Default builder without parameters
     */
     Matrix3();



     /**
      * Obtains the scaling 3x3 matrix using the coefficients x,y and z
      * @param x is the first coefficient
      * @param y is the second coefficient
      * @param z is the third coefficient
      * returns the scaling 3x3 matrix using the coefficients x,y and z
      */
     static Matrix3 scale(float x, float y, float z);



    /**
     * Gets the rotation matrix on the x-axis with angle theta
     * @param theta is the angle
     * @returns the rotation matrix on the x-axis with angle theta
     */
     static Matrix3 rotationX(float theta);



    /**
     * Gets the rotation matrix on the y-axis with angle theta
     * @param theta is the angle
     * @returns the rotation matrix on the y-axis with angle theta
     */
     static Matrix3 rotationY(float theta);



     /**
      * Gets the rotation matrix on the z-axis with angle theta
      * @param theta is the angle
      * @returns the rotation matrix on the z-axis with angle theta
      */
     static Matrix3 rotationZ(float theta);



     /**
      * Gets the base change matrix using the address vectors i, j and k 
      * @param i is the first Direction vector
      * @param j is the second Direction vector
      * @param k is the third Direction vector
      * @returns the base change matrix using the address vectors i, j and k
      */
     static Matrix3 changeBase(Direction i, Direction j, Direction k);



     /**
      * Gets the inverse of a matrix
      * @param a is the matrix 
      * @returns the inverse matrix of the matrix a
      */
     static Matrix3 inverse(Matrix3 a);
     


     /**
      * Gets the 3x3 matrix resulting from multiplying matrices a and b
      * @param a is the first 3x3 matrix
      * @param b is the second 3x3 matrix
      * @returns the 3x3 matrix resulting from multiplying matrices a and b
      */
     friend Matrix3 operator * (Matrix3 a, Matrix3 b);



     /**
     * Checks if two Matrix3 matrixes are equal
     * @param m1 is the first matrix
     * @param m2 is the second matrix
     * @returns true if the two Matrix3 matrixes m1 and m2 are equal and
     *          false in any other case
     */
    friend bool operator == (Matrix3 m1, Matrix3 m2);


    /**
     * Checks all the operations that work with Direction and Point vectors
     */
    friend void runSharedOpsUnitTests();

};



#endif