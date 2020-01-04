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
  emitsLight = true;
}


Triangle::Triangle(const Point _p0, const Point _pu, const Point _pv,
                   float _kdr, float _kdg, float _kdb,
                   float _ksr, float _ksg, float _ksb, float _shininess, float _kps,
                   float _krf, float _ri){
  p0 = _p0; pu = _pu; pv = _pv;
  edge1 = (_pu - _p0);
  edge2 = (_pv - _p0);
  normal = cross(edge1, edge2);
  // Diffuse
  kdr = _kdr; kdg = _kdg; kdb = _kdb;
  // Store maximun kd in maxkd
  kdr > kdg ? maxkd = kdr : maxkd = kdg;
  if(maxkd < kdb){
    maxkd = kdb;
  }
  // Specular
  ksr = _ksr; ksg = _ksg; ksb = _ksb;
  shininess = _shininess;
  // Store maximun ks in maxks
  ksr > ksg ? maxks = ksr : maxks = ksg;
  if(maxks < ksb){
    maxks = ksb;
  }
  // Perfect specular
  kps = _kps;
  // Refraction
  krf = _krf; ri = _ri;
  emitsLight = false;
  texture = nullptr;
}


Triangle::Triangle(const Point _p0, const Point _pu, const Point _pv, Image* _texture,
                   float _maxkd, float _maxks, float _shininess, float _kps,
                   float _krf, float _ri,
                   const float _s0, const float _su, const float _sv,
                   const float _t0, const float _tu, const float _tv){
  p0 = _p0; pu = _pu; pv = _pv;
  s0 = _s0; su = _su; sv = _sv;
  t0 = _t0; tu = _tu; tv = _tv;
  edge1 = (_pu - _p0);
  edge2 = (_pv - _p0);
  normal = cross(edge1, edge2);
  // Diffuse
  maxkd = _maxkd;
  // Specular
  maxks = _maxks;
  shininess = _shininess;
  // Perfect specular
  kps = _kps;
  // Refraction
  krf = _krf; ri = _ri;
  emitsLight = false;
  texture = _texture;
}
