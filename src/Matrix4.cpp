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
 * Matrix4.cpp implementation file of the Matrix4 module
 */


#include "../include/Matrix4.h"



/**
 * Default builder without parameters
 */
Matrix4::Matrix4(){}
    


/**
 * Build a Direction type object
 * @param x x-coordinate
 * @param y y-coordinate
 * @param z z-coordinate
 * @returns a Direction type object
 */
Matrix4 Matrix4::translation(float x, float y, float z){
    Matrix4 m;
    m.c[0][0] = 1;  m.c[0][1] = 0;  m.c[0][2] = 0;  m.c[0][3] = x;
    m.c[1][0] = 0;  m.c[1][1] = 1;  m.c[1][2] = 0;  m.c[1][3] = y;
    m.c[2][0] = 0;  m.c[2][1] = 0;  m.c[2][2] = 1;  m.c[2][3] = z;
    m.c[3][0] = 0;  m.c[3][1] = 0;  m.c[3][2] = 0;  m.c[3][3] = 1;
    return m;
}



/**
 * Obtains the scaling 3x3 matrix using the coefficients x,y and z
 * @param x is the first coefficient
 * @param y is the second coefficient
 * @param z is the third coefficient
 * returns the scaling 3x3 matrix using the coefficients x,y and z
 */
Matrix4 Matrix4::scale(float x, float y, float z){
    Matrix4 m;
    m.c[0][0] = x;  m.c[0][1] = 0;  m.c[0][2] = 0;  m.c[0][3] = 0;
    m.c[1][0] = 0;  m.c[1][1] = y;  m.c[1][2] = 0;  m.c[1][3] = 0;
    m.c[2][0] = 0;  m.c[2][1] = 0;  m.c[2][2] = z;  m.c[2][3] = 0;
    m.c[3][0] = 0;  m.c[3][1] = 0;  m.c[3][2] = 0;  m.c[3][3] = 1;
    return m;
}



/**
 * Gets the rotation matrix on the x-axis with angle theta
 * @param theta is the angle
 * @returns the rotation matrix on the x-axis with angle theta
 */
Matrix4 Matrix4::rotationX(float t){
    Matrix4 m;
    m.c[0][0] = 1;  m.c[0][1] = 0;       m.c[0][2] = 0;        m.c[0][3] = 0;
    m.c[1][0] = 0;  m.c[1][1] = cos(t);  m.c[1][2] = -sin(t);  m.c[1][3] = 0;
    m.c[2][0] = 0;  m.c[2][1] = sin(t);  m.c[2][2] = cos(t);   m.c[2][3] = 0;
    m.c[3][0] = 0;  m.c[3][1] = 0;       m.c[3][2] = 0;        m.c[3][3] = 1;
    return m;
}



/**
 * Gets the rotation matrix on the y-axis with angle theta
 * @param theta is the angle
 * @returns the rotation matrix on the y-axis with angle theta
 */
Matrix4 Matrix4::rotationY(float t){
    Matrix4 m;
    m.c[0][0] = cos(t);   m.c[0][1] = 0;  m.c[0][2] = sin(t);  m.c[0][3] = 0;
    m.c[1][0] = 0;        m.c[1][1] = 1;  m.c[1][2] = 0;       m.c[1][3] = 0;
    m.c[2][0] = -sin(t);  m.c[2][1] = 0;  m.c[2][2] = cos(t);  m.c[2][3] = 0;
    m.c[3][0] = 0;        m.c[3][1] = 0;  m.c[3][2] = 0;       m.c[3][3] = 1;
    return m;
}



/**
 * Gets the rotation matrix on the z-axis with angle theta
 * @param theta is the angle
 * @returns the rotation matrix on the z-axis with angle theta
 */
Matrix4 Matrix4::rotationZ(float t){
    Matrix4 m;
    m.c[0][0] = cos(t);  m.c[0][1] = -sin(t);  m.c[0][2] = 0;  m.c[0][3] = 0;
    m.c[1][0] = sin(t);  m.c[1][1] = cos(t);   m.c[1][2] = 0;  m.c[1][3] = 0;
    m.c[2][0] = 0;       m.c[2][1] = 0;        m.c[2][2] = 1;  m.c[2][3] = 0;
    m.c[3][0] = 0;       m.c[3][1] = 0;        m.c[3][2] = 0;  m.c[3][3] = 1;
    return m;
}



/**
 * Gets the base change matrix using the address vectors i, j and k 
 * @param i is the first Direction vector
 * @param j is the second Direction vector
 * @param k is the third Direction vector
 * @returns the base change matrix using the address vectors i, j and k
 */
Matrix4 Matrix4::changeBase(Direction i, Direction j, Direction k, Point o){
    Matrix4 m;
    m.c[0][0] = i.c[0];  m.c[0][1] = j.c[0];  m.c[0][2] = k.c[0];  m.c[0][3] = o.c[0];
    m.c[1][0] = i.c[1];  m.c[1][1] = j.c[1];  m.c[1][2] = k.c[1];  m.c[1][3] = o.c[1];
    m.c[2][0] = i.c[2];  m.c[2][1] = j.c[2];  m.c[2][2] = k.c[2];  m.c[2][3] = o.c[2];
    m.c[3][0] = 0;       m.c[3][1] = 0;       m.c[3][2] = 0;       m.c[3][3] = 1;
    return m;
}



