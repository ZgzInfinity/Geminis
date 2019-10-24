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
  * RGB.cpp interface file of RGB module
  */

#ifndef LAB_H
#define LAB_H


/*
 * Definition of the data type LAB
 */
struct LAB {
    // Value of the red pixel
    float l;
    // Value of the green pixel
    float a;
    // Value of the blue pixel
    float b;



    /**
     * Build a LAB type object
     * @param _l is a float value which represents the luminance
     * @param _a is a float value which represents the ...
     * @param _b is a float value which represents the ...
     * @returns a LAB type object
     */
    LAB(const float _l, const float _a, const float _b);



    /**
     * Default builder without parameters
     */
    LAB();
};

#endif