
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
#include <random>
#include <chrono>
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
        Direction d_k = Direction(0, 0, -1);
        //Point origin = Point(-1.5, 2, 2);
        Point origin = Point(0, 0, 5);

        // Creation of the base
        // Matrix4 camera = Matrix4::changeBase(d_i, d_j, d_k, origin);

        // Generation random numbers
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

        // Number of rays per pixel
        int PPP = atoi(argv[1]);

        // Image resolution
        float width = atof(argv[2]);
        float height = atof(argv[3]);
        float pixelSize;

        // Projection plane direction vectors
        Direction leftPP, upPP;
        
        // Calculation of the components of the vectors that form the projection plane
        // The smallest vector is taken as a reference in function of the width and height values
        if (width > height){
            // leftPP = Direction(0, 0, - width / height);
            leftPP = Direction(- width / height, 0, 0);
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
        Plane p5 = Plane(Direction(-1, 0, 0), 20, RGB(192, 57, 43));
        planeList[4] = p5;

        // Definition of the spheres which are going to appear in the scene 
        Sphere s1 = Sphere(Point(3, 0, 0), 1 , RGB(241, 196, 15));
        
        Sphere s2 = Sphere(Point(5, 0, 0), 1 , RGB(74, 105, 189));
        Sphere s3 = Sphere(Point(3, 1, 0), 0.5 , RGB(56, 173, 169));
        sphereList[0] = s1;
        sphereList[1] = s2;
        sphereList[2] = s3;

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

        // Calculation of the upper left corner of the proyection plane 
        Point upperLeftCorner = origin + d_k + leftPP + upPP;
        Point pixelPoint;
        float pixelOffset = pixelSize / 2.f;
        Direction rayDir;
        Point bary;

        // Aleatory number for the rays and russian roulette
        float random1, random2, randomRR;

        // Acumulated radiance for each pixel
        float acumR, acumG, acumB;
        // Acumulated product for each path
        float productR, productG, productB;

        // Upper bounds for russian roullete probabilities
        float diffuseUB, specularUB, perfectSpecularUB, refractionUB;

        // Nearest objects found in path intersection (0 is no intersection)
        Plane nearestPlane; // Object code = 1
        Sphere nearestSphere; // Object code = 2
        Triangle nearestTriangle; // Object code = 3
        int nearestObject; // Code of the nearest object (0, 1, 2 or 3)
        Direction x, y, normal; // Intersected object base directions (unitary)
        float pgeoFactor; // Factor used in montecarlo product (geometry / pdf)
        float minDistance; // Distance to the nearest intersected object
        bool pathFinished; // Store if path has to finish



        // Loop that calculates for each pixel the thrown ray and the intersections
        // between it and the spheres and planes stored in the scene
        for(int row = 0; row < height; row++){
            for(int col = 0; col <width; col++){
                // Inicialization
                acumR = 0, acumG = 0, acumB = 0;
                for (int i = 0; i < PPP; i++){
                    /*
                    pixelCenter = Point(upperLeftCorner.c[0],
                                        upperLeftCorner.c[1] - (row * pixelSize + pixelOffset),
                                        upperLeftCorner.c[2] + col * pixelSize + pixelOffset);
                    */

                    // Generation of the random values for the path direction inside pixel box
                    random1 = uniform_real_distribution<float>(0, 1)(rng);
                    random2 = uniform_real_distribution<float>(0, 1)(rng);

                    // Calculation of the center of each pixel where the ray is going to be thrown
                    pixelPoint = Point(upperLeftCorner.c[0] + col * pixelSize + (pixelSize * random1),
                                        upperLeftCorner.c[1] - (row * pixelSize + (pixelSize * random2)),
                                        upperLeftCorner.c[2]);

                    // Direction of the ray with an emission 
                    rayDir = pixelPoint - origin;
                    rayDir = rayDir / mod(rayDir);
                    //cout << rayDir.toString() << endl;
                    img[row][col] = RGB();
                    // Initialize montecarlo products
                    productR = 1, productG = 1, productB = 1;
                    // Initialize pathFinished to false
                    pathFinished = false;

                    while(!pathFinished){
                        //For each object intersection the starting distance is the biggest value and it is going to be reduced
                        minDistance = FLT_MAX;

                        // Initialize nearest object code to 0 (no intersection)
                        nearestObject = 0;

                        // Calculation of intersections between ray and planes
                        intersectionRayPlane(origin, rayDir, minDistance, img, planeList, nearestPlane, nearestObject);
        
                        // Calculation of intersections between ray and spheres
                        intersectionRaySphere(origin, rayDir, pixelPoint, minDistance, img, sphereList, nearestSphere, nearestObject);

                        // Calculation of intersections between ray and triangles
                        intersectionRayTriangle(origin, bary, rayDir, textureH, textureW, pixelPoint, 
                                                minDistance, textureImg, img, triangleList, nearestTriangle, nearestObject);

                        switch (nearestObject){
                        case 0:
                            // No intersection
                            // Path finished (no intersection)
                            pathFinished = true;
                            productR = 0;
                            productG = 0;
                            productB = 0;
                            break;
                        case 1:
                            // Nearest intersection: plane
                            if(nearestPlane.emitsLight){
                                productR *= nearestPlane.emission.red;
                                productG *= nearestPlane.emission.green;
                                productB *= nearestPlane.emission.blue;
                                // Path finished (reach emitting object)
                                pathFinished = true;
                            }
                            else{
                                diffuseUB = nearestPlane.maxkd;
                                // specularUB = diffuseUB + nearestPlane.maxks;
                                // perfectSpecularUB = specularUB + nearestPlane.maxkps;
                                // refractionUB = perfectSpecularUB + nearestPlane.maxkrf;
                                
                                normal = nearestPlane.normal / mod(nearestPlane.normal);
                                // Get tangent to plane using arbitraty unitary direction
                                x = cross(normal, Direction(1, 0, 0));
                                y = cross(x, normal);

                                randomRR = uniform_real_distribution<float>(0, 1)(rng);
                                if(randomRR <= diffuseUB){
                                    // Russian roulette: diffuse
                                    random1 = uniform_real_distribution<float>(0, 1)(rng);
                                    random2 = uniform_real_distribution<float>(0, 1)(rng);
                                    float sinTheta = sqrtf(1 - random1 * random1); 
                                    float phi = 2 * M_PI * random2; 
                                    float x_ = sinTheta * cosf(phi); 
                                    float y_ = sinTheta * sinf(phi);
                                    // Get new rayDir, using new direction with normal = 1 in local coordinates
                                    rayDir = Matrix3::changeBase(x, y, normal) * Direction(x_, y_, 1);
                                    pgeoFactor =  abs(dot(normal, rayDir)) * 2 * M_PI;
                                    productR *= (nearestPlane.kdr / M_PI) * pgeoFactor;
                                    productG *= (nearestPlane.kdg / M_PI) * pgeoFactor;
                                    productB *= (nearestPlane.kdb / M_PI) * pgeoFactor;
                                }
                                /*
                                else if(randomRR <= specularUB){
                                    // Russian roulette: specular

                                }
                                else if(randomRR <= perfectSpecularUB){
                                    // Russian roulette: perfect specular

                                }
                                else if(randomRR <= refractionUB){
                                    // Russian roulette: refraction

                                }
                                */
                                else{
                                    // Path finished (russian roulette = absortion)
                                    pathFinished = true;
                                    productR = 0;
                                    productG = 0;
                                    productB = 0;
                                }
                            }
                            
                            
                            break;
                        case 2:
                            // Nearest intersection: sphere
                            if(nearestSphere.emitsLight){
                                productR *= nearestSphere.emission.red;
                                productG *= nearestSphere.emission.green;
                                productB *= nearestSphere.emission.blue;
                                // Path finished (reach emitting object)
                                pathFinished = true;
                            }
                            else{
                                diffuseUB = nearestSphere.maxkd;
                                // specularUB = diffuseUB + nearestSphere.maxks;
                                // perfectSpecularUB = specularUB + nearestSphere.maxkps;
                                // refractionUB = perfectSpecularUB + nearestSphere.maxkrf;
                                normal = (origin - nearestSphere.center) / mod(origin - nearestSphere.center);
                                x = cross(normal, Direction(1, 0, 0));
                                y = cross(x, normal);

                                randomRR = uniform_real_distribution<float>(0, 1)(rng);
                                if(randomRR <= diffuseUB){
                                    // Russian roulette: diffuse
                                    random1 = uniform_real_distribution<float>(0, 1)(rng);
                                    random2 = uniform_real_distribution<float>(0, 1)(rng);
                                    float sinTheta = sqrtf(1 - random1 * random1); 
                                    float phi = 2 * M_PI * random2; 
                                    float x_ = sinTheta * cosf(phi); 
                                    float y_ = sinTheta * sinf(phi);
                                    // Get new rayDir, using new direction with normal = 1 in local coordinates
                                    rayDir = Matrix3::changeBase(x, y, normal) * Direction(x_, y_, 1);
                                    pgeoFactor =  abs(dot(normal, rayDir)) * 2 * M_PI;
                                    productR *= (nearestPlane.kdr / M_PI) * pgeoFactor;
                                    productG *= (nearestPlane.kdg / M_PI) * pgeoFactor;
                                    productB *= (nearestPlane.kdb / M_PI) * pgeoFactor;
                                }
                                /*
                                else if(randomRR <= specularUB){
                                    // Russian roulette: specular

                                }
                                else if(randomRR <= perfectSpecularUB){
                                    // Russian roulette: perfect specular

                                }
                                else if(randomRR <= refractionUB){
                                    // Russian roulette: refraction

                                }
                                */
                                else{
                                    // Path finished (russian roulette = absortion)
                                    pathFinished = true;
                                    productR = 0;
                                    productG = 0;
                                    productB = 0;
                                }
                            }
                            

                            break;
                        case 3:
                            // Nearest intersection: triangle
                            if(nearestTriangle.emitsLight){
                                productR *= nearestTriangle.emission.red;
                                productG *= nearestTriangle.emission.green;
                                productB *= nearestTriangle.emission.blue;
                                // Path finished (reach emitting object)
                                pathFinished = true;
                            }
                            else{
                                diffuseUB = nearestTriangle.maxkd;
                                // specularUB = diffuseUB + nearestTriangle.maxks;
                                // perfectSpecularUB = specularUB + nearestTriangle.maxkps;
                                // refractionUB = perfectSpecularUB + nearestTriangle.maxkrf; 
                                normal = nearestTriangle.normal / mod(nearestTriangle.normal);
                                x = nearestTriangle.edge1 / mod(nearestTriangle.edge1);
                                y = cross(x, normal);

                                randomRR = uniform_real_distribution<float>(0, 1)(rng);
                                if(randomRR <= diffuseUB){
                                    // Russian roulette: diffuse
                                    random1 = uniform_real_distribution<float>(0, 1)(rng);
                                    random2 = uniform_real_distribution<float>(0, 1)(rng);
                                    float sinTheta = sqrtf(1 - random1 * random1); 
                                    float phi = 2 * M_PI * random2; 
                                    float x_ = sinTheta * cosf(phi); 
                                    float y_ = sinTheta * sinf(phi);
                                    // Get new rayDir, using new direction with normal = 1 in local coordinates
                                    rayDir = Matrix3::changeBase(x, y, normal) * Direction(x_, y_, 1);
                                    pgeoFactor =  abs(dot(normal, rayDir)) * 2 * M_PI;
                                    productR *= (nearestPlane.kdr / M_PI) * pgeoFactor;
                                    productG *= (nearestPlane.kdg / M_PI) * pgeoFactor;
                                    productB *= (nearestPlane.kdb / M_PI) * pgeoFactor;
                                }
                                /*
                                else if(randomRR <= specularUB){
                                    // Russian roulette: specular

                                }
                                else if(randomRR <= perfectSpecularUB){
                                    // Russian roulette: perfect specular

                                }
                                else if(randomRR <= refractionUB){
                                    // Russian roulette: refraction

                                }
                                */
                                else{
                                    // Path finished (russian roulette = absortion)
                                    pathFinished = true;
                                    productR = 0;
                                    productG = 0;
                                    productB = 0;
                                }
                            }
                        }
                    }
                    acumR += productR;
                    acumG += productG;
                    acumB += productB;
                }
                img[row][col] = RGB(acumR / PPP, acumG / PPP, acumB / PPP);
            }
        }
        // Creation of the image and saving in a ppm format file
        Image image = Image(true, width, height, RC, RC, img);
        image.printImage(argv[4]);
    }
    // Final execution of the programm
    return 0;
}