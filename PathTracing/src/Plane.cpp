/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 


#include "../include/Plane.h"


Plane::Plane(){}

Plane::Plane(const Direction _normal, const float _distance2origin, const RGB _emission){
    normal = _normal;
    distance2origin = _distance2origin;
    emission = _emission;
}