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
     * Applies the clamping technique to the image and it has generated 
 	 * a ppm file name <<outputfile>> which stores the new image
 	 * @param outputFile is the name of the file resulting from applying 
 	 *         the clamping technique to the image
 	 */
	void clamping(string outputFile );



   /*
    * Applies the equalization technique to the image and it has generated 
    * a ppm file name <<outputfile>> which stores the new image
    * @param outputFile is the name of the file resulting from applying 
    *        the equalization technique to the image
    */
	void equalization(string outputFile);



   /*
    * Applies the equalization and clamping techniques to the image and it has generated 
    * a ppm file name <<outputfile>> which stores the new image
    * @param outputFile is the name of the file resulting from applying 
    *        the equalization and clamping techniques to the image
    * @param v is the dimension value for the clamping
    */
	void equalizeClamp(const float v, string outputFile);



   /*
 	* Applies the gamma curve technique to the image and it has generated 
 	* a ppm file name <<outputfile>> which stores the new image
 	* @param outputFile is the name of the file resulting from applying 
 	*        the curve gamma technique to the image
   * @param g is the gamma correction value
 	*/
	void gammaCurve(string outputFile, const float g);



   /*
    * Applies the clamping and gamma curve techniques to the image and it has generated 
    * a ppm file name <<outputfile>> which stores the new image
    * @param outputFile is the name of the file resulting from applying 
    *        the clamping and gamma curve technique to the image
    * @param v is the dimension value for the clamping
    * @param g is the gamma correction value
    */
	void clampGamma(const float v, string outputFile, const float g);

};


#endif 