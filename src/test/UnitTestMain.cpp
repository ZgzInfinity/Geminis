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
 * UnitTestMain.cpp implementation file of UnitTestMain module
 */

#include "../../include/test/UnitTestMain.h"


/**
 * proves that all operations working with Direction vectors function correctly
 */
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



/**
 * proves that all operations working with direction vectors and point vectors function correctly
 */
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



/**
 * proves that all operations working with 3x3 transformation matrices work correctly
 */
void runMatrix3x3Tests(){
    Matrix3 m1;
    m1.c[0][0] = 1;  m1.c[0][1] = 0; m1.c[0][2] = 0; 
    m1.c[1][0] = 0;  m1.c[1][1] = 2; m1.c[1][2] = 0; 
    m1.c[2][0] = 0;  m1.c[2][1] = 0; m1.c[2][2] = 3;
    testScale(1, 2, 3, m1);
    Matrix3 m2;
    m2.c[0][0] = 1;  m2.c[0][1] = 0;        m2.c[0][2] = 0;
    m2.c[1][0] = 0;  m2.c[1][1] = cos(PI);  m2.c[1][2] = -sin(PI);
    m2.c[2][0] = 0;  m2.c[2][1] = sin(PI);  m2.c[2][2] = cos(PI);
    testRotationX(PI, m2);
    Matrix3 m3;
    m3.c[0][0] = cos(PI);  m3.c[0][1] = 0;  m3.c[0][2] = sin(PI);
    m3.c[1][0] = 0;        m3.c[1][1] = 1;  m3.c[1][2] = 0;
    m3.c[2][0] = -sin(PI); m3.c[2][1] = 0;  m3.c[2][2] = cos(PI);
    testRotationY(PI, m3);
    Matrix3 m4;
    m4.c[0][0] = cos(PI);  m4.c[0][1] = -sin(PI); m4.c[0][2] = 0;
    m4.c[1][0] = sin(PI);  m4.c[1][1] = cos(PI);  m4.c[1][2] = 0;
    m4.c[2][0] = 0;        m4.c[2][1] = 0;        m4.c[2][2] = 1;
    testRotationZ(PI, m4);
    Direction i = Direction(1, 0, 3);
    Direction j = Direction(1, 4, 2);
    Direction k = Direction(0, 4, 5);
    Matrix3 m5;
    m5.c[0][0] = i.c[0];  m5.c[0][1] = j.c[0];  m5.c[0][2] = k.c[0];
    m5.c[1][0] = i.c[1];  m5.c[1][1] = j.c[1];  m5.c[1][2] = k.c[1];
    m5.c[2][0] = i.c[2];  m5.c[2][1] = j.c[2];  m5.c[2][2] = k.c[2];
    testChangeBase(i, j, k, m5);
    Matrix3 m6;
    m6.c[0][0] = 3;  m6.c[0][1] = 2;  m6.c[0][2] = -7;
    m6.c[1][0] = 2;  m6.c[1][1] = 0;  m6.c[1][2] = 0.5;
    m6.c[2][0] = -1; m6.c[2][1] = -3; m6.c[2][2] = 2;
    Matrix3 m7;
    m7.c[0][0] = 3;  m7.c[0][1] = 2;  m7.c[0][2] = -1;
    m7.c[1][0] = 2;  m7.c[1][1] = 0;  m7.c[1][2] = -3;
    m7.c[2][0] = -7; m7.c[2][1] = 0.5; m7.c[2][2] = 2;
    testTrans(m6, m7);
    Matrix3 m10;
    m10.c[0][0] = 1; m10.c[0][1] = 2; m10.c[0][2] = 3;
    m10.c[1][0] = 4; m10.c[1][1] = 5; m10.c[1][2] = 6;
    m10.c[2][0] = 7; m10.c[2][1] = 8; m10.c[2][2] = 9;
    Matrix3 m11;
    m11.c[0][0] = 9; m11.c[0][1] = 8; m11.c[0][2] = 7;
    m11.c[1][0] = 6; m11.c[1][1] = 5; m11.c[1][2] = 4;
    m11.c[2][0] = 3; m11.c[2][1] = 2; m11.c[2][2] = 1;
    Matrix3 m12;
    m12.c[0][0] = 30;  m12.c[0][1] = 24;  m12.c[0][2] = 18;
    m12.c[1][0] = 84;  m12.c[1][1] = 69;  m12.c[1][2] = 54;
    m12.c[2][0] = 138; m12.c[2][1] = 114; m12.c[2][2] = 90;
    testMulOperator(m10, m11, m12);
    cout << "Matrix3 unit tests passed." << endl;
}



/**
 * proves that all operations working with 4x4 transformation matrices work correctly
 */
