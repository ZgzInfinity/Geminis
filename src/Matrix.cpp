#include "../include/Matrix.h"


Matrix4::Matrix4(){}
    



Matrix4 Matrix4::translation(float x, float y, float z){
    Matrix4 m;
    m.c[0][0] = 1;  m.c[0][1] = 0;  m.c[0][2] = 0;  m.c[0][3] = x;
    m.c[1][0] = 0;  m.c[1][1] = 1;  m.c[1][2] = 0;  m.c[1][3] = y;
    m.c[2][0] = 0;  m.c[2][1] = 0;  m.c[2][2] = 1;  m.c[2][3] = z;
    m.c[3][0] = 0;  m.c[3][1] = 0;  m.c[3][2] = 0;  m.c[3][3] = 1;
    return m;
}





Matrix4 Matrix4::scale(float x, float y, float z){
    Matrix4 m;
    m.c[0][0] = x;  m.c[0][1] = 0;  m.c[0][2] = 0;  m.c[0][3] = 0;
    m.c[1][0] = 0;  m.c[1][1] = y;  m.c[1][2] = 0;  m.c[1][3] = 0;
    m.c[2][0] = 0;  m.c[2][1] = 0;  m.c[2][2] = z;  m.c[2][3] = 0;
    m.c[3][0] = 0;  m.c[3][1] = 0;  m.c[3][2] = 0;  m.c[3][3] = 1;
    return m;
}





Matrix4 Matrix4::rotationX(float t){
    Matrix4 m;
    m.c[0][0] = 1;  m.c[0][1] = 0;       m.c[0][2] = 0;        m.c[0][3] = 0;
    m.c[1][0] = 0;  m.c[1][1] = cos(t);  m.c[1][2] = -sin(t);  m.c[1][3] = 0;
    m.c[2][0] = 0;  m.c[2][1] = sin(t);  m.c[2][2] = cos(t);   m.c[2][3] = 0;
    m.c[3][0] = 0;  m.c[3][1] = 0;       m.c[3][2] = 0;        m.c[3][3] = 1;
    return m;
}





Matrix4 Matrix4::rotationY(float t){
    Matrix4 m;
    m.c[0][0] = cos(t);   m.c[0][1] = 0;  m.c[0][2] = sin(t);  m.c[0][3] = 0;
    m.c[1][0] = 0;        m.c[1][1] = 1;  m.c[1][2] = 0;       m.c[1][3] = 0;
    m.c[2][0] = -sin(t);  m.c[2][1] = 0;  m.c[2][2] = cos(t);  m.c[2][3] = 0;
    m.c[3][0] = 0;        m.c[3][1] = 0;  m.c[3][2] = 0;       m.c[3][3] = 1;
    return m;
}





Matrix4 Matrix4::rotationZ(float t){
    Matrix4 m;
    m.c[0][0] = cos(t);  m.c[0][1] = -sin(t);  m.c[0][2] = 0;  m.c[0][3] = 0;
    m.c[1][0] = sin(t);  m.c[1][1] = cos(t);   m.c[1][2] = 0;  m.c[1][3] = 0;
    m.c[2][0] = 0;       m.c[2][1] = 0;        m.c[2][2] = 1;  m.c[2][3] = 0;
    m.c[3][0] = 0;       m.c[3][1] = 0;        m.c[3][2] = 0;  m.c[3][3] = 1;
    return m;
}



Matrix4 Matrix4::changeBase(Direction i, Direction j, Direction k, Point o){
    Matrix4 m;
    m.c[0][0] = i.c[0];  m.c[0][1] = j.c[0];  m.c[0][2] = k.c[0];  m.c[0][3] = o.c[0];
    m.c[1][0] = i.c[1];  m.c[1][1] = j.c[1];  m.c[1][2] = k.c[1];  m.c[1][3] = o.c[1];
    m.c[2][0] = i.c[2];  m.c[2][1] = j.c[2];  m.c[2][2] = k.c[2];  m.c[2][3] = o.c[2];
    m.c[3][0] = 0;       m.c[3][1] = 0;       m.c[3][2] = 0;       m.c[3][3] = 1;
    return m;
}




Matrix4 operator* (Matrix4 a, Matrix4 b){
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



