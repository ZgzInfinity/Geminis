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
  * Plane.h interface file of Plane module
  */


#include "Direction.h"
#include "Point.h"
#include "SharedOps.h"
#include "RGB.h"


/*
 * Definition of data type Plane
 */
struct Triangle {
    // The normal direction vector 
    Direction normal, edge1, edge2;
    // Distance between the plane and the origin point
    // float distance2origin;
    // Color emission ray
    RGB emission;

    Point p0, pu, pv;




    /**
     * Default builder without parameters
     */
    Triangle();



    Triangle(const Point _p0, const Point _pu, const Point _pv, const RGB _emission);
};