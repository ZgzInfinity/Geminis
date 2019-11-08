
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
#include <list>
#include <iomanip>
#include "../include/Matrix4.h"
#include "../include/Plane.h"
#include "../include/Sphere.h"

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

        Direction d_i = Direction(0, 0, -1);
        Direction d_j = Direction(0, 1, 0);
        Direction d_k = Direction(1, 0, 0);
        Point origin = Point(0, 0, 0);

        Matrix4 camera = Matrix4::changeBase(d_i, d_j, d_k, origin);

        // Image resolution
        float width = 100;
        float height = 100;

        // Projection plane
        Direction leftPP = Direction(0, 0, -1);
        Direction upPP = Direction(0, 1, 0);

        list <Sphere> sphereList;
        list <Plane> planeList;

        float pixelDimension = mod(leftPP) / (width / 2.f);

        if(pixelDimension != mod(upPP) / (height / 2.f)){
            // Incorrect
            cerr << "Bad resolution and Project plane configuration" << endl;
        }
        else {
            // Correct
            cout << "The pixel is square with dimension " << pixelDimension << endl;
        }





    }

    return 0;
}