/**
 * Gets the inverse of a matrix
 * @param a is the matrix 
 * @returns the inverse matrix of the matrix a
 */
Matrix4 Matrix4::inverse(Matrix4 m){
    Matrix4 r;
    r.c[0][0] = m.c[1][1] * m.c[2][2] * m.c[3][3] - m.c[1][1] * m.c[2][3] * m.c[3][2] - m.c[2][1] * m.c[1][2] * m.c[3][3] 
              + m.c[2][1] * m.c[1][3] * m.c[3][2] + m.c[3][1] * m.c[1][2] * m.c[2][3] - m.c[3][1] * m.c[1][3] * m.c[2][2];

    r.c[0][1] =-m.c[0][1] * m.c[2][2] * m.c[3][3] + m.c[0][1] * m.c[2][3] * m.c[3][2] + m.c[2][1] * m.c[0][2] * m.c[3][3]
               -m.c[2][1] * m.c[0][3] * m.c[3][2] - m.c[3][1] * m.c[0][2] * m.c[2][3] + m.c[3][1] * m.c[0][3]  *m.c[2][2];
    r.c[0][2] = m.c[0][1] * m.c[1][2] * m.c[3][3] - m.c[0][1] * m.c[1][3] * m.c[3][2] - m.c[1][1] * m.c[0][2] * m.c[3][3] 
              + m.c[1][1] * m.c[0][3] * m.c[3][2] + m.c[3][1] * m.c[0][2] * m.c[1][3] - m.c[3][1] * m.c[0][3] * m.c[1][2];
    r.c[0][3] = -m.c[0][1] * m.c[1][2] * m.c[2][3] + m.c[0][1] * m.c[1][3] * m.c[2][2] + m.c[1][1] * m.c[0][2] * m.c[2][3] 
              -  m.c[1][1] * m.c[0][3] * m.c[2][2] - m.c[2][1] * m.c[0][2] * m.c[1][3] + m.c[2][1] * m.c[0][3] * m.c[1][2];
    r.c[1][0] = -m.c[1][0] * m.c[2][2] * m.c[3][3] + m.c[1][0] * m.c[2][3] * m.c[3][2] + m.c[2][0] * m.c[1][2] * m.c[3][3] 
              - m.c[2][0] * m.c[1][3] * m.c[3][2] - m.c[3][0] * m.c[1][2] * m.c[2][3] + m.c[3][0] * m.c[1][3] * m.c[2][2];
    r.c[1][1] =  m.c[0][0] * m.c[2][2] * m.c[3][3] - m.c[0][0] * m.c[2][3] * m.c[3][2] - m.c[2][0] * m.c[0][2] * m.c[3][3]
              + m.c[2][0] * m.c[0][3] * m.c[3][2] + m.c[3][0] * m.c[0][2] * m.c[2][3] - m.c[3][0] * m.c[0][3] * m.c[2][2];
    r.c[1][2] = -m.c[0][0] * m.c[1][2] * m.c[3][3] + m.c[0][0] * m.c[1][3] * m.c[3][2] + m.c[1][0] * m.c[0][2] * m.c[3][3]
              - m.c[1][0] * m.c[0][3] * m.c[3][2] - m.c[3][0] * m.c[0][2] * m.c[1][3] + m.c[3][0] * m.c[0][3] * m.c[1][2];
    r.c[1][3] =  m.c[0][0] * m.c[1][2] * m.c[2][3] - m.c[0][0] * m.c[1][3] * m.c[2][2] - m.c[1][0] * m.c[0][2] * m.c[2][3]
              + m.c[1][0] * m.c[0][3] * m.c[2][2] + m.c[2][0] * m.c[0][2] * m.c[1][3] - m.c[2][0] * m.c[0][3] * m.c[1][2];
    r.c[2][0] =  m.c[1][0] * m.c[2][1] * m.c[3][3] - m.c[1][0] * m.c[2][3] * m.c[3][1] - m.c[2][0] * m.c[1][1] * m.c[3][3]
              + m.c[2][0] * m.c[1][3] * m.c[3][1] + m.c[3][0] * m.c[1][1] * m.c[2][3] - m.c[3][0] * m.c[1][3]* m.c[2][1];
    r.c[2][1] = -m.c[0][0] * m.c[2][1] * m.c[3][3] + m.c[0][0] * m.c[2][3] * m.c[3][1] + m.c[2][0] * m.c[0][1] * m.c[3][3]
              - m.c[2][0] * m.c[0][3] * m.c[3][1] - m.c[3][0] * m.c[0][1] * m.c[2][3] + m.c[3][0] * m.c[0][3] * m.c[2][1];
    r.c[2][2] =  m.c[0][0] * m.c[1][1] * m.c[3][3] - m.c[0][0] * m.c[1][3] * m.c[3][1] - m.c[1][0] * m.c[0][1] * m.c[3][3]
              + m.c[1][0] * m.c[0][3] * m.c[3][1] + m.c[3][0] * m.c[0][1] * m.c[1][3] - m.c[3][0] * m.c[0][3] * m.c[1][1];
    r.c[2][3] = -m.c[0][0] * m.c[1][1] * m.c[2][3] + m.c[0][0] * m.c[1][3] * m.c[2][1] + m.c[1][0] * m.c[0][1] * m.c[2][3]
              - m.c[1][0] * m.c[0][3] * m.c[2][1] - m.c[2][0] * m.c[0][1] * m.c[1][3] + m.c[2][0] * m.c[0][3] * m.c[1][1];
    r.c[3][0] = -m.c[1][0] * m.c[2][1] * m.c[3][2] + m.c[1][0] * m.c[2][2] * m.c[3][1] + m.c[2][0] * m.c[1][1] * m.c[3][2]
              - m.c[2][0] * m.c[1][2] * m.c[3][1] - m.c[3][0] * m.c[1][1] * m.c[2][2] + m.c[3][0] * m.c[1][2] * m.c[2][1];
    r.c[3][1] =  m.c[0][0] * m.c[2][1] * m.c[3][2] - m.c[0][0] * m.c[2][2] * m.c[3][1] - m.c[2][0] * m.c[0][1] * m.c[3][2]
              + m.c[2][0] * m.c[0][2] * m.c[3][1] + m.c[3][0] * m.c[0][1] * m.c[2][2] - m.c[3][0] * m.c[0][2] * m.c[2][1];
    r.c[3][2] = -m.c[0][0] * m.c[1][1] * m.c[3][2] + m.c[0][0] * m.c[1][2] * m.c[3][1] + m.c[1][0] * m.c[0][1] * m.c[3][2]
              - m.c[1][0] * m.c[0][2] * m.c[3][1] - m.c[3][0] * m.c[0][1] * m.c[1][2] + m.c[3][0] * m.c[0][2] * m.c[1][1];
    r.c[3][3] = m.c[0][0] * m.c[1][1] * m.c[2][2] - m.c[0][0] * m.c[1][2] * m.c[2][1] - m.c[1][0] * m.c[0][1] * m.c[2][2]
              + m.c[1][0] * m.c[0][2] * m.c[2][1] + m.c[2][0] * m.c[0][1] * m.c[1][2] - m.c[2][0] * m.c[0][2] * m.c[1][1];

    float D = r.c[0][0] * m.c[0][0] + r.c[1][0] * m.c[0][1] +  r.c[2][0] * m.c[0][2] + r.c[3][0] * m.c[0][3];
    if(D != 0){
         r.c[0][0] /= D; r.c[0][1] /= D; r.c[0][2] /= D; r.c[0][3] /= D;
         r.c[1][0] /= D; r.c[1][1] /= D; r.c[1][2] /= D; r.c[1][3] /= D;
         r.c[2][0] /= D; r.c[2][1] /= D; r.c[2][2] /= D; r.c[2][3] /= D;
         r.c[3][0] /= D; r.c[3][1] /= D; r.c[3][2] /= D; r.c[3][3] /= D;   
    }
    return r;
}



