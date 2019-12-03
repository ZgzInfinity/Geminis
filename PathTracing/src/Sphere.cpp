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
 * Sphere.cpp implementation file of Sphere module
 */


#include "../include/Sphere.h"



/**
 * Default builder without parameters
 */
Sphere::Sphere(){}



/**
 * Build a Sphere type object
 * @param _center is the center of the sphere
 * @param _radius is the radius of the sphere
 * @param _emission is a color emission ray
 * @returns a Sphere type object
 */
Sphere::Sphere(const Point _center, const float _radius, const RGB _emission){
    center = _center;
    radius = _radius;
    emission = _emission;
    emitsLight = true;
}


Sphere::Sphere(const Point _center, const float _radius, float _kdr, float _kdg, float _kdb){
    center = _center;
    radius = _radius;
    kdr = _kdr; kdg = _kdg; kdb = _kdb;
    // Store maximun kd in maxkd
    kdr > kdg ? maxkd = kdr : maxkd = kdg;
    if(maxkd < kdb){
    maxkd = kdb;
    }
    emitsLight = false;
}


