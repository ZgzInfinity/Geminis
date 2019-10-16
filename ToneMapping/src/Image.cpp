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
 * Image.cpp implementation file of Image module
 */
 

#include "../include/Image.h"



/*
 * Default constructor
 */
Image::Image(const bool _isHDR, const int _width, const int _height, const float _rc,
             const float _m, Pixel **_img)
{
    isHDR = _isHDR;
    width = _width;
    height = _height;
    rc = _rc;
    m = _m;
    img = _img;
}

Image::Image(){}

