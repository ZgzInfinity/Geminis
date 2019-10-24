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


/*
 * Definition of the toneMapping data type
 */
class ToneMapper{

	//Image with which one works
	Image image;

	public:


	/*
	 * Constructor of the ToneMapper
	 */
	ToneMapper(Image _image);



	/*
	 * Pre: <<outputFile>> is the name of the file resulting 
	 * 		from applying the clamping technique to the image
	 * Post: It has applied the clamping technique to the image and
	 *       it has generated a ppm file name <<outputfile>>
	 *       which stores the new image
	 */
	void clamping(string outputFile );



	/*
	 * Pre: <<outputFile>> is the name of the file resulting 
	 * 		from applying the equalization technique to the image
	 * Post: It has applied the equalization technique to the image and
	 *       it has generated a ppm file name <<outputfile>>
	 *       which stores the new image
	 */
	void equalization(string outputFile);



	/*
	 * Pre: <<outputFile>> is the name of the file resulting 
	 * 		from applying the clamping technique to the image and <<v>>
	 *      is the dimendion value for clampling
	 * Post: It has applied the clamping and equalization techniques 
	 *       to the image and it has generated a ppm file name <<outputfile>>
	 *       which stores the new image
	 */
	void equalizeClamp(const float v, string outputFile);



	/*
	 * Pre: <<outputFile>> is the name of the file resulting 
	 * 		from applying the clamping technique to the image
	 * Post: It has applied the clamping technique to the image and
	 *       it has generated a ppm file name <<outputfile>>
	 *       which stores the new image
	 */
	void gammaCurve(string outputFile);



	/*
	 * Pre: <<outputFile>> is the name of the file resulting 
	 * 		from applying the curve gamma and clamping techniques
	 *      to the image and <<v>> is the dimension value for clamping
	 * Post: It has applied the curve gamma and clamping techniques 
	 *       to the image and it has generated a ppm file name <<outputfile>>
	 *       which stores the new image
	 */
	void clampGamma(const float v, string outputFile);

};


#endif 