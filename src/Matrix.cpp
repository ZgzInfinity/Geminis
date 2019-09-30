#include "../include/Matrix.h"


Matrix::Matrix(){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            m[i][j] = 0;
        }
    }
    m[0][0] = 1;
    m[1][1] = 1;
    m[2][2] = 1;
    m[3][3] = 1;
}
    



void Matrix::matrixTranslation(float x, float y, float z){
    m[0][3] = x;
    m[1][3] = y;
    m[2][3] = z;
}





void Matrix::matrixScale(float x, float y, float z){
    m[0][0] = x;
    m[1][1] = y;
    m[2][2] = z;
}





void Matrix::matrixRotationX(float theta){
    m[1][1] = cos(theta);
    m[1][2] = -sin(theta);
    m[2][1] = sin(theta);
    m[2][2] = cos(theta);
}





void Matrix::matrixRotationY(float theta){
    m[0][0] = cos(theta);
    m[2][0] = -sin(theta);
    m[0][2] = sin(theta);
    m[2][2] = cos(theta);
}





void Matrix::matrixRotationZ(float theta){
    m[1][1] = cos(theta);
    m[0][1] = -sin(theta);
    m[1][0] = sin(theta);
    m[1][1] = cos(theta);
}





Matrix mul(Matrix a, Matrix b){
    Matrix r = Matrix();
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            r.m[i][j] = 0.0;      
            for(int k = 0; k < 4; k++){
                r.m[i][j] = r.m[i][j] + a.m[i][k] * b.m[k][j];
            }
        }
    }
    return r;
}



