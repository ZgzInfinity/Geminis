/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 


#include "../include/Sphere.h"


Sphere::Sphere(){}

Sphere::Sphere(const Point _center, const float _radius, const RGB _emission){
    center = _center;
    radius = _radius;
    emission = _emission;
}


