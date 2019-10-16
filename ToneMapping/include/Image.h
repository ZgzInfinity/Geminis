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
  * Image.h interface file of Image module
  */

#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"

class Image {

  // Control if the image is in HDR format
  bool isHDR;
  // Dimensions of the image
  int width, height;
  // Resolution color 
  float rc;
  // Real maximun value of the image
  float m;
  // Matrix of pixels that represents the image
  Pixel **img;

  public:


    Image(const bool _isHDR, const int _width, const int _height, const float _rc,
          const float _m, Pixel **_img);



    Image();
};

#endif 