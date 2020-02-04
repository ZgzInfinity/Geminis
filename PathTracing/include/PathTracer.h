/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 

#ifndef PATH_TRACER_H
#define PATH_TRACER_H

#include <vector>
#include <iostream>
#include <cstring>
#include <list>
#include <iomanip>
#include <cfloat>
#include <random>
#include <chrono>
#include <algorithm>
#include <mutex>
#include "../include/Matrix4.h"
#include "../include/SharedOps.h"
#include "../include/Plane.h"
#include "../include/Sphere.h"
#include "../include/Triangle.h"
#include "../include/Image.h"
#include "../include/ImageLoaderPPM.h"
#include "../include/DirectLight.h"


const int BAR_PROGRESS = 30;


// Control the critical section
mutex g_pages_mutex;

// Number of rows processed
int rowsProcessed = 0;

// Progress of the render
int progress = 0;

/**
 * Computationof Path Tracing algorithm which calculates Render equation using Monte Carlo
 * @param PPP is the number of rays per pixel
 * @param width is the width dimension of the scene
 * @param i1 is the lower index row of the image
 * @param i2 is the upper index row of the image
 * @param img is the matrix where is going to be generated the scene
 * @param planeList is the list of planes of the scene
 * @param sphereList is the list spheres of the scene
 * @param triangleList is the list of triangles of the scene
 * @param directLightList is the list of point lights of the scene
 * @param camera is the camera which generates the scene
 * @param d_k is the direction vector of the k dimension 
 * @param leftPP is the left direction vector of the plane proyection 
 * @param upPP is the up direction vector of the plane proyection 
 * @param pixelSize is the dimension of each pixel of the image
 * @param rc is the real color number of the image
 * Generates a scene using path tracing algorithm
 */
