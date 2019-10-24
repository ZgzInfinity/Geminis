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
  * LAB.cpp implementation file of RGB module
  */

#include "../include/LAB.h"



/**
 * Build a LAB type object
 * @param _l is a float value which represents the luminance
 * @param _a is a float value which represents the ...
 * @param _b is a float value which represents the ...
 * @returns a LAB type object
 */
LAB::LAB(const float _l, const float _a, const float _b){
    l = _l;
    a = _a;
    b = _b;
}



/**
 * Default builder without parameters
 */
LAB::LAB(){}