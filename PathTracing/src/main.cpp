
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
#include <algorithm>
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
        Point camera = Point(-3, 0, 0);
        Point origin;

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
            leftPP = Direction(0, 0, - width / height);
            //leftPP = Direction(- width / height, 0, 0);
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
        Plane leftWall = Plane(Direction(0, 0, 1), 7, 0.8, 0.0, 0, 0.1, 0.1, 0.1, 0.1, 0, 0, 1);
        planeList[0] = leftWall;
        Plane rightWall = Plane(Direction(0, 0,-1), 7, 0.0, 0.8, 0.0, 0.1, 0.1, 0.1, 0.1, 0, 0, 1);
        planeList[1] = rightWall;
        Plane ceiling = Plane(Direction(0, -1, 0), 7, RGB(255, 255, 255));
        //Plane ceiling = Plane(Direction(0, -1, 0), 7, 0.8, 0.8, 0.8, 0.1, 0.1, 0.1, 0.1, 0, 0, 1);
        planeList[2] = ceiling;
        Plane floor = Plane(Direction(0, 1, 0), 7, 0.8, 0.8, 0.8, 0.1, 0.1, 0.1, 0.1, 0, 0, 1);
        planeList[3] = floor;
        Plane background = Plane(Direction(-1, 0, 0), 50, 0.8, 0.8, 0.8, 0.1, 0.1, 0.1, 0.1, 0, 0, 1);
        planeList[4] = background;

        Plane behind = Plane(Direction(1, 0, 0), 10, 0.8, 0.8, 0.8, 0.1, 0.1, 0.1, 0.1, 0, 0, 1);
        planeList[5] = behind;

        // Definition of the spheres which are going to appear in the scene 
        Sphere leftSphere = Sphere(Point(40, -5, -3), 2,  0.8, 0.8, 0.8, 0, 0, 0, 0.1, 0, 0, 1);
        // Sphere rightSphere = Sphere(Point(32, -5, 3), 2, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0.9, 0, 1);
        Sphere rightSphere = Sphere(Point(32, -5, 3), 2, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0.9, 1.5);

        //Sphere lightSphere = Sphere(Point(37, 7, 0), 5, RGB(255, 255, 255));

        sphereList[0] = leftSphere;
        sphereList[1] = rightSphere;
        //sphereList[2] = lightSphere;


        // Matrix of the image that is going to be built
        vector<vector<RGB>> img(height, vector<RGB>(width));

        // Calculation of the upper left corner of the proyection plane 
        Point upperLeftCorner = origin + d_k + leftPP + upPP;
        Point pixelPoint;
        Direction rayDir, oldRayDir;
        Point bary;

        // Aleatory number for the rays and russian roulette
        float random1, random2, randomRR;

        // Acumulated radiance for each pixel
        float acumR, acumG, acumB;
        // Acumulated product for each path
        float productR, productG, productB;

        // Upper bounds for russian roullete probabilities
        float diffuseUB, specularUB, perfectSpecularUB, refractionUB;
        // Temporary values for kd, ks, ksp, krf
        float kdr = 0, kdg = 0, kdb = 0;
        float ksr = 0, ksg = 0, ksb = 0, shininess = 0;
        float kps = 0;
        float ri = 1;

        // Nearest objects found in path intersection (0 is no intersection)
        Plane nearestPlane; // Object code = 1
        Sphere nearestSphere; // Object code = 2
        Triangle nearestTriangle; // Object code = 3
        int nearestObject; // Code of the nearest object (0, 1, 2 or 3)
        Direction x, y, normal; // Intersected object base directions (unitary)
        float minDistance; // Distance to the nearest intersected object
        bool pathFinished; // Store if path has to finish

        float x_, y_, z_, theta, phi;




        // Loop that calculates for each pixel the thrown ray and the intersections
        // between it and the spheres and planes stored in the scene
        for(int row = 0; row < height; row++){
            for(int col = 0; col <width; col++){
                // Inicialization
                acumR = 0, acumG = 0, acumB = 0;
                for (int i = 0; i < PPP; i++){
                    
                    origin = camera;

                    // Generation of the random values for the path direction inside pixel box
                    random1 = uniform_real_distribution<float>(0, 1)(rng);
                    random2 = uniform_real_distribution<float>(0, 1)(rng);

                    pixelPoint = Point(upperLeftCorner.c[0],
                                        upperLeftCorner.c[1] - (row * pixelSize + (pixelSize * random1)),
                                        upperLeftCorner.c[2] + col * pixelSize + (pixelSize * random2));

                    /*
                    // Calculation of the center of each pixel where the ray is going to be thrown
                    pixelPoint = Point(upperLeftCorner.c[0] + col * pixelSize + (pixelSize * random1),
                                        upperLeftCorner.c[1] - (row * pixelSize + (pixelSize * random2)),
                                        upperLeftCorner.c[2]);
                    */

                    // Direction of the ray with an emission 
                    rayDir = pixelPoint - origin;
                    rayDir = rayDir / mod(rayDir);
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
                        
                        // Save rayDir for next origin point
                        oldRayDir = rayDir;
                        if(nearestObject == 0){
                            // No intersection
                            // Path finished (no intersection)
                            pathFinished = true;
                            productR = 0;
                            productG = 0;
                            productB = 0;
                        }
                        else{
                            switch (nearestObject){
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
                                    specularUB = diffuseUB + nearestPlane.maxks;
                                    perfectSpecularUB = specularUB + nearestPlane.kps;
                                    refractionUB = perfectSpecularUB + nearestPlane.krf;
                                    
                                    normal = nearestPlane.normal / mod(nearestPlane.normal);
                                    // Get tangent to plane using arbitraty unitary direction
                                    x = cross(normal, Direction(1, random1, random2) / mod(Direction(1, random1, random2)));
                                    y = cross(normal, x);
                                    kdr = nearestPlane.kdr;
                                    kdg = nearestPlane.kdg;
                                    kdb = nearestPlane.kdb;
                                    ksr = nearestPlane.ksr;
                                    ksg = nearestPlane.ksg;
                                    ksb = nearestPlane.ksb;
                                    kps = nearestPlane.kps;
                                    shininess = nearestPlane.shininess;
                                    ri = nearestPlane.ri;
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
                                    specularUB = diffuseUB + nearestSphere.maxks;
                                    perfectSpecularUB = specularUB + nearestSphere.kps;
                                    refractionUB = perfectSpecularUB + nearestSphere.krf;
                                    normal = (origin + (rayDir * minDistance)) - nearestSphere.center;
                                    normal = normal / mod(normal);
                                    x = cross(normal, Direction(1, random1, random2) / mod(Direction(1, random1, random2)));
                                    y = cross(normal, x);
                                    kdr = nearestSphere.kdr;
                                    kdg = nearestSphere.kdg;
                                    kdb = nearestSphere.kdb;
                                    ksr = nearestSphere.ksr;
                                    ksg = nearestSphere.ksg;
                                    ksb = nearestSphere.ksb;
                                    kps = nearestSphere.kps;
                                    shininess = nearestSphere.shininess;
                                    ri = nearestSphere.ri;
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
                                    specularUB = diffuseUB + nearestTriangle.maxks;
                                    perfectSpecularUB = specularUB + nearestTriangle.kps;
                                    refractionUB = perfectSpecularUB + nearestTriangle.krf; 
                                    normal = nearestTriangle.normal / mod(nearestTriangle.normal);
                                    x = nearestTriangle.edge1 / mod(nearestTriangle.edge1);
                                    y = cross(normal, x);
                                    kdr = nearestTriangle.kdr;
                                    kdg = nearestTriangle.kdg;
                                    kdb = nearestTriangle.kdb;
                                    ksr = nearestTriangle.ksr;
                                    ksg = nearestTriangle.ksg;
                                    ksb = nearestTriangle.ksb;
                                    kps = nearestTriangle.kps;
                                    shininess = nearestTriangle.shininess;
                                    ri = nearestTriangle.ri;
                                }
                            }
                            if(!pathFinished){
                                randomRR = uniform_real_distribution<float>(0, 1)(rng);
                                if(randomRR <= diffuseUB){
                                    // Russian roulette: diffuse
                                    theta = acosf(sqrt(1.f - uniform_real_distribution<float>(0, 1)(rng)));
                                    phi = 2.f * M_PI * uniform_real_distribution<float>(0, 1)(rng);
                                    x_ = sin(theta) * cos(phi); 
                                    y_ = sin(theta) * sin(phi);
                                    z_ = cos(theta);

                                    // Get new rayDir, using new direction with normal = 1 in local coordinates
                                    rayDir = Matrix3::changeBase(x, y, normal) * Direction(x_, y_, z_);
                                    rayDir = rayDir / mod(rayDir);
                                    // product = product * kdx / maxkd
                                    productR *= (kdr / diffuseUB);
                                    productG *= (kdg / diffuseUB);
                                    productB *= (kdb / diffuseUB);
                                    if(nearestObject == 2){
                                        //cout << "oldRayDir " << oldRayDir.toString() << " rayDir " << rayDir.toString() << endl;
                                    }

                                }
                                else if(randomRR <= specularUB){
                                    // Russian roulette: specular
                                    theta = acosf(sqrt(1.f - uniform_real_distribution<float>(0, 1)(rng)));
                                    phi = 2.f * M_PI * uniform_real_distribution<float>(0, 1)(rng);
                                    x_ = sin(theta) * cos(phi); 
                                    y_ = sin(theta) * sin(phi);
                                    z_ = cos(theta);

                                    // Get new rayDir, using new direction with normal = 1 in local coordinates
                                    rayDir = Matrix3::changeBase(x, y, normal) * Direction(x_, y_, z_);
                                    rayDir = rayDir / mod(rayDir);
                                    productR *= (ksr / abs(specularUB - diffuseUB) * (shininess + 2.f) * powf(abs(cosf(theta)), shininess) / 2.f);
                                    productG *= (ksg / abs(specularUB - diffuseUB) * (shininess + 2.f) * powf(abs(cosf(theta)), shininess) / 2.f);
                                    productB *= (ksb / abs(specularUB - diffuseUB) * (shininess + 2.f) * powf(abs(cosf(theta)), shininess) / 2.f);
                                }
                                
                                else if(randomRR <= perfectSpecularUB){
                                    // Russian roulette: perfect specular
                                    // Get new rayDir, using new direction with normal = 1 in local coordinates
                                    rayDir = oldRayDir - normal * dot(oldRayDir, normal) * 2.f;
                                }                                
                                else if(randomRR <= refractionUB){
                                    // Russian roulette: refraction
                                    float cosi = dot(rayDir, normal) < -1.0 ? -1.0 : (1.0 < dot(rayDir, normal)) ? 1.0 : dot(rayDir, normal);
                                    float etai = 1, etat = ri;
                                    if (cosi < 0){
                                        cosi = -cosi;
                                    }
                                    else {
                                        swap(etai, etat);
                                        normal = normal * -1;
                                    }
                                    float eta = etai / etat;
                                    float k = 1 - eta * eta * (1 - cosi * cosi);
                                    if (k < 0){
                                        pathFinished = true;
                                        productR = 0;
                                        productG = 0;
                                        productB = 0;
                                    }
                                    else {
                                        rayDir = rayDir * eta + normal * (eta * cosi - sqrtf(k));
                                    }
                                    origin = origin + oldRayDir * 0.0001;
                                }
                                else{
                                    // Path finished (russian roulette = absortion)
                                    pathFinished = true;
                                    productR = 0;
                                    productG = 0;
                                    productB = 0;
                                }
                            } 
                        }
                        // Update origin point
                        origin =  origin + oldRayDir * minDistance;
                    }
                    acumR += productR;
                    acumG += productG;
                    acumB += productB;
                }
                // Clamp RGB values between 0 and 255 
                img[row][col] = RGB(clamp((int)(acumR / PPP), 0, 255), 
                                    clamp((int)(acumG / PPP), 0, 255), 
                                    clamp((int)(acumB / PPP), 0, 255));
            }
        }
        // Creation of the image and saving in a ppm format file
        Image image = Image(true, width, height, RC, RC, img);
        image.printImage(argv[4]);
    }
    // Final execution of the programm
    return 0;
}