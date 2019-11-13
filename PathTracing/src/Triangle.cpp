/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 


#include "../include/Triangle.h"



/**
 * Default builder without parameters
 */
Triangle::Triangle(){}



Triangle::Triangle(const Point _p0, const Point _pu, const Point _pv, const RGB _emission){
  p0 = _p0;
  pu = _pu;
  pv = _pv;
  // edge1 = (_pu - _p0) / mod (_pu - _p0);
  // edge2 = (_pv - _p0) / mod (_pv - _p0);
  edge1 = (_pu - _p0);
  edge2 = (_pv - _p0);
  normal = cross(edge1, edge2);
  emission = _emission;
}