void runMatrix4x4Tests(){
    Matrix4 m1;
    m1.c[0][0] = 1;  m1.c[0][1] = 0; m1.c[0][2] = 0; m1.c[0][3] = 0;
    m1.c[1][0] = 0;  m1.c[1][1] = 2; m1.c[1][2] = 0; m1.c[1][3] = 0;
    m1.c[2][0] = 0;  m1.c[2][1] = 0; m1.c[2][2] = 3; m1.c[2][3] = 0;
    m1.c[3][0] = 0;  m1.c[3][1] = 0; m1.c[3][2] = 0; m1.c[3][3] = 1;
    testScale(1, 2, 3, m1);
    Matrix4 m2;
    m2.c[0][0] = 1;  m2.c[0][1] = 0;        m2.c[0][2] = 0;          m2.c[0][3] = 0;
    m2.c[1][0] = 0;  m2.c[1][1] = cos(PI);  m2.c[1][2] = -sin(PI);   m2.c[1][3] = 0;
    m2.c[2][0] = 0;  m2.c[2][1] = sin(PI);  m2.c[2][2] = cos(PI);    m2.c[2][3] = 0;
    m2.c[3][0] = 0;  m2.c[3][1] = 0;        m2.c[3][2] = 0;          m2.c[3][3] = 1;
    testRotationX(PI, m2);
    Matrix4 m3;
    m3.c[0][0] = cos(PI);   m3.c[0][1] = 0;  m3.c[0][2] = sin(PI);  m3.c[0][3] = 0;
    m3.c[1][0] = 0;         m3.c[1][1] = 1;  m3.c[1][2] = 0;        m3.c[1][3] = 0;
    m3.c[2][0] = -sin(PI);  m3.c[2][1] = 0;  m3.c[2][2] = cos(PI);  m3.c[2][3] = 0;
    m3.c[3][0] = 0;         m3.c[3][1] = 0;  m3.c[3][2] = 0;        m3.c[3][3] = 1;
    testRotationY(PI, m3);
    Matrix4 m4;
    m4.c[0][0] = cos(PI);  m4.c[0][1] = -sin(PI);  m4.c[0][2] = 0;  m4.c[0][3] = 0;
    m4.c[1][0] = sin(PI);  m4.c[1][1] = cos(PI);   m4.c[1][2] = 0;  m4.c[1][3] = 0;
    m4.c[2][0] = 0;        m4.c[2][1] = 0;         m4.c[2][2] = 1;  m4.c[2][3] = 0;
    m4.c[3][0] = 0;        m4.c[3][1] = 0;         m4.c[3][2] = 0;  m4.c[3][3] = 1;
    testRotationZ(PI, m4);
    Direction i = Direction(1, 0, 3);
    Direction j = Direction(1, 4, 2);
    Direction k = Direction(0, 4, 5);
    Point o = Point(10, 5, 10);
    Matrix4 m5;
    m5.c[0][0] = i.c[0];  m5.c[0][1] = j.c[0];  m5.c[0][2] = k.c[0];  m5.c[0][3] = o.c[0];
    m5.c[1][0] = i.c[1];  m5.c[1][1] = j.c[1];  m5.c[1][2] = k.c[1];  m5.c[1][3] = o.c[1];
    m5.c[2][0] = i.c[2];  m5.c[2][1] = j.c[2];  m5.c[2][2] = k.c[2];  m5.c[2][3] = o.c[2];
    m5.c[3][0] = 0;       m5.c[3][1] = 0;       m5.c[3][2] = 0;       m5.c[3][3] = 1;
    testChangeBase(i, j, k, o, m5);
    Matrix4 m6;
    m6.c[0][0] = 3;  m6.c[0][1] = 2;  m6.c[0][2] = -7;  m6.c[0][3] = 2;
    m6.c[1][0] = 2;  m6.c[1][1] = 0;  m6.c[1][2] = 0.5; m6.c[1][3] = -1;
    m6.c[2][0] = -1; m6.c[2][1] = -3; m6.c[2][2] = 2;   m6.c[2][3] = -1;
    m6.c[3][0] = -1; m6.c[3][1] = -3; m6.c[3][2] = 2;   m6.c[3][3] = 4;
    Matrix4 m7;
    m7.c[0][0] = 3;  m7.c[0][1] = 2;   m7.c[0][2] = -1;  m7.c[0][3] = -1;
    m7.c[1][0] = 2;  m7.c[1][1] = 0;   m7.c[1][2] = -3; m7.c[1][3] = -3;
    m7.c[2][0] = -7; m7.c[2][1] = 0.5; m7.c[2][2] = 2;   m7.c[2][3] = 2;
    m7.c[3][0] = 2;  m7.c[3][1] = -1;  m7.c[3][2] = -1;   m7.c[3][3] = 4;
    testTrans(m6, m7);
    Matrix4 m10;
    m10.c[0][0] = 1;  m10.c[0][1] = 2;   m10.c[0][2] = 3;   m10.c[0][3] = 4;
    m10.c[1][0] = 5;  m10.c[1][1] = 6;   m10.c[1][2] = 7;   m10.c[1][3] = 8;
    m10.c[2][0] = 9;  m10.c[2][1] = 10;  m10.c[2][2] = 11;  m10.c[2][3] = 12;
    m10.c[3][0] = 13; m10.c[3][1] = 14;  m10.c[3][2] = 15;  m10.c[3][3] = 16;
    Matrix4 m11;
    m11.c[0][0] = 16; m11.c[0][1] = 15;  m11.c[0][2] = 14; m11.c[0][3] = 13;
    m11.c[1][0] = 12; m11.c[1][1] = 11;  m11.c[1][2] = 10; m11.c[1][3] = 9;
    m11.c[2][0] = 8;  m11.c[2][1] = 7;   m11.c[2][2] = 6;  m11.c[2][3] = 5;
    m11.c[3][0] = 4;  m11.c[3][1] = 3;   m11.c[3][2] = 2;  m11.c[3][3] = 1;
    Matrix4 m12;
    m12.c[0][0] = 80;   m12.c[0][1] = 70;   m12.c[0][2] = 60;    m12.c[0][3] = 50;
    m12.c[1][0] = 240;  m12.c[1][1] = 214;  m12.c[1][2] = 188;   m12.c[1][3] = 162;
    m12.c[2][0] = 400;  m12.c[2][1] = 358;  m12.c[2][2] = 316;   m12.c[2][3] = 274;
    m12.c[3][0] = 560;  m12.c[3][1] = 502;   m12.c[3][2] = 444;  m12.c[3][3] = 386;
    testMulOperator(m10, m11, m12);
    cout << "Matrix4 unit tests passed." << endl;
}



