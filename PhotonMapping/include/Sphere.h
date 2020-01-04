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
#include <list>
#include <vector>
#include "Point.h"
#include "Direction.h"
#include "RGB.h"
#include "../include/SharedOps.h"



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
    // Specular coefficient by RGB channel
    float ksr, ksg, ksb, shininess, maxks;
    // Perfect specular (k)
    float kps;
    // Refraction (k, refraction index)
    float krf, ri;



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


    Sphere(const Point _center, const float _radius, float _kdr, float _kdg, float _kdb,
           float _ksr, float _ksg, float _ksb, float _shininess, float _kps, float _krf, float _ri);
    
};



/**
 * Calculates all the intersections between the rays thrown by the camera 
 * and the spheres of the scene
 * @param origin is the point of the space where the camera is located
 * @param rayDir is  the direction of the ray thrown from the camera
 * @param row is the row index
 * @param col is the col index
 * @param distances is the matrix which stores de distances between the rays and the 
 *        pixels of the image
 * @param sphereList is the list which stores all the spheres in the scene
 * @param randomRR is the random value for russian roulette
 * @param nearestSphere is the nearest object found in path intersection
 * @param nearestObject is the code for the nearest object found in path intersection
 */
inline void intersectionRaySphere(const Point& origin, Direction& rayDir, float& minDistance, 
                                  list<Sphere>& sphereList,
                                  Sphere& nearestSphere, int& nearestObject)
{
    Direction oc;
    float a, b, c, discriminant;
    float t0, t1;
    // Sphere intersection
    for(const auto& sphere : sphereList){
        oc = origin - sphere.center;
        // Calculation of the coefficients to resolve a second grade equation
        a = dot(rayDir, rayDir);
        b = 2.f * dot(oc, rayDir);
        c = dot(oc, oc) - (sphere.radius * sphere.radius);
        discriminant = b * b - 4 * a * c;
        if (discriminant >= 0.f){
            t0 = (-b - sqrt(discriminant)) / 2.f * a;
            t1 = (-b + sqrt(discriminant)) / 2.f * a;

            if (t0 > t1) std::swap(t0, t1);
            if(t0 > 0.0005 && t1 > 0.0005){
                if(t0 < minDistance){
                    // Its a near intersection
                    // Update nearest object
                    minDistance = t0;
                    nearestSphere = sphere;
                    nearestObject =  2;
                }
            }
            else if(t1 > 0.0005){
                if(t1 < minDistance){                    
                    // Its a near intersection
                    // Update nearest object
                    minDistance = t1;
                    nearestSphere = sphere;
                    nearestObject =  2;
                }

            }
        }
    }
}



inline void updateNearestSphere(Sphere& nearestSphere, float& productR, float& productG, float& productB,
            bool& pathFinished, float& diffuseUB, float& specularUB, float& perfectSpecularUB,
            float& refractionUB, Point& intersection, Point& origin, Direction& rayDir, float& minDistance,
            Direction& normal, float& random1, float& random2, Direction& x, Direction& y, float& kdr,
            float& kdg, float& kdb, float& ksr, float& ksg, float& ksb, float& shininess, float& ri)
{
    if(nearestSphere.emitsLight){
        // TODO
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
        intersection = origin + (rayDir * minDistance);
        normal = intersection - nearestSphere.center;
        normal = normal / mod(normal);
        x = cross(normal, Direction(1, random1, random2) / mod(Direction(1, random1, random2)));
        y = cross(normal, x);
        kdr = nearestSphere.kdr;
        kdg = nearestSphere.kdg;
        kdb = nearestSphere.kdb;
        ksr = nearestSphere.ksr;
        ksg = nearestSphere.ksg;
        ksb = nearestSphere.ksb;
        shininess = nearestSphere.shininess;
        ri = nearestSphere.ri;
    }   
}


#endif