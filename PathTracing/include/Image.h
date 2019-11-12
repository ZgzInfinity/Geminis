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

#include <vector>
#include <cstring>
#include <fstream>
#include "RGB.h"

using namespace std;


/*
 * Definition of data type Image
 */
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
  vector<vector<RGB>> img;

  public:

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
    Image(const bool _isHDR, const int _width, const int _height, const float _rc,
          const float _m, vector<vector<RGB>> _img);


  
   /**
    * Default builder without parameters
    */
    Image();



    /**
     * Gets if the image is in HDR format
     * @returns <<true>> if the image is in HDR format.
     *          In any other case returns <<fslse>>
     */
    bool getIsHDR();



    /**
     * Gets the width of the image
     * @returns the width of the image
     */    
    int getWidth();



    /**
     * Gets the height of the image
     * @returns the height of the image
     */
    int getHeight();



    /**
     * Gets the rc value of the image
     * @returns the rc value of the image
     */    
    float getRc();



    /**
     * Gets the real maximun value of the image
     * @returns real maximun value of the image
     */ 
    float getM();



    /**
     * Gets the image
     * @returns the image
     */   
    vector<vector<RGB>> getImg();


    void printImage(string outputFile);

};

#endif 