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
  * ToneMapper.h interface file of ToneMapper module
  */
#ifndef TONE_MAPPER_H
#define TONE_MAPPER_H

#include <iostream>
#include "Image.h"
#include "LAB.h"

using namespace std;

class ToneMapper{
	Image image;

	public:

	ToneMapper(Image _image);

	void clamping();

	void equalization();

	void equalizeClamp(const float v);

	void gammaCurve();

	void clampGamma(const float v);

};


#endif 