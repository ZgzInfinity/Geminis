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
  * RGB.h interface file of RGB module
  */

#ifndef RGB_H
#define RGB_H


/*
 * Definition of the data type RGB
 */
struct RGB {
    // Value of the red pixel
    float red;
    // Value of the green pixel
    float green;
    // Value of the blue pixel
    float blue;

    /**
     * Build a RGB type object
     * @param _red is a float value which represents the red color
     * @param _green is a float value which represents the green color
     * @param _blue is a float value which represents the blue color
     * @returns a RGB type object
     */
    RGB(const float _red, const float _green, const float _blue);



    /**
     * Default builder without parameters
     */
    RGB();

};


RGB operator * (RGB a, RGB b);

RGB operator + (RGB a, RGB b);

#endif