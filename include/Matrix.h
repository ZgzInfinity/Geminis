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

#ifndef MATRIX_H
#define MATRIX_H

#include "cmath"
#include "Direction.h"
#include "Point.h"

struct Matrix
{
    float m[4][4];

    /**
     * Default builder without parameters
     */
     Matrix();

    /**
     * Build a Direction type object
     * @param x x-coordinate
     * @param y y-coordinate
     * @param z z-coordinate
     * @returns a Direction type object
     */
     void matrixTranslation(float x, float y, float z);




     void matrixScale(float x, float y, float z);




     void matrixRotationX(float theta);




     void matrixRotationY(float theta);




     void matrixRotationZ(float theta);




     void matrixChangeOfBase(Direction i, Direction j, Direction k, Point o);

};



Matrix mul(Matrix a, Matrix b);

#endif