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
  * Direction.h interface file of Direction module
  */


#ifndef DIRECTION_H
#define DIRECTION_H


/*
 * Definition of data type Direction
 */
struct Direction {
    // coordinate vector
    float c[4];

    /**
     * Build a Direction type object
     * @param x x-coordinate
     * @param y y-coordinate
     * @param z z-coordinate
     * @returns a Direction type object
     */
     Direction(float x, float y, float z);



    /**
     * Default builder without parameters
     */
     Direction();
};



/**
 * Obtains the direction resulting from adding the Direction d to the Direction e 
 * @param d is the first direction
 * @param e is the second direction
 * @returns the direction resulting from adding the Direction e to the Direction d
 */
Direction add(Direction d, Direction e);



/**
 * Gets the direction resulting from substracting the Direction d to the Direction e 
 * @param d is the first direction
 * @param e is the second direction
 * @returns the direction resulting from substracting the Direction e to the Direction d
 */
Direction sub(Direction d, Direction e);



/**
 * Gets the direction resulting from multiplying the Direction d by the scalar s
 * @param d is the direction
 * @param s is the scalar value
 * @returns the direction resulting from multiplying the Direction d by the scalar s
 */
Direction mul(Direction d, float s);



/**
 * Gets the direction resulting from dividing the Direction d by the scalar s
 * @param d is the direction
 * @param s is the scalar value
 * @returns the direction resulting from dividing the Direction d by the scalar s
 */
Direction div(Direction d, float s);



/**
 * Gets the Direction modulus d
 * @param d is the direction
 * @returns the Direction modulus d
 */  
float mod(Direction d);



/**
 * Gets the result of multiplying the module of the Direction d by the scalar s
 * @param d is the direction
 * @param s is the scalar value
 * @returns the result of multiplying the module of the Direction d by the scalar s
 */ 
float modMul(Direction d, float s);



/**
 * Gets the scalar product from the Directions d and e
 * @param d is the direction
 * @param s is the scalar value
 * @returns he scalar product from the Directions d and e
 */
float dot(Direction d, Direction e);



/**
 * Gets the scalar product of the modules dmod and emod and the cosine of the beta angle between them
 * @param d is the direction
 * @param s is the scalar value
 * @param beta is the angle between d and e directions
 * @returns the scalar product of the modules dmod and emod and the cosine of the beta angle between them
 */
float dot(float dmod, float emod, float beta);



/**
 * Gets the vector product in module of the Directions d and e and the sine of the beta angle between them
 * @param d is the first direction
 * @param e is the second direction
 * @returns the vector alar product from the Directions d and e
 */
float modCross(Direction d, Direction e, float beta);



/**
 * Gets the vector product of the modules dmod and emod and the cosine of the beta angle between them
 * @param d is the direction
 * @param s is the scalar value
 * @param beta is the angle between d and e directions
 * @returns the vector product of the modules dmod and emod and the cosine of the beta angle between them
 */
float modCross(float dmod, float emod, float beta);



/**
 * Gets the vector alar product from the Directions d and e
 * @param d is the first direction
 * @param e is the second direction
 * @returns the vector alar product from the Directions d and e
 */
Direction cross(Direction d, Direction e);

#endif /* DIRECTION_H */