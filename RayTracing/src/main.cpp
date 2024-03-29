
/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 


#include <vector>
#include <iostream>
#include <cstring>
#include <list>
#include <iomanip>
#include <cfloat>
#include "../include/Matrix4.h"
#include "../include/SharedOps.h"
#include "../include/Plane.h"
#include "../include/Sphere.h"
#include "../include/Triangle.h"
#include "../include/Image.h"
#include "../include/ImageLoaderPPM.h"

using namespace std;

const int NUMBER_PARAMETERS = 5;
const int RC = 255;



// http://viclw17.github.io/2018/07/16/raytracing-ray-sphere-intersection/

// https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm

// https://gamedev.stackexchange.com/questions/23743/whats-the-most-efficient-way-to-find-barycentric-coordinates

int main(int argc, char* argv[]){
    // Verification of the number of parameters
    if (argc != NUMBER_PARAMETERS){
        // Incorret
        cerr << "Wrong number of parameters" << endl;
        cerr << "Invoke like pathTracing <rays per pixel> <width of image> <height of image" 
             << "path of the file" << endl;
    }
    else {
        // Correct

        // Definition of the vectors of the space with the origin point
        // Direction d_i = Direction(0, 0, -1);
        // Direction d_j = Direction(0, 1, 0);
        //Direction d_k = Direction(1, 0, 0);
        Direction d_k = Direction(1, 0, 0);
        //Point origin = Point(-1.5, 2, 2);
        Point origin = Point(-7, 0, 0);

        // Creation of the base
        // Matrix4 camera = Matrix4::changeBase(d_i, d_j, d_k, origin);

        // Image resolution
        float width = atof(argv[2]);
        float height = atof(argv[3]);
        float pixelSize;

        // Projection plane direction vectors
        Direction leftPP, upPP;
        
        // Calculation of the components of the vectors that form the projection plane
        // The smallest vector is taken as a reference in function of the width and height values
        if (width > height){
            leftPP = Direction(0, 0, - width / height);
            // leftPP = Direction(- width / height, 0, 0);
            upPP = Direction(0, 1, 0);
            pixelSize = mod(upPP) / (height / 2.f);
        }
        else {
            leftPP = Direction(0, 0, -1);
            upPP = Direction(0, height / width, 0);
            pixelSize = mod(leftPP) / (width / 2.f);
        }

        // Load of the file which contains the texture format
        Image brickTexture = loadImagePPM("textures/brick_wall.ppm");
        vector<vector<RGB>> textureImg = brickTexture.getImg();

        // Dimensions of the texture image
        int textureH = brickTexture.getHeight();
        int textureW = brickTexture.getWidth();

        // Vectors with the planes and spheres represented in the scene
        Sphere sphereList[DIM_SPHERE];
        Plane planeList[DIM_PLANE];
        Triangle triangleList[DIM_TRIANGLE];
        
        // Definition of the planes which are going to appear in the scene 
        Plane leftWall = Plane(Direction(0, 0, 1), 7, RGB(255, 0, 0));
        planeList[0] = leftWall;
        Plane rightWall = Plane(Direction(0, 0,-1), 7, RGB(0, 255, 0));
        planeList[1] = rightWall;
        Plane ceiling = Plane(Direction(0, -1, 0), 7, RGB(255, 255, 255));
        planeList[2] = ceiling;
        Plane floor = Plane(Direction(0, 1, 0), 7, RGB(255, 255, 255));
        planeList[3] = floor;
        Plane background = Plane(Direction(-1, 0, 0), 7, RGB(255, 255, 255));
        planeList[4] = background;

        // Definition of the spheres which are going to appear in the scene 
        Sphere leftSphere = Sphere(Point(3, -5, -3), 2 , RGB(241, 196, 15));
        Sphere rightSphere = Sphere(Point(5, -5, 3), 2 , RGB(74, 105, 189));

        sphereList[0] = leftSphere;
        sphereList[1] = rightSphere;

        // Matrix of the image that is going to be built
        vector<vector<RGB>> img(height, vector<RGB>(width));
        // Matrix which stores the intersection distance for each pixel
        vector<vector<float>> distances(height, vector<float>(width));

        // Calculation of the upper left corner of the proyection plane 
        Point upperLeftCorner = origin + d_k + leftPP + upPP;
        Point pixelCenter;
        float pixelOffset = pixelSize / 2.f;
        Direction rayDir;
        Point bary;

        // Loop that calculates for each pixel the thrown ray and the intersections
        // between it and the spheres and planes stored in the scene
        for(int row = 0; row < height; row++){
            for(int col = 0; col <width; col++){
                // Calculation of the center of each pixel where the ray is going to be thrown
               
                pixelCenter = Point(upperLeftCorner.c[0],
                                    upperLeftCorner.c[1] - (row * pixelSize + pixelOffset),
                                    upperLeftCorner.c[2] + col * pixelSize + pixelOffset);
                

                /*
                pixelCenter = Point(upperLeftCorner.c[0] + col * pixelSize + pixelOffset,
                                    upperLeftCorner.c[1] - (row * pixelSize + pixelOffset),
                                    upperLeftCorner.c[2]);
                */

                // Direction of the ray with an emission 
                rayDir = pixelCenter - origin;
                rayDir = rayDir / mod(rayDir);
                //cout << rayDir.toString() << endl;
                img[row][col] = RGB();
                //For each pixel the starting distance is the biggest value and it is going reduced
                distances[row][col] = FLT_MAX;

                // Calculation of intersections between ray and planes
                intersectionRayPlane(origin, rayDir, row, col, distances, img, planeList);
 
                // Calculation of intersections between ray and spheres
                intersectionRaySphere(origin, rayDir, row, col, pixelCenter, distances, img, sphereList);

                // Calculation of intersections between ray and triangles
                intersectionRayTriangle(origin, bary, rayDir, row, col, textureH, textureW, pixelCenter, 
                                        distances, textureImg, img, triangleList);
            }
        }
        // Creation of the image and saving in a ppm format file
        Image image = Image(true, width, height, RC, RC, img);
        image.printImage(argv[4]);
    }
    // Final execution of the programm
    return 0;
}