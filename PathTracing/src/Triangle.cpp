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
  p0 = _p0; pu = _pu; pv = _pv;
  edge1 = (_pu - _p0);
  edge2 = (_pv - _p0);
  normal = cross(edge1, edge2);
  emission = _emission;
  texture = nullptr;
}


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