/**
 * proves that all operations working with planets work correctly
 */
void runPlanetTests(){
    Planet p1 = Planet(Point(0, 0, 0), Direction(0,2,0), Point(0, 1, 0));
    testPlanet(p1, 1);
    Planet p2 = Planet(Point(0, 0, 0), Direction(0, 2, 0), Point(1, 0, 0));
    testPlanet(p2, 1);
    cout << "Planet unit tests passed." << endl;
}



/**
 * proves that all operations working with planetary stations work correctly
 */
void runPlanetaryStationTests(){
    Planet p1 = Planet(Point(0, 0, 0), Direction(0, 2, 0), Point(1, 0, 0));
    testPlanetaryStation(PlanetaryStation(p1, PI/2, PI/2), Point(0, 0, -1),
    Direction(0, 0, -1), Direction(-1, 0, 0), Direction(0, 1, 0));

    Planet p10 = Planet(Point(0, 0, 0), Direction(0, 2, 0), Point(1, 0, 0));
    testPlanetaryStation(PlanetaryStation(p10, PI/2, 0), Point(1, 0, 0),
    Direction(1, 0, 0), Direction(0, 0, -1), Direction(0, 1, 0));

    Planet p11 = Planet(Point(0, 0, 0), Direction(0, 2, 0), Point(1, 0, 0));
    testPlanetaryStation(PlanetaryStation(p11, PI/2, PI), Point(-1, 0, 0),
    Direction(-1, 0, 0), Direction(0, 0, 1), Direction(0, 1, 0));

    Planet p2 = Planet(Point(0,0,0), Direction(2, 0, 0), Point(0, 1, 0));
    testPlanetaryStation(PlanetaryStation(p2, PI/2, -PI/2), Point(0, 0, -1),
    Direction(0, 0, -1), Direction(0, 1, 0), Direction(1, 0, 0));

    Planet p3 = Planet(Point(5, 5, 5), Direction(0, -6, 0), Point(8, 5, 5));
    testPlanetaryStation(PlanetaryStation(p3, PI/2, PI), Point(2, 5, 5),
    Direction(-1, 0, 0), Direction(0, 0, -1), Direction(0, -1, 0));
}


/**
 * proves that all operations working with interplanetary connections work correctly
 */
void runInterplanetaryConnectionTests(){
    Planet p1 = Planet(Point(0, 0, 0), Direction(0, 2, 0), Point(1, 0, 0));
    PlanetaryStation ps1 = PlanetaryStation(p1, PI/2, 0);
    Planet p2 = Planet(Point(10, 0, 0), Direction(0, 2, 0), Point(11, 0, 0));
    PlanetaryStation ps2 = PlanetaryStation(p2, PI/2, PI);
    
    testInterplanetaryConnection(InterplanetaryConnection(ps1, ps2), Direction(8, 0, 0),
     Direction(0, 8, 0), Direction(0, -8, 0));
}



/**
 * test that all the tests work correctly
 */
void runAllUnitTests(){
    runDirectionUnitTests();
    runSharedOpsUnitTests();
    runMatrix3x3Tests();
    runMatrix4x4Tests();
    runPlanetTests();
    runPlanetaryStationTests();
    runInterplanetaryConnectionTests();
    cout << "ALL UNIT TESTS HAVE PASSED." << endl;
}