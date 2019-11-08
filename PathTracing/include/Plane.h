/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 


#include "Direction.h"
#include "RGB.h"


struct Plane {
    Direction normal;
    float distance2origin;
    RGB emission;

    Plane();

    Plane(const Direction _normal, const float _distance2origin, const RGB _emission);
};