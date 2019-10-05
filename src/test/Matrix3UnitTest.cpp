#include "../../include/test/Matrix3UnitTest.h"

void testScale(float x, float y, float z, Matrix3 expected){
    Matrix3 result = Matrix3::scale(x, y, z);
    assert(result == expected);
}



void testRotationX(float theta, Matrix3 expected){
    Matrix3 result = Matrix3::rotationX(theta);
    assert(result == expected);
}



void testRotationY(float theta, Matrix3 expected){
    Matrix3 result = Matrix3::rotationY(theta);
    assert(result == expected);
}



void testRotationZ(float theta, Matrix3 expected){
    Matrix3 result = Matrix3::rotationZ(theta);
    assert(result == expected);
}



void testChangeBase(Direction i, Direction j, Direction k, Matrix3 expected){
    Matrix3 result = Matrix3::changeBase(i, j, k);
    assert(result == expected);
}



void testInverse(Matrix3 a, Matrix3 expected){
    Matrix3 result = Matrix3::inverse(a);
    assert(result == expected);
}

/**
 * Test the Matrix3 matrix resulting from muliplying the Matrix3 m1 by the Matrix3 m2
 * @param m1 is the first Matrix3 matrix
 * @param m2 is the second Matrix3 matrix
 * @param expected is the value of the expected Matrix3 matrix
 */
void testMulOperator(Matrix3 m1, Matrix3 m2, Matrix3 expected){
    Matrix3 result = m1 * m2;
    assert(result == expected);
}