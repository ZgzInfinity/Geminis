#include "../include/Planet.h"

Planet::Planet(Point _center, Direction _axis, Point _refCity){
    if(mod(_axis) == 2 * mod(sub(_center, _refCity))){
        center = _center;
        axis = _axis;
        refCity = _refCity;
    }
    else{
        cout << "Error creating planet. Difference = " 
        << mod(_axis) - 2 * mod(sub(_center, _refCity)) <<  endl;
    }
}