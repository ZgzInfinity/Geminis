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
 * Matrix3.cpp implementation file of the Matrix3 module
 */

#include "../include/Matrix3.h"


/**
 * Default builder without parameters
 */
Matrix3::Matrix3(){}
    


/**
 * Obtains the scaling 3x3 matrix using the coefficients x,y and z
 * @param x is the first coefficient
 * @param y is the second coefficient
 * @param z is the third coefficient
 * returns the scaling 3x3 matrix using the coefficients x,y and z
 */
Matrix3 Matrix3::scale(float x, float y, float z){
    Matrix3 m;
    m.c[0][0] = x;  m.c[0][1] = 0;  m.c[0][2] = 0;
    m.c[1][0] = 0;  m.c[1][1] = y;  m.c[1][2] = 0;
    m.c[2][0] = 0;  m.c[2][1] = 0;  m.c[2][2] = z;
    return m;
}



/**
 * Gets the rotation matrix on the x-axis with angle theta
 * @param theta is the angle
 * @returns the rotation matrix on the x-axis with angle theta
 */
Matrix3 Matrix3::rotationX(float t){
    Matrix3 m;
    m.c[0][0] = 1;  m.c[0][1] = 0;       m.c[0][2] = 0;
    m.c[1][0] = 0;  m.c[1][1] = cos(t);  m.c[1][2] = -sin(t);
    m.c[2][0] = 0;  m.c[2][1] = sin(t);  m.c[2][2] = cos(t);
    return m;
}



/**
 * Gets the rotation matrix on the y-axis with angle theta
 * @param theta is the angle
 * @returns the rotation matrix on the y-axis with angle theta
 */
Matrix3 Matrix3::rotationY(float t){
    Matrix3 m;
    m.c[0][0] = cos(t);   m.c[0][1] = 0;  m.c[0][2] = sin(t);
    m.c[1][0] = 0;        m.c[1][1] = 1;  m.c[1][2] = 0;
    m.c[2][0] = -sin(t);  m.c[2][1] = 0;  m.c[2][2] = cos(t);
    return m;
}



/**
 * Gets the rotation matrix on the z-axis with angle theta
 * @param theta is the angle
 * @returns the rotation matrix on the z-axis with angle theta
 */
Matrix3 Matrix3::rotationZ(float t){
    Matrix3 m;
    m.c[0][0] = cos(t);  m.c[0][1] = -sin(t);  m.c[0][2] = 0;
    m.c[1][0] = sin(t);  m.c[1][1] = cos(t);   m.c[1][2] = 0;
    m.c[2][0] = 0;       m.c[2][1] = 0;        m.c[2][2] = 1;
    return m;
}



/**
 * Gets the base change matrix using the address vectors i, j and k 
 * @param i is the first Direction vector
 * @param j is the second Direction vector
 * @param k is the third Direction vector
 * @returns the base change matrix using the address vectors i, j and k
 */
Matrix3 Matrix3::changeBase(Direction i, Direction j, Direction k){
    Matrix3 m;
    m.c[0][0] = i.c[0];  m.c[0][1] = j.c[0];  m.c[0][2] = k.c[0];
    m.c[1][0] = i.c[1];  m.c[1][1] = j.c[1];  m.c[1][2] = k.c[1];
    m.c[2][0] = i.c[2];  m.c[2][1] = j.c[2];  m.c[2][2] = k.c[2];
    return m;
}



/**
 * Gets the inverse of a matrix
 * @param a is the matrix 
 * @returns the inverse matrix of the matrix a
 */
Matrix3 Matrix3::inverse(Matrix3 m){
    float det = m.c[0][0] * m.c[1][1] * m.c[2][2] - m.c[2][1] * m.c[1][2] -
                m.c[0][1] * m.c[1][0] * m.c[2][2] - m.c[1][2] * m.c[2][0] +
                m.c[0][2] * m.c[1][0] * m.c[2][1] - m.c[1][1] * m.c[2][0];
    Matrix3 r;
    if(det != 0){
        float idet = 1 / det;
        r.c[0][0] = (m.c[1][1] * m.c[2][2] - m.c[2][1] * m.c[1][2]) * idet;
        r.c[0][1] = (m.c[0][2] * m.c[2][1] - m.c[0][1] * m.c[2][2]) * idet;
        r.c[0][2] = (m.c[0][1] * m.c[1][2] - m.c[0][2] * m.c[1][1]) * idet;
        r.c[1][0] = (m.c[1][2] * m.c[2][0] - m.c[1][0] * m.c[2][2]) * idet;
        r.c[1][1] = (m.c[0][0] * m.c[2][2] - m.c[0][2] * m.c[2][0]) * idet;
        r.c[1][2] = (m.c[1][0] * m.c[0][2] - m.c[0][0] * m.c[1][2]) * idet;
        r.c[2][0] = (m.c[1][0] * m.c[2][1] - m.c[2][0] * m.c[1][1]) * idet;
        r.c[2][1] = (m.c[2][0] * m.c[0][1] - m.c[0][0] * m.c[2][1]) * idet;
        r.c[2][2] = (m.c[0][0] * m.c[1][1] - m.c[1][0] * m.c[0][1]) * idet;
    }
    return r;
}



/**
 * Gets the 3x3 matrix resulting from multiplying matrices a and b
 * @param a is the first 3x3 matrix
 * @param b is the second 3x3 matrix
 * @returns the 3x3 matrix resulting from multiplying matrices a and b
 *
 */
Matrix3 operator* (Matrix3 a, Matrix3 b){
    Matrix3 r;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            r.c[i][j] = 0.0;      
            for(int k = 0; k < 3; k++){
                r.c[i][j] = r.c[i][j] + a.c[i][k] * b.c[k][j];
            }
        }
    }
    return r;
}



/**
     * Checks if two Matrix3 matrixes are equal
     * @param m1 is the first matrix
     * @param m2 is the second matrix
     * @returns true if the two Matrix3 matrixes m1 and m2 are equal and
     *          false in any other case
     */
bool operator == (Matrix3 m1, Matrix3 m2){
    return m1.c[0][0] == m2.c[0][0] && m1.c[0][1] == m2.c[0][1] && m1.c[0][2] == m2.c[0][2]
        && m1.c[1][0] == m2.c[1][0] && m1.c[1][1] == m2.c[1][1] && m1.c[1][2] == m2.c[1][2]
        && m1.c[2][0] == m2.c[2][0] && m1.c[2][1] == m2.c[2][1] && m1.c[2][2] == m2.c[2][2];
}


