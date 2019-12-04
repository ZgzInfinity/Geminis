/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 

/*
 * Sphere.h interface file of the Sphere module
 */

#ifndef SPHERE_H
#define SPHERE_H


#include <cmath>
#include <vector>
#include "Point.h"
#include "Direction.h"
#include "RGB.h"
#include "../include/SharedOps.h"


const int DIM_SPHERE = 2;

/*
 * Definition of data type Sphere
 */
struct Sphere {
    // Center of the sphere
    Point center;
    // Radius of the sphere
    float radius;
    // Color emission ray
    RGB emission;
    // is it a light source?
    bool emitsLight;

    // Material properties
    // Diffuse coefficient by RGB channel
    float kdr, kdg, kdb, maxkd;



    /**
     * Default builder without parameters
     */
    Sphere();



    /**
     * Build a Sphere type object
     * @param _center is the center of the sphere
     * @param _radius is the radius of the sphere
     * @param _emission is a color emission ray
     * @returns a Sphere type object
     */
    Sphere(const Point _center, const float _radius, const RGB _emission);


    Sphere(const Point _center, const float _radius, float _kdr, float _kdg, float _kdb);
    
};



/**
 * Calculates all the intersections between the rays thrown by the camera 
 * and the spheres of the scene
 * @param origin is the point of the space where the camera is located
 * @param rayDir is  the direction of the ray thrown from the camera
 * @param row is the row index
 * @param col is the col index
 * @param pixelCenter is the size of the pixel 
 * @param distances is the matrix which stores de distances between the rays and the 
 *        pixels of the image
 * @param img is the matrix which contains the image 
 * @param sphereList is the list which stores all the spheres in the scene
 * @param randomRR is the random value for russian roulette
 * @param nearestSphere is the nearest object found in path intersection
 * @param nearestObject is the code for the nearest object found in path intersection
 */
inline void intersectionRaySphere(const Point& origin, Direction& rayDir,
                                  const Point& pixelCenter, float& minDistance, 
                                  vector<vector<RGB>>& img, Sphere sphereList[],
                                  Sphere& nearestSphere, int& nearestObject)
{
    Direction oc;
    float t, a, b, c, discriminant;
    // Sphere intersection
    for(int i = 0; i < DIM_SPHERE; i++){
        oc = origin - sphereList[i].center;
        // Calculation of the coefficients to resolve a second grade equation
        a = dot(rayDir, rayDir);
        b = 2.f * dot(oc, rayDir);
        c = dot(oc, oc) - (sphereList[i].radius * sphereList[i].radius);
        discriminant = b * b - 4 * a * c;
        if (discriminant >= 0.f){
            t = (-b -sqrt(discriminant)) / 2.f * a;
            // Control of dividing by zero
            if(t > 0.f){
                if(t < minDistance){
                    // Its a near intersection
                    minDistance = t;

                    // Update nearest object
                    nearestSphere = sphereList[i];
                    nearestObject =  2;
                }
            }
        }
    }
}


#endif