/**
 * Gets the 4x4 matrix resulting from multiplying matrices a and b
 * @param a is the first 4x4 matrix
 * @param b is the second 4x4 matrix
 * @returns the 4x4 matrix resulting from multiplying matrices a and b
 */
Matrix4 operator * (Matrix4 a, Matrix4 b){
    Matrix4 r;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            r.c[i][j] = 0.0;      
            for(int k = 0; k < 4; k++){
                r.c[i][j] = r.c[i][j] + a.c[i][k] * b.c[k][j];
            }
        }
    }
    return r;
}



/**
     * Checks if two Matrix4 matrixes are equal
     * @param m1 is the first matrix
     * @param m2 is the second matrix
     * @returns true if the two Matrix4 matrixes m1 and m2 are equal and
     *          false in any other case
     */
bool operator == (Matrix4 m1, Matrix4 m2){
    return m1.c[0][0] == m2.c[0][0] && m1.c[0][1] == m2.c[0][1] && m1.c[0][2] == m2.c[0][2] && m1.c[0][3] == m2.c[0][3]
        && m1.c[1][0] == m2.c[1][0] && m1.c[1][1] == m2.c[1][1] && m1.c[1][2] == m2.c[1][2] && m1.c[1][3] == m2.c[1][3]
        && m1.c[2][0] == m2.c[2][0] && m1.c[2][1] == m2.c[2][1] && m1.c[2][2] == m2.c[2][2] && m1.c[2][3] == m2.c[2][3]
        && m1.c[3][0] == m2.c[3][0] && m1.c[3][1] == m2.c[3][1] && m1.c[3][2] == m2.c[3][2] && m1.c[3][3] == m2.c[3][3];
}


