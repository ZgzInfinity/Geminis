
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
#include "../include/Triangle.h"
#include "../include/Image.h"
#include "../include/ImageLoaderPPM.h"

using namespace std;

const int NUMBER_PARAMETERS = 5;
const int RC = 255;
const int DIM_PLANE = 5;
const int DIM_SPHERE = 1;
const int DIM_TRIANGLE = 4;
const float EPSILON = 0.0000001;

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
        int raysPerPixel = atoi(argv[1]);
        cout << "Number of rays per pixel " << raysPerPixel << endl;

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


        Image brickTexture = loadImagePPM("textures/brick_wall.ppm");
        vector<vector<RGB>> textureImg = brickTexture.getImg();
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

        Point upperLeftCorner = origin + d_k + leftPP + upPP;
        Point pixelCenter;
        float pixelOffset = pixelSize / 2.f;
        Direction rayDir, oc, h, s, q;
        float denom, t, a, b, c, d, discriminant, x, y;
        Point contactPoint;
        Point bary;
        float area0uv, areaPuv, areaPv0;

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

                // Plane intersection
                for(int i = 0; i < DIM_PLANE; i++){
                   if(abs(denom = dot(rayDir, planeList[i].normal)) > EPSILON){
                        // Calculation of the distance between 
                        t = - (dot(origin, planeList[i].normal) + planeList[i].distance2origin) / denom;
                        // Control of dividing by zerp
                        if(t > 0.f){
                            if(t < distances[row][col]){
                                // Its a near intersection and it is saved with the correct emission
                                distances[row][col] = t;
                                img[row][col] = planeList[i].emission;
                            }
                        }
                    }
                }

                // Sphere intersection
                for(int i = 0; i < DIM_SPHERE; i++){
                    oc = origin - sphereList[i].center;
                    rayDir = pixelCenter - origin;
                    // Calculation of the coefficients to resolve a second grade equation
                    a = dot(rayDir, rayDir);
                    b = 2.f * dot(oc, rayDir);
                    c = dot(oc, oc) - (sphereList[i].radius * sphereList[i].radius);
                    discriminant = b * b - 4 * a * c;
                    if (discriminant >= 0.f){
                          t = (-b -sqrt(discriminant)) / 2.f * a;
                          // Control of dividing by zero
                          if(t > 0.f){
                            if(t < distances[row][col]){
                                // Its a near intersection and it is saved with the correct emission
                                distances[row][col] = t;
                                img[row][col] = sphereList[i].emission;
                            }
                        }
                    }
                }

                // Triangle intersection
                for(int i = 0; i < DIM_TRIANGLE; i++){
                    h = cross(rayDir, triangleList[i].edge2);
                    a = dot(triangleList[i].edge1, h);
                    if (a > -EPSILON && a < EPSILON){
                        continue;    // This ray is parallel to this triangle.
                    }
                    b = 1.0/a;
                    s = origin - triangleList[i].p0;
                    c = b * dot(s, h);
                    if (c < 0.0 || c > 1.0){
                        continue;
                    }
                    q = cross(s, triangleList[i].edge1);
                    d = b * dot(rayDir, q);
                    if (d < 0.0 || c + d > 1.0){
                        continue;
                    }
                    // At this stage we can compute t to find out where the intersection point is on the line.
                    float t = b * dot(triangleList[i].edge2, q);
                    if (t > EPSILON && t < 1/EPSILON) // ray intersection
                    {
                        if(t < distances[row][col]){
                            // Its a near intersection and it is saved with the correct emission
                            if(triangleList[i].texture == nullptr){
                                distances[row][col] = t;
                                img[row][col] = triangleList[i].emission;
                            }
                            else{
                                contactPoint = origin + rayDir * t;
                                // The area of a triangle is 
                                area0uv = dot( triangleList[i].normal, cross( (triangleList[i].pu - triangleList[i].p0), (triangleList[i].pv - triangleList[i].p0) )  ) ;
                                areaPuv = dot( triangleList[i].normal, cross( (triangleList[i].pu - contactPoint), (triangleList[i].pv - contactPoint) )  ) ;
                                areaPv0 = dot( triangleList[i].normal, cross( (triangleList[i].pv - contactPoint), (triangleList[i].p0 - contactPoint) )  ) ;

                                bary.c[0] = areaPuv / area0uv ; // alpha
                                bary.c[1] = areaPv0 / area0uv ; // beta
                                bary.c[2] = 1.0f - bary.c[0] - bary.c[1] ; // gamma

                                x = bary.c[0]*triangleList[i].s0 + bary.c[1]*triangleList[i].su + bary.c[2]*triangleList[i].sv;
                                y = bary.c[0]*triangleList[i].t0 + bary.c[1]*triangleList[i].tu + bary.c[2]*triangleList[i].tv;
                                img[row][col] = textureImg[(int)(textureH*(1.f - y))][(int)(textureW*x)];
                                
                            }
                        }
                    }
                }


            }
        }
        // Creation of the image and saving in a ppm format file
        Image image = Image(true, width, height, RC, RC, img);
        image.printImage(argv[4]);
    }
    // Final execution of the programm
    return 0;
}