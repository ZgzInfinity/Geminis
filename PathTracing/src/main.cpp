
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
        Direction d_k = Direction(1, 0, 0);
        Point origin = Point(0, 0, 0);

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
        Plane p1 = Plane(Direction(0, 0, 1), 7, RGB(155, 89, 182));
        planeList[0] = p1;
        Plane p2 = Plane(Direction(0, 0,-1), 7, RGB(46, 204, 113));
        planeList[1] = p2;
        Plane p3 = Plane(Direction(0, -1, 0), 5, RGB(236, 240, 241));
        planeList[2] = p3;
        Plane p4 = Plane(Direction(0, 1, 0), 5, RGB(52, 73, 94));
        planeList[3] = p4;
        Plane p5 = Plane(Direction(-1, 0, 0), 7, RGB(192, 57, 43));
        planeList[4] = p5;

        // Definition of the spheres which are going to appear in the scene 
        Sphere s1 = Sphere(Point(3, 0, 0), 1 , RGB(241, 196, 15));
        sphereList[0] = s1;

        // Definition of the triangles which are going to appear in the scene 
        Triangle t1 = Triangle(Point(2, -1, -1), Point(2, -1, 0), 
                               Point(2, 0, 0), &brickTexture, 0, 1, 1, 0, 0, 1);
        triangleList[0] = t1;
        Triangle t2 = Triangle(Point(2, 0, 0), Point(2, 1, 1), 
                               Point(2, 1, 0), &brickTexture, 0, 1, 0, 0, 1, 1);
        triangleList[1] = t2;
        Triangle t3 = Triangle(Point(2, -2, 0), Point(2, -2, 1),
                               Point(3, -2, 0), &brickTexture, 0, 1, 1, 0, 0, 1);
        triangleList[2] = t3;
        Triangle t4 = Triangle(Point(2, -2, 1), Point(3, -2, 1), 
                               Point(3, -2, 0), &brickTexture, 0, 1, 0, 0, 1, 1);
        triangleList[3] = t4;

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

                // Direction of the ray with an emission 
                rayDir = pixelCenter - origin;
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