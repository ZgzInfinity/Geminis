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
  * RGB.cpp implementation file of RGB module
  */

#include "../include/RGB.h"



/**
 * Build a RGB type object
 * @param _red is a float value which represents the red color
 * @param _green is a float value which represents the green color
 * @param _blue is a float value which represents the blue color
 * @returns a RGB type object
 */
RGB::RGB(const float _red, const float _green, const float _blue){
    red = _red;
    green = _green;
    blue = _blue;
}



/**
 * Default builder without parameters
 */
RGB::RGB(){
    red = 0.f;
    green = 0.f;
    blue = 0.f;
}