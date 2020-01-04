/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 

#ifndef PHOTON_MAPPER_H
#define PHOTON_MAPPER_H

#include <list>
#include <random>
#include <chrono>
#include <cfloat>
#include "Photon.h"
#include "DirectLight.h"
#include "Plane.h"
#include "Sphere.h"
#include "Triangle.h"

const int numRays = 100;


inline void photonMapper(list<Photon>& photonList, list<DirectLight>& directLightList,
                         list<Plane>& planeList, list<Sphere>& sphereList,
                         list<Triangle>& triangleList){

    Point intersection, lastIntersection;
    Point origin;
    Direction rayDir, oldRayDir, directLightRay;
    Point bary;

    // Generation random numbers
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    // Aleatory number for the rays and russian roulette
    float random1, random2, randomRR;

    float productR = 1, productG = 1, productB = 1;

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
    float x_, y_, z_, theta, phi;

    // Aleatory number for the rays and russian roulette
    float xCoord, yCoord, zCoord;
    
    for(const auto& directLight : directLightList){
        for(int i = 0; i < numRays; i++){
            // Calculate new ray from light source

            // Generation of the random values
            xCoord = uniform_real_distribution<float>(-1, 1)(rng);
            yCoord = uniform_real_distribution<float>(-1, 1)(rng);
            zCoord = uniform_real_distribution<float>(-1, 1)(rng);

            Point randomPoint = Point(directLight.location.c[0] + xCoord,
                                      directLight.location.c[1] + yCoord,
                                      directLight.location.c[2] + zCoord);
            rayDir = randomPoint - directLight.location;

            if(mod(rayDir) > 1.f){
                // Out of the box (invalid ray)
                i--;
                continue;
            }

            // Normalize rayDir
            rayDir = rayDir / mod(rayDir);

            origin = directLight.location;


            // Generation of the random values for the path direction inside pixel box
            random1 = uniform_real_distribution<float>(0, 1)(rng);
            random2 = uniform_real_distribution<float>(0, 1)(rng);

            // Initialize pathFinished to false
            pathFinished = false;

            while(!pathFinished){
                
                //For each object intersection the starting distance is the biggest value and it is going to be reduced
                minDistance = FLT_MAX;

                // Initialize nearest object code to 0 (no intersection)
                nearestObject = 0;
                // Calculation of intersections between ray and planes
                intersectionRayPlane(origin, rayDir, minDistance, planeList, nearestPlane, nearestObject);
                // Calculation of intersections between ray and spheres
                intersectionRaySphere(origin, rayDir, minDistance, sphereList, nearestSphere, nearestObject);
                
                // Calculation of intersections between ray and triangles
                intersectionRayTriangle(origin, bary, rayDir, minDistance, triangleList, 
                                        nearestTriangle, nearestObject);
                
                // Save rayDir for next origin point
                oldRayDir = rayDir;
                if(nearestObject == 0){
                    // No intersection
                    // Path finished (no intersection)
                    pathFinished = true;
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
                            
                            // TODO: Photon flux ????
                            photonList.push_back(Photon(directLight.color, intersection, oldRayDir * -1));

                            // (kdr / diffuseUB);
                            // (kdg / diffuseUB);
                            // (kdb / diffuseUB);
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
                                productR = 0; productG = 0; productB = 0;
                            }
                            else {
                                rayDir = rayDir * eta + normal * (eta * cosi - sqrtf(k));
                            }
                            origin = origin + oldRayDir * 0.0001;
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
        }
    }


}


#endif