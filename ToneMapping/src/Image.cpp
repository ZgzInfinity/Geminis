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
             const float _m, vector<vector<RGB>> _img)
{
    isHDR = _isHDR;
    width = _width;
    height = _height;
    rc = _rc;
    m = _m;
    img = _img;
}

Image::Image(){}

bool Image::getIsHDR(){
    return isHDR;
}

int Image::getWidth(){
    return width;
}

int Image::getHeight(){
    return height;
}

float Image::getRc(){
    return rc;
}

float Image::getM(){
    return m;
}

vector<vector<RGB>> Image::getImg(){
    return img;
}