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
 * Planet.cpp implementation file of Planet module
 */

#include "../include/Planet.h"

const float MAX_RADIUS_ERROR = 0.000001;

/**
 * Build a Planet type object
 * @param _center center of the planet
 * @param _axis axis of the planet
 * @param _refCity referenced-city of the planet
 * @returns a Planet type object
 */
Planet::Planet(Point _center, Direction _axis, Point _refCity){
    if(abs(mod(_axis) - 2 * (radius = mod(sub(_center, _refCity)))) <= MAX_RADIUS_ERROR){
        center = _center;
        axis = _axis;
        refCity = _refCity;
    }
    else{
        cout << "Error creating planet. Difference = " 
        << abs(mod(_axis) - 2 * radius) <<  endl;
    }
}

Planet::Planet(){}