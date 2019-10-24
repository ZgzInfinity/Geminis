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



/**
 * Build an Image type object
 * @param _isHDR is a boolean in order to control if the image is in HDR
 * @param _width is the width of the image
 * @param _height is the height of the image
 * @param _rc is the rc value of the image
 * @param _m is the real maximun value of the image
 * @param _img is a dinamic matrix that stores de image
 * @returns a Direction type object
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



/**
 * Default builder without parameters
 */
Image::Image(){}



/**
 * Gets if the image is in HDR format
 * @returns <<true>> if the image is in HDR format.
 *          In any other case returns <<fslse>>
 */
bool Image::getIsHDR(){
    return isHDR;
}



/**
 * Gets the width of the image
 * @returns the width of the image
 */  
int Image::getWidth(){
    return width;
}



/**
 * Gets the height of the image
 * @returns the height of the image
 */
int Image::getHeight(){
    return height;
}



/**
 * Gets the rc value of the image
 * @returns the rc value of the image
 */ 
float Image::getRc(){
    return rc;
}



/**
 * Gets the real maximun value of the image
 * @returns real maximun value of the image
 */ 
float Image::getM(){
    return m;
}



/**
 * Gets the image
 * @returns the image
 */  
vector<vector<RGB>> Image::getImg(){
    return img;
}