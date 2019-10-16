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
#include "Matrix4.h"
#include "Matrix3.h"

const float PI = 3.141592741F;

/**
 * Gets the destination point resulting from adding the direction d to the point p 
 * @param p is the origin point
 * @param q is the destination point
 * @returns the point resulting from adding the direction d to point p
 */
Point operator + (Point p, Direction d);



/**
 * Gets the result of subtracting the point p from point q as a direction
 * @param p is the origin point
 * @param q is the destination point
 * @returns the direction between both points
 */
Direction operator - (Point p, Point q);



/**
 * Obtains the Direction vector result of multiplying the 4x4 transformation matrix t 
 * by the Direction vector d
 * @param t is the 4x4 transformation matrix 
 * @param d is the Direction vector
 * @returns the Direction vector result of multiplying the 4x4 transformation matrix t 
 * by the Direction vector d
 */
Direction operator * (Matrix4 t, Direction d);



/**
 * Obtains the Point vector result of multiplying the 4x4 transformation matrix t 
 * by the Point vector p
 * @param t is the 4x4 transformation matrix 
 * @param  is the POint vector
 * @returns the Point vector result of multiplying the 4x4 transformation matrix t 
 * by the Point vector p
 */
Point operator * (Matrix4 t, Point p);



/**
 * Obtains the Direction vector result of multiplying the 3x3 transformation matrix t 
 * by the Direction vector d
 * @param t is the 4x4 transformation matrix 
 * @param d is the Direction vector
 * @returns the Direction vector result of multiplying the 4x4 transformation matrix t 
 * by the Direction vector d
 */
Direction operator * (Matrix3 t, Direction d);



/**
 * Obtains the Point vector result of multiplying the 3x3 transformation matrix t 
 * by the Point vector p
 * @param t is the 3x3 transformation matrix 
 * @param  is the POint vector
 * @returns the Point vector result of multiplying the 3x3 transformation matrix t 
 * by the Point vector p
 */
Point operator * (Matrix3 t, Point d);


#endif 