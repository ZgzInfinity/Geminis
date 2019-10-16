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
  * ImageLoaderPPM.h interface file of ImageLoaderPPM module
  */
#ifndef IMAGE_LOADER_PPM_H
#define IMAGE_LOADER_PPM_H

#include <iostream>
#include <cstring>
#include <fstream>
#include "Image.h"
#include "Pixel.h"

using namespace std;


Image loadImagePPM(string path);

#endif 