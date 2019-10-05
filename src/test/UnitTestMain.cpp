#include "../../include/test/UnitTestMain.h"

void runDirectionUnitTests(){
    testPlusOperator(Direction(1, 0, 3), Direction(-1, 4, 2), Direction(0, 4, 5));
    testSubOperator(Direction(0, 4, 5), Direction(1, 0, 3), Direction(-1, 4, 2));
    testMultiplyOperator(Direction(1, 5, 0), -3, Direction(-3, -15, 0));
    testDivOperator(Direction(-3, -15, 0), -3, Direction(1, 5, 0));
    testMod(Direction(3, 4, 0), 5);
    testDot(Direction(1, 2, 3), Direction(1, 5, 7), 32);
    testCross(Direction(-1, -2, 3), Direction(4, 0, -8), Direction(16, 4, 8));
    cout << "Direction unit tests passed." << endl;
}

void runSharedOpsUnitTests(){
    testAddOperator(Point(1, 0, 3), Direction(-1, 4, 2), Point(0, 4, 5));
    testSubOperator(Point(0, 4, 5), Point(1, 0, 3), Direction(-1, 4, 2));
    Matrix4 m4;
    m4.c[0][0] = 2;  m4.c[0][1] = 3; m4.c[0][2] = -4; m4.c[0][3] = 2;
    m4.c[1][0] = 11; m4.c[1][1] = 8; m4.c[1][2] = 7;  m4.c[1][3] = 5;
    m4.c[2][0] = 2;  m4.c[2][1] = 5; m4.c[2][2] = 3;  m4.c[2][3] = 2;
    m4.c[3][0] = 0;  m4.c[3][1] = 0; m4.c[3][2] = 0; m4.c[3][3] = 1;
    testMultiplyMatrix4Direction(m4, Direction(3, 7, 5), Direction(7, 124, 56));
    testMultiplyMatrix4Point(m4, Point(3, 7, 5), Point(9, 129, 58));
    Matrix3 m3;
    m3.c[0][0] = 2;  m3.c[0][1] = 3; m3.c[0][2] = -4; 
    m3.c[1][0] = 11; m3.c[1][1] = 8; m3.c[1][2] = 7; 
    m3.c[2][0] = 2;  m3.c[2][1] = 5; m3.c[2][2] = 3; 
    testMultiplyMatrix3Direction(m3, Direction(3, 7, 5), Direction(7, 124, 56));
    testMultiplyMatrix3Point(m3, Point(3, 7, 5), Point(7, 124, 56));
    cout << "SharedOps unit tests passed." << endl;
}

void runAllUnitTests(){
    runDirectionUnitTests();
    runSharedOpsUnitTests();

    cout << "ALL UNIT TESTS HAVE PASSED." << endl;

}