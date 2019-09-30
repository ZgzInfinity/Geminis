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
 * ShareOpps.h interface file of the ShareOpps module
 */

#ifndef SHARED_OPS_H
#define SHARED_OPS_H

#include "Direction.h"
#include "Point.h"
#include "Matrix.h"



/**
 * Gets the destination point resulting from adding the direction d to the point p 
 * @param p is the origin point
 * @param q is the destination point
 * @returns the point resulting from adding the direction d to point p
 */
Point add(Point p, Direction d);



/**
 * Gets the result of subtracting the point p from point q as a direction
 * @param p is the origin point
 * @param q is the destination point
 * @returns the direction between both points
 */
Direction sub(Point p, Point q);


Direction mul(Matrix t, Direction d);


Point mul(Matrix t, Point p);


Direction translation(Direction d, Point p);




 
#endif /* SHARED_OPS_H */