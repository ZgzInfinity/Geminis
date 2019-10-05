#include "../../include/test/Matrix4UnitTest.h"

void testScale(float x, float y, float z, Matrix4 expected){
    Matrix4 result = Matrix4::scale(x, y, z);
    assert(result == expected);
}



void testRotationX(float theta, Matrix4 expected){
    Matrix4 result = Matrix4::rotationX(theta);
    assert(result == expected);
}



void testRotationY(float theta, Matrix4 expected){
    Matrix4 result = Matrix4::rotationY(theta);
    assert(result == expected);
}



void testRotationZ(float theta, Matrix4 expected){
    Matrix4 result = Matrix4::rotationZ(theta);
    assert(result == expected);
}



void testChangeBase(Direction i, Direction j, Direction k, Point o, Matrix4 expected){
    Matrix4 result = Matrix4::changeBase(i, j, k, o);
    assert(result == expected);
}



void testInverse(Matrix4 a, Matrix4 expected){
    Matrix4 result = Matrix4::inverse(a);
    assert(result == expected);
}

/**
 * Test the Matrix4 matrix resulting from muliplying the Matrix4 m1 by the Matrix4 m2
 * @param m1 is the first Matrix4 matrix
 * @param m2 is the second Matrix4 matrix
 * @param expected is the value of the expected Matrix4 matrix
 */
void testMulOperator(Matrix4 m1, Matrix4 m2, Matrix4 expected){
    Matrix4 result = m1 * m2;
    assert(result == expected);
}