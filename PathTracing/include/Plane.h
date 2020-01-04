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

#include <list>
#include "Direction.h"
#include "RGB.h"
#include "../include/SharedOps.h"


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
    // is it a light source?
    bool emitsLight;

    // Material properties
    // Diffuse coefficient by RGB channel
    float kdr, kdg, kdb, maxkd;
    // Specular coefficient by RGB channel
    float ksr, ksg, ksb, shininess, maxks;
    // Perfect specular (k)
    float kps;
    // Refraction (k, refraction index)
    float krf, ri;



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


    Plane(const Direction _normal, const float _distance2origin, float _kdr, float _kdg, float _kdb,
          float _ksr, float _ksg, float _ksb, float _shininess, float _kps, float _krf, float _ri);

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
 * @param nearestPlane is the nearest object found in path intersection
 * @param nearestObject is the code for the nearest object found in path intersection
 */
inline void intersectionRayPlane(const Point& origin, const Direction& rayDir, float& minDistance, vector<vector<RGB>>& img,
                                 list<Plane>& planeList, Plane& nearestPlane, int& nearestObject)
{
    float denom, t;
    // Plane intersection
    for(const auto& plane : planeList){
        if(abs(denom = dot(rayDir, plane.normal)) > EPSILON){
            // Calculation of the distance between 
            t = - (dot(origin, plane.normal) + plane.distance2origin) / denom;
            // Control of dividing by zerp
            if(t > 0.0005){
                if(t < minDistance){
                    // Its a near intersection and it is saved with the correct emission
                    minDistance = t;
                    // Update nearest object
                    nearestPlane = plane;
                    nearestObject =  1;
                }
            }
        }
    }
}



inline void updateNearestPlane(Plane& nearestPlane, float& productR, float& productG, float& productB,
            bool& pathFinished, float& diffuseUB, float& specularUB, float& perfectSpecularUB,
            float& refractionUB, Point& intersection, Point& origin, Direction& rayDir, float& minDistance,
            Direction& normal, float& random1, float& random2, Direction& x, Direction& y, float& kdr,
            float& kdg, float& kdb, float& ksr, float& ksg, float& ksb, float& shininess, float& ri)
{
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
        intersection = origin + (rayDir * minDistance);
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
        shininess = nearestPlane.shininess;
        ri = nearestPlane.ri;
    }
}

#endif