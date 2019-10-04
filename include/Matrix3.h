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

#ifndef MATRIX3_H
#define MATRIX3_H

#include "cmath"
#include "Direction.h"
#include "Point.h"

struct Matrix3
{
private:
    
    /**
     * Default builder without parameters
     */
     Matrix3();

public:

    float c[3][3];


     Matrix3 scale(float x, float y, float z);




     Matrix3 rotationX(float theta);




     Matrix3 rotationY(float theta);




     Matrix3 rotationZ(float theta);



     Matrix3 changeBase(Direction i, Direction j, Direction k);



     Matrix3 reverse(Matrix3 a);
     

     friend Matrix3 operator* (Matrix3 a, Matrix3 b);

};



#endif