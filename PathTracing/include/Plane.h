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
 * Plane.h interface file of Plane module
 */


#ifndef PLANE_H
#define PLANE_H

#include "Direction.h"
#include "RGB.h"
#include "../include/SharedOps.h"


const int DIM_PLANE = 5;
const float EPSILON = 0.0000001;


/*
 * Definition of data type Plane
 */
struct Plane {
    // The normal direction vector 
    Direction normal;
    // Distance between the plane and the origin point
    float distance2origin;
    // Color emission ray
    RGB emission;



    /**
     * Default builder without parameters
     */
    Plane();



    /**
     * Build a Plane type object
     * @param _normal is the normal direction vector 
     * @param _distance2origin is the distance between the plane and the origin point
     * @param _emission is a color emission ray
     * @returns a Point type object
     */
    Plane(const Direction _normal, const float _distance2origin, const RGB _emission);

};



/**
 * Calculates all the intersections between the rays thrown by the camera 
 * and the planes of the scene
 * @param origin is the point of the space where the camera is located
 * @param rayDir is  the direction of the ray thrown from the camera
 * @param row is the row index
 * @param col is the col index
 * @param distances is the matrix which stores de distances between the rays and the 
 *        pixels of the image
 * @param img is the matrix which contains the image 
 * @param planeList is the list which stores all the planes in the scene
 * @param randomRR is the random value for russian roulette
 */
inline void intersectionRayPlane(const Point& origin, const Direction& rayDir, const int& row, 
                                 const int& col, vector<vector<float>>& distances, vector<vector<RGB>>& img,
                                 Plane planeList[], float& randomRR)
{
    float denom, t;
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
                    // Stores the color of the ray
                    img[row][col] = planeList[i].emission;
                }
            }
        }
    }
}

#endif