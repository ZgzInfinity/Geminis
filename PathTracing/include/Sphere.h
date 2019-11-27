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


const int DIM_SPHERE = 1;

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
 * @sphereList is the list which stores all the spheres in the scene
 */
inline void intersectionRaySphere(const Point& origin, Direction& rayDir, const int& row, const int& col,
                                  const Point& pixelCenter, vector<vector<float>>& distances, 
                                  vector<vector<RGB>>& img, Sphere sphereList[])
{
    Direction oc;
    float t, a, b, c, discriminant, t0, t1;
    // Sphere intersection
    for(int i = 0; i < DIM_SPHERE; i++){
        // https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection
        oc = origin - sphereList[i].center;
        rayDir = pixelCenter - origin; // normalize rayDir?
        // Calculation of the coefficients to resolve a second grade equation
        a = dot(rayDir, rayDir);
        b = 2.f * dot(oc, rayDir);
        c = dot(oc, oc) - (sphereList[i].radius * sphereList[i].radius);
        discriminant = b * b - 4 * a * c;
        if(discriminant < 0.f){
            break;
        }
        else if (discriminant == 0.f) t0 = t1 = - 0.5 * b / a; 
        else { 
            float q = (b > 0.f) ? 
                -0.5 * (b + sqrt(discriminant)) : 
                -0.5 * (b - sqrt(discriminant)); 
            t0 = q / a; 
            t1 = c / q; 
        } 
        if (t0 > t1) std::swap(t0, t1); 

        if (t0 < 0.f) { 
            t0 = t1; // if t0 is negative, let's use t1 instead 
            if (t0 < 0.f){
                break; // both t0 and t1 are negative 
            } 
        } 
 
        t = t0;
        if(t > 0.f){
            if(t < distances[row][col]){
                // Its a near intersection and it is saved with the correct emission
                distances[row][col] = t;
                img[row][col] = sphereList[i].emission;
            }
        }
    }
}


#endif