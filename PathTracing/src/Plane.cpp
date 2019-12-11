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
 * Plane.cpp implementation file of Plane module
 */

#include <vector>
#include "../include/Plane.h"
#include "../include/Point.h"


/**
 * Default builder without parameters
 */
Plane::Plane(){}



/**
 * Build a Plane type object
 * @param _normal is the normal direction vector 
 * @param _distance2origin is the distance between the plane and the origin point
 * @param _emission is a color emission ray
 * @returns a Point type object
 */
Plane::Plane(const Direction _normal, const float _distance2origin, const RGB _emission){
    normal = _normal;
    distance2origin = _distance2origin;
    emission = _emission;
    emitsLight = true;
}

// Not emiting plane
Plane::Plane(const Direction _normal, const float _distance2origin,
             float _kdr, float _kdg, float _kdb,
             float _ksr, float _ksg, float _ksb, float _shininess, float _kps,
             float _krf, float _ri){
    normal = _normal;
    distance2origin = _distance2origin;
    // Diffuse
    kdr = _kdr; kdg = _kdg; kdb = _kdb;
    // Store maximun kd in maxkd
    kdr > kdg ? maxkd = kdr : maxkd = kdg;
    if(maxkd < kdb){
        maxkd = kdb;
    }
    // Specular
    ksr = _ksr; ksg = _ksg; ksb = _kdb;
    shininess = _shininess;
    // Store maximun ks in maxks
    ksr > ksg ? maxks = ksr : maxks = ksg;
    if(maxks < ksb){
        maxks = ksb;
    }
    // Perfect specular
    kps = _kps;
    // Refraction
    krf = _krf; ri = _ri;
    emitsLight = false;
}
