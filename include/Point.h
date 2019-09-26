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
  * Point.h interface file of Point module
  */
#ifndef POINT_H
#define POINT_H


/*
 * Definition of data type Point
 */
struct Point {
    // coordinate vector
    float c[4];

    /**
     * Build a Point type object
     * @param x x-coordinate
     * @param y y-coordinate
     * @param z z-coordinate
     * @returns a Point type object
     */
    Point(float x, float y, float z);



    /**
     * Default builder without parameters
     */
    Point();
};

#endif /* POINT_H */