inline void pathTracer(const int& PPP, const int& width, const float height, const float i1, const float i2, 
                       vector<vector<RGB>>& img, list<Plane>& planeList, list<Sphere>& sphereList, 
                       list<Triangle>& triangleList, list<DirectLight>& directLightList, Point& camera, 
                       Direction& d_k, Direction& leftPP, Direction& upPP, float& pixelSize, int& rc)
{
    Point intersection, lastIntersection;
    Point origin = camera;
    // Calculation of the upper left corner of the proyection plane 
    Point upperLeftCorner = origin + d_k + leftPP + upPP;
    Point pixelPoint;
    Direction rayDir, oldRayDir, directLightRay;
    Point bary;

    // Generation random numbers
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
    float ri = 1;

    // Nearest objects found in path intersection (0 is no intersection)
    Plane nearestPlane; // Object code = 1
    Sphere nearestSphere; // Object code = 2
    Triangle nearestTriangle; // Object code = 3
    int nearestObject; // Code of the nearest object (0, 1, 2 or 3)
    Direction x, y, normal; // Intersected object base directions (unitary)
    float minDistance; // Distance to the nearest intersected object
    bool pathFinished; // Store if path has to finish
    float minDistanceDL, oldDistanceDL;
    float x_, y_, z_, theta, phi;

    list<RGB> acumDL;
    list<RGB> acumIL;
    
    // Loop that calculates for each pixel the thrown ray and the intersections
    // between it and the spheres and planes stored in the scene
    for(int row = i1; row <= i2; row++){
        for(int col = 0; col < width; col++){
            // Inicialization
            acumR = 0, acumG = 0, acumB = 0;
            for (int i = 0; i < PPP; i++){
                origin = camera;

                // Generation of the random values for the path direction inside pixel box
                random1 = uniform_real_distribution<float>(0, 1)(rng);
                random2 = uniform_real_distribution<float>(0, 1)(rng);

                // Calculation of the center of each pixel where the ray is going to be thrown
                pixelPoint = Point(upperLeftCorner.c[0],
                                    upperLeftCorner.c[1] - (row * pixelSize + (pixelSize * random1)),
                                    upperLeftCorner.c[2] + col * pixelSize + (pixelSize * random2));

                // Direction of the new ray
                rayDir = pixelPoint - origin;
                rayDir = rayDir / mod(rayDir);
                img[row][col] = RGB();

                // Initialize montecarlo products
                productR = 1, productG = 1, productB = 1;
                acumDL.clear();
                acumIL.clear();
                // Initialize pathFinished to false
                pathFinished = false;

                while(!pathFinished){
                    acumDL.push_back(RGB());
                    acumIL.push_back(RGB());
                    
                    //For each object intersection the starting distance is the biggest value and it is going to be reduced
                    minDistance = FLT_MAX;

                    // Initialize nearest object code to 0 (no intersection)
                    nearestObject = 0;
                    // Calculation of intersections between ray and planes
                    intersectionRayPlane(origin, rayDir, minDistance, planeList, nearestPlane, nearestObject);
                    // Calculation of intersections between ray and spheres
                    intersectionRaySphere(origin, rayDir, minDistance, sphereList, nearestSphere, nearestObject);
                    
                    // Calculation of intersections between ray and triangles
                    intersectionRayTriangle(origin, bary, rayDir, 
                                            minDistance, triangleList, nearestTriangle, nearestObject);
                    
                    // Save rayDir for next origin point
                    oldRayDir = rayDir;
                    if(nearestObject == 0){
                        // No intersection
                        // Path finished (no intersection)
                        pathFinished = true;
                        productR = 0; productG = 0; productB = 0;
                    }
                    else{
                        switch (nearestObject){
                        case 1:
                            // Nearest intersection: plane
                            // Update variables in inline method
                            updateNearestPlane(nearestPlane, productR, productG, productB, pathFinished,
                                diffuseUB, specularUB, perfectSpecularUB, refractionUB, intersection,
                                origin, rayDir, minDistance, normal, random1, random2, x, y, kdr, kdg,
                                kdb, ksr, ksg, ksb, shininess, ri);
                            break;
                        case 2:
                            // Nearest intersection: sphere
                            // Update variables in inline method
                            updateNearestSphere(nearestSphere, productR, productG, productB, pathFinished,
                                diffuseUB, specularUB, perfectSpecularUB, refractionUB, intersection,
                                origin, rayDir, minDistance, normal, random1, random2, x, y, kdr, kdg,
                                kdb, ksr, ksg, ksb, shininess, ri);
                            break;
                        case 3:
                            // Nearest intersection: triangle
                            // Update variables in inline method
                            updateNearestTriangle(nearestTriangle, productR, productG, productB, pathFinished,
                                diffuseUB, specularUB, perfectSpecularUB, refractionUB, intersection,
                                origin, rayDir, minDistance, normal, random1, random2, x, y, kdr, kdg,
                                kdb, ksr, ksg, ksb, shininess, ri);
                        }
                        if(!pathFinished){
                            randomRR = uniform_real_distribution<float>(0, 1)(rng);
                            lastIntersection = intersection;                            
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
                                Direction perfectReflection = oldRayDir - normal * dot(oldRayDir, normal) * 2.f;
                                // product = product * kdx / maxkd
                                productR *= (kdr / diffuseUB);
                                productG *= (kdg / diffuseUB);
                                productB *= (kdb / diffuseUB);

                                // Calculate the contribution from direct light sources
                                for(const auto& directLight : directLightList){
                                    // Direction of the ray to the direct light
                                    directLightRay = directLight.location - intersection;
                                    // Update the minimum distance
                                    minDistanceDL = mod(directLightRay);
                                    oldDistanceDL = minDistanceDL;
                                    directLightRay = directLightRay / mod(directLightRay);

                                    // Check posible intersections between the objects and the light ray
                                    // Calculation of intersections between ray and planes
                                    intersectionRayPlane(intersection, directLightRay, minDistanceDL, planeList, nearestPlane, nearestObject);
                    
                                    // Calculation of intersections between ray and spheres
                                    intersectionRaySphere(intersection, directLightRay, minDistanceDL, sphereList, nearestSphere, nearestObject);
                                    
                                    // Calculation of intersections between ray and triangles
                                    intersectionRayTriangle(intersection, bary, directLightRay, 
                                                            minDistanceDL, triangleList, nearestTriangle, nearestObject);
                                    // Check if directRay has intersect any object
                                    if (minDistanceDL == oldDistanceDL){
                                        acumDL.back() = acumDL.back() +
                                                        RGB((directLight.color.red / (oldDistanceDL * oldDistanceDL)) * ((kdr / M_PI) + 
                                                                (ksr * ((shininess + 2.f) / (2.f * M_PI)) * pow(abs(dot(perfectReflection, rayDir)), shininess))) * abs(dot(normal, directLightRay)),
                                                            (directLight.color.green / (oldDistanceDL * oldDistanceDL)) * ((kdg / M_PI) + 
                                                                (ksg * ((shininess + 2.f) / (2.f * M_PI)) * pow(abs(dot(perfectReflection, rayDir)), shininess))) * abs(dot(normal, directLightRay)),
                                                            (directLight.color.blue / (oldDistanceDL * oldDistanceDL)) * ((kdb / M_PI) + 
                                                                (ksb * ((shininess + 2.f) / (2.f * M_PI)) * pow(abs(dot(perfectReflection, rayDir)), shininess))) * abs(dot(normal, directLightRay)));                                            
                                    }
                                }
                                acumIL.back() = RGB((kdr / diffuseUB),
                                                    (kdg / diffuseUB),
                                                    (kdb / diffuseUB));
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
                                Direction perfectReflection = oldRayDir - normal * dot(oldRayDir, normal) * 2.f;
                                productR *= (ksr / abs(specularUB - diffuseUB) * (shininess + 2.f) * powf(abs(dot(perfectReflection, rayDir)), shininess) / 2.f);
                                productG *= (ksg / abs(specularUB - diffuseUB) * (shininess + 2.f) * powf(abs(dot(perfectReflection, rayDir)), shininess) / 2.f);
                                productB *= (ksb / abs(specularUB - diffuseUB) * (shininess + 2.f) * powf(abs(dot(perfectReflection, rayDir)), shininess) / 2.f);

                                // Calculate the contribution from direct light sources
                                for(const auto& directLight : directLightList){
                                    // Direction of the ray to the direct light
                                    directLightRay = directLight.location - intersection;

                                    // Update the minimum distance
                                    minDistanceDL = mod(directLightRay);
                                    oldDistanceDL = minDistanceDL;
                                    directLightRay = directLightRay / mod(directLightRay);

                                    // Check posible intersections between the objects and the light ray
                                    // Calculation of intersections between ray and planes
                                    intersectionRayPlane(intersection, directLightRay, minDistanceDL, planeList, nearestPlane, nearestObject);
                    
                                    // Calculation of intersections between ray and spheres
                                    intersectionRaySphere(intersection, directLightRay,minDistanceDL, sphereList, nearestSphere, nearestObject);
                                    
                                    // Calculation of intersections between ray and triangles
                                    intersectionRayTriangle(intersection, bary, directLightRay,
                                                            minDistanceDL, triangleList, nearestTriangle, nearestObject);

                                    // Check if directRay has intersect any object
                                    if (minDistanceDL == oldDistanceDL){
                                        acumDL.back() = acumDL.back() +
                                                        RGB((directLight.color.red / (oldDistanceDL * oldDistanceDL)) * ((kdr / M_PI) + 
                                                                (ksr * ((shininess + 2.f) / (2.f * M_PI)) * pow(abs(dot(perfectReflection, rayDir)), shininess))) * abs(dot(normal, directLightRay)),
                                                            (directLight.color.green / (oldDistanceDL * oldDistanceDL)) * ((kdg / M_PI) + 
                                                                (ksg * ((shininess + 2.f) / (2.f * M_PI)) * pow(abs(dot(perfectReflection, rayDir)), shininess))) * abs(dot(normal, directLightRay)),
                                                            (directLight.color.blue / (oldDistanceDL * oldDistanceDL)) * ((kdb / M_PI) + 
                                                                (ksb * ((shininess + 2.f) / (2.f * M_PI)) * pow(abs(dot(perfectReflection, rayDir)), shininess))) * abs(dot(normal, directLightRay)));
                                    } 
                                }
                                acumIL.back() = RGB((ksr / abs(specularUB - diffuseUB) * (shininess + 2.f) * powf(abs(dot(perfectReflection, rayDir)), shininess) / 2.f),
                                                    (ksg / abs(specularUB - diffuseUB) * (shininess + 2.f) * powf(abs(dot(perfectReflection, rayDir)), shininess) / 2.f),
                                                    (ksb / abs(specularUB - diffuseUB) * (shininess + 2.f) * powf(abs(dot(perfectReflection, rayDir)), shininess) / 2.f));
                            }                                
                            else if(randomRR <= perfectSpecularUB){
                                // Russian roulette: perfect specular
                                // Get new rayDir, using new direction with normal = 1 in local coordinates
                                rayDir = oldRayDir - normal * dot(oldRayDir, normal) * 2.f;
                                acumDL.back() = RGB(0, 0, 0);
                                acumIL.back() = RGB(1, 1, 1);
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
                                    productR = 0; productG = 0; productB = 0;
                                }
                                else {
                                    rayDir = rayDir * eta + normal * (eta * cosi - sqrtf(k));
                                }
                                origin = origin + oldRayDir * 0.0001;
                                acumDL.back() = RGB(0, 0, 0);
                                acumIL.back() = RGB(1, 1, 1);
                            }
                            else{
                                // Path finished (russian roulette = absortion)
                                pathFinished = true;
                                productR = 0; productG = 0; productB = 0;
                            }
                        } 
                    }
                    // Update origin point
                    origin =  origin + oldRayDir * minDistance;
                }
                while(acumDL.size() > 1){
                    RGB p = acumDL.back();
                    acumDL.pop_back();
                    acumIL.pop_back();
                    acumDL.back() = acumDL.back() + (p * acumIL.back());
                }
                acumR += productR + acumDL.back().red;
                acumG += productG + acumDL.back().green;
                acumB += productB + acumDL.back().blue;
            }
            // Critical section (updating variable rc by the threads)
            g_pages_mutex.lock();

            // Update max rc (resolution color) value
            if((acumR / PPP) > rc){
                rc = (int)(acumR / PPP);
            }
            if((acumG / PPP) > rc){
                rc = (int)(acumG / PPP);
            }
            if((acumB / PPP) > rc){
                rc = (int)(acumB / PPP);
            }
            img[row][col] = RGB((int)(acumR / PPP), (int)(acumG / PPP), (int)(acumB / PPP));
        
            // Finished critical section code
            g_pages_mutex.unlock();
        }
        // Critical section (updating loading bar by the threads)
        g_pages_mutex.lock();

        // Incremention of rows processed
        rowsProcessed++;

        // A new row of the image has been processed
        progress = (BAR_PROGRESS * rowsProcessed) / int(height);

        // Write progress bar 
        cout << "Rendering progress [";
        for(int i = 0; i != BAR_PROGRESS; ++i){
            if(i < progress){
                cout << "#";
            }
            else {
                cout << ".";
            }
        }
        // Progress in percent
        cout << "] " << int((rowsProcessed / height) * 100.f) << " %\r";
        cout.flush();
        // Finished critical section code
        g_pages_mutex.unlock();
    }
}

#endif