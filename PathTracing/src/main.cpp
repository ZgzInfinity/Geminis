
/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 


#include <iostream>
#include <cstring>
#include "../include/Matrix4.h"

using namespace std;

const int NUMBER_PARAMETERS = 2;

int main(int argc, char* argv[]){

    if (argc != NUMBER_PARAMETERS){
        cerr << "Wrong number of parameters" << endl;
        cerr << "Invoke like pathTracing <rays per pixel>" << endl;
    }
    else {
        int raysPerPixel = atoi(argv[1]);
        cout << "Number of rays per pixel " << raysPerPixel << endl;

        Direction d_i = Direction(1, 0, 0);
        Direction d_j = Direction(0, 1, 0);
        Direction d_k = Direction(0, 0, 1);
        Point origin = Point(0, 0, 0);

        Matrix4 Camara = Matrix4::changeBase(d_i, d_j, d_k, origin);
    }

    return 0;
}