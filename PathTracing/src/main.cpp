
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
#include <cfloat>
#include "../include/Matrix4.h"
#include "../include/SharedOps.h"
#include "../include/Plane.h"
#include "../include/Sphere.h"
#include "../include/Image.h"

using namespace std;

const int NUMBER_PARAMETERS = 2;
const int RC = 255;
const int DIM_PLANE = 1;
const int DIM_SPHERE = 1;

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

        Sphere sphereList[DIM_SPHERE];
        Plane planeList[DIM_PLANE];

        float pixelSize = mod(leftPP) / (width / 2.f);

        if(pixelSize != mod(upPP) / (height / 2.f)){
            // Incorrect
            cerr << "Bad resolution and Project plane configuration" << endl;
        }
        else {
            // Correct
            cout << "The pixel is square with dimension " << pixelSize << endl;
            vector<vector<RGB>> img(height, vector<RGB>(width));;

            Point upperLeftCorner = origin + d_k + d_i;
            Point pixelCenter;
            float pixelOffset = pixelSize / 2.f;
            Direction rayDir;
            float denom;
            float tMin = FLT_MAX;
            float t;

            for(int row = 0; row < height; row++){
                for(int col = 0; col <width; col++){
                    pixelCenter = Point(upperLeftCorner.c[0],
                         upperLeftCorner.c[1] - row*pixelSize + pixelOffset,
                         upperLeftCorner.c[2] + col*pixelSize + pixelOffset);
                    rayDir = pixelCenter - origin;
                    img[row][col] = RGB();
                    for(int i = 0; i < DIM_PLANE; i++){
                        if(abs(denom = dot(rayDir, planeList[i].normal)) > 0.00001f){
                            t = - (dot(origin, planeList[i].normal) + planeList[i].distance2origin) / denom;
                            if(t > 0.f){
                                if((dot(origin, planeList[i].normal) + planeList[i].distance2origin) / denom < tMin){
                                    tMin = t;
                                    img[row][col] = planeList[i].emission;
                                }
                            }
                        }
                    }






                }
            }
            
            
            
            
            
            
            
            
            
            Image image = Image(true, width, height, RC, RC, img);
        }





    }

    return 0;
}