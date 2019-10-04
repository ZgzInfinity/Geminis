#include "../include/Matrix3.h"


Matrix3::Matrix3(){}
    

Matrix3 Matrix3::scale(float x, float y, float z){
    Matrix3 m;
    m.c[0][0] = x;  m.c[0][1] = 0;  m.c[0][2] = 0;
    m.c[1][0] = 0;  m.c[1][1] = y;  m.c[1][2] = 0;
    m.c[2][0] = 0;  m.c[2][1] = 0;  m.c[2][2] = z;
    return m;
}





Matrix3 Matrix3::rotationX(float t){
    Matrix3 m;
    m.c[0][0] = 1;  m.c[0][1] = 0;       m.c[0][2] = 0;
    m.c[1][0] = 0;  m.c[1][1] = cos(t);  m.c[1][2] = -sin(t);
    m.c[2][0] = 0;  m.c[2][1] = sin(t);  m.c[2][2] = cos(t);
    return m;
}





Matrix3 Matrix3::rotationY(float t){
    Matrix3 m;
    m.c[0][0] = cos(t);   m.c[0][1] = 0;  m.c[0][2] = sin(t);
    m.c[1][0] = 0;        m.c[1][1] = 1;  m.c[1][2] = 0;
    m.c[2][0] = -sin(t);  m.c[2][1] = 0;  m.c[2][2] = cos(t);
    return m;
}





Matrix3 Matrix3::rotationZ(float t){
    Matrix3 m;
    m.c[0][0] = cos(t);  m.c[0][1] = -sin(t);  m.c[0][2] = 0;
    m.c[1][0] = sin(t);  m.c[1][1] = cos(t);   m.c[1][2] = 0;
    m.c[2][0] = 0;       m.c[2][1] = 0;        m.c[2][2] = 1;
    return m;
}



Matrix3 Matrix3::changeBase(Direction i, Direction j, Direction k){
    Matrix3 m;
    m.c[0][0] = i.c[0];  m.c[0][1] = j.c[0];  m.c[0][2] = k.c[0];
    m.c[1][0] = i.c[1];  m.c[1][1] = j.c[1];  m.c[1][2] = k.c[1];
    m.c[2][0] = i.c[2];  m.c[2][1] = j.c[2];  m.c[2][2] = k.c[2];
    return m;
}



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



