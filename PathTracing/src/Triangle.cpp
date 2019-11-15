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
 * Triangle.cpp implementation file of Triangle module
 */

#include "../include/Triangle.h"



/**
 * Default builder without parameters
 */
Triangle::Triangle(){}



/**
 *Build a triangle type object without texture
 * @param _p0 is a the first vertex of the triangle
 * @param _pu is a the second vertex of the triangle
 * @param _pv is a the third vertex of the triangle
 * @param _emission is a color emission ray
 * @returns a Triangle type object
 */
Triangle::Triangle(const Point _p0, const Point _pu, const Point _pv, const RGB _emission){
  p0 = _p0; pu = _pu; pv = _pv;
  edge1 = (_pu - _p0);
  edge2 = (_pv - _p0);
  normal = cross(edge1, edge2);
  emission = _emission;
  texture = nullptr;
}



/**
 *Build a triangle type object without texture
 * @param _p0 is a the first vertex of the triangle
 * @param _pu is a the second vertex of the triangle
 * @param _pv is a the third vertex of the triangle
 * @param _s0 is the coordinate s of the frst vertex of the triangle in the texture image
 * @param _su is the coordinate s of the second vertex of the triangle in the texture image
 * @param _sv is the coordinate s of the third vertex of the triangle in the texture image
 * @param _t0 is the coordinate t of the frst vertex of the triangle in the texture image
 * @param _tu is the coordinate t of the second vertex of the triangle in the texture image
 * @param _tv is the coordinate t of the third vertex of the triangle in the texture image
 * @returns a Triangle type object
 */
Triangle::Triangle(const Point _p0, const Point _pu, const Point _pv, Image* _texture,
                   const float _s0, const float _su, const float _sv,
                   const float _t0, const float _tu, const float _tv){
  p0 = _p0; pu = _pu; pv = _pv;
  s0 = _s0; su = _su; sv = _sv;
  t0 = _t0; tu = _tu; tv = _tv;
  edge1 = (_pu - _p0);
  edge2 = (_pv - _p0);
  normal = cross(edge1, edge2);
  texture = _texture;
}
